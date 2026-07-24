#!/usr/bin/env python3
"""
Build harness for the Yu-Gi-Oh! Forbidden Memories matching decompilation.

Reproduces the original SLUS_014.11 executable from asm/ + src/ using the
real PsyQ 4.6 toolchain, then verifies the result is byte-identical to the
retail binary via sha1.

Layout is driven by the linker script, not by compiler output order. Every
function is placed individually, in address order:

  * a function that has been decompiled lives in src/<func_name>.c and is
    compiled to its own object;
  * every run of consecutive not-yet-decompiled functions is gathered into
    one generated .s (build/gen/) and assembled as a single object.

This matters because cc1psx, when small-data is enabled (-G, required to
reproduce gp-relative global access), defers ALL C function output to the
end of the translation unit. Mixing INCLUDE_ASM with real C in one file
would therefore scramble .text. Placing each function separately makes
emission order irrelevant. See docs/DECISIONS.md.

Pipeline per C file:
    CPPPSX.EXE -> CC1PSX.EXE -> maspsx -> mipsel-none-elf-as

Run from the repo root:  python tools_src/build.py
"""

import argparse
import hashlib
import re
import shutil
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent

# --- toolchain locations (all gitignored, see docs/DECISIONS.md) -------------
PSYQ_BIN = ROOT / "tools" / "psyq46" / "Psy-Q - 46" / "BIN"
CPPPSX = PSYQ_BIN / "CPPPSX.EXE"
CC1PSX = PSYQ_BIN / "CC1PSX.EXE"

MIPS_BIN = ROOT / "tools" / "mips" / "bin"
AS = MIPS_BIN / "mipsel-none-elf-as.exe"
LD = MIPS_BIN / "mipsel-none-elf-ld.exe"
OBJCOPY = MIPS_BIN / "mipsel-none-elf-objcopy.exe"

MASPSX = ROOT / "tools" / "maspsx" / "maspsx.py"
VENV_PYTHON = ROOT / ".venv" / "Scripts" / "python.exe"

# --- project layout ----------------------------------------------------------
SRC = ROOT / "src"
ASM_FUNCS = ROOT / "asm" / "nonmatchings" / "31D8"
BUILD = ROOT / "build"
GEN = BUILD / "gen"
SPLAT_LD = ROOT / "config" / "slus_014.11.ld"
GEN_LD = GEN / "slus_014.11.ld"
BOUNDARIES = ROOT / "docs" / "FILE_BOUNDARIES.txt"
ELF = BUILD / "slus_014.11.elf"
TARGET_BIN = BUILD / "slus_014.11.bin"
EXPECTED_SHA1 = "84747e64f6da8e764206ec203e489acf8c9dcf7d"

# The object splat's linker script expects the whole code segment to come
# from; we substitute our per-function objects for it.
SPLAT_CODE_OBJ = "build/src/31D8.o"

# ASPSX version bundled with PsyQ 4.6; maspsx emulates its quirks.
ASPSX_VERSION = "2.86"

# -G8 enables small-data/gp-relative access, which the retail code uses for
# most globals. The assembler's -G must match, or it cannot assume a bare
# symbol is small data and expands each reference into a lui/%lo pair.
# The -O level is NOT confirmed for this game and may vary per function;
# see docs/DECISIONS.md.
CC1_FLAGS = ["-quiet", "-O2", "-G8"]

CPP_FLAGS = [
    "-undef", "-D__GNUC__=2", "-lang-c",
    "-Dmips", "-D__mips__", "-D__mips",
    "-Dpsx", "-D__psx__", "-D__psx",
    "-D_PSYQ", "-D__EXTENSIONS__", "-D_MIPSEL",
    "-D__CHAR_UNSIGNED__", "-D_LANGUAGE_C", "-DLANGUAGE_C",
    "-Iinclude",
]

# -no-pad-sections and -O0 are required for byte-exact section contents.
AS_FLAGS = [
    "-EL", "-march=r3000", "-mtune=r3000",
    "-no-pad-sections", "-O0", "-G8",
    "-I.", "-Iinclude",
]

# Per-function compiler flags. The retail game was built from ~234 separate
# translation units and clearly did not use one flag set throughout, so
# expect this table to keep growing; it is normal, not a smell.
#
# Two recurring cases so far:
#   -O1        some units were built at -O1; it changes register allocation.
#   -G0        a unit whose globals are reached with explicit %hi/%lo pairs
#              rather than gp-relative. Such a function usually needs
#              PER_FUNC_AS_FLAGS too, so the assembler agrees.
_O1_G8 = ["-quiet", "-O1", "-G8"]
_O1_G0 = ["-quiet", "-O1", "-G0"]
# -mno-split-addresses leaves the address in macro form for the assembler to
# expand via $at, which is what the retail code shows for these.
_O1_G0_MACRO = ["-quiet", "-O1", "-G0", "-mno-split-addresses"]

