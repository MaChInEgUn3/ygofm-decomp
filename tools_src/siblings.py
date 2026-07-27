#!/usr/bin/env python3
"""Pair each unmatched candidate with the decompiled function it most resembles.

Four functions in a row matched on the first attempt today because they were
siblings of something already in src/: same shape, different constants or
fields. Adapting the sibling's C is far cheaper than reading a listing cold,
so it is worth knowing which candidate has a sibling before picking one.

Similarity is over the *mnemonic sequence* with operands stripped, which is
what "same shape" means here -- two functions that differ only in offsets,
constants and which globals they touch have identical sequences.

    python tools_src/siblings.py [min_ratio] [max_rows]
"""

import difflib
import glob
import os
import re
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
ASM = os.path.join(ROOT, "asm", "nonmatchings", "31D8")
LIBRARY_REGION = 0x80073840

INSN = re.compile(r"/\*[^*]*\*/\s+(\S+)")


def mnemonics(path):
    return tuple(m.group(1) for m in INSN.finditer(open(path).read()))


def main():
    min_ratio = float(sys.argv[1]) if len(sys.argv) > 1 else 0.90
    max_rows = int(sys.argv[2]) if len(sys.argv) > 2 else 25

    lib = {l.strip() for l in open(os.path.join(ROOT, "docs", "LIBRARY_FUNCS.txt"))
           if l.startswith("func_")}
    done = {os.path.basename(p)[:-2] for p in glob.glob(os.path.join(ROOT, "src", "func_*.c"))}
    # Parked functions are included, flagged, and sorted LAST -- the opposite
    # of what this file said when it was written. The claim was that a park
    # predating its sibling's decompilation is the best lead in the list, and
    # one session measured it: eleven non-parked leads gave eleven matches,
    # most on the first try, while the two [PARKED] ones at the very top of
    # the ratio list (0.933 and 1.000) took more attempts than anything else
    # that day and stayed parked. It makes sense in hindsight. A park in the
    # register-allocation class asserts the *shape* is already right, and a
    # matching sibling proves the same thing, so the sibling carries no new
    # information. Ranking them first inverts the list against its own yield.
    parked = {l.split("#")[0].strip()
              for l in open(os.path.join(ROOT, "docs", "PARKED.txt"))
              if l.startswith("func_")}

    seqs = {}
    for p in glob.glob(os.path.join(ASM, "*.s")):
        name = os.path.basename(p)[:-2]
        if name in lib or int(name[5:], 16) >= LIBRARY_REGION:
            continue
        seqs[name] = mnemonics(p)

    matched = [(n, s) for n, s in seqs.items() if n in done]
    rows = []
    for name, seq in seqs.items():
        if name in done or len(seq) < 8:
            continue
        best, ratio = None, 0.0
        for m, ms in matched:
            # cheap length gate first: difflib over every pair is too slow
            if abs(len(ms) - len(seq)) > max(3, len(seq) // 8):
                continue
            r = difflib.SequenceMatcher(None, seq, ms).ratio()
            if r > ratio:
                best, ratio = m, r
        if best and ratio >= min_ratio:
            rows.append((ratio, len(seq), name, best, name in parked))

    # is_parked last in the key, negated, so unparked leads outrank a parked
    # one at the same ratio.
    rows.sort(key=lambda r: (not r[4], r[0], r[1]), reverse=True)
    print(f"{len(rows)} unmatched candidates with a sibling at ratio >= {min_ratio}")
    for ratio, n, name, sib, is_parked in rows[:max_rows]:
        tag = "  [PARKED]" if is_parked else ""
        print(f"  {ratio:.3f}  {name} ({n})  <- src/{sib}.c{tag}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
