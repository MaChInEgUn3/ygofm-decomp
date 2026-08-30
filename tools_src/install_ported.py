#!/usr/bin/env python3
"""
Install a function ported from the second decompilation tree, with provenance.

`tools_src/transplant.py` measures; this installs what measured MATCH. The two
are deliberately separate acts -- a manifest row is a claim about one function
compiled alone, and the only thing that settles a merge is `tools_src/build.py`
going green afterwards, which is a claim about the whole 1.9 MB image.

Ported files are installed SELF-CONTAINED: they keep the `extern` declarations
Unchiga's tree carries inline, and do not include `common.h`. That is a real
departure from this repo's rule that every global is declared once in
`include/variables.h`, and it is deliberate rather than lazy:

  * the declaration is a codegen input here, and his is often not ours -- his
    `u32 D_8009B0F4` against our `volatile s32 D_8009B0F4`, his
    `struct T800E9E18 D_800E9E18[]` against our `u8 D_800E9E18[]`. Rewriting
    his C onto our declarations is not a merge, it is a re-derivation, and it
    un-matched func_800137E4 by six instructions the first time it was tried.
  * a file that declares its own globals cannot change codegen in any OTHER
    file, which is the hazard the once-only rule exists to prevent. What it
    does cost is that variables.h stops being the whole story, so every ported
    file says so at the top and the manifest lists them.

Reconciling a ported file onto our headers is a later, per-function job: do it
by adding a guard arm for the declaration his C needs, never by editing the
default arm, and re-measure.

    python tools_src/install_ported.py func_800137E4 [func_... ...]
"""

import re
import subprocess
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import build as B  # noqa: E402

ROOT = B.ROOT
PORTED = ROOT / "build" / "transplant"

BANNER = """/* PORTED from Unchiga's decompilation of SLUS_014.11, shared 2026-08-30.
 * His C, his comments; the identifiers are rewritten to this repo's address
 * form and nothing else was touched. Verified the only way that counts here:
 * tools_src/build.py rebuilds the retail image byte-for-byte with this in it.
 *
 * Self-contained by design -- it keeps his declarations rather than ours,
 * because a declaration is a codegen input and his are what this C matched
 * under. See docs/MERGE_UNCHIGA.md and tools_src/install_ported.py.
 */
"""


FLAG_BLOCK = re.compile(r"(# >>> ported flags\nPORTED_FLAGS = \{\n)(.*?)(\})",
                        re.S)


def record_flags(entries):
    """Write each ported function's flags into build.py's PORTED_FLAGS block.

    Not optional and not cosmetic: try_func measures a ported function under
    HIS per-unit flags, and build.py compiles src/ from its own tables. Leave a
    function out and the two disagree -- func_800137E4 measured MATCH under
    `-G0 -mno-split-addresses`, came out six instructions short in the full
    build, and the size error then reported 847 unrelated functions as
    differing. The wrong-size line is the only one worth reading there.
    """
    p = ROOT / "tools_src" / "build.py"
    text = p.read_text()
    m = FLAG_BLOCK.search(text)
    if not m:
        raise SystemExit("build.py: `# >>> ported flags` block not found")
    body = m.group(2)
    for name, flags in entries.items():
        line = '    "%s": %s,\n' % (name, flags)
        body = re.sub(r'^    "%s":.*\n' % re.escape(name), "", body, flags=re.M)
        body += line
    keep = sorted(set(l for l in body.splitlines() if l.strip()))
    p.write_text(text[:m.start(2)] + "\n".join(keep) + "\n" + text[m.end(2):])


def flags_for(tree_flags):
    """His unit flags -> our CC1 list."""
    out = ["-quiet", "-O2"]
    g = [f for f in tree_flags if f.startswith("-G")]
    out.append(g[-1] if g else "-G8")
    out += [f for f in tree_flags if f.startswith("-mno-") or f.startswith("-fno-")]
    return out


def main():
    argv = sys.argv[1:]
    tree = None
    if argv and argv[0] == "--tree":
        tree, argv = Path(argv[1]), argv[2:]
    names = argv
    if not names or tree is None:
        print(__doc__)
        return 2

    sys.path.insert(0, str(ROOT / "tools_src"))
    import transplant as T
    units, unit_flags = T.their_units(tree), T.their_flags(tree)

    done, entries, backup = [], {}, (ROOT / "tools_src" / "build.py").read_text()
    for name in names:
        src = PORTED / (name + ".c")
        if not src.exists():
            print("%-16s no ported source (run transplant.py first)" % name)
            continue
        dst = ROOT / "src" / (name + ".c")
        if dst.exists():
            print("%-16s already in src/ -- skipped, this tool never overwrites"
                  % name)
            continue
        unit = units.get(int(name[5:], 16))
        cc = flags_for([f for f in (unit_flags.get(unit) or []) if T.CC1_OK.match(f)])
        dst.write_text(BANNER + src.read_text())
        done.append(name)
        if cc != list(B.CC1_FLAGS):
            entries[name] = cc
        print("%-16s installed   %s" % (name, " ".join(cc[2:])))
    if not done:
        return 1
    if entries:
        record_flags(entries)

    print("\nbuilding...", flush=True)
    r = subprocess.run([str(B.VENV_PYTHON), str(ROOT / "tools_src" / "build.py")],
                       cwd=ROOT, capture_output=True, text=True)
    out = (r.stdout + r.stderr).splitlines()
    # The wrong-size line is the only diagnostic worth reading on a red build:
    # one bad size shifts everything after it and the rest is fallout.
    for line in out:
        if "wrong size" in line or "vs" in line and "expected" in line:
            print(line)
    print("\n".join([l for l in out if l.strip()][-3:]))
    if r.returncode:
        print("\nBUILD RED -- backing the batch out.")
        for name in done:
            (ROOT / "src" / (name + ".c")).unlink()
        (ROOT / "tools_src" / "build.py").write_text(backup)
        return 1
    print("\nbuild green with %d ported function(s)." % len(done))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
