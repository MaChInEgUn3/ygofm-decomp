#!/usr/bin/env python3
"""Promote a US matching_c unit to the Japanese build (SLPM-86398) in krystalgamer's tree.

    .venv/bin/python tools_src/jp_promote.py scan                 # every queued pair: word-level verdict, no writes
    .venv/bin/python tools_src/jp_promote.py apply 0x800XXXXX     # US address: write split.yaml / matching_c.json / symbols.txt

The JP function is proven only by `make japanese-match`; this tool writes the
three files the merged PRs write (#5611 is the model) and reports what it could
derive. Word-level pairing: the US bytes of the unit and the JP bytes at the
paired address are compared word by word; a differing word must be a symbol
half (lui / lo pair), a gp-relative offset, or a jal target, and each such
difference yields `USName = JPaddr;` for symbols.txt. Any other difference
means the code is not the same and the unit is skipped.
"""
import collections, csv, json, os, re, struct, sys, pathlib

ROOT = pathlib.Path(__file__).resolve().parent.parent
# his tree checked out beside this one, or YGOFM_KG=<path> (same convention as port_kg.py)
KG = pathlib.Path(os.environ.get("YGOFM_KG", ROOT.parent / "memories-decomp"))
PAIRS = ROOT / "config" / "jp_matches.csv"   # address = JP, address2 = US; the pair list the scan starts from
US_EXE, JP_EXE = KG / "game/SLUS_014.11", KG / "game/japanese/SLPM_863.98"
LOAD, HDR = 0x80010000, 0x800
GP_US, GP_JP = None, 0x8009AE48

def sx16(v): return v - 0x10000 if v & 0x8000 else v

