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

# Every toolchain constant comes from build.py rather than being restated
# here. This file used to keep its own copies, and they went stale without
# anyone noticing: it still pointed at psyq46 after the SDK was corrected to
# 4.5, still passed --aspsx-version=2.86, still ran the Windows venv python,
# and never applied the post-passes. So it would have compiled a candidate
# with the *wrong compiler* and printed a confident side-by-side diff about
# it. Importing is what keeps the two honest -- there is nothing left to
# drift.
sys.path.insert(0, str(Path(__file__).resolve().parent))
import build as B  # noqa: E402

ROOT = B.ROOT
PSYQ_BIN, CPPPSX, CC1PSX = B.PSYQ_BIN, B.CPPPSX, B.CC1PSX
PSYQ_RUNNER = B.PSYQ_RUNNER
ASM_DIR = B.ASM_FUNCS
MASPSX, VENV_PYTHON = B.MASPSX, B.VENV_PYTHON
CPP_FLAGS = B.CPP_FLAGS
SCRATCH = ROOT / "build" / "scratch"

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
    # Numbered registers appear bare and inside operands like `0($4)`, so
    # rewrite them wherever they occur rather than only as whole tokens.
    line = re.sub(r"\$(\d+)\b", lambda m: REG_NAMES.get("$" + m.group(1),
                                                       "$" + m.group(1)), line)
    parts = line.replace(",", " , ").split()
    if not parts:
        return None
    text = " ".join(parts).replace(" , ", ",")
    # `li $r,N` is a pseudo-instruction; for small N the assembler emits
    # exactly `addiu $r,$zero,N`, which is what the disassembly shows.
    # The disassembly spells split constants as expressions; evaluate them
    # so `(0x808080 >> 16)` compares against a plain 0x80.
    text = re.sub(r"\((0x[0-9a-fA-F]+|\d+)\s*>>\s*(\d+)\)",
                  lambda m: str(int(m.group(1), 0) >> int(m.group(2))), text)
    text = re.sub(r"\((0x[0-9a-fA-F]+|\d+)\s*&\s*(0x[0-9a-fA-F]+|\d+)\)",
                  lambda m: str(int(m.group(1), 0) & int(m.group(2), 0)), text)

    m = re.match(r"li (\$\w+),(-?(?:0x)?[0-9a-fA-F]+)$", text)
    if m:
        value = int(m.group(2), 0)
        if -0x8000 <= value < 0x8000:
            text = f"addiu {m.group(1)},$zero,{value}"
        elif value > 0 and (value & 0xFFFF) == 0:
            # a constant with no low half assembles to a bare lui
            text = f"lui {m.group(1)},{value >> 16}"
    # `j $ra` and `jr $ra` are the same instruction spelled two ways.
    text = re.sub(r"^j\b", "jr", text) if text.startswith("j $ra") else text
    # cc1psx emits small-data references bare (`lhu $v0,sym`); the assembler
    # turns them into the gp-relative form the disassembly shows. Same thing.
    text = re.sub(r"%gp_rel\(([^)]*)\)\(\$gp\)", r"\1", text)
    # Immediates and offsets are written 0x1618 in one place and 5656 in
    # the other; normalise every hex literal to decimal so they compare.
    text = re.sub(r"\b0x([0-9a-fA-F]+)\b",
                  lambda m: str(int(m.group(1), 16)), text)
    text = text.lower()

    # Label definitions occupy no bytes; the two sides can never agree on
    # their names, and renumber_labels only handles references.
    if re.match(r"^(?:\$|\.)?l?\w*:$", text) or text.endswith(":"):
        return None

    # Pseudo-instructions the two sides spell differently but which
    # assemble identically.
    text = re.sub(r"^move (\$\w+),(\$\w+)$", r"addu \1,\2,$zero", text)
    text = re.sub(r"^beqz (\$\w+),", r"beq \1,$zero,", text)
    text = re.sub(r"^bnez (\$\w+),", r"bne \1,$zero,", text)
    text = re.sub(r"^negu (\$\w+),(\$\w+)$", r"subu \1,$zero,\2", text)
    # gcc writes the register form with an immediate operand; the assembler
    # emits the immediate instruction, which is what the disassembly shows.
    text = re.sub(r"^(add|sub|and|or|xor|slt|sltu)u? (\$\w+),(\$\w+),(-?\d+)$",
                  lambda m: f"{m.group(1)}iu "
                            f"{m.group(2)},{m.group(3)},{m.group(4)}"
                  if m.group(1) in ("add", "sub", "slt", "sltu")
                  else f"{m.group(1)}i {m.group(2)},{m.group(3)},{m.group(4)}",
                  text)
    return text


