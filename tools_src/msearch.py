#!/usr/bin/env python3
"""
msearch -- enumerate source shapes instead of hand-writing them.

The sketch format is Unchiga's (`tools/msearch.py` in the tree he shared on
2026-08-30) and is kept COMPATIBLE ON PURPOSE, so a sketch written here can be
run there and the other way round. The search engine underneath is ours,
because the pipelines are not the same: his runs a native gcc, ours runs PsyQ
4.5 through Wine, and the whole cost model is different (see PERFORMANCE).

Why this exists. Matching is a search over a handful of discrete knobs --
statement order, index versus cursor addressing, whether a value goes through
a name, which arm of a declaration guard, the flag combo. Every lever in
docs/WORKFLOW.md is one of those. The loop this replaces was: write a
candidate, measure, write another, measure. Two of today's functions took a
20-of-120 hand sweep that was abandoned before it finished (func_8004D58C)
and a 24-order declaration sweep run one at a time (func_8003AD6C). Those are
one command here.

SKETCH FORMAT

    //@ func func_80012B50          the target (or pass it on the command line)
    //@ flags G8 G0 G8:nosplit      flag combos to try; default is all four
    //@ cflags -fno-schedule-insns  extra cc1 flags on every combo

    /*@ALT bittest
    ---
        ok = (o->flags & 0x1000) == 0;
    ---
        t = o->flags & 0x1000;
        ok = (t == 0);
    @*/

    /*@PERM stores
    ---
        *(s16 *)(p + 4) = a;
    ---
        *(s16 *)(p + 6) = b;
    @*/

An ALT block picks one option. A PERM block emits every ordering of its parts.
An empty option is `---` immediately followed by `---`, which is how a
statement or a declaration is made optional -- that spelling is how you ask
"does this line belong here at all", which was the whole answer on
func_8003CEB8 (`s16 crc`) and func_80047480 (one moved store).

    //@ permute a b c               reorder the named ALT blocks among
                                    themselves -- separates WHAT each
                                    statement is from WHAT ORDER they come in

PERFORMANCE, and why the numbers here are not his

Wine is the entire cost: `cpppsx` and `cc1psx` are ~1.9 s each through it,
while `as` and `objdump` are native and round to zero. So a variant is ~4 s
naively, against the ~50 ms his native pipeline gets. Two things claw it back
and neither is optional:

  * **Preprocess once per sketch, not once per variant.** The variant bodies
    are plain C, so the prelude is cpp'd once and each body is spliced into
    the `.i`. That is half the cost, and it is why a sketch may not contain a
    preprocessor directive inside an ALT or PERM block -- msearch refuses one
    rather than silently producing a variant that was never preprocessed.
  * **Four worker processes.** SCRATCH in try_func is per-PID, so processes
    are safe where threads would clobber each other. Bounded at the core
    count on purpose: an unbounded pool of Wine processes is how this project
    once wedged a `wineboot --init` and hung every compile behind it.

Together: about half a second a variant, so a few hundred variants is minutes
rather than an afternoon. Cap the product accordingly -- a coordinate sweep
first and a full product only over the axes that moved is usually the right
shape, and remember that coupled levers are real (func_80026D18,
func_80047480), so a flat single-axis sweep does not prove an axis is dead.

USAGE
    .venv/bin/python tools_src/msearch.py sketch.c
    .venv/bin/python tools_src/msearch.py sketch.c --emit src/func_X.c
    .venv/bin/python tools_src/msearch.py sketch.c --cap 4000 -j 4

Exit status is 0 when a byte-identical variant was found, 1 otherwise.
"""

import argparse
import itertools
import os
import re
import subprocess
import sys
import time
from concurrent.futures import ProcessPoolExecutor
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import build as B  # noqa: E402
import matchlib as M  # noqa: E402
import try_func as T  # noqa: E402

ROOT = B.ROOT

# The four combos his format names, in our flag vocabulary. `split` is
# cc1psx's default and is therefore spelled by OMISSION here, not by passing
# `-msplit-addresses`: passing it explicitly is NOT a no-op in this pipeline
# (func_8002C6C8 measured MATCH with it and built four instructions short
# without it), so it stays available through `//@ cflags` and is never
# silently added.
COMBOS = {
    "G8": ["-quiet", "-O2", "-G8"],
    "G0": ["-quiet", "-O2", "-G0"],
    "G8:nosplit": ["-quiet", "-O2", "-G8", "-mno-split-addresses"],
    "G0:nosplit": ["-quiet", "-O2", "-G0", "-mno-split-addresses"],
}
DEFAULT_COMBOS = ["G8", "G8:nosplit", "G0", "G0:nosplit"]

