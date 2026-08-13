#!/usr/bin/env python3
"""
Set up decomp-permuter for one function.

The permuter randomly rewrites a candidate C function -- reordering
declarations, introducing temporaries, changing types -- recompiles each
variant and scores it against the target object. It exists for exactly the
failure we keep hitting: the logic and instruction count are right but gcc
allocates registers differently, and no amount of hand-guessing at the C
finds the shape that reproduces the original.

    python tools_src/permute.py func_80035598
    python tools_src/permute.py func_80035598 --run

Without --run it only prepares build/permuter/<func>/ and prints the
command, so you can inspect or tweak before starting a long search.

Requires a candidate C to already exist, in parked/<func>.c or src/<func>.c
-- the permuter improves a near miss, it does not decompile from nothing.
Parked near-misses are the normal input: the register-allocation class is
exactly what it is for.

**This script was written for Windows in July and had gone stale in the way
this project keeps hitting.** Its generated compile.sh restated build.py's
pipeline instead of importing it, and by August it was missing --expand-div
and all four post-passes -- so every variant it scored was compiled
differently from the real build, and a "match" would not have been one. The
compile step now delegates to tools_src/permuter_compile.py, which imports
build.py and cannot drift.

Three other things bite, all found the hard way on func_800135FC:
 - decomp-permuter's prelude.inc sets `.set gp=64`, which our assembler
   rejects on a 32-bit processor. Stripped when the target is built.
 - the target has to be assembled with the project's own AS_FLAGS.
 - the candidate's callees are mostly implicitly declared, and the permuter's
   typemap raises KeyError on them during some randomizations -- 3 failures in
   66 iterations, survivable, but prototypes in the candidate cost nothing.
"""

import argparse
import io
import os
import shutil
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tools_src"))

import build as B  # noqa: E402  (shares toolchain paths and flag tables)

PERMUTER = ROOT / "tools" / "decomp-permuter"
OUTDIR = ROOT / "build" / "permuter"


def patch_permuter_for_windows():
    """Skip the permuter's executable-bit check, which Windows cannot pass.

    permuter.py refuses to start unless compile.sh has mode bit 0o100.
    On Windows os.chmod cannot set it -- os.stat reports 0o100666 for any
    writable file regardless -- so the check fails for everyone on this
    platform. Relaxing it to "only enforce off Windows" is the smallest
    change that works; it is idempotent, so re-running is harmless.

    This patches a cloned third-party tool, which is worth doing
    deliberately rather than by accident: re-cloning decomp-permuter
    reverts it, and running this script again re-applies it.
    """
    patches = [
        # 1. The executable-bit check itself.
        (PERMUTER / "src" / "main.py",
         "        if not os.stat(compile_cmd).st_mode & 0o100:",
         "        if os.name != \"nt\" and "
         "not os.stat(compile_cmd).st_mode & 0o100:"),
        # 2. Windows cannot exec a .sh directly, so route it through bash.
        (PERMUTER / "src" / "compiler.py",
         "                [self.compile_cmd, c_name, \"-o\", o_name],",
         "                ([\"bash\"] if os.name == \"nt\" else [])\n"
         "                + [self.compile_cmd, c_name, \"-o\", o_name],"),
    ]
    changed = False
    for path, old, new in patches:
        text = path.read_text(encoding="utf-8")
        if new in text:
            continue
        if old not in text:
            print(f"warning: could not patch {path.name}; decomp-permuter "
                  f"may have changed", file=sys.stderr)
            continue
        text = text.replace(old, new)
        if path.name == "compiler.py" and "\nimport os" not in text:
            text = text.replace("import subprocess", "import os\nimport subprocess", 1)
        with io.open(path, "w", encoding="utf-8", newline="\n") as f:
            f.write(text)
        changed = True
    return changed


def make_tool_shims():
    """Expose the toolchain under the names the permuter looks for.

    It locates objdump with shutil.which() against a fixed list of names
    (mips-linux-gnu-objdump and friends) and shells out to a bare `cpp`.
    Ours are prefixed mipsel-none-elf-*, so we drop copies under the
    expected names rather than patching the tool further.

    The copies go *inside* the toolchain's own bin directory, not a
    separate shim directory: `cpp` is a driver that locates its `cc1`
    relative to its own location, so a copy anywhere else fails with
    "cannot execute 'cc1'". tools/ is gitignored, so this leaves no trace
    in the repo.
    """
    bindir = B.MIPS_BIN
    for want, have in (("mips-linux-gnu-objdump.exe", "mipsel-none-elf-objdump.exe"),
                       ("cpp.exe", "mipsel-none-elf-cpp.exe")):
        shim, real = bindir / want, bindir / have
        if not shim.exists() or shim.stat().st_mtime < real.stat().st_mtime:
            shutil.copy2(real, shim)
    return bindir


def write_compile_script(dest: Path, func: str):
    """The permuter invokes this as `./compile.sh input.c -o output.o`.

    It delegates rather than restating the pipeline. The previous version
    inlined cc1psx/maspsx/as into generated bash and was silently a build
    behind within two weeks -- no --expand-div, none of the post-passes.
    """
    with io.open(dest, "w", encoding="utf-8", newline="\n") as f:
        f.write(
            "#!/bin/bash\n"
            "# Generated by tools_src/permute.py.\n"
            "export WINEDEBUG=-all\n"
            f"export PERMUTER_FUNC={func}\n"
            f'exec "{B.VENV_PYTHON.as_posix()}" '
            f'"{(ROOT / "tools_src" / "permuter_compile.py").as_posix()}" "$@"\n')
    dest.chmod(0o755)


