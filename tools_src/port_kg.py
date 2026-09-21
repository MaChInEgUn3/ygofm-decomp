#!/usr/bin/env python3
"""
Port one matched function from krystalgamer/memories-decomp into a unit this
tree's try_func can measure.

    .venv/bin/python tools_src/port_kg.py func_XXXXXXXX [--json]

His tree is expected beside this one as ../memories-decomp, or at $YGOFM_KG.
Output goes to build/port/: port_<func>.c (his whole unit, preprocessed) and
port_pruned_<func>.c (the same, cut down to the declarations the function
reaches). --json adds a line with the cc1psx flags and the assembler -G his
compiler profile means in this tree's terms.

What it does, and why each step exists (measured 2026-09-21, 67 of 105 parks
matched on the first try -- see docs/MERGE_KRYSTALGAMER.md):

  * preprocess with HIS gcc from HIS tree, so his per-TU headers and guards
    are what his build saw;
  * rename every symbol of his tree to this tree's spelling (func_ADDR from
    his functions.csv, D_ADDR from his symbols.txt), strings included, so
    his asm("name") aliases keep pointing at the right address;
  * move the target definition to the END of the unit: try_func reads the
    object from the function's symbol to the end, so a helper placed after
    the target reads as extra instructions;
  * prune to a fixpoint over the names each declaration DEFINES (typedef
    names, tags, variables, prototypes), never over the names it mentions --
    keying on mentions keeps every unit that says `u8`. Called `static`
    helpers are kept; any other function definition the target calls becomes
    a prototype, because the full build already has that function and the
    link fails on a second definition. A symbol alias `asm("...")` is
    stripped before the definer is read, or the definer comes out as `asm`.

try_func does not link. Two things pass it and break the build, and both
are handled: another TU's definition (above) and his linker-script aliases
(`D_8009B0F4_abs`, `D_8009B134_abs`), which live in config/symbol_aliases.txt
here.
"""
import csv
import json
import os
import pathlib
import re
import subprocess
import sys

ROOT = pathlib.Path(__file__).resolve().parent.parent
KG = pathlib.Path(os.environ.get("YGOFM_KG", ROOT.parent / "memories-decomp"))
OUT = ROOT / "build" / "port"

IDENT = re.compile(r"\b[A-Za-z_]\w*\b")
KW = set("""auto break case char const continue default do double else enum extern float for goto if int long
register return short signed sizeof static struct switch typedef union unsigned void volatile while asm __asm__
__attribute__ __volatile__ inline""".split())
DECL_HEAD = re.compile(r"^\s*(typedef|struct|union|enum)\b")
FUNC_HEAD = re.compile(r"\)\s*\{")
KNR_TAIL = re.compile(r"\)\s*[A-Za-z_][^{}()]*$")   # `;` allowed: the 2nd, 3rd parameter declaration
BASE_FLAGS = ("-mel", "-mips1", "-mcpu=R3000", "-msoft-float", "-Dpsx", "-D__psx__", "-D__psx")


def load_kg():
    fn = {int(r["address"], 16): r
          for r in csv.DictReader(open(KG / "config/slus_01411/functions.csv"))}
    mc = {int(f["address"], 16): f
          for f in json.load(open(KG / "config/slus_01411/matching_c.json"))["functions"]}
    profiles = json.load(open(KG / "config/slus_01411/compiler_profiles.json"))["profiles"]
    return fn, mc, profiles


ALIAS_SHAPE = re.compile(r"^(D_[0-9A-F]{8}_\w+|Base\d*_[0-9A-F]{8}\w*)$")


def kg_symbols():
    """name -> address from his three symbol files (symbols.txt has 1361 names,
    c_symbols.ld another 400 that only the linker sees, link_symbols.ld 2)."""
    out = {}
    for f in ("symbols.txt", "c_symbols.ld", "link_symbols.ld"):
        for m in re.finditer(r"(?m)^\s*([A-Za-z_]\w*)\s*=\s*0x([0-9A-Fa-f]+)\s*;",
                             (KG / "config/slus_01411" / f).read_text()):
            out.setdefault(m.group(1), int(m.group(2), 16))
    return out


