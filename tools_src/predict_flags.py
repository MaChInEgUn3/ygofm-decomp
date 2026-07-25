#!/usr/bin/env python3
"""
Guess whether an undecompiled function wants -G0, from its target asm.

    python tools_src/predict_flags.py func_80012B50    # one function
    python tools_src/predict_flags.py --validate       # score against the corpus

Two independent signals, both measured against the 179 already-matching
functions. Neither is exact -- see the "predicting -G0" section of
docs/DECISIONS.md for why exactness is not achievable.

  run     A function using %gp_rel was certainly compiled -G8. Maximal runs
          of consecutive functions with no %gp_rel that do touch globals are
          candidate -G0 translation units. Recall 19/19 on the main body,
          precision ~51% -- so it is a *negative* filter: outside a run,
          -G0 is not worth sweeping.

  small   A symbol reached via %gp_rel somewhere must fit the -G8 threshold,
          so a %hi/%lo access to that same symbol suggests -G0. Precision
          ~97%, recall ~27%. The misses are ours, not the game's: declaring
          the symbol as an unsized array in include/variables.h also forces
          %hi/%lo, and that is a knob we use instead of -G0.
"""

import bisect
import glob
import importlib.util
import os
import re
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
ASM = os.path.join(ROOT, "asm", "nonmatchings", "31D8")
MAIN_BODY_END = 0x80073840          # above this, use docs/FILE_BOUNDARIES.txt

GP = re.compile(r"%gp_rel\(([A-Za-z_]\w*)\)")
HI = re.compile(r"%hi\(([A-Za-z_]\w*)\)")


def load():
    lib = {l.strip() for l in open(os.path.join(ROOT, "docs", "LIBRARY_FUNCS.txt"))
           if l.startswith("func_")}
    out = {}
    for f in glob.glob(os.path.join(ASM, "*.s")):
        n = os.path.basename(f)[:-2]
        if n in lib:
            continue
        t = open(f).read()
        out[n] = (set(GP.findall(t)), set(HI.findall(t)))
    return out


def signals(info):
    small = set().union(*(g for g, _ in info.values())) if info else set()

    body = sorted((int(n[5:], 16), n) for n in info if int(n[5:], 16) < MAIN_BODY_END)
    runs, cur = [], []
    for a, n in body:
        if info[n][0]:
            if cur:
                runs.append(cur)
            cur = []
        else:
            cur.append((a, n))
    if cur:
        runs.append(cur)
    runs = [r for r in runs if any(info[n][1] for _, n in r)]
    starts = [r[0][0] for r in runs]
    ends = [r[-1][0] for r in runs]

    def in_run(name):
        a = int(name[5:], 16)
        i = bisect.bisect_right(starts, a) - 1
        return i >= 0 and a <= ends[i]

    return small, in_run


def current_flags():
    spec = importlib.util.spec_from_file_location(
        "b", os.path.join(ROOT, "tools_src", "build.py"))
    b = importlib.util.module_from_spec(spec)
    try:
        spec.loader.exec_module(b)
    except SystemExit:
        pass
    done = sorted(os.path.basename(p)[:-2]
                  for p in glob.glob(os.path.join(ROOT, "src", "func_*.c")))
    return {n: " ".join(b.PER_FUNC_FLAGS.get(n, b.CC1_FLAGS)) for n in done}


def main():
    info = load()
    small, in_run = signals(info)

    if "--validate" in sys.argv:
        flags = current_flags()
        g0 = [n for n, f in flags.items() if "-G0" in f]
        g8 = [n for n, f in flags.items() if "-G0" not in f]
        for label, pred in (("run  ", lambda n: in_run(n)),
                            ("small", lambda n: bool(info[n][1] & small)
                                                and not info[n][0])):
            hit = sum(1 for n in g0 if n in info and pred(n))
            fp = sum(1 for n in g8 if n in info and pred(n))
            print(f"  {label}  recall {hit}/{len(g0)}   false positives {fp}/{len(g8)}")
        return 0

    if len(sys.argv) < 2:
        sys.exit(__doc__)
    for n in sys.argv[1:]:
        if n not in info:
            print(f"{n}: not a non-library function in {ASM}")
            continue
        gp, hi = info[n]
        run = in_run(n)
        prov = bool(hi & small) and not gp
        if gp:
            verdict = "-G8 (uses %gp_rel)"
        elif prov:
            verdict = "-G0 likely (reaches a proven-small symbol via %hi)"
        elif run:
            verdict = "-G0 worth trying (inside a gp_rel-free run)"
        else:
            verdict = "-G8 (outside any -G0 run; do not sweep -G0)"
        print(f"{n}: {verdict}")
        if hi:
            print(f"    %hi symbols: {' '.join(sorted(hi))}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