_G0_FUNCS = [
    "func_8003B734", "func_80058F10", "func_8004544C", "func_80049594",
    "func_800495DC", "func_8007BAC0", "func_8007BF04",
    "func_8007BF14", "func_8007BF30", "func_8007BF40", "func_8007BF50",
    "func_8007BF60", "func_8007CD14", "func_8007F5C4", "func_80085320",
    "func_80044FE4", "func_8004503C", "func_800490F0", "func_80049108",
    "func_80049120", "func_800744F4", "func_80080B6C",
    "func_800901D4", "func_80030090", "func_800300AC",
    "func_80082274",     ]
# Stores the assembler expands through $at. These need the macro form from
# the compiler *and* an assembler that will not treat the symbol as small
# data, so they carry a PER_FUNC_AS_FLAGS entry too.
_G0_MACRO_FUNCS = [
    "func_80082A80", "func_8008D1E0", "func_8008D1F4", "func_8008D208",
    "func_8008D21C", "func_8008D230", "func_8008D244", "func_8008D258",
    "func_8008D26C", "func_8002F930", "func_8002F94C",
    ]

PER_FUNC_FLAGS = {
    "func_80015010": _O1_G8,
    "func_80047008": _O1_G8,
    "func_8004703C": _O1_G8,
    "func_80038D14": _O1_G8,
    "func_800828A0": _O1_G8,
    "func_800828C0": _O1_G8,
    "func_800828E0": _O1_G8,
    "func_80082900": _O1_G8,
}
PER_FUNC_FLAGS.update({n: _O1_G0 for n in _G0_FUNCS})
PER_FUNC_FLAGS.update({n: _O1_G0_MACRO for n in _G0_MACRO_FUNCS})

# Per-function assembler flags. Needed when the compiler emits a bare symbol
# reference and the assembler's -G decides whether to make it gp-relative or
# expand it into a lui/%lo pair through $at.
PER_FUNC_AS_FLAGS = {n: "-G0" for n in _G0_MACRO_FUNCS}


def run(cmd, **kwargs):
    kwargs.setdefault("cwd", ROOT)
    result = subprocess.run([str(c) for c in cmd], capture_output=True,
                            text=True, **kwargs)
    if result.returncode != 0:
        sys.stderr.write(f"\nCommand failed: {' '.join(str(c) for c in cmd)}\n")
        for stream in (result.stdout, result.stderr):
            if stream:
                sys.stderr.write(stream[:8000] + "\n")
        raise SystemExit(1)
    return result


def check_toolchain():
    missing = [str(p) for p in (CPPPSX, CC1PSX, AS, LD, OBJCOPY, MASPSX,
                                VENV_PYTHON) if not p.exists()]
    if missing:
        sys.stderr.write("Missing toolchain components "
                         "(see docs/DECISIONS.md for where to get each):\n")
        for m in missing:
            sys.stderr.write(f"  {m}\n")
        raise SystemExit(1)


def func_addr(name):
    return int(name.split("_")[1], 16)


def ordered_functions():
    """Every function in the code segment, in address order."""
    names = [p.stem for p in ASM_FUNCS.glob("func_*.s")]
    if not names:
        sys.exit(f"no disassembly in {ASM_FUNCS} — run `splat split` first")
    return sorted(names, key=func_addr)


def boundary_functions():
    """Functions that end an original translation unit.

    The retail binary pads each object's .text out to 16 bytes. For a
    function still assembled from its .s that padding is already in the
    file; for one we've decompiled we have to reinstate it, which the
    linker script does with an explicit ALIGN.
    """
    if not BOUNDARIES.exists():
        return set()
    out = set()
    for line in BOUNDARIES.read_text().splitlines():
        if line.startswith("#") or not line.strip():
            continue
        parts = line.split()
        if len(parts) >= 2:
            out.add(parts[1])
    return out


