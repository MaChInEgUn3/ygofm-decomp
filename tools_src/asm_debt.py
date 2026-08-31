#!/usr/bin/env python3
"""
Count the assembly debt in src/, and mark it.

A function "matched" by transcribing its instructions into inline `__asm__` is
byte-exact, so `build.py` cannot tell it from real C. Nothing except a count
stops it being reported as finished work. This is that count, as a script
rather than as a `grep` someone has to get right, because getting it right by
hand failed twice on the same afternoon:

  * the first pass classified by "does the file contain a `.word` stream and a
    `.global`", which put a hand-encoded seven-word CALL SEQUENCE
    (`lui/ori/li/li/lui/jal/addiu` in func_8004B854) in the clean bucket
    because it had neither marker. 53 counted, 54 true.
  * the second pass scanned every string literal in the file, which meant the
    CONSTRAINTS and CLOBBERS of a legitimate GTE block -- `"=r"`, `"r"`,
    `"memory"`, `"v0"` -- were read as instructions. It reported 96 of 97 as
    debt. Only the instruction TEMPLATE counts, i.e. the strings before the
    first `:` at paren depth one.

Both errors are the same error the rest of this project keeps hitting: a tool
answering confidently about something it did not measure. The rule that would
have caught either in one minute is to check that the classifier can say both
words -- run it against a file you know is clean and one you know is not.

WHAT COUNTS AS DEBT

Coprocessor-2 instructions are not debt: C has no operators for `lwc2`,
`swc2`, `mtc2`, `rtps` and friends, and the geometry engine has to be reached
somehow. What IS debt is ordinary MIPS -- loads, stores, arithmetic, branches,
a `.global`, or a `.word` whose opcode field is not COP2/LWC2/SWC2 -- written
into an asm block to force a match.

**And "not debt" is not the same as "right".** krystalgamer pointed out on
2026-08-31 that the PsyQ SDK ships these as macros (`GTEMAC.H`, `INLINE_C.H`:
`gte_ldv0()`, `gte_rtps()`, `gte_stsxy()`), so a decomp should call those
rather than hand-roll the same instructions. Hand-written GTE asm is a smaller
debt than transcription, not zero. The macros expand to the same words, so
converting is free in bytes and pure gain in readability.

    .venv/bin/python tools_src/asm_debt.py            # count
    .venv/bin/python tools_src/asm_debt.py --mark     # count and write banners
"""

import glob
import re
import sys
from pathlib import Path

COP_MNEMONICS = {"lwc2", "swc2", "mtc2", "mfc2", "ctc2", "cfc2", "nop"}
# COP2 (0x12), LWC2 (0x32), SWC2 (0x3A) in the top six bits.
COP_OPCODES = (0x12, 0x32, 0x3A)

BANNER = """/* ASSEMBLY DEBT -- this is a TRANSCRIPTION, not a decompilation.
 * Ordinary MIPS written into an inline asm block to force a match. It is
 * byte-exact and therefore invisible to build.py, which is exactly the
 * problem: the oracle cannot tell transcribed assembly from real C, so
 * nothing but this comment stops it being counted as done.
 * Counted by tools_src/asm_debt.py; the standard is in docs/ASM_DEBT.md.
 */
"""


def templates(text):
    """The instruction template of each `__asm__` -- strings before the first
    `:` at depth one. Constraints and clobbers are strings too, and reading
    them as instructions is how the second miscount happened."""
    for m in re.finditer(r"__asm__\s*(?:volatile\s*)?\(", text):
        i, depth, instr, out = m.end(), 1, True, []
        while i < len(text) and depth:
            c = text[i]
            if c == "(":
                depth += 1
            elif c == ")":
                depth -= 1
            elif c == ":" and depth == 1:
                instr = False
            elif c == '"' and instr:
                j = text.index('"', i + 1)
                out.append(text[i + 1:j])
                i = j
            i += 1
        yield "".join(out)


def classify(path):
    """-> 'clean' | 'gte' | 'debt'."""
    text = Path(path).read_text(errors="replace")
    if "__asm__" not in text:
        return "clean"
    for tpl in templates(text):
        for line in tpl.replace("\\n", "\n").replace("\\t", " ").split("\n"):
            line = line.split("/*")[0].strip()
            if not line or line.startswith((".set", ".align")) or line.endswith(":"):
                continue
            if line.startswith(".global"):
                return "debt"
            if line.startswith(".word"):
                m = re.search(r"0x([0-9a-fA-F]+)", line)
                if m and ((int(m.group(1), 16) >> 26) & 0x3F) not in COP_OPCODES:
                    return "debt"
                continue
            if line.split()[0] not in COP_MNEMONICS:
                return "debt"
    return "gte"


def main():
    buckets = {"clean": [], "gte": [], "debt": []}
    for p in sorted(glob.glob("src/func_*.c")):
        buckets[classify(p)].append(p)

    total = sum(len(v) for v in buckets.values())
    print("src/func_*.c                 : %d" % total)
    print("  real C, no inline asm      : %d" % len(buckets["clean"]))
    print("  GTE coprocessor asm only   : %d  (should use the PsyQ gte_* macros)"
          % len(buckets["gte"]))
    print("  ASSEMBLY DEBT              : %d" % len(buckets["debt"]))
    print("\n  honest decompiled count    : %d" % (total - len(buckets["debt"])))

    if "--mark" in sys.argv:
        added = removed = 0
        for p in buckets["debt"]:
            t = Path(p).read_text(errors="replace")
            if "ASSEMBLY DEBT" not in t:
                Path(p).write_text(BANNER + t)
                added += 1
        for p in buckets["clean"] + buckets["gte"]:
            t = Path(p).read_text(errors="replace")
            if "ASSEMBLY DEBT" in t:
                Path(p).write_text(re.sub(r"^/\* ASSEMBLY DEBT.*?\*/\n", "", t,
                                          count=1, flags=re.S))
                removed += 1
        print("\nmarked %d, unmarked %d" % (added, removed))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
