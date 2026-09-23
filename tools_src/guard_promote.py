#!/usr/bin/env python3
"""Promote SOME functions of a US unit to the Japanese build, under a VERSION_JAPAN guard.

    .venv/bin/python tools_src/guard_promote.py UNIT WRAPPER GUARD US_ADDR:JP_ADDR [US_ADDR:JP_ADDR ...]
        [--patch US_WORD_ADDR:US_IMM:JP_IMM ...] [--define MACRO=VALUE ...]

Writes into krystalgamer's tree, on whatever branch is checked out:
  * src/game/UNIT.c: each function opened with `#if !defined(VERSION_JAPAN) ||
    defined(GUARD)`, split out of the `#ifndef VERSION_JAPAN` block it sits in;
  * src/game/japanese/WRAPPER.c: VERSION_JAPAN, GUARD, --define lines, aliases;
  * config/slpm_86398/{split.yaml,matching_c.json,symbols.txt}.

WHY IT EXISTS. jp_select and jp_batch promote whole units. When a unit's last
functions differ in the Japanese build, the rest of it pairs word for word but
never gets promoted. The maintainer's own pattern for that is this guard
(#5922, and #5928/#5933/#5942/#5943 by hand). The census of 2026-09-23 found
about 95 such functions. Every step below was done by hand five times first.

WHAT IT REFUSES, each learned by hand:
  * a function that does not pair (pair_words, with the --patch immediates only);
  * a US source file where the function is not inside `#ifndef VERSION_JAPAN`,
    because in an unguarded file the wrapper would compile every other function
    too. Guard those files by hand;
  * a JP address already in the Japanese manifest.
The immediates in --patch are checked in both binaries, as REGIONAL entries are.

NAMES. The promoted function keeps its US name when symbols.txt already maps it
to its JP address (lesson of batch 38: Main_Init called func_80013154 by that
name). It takes an existing name when symbols.txt names the JP address. Otherwise
it takes the JP-address name `func_<JP>`, which is how the asm around it calls it.
Callees and data follow pair_words: an address symbols.txt already names is
#defined to that name; a US name that symbols.txt maps elsewhere gets a
gJapanese_ name; a function already promoted in C with no line is #defined to
func_<JP>; everything else gets a line.
"""
import argparse, json, pathlib, re, sys

sys.path.insert(0, str(pathlib.Path(__file__).resolve().parent))
import jp_promote as M
from jp_pairs import words

KG = M.KG
CFG = KG / "config/slpm_86398"


