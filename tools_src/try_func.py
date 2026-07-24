#!/usr/bin/env python3
"""
Fast single-function matching loop.

Compiles one snippet of candidate C with the real PsyQ toolchain and diffs
the resulting instructions against a target function's disassembly, without
running a full build. Use this while hunting for the C (and flags) that
reproduce a function, then fold the winner into src/ and verify with
tools_src/build.py.

    python tools_src/try_func.py func_80015010 candidate.c [-O2] [-G8] ...

Any trailing arguments are passed straight through to CC1PSX, so you can
sweep optimisation levels etc. without editing anything.
"""

import re
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
PSYQ_BIN = ROOT / "tools" / "psyq46" / "Psy-Q - 46" / "BIN"
CPPPSX = PSYQ_BIN / "CPPPSX.EXE"
CC1PSX = PSYQ_BIN / "CC1PSX.EXE"
ASM_DIR = ROOT / "asm" / "nonmatchings" / "31D8"
SCRATCH = ROOT / "build" / "scratch"

CPP_FLAGS = [
    "-undef", "-D__GNUC__=2", "-lang-c",
    "-Dmips", "-D__mips__", "-D__mips",
    "-Dpsx", "-D__psx__", "-D__psx",
    "-D_PSYQ", "-D__EXTENSIONS__", "-D_MIPSEL",
    "-D__CHAR_UNSIGNED__", "-D_LANGUAGE_C", "-DLANGUAGE_C",
    "-Iinclude",
]

# cc1psx writes numbered registers; the target disassembly uses ABI names.
REG_NAMES = {
    "$0": "$zero", "$1": "$at", "$2": "$v0", "$3": "$v1",
    "$4": "$a0", "$5": "$a1", "$6": "$a2", "$7": "$a3",
    "$8": "$t0", "$9": "$t1", "$10": "$t2", "$11": "$t3",
    "$12": "$t4", "$13": "$t5", "$14": "$t6", "$15": "$t7",
    "$16": "$s0", "$17": "$s1", "$18": "$s2", "$19": "$s3",
    "$20": "$s4", "$21": "$s5", "$22": "$s6", "$23": "$s7",
    "$24": "$t8", "$25": "$t9", "$28": "$gp", "$29": "$sp",
    "$30": "$fp", "$31": "$ra",
}


def normalise(line):
    """Reduce an asm line to `mnemonic operands` for comparison."""
    line = line.split("#")[0].strip()
    if not line or line.startswith((".", "/*")):
        return None
    line = re.sub(r"/\*.*?\*/", "", line)
    parts = line.replace(",", " , ").split()
    if not parts:
        return None
    out = []
    for p in parts:
        out.append(REG_NAMES.get(p, p))
    text = " ".join(out).replace(" , ", ",")
    # `j $ra` and `jr $ra` are the same instruction spelled two ways.
    text = re.sub(r"^j\b", "jr", text) if text.startswith("j $ra") else text
    # cc1psx emits small-data references bare (`lhu $v0,sym`); the assembler
    # turns them into the gp-relative form the disassembly shows. Same thing.
    text = re.sub(r"%gp_rel\(([^)]*)\)\(\$gp\)", r"\1", text)
    return text.lower()


def target_lines(func):
    path = ASM_DIR / f"{func}.s"
    if not path.exists():
        sys.exit(f"no disassembly for {func} at {path}")
    out = []
    for line in path.read_text().splitlines():
        if "/*" in line and "*/" in line:
            body = line.split("*/", 1)[1]
            n = normalise(body)
            if n:
                out.append(n)
    return out


def built_lines(func, csrc, extra_flags):
    SCRATCH.mkdir(parents=True, exist_ok=True)
    src = SCRATCH / "try.c"
    src.write_text(Path(csrc).read_text())
    pre, asm = SCRATCH / "try.i", SCRATCH / "try.s"

    for cmd in (
        [CPPPSX, *CPP_FLAGS, src.relative_to(ROOT).as_posix(),
         pre.relative_to(ROOT).as_posix()],
        [CC1PSX, "-quiet", *extra_flags, pre.relative_to(ROOT).as_posix(),
         "-o", asm.relative_to(ROOT).as_posix()],
    ):
        r = subprocess.run([str(c) for c in cmd], cwd=ROOT,
                           capture_output=True, text=True)
        if r.returncode != 0:
            sys.exit(f"{Path(str(cmd[0])).name} failed:\n{r.stdout}\n{r.stderr}")

    out, inside = [], False
    for line in asm.read_text().splitlines():
        if line.startswith(f"{func}:"):
            inside = True
            continue
        if inside:
            if ".end" in line:
                break
            n = normalise(line)
            if n:
                out.append(n)
    return out


def main():
    if len(sys.argv) < 3:
        sys.exit(__doc__)
    func, csrc, flags = sys.argv[1], sys.argv[2], sys.argv[3:] or ["-O2", "-G8"]

    want = target_lines(func)
    got = built_lines(func, csrc, flags)

    # The target keeps explicit load-delay nops that the compiler leaves to
    # the assembler to insert, so ignore bare nops when lining things up.
    w = [l for l in want if l != "nop"]
    g = [l for l in got if l != "nop"]

    print(f"flags: {' '.join(flags)}")
    print(f"{'TARGET':<44} {'BUILT'}")
    print("-" * 90)
    bad = 0
    for i in range(max(len(w), len(g))):
        a = w[i] if i < len(w) else ""
        b = g[i] if i < len(g) else ""
        mark = "  " if a == b else "<<"
        if a != b:
            bad += 1
        print(f"{a:<44} {b:<40} {mark}")
    print("-" * 90)
    print("MATCH" if bad == 0 and len(w) == len(g)
          else f"{bad} differing instruction(s)")
    return 0 if bad == 0 else 1


if __name__ == "__main__":
    raise SystemExit(main())
