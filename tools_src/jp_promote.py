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
# One entry per region, because nothing in the pairing is Japanese: it accepts
# a unit whose target words are the US words modulo relocation, which is true
# of ANY release built from the same code. krystalgamer's stated next
# objective is every iteration (European, French, German, Italian, Spanish and
# Japanese), and his reading is that the European ones differ from the US only
# in resources -- if that holds, this pairs nearly all of them where it pairs
# about a fifth of the Japanese queue. `jp` is the one measured so far; add a
# region by dropping its config directory and executable in here.
REGIONS = {
    "jp": dict(config="slpm_86398", exe="game/japanese/SLPM_863.98",
               srcdir="japanese", make="japanese", pairs="jp_matches.csv"),
}
REGION = os.environ.get("YGOFM_REGION", "jp")
if REGION not in REGIONS: sys.exit(f"unknown region {REGION!r}; known: {', '.join(sorted(REGIONS))}")
R = REGIONS[REGION]
BASE_CFG = KG / "config" / "slus_01411"          # the US side, always the source of the C
TGT_CFG = KG / "config" / R["config"]
SPLAT = KG / "tmp/splat" / R["config"]
PAIRS = ROOT / "config" / R["pairs"]   # address = target, address2 = US; the pair list the scan starts from
US_LINK_SYMS = ROOT / "config" / "us_link_symbols.csv"   # names the US link gives C-defined data
US_EXE, JP_EXE = KG / "game/SLUS_014.11", KG / R["exe"]
LOAD, HDR = 0x80010000, 0x800
# BOTH gp values are read from their own split.yaml. GP_JP used to be the
# literal 0x8009AE48, which is right for SLPM-86398 and would have silently
# paired a European target against the Japanese gp.
GP_US, GP_JP = None, None

# Units that reach ONE object under TWO US names whose declarations differ. A
# `#define` cannot carry both: they become one identifier with two
# declarations, which is `conflicting types for 'gJapanese_FadeState'` at
# fade.h:12. The copied wrapper his tree uses elsewhere would work and would
# duplicate the whole unit. MEASURED 2026-09-21, and it is neither: an `asm`
# label binds the second name to the same Japanese symbol, a clean
# `japanese-match` matches, and 31 functions come in with no copy. The
# declaration is hand-written per unit because its type comes from the US
# header, and an array is left UNSIZED so that header completes it.
# unit -> [(extra US name, the US address it shares, declaration template)]
ASM_ALIASES = {
    "game/fade_runtime": [("D_800E9EC8_arr", 0x800E9EC8,
                           'extern u8 D_800E9EC8_arr[] asm("%s");')],
    # duel_card_effects.c defines DUEL_FIELD_GRID_ALIASES on its line 2, which
    # takes the branch of src/game/duel_grid.h -- ANOTHER unit's header, so the
    # scan of this unit's own header below never sees it -- declaring TWO views
    # of one object, both bound by an asm label:
    #     extern u8 D_800907D8_2d[..][..] asm("D_800907D8");
    #     extern u8 D_800907D8_flat[]     asm("D_800907D8");
    #     #define D_800907D8 D_800907D8_flat
    # The wrapper's `#define D_800907D8 gJapanese_D_800907D8` cannot reach
    # either, because a macro does not expand inside a string literal, so every
    # reference bound to the US name and seven words came out with the US
    # address (0x800907D8 against the Japanese 0x80090688, a uniform 0x150).
    # The inner bound is DUEL_FIELD_SIDE_GRID_SLOT_COUNT, which that header
    # defines at its line 9; it is written out here because the wrapper is
    # included before the header that defines it, and the outer bound is left
    # for the header to complete.
    "game/duel_card_effects": [("D_800907D8_2d", 0x800907D8,
                                'extern u8 D_800907D8_2d[][20] asm("%s");'),
                               ("D_800907D8_flat", 0x800907D8,
                                'extern u8 D_800907D8_flat[] asm("%s");')],
}

# Carving a block can leave the blob piece BEFORE it short, and the bytes are
# lost silently. splat drops the TRAILING ZEROS of a row that now has a fixed
# end: `initialized_data_8b66a` spans 0x8b66a..0x8b670 and its object comes out
# FOUR bytes, so everything after it shifts down by two. Measured on
# duel_card_effects as three `addiu $v0,$gp` off by exactly 2, each pointing two
# bytes below that unit's own block.
# Naming the byte in symbols.txt does NOT fix it -- splat accepts the symbol
# (it is not in the "unable to determine a segment" list) and still drops the
# bytes. A `pad` row does, and it is how the US split spells the same gap
# (`[0x8b70d, pad]`); the Japanese split already carries `pad` rows, while a
# `size:` attribute -- the other route, used 1137 times in the US symbols --
# appears there zero times, so the row is the smaller imposition.
# Hand-written per unit, like ASM_ALIASES above, because only a splat run says
# where the emission stops. These two bytes are the zero tail of
# debug_effect_screen's unpromoted block, not real padding.
# unit -> [file offset of a `pad` row to add inside initialized_data]
CARVE_PADS = {
    "game/duel_card_effects": [0x8b66e],
}