def sub1(s, a, b):
    if s.count(a) != 1: sys.exit(f"expected one occurrence of {a[:60]!r}, found {s.count(a)}")
    return s.replace(a, b)


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("unit"); ap.add_argument("wrapper"); ap.add_argument("guard")
    ap.add_argument("pairs_", nargs="+", metavar="US:JP")
    ap.add_argument("--patch", action="append", default=[])
    ap.add_argument("--define", action="append", default=[])
    a = ap.parse_args()
    us, jp, pairs, names, jpsyms = M.load_all()
    usb, jpb = M.US_EXE.read_bytes(), M.JP_EXE.read_bytes()
    patches = {}
    for p in a.patch:
        ua, ui, ji = (int(x, 16) for x in p.split(":")); patches[ua] = (ui, ji)
    fns = sorted((int(u, 16), int(j, 16)) for u, j in (x.split(":") for x in a.pairs_))
    src = f"src/game/{a.unit}.c"
    txt = (CFG / "symbols.txt").read_text()
    jsym = {m[1]: int(m[2], 16) for m in re.finditer(r"^(\w+) = (0x[0-9A-Fa-f]+);", txt, re.M)}
    byaddr = {}
    for n, v in jsym.items(): byaddr.setdefault(v, []).append(n)

    aliases, lines, renames = {}, {}, {}
    for ua, ja in fns:
        if ua not in us or us[ua]["source"] != src: sys.exit(f"{ua:#x} is not a function of {src}")
        if ja in jp: sys.exit(f"{ja:#x} is already in the Japanese manifest")
        sz = int(us[ua]["size"], 16)
        uw = words(usb, ua, sz); jw = list(words(jpb, ja, sz))
        for wa, (ui, ji) in patches.items():
            k = (wa - ua) // 4
            if 0 <= k < len(uw):
                if uw[k] & 0xFFFF != ui or jw[k] & 0xFFFF != ji or (uw[k] ^ jw[k]) & 0xFFFF0000:
                    sys.exit(f"--patch {wa:#x} does not hold in the binaries")
                jw[k] = uw[k]
        ok, syms, why = M.pair_words(uw, jw, names, pairs, (ua, ja))
        if not ok: sys.exit(f"{names.get(ua)} at {ja:#x} does not pair: {why}")
        own = names[ua]
        if jsym.get(own) == ja: pass
        elif ja in byaddr: renames[own] = byaddr[ja][0]
        else: renames[own] = f"func_{ja:08X}"
        for n, v in syms.items():
            if jsym.get(n) == v: continue
            m = re.match(r"(D|func)_([0-9A-Fa-f]{8})$", n)
            if v in byaddr: aliases[n] = byaddr[v][0]
            elif n in jsym:
                aliases[n] = ("gJapanese_" if not n.startswith("func_") else "Japanese_") + n
                lines[aliases[n]] = v
            # already C in the Japanese build with no symbols line: its wrapper
            # defines it under the JP-address name, whatever its US name is
            # (DisplayEffect_BuildResourceObjects is `func_8003986C` there)
            elif v in jp and v not in byaddr: aliases[n] = f"func_{v:08X}"
            else: lines[n] = v

    # ---- the US source: split each function out of its #ifndef VERSION_JAPAN block
    p = KG / src; s = p.read_text()
    for ua, ja in fns:
        fn = names[ua]
        mdef = re.search(r"\n([^\n;{}]*\b%s\s*\([^;{]*\)\s*\{)" % re.escape(fn), s)
        if not mdef: sys.exit(f"no definition of {fn} in {src}")
        i = mdef.start() + 1
        # take the comment block right above the definition with it
        while True:
            prev = s.rfind("\n", 0, i - 1) + 1
            line = s[prev:i - 1]
            if line.strip().startswith(("/*", "*", "//")) or line.strip().endswith("*/"): i = prev
            else: break
        j = s.index("\n}\n", mdef.end()) + 3
        before = s[:i]
        opened = before.rfind("#ifndef VERSION_JAPAN\n"); closed = before.rfind("#endif")
        if opened < 0 or closed > opened:
            sys.exit(f"{fn} is not inside `#ifndef VERSION_JAPAN` in {src}; guard this file by hand")
        s = (s[:i] + f"#endif\n\n#if !defined(VERSION_JAPAN) || defined({a.guard})\n" + s[i:j]
             + "#endif\n\n#ifndef VERSION_JAPAN\n" + s[j:])
    # drop the blocks the splits left empty, and join neighbouring functions that
    # carry the same guard into one block
    s = re.sub(r"#ifndef VERSION_JAPAN\n\s*#endif\n\n?", "", s)
    # only when the block BEFORE carries the same guard: a plain replace of
    # `#endif / #if GUARD` also swallowed the #endif of a neighbouring block with
    # ANOTHER guard (display_effect_update_callbacks: func_8003AAE4 ended up inside
    # VERSION_JAPAN_DISPLAY_EFFECT_POSITION_INTERPOLATION and linked unaliased)
    opener = f"#if !defined(VERSION_JAPAN) || defined({a.guard})\n"
    join = re.compile(re.escape(opener) + r"((?:(?!#if|#endif).)*?)#endif\n\n" + re.escape(opener), re.S)
    while True:
        s2 = join.sub(lambda m: opener + m.group(1) + "\n", s)
        if s2 == s: break
        s = s2
    p.write_text(s)

    # ---- wrapper
    body = ['#include "../../types.h"', "", "#define VERSION_JAPAN", f"#define {a.guard}"]
    body += [f"#define {d.split('=', 1)[0]} {d.split('=', 1)[1]}" for d in a.define]
    body += [f"#define {n} {v}" for n, v in sorted(aliases.items())]
    body += [f"#define {n} {v}" for n, v in sorted(renames.items())]
    body += [f'#include "../{a.unit}.c"', ""]
    w = KG / f"src/game/japanese/{a.wrapper}.c"
    if w.exists(): sys.exit(f"{w} exists")
    w.write_text("\n".join(body))

    # ---- split.yaml: one c row per contiguous run of promoted functions
    runs = []
    for ua, ja in fns:
        sz = int(us[ua]["size"], 16)
        if runs and runs[-1][1] == ja: runs[-1][1] = ja + sz
        else: runs.append([ja, ja + sz])
    sp = CFG / "split.yaml"; st = sp.read_text().split("\n")
    rows = [(i, int(m.group(1), 16), m) for i, l in enumerate(st)
            for m in [re.match(r"\s+- \[(0x[0-9a-f]+), (asm|c|rodata|\.rodata|bin|pad|data)", l)] if m]
    for js, je in runs:
        fs, fe = js - M.LOAD + M.HDR, je - M.LOAD + M.HDR
        cov = [(i, o) for i, o, m in rows if o <= fs and m.group(2) == "asm"]
        i0, o0 = max(cov, key=lambda t: t[1])
        nxt = min(o for i, o, m in rows if o > o0)
        if fe > nxt: sys.exit(f"{js:#x}..{je:#x} runs past the asm row at {o0:#x}")
        new = []
        if o0 < fs: new.append(st[i0])
        new.append(f"      - [{fs:#x}, c, game/japanese/{a.wrapper}]")
        if fe < nxt: new.append(f"      - [{fe:#x}, asm, func_{je:08X}]")
        st[i0] = "\n".join(new)
        st = "\n".join(st).split("\n")
        rows = [(i, int(m.group(1), 16), m) for i, l in enumerate(st)
                for m in [re.match(r"\s+- \[(0x[0-9a-f]+), (asm|c|rodata|\.rodata|bin|pad|data)", l)] if m]
    sp.write_text("\n".join(st))

    # ---- manifest
    mp = CFG / "matching_c.json"; s = mp.read_text()
    for ua, ja in fns:
        block = ('    {\n      "address": "0x%08X",\n      "profile": "%s",\n      "size": "0x%X",\n'
                 '      "source": "src/game/japanese/%s.c"\n    },\n') % (ja, us[ua]["profile"],
                                                                         int(us[ua]["size"], 16), a.wrapper)
        ms = [(int(m.group(1), 16), m.start()) for m in re.finditer(r'    \{\n      "address": "(0x[0-9A-F]+)"', s)]
        pos = next(st_ for ad, st_ in ms if ad > ja)
        s = s[:pos] + block + s[pos:]
    json.loads(s); mp.write_text(s)

    # ---- symbols
    if lines:
        s = (CFG / "symbols.txt").read_text()
        if not s.endswith("\n"): s += "\n"
        s += "".join(f"{n} = 0x{v:08X};\n" for n, v in sorted(lines.items(), key=lambda t: t[1]))
        (CFG / "symbols.txt").write_text(s)
    print(f"{a.wrapper}: {len(fns)} fn, {len(runs)} c row(s), {len(aliases)} aliases, "
          f"{len(renames)} renames {renames}, {len(lines)} lines")


if __name__ == "__main__":
    main()