BLOCK = re.compile(r"/\*@(ALT|PERM)\s+(\S+)\s*\n(.*?)@\*/", re.S)


class Slot:
    def __init__(self, kind, name, options):
        self.kind, self.name, self.options = kind, name, options

    def __len__(self):
        return len(self.options)


def parse(path):
    """Sketch text -> (skeleton with {0}-style holes, slots, directives)."""
    text = Path(path).read_text()
    d = {"func": None, "flags": None, "cflags": [], "permute": []}
    for m in re.finditer(r"^\s*//@\s*(\w+)\s*(.*)$", text, re.M):
        k, v = m.group(1), m.group(2).strip()
        if k == "func":
            d["func"] = v
        elif k == "flags":
            d["flags"] = v.split()
        elif k == "cflags":
            d["cflags"] += v.split()
        elif k == "permute":
            d["permute"] = v.split()
    text = re.sub(r"^\s*//@.*$", "", text, flags=re.M)

    slots, order = [], []
    def take(m):
        kind, name, body = m.group(1), m.group(2), m.group(3)
        opts = [o.strip("\n") for o in re.split(r"^\s*---\s*$", body, flags=re.M)]
        opts = [o for o in opts]
        if opts and not opts[0].strip():
            opts = opts[1:]
        if kind == "PERM":
            opts = ["\n".join(p) for p in itertools.permutations(opts)]
        for o in opts:
            if re.search(r"^\s*#", o, re.M):
                sys.exit("%s: a preprocessor directive inside an @%s block -- "
                         "msearch preprocesses the sketch once and splices "
                         "bodies in, so a directive here would never be "
                         "preprocessed. Move it to the prelude." % (name, kind))
        slots.append(Slot(kind, name, opts))
        order.append(name)
        return "\x00SLOT%d\x00" % (len(slots) - 1)

    skeleton = BLOCK.sub(take, text)
    return skeleton, slots, order, d


def variants(skeleton, slots, order, permute, cap):
    """Every combination, as (label, text). Permuted names reorder their
    own positions, which is what separates WHAT a statement is from WHERE."""
    idx = {n: i for i, n in enumerate(order)}
    perm_positions = [idx[n] for n in permute if n in idx]
    choices = [range(len(s)) for s in slots]
    orders = list(itertools.permutations(perm_positions)) or [()]
    n = 0
    for combo in itertools.product(*choices):
        for perm in orders:
            body = skeleton
            pick = list(combo)
            if perm:
                remap = dict(zip(perm_positions, perm))
                pick = [combo[remap.get(i, i)] for i in range(len(slots))]
            for i, s in enumerate(slots):
                body = body.replace("\x00SLOT%d\x00" % i, s.options[pick[i]])
            label = ",".join("%s=%d" % (slots[i].name, pick[i])
                             for i in range(len(slots)))
            yield label, body
            n += 1
            if n >= cap:
                return


_PRE = {}


def preprocess_once(func, skeleton, slots, cflags):
    """cpp the sketch with every hole emptied, once. Returns the .i text with
    the holes still in it, ready for splicing."""
    holes = skeleton
    for i in range(len(slots)):
        # NOT a comment: cpp strips comments, so a /*@@0@@*/ marker vanishes
        # during the one-time preprocess and every variant comes back an
        # error with nothing to show for it. An identifier survives.
        holes = holes.replace("\x00SLOT%d\x00" % i, "YGOFMHOLE%d" % i)
    src = T.SCRATCH / "sk.c"
    T.SCRATCH.mkdir(parents=True, exist_ok=True)
    src.write_text(holes)
    pre = T.SCRATCH / "sk.i"
    r = subprocess.run([str(c) for c in (
        *B.PSYQ_RUNNER, B.CPPPSX, *B.CPP_FLAGS,
        src.relative_to(ROOT).as_posix(), pre.relative_to(ROOT).as_posix())],
        cwd=ROOT, capture_output=True, text=True)
    if r.returncode:
        sys.exit("cpppsx failed on the sketch:\n%s\n%s" % (r.stdout, r.stderr))
    return pre.read_text()


_CTX = {}


