#!/usr/bin/env python3
"""
Three-way coverage across the decomps of this binary, and our status exported
in the interchange format.

Unchiga asked on 2026-08-31 whether the three projects want a mechanism to
stop duplicating work. The measured answer is that they need one: 617
functions have been decompiled by all three of us independently, 400 by
exactly two, and only 148 are left that nobody has. The mechanism arrives
about 1000 functions late, which is the argument for having it now rather than
an argument against it.

FORMAT. krystalgamer/memories-decomp already publishes the right thing --
`config/slus_01411/functions.csv`, columns address,size,name,status,module,
notes, with an explicit status of matching_c / unmatched_asm / sdk_asm /
handwritten_asm. That last category is his name for what candidates.py calls
HAND_WRITTEN, so the vocabularies already agree. This writes ours in the same
shape rather than inventing a format: `--export config/coverage.csv`.

INPUTS, all optional -- it reports on whatever it can see:
  third_party/unchiga        a checkout of his tree (any branch)
  third_party/krystal-notes/functions.csv
"""

import csv
import os
import re
import sys
from pathlib import Path

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
ROOT = Path(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
SCOPE = 0x80073840


def ours():
    done = {int(p.stem[5:], 16) for p in (ROOT / "src").glob("func_*.c")}
    parked = {int(p.stem[5:], 16) for p in (ROOT / "parked").glob("func_*.c")}
    return done, parked


def listing():
    return {int(p.stem[5:], 16)
            for p in (ROOT / "asm/nonmatchings/31D8").glob("func_*.s")}


def unchiga(tree):
    """Decompiled means the unit file exists and is not an INCLUDE_ASM stub."""
    if not tree.exists():
        return None
    sys.path.insert(0, str(ROOT / "tools_src"))
    import transplant as T
    out = set()
    for a, u in T.their_units(tree).items():
        p = tree / "src" / f"{u}.c"
        if p.exists() and "INCLUDE_ASM" not in p.read_text(errors="replace"):
            out.add(a)
    return out


def krystal(path):
    if not path.exists():
        return None, None
    done, sdk = set(), set()
    for r in csv.DictReader(open(path)):
        a = int(r["address"], 16)
        if r["status"] == "matching_c":
            done.add(a)
        elif r["status"] == "sdk_asm":
            sdk.add(a)
    return done, sdk


def main():
    allf = {a for a in listing() if a < SCOPE}
    o, parked = ours()
    o = {a for a in o if a < SCOPE}
    u = unchiga(ROOT / "third_party/unchiga")
    k, _ = krystal(ROOT / "third_party/krystal-notes/functions.csv")

    trees = [("ours", o)]
    if u is not None:
        trees.append(("unchiga", u))
    if k is not None:
        trees.append(("krystal", k))

    print("in scope (below 0x%X): %d\n" % (SCOPE, len(allf)))
    for n, s in trees:
        print("  %-9s %4d" % (n, len(s & allf)))

    union = set().union(*(s for _, s in trees))
    print("\n  union     %4d  (%.1f%%)" % (len(union & allf),
                                           100 * len(union & allf) / len(allf)))
    print("  NOBODY    %4d" % len(allf - union))

    if len(trees) > 1:
        counts = {a: sum(a in s for _, s in trees) for a in allf}
        for n in range(len(trees), 1, -1):
            print("  done by %d: %4d%s" % (n, sum(v == n for v in counts.values()),
                                           "   <- duplicated work" if n > 1 else ""))
        for i, (na, sa) in enumerate(trees):
            for nb, sb in trees[i + 1:]:
                print("    only %-8s vs %-8s: %d / %d"
                      % (na, nb, len((sa - sb) & allf), len((sb - sa) & allf)))

    todo = sorted(allf - union)
    if todo:
        Path("/tmp/nobody.txt").write_text(
            "\n".join("func_%08X" % a for a in todo) + "\n")
        print("\n  the %d nobody has -> /tmp/nobody.txt" % len(todo))

    if "--export" in sys.argv:
        dst = Path(sys.argv[sys.argv.index("--export") + 1])
        with open(dst, "w", newline="") as f:
            w = csv.writer(f)
            w.writerow(["address", "size", "name", "status", "module", "notes"])
            for a in sorted(listing()):
                p = ROOT / f"asm/nonmatchings/31D8/func_{a:08X}.s"
                n = sum(1 for l in open(p, errors="replace")
                        if re.match(r"^\s+/\* [0-9A-F]+ [0-9A-F]{8} ", l))
                if a >= SCOPE:
                    st = "sdk_asm"
                elif a in o:
                    st = "matching_c"
                else:
                    st = "unmatched_asm"
                note = "parked, see docs/PARKED.txt" if a in parked else ""
                w.writerow(["0x%08X" % a, "0x%X" % (n * 4), "func_%08X" % a,
                            st, "", note])
        print("  exported -> %s" % dst)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
