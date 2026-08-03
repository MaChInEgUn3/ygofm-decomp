#!/usr/bin/env python3
"""
Flag sweep for one candidate, through try_func instead of the full build.

    python tools_src/sweep_try.py func_800732A0 [candidate.c]

sweep_flags.py runs a whole build per combination -- about ninety seconds each,
so twenty-one combinations is half an hour and sweeping the parked set is a
day. This runs the same combination table through try_func, which is seconds
each, and reports the best.

It exists because of a specific failure: `-mno-split-addresses` has been in the
sweeper's table for weeks, and two functions were parked for hours -- after
scheduler flags, several source shapes and permuter runs -- that match under
it. I had stopped running the sweep at all, because reading the target for
which flag it wants had started working often enough that step 5 of the
workflow felt optional. It is not optional; it is just slow, so here it is
fast.

The full build stays the authority. This narrows the search; sweep_flags.py or
a plain build confirms it.
"""

import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tools_src"))
import sweep_flags as S  # noqa: E402

PY = ROOT / ".venv" / "bin" / "python"
OVERRIDES = ROOT / "config" / "flag_overrides.json"


def main():
    if len(sys.argv) < 2:
        sys.exit(__doc__)
    func = sys.argv[1]
    cand = sys.argv[2] if len(sys.argv) > 2 else f"parked/{func}.c"
    if not (ROOT / cand).exists():
        cand = f"src/{func}.c"
    results = []
    for label, cc, asf in S.COMBOS:
        # try_func takes cc flags on the command line; the assembler flags come
        # from build.py's tables, so route them through the override file the
        # way the real sweeper does.
        # "as" is always set, to null when the row wants the default. Deleting
        # the override file instead left whatever PER_FUNC_AS_FLAGS already
        # held for this function in place, so every row labelled with no
        # assembler flag was silently tested against that entry -- and a
        # parked function keeps its entry in build.py precisely so its
        # difference count stays reproducible. sweep_flags.py fixed exactly
        # this bug in its own loop and left the comment; this tool had the
        # same one, unnoticed, because the two -G values were always equal in
        # the table and the difference never showed.
        OVERRIDES.write_text(
            '{"%s": {"cc": %s, "as": %s}}' %
            (func, str(cc).replace("\'", '"'),
             '"%s"' % asf if asf else "null"))
        r = subprocess.run([str(PY), "tools_src/try_func.py", func, cand,
                            *cc], cwd=ROOT, capture_output=True, text=True)
        line = r.stdout.strip().splitlines()[-1] if r.stdout.strip() else "failed"
        n = 0 if line == "MATCH" else (
            int(line.split()[0]) if line.split()[0].isdigit() else 9999)
        results.append((n, label, line))
        print(f"  {line:<32} {label}")
    OVERRIDES.unlink(missing_ok=True)
    results.sort()
    print(f"\nbest: {results[0][2]}  ({results[0][1]})")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