def _init(func, itext, nslots):
    # Give every worker its own scratch. try_func computes SCRATCH from
    # os.getpid() AT IMPORT TIME, and ProcessPoolExecutor forks a parent that
    # has already imported it -- so without this line all four workers write
    # cand.i / cand.s / cand.o into the SAME directory and read back each
    # other's object. It does not fail loudly; it reports another variant's
    # score under this variant's label, which is the worst possible failure
    # for a search tool. Caught by a positive control whose known-bad first
    # option came back MATCH.
    T.SCRATCH = ROOT / "build" / "scratch" / ("ms%d" % os.getpid())
    _CTX["func"], _CTX["i"], _CTX["n"] = func, itext, nslots


def _run(job):
    label, picks, flags = job
    itext = _CTX["i"]
    for i, opt in enumerate(picks):
        itext = itext.replace("YGOFMHOLE%d" % i, opt)
    r = M.score_preprocessed(_CTX["func"], itext, flags)
    return label, flags, r


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("sketch")
    ap.add_argument("--func")
    ap.add_argument("--cap", type=int, default=20000)
    ap.add_argument("-j", type=int, default=min(4, os.cpu_count() or 4))
    ap.add_argument("--emit")
    ap.add_argument("--top", type=int, default=12)
    a = ap.parse_args()

    skeleton, slots, order, d = parse(a.sketch)
    func = a.func or d["func"]
    if not func:
        sys.exit("no target: add `//@ func func_XXXXXXXX` or pass --func")
    combos = d["flags"] or DEFAULT_COMBOS
    for c in combos:
        if c not in COMBOS:
            sys.exit("unknown flag combo %r (have %s)" % (c, " ".join(COMBOS)))

    total = 1
    for s in slots:
        total *= len(s)
    perm_n = 1
    for i in range(2, len(d["permute"]) + 1):
        perm_n *= i
    total *= perm_n * len(combos)
    print("%s: %d slot(s), %d flag combo(s) -> %d variants (cap %d)"
          % (func, len(slots), len(combos), total, a.cap), flush=True)

    itext = preprocess_once(func, skeleton, slots, d["cflags"])

    jobs = []
    for label, _body in variants(skeleton, slots, order, d["permute"], a.cap):
        picks = [s.options[int(p.split("=")[1])]
                 for s, p in zip(slots, label.split(",") if label else [])]
        for c in combos:
            jobs.append((label, picks, COMBOS[c] + d["cflags"]))

    t0 = time.time()
    best, seen, rows, errs = None, {}, 0, []
    with ProcessPoolExecutor(max_workers=a.j, initializer=_init,
                             initargs=(func, itext, len(slots))) as ex:
        for label, flags, r in ex.map(_run, jobs, chunksize=1):
            rows += 1
            if r.status != "OK":
                if len(errs) < 3:
                    errs.append(r.note)
                continue
            seen.setdefault(r.key, []).append((label, flags, r))
            if best is None or r.rank < best[2].rank:
                best = (label, flags, r)
                if r.rank == (0, 0):
                    break
            if rows % 25 == 0:
                print("  %d/%d  best %s" % (rows, len(jobs), best[2]), flush=True)

    dt = time.time() - t0
    print("\n%d variants in %.0fs (%.2fs each), %d distinct instruction streams"
          % (rows, dt, dt / max(rows, 1), len(seen)), flush=True)
    # Distinct-stream count IS the wrong-axis diagnostic: if hundreds of
    # spellings collapse to a handful of streams, the knobs you varied are not
    # the knobs the compiler is reading.
    if rows >= 8 and len(seen) * 4 < rows:
        print("  NOTE: %d variants collapsed to %d streams -- most of what you "
              "varied changes nothing. Wrong axis." % (rows, len(seen)))

    # A sweep that returns nothing must be able to say WHY. This project has
    # lost hours to a filter that silently matched nothing and read as a clean
    # negative; printing the first error costs one line.
    if not seen:
        print("  no variant compiled. First errors:")
        for e in errs:
            print("    " + e[:160])
    ranked = sorted((v[0] for v in seen.values()), key=lambda x: x[2].rank)
    for label, flags, r in ranked[: a.top]:
        print("  %-9s %-28s %s" % (r, " ".join(flags[2:]), label))

    if best and best[2].rank == (0, 0):
        print("\nMATCH: %s   flags %s" % (best[0], " ".join(best[1][2:])))
        if a.emit:
            body = itext  # emit the SOURCE, not the preprocessed text
            _, text = next(
                (lb, tx) for lb, tx in
                variants(skeleton, slots, order, d["permute"], a.cap)
                if lb == best[0])
            Path(a.emit).write_text(text)
            print("wrote %s" % a.emit)
        return 0
    return 1


if __name__ == "__main__":
    raise SystemExit(main())