def sx16(v): return v - 0x10000 if v & 0x8000 else v

def words(exe, addr, size):
    b = exe.read_bytes()[addr - LOAD + HDR: addr - LOAD + HDR + size]
    return list(struct.unpack("<%dI" % (len(b) // 4), b))

def raw(exe, addr, size):
    # a .sdata block is data, not instructions: its size is not a multiple of
    # four (gDuel_abTrapAttackThresholds is 5 bytes and the scalar after it 1,
    # game/main_frame's whole block is 1), so it is compared byte-wise
    return exe.read_bytes()[addr - LOAD + HDR: addr - LOAD + HDR + size]

def load_all():
    global GP_US, GP_JP
    us = {int(f["address"], 16): f for f in json.load(open(BASE_CFG / "matching_c.json"))["functions"]}
    jp = {int(f["address"], 16): f for f in json.load(open(TGT_CFG / "matching_c.json"))["functions"]}
    pairs = {}
    for r in csv.DictReader(open(PAIRS)):
        pairs[int(r["address2"], 16)] = int(r["address"], 16)     # US -> target
    names = {}
    for line in open(BASE_CFG / "symbols.txt"):
        m = re.match(r"\s*(\w+)\s*=\s*(0x[0-9A-Fa-f]+)", line)
        if m: names[int(m.group(2), 16)] = m.group(1)
    # the C sources define functions by the name in functions.csv, which
    # symbols.txt does not always carry (first apply: three undefined
    # `func_` names because the file names them differently)
    for r in csv.DictReader(open(BASE_CFG / "functions.csv")):
        names[int(r["address"], 16)] = r["name"]
    jpsyms = {}
    for line in open(TGT_CFG / "symbols.txt"):
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
    for line in open(BASE_CFG / "c_symbols.ld"):
        m = re.match(r"\s*(\w+)\s*=\s*(0x[0-9A-Fa-f]+)\s*;", line)
        if m: ALT_NAMES[int(m.group(2), 16)].add(m.group(1))
    # DATA DEFINED IN C carries a name that no config file holds: the address comes
    # out of the US link and nothing else. `gDebugMenu_abMainModeByEntry` is one --
    # the promoter recorded 0x80090D68 -> 0x80090C18 and wrote it as `D_80090D68`,
    # while debug_menu_leave_entries calls it by its real name and the JP link had
    # nothing to bind. config/us_link_symbols.csv is that map, read off
    # tmp/project-build/SLUS_014.11.map after `make match`; it is committed because
    # `make clean` inside a batch deletes the map.
    for r in csv.DictReader(open(US_LINK_SYMS)) if US_LINK_SYMS.exists() else ():
        ALT_NAMES[int(r["address"], 16)].add(r["name"])
    # A FIFTH source, and the only one that maps a name to another NAME instead
    # of to an address: `config/slus_01411/link_symbols.ld`, which the US link
    # takes and the JP link does not (there is no slpm_86398 copy, and the
    # build hard-codes the US path). Its own comment says what it is for --
    # "Address-based call target retained by unmatched DuelScene_UpdateBattle"
    # -- and duel_scene_battle is exactly the unit whose JP link reported
    # `undefined reference to func_8001F0D0`: the source calls the address
    # name while duel_trap_resolution.c defines Duel_SelectAttackTrap, and
    # `func_8001F0D0 = Duel_SelectAttackTrap;` is what joins them.
    # Only the plain `A = B;` form is a second name: `A = 0x...;` is a layout
    # address and `A = B + N;` is an interior symbol.
    byname = {}
    for a, n in names.items(): byname.setdefault(n, a)
    lnk = BASE_CFG / "link_symbols.ld"
    for line in (open(lnk) if lnk.exists() else ()):
        m = re.match(r"\s*(\w+)\s*=\s*(\w+)\s*;", line)
        if m and not m.group(2).startswith("0x") and m.group(2) in byname:
            ALT_NAMES[byname[m.group(2)]].add(m.group(1))
    global US_RODATA
    us_split = (BASE_CFG / "split.yaml").read_text()
    m = re.search(r"gp_value:\s*(0x[0-9a-fA-F]+)", us_split)
    GP_US = int(m.group(1), 16)
    m = re.search(r"gp_value:\s*(0x[0-9a-fA-F]+)", (TGT_CFG / "split.yaml").read_text())
    if not m: sys.exit(f"no gp_value in {TGT_CFG.name}/split.yaml")
    GP_JP = int(m.group(1), 16)
    # A unit with its own .rodata subsegment (a switch table) needs the JP
    # table placed too, and the word comparison covers .text only. The block's
    # SIZE comes from the next rodata row, so keep every row sorted by offset:
    # name -> (file offset, size).
    rows = sorted((int(m.group(1), 16), m.group(2))
                  for m in re.finditer(r"- \[(0x[0-9a-fA-F]+), \.?rodata, (\S+)\]", us_split))
    US_RODATA = {n: (o, rows[i + 1][0] - o) for i, (o, n) in enumerate(rows) if i + 1 < len(rows)}
    global US_SDATA
    # A unit whose source DEFINES data has its own `.sdata` row in the US
    # split; the JP split carries the whole region as ONE blob, so without a
    # carve the symbol is defined twice and the link says so -- measured on
    # duel_trap_resolution: "multiple definition of `gDuel_abTrapAttackThresholds';
    # initialized_data.data.o ... first defined here src/game/japanese/duel_trap_resolution.o:(.sdata+0x0)".
    # The size comes from the NEXT row whatever its type, because a block can be
    # bounded by a `pad` rather than by another unit (game/main_frame is, at
    # 0x8b70c). Matching `\.?s?data` instead would also match the "data" inside
    # ".rodata" -- that spelling reported 8 phantom sdata carves in the JP split,
    # which has none.
    # A `pad` row after a .sdata row is the block's alignment tail, and it is a
    # row of its OWN because the object does not supply those bytes:
    # game/main_frame is `[0x8b70c, .sdata]`, `[0x8b70d, pad]`, `[0x8b710, ...]`,
    # and its object's .sdata is one byte at alignment 1 (against six at
    # alignment 4 for duel_trap_resolution). Both ways of ignoring that row cost
    # the same four bytes -- "rebuilt executable is 0x1d07fc bytes, expected
    # 0x1d0800": carving only the byte resumes the blob at 1 mod 4 and the
    # linker realigns it, and carving the padding too promises three bytes no
    # object provides. So the US shape is mirrored exactly, `pad` row included:
    # (start, size the object supplies, where the blob resumes).
    allrows = sorted((int(m.group(1), 16), m.group(2))
                     for m in re.finditer(r"- \[(0x[0-9a-fA-F]+), ([.\w]+)", us_split))
    US_SDATA = {}
    for m in re.finditer(r"- \[(0x[0-9a-fA-F]+), \.sdata, (\S+)\]", us_split):
        o = int(m.group(1), 16)
        nxt = [x for x, t in allrows if x > o]
        real = [x for x, t in allrows if x > o and t != "pad"]
        if nxt and real: US_SDATA[m.group(2)] = (o, nxt[0] - o, real[0])
    global JPVRAM, JP_AUTO
    JPVRAM = {a: n for n, a in jpsyms.items()}       # JP address -> the name JP already gives it
    # default names JP splat generated for ITS OWN addresses (from the last
    # japanese-split): a US `D_8009B314` mapped to another JP address collides
    # with them, and the linker then takes splat's definition (measured:
    # sorted_entry_relink, built lo 0xB314 where JP has 0xB204)
    JP_AUTO = set()
    for p in list((SPLAT / "asm").rglob("*.s")) + [SPLAT / "undefined_syms_auto.txt",
                                                   SPLAT / "undefined_funcs_auto.txt",
                                                   SPLAT / (R["config"] + ".ld")]:
        if p.exists():
            JP_AUTO.update(re.findall(r"\b(?:D|func)_[0-9A-Fa-f]{8}\b", p.read_text(errors="replace")))
    if not JP_AUTO: sys.exit(f"no {SPLAT.relative_to(KG)} output: run `make {R['make']}-split` in his tree first")
    JP_AUTO -= set(jpsyms)      # a D_ name symbols.txt gave a JP address is a user name, not a collision
    return us, jp, pairs, names, jpsyms

def _ua_of(names, n, jp_addr):
    """The US address `n` names: from the name map, or from the name itself."""
    for a, x in names.items():
        if x == n: return a
    m = re.match(r"(?:D|func)_([0-9A-Fa-f]{8})$", n)
    return int(m.group(1), 16) if m else None


def usname(names, addr, func=False):
    return names.get(addr) or (("func_%08X" if func else "D_%08X") % addr)

LOADSTORE = {0x08, 0x09, 0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x28, 0x29, 0x2A, 0x2B, 0x2E, 0x31, 0x39}

def pair_words(uw, jw, names, func_map, uw_base=(0, 0)):
    """Return (ok, symbol map {USname: JPaddr}, reason)."""
    if len(uw) != len(jw): return False, {}, "size differs"
    lui = {}       # rt -> (us_hi, jp_hi)
    last_lui = {}  # rt -> the last lui pair on rt, kept after the register is overwritten
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
    # The lui state that REACHES a label. A linear scan carries the fall-through
    # state into every word, which is wrong at a label nothing falls into: there
    # the live state is whatever the branches carry, taken AFTER each branch's
    # delay slot because MIPS executes it on the taken path too. Measured on
    # script_op_load_image_scene: `bne` at 0x8002E530 with `lui $v0,0x800f` in
    # its delay slot, the fall-through then does `lui $v0,0x0200` for a constant,
    # and 0x8002E584 (after a `j` + delay slot, so reachable only by that bne)
    # reads `lbu 0x9ece($v0)`. Linearly that is 0x0200_0000 - 0x6132 =
    # 0x01FF9ECE, an address outside the image that nonetheless tracked the
    # region's 0x120 displacement; through the branch it is 0x800E9ECE,
    # gFade_State + 6 -- the very neighbour the base derivation was missing.
    branch_tgt = {}   # word index of a branch/jump -> its target word index
    at_target = {}    # target word index -> {rt: (us_hi, jp_hi)} carried into it
    def _uncond(w):
        o = w >> 26
        return (o == 0x02 or (o == 0 and (w & 0x3F) == 0x08)
                or (o == 0x04 and ((w >> 21) & 31) == 0 and ((w >> 16) & 31) == 0))
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
        # record what a branch two words back carries into its target (its delay
        # slot, word i-1, has been applied and its own write dropped by now)
        if (i - 2) in branch_tgt:
            t = branch_tgt.pop(i - 2)
            snap = dict(lui)
            at_target[t] = snap if t not in at_target else {r: v for r, v in at_target[t].items() if snap.get(r) == v}
        # at a label nothing falls into, the branches' state IS the live state;
        # several forward branches keep only the registers they agree on
        if i >= 2 and _uncond(uw[i - 2]) and i in at_target:
            lui = dict(at_target[i])
        if op in (0x01, 0x04, 0x05, 0x06, 0x07) or (0x14 <= op <= 0x17):
            t = i + 1 + sx16(u & 0xFFFF)
            if i < t < len(uw): branch_tgt[i] = t
        elif op == 0x02 and uw_base[0]:
            t = ((0x80000000 | ((u & 0x3FFFFFF) << 2)) - uw_base[0]) // 4
            if i < t < len(uw): branch_tgt[i] = t
        if op == 0: dst = (u >> 11) & 31
        elif op == 0x03: dst = 31
        elif op in (0x01, 0x02, 0x04, 0x05, 0x06, 0x07) or op in (0x28, 0x29, 0x2A, 0x2B, 0x2E) or op >= 0x38: dst = None
        else: dst = rt
        pending = dst if (dst and op != 0x0F) else None
        if op == 0x0F and (j >> 26) == 0x0F and ((u ^ j) & 0xFFFF0000) == 0:
            lui[rt] = (u & 0xFFFF, j & 0xFFFF)
            last_lui[rt] = lui[rt]
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
        # A %lo at a BRANCH TARGET whose %hi was loaded on another path: the linear
        # scan saw the register overwritten in between and forgot it (measured on
        # script_op_fade_out: `lui $v0,0x800f` ... `andi $v0,...` ... label:
        # `lbu 0x9ece($v0)`). Only the differing-word path uses it, only with equal
        # %hi halves on both sides, and put() still rejects a conflicting symbol.
        if op in LOADSTORE and rs in last_lui and rs not in lui and last_lui[rs][0] == last_lui[rs][1]:
            ua = ((last_lui[rs][0] << 16) + sx16(u & 0xFFFF)) & 0xFFFFFFFF
            ja = ((last_lui[rs][1] << 16) + sx16(j & 0xFFFF)) & 0xFFFFFFFF
            if not put(ua, ja): return False, {}, f"word {i}: symbol conflict"
            continue
        return False, {}, f"word {i}: immediate differs {u:08x} {j:08x}"
    if unpaired: return False, {}, f"word {min(unpaired.values())}: lui immediate differs with no lo use"
    # named symbols at an equal address: the C names them, JP splat does not
    for n, a in eq.items():
        # A D_/func_ name is skipped only when JP splat really generates it. The US
        # link also takes `config/slus_01411/c_symbols.ld`, which the JP link does
        # not, so a name defined only there is undefined on the JP side however
        # ordinary it looks: `undefined reference to D_8009B23A` deferred five units
        # before this was measured (2026-09-22).
        if not re.match(r"(D_|func_)[0-9A-Fa-f]{8}$", n) or n not in JP_AUTO:
            syms[n] = a
    return True, syms, "ok"

def unit_of(us, addr):
    src = us[addr]["source"]
    fns = sorted(a for a, f in us.items() if f["source"] == src)
    return src, fns

def analyze(us, jp, pairs, names, jpsyms, addr):
    src, fns = unit_of(us, addr)
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
    # A derived symbol whose US address is outside the image cannot be a symbol:
    # it is a mispaired %hi/%lo, and a unit that passed carrying one would put a
    # nonsense line in upstream's symbols.txt. script_op_load_image_scene yields
    # `D_01FF9ECE -> 0x01FF9DAE`, which LOOKS right because it tracks the data
    # displacement (0x120) exactly, like every real pair in that unit. Refusing is
    # better than dropping it silently: the unit is not promotable until the
    # pairing is understood. The scratchpad and hardware registers at 0x1F80xxxx
    # are addresses the code legitimately names (WORKFLOW's 0x1F8002A0).
    def _plausible(a):
        return a is not None and (0x80000000 <= a < 0x80200000 or 0x1F800000 <= a < 0x1F802000)
    bad = sorted(n for n, a in syms.items() if not _plausible(_ua_of(names, n, a)))
    if bad:
        return dict(ok=False, src=src, why=f"derived symbol outside the image, mispaired %hi/%lo: {bad[:3]}")
    fnames = [usname(names, a, True) for a in fns]
    # aliases: US name -> the name the JP build must use (a wrapper's #define
    # lines, upstream's "regional alias"); lines: symbols.txt lines to add
    aliases, lines = {}, {}
    # the unit's own source text, with comments stripped: a provenance header or a
    # goto label reads as a reference and is not one
    _text = (KG / src).read_text(errors="replace") if (KG / src).exists() else ""
    _code = re.sub(r"//[^\n]*", " ", re.sub(r"/\*.*?\*/", " ", _text, flags=re.S))
    for n, a in syms.items():
        if n in fnames: continue                          # on the function line already
        if a in JPVRAM:                                   # JP already names that address
            if JPVRAM[a] != n:
                aliases[n] = JPVRAM[a]
            else:
                # SAME name, already there -- and still an undefined reference when the
                # SOURCE calls the object by its other US name. `config/slus_01411/c_symbols.ld`
                # gives 0x8009B23A the second name `D_8009B23A`, the US link takes that file
                # and the JP link does not, so `flags = D_8009B23A;` has nothing to bind to
                # while `gDuel_wSceneStateFlags` sits in the JP symbols already. Alias the
                # name the source uses onto the one the JP build has. Measured 2026-09-22 on
                # func_80018FEC, deferred until then as "nothing on the JP side names it".
                # Only when the source uses ONE other name INSTEAD of this one: with both
                # names in the source the two declarations still cannot share one JP
                # identifier, which is the rejection below (measured: aliasing both cost
                # func_80059AF8, whose source reads 0x80058938 as func_80058938 and as
                # Model_QueueTintRequest).
                if not re.search(r"\b%s\b" % re.escape(n), _code):
                    alt = [n2 for n2 in sorted(ALT_NAMES.get(_ua_of(names, n, a), ()))
                           if n2 != n and re.search(r"\b%s\b" % re.escape(n2), _code)]
                    if len(alt) == 1 and alt[0] not in aliases: aliases[alt[0]] = JPVRAM[a]
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
    # Count the alternates the unit uses IN CODE. Comments have to go first:
    # a provenance header naming a sibling, or a `goto func_80073900;` label,
    # reads as a reference and is not one (measured on six such names, five of
    # them false).
    code = re.sub(r"//[^\n]*", " ", re.sub(r"/\*.*?\*/", " ", text, flags=re.S))
    rename = {}
    for n, jn in list(aliases.items()) + [(n, n) for n in lines]:
        m = re.match(r"(?:D|func)_([0-9A-Fa-f]{8})$", n)
        ua = int(m.group(1), 16) if m else addr_of.get(n)
        if ua is None: continue
        handled = {x for x, _, _ in ASM_ALIASES.get(src[len("src/"):-2], ())}
        used = sorted(n2 for n2 in ALT_NAMES.get(ua, ())
                      if n2 not in handled and re.search(r"\b%s\b" % re.escape(n2), code))
        if len(used) == 1 and used[0] != n and used[0] not in aliases and used[0] not in lines:
            # ONE name in the code, and it is not the one usname() picked:
            # symbols.txt does not name this address, so the tool synthesised
            # `D_<addr>` while the unit calls it by its real name. Emit the
            # line under the name the source uses -- there is no conflict.
            # card_list_sort is the case: `gBuildDeck_pState` twice in code,
            # `D_8009B2FC` nowhere in the file, not even in a comment, because
            # it exists only as an alias in config/slus_01411/c_symbols.ld.
            rename[n] = used[0]
            continue
        for n2 in used:
            if n2 != n and n2 not in aliases and n2 not in lines:
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
    # A US HEADER CAN BIND A NAME TO A LABEL: func_8004E9A0.h declares
    # `extern RECT gModel_ImageCopyRect asm("D_8009B468");`, so the object emits
    # D_8009B468 and a line written under the C name binds nothing. Read the labels
    # out of the unit's own header and write each line under the label instead.
    hdr = (KG / src).with_suffix(".h")
    if hdr.exists():
        pat = r'\bextern\b[^;{}]*?\b(\w+)\s*(?:\[[^\]]*\])?\s*asm\s*\(\s*"(\w+)"\s*\)'
        for m0 in re.finditer(pat, hdr.read_text(errors="replace")):
            decl, label = m0.group(1), m0.group(2)
            if decl != label and decl in lines and label not in lines: rename.setdefault(decl, label)
    for old, newn in rename.items():
        if old in lines: lines[newn] = lines.pop(old)
        if old in aliases: aliases[newn] = aliases.pop(old)
    # A BASE SYMBOL THE CODE NAMES AND NO INSTRUCTION CARRIES. `D_8009B20C[1]` on a
    # u16 array is an access at 0x8009B20E, so the words yield `D_8009B20E` and the
    # source's own `D_8009B20C` is never written -- undefined at the JP link, which is
    # what deferred duel_field_effect_steps (measured 2026-09-22). splat's interior
    # symbol, from the other side.
    # The base's JP address is derived from the symbols this unit DID record, and only
    # when at least two of them within 0x100 agree on one displacement; a single
    # neighbour is not evidence, and a disagreement means the region is not uniform.
    # The neighbours come from every pair the words yielded, not just the ones
    # that reached `lines`: game_over records D_800E9ECE and D_800E9ECF in syms
    # and NEITHER reaches lines, so a lines-only seed leaves the set empty and
    # the derivation cannot fire at all. Function pairs are excluded -- a jal
    # target's displacement is the text one and would poison a data neighbourhood.
    known = []
    for n0, ja in syms.items():
        if n0.startswith("func_"): continue
        ua = _ua_of(names, n0, ja)
        if ua is None or ua in us: continue
        known.append((ua, ja))
    # A NAMED base is the same case and the D_ pattern cannot see it. game_over
    # reads gFade_State (US 0x800E9EC8) only at +6 and +7, so the words yield
    # D_800E9ECE and D_800E9ECF and the name the source actually writes is never
    # recorded: `undefined reference to gFade_State`, six times, and no wrapper
    # at all because the unit derived no aliases.
    cands = [(m0.group(0), int(m0.group(1), 16))
             for m0 in re.finditer(r"\bD_([0-9A-Fa-f]{8})\b", code)]
    _byname = {}
    for _a, _n in names.items(): _byname.setdefault(_n, _a)
    for m0 in re.finditer(r"\b[A-Za-z_]\w+\b", code):
        n0 = m0.group(0)
        if n0 in _byname and not n0.startswith("func_") and _byname[n0] not in us:
            cands.append((n0, _byname[n0]))
    for n0, ua0 in cands:
        # The name being TAKEN on the Japanese side blocks a symbols.txt line and
        # is exactly when an alias is wanted, so the skip cannot come first:
        # func_800388D8 reads `*(u8 *)&D_8009AF74[1]`, the words carry only the
        # interior D_8009AF76 (JP 0x8009AEBE), the base derives to 0x8009AEBC --
        # and splat already calls that gJapanese_D_8009AF74 while generating
        # `D_8009AF74` for its OWN 0x8009AF74. Skipping there left the unit one
        # word out (lbu imm 0xaf76 against 0xaebe).
        if n0 in lines or n0 in aliases: continue
        # One neighbour is evidence only when it is a few bytes away, i.e. the same
        # object: `D_8009B20C` against the recorded `D_8009B20E`. Further out the
        # displacement is not uniform -- those two move by 0x110 where gp moves by
        # 0xC0 -- so a wider window needs two neighbours that agree.
        close = [(ua, ja) for ua, ja in known if abs(ua - ua0) <= 0x10]
        wide = [(ua, ja) for ua, ja in known if abs(ua - ua0) < 0x100]
        for group, need in ((close, 1), (wide, 2)):
            ds = {ja - ua for ua, ja in group}
            if len(ds) == 1 and len({ua for ua, _ in group}) >= need:
                d = ds.pop()
                j0 = ua0 + d
                # when the derived address is ALREADY named on the Japanese side
                # the base needs an alias, not a symbols line: splat refuses a
                # second name for one address (gFade_State against the
                # gJapanese_FadeState that fade_runtime's promotion put at
                # 0x800E9DA8)
                if j0 in JPVRAM:
                    if JPVRAM[j0] != n0: aliases[n0] = JPVRAM[j0]
                # a line only when the name is free on the Japanese side: it is
                # taken when symbols.txt carries it, or when splat generated the
                # same D_ name for its own address
                elif n0 not in jpsyms and n0 not in JP_AUTO:
                    lines[n0] = j0
                break
    # the asm-label declarations for this unit's second names
    asm_lines = []
    for extra, uaddr, tmpl in ASM_ALIASES.get(src[len("src/"):-2], ()):
        jn = aliases.get(usname(names, uaddr))
        if jn is None:
            return dict(ok=False, src=src, why=f"{extra} needs the JP name of {uaddr:#x}, which this unit does not alias")
        asm_lines.append(tmpl % jn)
    # A unit with its own .rodata block: derive where the JP copy sits and
    # refuse unless the bytes SELF-CHECK. The block is a switch table of .text
    # addresses, so the JP words must be the US words shifted by this unit's
    # own text displacement, uniformly -- measured on both candidates
    # (display_object_helpers 0x920, mem_card_driver 0x914). Taking the JP
    # start from any nearby derived symbol instead of the one whose US address
    # IS the block's read ASCII as a broken table, sixteen bytes off.
    rodata = None
    unit_name = src[len("src/"):-2]
    if unit_name in US_RODATA:
        off, size = US_RODATA[unit_name]
        usvram = off - HDR + LOAD
        want = "D_%08X" % usvram
        jpvram = syms.get(want)
        if jpvram is None:
            return dict(ok=False, src=src, why=f".rodata block at {usvram:#x} has no derived JP address ({want} never paired)")
        tdelta = fns[0] - jps[0]
        uw2, jw2 = words(US_EXE, usvram, size), words(JP_EXE, jpvram, size)
        deltas = {(a - b) & 0xFFFFFFFF for a, b in zip(uw2, jw2)}
        if deltas != {tdelta}:
            return dict(ok=False, src=src, why=f".rodata at {usvram:#x} is not the US block shifted by the unit's {tdelta:#x} "
                                               f"(deltas {sorted(hex(d) for d in deltas)[:3]})")
        rodata = (jpvram - LOAD + HDR, size)
    # A unit whose source DEFINES data needs its block carved out of the JP
    # blob: otherwise splat's blob and the promoted object both define the
    # symbol and the link refuses it. The block's JP address comes from the
    # symbol whose US address IS the block's start -- the same rule the
    # .rodata carve above uses -- and the bytes must then be EQUAL rather than
    # shifted: this is data, and it sits in the gp region, so the unit's text
    # displacement does not apply to it.
    sdata = None
    carve_pads = []
    if unit_name in US_SDATA:
        off, size, resume = US_SDATA[unit_name]
        usvram = off - HDR + LOAD
        cand = sorted((n, j) for n, j in syms.items() if _ua_of(names, n, j) == usvram)
        if len(cand) != 1:
            return dict(ok=False, src=src, why=f".sdata block at {usvram:#x} has {len(cand)} derived JP "
                                               f"addresses, needs exactly one ({cand})")
        jpvram = cand[0][1]
        ub, jb = raw(US_EXE, usvram, size), raw(JP_EXE, jpvram, size)
        if ub != jb:
            return dict(ok=False, src=src, why=f".sdata at {usvram:#x} is not the JP block at {jpvram:#x} "
                                               f"({ub.hex()} against {jb.hex()})")
        # every symbol the carved range covers is defined by the promoted C, so
        # its symbols.txt line has to go: splat would name it inside a range it
        # no longer emits
        inside = {n for n, j in syms.items() if jpvram <= j < jpvram + size}
        for n in inside: lines.pop(n, None)
        # the blob resumes where the US split resumes, which is past the `pad`
        # row when there is one -- the padding gets a row of its own
        sdata = (jpvram - LOAD + HDR, size, jpvram - LOAD + HDR + (resume - off))
        carve_pads = CARVE_PADS.get(unit_name, [])
    return dict(ok=True, src=src, fns=fns, jps=jps, sizes=sizes, syms=syms, aliases=aliases, lines=lines,
                rodata=rodata, sdata=sdata, carve_pads=carve_pads, asm_aliases=asm_lines, profile=us[fns[0]]["profile"], names=fnames)

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
        wrapper = KG / "src/game" / R["srcdir"] / (base + ".c")
        if wrapper.exists(): sys.exit(f"{wrapper} exists")
        # `make basic-types` wants types.h included first in every source file
        body = ['#include "../../types.h"', "",
                f"/* SLPM-86398 build of {r['src']}: the symbols below sit at other addresses in the",
                " * Japanese executable and their US names are taken there, so they are aliased",
                f" * (config/{R['config']}/symbols.txt has the addresses). The US source is included",
                " * unchanged. */"]
        body += [f"#define {n} {jn}" for n, jn in sorted(r["aliases"].items())]
        if r.get("asm_aliases"):
            body += ["",
                     " /* The same object under a second US name, which a #define cannot carry:".replace(" /*", "/*"),
                     " * both names would become one identifier with two declarations. An asm",
                     " * label binds it to the same Japanese symbol instead; an array is left",
                     " * unsized so the US header completes the type. */"]
            body += r["asm_aliases"]
        body += ["", f'#include "../{base}.c"', ""]
        wrapper.write_text("\n".join(body))
        unit = "game/" + R["srcdir"] + "/" + base
        r["src"] = "src/" + unit + ".c"
    start, end = r["jps"][0] - LOAD + HDR, r["jps"][0] + sum(r["sizes"]) - LOAD + HDR
    # split.yaml: the main segment's subsegment list
    sp = TGT_CFG / "split.yaml"; text = sp.read_text()
    lines = text.split("\n")
    idx = [i for i, l in enumerate(lines) if re.match(r"\s+- \[0x[0-9a-f]+, (c|asm|rodata|pad)", l) and i < lines.index("  - name: initialized_data")]
    ents = [(int(re.match(r"\s+- \[(0x[0-9a-f]+)", lines[i]).group(1), 16), i) for i in idx]
    offs = {o: i for o, i in ents}
    if start in offs and ", c," in lines[offs[start]]: sys.exit("start offset already a c segment")
    pending = [(start, f"      - [{start:#x}, c, {unit}]")]
    if end not in offs: pending.append((end, f"      - [{end:#x}, asm, func_{end - HDR + LOAD:08X}]"))
    if r.get("rodata"):
        # The unit's switch table. The JP split covers the whole initial-data
        # region with ONE `[0x800, rodata, initial_data]` line where the US
        # split carves it unit by unit, so the table is carved out and the
        # blob resumed after it. These offsets are LOWER than the text ones,
        # which is why each line below goes to its own sorted position
        # instead of the block going in at one point.
        roff, rsize = r["rodata"]
        pending.append((roff, f"      - [{roff:#x}, .rodata, {unit}]"))
        if roff + rsize not in offs:
            pending.append((roff + rsize, f"      - [{roff + rsize:#x}, rodata, initial_data_{roff + rsize:x}]"))
    keep = [l for i, l in enumerate(lines) if not (i in offs.values() and int(re.match(r"\s+- \[(0x[0-9a-f]+)", l).group(1), 16) == start and ", asm," in l)]
    # insert each line in offset order
    out, pend = [], sorted(pending)
    for l in keep:
        m = re.match(r"\s+- \[(0x[0-9a-f]+), ", l)
        if m and "- name: initialized_data" not in "".join(out[-3:]):
            o = int(m.group(1), 16)
            while pend and pend[0][0] < o:
                out.append(pend.pop(0)[1])
        out.append(l)
    assert not pend, f"nowhere to place {pend}"
    sp.write_text("\n".join(out))
    if r.get("sdata"):
        # the carve goes in the initialized_data segment, which the pass above
        # deliberately does not touch
        soff, ssize, sresume = r["sdata"]; end = soff + ssize
        l2 = sp.read_text().split("\n")
        i0 = l2.index("  - name: initialized_data")
        j = i0
        while j < len(l2) and not re.match(r"\s+- \[0x[0-9a-f]+, ", l2[j]): j += 1
        k = j
        while k < len(l2) and re.match(r"\s+- \[0x[0-9a-f]+, ", l2[k]): k += 1
        have = {int(re.match(r"\s+- \[(0x[0-9a-f]+), ", l).group(1), 16): l for l in l2[j:k]}
        assert soff not in have, f"{soff:#x} already a subsegment of initialized_data"
        have[soff] = f"      - [{soff:#x}, .sdata, {unit}]"
        # ONE resumption row, and it must be typed `sdata` rather than `data`:
        # section_order puts .data before .sdata, so a `data` remainder places
        # the carved block after the whole .data region (measured: no match,
        # mismatch at 0x80012d18).
        #
        # The remainder then starts at an offset that is 2 mod 4, which makes
        # every 4-aligned datum inside it 2-aligned as far as ld is concerned,
        # and it warns where a C unit has the same name as a common definition
        # with alignment 4: `alignment 2 of normal symbol D_8009AF88 ... is
        # smaller than 4 used by the common definition in func_8004E7B0.o`
        # (D_8009AF88 is a tentative definition at src/game/func_8004E7B0.c:11
        # and the JP symbols.txt also gives that US name to the blob address
        # 0x8009AEF0, so the two have always been one symbol). The warning is
        # NEW -- it is in no earlier gate log -- and the obvious fix does not
        # work: resuming a SECOND time at the next 4-aligned offset silences it
        # (0 warnings) and the build then does NOT match. Measured 2026-09-22,
        # all three variants; only this one is byte-identical, so the warning is
        # disclosed in the PR rather than traded for a wrong image.
        for b in r.get("carve_pads", []):
            have.setdefault(b, f"      - [{b:#x}, pad]")
        if sresume != end:
            have.setdefault(end, f"      - [{end:#x}, pad]")
        have.setdefault(sresume, f"      - [{sresume:#x}, sdata, initialized_data_{sresume:x}]")
        sp.write_text("\n".join(l2[:j] + [have[o] for o in sorted(have)] + l2[k:]))
    # matching_c.json
    # matching_c.json: the file is not globally sorted upstream (one entry sits
    # out of order), so never re-sort it -- insert before the first entry in
    # file order whose address is larger, else append. The diff is then only
    # the new entries.
    mc = TGT_CFG / "matching_c.json"; d = json.load(open(mc))
    new_ents = [{"address": f"0x{j:08X}", "profile": r["profile"], "size": f"0x{s:X}", "source": r["src"]}
                for j, s in zip(r["jps"], r["sizes"])]
    pos = next((i for i, f in enumerate(d["functions"]) if int(f["address"], 16) > r["jps"][0]), len(d["functions"]))
    d["functions"][pos:pos] = new_ents
    mc.write_text(json.dumps(d, indent=2) + "\n")
    # symbols.txt: upstream appends each PR's lines at the end, functions then
    # data symbols; the existing lines and the trailing newline are kept as is
    st = TGT_CFG / "symbols.txt"; old = st.read_text()
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