def words(exe, addr, size):
    b = exe.read_bytes()[addr - LOAD + HDR: addr - LOAD + HDR + size]
    return list(struct.unpack("<%dI" % (len(b) // 4), b))

def load_all():
    global GP_US
    us = {int(f["address"], 16): f for f in json.load(open(KG / "config/slus_01411/matching_c.json"))["functions"]}
    jp = {int(f["address"], 16): f for f in json.load(open(KG / "config/slpm_86398/matching_c.json"))["functions"]}
    pairs = {}
    for r in csv.DictReader(open(PAIRS)):
        pairs[int(r["address2"], 16)] = int(r["address"], 16)     # US -> JP
    names = {}
    for line in open(KG / "config/slus_01411/symbols.txt"):
        m = re.match(r"\s*(\w+)\s*=\s*(0x[0-9A-Fa-f]+)", line)
        if m: names[int(m.group(2), 16)] = m.group(1)
    # the C sources define functions by the name in functions.csv, which
    # symbols.txt does not always carry (first apply: three undefined
    # `func_` names because the file names them differently)
    for r in csv.DictReader(open(KG / "config/slus_01411/functions.csv")):
        names[int(r["address"], 16)] = r["name"]
    jpsyms = {}
    for line in open(KG / "config/slpm_86398/symbols.txt"):
        m = re.match(r"\s*(\w+)\s*=\s*(0x[0-9A-Fa-f]+)", line)
        if m: jpsyms[m.group(1)] = int(m.group(2), 16)
    # EVERY US name of an address, `names` keeps one. 76 addresses carry more
    # than one, and `config/slus_01411/c_symbols.ld` -- which the US link
    # takes and the JP link does not -- is where the second one usually lives
    # (fade_runtime reads 0x800E9EC8 as both `gFade_State` and
    # `D_800E9EC8_arr`, and the JP link wanted the name nobody mapped)
    global ALT_NAMES
    ALT_NAMES = collections.defaultdict(set)
    for a, n in names.items(): ALT_NAMES[a].add(n)
    for line in open(KG / "config/slus_01411/c_symbols.ld"):
        m = re.match(r"\s*(\w+)\s*=\s*(0x[0-9A-Fa-f]+)\s*;", line)
        if m: ALT_NAMES[int(m.group(2), 16)].add(m.group(1))
    global US_RODATA
    us_split = (KG / "config/slus_01411/split.yaml").read_text()
    m = re.search(r"gp_value:\s*(0x[0-9a-fA-F]+)", us_split)
    GP_US = int(m.group(1), 16)
    # a unit with its own .rodata subsegment (a switch table) needs the JP
    # table placed too; the word comparison covers .text only, so those are
    # flagged rather than applied (3 of the 81 clean units on 2026-09-21)
    US_RODATA = set(re.findall(r"\.rodata, (game/\S+)\]", us_split))
    global JPVRAM, JP_AUTO
    JPVRAM = {a: n for n, a in jpsyms.items()}       # JP address -> the name JP already gives it
    # default names JP splat generated for ITS OWN addresses (from the last
    # japanese-split): a US `D_8009B314` mapped to another JP address collides
    # with them, and the linker then takes splat's definition (measured:
    # sorted_entry_relink, built lo 0xB314 where JP has 0xB204)
    JP_AUTO = set()
    for p in list((KG / "tmp/splat/slpm_86398/asm").rglob("*.s")) + [KG / "tmp/splat/slpm_86398/undefined_syms_auto.txt", KG / "tmp/splat/slpm_86398/undefined_funcs_auto.txt", KG / "tmp/splat/slpm_86398/slpm_86398.ld"]:
        if p.exists():
            JP_AUTO.update(re.findall(r"\b(?:D|func)_[0-9A-Fa-f]{8}\b", p.read_text(errors="replace")))
    if not JP_AUTO: sys.exit("no tmp/splat/slpm_86398 output: run `make japanese-split` in his tree first")
    JP_AUTO -= set(jpsyms)      # a D_ name symbols.txt gave a JP address is a user name, not a collision
    return us, jp, pairs, names, jpsyms

def usname(names, addr, func=False):
    return names.get(addr) or (("func_%08X" if func else "D_%08X") % addr)

LOADSTORE = {0x08, 0x09, 0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x28, 0x29, 0x2A, 0x2B, 0x2E, 0x31, 0x39}

def pair_words(uw, jw, names, func_map, uw_base=(0, 0)):
    """Return (ok, symbol map {USname: JPaddr}, reason)."""
    if len(uw) != len(jw): return False, {}, "size differs"
    lui = {}       # rt -> (us_hi, jp_hi)
    syms = {}      # US name -> JP address, where the two differ
    eq = {}        # US name -> address, where they are equal: the JP link still needs
                   # a line for a NAMED symbol (splat only auto-labels D_/func_ names)
    def put(uaddr, jaddr, func=False):
        n = usname(names, uaddr, func)
        if uaddr == jaddr:
            eq[n] = jaddr; return True
        if syms.get(n, jaddr) != jaddr: return False
        syms[n] = jaddr; return True
    pending = None    # register written by the previous word, dropped from lui before this one
    unpaired = {}     # rt -> word index of a lui whose halves differ and has had no lo use yet
    for i, (u, j) in enumerate(zip(uw, jw)):
        op, rs, rt = u >> 26, (u >> 21) & 31, (u >> 16) & 31
        # the register a word writes: a stale lui entry for it would pair a
        # later displacement off a LOADED pointer as a symbol half (first
        # seen as a bogus `D_FFFF0058` line splat could place nowhere). The
        # drop is deferred one word because `lw $v0, lo($v0)` reads rs first.
        if pending is not None:
            lui.pop(pending, None)
            # a lui whose halves differ and that no load/store/addiu ever
            # consumed was a CONSTANT, and the code differs (text_control_commands:
            # US `lui $a0,0xffff` for a mask where the JP has `lui $a0,0x801f`;
            # the old scan called it clean and the link showed one wrong byte)
            if pending in unpaired: return False, {}, f"word {unpaired[pending]}: lui immediate differs with no lo use"
        if op == 0: dst = (u >> 11) & 31
        elif op == 0x03: dst = 31
        elif op in (0x01, 0x02, 0x04, 0x05, 0x06, 0x07) or op in (0x28, 0x29, 0x2A, 0x2B, 0x2E) or op >= 0x38: dst = None
        else: dst = rt
        pending = dst if (dst and op != 0x0F) else None
        if op == 0x0F and (j >> 26) == 0x0F and ((u ^ j) & 0xFFFF0000) == 0:
            lui[rt] = (u & 0xFFFF, j & 0xFFFF)
            if (u & 0xFFFF) != (j & 0xFFFF): unpaired[rt] = i
            else: unpaired.pop(rt, None)
        if u == j:
            # an equal word still names a symbol: through gp it is the SAME
            # offset from a DIFFERENT gp (US 0x8009AF08, JP 0x8009AE48, so the
            # symbol moved by -0xC0 and needs its line); through a lui pair
            # with equal halves it is an equal address, recorded for the named
            # case (first seen as `undefined reference to gDuel_awPlayerDeck`)
            if op in LOADSTORE and rs == 28:
                ua, ja = (GP_US + sx16(u & 0xFFFF)) & 0xFFFFFFFF, (GP_JP + sx16(j & 0xFFFF)) & 0xFFFFFFFF
                if not put(ua, ja): return False, {}, f"word {i}: gp symbol conflict"
            elif op in LOADSTORE and rs in lui:
                ua = ((lui[rs][0] << 16) + sx16(u & 0xFFFF)) & 0xFFFFFFFF
                ja = ((lui[rs][1] << 16) + sx16(j & 0xFFFF)) & 0xFFFFFFFF
                if not put(ua, ja): return False, {}, f"word {i}: symbol conflict"
                unpaired.pop(rs, None)
            continue
        if op in (0x02, 0x03) and (j >> 26) == op:
            ua, ja = 0x80000000 | ((u & 0x3FFFFFF) << 2), 0x80000000 | ((j & 0x3FFFFFF) << 2)
            if op == 0x02 and (ua - ja) == (uw_base[0] - uw_base[1]):
                continue                              # `j` inside the unit: same displacement, no symbol
            if func_map.get(ua) not in (None, ja): return False, {}, f"word {i}: jal target {ua:#x} pairs to {func_map[ua]:#x} not {ja:#x}"
            if not put(ua, ja, func=True): return False, {}, f"word {i}: jal conflict"
            continue
        if ((u ^ j) & 0xFFFF0000) != 0: return False, {}, f"word {i}: opcode/register differs {u:08x} {j:08x}"
        if op == 0x0F: continue                       # lui halves handled at the lo use
        if op in LOADSTORE and rs == 28:              # gp-relative
            ua, ja = (GP_US + sx16(u & 0xFFFF)) & 0xFFFFFFFF, (GP_JP + sx16(j & 0xFFFF)) & 0xFFFFFFFF
            if not put(ua, ja): return False, {}, f"word {i}: gp symbol conflict"
            continue
        if op in LOADSTORE and rs in lui:
            ua = ((lui[rs][0] << 16) + sx16(u & 0xFFFF)) & 0xFFFFFFFF
            ja = ((lui[rs][1] << 16) + sx16(j & 0xFFFF)) & 0xFFFFFFFF
            if not put(ua, ja): return False, {}, f"word {i}: symbol conflict"
            unpaired.pop(rs, None)
            continue
        return False, {}, f"word {i}: immediate differs {u:08x} {j:08x}"
    if unpaired: return False, {}, f"word {min(unpaired.values())}: lui immediate differs with no lo use"
    # named symbols at an equal address: the C names them, JP splat does not
    for n, a in eq.items():
        if not re.match(r"(D_|func_)[0-9A-Fa-f]{8}$", n):
            syms[n] = a
    return True, syms, "ok"

def unit_of(us, addr):
    src = us[addr]["source"]
    fns = sorted(a for a, f in us.items() if f["source"] == src)
    return src, fns

def analyze(us, jp, pairs, names, jpsyms, addr):
    src, fns = unit_of(us, addr)
    if src[len("src/"):-2] in US_RODATA: return dict(ok=False, src=src, why="US unit has a .rodata subsegment (JP placement not derived)")
    sizes = [int(us[a]["size"], 16) for a in fns]
    for a, s, b in zip(fns, sizes, fns[1:]):
        if a + s != b: return dict(ok=False, src=src, why=f"US unit not contiguous at {a:#x}")
    jps = [pairs.get(a) for a in fns]
    # the pair list is incomplete: infer a missing JP address from a paired
    # neighbour by contiguity, and let the word comparison decide
    for k in range(len(fns)):
        if jps[k] is None:
            if k > 0 and jps[k - 1] is not None: jps[k] = jps[k - 1] + sizes[k - 1]
    for k in range(len(fns) - 1, -1, -1):
        if jps[k] is None and k + 1 < len(fns) and jps[k + 1] is not None: jps[k] = jps[k + 1] - sizes[k]
    if any(j is None for j in jps): return dict(ok=False, src=src, why="no function of the unit has a JP pair")
    for j, s, k in zip(jps, sizes, jps[1:]):
        if j + s != k: return dict(ok=False, src=src, why=f"JP unit not contiguous at {j:#x}")
    if any(j in jp for j in jps): return dict(ok=False, src=src, why="already in JP matching_c")
    uw = words(US_EXE, fns[0], sum(sizes)); jw = words(JP_EXE, jps[0], sum(sizes))
    ok, syms, why = pair_words(uw, jw, names, pairs, (fns[0], jps[0]))
    if not ok: return dict(ok=False, src=src, why=why)
    fnames = [usname(names, a, True) for a in fns]
    # aliases: US name -> the name the JP build must use (a wrapper's #define
    # lines, upstream's "regional alias"); lines: symbols.txt lines to add
    aliases, lines = {}, {}
    for n, a in syms.items():
        if n in fnames: continue                          # on the function line already
        if a in JPVRAM:                                   # JP already names that address
            if JPVRAM[a] != n: aliases[n] = JPVRAM[a]
            continue
        if n in jpsyms:
            if jpsyms[n] != a: return dict(ok=False, src=src, why=f"{n} already {jpsyms[n]:#x} in JP symbols, unit wants {a:#x}")
            continue
        m = re.match(r"(D|func)_([0-9A-Fa-f]{8})$", n)
        if m and n in JP_AUTO and int(m.group(2), 16) != a:
            jn = ("gJapanese_" if m.group(1) == "D" else "Japanese_") + n
            aliases[n] = jn; lines[jn] = a
        else:
            lines[n] = a
    # a second US name of the same address, used by this unit's source, needs
    # the same treatment: splat refuses a second name for one JP address, so
    # it can only be a #define onto whatever name the JP build does use
    addr_of = {n: a for a, n in names.items()}
    text = (KG / src).read_text(errors="replace") if (KG / src).exists() else ""
    for n, jn in list(aliases.items()) + [(n, n) for n in lines]:
        m = re.match(r"(?:D|func)_([0-9A-Fa-f]{8})$", n)
        ua = int(m.group(1), 16) if m else addr_of.get(n)
        if ua is None: continue
        for n2 in ALT_NAMES.get(ua, ()):
            if n2 != n and n2 not in aliases and n2 not in lines and re.search(r"\b%s\b" % re.escape(n2), text):
                # MEASURED, and it is why this is a rejection rather than a
                # second #define: fade_runtime reads 0x800E9EC8 as both
                # `gFade_State` and `u8 D_800E9EC8_arr[]`, and aliasing both
                # onto gJapanese_FadeState gives cc1 "conflicting types for
                # `gJapanese_FadeState'" at fade.h:12. One JP identifier
                # cannot carry two US declarations, so an including wrapper
                # cannot reach this unit at all -- only a copied one can.
                return dict(ok=False, src=src,
                            why=f"{n} and {n2} are two US names of {ua:#x} with different declarations; "
                                f"one JP identifier ({jn}) cannot carry both")
    return dict(ok=True, src=src, fns=fns, jps=jps, sizes=sizes, syms=syms, aliases=aliases, lines=lines,
                profile=us[fns[0]]["profile"], names=fnames)

def scan():
    us, jp, pairs, names, jpsyms = load_all()
    seen, rows = set(), []
    for a in sorted(pairs, key=lambda a: int(us[a]["size"], 16) if a in us else 0):
        if a not in us: continue
        src = us[a]["source"]
        if src in seen: continue
        seen.add(src)
        r = analyze(us, jp, pairs, names, jpsyms, a)
        rows.append((src, r))
        tag = "OK " if r["ok"] else "-- "
        extra = f"{len(r['fns'])} fn, {sum(r['sizes']):#x} B, syms {len(r['syms'])}" if r["ok"] else r["why"]
        print(f"{tag}{src:<52} {extra}")
    print(f"\n{sum(1 for _, r in rows if r['ok'])} units pair cleanly of {len(rows)} queued units")

def apply(addr):
    us, jp, pairs, names, jpsyms = load_all()
    r = analyze(us, jp, pairs, names, jpsyms, addr)
    if not r["ok"]: sys.exit(f"cannot apply {r['src']}: {r['why']}")
    unit = r["src"][len("src/"):-2]
    wrapper = None
    if r["aliases"]:
        # upstream's regional-alias wrapper (src/game/japanese/*.c): the US
        # names the JP build cannot use are #defined to JP names before the
        # headers are seen; the US source is included rather than copied
        base = unit[len("game/"):]
        wrapper = KG / "src/game/japanese" / (base + ".c")
        if wrapper.exists(): sys.exit(f"{wrapper} exists")
        # `make basic-types` wants types.h included first in every source file
        body = ['#include "../../types.h"', "",
                f"/* SLPM-86398 build of {r['src']}: the symbols below sit at other addresses in the",
                " * Japanese executable and their US names are taken there, so they are aliased",
                " * (config/slpm_86398/symbols.txt has the addresses). The US source is included",
                " * unchanged. */"]
        body += [f"#define {n} {jn}" for n, jn in sorted(r["aliases"].items())]
        body += ["", f'#include "../{base}.c"', ""]
        wrapper.write_text("\n".join(body))
        unit = "game/japanese/" + base
        r["src"] = "src/" + unit + ".c"
    start, end = r["jps"][0] - LOAD + HDR, r["jps"][0] + sum(r["sizes"]) - LOAD + HDR
    # split.yaml: the main segment's subsegment list
    sp = KG / "config/slpm_86398/split.yaml"; text = sp.read_text()
    lines = text.split("\n")
    idx = [i for i, l in enumerate(lines) if re.match(r"\s+- \[0x[0-9a-f]+, (c|asm|rodata|pad)", l) and i < lines.index("  - name: initialized_data")]
    ents = [(int(re.match(r"\s+- \[(0x[0-9a-f]+)", lines[i]).group(1), 16), i) for i in idx]
    offs = {o: i for o, i in ents}
    if start in offs and ", c," in lines[offs[start]]: sys.exit("start offset already a c segment")
    new = [f"      - [{start:#x}, c, {unit}]"]
    if end not in offs: new.append(f"      - [{end:#x}, asm, func_{end - HDR + LOAD:08X}]")
    keep = [l for i, l in enumerate(lines) if not (i in offs.values() and int(re.match(r"\s+- \[(0x[0-9a-f]+)", l).group(1), 16) == start and ", asm," in l)]
    # insert in order
    out, done = [], False
    for l in keep:
        m = re.match(r"\s+- \[(0x[0-9a-f]+), ", l)
        if not done and m and int(m.group(1), 16) > start and "- name: initialized_data" not in "".join(out[-3:]):
            out.extend(new); done = True
        out.append(l)
    assert done
    sp.write_text("\n".join(out))
    # matching_c.json
    # matching_c.json: the file is not globally sorted upstream (one entry sits
    # out of order), so never re-sort it -- insert before the first entry in
    # file order whose address is larger, else append. The diff is then only
    # the new entries.
    mc = KG / "config/slpm_86398/matching_c.json"; d = json.load(open(mc))
    new_ents = [{"address": f"0x{j:08X}", "profile": r["profile"], "size": f"0x{s:X}", "source": r["src"]}
                for j, s in zip(r["jps"], r["sizes"])]
    pos = next((i for i, f in enumerate(d["functions"]) if int(f["address"], 16) > r["jps"][0]), len(d["functions"]))
    d["functions"][pos:pos] = new_ents
    mc.write_text(json.dumps(d, indent=2) + "\n")
    # symbols.txt: upstream appends each PR's lines at the end, functions then
    # data symbols; the existing lines and the trailing newline are kept as is
    st = KG / "config/slpm_86398/symbols.txt"; old = st.read_text()
    # a function an earlier promotion reached by `jal` already has its line
    # (splat rejects a second one: "Duplicate symbol detected", first seen on
    # Text_EncodeDecimalDigits after #5649); a different address is a conflict
    for n, j in zip(r["names"], r["jps"]):
        if n in jpsyms and jpsyms[n] != j: sys.exit(f"{n} already {jpsyms[n]:#x} in JP symbols, unit wants {j:#x}")
    add = [f"{n} = 0x{j:08X};" for n, j in zip(r["names"], r["jps"]) if n not in jpsyms]
    # a unit's own function reached by `jal` at an equal address is in syms
    # too (named, equal-address): it is already on the function line above,
    # and splat rejects the duplicate ("Duplicate symbol detected")
    add += [f"{n} = 0x{a:08X};" for n, a in sorted(r["lines"].items(), key=lambda kv: kv[1])]
    body = old if old.endswith("\n") else old + "\n"
    st.write_text(body + "\n".join(add) + ("\n" if old.endswith("\n") else ""))
    print(f"applied {unit}: {len(r['fns'])} fn at {r['jps'][0]:#x}..{r['jps'][0] + sum(r['sizes']):#x}, "
          f"{len(r['lines'])} symbol lines, {len(r['aliases'])} aliases {r['aliases']}"
          + (f", wrapper {wrapper.relative_to(KG)}" if wrapper else ""))

if __name__ == "__main__":
    if sys.argv[1] == "scan": scan()
    else: apply(int(sys.argv[2], 16))