def build_target_object(func: str, dest: Path, as_flags):
    """Assemble the original disassembly into the object to match against.

    decomp-permuter's own prelude.inc supplies glabel/endlabel and the float
    aliases, but its `.set gp=64` is rejected by our assembler on a 32-bit
    processor, so that one line is dropped.
    """
    prelude = [l for l in (PERMUTER / "prelude.inc").read_text().splitlines()
               if "gp=64" not in l]
    stub = dest.parent / "target.s"
    with io.open(stub, "w", encoding="utf-8", newline="\n") as f:
        f.write("\n".join(prelude) + "\n")
        f.write((B.ASM_FUNCS / f"{func}.s").read_text())
    subprocess.run([str(B.AS), *as_flags, "-o", str(dest), str(stub)],
                   cwd=ROOT, check=True)


def main():
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("func", help="function name, e.g. func_80035598")
    ap.add_argument("--run", action="store_true",
                    help="start the permuter instead of only preparing")
    ap.add_argument("-j", default="4", help="permuter worker threads")
    args = ap.parse_args()

    # A run killed by timeout leaves its in-flight candidate .c/.o pairs in
    # /tmp (the permuter cleans them only on a clean exit). By the time this
    # script runs again every previous owner is dead, so sweep them here --
    # 182 of them accumulated across two sessions of bounded runs, and /tmp
    # on this machine has a per-user quota with a documented failure mode.
    import glob as _glob
    import tempfile as _tempfile
    for _p in _glob.glob(_tempfile.gettempdir() + "/permuter0*"):
        try:
            os.unlink(_p)
        except OSError:
            pass

    src = None
    for cand in (ROOT / "parked" / f"{args.func}.c",
                 ROOT / "src" / f"{args.func}.c"):
        if cand.exists():
            src = cand
            break
    if src is None:
        sys.exit(f"no candidate for {args.func} in parked/ or src/ -- write "
                 f"one first; the permuter refines a near miss, it cannot "
                 f"start from nothing")
    if not (B.ASM_FUNCS / f"{args.func}.s").exists():
        sys.exit(f"no disassembly for {args.func}")

    flags = [f for f in B.PER_FUNC_FLAGS.get(args.func, B.CC1_FLAGS)]
    as_flags = list(B.AS_FLAGS)
    override = B.PER_FUNC_AS_FLAGS.get(args.func)
    if override:
        as_flags.append(override)

    if B.WINDOWS and patch_permuter_for_windows():
        print("patched decomp-permuter: relaxed its executable-bit check on Windows")

    work = OUTDIR / args.func
    work.mkdir(parents=True, exist_ok=True)

    # base.c: preprocessed, reduced to just this function.
    # The host cpp, not CPPPSX: the permuter parses this with pycparser, and
    # it only needs the includes flattened. __attribute__ is stripped because
    # pycparser does not know it.
    base = work / "base.c"
    with open(base, "w") as f:
        subprocess.run(["gcc", "-E", "-P", "-I", str(ROOT / "include"),
                        "-D__attribute__(x)=", str(src)],
                       stdout=f, check=True)
    subprocess.run([str(B.VENV_PYTHON), str(PERMUTER / "strip_other_fns.py"),
                    str(base), args.func], cwd=ROOT, check=True)

    bindir = make_tool_shims() if B.WINDOWS else None

    write_compile_script(work / "compile.sh", args.func)
    build_target_object(args.func, work / "target.o", as_flags)
    (work / "settings.toml").write_text(
        f'func_name = "{args.func}"\ncompiler_type = "gcc"\n')

    cmd = (f'"{B.VENV_PYTHON.as_posix()}" '
           f'"{(PERMUTER / "permuter.py").as_posix()}" '
           f'"{work.as_posix()}" -j {args.j} --better-only --stop-on-zero')
    print(f"\nprepared {work.relative_to(ROOT)}")
    print(f"compiler flags: {' '.join(flags)}")
    print(f"\n{cmd}\n")
    if not args.run:
        # Say so loudly. Without --run this tool only *prints* the command,
        # and a log containing nothing but that command reads exactly like a
        # permuter run that finished and found nothing. That misreading went
        # into a park entry ("the permuter was run and is not the answer")
        # before anyone noticed the permuter had never started.
        print("NOT RUN: this only prepared the directory. Pass --run to "
              "start the permuter, or paste the command above.\n")

    if args.run:
        # Windows resolves a child's program name against the *parent's*
        # PATH, so setting it on the child env alone would not work.
        if bindir:
            os.environ["PATH"] = f"{bindir}{os.pathsep}{os.environ['PATH']}"
        # shell=True puts the permuter behind a /bin/sh the signal never
        # reaches: `timeout N permute.py --run` TERMs this process, the sh
        # and its -j workers survive as orphans, and one such tree burned
        # four cores for two days after its function was already parked.
        # Run the tree in its own process group and forward the signal.
        import signal
        proc = subprocess.Popen(cmd, shell=True, cwd=ROOT,
                                start_new_session=True)

        def _forward(signum, _frame):
            try:
                os.killpg(proc.pid, signum)
            except OSError:
                pass

        for _sig in (signal.SIGTERM, signal.SIGINT, signal.SIGHUP):
            try:
                signal.signal(_sig, _forward)
            except (ValueError, OSError):
                pass
        try:
            proc.wait()
        finally:
            try:
                os.killpg(proc.pid, signal.SIGTERM)
            except OSError:
                pass
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
