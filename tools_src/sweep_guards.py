#!/usr/bin/env python3
"""Sweep every per-file guard in variables.h against every close parked candidate.

    tools_src/sweep_guards.py [max_differences]

Why this exists
---------------
`include/variables.h` carries ~100 per-file guards -- `_IS_VOLATILE`,
`_IS_AGGREGATE`, `_IS_SCALAR`, `_SIZED` -- each one added because some *other*
function needed that symbol spelled differently, and each with a comment saying
which symptom it fixed. A park that describes the same symptom is a free match
waiting to be tried, and nobody was trying them: a guard is invisible unless
you already suspect the symbol.

First run: **one match** (func_8003353C, 2 -> 0 on `D_8009B3A4_IS_VOLATILE`)
and three park improvements. The comment beside that guard said "retail reloads
each time, which only a volatile does" and the park's own residue said "retail
leaves a nop in the preceding volatile load's delay slot" -- the two sentences
describe the same thing and sat unconnected for weeks.

What it does
------------
For each `parked/*.c` scoring at or below `max_differences` (default 50), find
every guard belonging to a symbol the file *references* but does not already
`#define`, prepend it, and re-score through try_func. Prints only strict
improvements on `(abs(length_error), differences)`, worst axis first -- because
a difference count taken at a different length is not comparable, which is the
hazard try_func's own header shouts about.

A hit is a lead, not an answer. A guard changes what the symbol *is*, so read
its comment and check the claim against the listing before installing one; and
a guard is per-file, so it cannot break another translation unit -- but the
full build is still the only arbiter.
"""
import os
import re
import subprocess
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
PY = os.path.join(ROOT, ".venv", "bin", "python")
TRY = os.path.join(ROOT, "tools_src", "try_func.py")
PROBE = os.path.join(ROOT, "build", "guard_probe.c")


def guards_by_symbol():
    text = open(os.path.join(ROOT, "include", "variables.h")).read()
    out = {}
    for g in set(re.findall(r"D_[0-9A-F]{8}_[A-Z_]+", text)):
        out.setdefault(g[:10], set()).add(g)
    return out


def score(func, path):
    """(differences, built - target), or (None, None) if it did not compile.

    try_func prints nothing matching either pattern on a compile error, which
    is the filter hazard WORKFLOW warns about -- so a parse failure has to read
    as "no answer", never as "no improvement"."""
    try:
        out = subprocess.run([PY, TRY, func, path], capture_output=True,
                             text=True, timeout=180).stdout
    except subprocess.TimeoutExpired:
        return None, None
    lens = re.search(r"(\d+) target instruction\(s\), (\d+) built", out)
    diff = re.search(r"(\d+) differing instruction", out)
    if lens and "MATCH" in out and not diff:
        return 0, 0
    if not lens or not diff:
        return None, None
    return int(diff.group(1)), int(lens.group(2)) - int(lens.group(1))


def main():
    limit = int(sys.argv[1]) if len(sys.argv) > 1 else 50
    bysym = guards_by_symbol()
    os.makedirs(os.path.dirname(PROBE), exist_ok=True)
    parked = os.path.join(ROOT, "parked")
    names = sorted(f[:-2] for f in os.listdir(parked) if f.endswith(".c"))
    print("%d parked candidates, %d guarded symbols" % (len(names), len(bysym)))

    for func in names:
        path = os.path.join(parked, func + ".c")
        src = open(path).read()
        base_d, base_l = score(func, path)
        if base_d is None or base_d > limit:
            continue
        cand = [g for sym in set(re.findall(r"D_[0-9A-F]{8}", src))
                for g in bysym.get(sym, ()) if "#define %s" % g not in src]
        hits = []
        for g in cand:
            with open(PROBE, "w") as f:
                f.write("#define %s\n%s" % (g, src))
            d, l = score(func, PROBE)
            if d is not None and (abs(l), d) < (abs(base_l), base_d):
                hits.append((abs(l), d, l, g))
        if hits:
            hits.sort()
            print("%-16s base %d (len %+d)  ->  %s" % (
                func, base_d, base_l,
                "  ".join("%s: %d (%+d)" % (g, d, l) for _, d, l, g in hits[:3])))
            sys.stdout.flush()
    print("sweep done")


if __name__ == "__main__":
    main()
