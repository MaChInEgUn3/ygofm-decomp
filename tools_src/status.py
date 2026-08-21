#!/usr/bin/env python3
"""
Recompute the Status tables in README.md from the tree itself.

    python tools_src/status.py            # print the numbers
    python tools_src/status.py --write    # rewrite README.md's two tables

Both tables in the README have been wrong before, and always the same way: a
hand-typed number carried forward past the batch that changed it. The scope
filters are *imported* from candidates.py rather than restated -- the `lui $at`
pool was miscounted 167 -> 136 -> 66 exactly because an ad-hoc scan skipped a
filter candidates.py already applied.
"""
import glob
import os
import re
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import candidates as C  # noqa: E402

ROOT = C.ROOT
BANDS = [(0, 25), (26, 50), (51, 100), (101, 200), (201, 400), (401, 10 ** 9)]
BAND_LABELS = ["≤ 25", "26–50", "51–100", "101–200", "201–400", "> 400"]


def collect():
    lib = {l.strip() for l in open(os.path.join(ROOT, "docs", "LIBRARY_FUNCS.txt"))
           if l.startswith("func_")}
    done = {os.path.basename(p)[:-2]
            for p in glob.glob(os.path.join(ROOT, "src", "func_*.c"))}
    parked = C.parked()

    scope = {}
    for path in glob.glob(os.path.join(C.ASM, "*.s")):
        name = os.path.basename(path)[:-2]
        if name in lib or int(name[5:], 16) >= C.LIBRARY_REGION:
            continue
        _, body = C.read(name)
        if C.HAND_WRITTEN.search(" ".join(body)):
            continue
        scope[name] = len(body)
    return scope, done, parked


def main():
    scope, done, parked = collect()
    matched = {n: k for n, k in scope.items() if n in done}
    left = {n: k for n, k in scope.items() if n not in done}
    tot_f, tot_i = len(scope), sum(scope.values())
    m_f, m_i = len(matched), sum(matched.values())
    r_f, r_i = len(left), sum(left.values())

    print(f"scope: {tot_f} functions, {tot_i} instructions")
    print(f"  matching : {m_f} ({100.0*m_f/tot_f:.1f}%)  "
          f"{m_i} ({100.0*m_i/tot_i:.1f}%)")
    print(f"  remaining: {r_f} ({100.0*r_f/tot_f:.1f}%)  "
          f"{r_i} ({100.0*r_i/tot_i:.1f}%)")
    print(f"  averages : matched {m_i//m_f}, remaining {r_i//r_f}")
    print(f"src/ holds {len(glob.glob(os.path.join(ROOT, 'src', 'func_*.c')))} files")

    rows = []
    for (lo, hi), label in zip(BANDS, BAND_LABELS):
        band = [n for n, k in left.items() if lo <= k <= hi]
        p = sum(1 for n in band if n in parked)
        rows.append((label, len(band), p, len(band) - p))
        print(f"  {label:<9} remaining {len(band):>4}  parked {p:>4}  "
              f"unclaimed {len(band) - p:>4}")
    unclaimed = sorted(k for n, k in left.items() if n not in parked)
    if unclaimed:
        print(f"lowest unclaimed: {unclaimed[0]} instructions")

    if "--write" not in sys.argv:
        return 0

    path = os.path.join(ROOT, "README.md")
    text = open(path, encoding="utf-8").read()
    t1 = ("| | functions | instructions |\n|---|---|---|\n"
          f"| decompiled and matching | **{m_f}** ({100.0*m_f/tot_f:.1f}%) | "
          f"**{m_i:,}** ({100.0*m_i/tot_i:.1f}%) |\n"
          f"| remaining | {r_f} ({100.0*r_f/tot_f:.1f}%) | "
          f"{r_i:,} ({100.0*r_i/tot_i:.1f}%) |\n")
    text = re.sub(r"\| \| functions \| instructions \|\n\|---\|---\|---\|\n"
                  r"\| decompiled and matching \|[^\n]*\n\| remaining \|[^\n]*\n",
                  t1, text, count=1)
    t2 = "| size (instructions) | remaining | parked | unclaimed |\n|---|---|---|---|\n"
    for label, rem, p, un in rows:
        if rem == 0:
            continue
        t2 += (f"| {label} | {rem} | {p} | "
               f"{'**0**' if un == 0 else un} |\n")
    text = re.sub(r"\| size \(instructions\) \| remaining \| parked \| unclaimed \|\n"
                  r"\|---\|---\|---\|---\|\n(?:\|[^\n]*\n)+", t2, text, count=1)
    text = re.sub(r"average 29 instructions and the ones\nremaining average \d+",
                  f"average {m_i//m_f} instructions and the ones\n"
                  f"remaining average {r_i//r_f}", text, count=1)
    text = re.sub(r"`src/` holds \d+ files; \d+ of them are in scope",
                  f"`src/` holds {len(glob.glob(os.path.join(ROOT, 'src', 'func_*.c')))}"
                  f" files; {m_f} of them are in scope", text, count=1)
    if unclaimed:
        text = re.sub(r"the lowest unclaimed function is \*\*\d+\*\*",
                      f"the lowest unclaimed function is **{unclaimed[0]}**",
                      text, count=1)
    open(path, "w", encoding="utf-8", newline="\n").write(text)
    print("README.md rewritten")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
