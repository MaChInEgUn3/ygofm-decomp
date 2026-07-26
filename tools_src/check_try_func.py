#!/usr/bin/env python3
"""
Regression test for tools_src/try_func.py.

    python tools_src/check_try_func.py [stride]

Every function in src/ is byte-identical to retail -- that is what a green
build means -- so try_func must report MATCH for every one of them. Anything
else is a bug in try_func's normalisation, not in the C.

This exists because that file produced seven separate wrong answers in one
day, each of them confident rather than an error: a stale toolchain path, a
rewrite rule placed before the rule that creates its input, two different
signedness mix-ups in one regex, a constant form left unexpanded, symbol
aliases compared as text, and an indirect call spelled two ways. The last of
those was introduced *while fixing* another one and would have gone unnoticed
without a check like this -- reordering two branches of the `li` rewrite
silently broke every 0xFFFF0000 mask.

It checks both directions, and the second one is the one that matters more.
src/ is the positive set: every file there is byte-identical to retail, so
try_func must say MATCH. parked/ is the negative set: every file there is a
recorded near miss, so try_func must *not* say MATCH. Only the positive
direction was checked at first, which left the dangerous failure uncovered --
a tool that says MATCH when the build would disagree costs a full build cycle
to catch, or gets a parked function wrongly declared solved.

Pass a stride to sample the positive set (default 7, so roughly one function
in seven); stride 1 checks everything and takes a while. The negative set is
small and always checked in full.
"""

import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
PY = ROOT / ".venv" / "bin" / "python"


def verdict_for(name, path):
    r = subprocess.run([str(PY), "tools_src/try_func.py", name,
                        Path(path).relative_to(ROOT).as_posix()],
                       cwd=ROOT, capture_output=True, text=True)
    return r.stdout.strip().splitlines()[-1] if r.stdout.strip() else "no output"


def main():
    stride = int(sys.argv[1]) if len(sys.argv) > 1 else 7
    srcs = sorted((ROOT / "src").glob("func_*.c"))[::stride]
    bad = []
    for i, f in enumerate(srcs, 1):
        verdict = verdict_for(f.stem, f)
        if verdict != "MATCH":
            bad.append((f.stem, verdict))
        print(f"\r[src] {i}/{len(srcs)}  {len(bad)} bad ", end="", flush=True)
    print()
    for name, verdict in bad:
        print(f"  {name}: expected MATCH, got {verdict}")

    parked = sorted((ROOT / "parked").glob("func_*.c"))
    false_pos = []
    for i, f in enumerate(parked, 1):
        verdict = verdict_for(f.stem, f)
        if verdict == "MATCH":
            false_pos.append(f.stem)
        print(f"\r[parked] {i}/{len(parked)}  {len(false_pos)} bad ",
              end="", flush=True)
    print()
    for name in false_pos:
        print(f"  {name}: reported MATCH for a parked near miss")

    print(f"\n{len(srcs) - len(bad)}/{len(srcs)} of src report MATCH; "
          f"{len(parked) - len(false_pos)}/{len(parked)} of parked report a "
          f"difference")
    return 1 if (bad or false_pos) else 0


if __name__ == "__main__":
    raise SystemExit(main())
