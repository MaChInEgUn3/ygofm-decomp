#!/usr/bin/env python3
"""
Build harness for the Yu-Gi-Oh! Forbidden Memories matching decompilation.

Reproduces the original SLUS_014.11 executable from asm/ + src/ using the
real PsyQ 4.6 toolchain, then verifies the result is byte-identical to the
retail binary via sha1.

Pipeline per C file:
    CPPPSX.EXE  (preprocess)
      -> CC1PSX.EXE  (compile to MIPS asm)
      -> maspsx      (rewrite PsyQ asm quirks into GNU as syntax)
      -> mipsel-none-elf-as  (assemble)

Raw .s files (header, data segments) go straight to the assembler.
Everything is then linked with the splat-generated linker script and
objcopy'd to a flat binary.

We use a Python script rather than a Makefile because `make` is not
available in this project's Windows environment; the dependency graph here
is shallow enough that a plain script with mtime checks is sufficient.

Run from the repo root:  python tools_src/build.py
"""

import argparse
import hashlib
import os
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

# --- build configuration -----------------------------------------------------
BUILD = ROOT / "build"
LD_SCRIPT = ROOT / "config" / "slus_014.11.ld"
ELF = BUILD / "slus_014.11.elf"
TARGET_BIN = BUILD / "slus_014.11.bin"
EXPECTED_SHA1 = "84747e64f6da8e764206ec203e489acf8c9dcf7d"

# ASPSX version bundled with PsyQ 4.6; maspsx emulates its quirks.
ASPSX_VERSION = "2.86"

# Flags cc1psx was invoked with. -O2 is the near-universal choice for
# retail PS1 titles; revisit per-file if some functions refuse to match.
CC1_FLAGS = ["-quiet", "-O2", "-G0"]

# Mirrors what decomp.me's PsyQ backend passes to cpppsx.
CPP_FLAGS = [
    "-undef", "-D__GNUC__=2", "-lang-c",
    "-Dmips", "-D__mips__", "-D__mips",
    "-Dpsx", "-D__psx__", "-D__psx",
    "-D_PSYQ", "-D__EXTENSIONS__", "-D_MIPSEL",
    "-D__CHAR_UNSIGNED__", "-D_LANGUAGE_C", "-DLANGUAGE_C",
    "-Iinclude",
]

# -G0 keeps the assembler from putting anything in the small-data section on
# its own; the original binary's gp-relative layout is already baked into the
# disassembly. -no-pad-sections is required for byte-exact section sizes.
AS_FLAGS = [
    "-EL", "-march=r3000", "-mtune=r3000",
    "-no-pad-sections", "-O0", "-G0",
    "-I.", "-Iinclude",
]


def run(cmd, **kwargs):
    """Run a command from the repo root, raising with useful output on failure."""
    kwargs.setdefault("cwd", ROOT)
    result = subprocess.run(
        [str(c) for c in cmd],
        capture_output=True,
        text=True,
        **kwargs,
    )
    if result.returncode != 0:
        sys.stderr.write(f"\nCommand failed: {' '.join(str(c) for c in cmd)}\n")
        if result.stdout:
            sys.stderr.write(result.stdout[:8000] + "\n")
        if result.stderr:
            sys.stderr.write(result.stderr[:8000] + "\n")
        raise SystemExit(1)
    return result


def check_toolchain():
    missing = [
        str(p) for p in (CPPPSX, CC1PSX, AS, LD, OBJCOPY, MASPSX, VENV_PYTHON)
        if not p.exists()
    ]
    if missing:
        sys.stderr.write(
            "Missing toolchain components (see docs/DECISIONS.md for where to get each):\n"
        )
        for m in missing:
            sys.stderr.write(f"  {m}\n")
        raise SystemExit(1)


