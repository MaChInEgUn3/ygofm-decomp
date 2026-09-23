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

WHAT IT REFUSES, each learned by hand (and one thing it does NOT see: a callee
reached through an `asm("NAME")` label, like external_funcs.h's
SD_ConfigureTransferPhase_callback -- a #define cannot rename inside the string,
so the link fails with "undefined reference to NAME"; leave that function out):
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


def _clashes():
    """(wrapper, name) pairs where a wrapper #defines a name symbols.txt also lines up.
    The tree has some on purpose (data aliases), so only NEW ones are an error."""
    final = {m[1] for m in re.finditer(r"^(\w+) = ", (CFG / "symbols.txt").read_text(), re.M)}
    out = set()
    for wf in (KG / "src/game/japanese").glob("*.c"):
        for m in re.finditer(r"^#define (\w+) ", wf.read_text(), re.M):
            if m.group(1) in final and not m.group(1).startswith("VERSION_JAPAN"): out.add((wf.name, m.group(1)))
    return out


def _guard_whole_file(s, src):
    """A file with no VERSION_JAPAN at all: put every function definition under
    `#ifndef VERSION_JAPAN` first, so the split below can open the promoted ones.
    Refused when anything outside the functions DEFINES data -- the wrapper would
    compile it a second time."""
    code = re.sub(r"/\*.*?\*/", lambda m: " " * len(m.group(0)), s, flags=re.S)
    code = re.sub(r"//[^\n]*", lambda m: " " * len(m.group(0)), code)
    spans = []
    for m in re.finditer(r"^[A-Za-z_][^;{}()\n]*\b\w+\s*\([^;{}]*\)\s*\{", code, re.M):
        if spans and m.start() < spans[-1][1]: continue
        j = code.index("\n}\n", m.end()) + 3
        spans.append((m.start(), j))
    if not spans: sys.exit(f"{src}: no function definitions found")
    outside, prev = [], 0
    for a0, b0 in spans:
        outside.append(code[prev:a0]); prev = b0
    outside.append(code[prev:])
    for chunk in outside:
        for line in chunk.split("\n"):
            t = line.strip()
            if t.endswith(";") and not t.startswith(("extern", "typedef", "#")) and "(" not in t.split("=")[0]:
                sys.exit(f"{src} defines data outside its functions ({t[:50]!r}); guard it by hand")
    out, prev = [], 0
    for a0, b0 in spans:
        # keep a comment that ends right above the definition with it
        k = a0
        above = s[:k].rstrip()
        if above.endswith("*/"):
            k = s.rfind("\n", 0, s.rfind("/*", 0, len(above))) + 1
        out.append(s[prev:k]); out.append("#ifndef VERSION_JAPAN\n" + s[k:b0] + "#endif\n"); prev = b0
    out.append(s[prev:])
    s = "".join(out)
    return s.replace("#endif\n\n#ifndef VERSION_JAPAN\n", "\n").replace("#endif\n#ifndef VERSION_JAPAN\n", "")


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("unit"); ap.add_argument("wrapper"); ap.add_argument("guard")
    ap.add_argument("pairs_", nargs="+", metavar="US:JP")
    ap.add_argument("--patch", action="append", default=[])
    ap.add_argument("--define", action="append", default=[])
    a = ap.parse_args()
    clash0 = _clashes()
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

    # the naming is jp_promote.analyze's, on just these functions: a second US name
    # (`D_8009B0F4_abs`), a base the source names but no instruction carries
    # (`gFade_State`), a name splat already gives the JP address, an asm label.
    # A first version of this tool re-derived those rules and got each wrong once.
    has_table = False
    for ua, ja in fns:
        if ua not in us or us[ua]["source"] != src: sys.exit(f"{ua:#x} is not a function of {src}")
        sz = int(us[ua]["size"], 16); uw = words(usb, ua, sz)
        # a `jr` through anything but $ra is a switch whose table sits in .rodata,
        # which this tool does not carve (library_runtime's func_8002BAB4 linked
        # with the table still pointing at labels the asm no longer had)
        if any(w >> 26 == 0 and (w & 0x3F) == 0x08 and (w >> 21) & 31 != 31 for w in uw):
            has_table = True
        # a call into an overlay: the Japanese link has no overlay symbols
        # (main_mode_runners' Main_RunTrade -> MainMenu_InitTradeScreen)
        if any(w >> 26 == 3 and (0x80000000 | ((w & 0x3FFFFFF) << 2)) >= 0x80100000 for w in uw):
            sys.exit(f"{names.get(ua)} calls into an overlay, which the Japanese link cannot resolve")
    # a switch's table moves with the function only when the unit's WHOLE .rodata
    # block points into these functions (func_80014294's 7 words are all
    # File_StepActiveTransfer's); a block shared with functions left behind
    # (library_runtime, ai_script_control_flow) needs the whole unit
    if has_table:
        blk = M.US_RODATA.get(f"game/{a.unit}")
        if not blk: sys.exit(f"{src} has a jump table but no US .rodata block")
        lo = fns[0][0]; hi = fns[-1][0] + int(us[fns[-1][0]]["size"], 16)
        tw = words(usb, blk[0] - M.HDR + M.LOAD, blk[1])
        mine = [i for i, w in enumerate(tw) if lo <= w < hi]
        if not mine: sys.exit(f"{src}'s .rodata block has no word pointing into these functions")
        # the tables these functions own may be a contiguous SUFFIX of the block
        # (model_texture_transfer: func_80056D7C's 17 words stay, func_80057544's
        # and func_800577B0's follow); then only that suffix is carved
        first = mine[0]
        outside = [w for w in tw[first:] if 0x80010000 <= w < 0x80090000 and not lo <= w < hi]
        if outside or mine != list(range(first, len(tw))):
            sys.exit(f"{src}'s .rodata block points outside these functions ({len(outside)} words) "
                     "and the rest is not a suffix of it; promote the whole unit")
        if first:
            M.US_RODATA[f"game/{a.unit}"] = (blk[0] + 4 * first, blk[1] - 4 * first)
    if patches:
        M.REGIONAL[a.unit] = (fns[0][1], [(wa, ui, ji) for wa, (ui, ji) in patches.items()], [])
    r = M.analyze(us, jp, pairs, names, jpsyms, fns[0][0],
                  only=[u for u, _ in fns], jps_given=[j for _, j in fns], rodata_ok=has_table)
    if has_table and not r.get("rodata"):
        sys.exit(f"{src}: the jump table's JP copy was not derived ({r.get('why')})")
    if not r.get("ok"): sys.exit(f"{src}: {r.get('why')}")
    aliases, lines, asm_lines = dict(r["aliases"]), dict(r["lines"]), list(r.get("asm_aliases") or [])
    renames = {names[u]: n for (u, _), n in zip(fns, r["names"]) if n != names[u]}
    # existing Japanese wrappers may call a function of this call by its
    # JP-address name, from when it was asm (func_80014294's wrappers call
    # `func_8001427C`): the definition must then carry that name, and the US
    # name gets no symbols line
    others = "".join(wf.read_text(errors="replace") for wf in (KG / "src/game/japanese").glob("*.c")
                     if wf.stem != a.wrapper)
    for (u, j), n in zip(fns, r["names"]):
        jn = f"func_{j:08X}"
        if n != jn and re.search(r"\b%s\b" % jn, others):
            aliases[names[u]] = jn; renames[names[u]] = jn
            lines.pop(names[u], None); lines.pop(n, None)
    # each promoted function whose final name is not splat's automatic one needs a
    # symbols line, or splat keeps labelling the address `func_<JP>` and the asm
    # around it calls a name no object defines (File_StepActiveTransfer, still
    # asm, called func_8001427C); jp_batch's apply writes the same lines
    for (u, j), n in zip(fns, r["names"]):
        final = aliases.get(names[u], n)
        if final != f"func_{j:08X}" and jsym.get(final) != j: lines[final] = j

    # ---- the US source: split each function out of its #ifndef VERSION_JAPAN block
    p = KG / src; s = p.read_text()
    if "VERSION_JAPAN" not in s:
        s = _guard_whole_file(s, src)
    for ua, ja in fns:
        fn = names[ua]
        mdef = re.search(r"\n([^\n;{}]*\b%s\s*\([^;{]*\)\s*\{)" % re.escape(fn), s)
        if not mdef: sys.exit(f"no definition of {fn} in {src}")
        i = mdef.start() + 1
        # take the comment right above the definition with it. A /* */ comment is
        # taken WHOLE, from its closing line back to the line holding its `/*`:
        # reading line by line for a leading `*` stopped halfway through a comment
        # whose middle lines do not start with one (sound_sequence_parser), put the
        # guard inside the comment and left the function under #ifndef VERSION_JAPAN
        while True:
            prev = s.rfind("\n", 0, i - 1) + 1
            line = s[prev:i - 1].strip()
            if line.endswith("*/"):
                k = s.rfind("/*", 0, i - 1)
                i = s.rfind("\n", 0, k) + 1
            elif line.startswith("//"):
                i = prev
            elif line == "" and s[:prev].rstrip().endswith("*/"):
                i = prev   # a blank line between the comment and the function
            else:
                break
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
    # a #ifndef VERSION_JAPAN block left holding only macros, comments and blank
    # lines loses its guard: the US build already saw it, and a promoted function
    # next to it needs it (library_runtime's `#define gStageRect (D_800E9D70[0])`
    # sat between two promoted functions and the Japanese compile lost it)
    def _only_macros(body):
        body = re.sub(r"/\*.*?\*/", "", body, flags=re.S)
        body = re.sub(r"\\\n", " ", body)
        return all(l.strip() == "" or l.strip().startswith(("#define", "//")) for l in body.split("\n"))
    s = re.sub(r"#ifndef VERSION_JAPAN\n((?:(?!#if|#endif).)*?)#endif\n",
               lambda m: (m.group(1).strip("\n") + "\n") if _only_macros(m.group(1)) else m.group(0),
               s, flags=re.S)
    # (the strip: the directives' own blank lines would otherwise double up around
    # the macro, and `make basic-types` refuses a double blank line)
    s = s.rstrip("\n") + "\n"   # a split of the file's last block left a blank line at EOF
    # the two ways the split went wrong by hand, checked on the result: a guard
    # inside a /* */ comment, and a #ifndef block holding nothing but a comment
    inside = [m.start() for m in re.finditer(r"#(if|endif)", s)
              if s.rfind("/*", 0, m.start()) > s.rfind("*/", 0, m.start())]
    orphan = re.findall(r"#ifndef VERSION_JAPAN\n(?:\s*/\*.*?\*/\s*)+#endif", s, re.S)
    if inside or orphan:
        sys.exit(f"{src}: {len(inside)} directive(s) inside comments, {len(orphan)} comment-only block(s)")
    p.write_text(s)

    # ---- prototypes: a function of the same file that the promoted ones use (a
    # callback address, a call) but that stays outside this guard is declared only
    # by its own definition, which the wrapper no longer compiles
    # (File_StepActiveTransfer takes func_80014294, func_80014308 and
    # func_80014390 as callbacks: "`func_80014390' undeclared")
    code_all = re.sub(r"/\*.*?\*/", " ", s, flags=re.S)
    heads = {m.group(2): m.group(1).strip() for m in
             re.finditer(r"^((?:static\s+)?[A-Za-z_][\w\s\*]*?\b(\w+)\s*\([^;{}]*\))\s*\{", code_all, re.M)}
    own_names = {names[u] for u, _ in fns}
    bodies = ""
    for u, _ in fns:
        mdef = re.search(r"\b%s\s*\([^;{]*\)\s*\{" % re.escape(names[u]), code_all)
        if mdef: bodies += code_all[mdef.end():code_all.index("\n}\n", mdef.end())]
    protos = [heads[n] + ";" for n in sorted(heads) if n not in own_names
              and re.search(r"\b%s\b" % re.escape(n), bodies) and not heads[n].startswith("static")]

    # ---- wrapper
    body = ['#include "../../types.h"', "", "#define VERSION_JAPAN", f"#define {a.guard}"]
    body += [f"#define {d.split('=', 1)[0]} {d.split('=', 1)[1]}" for d in a.define]
    body += [f"#define {n} {v}" for n, v in sorted(aliases.items())]
    body += asm_lines
    body += [f'#include "../{a.unit}.c"', ""]
    if protos:
        # after the include would be too late; they go in front of it, after the
        # types, so the #defines above rename them too
        k = body.index(f'#include "../{a.unit}.c"')
        body[k:k] = ["", "/* Same-file functions this one uses but that stay outside its guard. */"] + protos + [""]
    w = KG / f"src/game/japanese/{a.wrapper}.c"
    if w.exists(): sys.exit(f"{w} exists")
    w.write_text("\n".join(body))

    # ---- split.yaml: one c row per contiguous run of promoted functions
    runs = []
    for ua, ja in fns:
        sz = int(us[ua]["size"], 16)
        if runs and runs[-1][1] == ja: runs[-1][1] = ja + sz
        else: runs.append([ja, ja + sz])
    # one wrapper is one object: two separate runs under one wrapper would put the
    # same object (with every run in it) at both places. Refuse; call once per run,
    # each with its own GUARD and WRAPPER (sound_sequence_parser had three runs).
    if len(runs) > 1:
        sys.exit(f"{len(runs)} separate runs {[hex(r[0]) for r in runs]}: call once per contiguous run")
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
    if r.get("rodata"):
        roff, rsize = r["rodata"]
        rrows = [(i, int(m.group(1), 16), m.group(2)) for i, l in enumerate(st)
                 for m in [re.match(r"\s+- \[(0x[0-9a-f]+), (asm|c|rodata|\.rodata|bin|pad|data|sdata)", l)] if m]
        i0, o0, t0 = max((x for x in rrows if x[1] <= roff), key=lambda x: x[1])
        if t0 != "rodata": sys.exit(f".rodata block at {roff:#x} does not sit in an initial-data blob row")
        nxt = min(o for _, o, _ in rrows if o > o0)
        new = [] if o0 == roff else [st[i0]]
        new.append(f"      - [{roff:#x}, .rodata, game/japanese/{a.wrapper}]")
        if roff + rsize < nxt: new.append(f"      - [{roff + rsize:#x}, rodata, initial_data_{roff + rsize:x}]")
        st[i0] = "\n".join(new)
        st = "\n".join(st).split("\n")
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
    # consistency across calls: no name may be both a symbols.txt line and a
    # #define in a Japanese wrapper (func_80014308 was renamed by one call and
    # given a line by another, so the asm around it called a name nothing defined)
    # a NAME already in that state in some existing wrapper is the tree's own
    # pattern (D_8009B360 is #defined in several and has a line); only a name that
    # was clean before this call is an error
    known = {n for _, n in clash0}
    new = sorted(c for c in _clashes() - clash0 if c[1] not in known)
    if new: sys.exit(f"names both #defined in a wrapper and given a symbols line by this call: {new[:8]}")
    print(f"{a.wrapper}: {len(fns)} fn, {len(runs)} c row(s), {len(aliases)} aliases, "
          f"{len(renames)} renames {renames}, {len(lines)} lines")


if __name__ == "__main__":
    main()