def renames(fn):
    """A named symbol becomes this tree's func_ADDR / D_ADDR. A SECOND name for
    an address that already has its D_ name (`D_800E9EC8_arr`, `D_8009B0F4_abs`,
    `Base2_...`) is one of his linker-script aliases: it exists so that one
    reference can be declared with another type or emitted in another form,
    so it cannot be folded into the D_ name inside the unit. Those are kept
    and reported as ALIASES for config/symbol_aliases.txt."""
    ren = {}
    for a, row in fn.items():
        if row["name"] != f"func_{a:08X}":
            ren[row["name"]] = f"func_{a:08X}"
    for name, addr in kg_symbols().items():
        if addr in fn or ALIAS_SHAPE.match(name) or name == f"D_{addr:08X}":
            continue
        ren[name] = f"D_{addr:08X}"
    return ren


def aliases_used(text):
    syms = kg_symbols()
    return {w: syms[w] for w in set(IDENT.findall(text)) if w in syms and ALIAS_SHAPE.match(w)}


def preprocess(src):
    gcc = KG / "tools/toolchains/gcc-2.8.1-psx/bin/mips-sony-psx-gcc"
    r = subprocess.run([str(gcc), "-E", "-P", "-Dpsx", "-D__psx__", "-D__psx", str(src)],
                       cwd=KG, capture_output=True, text=True)
    if r.returncode:
        sys.exit("cpp failed:\n" + r.stderr)
    return r.stdout


def move_target_last(text, func):
    # ANSI head, or a K&R head followed by parameter declarations that cannot
    # contain parens -- an unbounded `(?:[^;{}]*;)*` here backtracked for
    # minutes on a unit that prototypes the target before defining it
    m = re.search(r"(?m)^[^\n;{}]*\b" + func + r"\s*\([^;{)]*\)(?:\s*[A-Za-z_][^;{}()]*;)*\s*\{", text)
    if not m:
        sys.exit(f"definition of {func} not found in preprocessed unit")
    depth, i = 0, m.end() - 1
    while True:
        if text[i] == "{":
            depth += 1
        elif text[i] == "}":
            depth -= 1
            if depth == 0:
                break
        i += 1
    body = text[m.start():i + 1]
    return text[:m.start()] + text[i + 1:] + "\n" + body + "\n"


def split_units(text):
    units, buf, depth, i, n = [], [], 0, 0, len(text)
    while i < n:
        c = text[i]
        if c in "\"'":
            j = i + 1
            while j < n and text[j] != c:
                j += 2 if text[j] == "\\" else 1
            buf.append(text[i:j + 1])
            i = j + 1
            continue
        buf.append(c)
        if c in "({[":
            depth += 1
        elif c in ")}]":
            depth -= 1
            if c == "}" and depth == 0:
                u = "".join(buf)
                head = u[:u.index("{")]
                if FUNC_HEAD.search(head + "{") and not DECL_HEAD.match(u):
                    units.append(u)
                    buf = []
        elif c == ";" and depth == 0:
            u = "".join(buf)
            # a K&R definition: `void f(a, b)` then `u32 a;` -- the `;` after
            # a parameter declaration is inside the definition, not its end
            if KNR_TAIL.search(u[:-1]):
                i += 1
                continue
            units.append(u)
            buf = []
        i += 1
    if "".join(buf).strip():
        units.append("".join(buf))
    return [u.strip() for u in units if u.strip()]


def idents(u):
    return {w for w in IDENT.findall(u) if w not in KW}


def is_def(u):
    return u.endswith("}") and not DECL_HEAD.match(u)


def strip_bodies(s):
    while True:
        s2 = re.sub(r"\{[^{}]*\}", " ", s)
        if s2 == s:
            return s
        s = s2


def definers(u):
    """Names a declaration introduces: typedef names, tags, variables, functions."""
    names = set(re.findall(r"\b(?:struct|union|enum)\s+([A-Za-z_]\w*)\s*\{", u))
    m = re.match(r"\s*(?:typedef\s+)?enum\b[^{]*\{([^}]*)\}", u)
    if m:   # an enum's constants are definers too: `enum { ROW_COUNT = 3 };`
        names |= {c.split("=")[0].strip() for c in m.group(1).split(",") if c.strip()}
    s = strip_bodies(u)
    s = re.sub(r"__attribute__\s*\(\(.*?\)\)", " ", s)
    s = re.sub(r"\basm\s*\(\s*\"[^\"]*\"\s*\)", " ", s)
    s = re.sub(r"\[[^\]]*\]", " ", s)
    s = s.split("=")[0].rstrip(";").strip()
    m = re.match(r"[^(]*\(\s*\*\s*([A-Za-z_]\w*)\s*\)\s*\(", s)
    if m:
        names.add(m.group(1))
        return names
    if "(" in s:
        ws = IDENT.findall(s[:s.index("(")])
        if ws:
            names.add(ws[-1])
        return names
    ws = [w for w in IDENT.findall(s) if w not in KW]
    if ws:
        names.add(ws[-1])
    return names