def compile_c(name):
    """cpppsx -> cc1psx -> maspsx -> as for one decompiled function."""
    src = SRC / f"{name}.c"
    out_dir = BUILD / "src"
    out_dir.mkdir(parents=True, exist_ok=True)
    pre = out_dir / f"{name}.i"
    asm = out_dir / f"{name}.s"
    masm = out_dir / f"{name}.maspsx.s"
    obj = out_dir / f"{name}.o"

    flags = PER_FUNC_FLAGS.get(name, CC1_FLAGS)
    run([CPPPSX, *CPP_FLAGS, src.relative_to(ROOT).as_posix(),
         pre.relative_to(ROOT).as_posix()])
    run([CC1PSX, *flags, pre.relative_to(ROOT).as_posix(),
         "-o", asm.relative_to(ROOT).as_posix()])

    with open(asm) as fin, open(masm, "w") as fout:
        r = subprocess.run(
            [str(VENV_PYTHON), str(MASPSX),
             f"--aspsx-version={ASPSX_VERSION}", "--macro-inc"],
            stdin=fin, stdout=fout, stderr=subprocess.PIPE, text=True, cwd=ROOT)
    if r.returncode != 0:
        sys.stderr.write(f"maspsx failed on {src.name}:\n{r.stderr[:8000]}\n")
        raise SystemExit(1)

    as_flags = list(AS_FLAGS)
    override = PER_FUNC_AS_FLAGS.get(name)
    if override:
        # later -G wins, so appending is enough to override the default
        as_flags.append(override)
    run([AS, *as_flags, "-o", obj.relative_to(ROOT).as_posix(),
         masm.relative_to(ROOT).as_posix()])
    return obj


def object_func_size(obj, name):
    """Size of `name` as compiled, read back from the object's symbol table."""
    r = run([OBJCOPY.with_name("mipsel-none-elf-objdump.exe"), "-t",
             obj.relative_to(ROOT).as_posix()])
    for line in r.stdout.splitlines():
        parts = line.split()
        if parts and parts[-1] == name and len(parts) >= 5:
            try:
                return int(parts[-2], 16)
            except ValueError:
                continue
    return None


def assemble_run(index, names):
    """Assemble a run of consecutive not-yet-decompiled functions."""
    GEN.mkdir(parents=True, exist_ok=True)
    stub = GEN / f"run_{index:04d}.s"
    lines = ['.include "include/macro.inc"', "", ".section .text",
             ".set noat", ".set noreorder", ""]
    for n in names:
        lines.append(f'.include "asm/nonmatchings/31D8/{n}.s"')
    stub.write_text("\n".join(lines) + "\n")
    obj = GEN / f"run_{index:04d}.o"
    run([AS, *AS_FLAGS, "-o", obj.relative_to(ROOT).as_posix(),
         stub.relative_to(ROOT).as_posix()])
    return obj


def assemble_plain(src: Path) -> Path:
    obj = BUILD / src.relative_to(ROOT).with_suffix(".o")
    obj.parent.mkdir(parents=True, exist_ok=True)
    run([AS, *AS_FLAGS, "-o", obj.relative_to(ROOT).as_posix(),
         src.relative_to(ROOT).as_posix()])
    return obj


def write_linker_script(text_entries):
    """Rewrite splat's linker script to place our per-function objects.

    splat emits a single `build/src/31D8.o(<section>);` line per section,
    assuming one object for the whole code segment. We swap the .text one
    for the ordered per-function list and drop the rest, since our objects
    contribute no rodata/data/bss of their own.
    """
    GEN.mkdir(parents=True, exist_ok=True)
    out = []
    for line in SPLAT_LD.read_text().splitlines():
        stripped = line.strip()
        m = re.match(rf"{re.escape(SPLAT_CODE_OBJ)}\((\.\w+)\);", stripped)
        if not m:
            out.append(line)
            continue
        if m.group(1) != ".text":
            continue  # our objects have no rodata/data/bss to contribute
        indent = line[: len(line) - len(line.lstrip())]
        out.extend(indent + e for e in text_entries)
    GEN_LD.write_text("\n".join(out) + "\n")


def read_defsyms():
    """splat emits symbols it couldn't place as `name = 0xADDR;` lines."""
    defsyms = []
    for name in ("undefined_syms_auto.txt", "undefined_funcs_auto.txt"):
        path = ROOT / "config" / name
        if not path.exists():
            continue
        for line in path.read_text().splitlines():
            line = line.split("//")[0].split("#")[0].strip().rstrip(";").strip()
            if not line or "=" not in line:
                continue
            sym, _, value = line.partition("=")
            defsyms += ["--defsym", f"{sym.strip()}={value.strip()}"]
    return defsyms


def link_and_verify():
    run([LD, "-T", GEN_LD.relative_to(ROOT).as_posix(),
         "-Map", (BUILD / "slus_014.11.map").relative_to(ROOT).as_posix(),
         "--no-check-sections", *read_defsyms(),
         "-o", ELF.relative_to(ROOT).as_posix()])
    run([OBJCOPY, "-O", "binary", ELF.relative_to(ROOT).as_posix(),
         TARGET_BIN.relative_to(ROOT).as_posix()])

    actual = hashlib.sha1(TARGET_BIN.read_bytes()).hexdigest()
    print(f"\nbuilt : {TARGET_BIN.relative_to(ROOT)}")
    print(f"sha1  : {actual}")
    print(f"want  : {EXPECTED_SHA1}")
    if actual == EXPECTED_SHA1:
        print("\nOK: build is byte-identical to the retail executable.")
        return 0

    original = ROOT / "extracted" / "SLUS_014.11"
    if not original.exists():
        print("\nMISMATCH (original not present for a byte-level diff)")
        return 1

    want, got = original.read_bytes(), TARGET_BIN.read_bytes()
    print(f"\nMISMATCH: {len(got)} bytes built vs {len(want)} expected")
    report_bad_functions(want, got)
    return 1


