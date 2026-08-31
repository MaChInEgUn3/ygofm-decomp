#!/usr/bin/env python3
"""
Sweep the declared width of every local, one at a time and then in pairs.

A narrow declaration is one of the few levers in docs/WORKFLOW.md that is
fully mechanical: there is nothing to invent, only `s32 / s16 / s8 / u32 /
u16 / u8` to try. It is also one of the highest-yield -- `s16 crc` was the
whole of func_8003CEB8, `u16 a` opened func_80045C98, `u32 f` was 87
differences on func_80043BCC, and `s8 v` versus `s32 v = (s8)...` was
func_80027060 with no instruction changing at all. Every one of those was
found by hand, one edit at a time.

The tool exists because the hand version does not scale and stops early. This
sweeps every local's width, reports each on its own, and then takes the
product over just the ones that moved -- which is the shape the coupled-lever
rule asks for (func_80026D18 and func_80047480 both needed two edits that are
worth nothing alone, so a flat single-axis result is not proof an axis is
dead; it is proof that axis is dead *alone*).

Reads the declarations out of the function's own top-of-body block, so it
only ever touches lines it can see. Anything it proposes still has to survive
the full build.

    .venv/bin/python tools_src/sweep_decls.py func_80058624 parked/func_80058624.c
    .venv/bin/python tools_src/sweep_decls.py func_X src.c --pairs --top 20
"""

import argparse
import itertools
import os
import re
import sys
from concurrent.futures import ProcessPoolExecutor
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import build as B  # noqa: E402
import matchlib as M  # noqa: E402
import try_func as T  # noqa: E402

ROOT = B.ROOT
WIDTHS = ["s32", "u32", "s16", "u16", "s8", "u8"]
DECL = re.compile(r"^(\s*)(s32|u32|s16|u16|s8|u8)(\s+)([A-Za-z_][A-Za-z_0-9]*)\s*;\s*$")

_CTX = {}


def _init(func, text, flags):
    T.SCRATCH = ROOT / "build" / "scratch" / ("dw%d" % os.getpid())
    _CTX["func"], _CTX["text"], _CTX["flags"] = func, text, flags


def _apply(text, changes):
    """changes: {line_index: new_width}"""
    lines = text.splitlines()
    for i, w in changes.items():
        m = DECL.match(lines[i])
        lines[i] = "%s%s%s%s;" % (m.group(1), w, m.group(3), m.group(4))
    return "\n".join(lines) + "\n"


def _run(changes):
    r = M.score(_CTX["func"], _apply(_CTX["text"], changes), _CTX["flags"])
    return changes, r


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("func")
    ap.add_argument("src")
    ap.add_argument("--pairs", action="store_true",
                    help="after the single sweep, take the product over the "
                         "declarations that moved -- coupled levers are real")
    ap.add_argument("--top", type=int, default=12)
    ap.add_argument("-j", type=int, default=min(4, os.cpu_count() or 4))
    ap.add_argument("flags", nargs="*")
    a = ap.parse_args()

    text = Path(a.src).read_text()
    flags = a.flags or list(B.PER_FUNC_FLAGS.get(a.func, B.CC1_FLAGS))
    decls = [(i, m.group(2), m.group(4))
             for i, l in enumerate(text.splitlines())
             if (m := DECL.match(l))]
    if not decls:
        sys.exit("no simple scalar declarations found in %s" % a.src)
    print("%s: %d declaration(s), flags %s"
          % (a.func, len(decls), " ".join(flags[2:])), flush=True)

    base = M.score(a.func, text, flags)
    print("base: %s\n" % base, flush=True)

    jobs = [{i: w} for i, cur, _ in decls for w in WIDTHS if w != cur]
    results, moved = [], {}
    with ProcessPoolExecutor(max_workers=a.j, initializer=_init,
                             initargs=(a.func, text, flags)) as ex:
        for changes, r in ex.map(_run, jobs, chunksize=1):
            results.append((changes, r))
            if r.status == "OK" and r.rank < base.rank:
                i = next(iter(changes))
                moved.setdefault(i, []).append((changes[i], r))
                name = dict((d[0], d[2]) for d in decls)[i]
                print("  %-4s %-16s %s" % (changes[i], name, r), flush=True)

    if a.pairs and len(moved) >= 2:
        # The product over ONLY the axes that moved. Doing the full product
        # over every declaration is combinatorially silly and doing none of it
        # misses the coupled cases this project keeps finding.
        axes = [[(i, w) for w, _ in v] for i, v in moved.items()]
        pairs = [dict(c) for c in itertools.product(*axes)]
        print("\n%d combination(s) over the %d declaration(s) that moved"
              % (len(pairs), len(moved)), flush=True)
        with ProcessPoolExecutor(max_workers=a.j, initializer=_init,
                                 initargs=(a.func, text, flags)) as ex:
            for changes, r in ex.map(_run, pairs, chunksize=1):
                results.append((changes, r))

    ok = [(c, r) for c, r in results if r.status == "OK"]
    ok.sort(key=lambda x: x[1].rank)
    names = dict((d[0], d[2]) for d in decls)
    print("\ntop:")
    for c, r in ok[: a.top]:
        spec = " ".join("%s=%s" % (names[i], w) for i, w in sorted(c.items()))
        print("  %-22s %s" % (str(r), spec))
    streams = {r.key for _, r in ok}
    if len(ok) >= 8 and len(streams) * 4 < len(ok):
        print("\n  NOTE: %d variants collapsed to %d instruction streams -- "
              "most of these declarations are not read by the compiler here."
              % (len(ok), len(streams)))
    return 0 if ok and ok[0][1].rank == (0, 0) else 1


if __name__ == "__main__":
    raise SystemExit(main())