def target_lines(func):
    path = ASM_DIR / f"{func}.s"
    if not path.exists():
        sys.exit(f"no disassembly for {func} at {path}")
    out = []
    for line in path.read_text().splitlines():
        # Anything past endlabel is inter-object padding, not part of the
        # function -- see the translation-unit boundary note in DECISIONS.md.
        if line.strip().startswith("endlabel"):
            break
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
        [*PSYQ_RUNNER, CPPPSX, *CPP_FLAGS, src.relative_to(ROOT).as_posix(),
         pre.relative_to(ROOT).as_posix()],
        [*PSYQ_RUNNER, CC1PSX, *extra_flags, pre.relative_to(ROOT).as_posix(),
         "-o", asm.relative_to(ROOT).as_posix()],
    ):
        r = subprocess.run([str(c) for c in cmd], cwd=ROOT,
                           capture_output=True, text=True)
        if r.returncode != 0:
            sys.exit(f"{Path(str(cmd[0])).name} failed:\n{r.stdout}\n{r.stderr}")

    # Run maspsx as the build does. It inserts the load-delay nops the
    # compiler leaves to the assembler, and those nops are real
    # instructions -- comparing pre-maspsx output silently ignores them and
    # will call a function matching when it is several instructions short.
    masm = SCRATCH / "try.maspsx.s"
    with open(asm) as fin, open(masm, "w") as fout:
        r = subprocess.run(
            [str(VENV_PYTHON), str(MASPSX),
             f"--aspsx-version={B.ASPSX_VERSION}", "--macro-inc"],
            stdin=fin, stdout=fout, stderr=subprocess.PIPE, text=True, cwd=ROOT)
    if r.returncode != 0:
        sys.exit(f"maspsx failed:\n{r.stderr[:4000]}")

    # The build applies these after maspsx; a diff taken without them is a
    # diff against a file the build would never produce.
    text = masm.read_text().splitlines()
    if func in B.DELAY_SLOT_MACRO_FUNCS:
        text = B.fill_delay_slot_with_macro_tail(text)
    if func in B.SMALL_DATA_NOP_FUNCS:
        text = B.insert_small_data_load_delay_nops(text)
    if func in B.HOIST_EPILOGUE_FUNCS:
        text = B.hoist_epilogue_out_of_delay_slot(text)

    out, inside = [], False
    for line in text:
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


def renumber_labels(lines):
    """Rewrite branch labels positionally so the two sides can be compared.

    gcc emits `$L3`, the disassembly has `.L80058E34`. The names can never
    agree, so map each side's labels to L1, L2, ... in order of first
    appearance; a real control-flow difference still shows up as a
    mismatch, but the naming no longer does.
    """
    mapping, counter, out = {}, 0, []
    label_re = re.compile(r"(?:\$|\.)l[0-9a-f]+", re.IGNORECASE)

    def sub(m):
        nonlocal counter
        key = m.group(0)
        if key not in mapping:
            counter += 1
            mapping[key] = f"L{counter}"
        return mapping[key]

    for line in lines:
        out.append(label_re.sub(sub, line))
    return out


def main():
    if len(sys.argv) < 3:
        sys.exit(__doc__)
    func, csrc = sys.argv[1], sys.argv[2]
    # Default to the flags the build would use for this very function,
    # including any per-function override, not to a guess at the defaults.
    flags = sys.argv[3:] or list(B.PER_FUNC_FLAGS.get(func, B.CC1_FLAGS))

    want = renumber_labels(target_lines(func))
    got = renumber_labels(built_lines(func, csrc, flags))

    # maspsx inserts the load-delay nops, so both sides now carry them and
    # they must be compared -- they occupy real bytes.
    w, g = want, got

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