def report_bad_functions(want, got):
    """Map differing bytes back to the functions they belong to.

    With a whole-binary diff the first bad byte is rarely informative: one
    wrong function shifts everything after it. Attributing differences to
    named functions says directly which sources to look at.
    """
    funcs = ordered_functions()
    spans = []           # (start_file_off, end_file_off, name)
    for name in funcs:
        addr = func_addr(name)
        size = target_size(name)
        start = 0x800 + (addr - 0x80010000)
        spans.append((start, start + size, name))

    limit = min(len(want), len(got))
    bad, first_off = [], None
    for start, end, name in spans:
        if start >= limit:
            break
        chunk_end = min(end, limit)
        if want[start:chunk_end] != got[start:chunk_end]:
            bad.append(name)
            if first_off is None:
                first_off = start

    decompiled = [n for n in bad if (SRC / f"{n}.c").exists()]
    if decompiled:
        print(f"\n{len(decompiled)} decompiled function(s) differ — "
              f"these are the ones to fix:")
        for n in decompiled[:25]:
            print(f"  {n}   (src/{n}.c)")
        if len(decompiled) > 25:
            print(f"  ... and {len(decompiled) - 25} more")
    if bad and not decompiled:
        print("\nNo decompiled function differs directly; the first bad "
              f"region is {bad[0]}, which is still assembled from .s — "
              "this usually means something before it changed size.")
    if not bad:
        print("\nAll function bodies match; the difference is outside "
              "function bodies (padding, data, or alignment).")


def target_size(name):
    """Size of a function as recorded in its disassembly header."""
    path = ASM_FUNCS / f"{name}.s"
    first = path.read_text().split("\n", 1)[0]
    m = re.search(r",\s*(0x[0-9A-Fa-f]+)", first)
    return int(m.group(1), 16) if m else 0


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("--clean", action="store_true", help="remove build/ first")
    args = ap.parse_args()

    check_toolchain()
    if args.clean and BUILD.exists():
        shutil.rmtree(BUILD)
    BUILD.mkdir(parents=True, exist_ok=True)

    functions = ordered_functions()
    decompiled = [n for n in functions if (SRC / f"{n}.c").exists()]
    boundaries = boundary_functions()
    print(f"{len(functions)} functions, {len(decompiled)} decompiled")

    # Walk the address-ordered list, emitting one object per decompiled
    # function and one per run of consecutive undecompiled ones.
    text_entries = []
    pending, run_index = [], 0
    size_errors = []
    for name in functions:
        if (SRC / f"{name}.c").exists():
            if pending:
                obj = assemble_run(run_index, pending)
                text_entries.append(
                    f"{obj.relative_to(ROOT).as_posix()}(.text);")
                run_index += 1
                pending = []
            obj = compile_c(name)
            # A wrong-sized function shifts everything after it, so the
            # whole-binary diff would blame dozens of innocent functions.
            # Catching size errors here keeps the blame local.
            built, wanted = object_func_size(obj, name), target_size(name)
            if built is not None and wanted and built != wanted:
                size_errors.append((name, built, wanted))
            text_entries.append(f"{obj.relative_to(ROOT).as_posix()}(.text);")
            if name in boundaries:
                # reinstate the original object's 16-byte .text padding
                text_entries.append(". = ALIGN(., 16);")
        else:
            pending.append(name)
    if pending:
        obj = assemble_run(run_index, pending)
        text_entries.append(f"{obj.relative_to(ROOT).as_posix()}(.text);")

    for src in sorted((ROOT / "asm").glob("*.s")) + \
               sorted((ROOT / "asm" / "data").glob("*.s")):
        assemble_plain(src)

    if size_errors:
        print(f"\n{len(size_errors)} function(s) compiled to the wrong size. "
              "Fix these first — each one shifts everything after it, so any "
              "other reported difference is probably just fallout:")
        for name, built, wanted in size_errors:
            delta = (built - wanted) // 4
            print(f"  {name}: {built:#x} vs {wanted:#x} expected "
                  f"({delta:+d} instructions)   src/{name}.c")

    write_linker_script(text_entries)
    print(f"placed {len(text_entries)} entries in .text")
    return link_and_verify()


if __name__ == "__main__":
    raise SystemExit(main())