def def_name(u):
    head = u[:u.index("{")]
    return set(IDENT.findall(head[:head.rindex("(")])[-1:])


def prune(text, func):
    units = split_units(text)
    target = [k for k, u in enumerate(units)
              if is_def(u) and re.search(r"\b" + func + r"\s*\(", u[:u.index("{")])]
    if not target:
        sys.exit(f"target definition not found among {len(units)} units")
    t = target[-1]
    keep, needed = {t}, idents(units[t])
    defs = [definers(u) if not is_def(u) else def_name(u) for u in units]
    protos = set()
    changed = True
    while changed:
        changed = False
        for k, u in enumerate(units):
            if k in keep or not (defs[k] & needed):
                continue
            if is_def(u) and not u.startswith("static") and k != t:
                units[k] = u[:u.index("{")].rstrip() + ";"
            if (not is_def(units[k]) and not DECL_HEAD.match(units[k])
                    and not re.match(r"\s*(extern|static|typedef|const)\b", units[k])
                    and "(" not in strip_bodies(units[k].split("=")[0])):
                # a definition with a zero initialiser and a section attribute
                # (`u8 g[6] __attribute__((section(".sdata"))) = {0};`) is the
                # same thing: his TU owns it, here it is a linker symbol
                units[k] = re.sub(r"\s*__attribute__\s*\(\(.*?\)\)", "", units[k].split("=")[0]).rstrip() + ";"
                # a tentative definition, `u8 D_8009B0A8;`: his TU OWNS the
                # object and maspsx --use-comm-section places it; here every
                # global is a linker symbol, so the unit only declares it
                units[k] = "extern " + units[k]
            if not is_def(units[k]) and "(" in strip_bodies(units[k]) and not DECL_HEAD.match(units[k]):
                # a prototype: his unit can reach one address under two names
                # with two parameter lists (an SDK header and his own), and
                # both rename to the same func_; the first declaration wins
                if defs[k] & protos:
                    units[k] = ""
                    continue
                protos |= defs[k]
            keep.add(k)
            needed |= idents(units[k])
            changed = True
    return "\n".join(units[k] for k in sorted(keep) if units[k]) + "\n", len(units), len(keep)


def flags_for(profile):
    cc = [f for f in profile["compiler_flags"] if f.startswith(("-O", "-G", "-m", "-f")) and f not in BASE_FLAGS]
    g = [x for x in cc if x.startswith("-G")][0]
    short = ["-quiet", "-O2", g] + [x for x in cc if x.startswith("-fno-")]
    short.append("-msplit-addresses" if "-msplit-addresses" in cc else "-mno-split-addresses")
    asg = " ".join(f for f in profile["maspsx_flags"] if f.startswith("-G"))
    return short, asg


def main():
    func = sys.argv[1]
    addr = int(func[5:], 16)
    fn, mc, profiles = load_kg()
    if addr not in mc:
        sys.exit(f"{func} is not matching_c in {KG}")
    entry = mc[addr]
    text = preprocess(KG / entry["source"])
    ren = renames(fn)
    pat = re.compile(r"\b(" + "|".join(sorted(map(re.escape, ren), key=len, reverse=True)) + r")\b")
    text = pat.sub(lambda m: ren[m.group(1)], text)
    text = move_target_last(text, func)
    OUT.mkdir(parents=True, exist_ok=True)
    (OUT / f"port_{func}.c").write_text(text)
    pruned, n_units, n_kept = prune(text, func)
    (OUT / f"port_pruned_{func}.c").write_text(pruned)
    cc, asg = flags_for(profiles[entry["profile"]])
    aliases = aliases_used(pruned)
    if aliases:
        print("ALIASES " + " ".join(f"{k}=0x{v:08X}" for k, v in sorted(aliases.items())))
    print(f"{func}: {entry['source']} ({fn[addr]['name']}) profile={entry['profile']} "
          f"units {n_units} -> {n_kept}, {pruned.count(chr(10))} lines")
    print("FLAGS " + " ".join(cc) + (f"   as {asg}" if asg else ""))
    if "--json" in sys.argv:
        print("JSON " + json.dumps({"cc": cc, "as": asg, "source": entry["source"],
                                    "name": fn[addr]["name"], "profile": entry["profile"],
                                    "aliases": {k: f"0x{v:08X}" for k, v in sorted(aliases.items())}}))


if __name__ == "__main__":
    main()