def compile_c(src: Path) -> Path:
    """cpppsx -> cc1psx -> maspsx -> as, returning the object path."""
    rel = src.relative_to(ROOT)
    stem = rel.with_suffix("")
    out_dir = BUILD / stem.parent
    out_dir.mkdir(parents=True, exist_ok=True)

    preprocessed = BUILD / stem.with_suffix(".i")
    compiled = BUILD / stem.with_suffix(".s")
    maspsx_out = BUILD / stem.with_suffix(".maspsx.s")
    obj = BUILD / stem.with_suffix(".o")

    run([CPPPSX, *CPP_FLAGS, rel.as_posix(), preprocessed.relative_to(ROOT).as_posix()])
    run([CC1PSX, *CC1_FLAGS,
         preprocessed.relative_to(ROOT).as_posix(),
         "-o", compiled.relative_to(ROOT).as_posix()])

    # maspsx reads the compiler's asm on stdin and writes GNU-as-ready asm out.
    with open(compiled, "r") as fin, open(maspsx_out, "w") as fout:
        result = subprocess.run(
            [str(VENV_PYTHON), str(MASPSX),
             f"--aspsx-version={ASPSX_VERSION}", "--macro-inc"],
            stdin=fin, stdout=fout, stderr=subprocess.PIPE,
            text=True, cwd=ROOT,
        )
    if result.returncode != 0:
        sys.stderr.write(f"maspsx failed on {rel}:\n{result.stderr[:8000]}\n")
        raise SystemExit(1)

    run([AS, *AS_FLAGS, "-o", obj.relative_to(ROOT).as_posix(),
         maspsx_out.relative_to(ROOT).as_posix()])
    return obj


def assemble_s(src: Path) -> Path:
    """Assemble a raw .s (header / data segments) straight to an object."""
    rel = src.relative_to(ROOT)
    obj = BUILD / rel.with_suffix(".o")
    obj.parent.mkdir(parents=True, exist_ok=True)
    run([AS, *AS_FLAGS, "-o", obj.relative_to(ROOT).as_posix(), rel.as_posix()])
    return obj


def read_defsyms():
    """splat emits symbols it couldn't place as `name = 0xADDR;` lines.

    These live outside our defined segments (mostly addresses in the trailing
    carddata region), so the linker needs them supplied explicitly.
    """
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
    ELF.parent.mkdir(parents=True, exist_ok=True)
    run([LD, "-T", LD_SCRIPT.relative_to(ROOT).as_posix(),
         "-Map", (BUILD / "slus_014.11.map").relative_to(ROOT).as_posix(),
         "--no-check-sections",
         *read_defsyms(),
         "-o", ELF.relative_to(ROOT).as_posix()])

    run([OBJCOPY, "-O", "binary",
         ELF.relative_to(ROOT).as_posix(),
         TARGET_BIN.relative_to(ROOT).as_posix()])

    actual = hashlib.sha1(TARGET_BIN.read_bytes()).hexdigest()
    print(f"\nbuilt : {TARGET_BIN.relative_to(ROOT)}")
    print(f"sha1  : {actual}")
    print(f"want  : {EXPECTED_SHA1}")
    if actual == EXPECTED_SHA1:
        print("\nOK: build is byte-identical to the retail executable.")
        return 0

    original = ROOT / "extracted" / "SLUS_014.11"
    if original.exists():
        want = original.read_bytes()
        got = TARGET_BIN.read_bytes()
        print(f"\nMISMATCH: {len(got)} bytes built vs {len(want)} bytes expected")
        limit = min(len(want), len(got))
        for i in range(limit):
            if want[i] != got[i]:
                print(f"first differing byte at file offset 0x{i:X} "
                      f"(vram ~0x{0x80010000 + i - 0x800:08X}): "
                      f"expected {want[i]:02X}, got {got[i]:02X}")
                break
        else:
            print("common prefix matches; files differ only in length")
    else:
        print("\nMISMATCH (original executable not present for a byte-level diff)")
    return 1


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--clean", action="store_true",
                        help="remove build/ before building")
    args = parser.parse_args()

    check_toolchain()

    if args.clean and BUILD.exists():
        import shutil
        shutil.rmtree(BUILD)

    objects = []

    asm_sources = sorted((ROOT / "asm").glob("*.s")) + \
                  sorted((ROOT / "asm" / "data").glob("*.s"))
    for src in asm_sources:
        print(f"as   {src.relative_to(ROOT)}")
        objects.append(assemble_s(src))

    for src in sorted((ROOT / "src").rglob("*.c")):
        print(f"cc   {src.relative_to(ROOT)}")
        objects.append(compile_c(src))

    print(f"\nlinking {len(objects)} objects")
    return link_and_verify()


if __name__ == "__main__":
    raise SystemExit(main())
