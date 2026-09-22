#!/usr/bin/env python3
"""Regenerate the US-to-target address pair list that jp_promote.py starts from.

    .venv/bin/python tools_src/jp_pairs.py            # measure, write nothing
    .venv/bin/python tools_src/jp_pairs.py --write    # merge the recoveries into config/jp_matches.csv

WHY THIS EXISTS. `config/jp_matches.csv` was written by hand in one commit
(4a0f518) and never regenerated, while krystalgamer's US config moves under it
every day. Measured 2026-09-21 against his master: 306 entries, of which **127
name a US address that no longer exists** in `config/slus_01411/matching_c.json`,
and **351 US units have no coverage at all**. That is why the Japanese queue kept
reading as exhausted -- the queue was the pair list, not the binary.

The mechanism is the translation-unit splitting he does upstream. #5600 split
`sorted_entry_relink.c` from two functions to one; the function that moved out
carried the unit's only pair entry, so the remainder reported "no function of the
unit has a JP pair" and left the queue silently. It looks like missing data and
is an upstream reshape.

HOW IT RECOVERS A PAIR, and why a wrong guess cannot get through. Both
executables lay the same code out in the same order, so the displacement between
a US function and its target counterpart is locally constant and changes only at
region boundaries. For an uncovered unit we take the displacement of the nearest
already-known pair (and its two neighbours), predict the target address, and then
hand the two word streams to `jp_promote.pair_words` -- the SAME check the
promoter runs before it writes any config. It accepts a differing word only as a
symbol half, a gp-relative offset or a jal target; anything else is a rejection.
So a wrong prediction does not produce a wrong pair, it produces no pair.

`--check` runs the negative control that makes that claim measurable: for a
sample of the recoveries it re-tries the same unit at the predicted address off
by one instruction and by one function, and asserts every one of those is
REJECTED. A method that cannot say no is not a method.

The pair list keys on the unit's FIRST function only; jp_promote infers the rest
of a unit by contiguity, which is what it already does for partially covered
units.
"""
import bisect, collections, csv, struct, sys, pathlib

sys.path.insert(0, str(pathlib.Path(__file__).resolve().parent))
import jp_promote as M

WRITE = "--write" in sys.argv
CHECK = "--check" in sys.argv or WRITE


