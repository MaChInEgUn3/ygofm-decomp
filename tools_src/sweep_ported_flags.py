#!/usr/bin/env python3
"""
Re-measure every near-miss from the ported tree under all four flag combos.

`transplant.py` measured each of Unchiga's units once, under the flags HIS
`config/unit_flags.txt` records for it. That is the right first measurement --
it asks whether his C, as he wrote it, reproduces the bytes here. But his flag
choice was made against his pipeline, and the two do not agree everywhere: the
same C can want a different `-G` or a different split-address setting under
ours. 145 of his units came back OK-but-not-MATCH, most of them at one or two
differences, and a flag sweep over those costs nothing to author.

This is deliberately the *mechanical* half of the merge. No sketch, no
reading, no judgement -- just the four combos msearch would try anyway, over
a list that already exists. Anything it turns green still has to survive
`install_ported.py`, which builds the whole image.

    .venv/bin/python tools_src/sweep_ported_flags.py [--max-diffs 6]
"""

import argparse
import os
import sys
from concurrent.futures import ProcessPoolExecutor
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import build as B  # noqa: E402
import matchlib as M  # noqa: E402
import try_func as T  # noqa: E402

ROOT = B.ROOT
PORTED = ROOT / "build" / "transplant"
MANIFEST = ROOT / "docs" / "merge" / "transplant_manifest.tsv"

COMBOS = [
    ["-quiet", "-O2", "-G8"],
    ["-quiet", "-O2", "-G0"],
    ["-quiet", "-O2", "-G8", "-mno-split-addresses"],
    ["-quiet", "-O2", "-G0", "-mno-split-addresses"],
    ["-quiet", "-O2", "-G8", "-msplit-addresses"],
    ["-quiet", "-O2", "-G0", "-msplit-addresses"],
]


def _init():
    # Same fork hazard as msearch: SCRATCH is computed at import time in the
    # parent, so without this every worker shares one scratch directory and
    # reads back another worker's object.
    T.SCRATCH = ROOT / "build" / "scratch" / ("fs%d" % os.getpid())


def _run(job):
    func, base = job
    src = PORTED / (func + ".c")
    if not src.exists():
        return func, base, None
    text = src.read_text()
    best = None
    for flags in COMBOS:
        r = M.score(func, text, flags)
        if r.status != "OK":
            continue
        if best is None or r.rank < best.rank:
            best = r
    return func, base, best


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--max-diffs", type=int, default=8,
                    help="only sweep units already within this many diffs")
    ap.add_argument("-j", type=int, default=min(4, os.cpu_count() or 4))
    a = ap.parse_args()

    jobs = []
    for line in MANIFEST.read_text().splitlines()[1:]:
        f = line.split("\t")
        if len(f) < 5 or f[2] != "OK":
            continue
        try:
            lenerr, diffs = int(f[3]), int(f[4])
        except ValueError:
            continue
        if abs(lenerr) == 0 and diffs <= a.max_diffs:
            jobs.append((f[0], diffs))
    print("%d near-miss unit(s) within %d diffs" % (len(jobs), a.max_diffs),
          flush=True)

    wins = []
    with ProcessPoolExecutor(max_workers=a.j, initializer=_init) as ex:
        for func, base, best in ex.map(_run, jobs, chunksize=1):
            if best is None:
                continue
            if best.rank < (0, base):
                wins.append((func, base, best))
                print("  %-16s %d -> %s   %s"
                      % (func, base, best, " ".join(best.flags[2:])), flush=True)
    print("\n%d improved of %d" % (len(wins), len(jobs)), flush=True)
    matches = [w for w in wins if w[2].rank == (0, 0)]
    if matches:
        print("MATCH candidates (still must survive the full build):")
        print("  " + " ".join(m[0] for m in matches))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
