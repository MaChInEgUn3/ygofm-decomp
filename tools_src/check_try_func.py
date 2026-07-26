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

Pass a stride to sample (default 7, so roughly one function in seven);
stride 1 checks everything and takes a while.
"""

import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
PY = ROOT / ".venv" / "bin" / "python"


def main():
    stride = int(sys.argv[1]) if len(sys.argv) > 1 else 7
    srcs = sorted((ROOT / "src").glob("func_*.c"))[::stride]
    bad = []
    for i, f in enumerate(srcs, 1):
        name = f.stem
        r = subprocess.run([str(PY), "tools_src/try_func.py", name,
                            f.relative_to(ROOT).as_posix()],
                           cwd=ROOT, capture_output=True, text=True)
        verdict = r.stdout.strip().splitlines()[-1] if r.stdout.strip() else "no output"
        if verdict != "MATCH":
            bad.append((name, verdict))
        print(f"\r{i}/{len(srcs)}  {len(bad)} bad ", end="", flush=True)
    print()
    for name, verdict in bad:
        print(f"  {name}: {verdict}")
    print(f"\n{len(srcs) - len(bad)}/{len(srcs)} report MATCH")
    return 1 if bad else 0


if __name__ == "__main__":
    raise SystemExit(main())