def words(buf, addr, size):
    o = addr - M.LOAD + M.HDR
    b = buf[o:o + size]
    if len(b) != size or size % 4: return None
    return list(struct.unpack("<%dI" % (size // 4), b))


def main():
    us, jp, pairs, names, jpsyms = M.load_all()
    usb, jpb = M.US_EXE.read_bytes(), M.JP_EXE.read_bytes()
    by_src = collections.defaultdict(list)
    for a, x in us.items(): by_src[x["source"]].append(a)
    known = sorted(pairs)
    delta = {a: pairs[a] - a for a in known}
    stale = [a for a in known if a not in us]
    print(f"pair list: {len(pairs)} entries, {len(stale)} naming a US address that no longer exists")

    def predicted(a):
        i = bisect.bisect_right(known, a) - 1
        out, seen = [], set()
        for k in (i, i + 1, i - 1):
            if 0 <= k < len(known) and delta[known[k]] not in seen:
                seen.add(delta[known[k]]); out.append(delta[known[k]])
        return out

    def verify(addrs, sizes, d):
        """The promoter's own check, at a predicted displacement."""
        tot = sum(sizes)
        uw = words(usb, addrs[0], tot)
        jw = words(jpb, addrs[0] + d, tot)
        if uw is None or jw is None: return None
        ok, syms, _why = M.pair_words(uw, jw, names, pairs, (addrs[0], addrs[0] + d))
        return syms if ok else None

    # FALLBACK: find the unit by its SHAPE. Measured 2026-09-22 on the 129 units
    # the displacement predictor could not pair: 84 failed on an opcode, which
    # means the predicted address was wrong, not the code -- the JP build moved
    # some functions a long way (card_list_render_deck_box_stats by 0x114cc).
    # The first K instructions with immediates and jump targets masked are
    # looked up across the whole target .text, and a hit still has to pass
    # pair_words, so a shape collision cannot become a pair.
    K = 8
    def mask(w):
        op = w >> 26
        if op in (2, 3): return w & 0xFC000000
        if op == 0: return w
        return w & 0xFFFF0000
    n = (len(jpb) - M.HDR) // 4
    jm = [mask(w) for w in struct.unpack("<%dI" % n, jpb[M.HDR:M.HDR + n * 4])]
    shape = collections.defaultdict(list)
    for i in range(n - K): shape[tuple(jm[i:i + K])].append(M.LOAD + i * 4)

    recovered, tried, by_shape = [], 0, 0
    for src, addrs in sorted(by_src.items()):
        addrs.sort()
        if any(a in pairs for a in addrs): continue
        sizes = [int(us[a]["size"], 16) for a in addrs]
        if any(addrs[i] + sizes[i] != addrs[i + 1] for i in range(len(addrs) - 1)):
            continue                       # not contiguous: the unit is not one block
        tried += 1
        for d in predicted(addrs[0]):
            syms = verify(addrs, sizes, d)
            if syms is not None:
                recovered.append((src, addrs, sizes, d, len(syms))); break
        else:
            uw = words(usb, addrs[0], sum(sizes))
            hits = [(ja - addrs[0], s) for ja in shape.get(tuple(mask(w) for w in uw[:K]), [])
                    for s in [verify(addrs, sizes, ja - addrs[0])] if s is not None]
            if len(hits) == 1:             # a unique verified hit only
                recovered.append((src, addrs, sizes, hits[0][0], len(hits[0][1]))); by_shape += 1
    print(f"uncovered contiguous units: {tried}")
    print(f"recovered: {len(recovered)} units, {sum(len(r[1]) for r in recovered)} functions "
          f"({by_shape} of the units by shape search)")

    if CHECK:
        # NEGATIVE CONTROL. The same units at a displacement that is wrong by one
        # instruction, and by one whole first function, must all be REJECTED.
        bad = []
        for src, addrs, sizes, d, _ in recovered[:40]:
            for off in (4, -4, sizes[0]):
                if verify(addrs, sizes, d + off) is not None:
                    bad.append((src, d, off))
        print(f"negative control: {len(recovered[:40]) * 3} deliberately wrong displacements tried, "
              f"{len(bad)} wrongly accepted")
        if bad:
            for b in bad[:5]: print("   ACCEPTED A WRONG PAIR:", b)
            sys.exit("negative control FAILED -- the verification cannot say no, so the recoveries mean nothing")

    if not WRITE:
        print("\n(measure only; pass --write to merge into config/jp_matches.csv)")
        for src, addrs, sizes, d, ns in sorted(recovered, key=lambda r: -len(r[1]))[:12]:
            print(f"  {src.rsplit('/', 1)[-1][:-2]:<34} {len(addrs):>2} fn  "
                  f"US {addrs[0]:#x} -> JP {addrs[0] + d:#x}  delta {d:+#x}  syms {ns}")
        return

    rows = list(csv.DictReader(open(M.PAIRS)))
    have = {r["address2"].lower() for r in rows}
    added = 0
    for src, addrs, sizes, d, _ in recovered:
        key = f"{addrs[0]:08x}"
        if key in have: continue
        rows.append({"address": f"{addrs[0] + d:08x}", "address2": key}); added += 1
    rows.sort(key=lambda r: int(r["address2"], 16))
    with open(M.PAIRS, "w", newline="") as fh:
        w = csv.DictWriter(fh, fieldnames=["address", "address2"])
        w.writeheader(); w.writerows(rows)
    print(f"wrote {M.PAIRS}: {len(rows)} entries ({added} added, existing entries kept)")


if __name__ == "__main__":
    main()
