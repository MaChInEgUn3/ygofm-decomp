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
# A file that reaches the geometry engine through include/gte.h has no
# `__asm__` of its own -- the asm lives in the macro. Counting it as "real C,
# no inline asm" is how the split silently drifts as files are converted: the
# clean bucket grew by three the moment the last raw block went away, which is
# the same class of miscount as the two below wearing a nicer suit. A file that
# touches the GTE stays in the GTE bucket however it spells it.
GTE_MACRO = re.compile(r"\bgte_[a-z0-9_]+\s*\(")
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


def is_debt(tpl):
    """True when an instruction template contains ordinary MIPS."""
    for line in tpl.replace("\\n", "\n").replace("\\t", " ").split("\n"):
        line = line.split("/*")[0].strip()
        if not line or line.startswith((".set", ".align")) or line.endswith(":"):
            continue
        if line.startswith(".global"):
            return True
        if line.startswith(".word"):
            m = re.search(r"0x([0-9a-fA-F]+)", line)
            if m and ((int(m.group(1), 16) >> 26) & 0x3F) not in COP_OPCODES:
                return True
            continue
        if line.split()[0] not in COP_MNEMONICS:
            return True
    return False


def classify(path):
    """-> 'clean' | 'gte' | 'debt'.

    An EMPTY instruction template -- `__asm__ volatile("" ::: "memory")` -- is
    a compiler barrier, not assembly: it emits no words. Letting one fall
    through to the GTE bucket was the third instance of the miscount this file
    documents, because an empty template contains no offending mnemonic and so
    survives every test above.
    """
    text = Path(path).read_text(errors="replace")
    if any(is_debt(t) for t in templates(text)):
        return "debt"
    if GTE_MACRO.search(text):
        return "gte"
    if any(t.strip() for t in templates(text)):
        return "gte"
    return "clean"



def hand_written_original(name):
    """True when the retail listing cannot be compiler output at all.

    Measured 2026-09-04 over every transcription in src/: 52 of the 70 have
    NO stack frame, NO `sw $ra`, ZERO `jal`, and save four to ten `$s`
    registers somewhere other than the stack -- the caller's structure.
    No C compiler emits that; it is hand-written assembly in the original,
    and it can never be "retired" into C. The other 18 all have a frame or a
    call and save `$s` to `$sp`. func_80015DFC, a GTE user that IS compiled,
    sits on the right side of this line where candidates.HAND_WRITTEN's
    mnemonic regex puts it on the wrong one -- which is why this is a
    separate test rather than a reuse of that pattern.
    """
    listing = Path("asm/nonmatchings/31D8") / (name + ".s")
    if not listing.is_file():
        return False
    ins = [re.sub(r"^\s*/\*.*?\*/\s*", "", l).strip()
           for l in listing.read_text(errors="replace").splitlines() if "/*" in l]
    frame = any(re.match(r"addiu\s+\$sp,\s*\$sp,\s*-", i) for i in ins)
    ra = any(re.match(r"sw\s+\$ra,", i) for i in ins)
    jal = any(i.startswith("jal ") for i in ins)
    s_off_stack = sum(1 for i in ins if re.match(r"sw\s+\$s\d,", i)
                      and not re.match(r"sw\s+\$s\d,\s*0x[0-9A-Fa-f]+\(\$sp\)", i))
    return (not frame) and (not ra) and (not jal) and s_off_stack > 0

def main():
    buckets = {"clean": [], "gte": [], "debt": []}
    for p in sorted(glob.glob("src/func_*.c")):
        buckets[classify(p)].append(p)

    total = sum(len(v) for v in buckets.values())
    print("src/func_*.c                 : %d" % total)
    print("  real C, no inline asm      : %d" % len(buckets["clean"]))
    # Key on a non-empty template, not on the word `__asm__`: a macro file
    # still carries barrier blocks and they are not raw GTE.
    raw = [p for p in buckets["gte"]
           if any(t.strip() for t in
                  templates(Path(p).read_text(errors="replace")))]
    print("  reaches the GTE            : %d  (%d via gte_* macros, %d raw asm)"
          % (len(buckets["gte"]), len(buckets["gte"]) - len(raw), len(raw)))
    hand = [p for p in buckets["debt"] if hand_written_original(Path(p).stem)]
    owed = [p for p in buckets["debt"] if p not in hand]
    print("  transcribed, but the ORIGINAL was hand-written asm (kept as asm by")
    print("    design; never retirable into C; see hand_written_original): %d" % len(hand))
    print("  ASSEMBLY DEBT (compiler-generated, owed as C) : %d" % len(owed))
    print("\n  honest decompiled count    : %d  (debt of %d excluded; hand-written asm is not owed)" % (total - len(owed), len(owed)))

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
