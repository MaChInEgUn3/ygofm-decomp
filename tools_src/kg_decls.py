#!/usr/bin/env python3
"""
The ported files' inline declarations: census, and the fold into include/.

    .venv/bin/python tools_src/kg_decls.py census        # what is still inline, and what conflicts
    .venv/bin/python tools_src/kg_decls.py fold-types    # typedefs, tag definitions and forward
                                                         # declarations -> include/kg_types.h

Every src/func_*.c whose header starts "Ported from krystalgamer" carries the
subset of his headers it needs, preprocessed (port_kg.py). The fold moves
those declarations into headers that ONLY the ported units include, so a
non-ported unit cannot see a change (nothing it includes is touched) and the
build proves the ported ones did not move. The census is the definition of
done: zero file-scope type units in the ported files after fold-types, and
its conflict counts say which shape the extern fold has to take.

Type units are safe to merge because the census measures them so: a typedef
name with two different definition texts across the ported units would be
two types, and there are none (census of 2026-09-21, before the fold: 240
type names, 0 with more than one definition text; only the six fixed-width
names also live in include/types.h, with the same text). Externs and
prototypes are NOT folded here: the same census says 451 extern symbols of
which 46 have more than one declaration across the ported units, 109 D_
symbols absent from variables.h and 157 declared with a type variables.h
lacks, 612 prototypes of which 14 disagree -- per-symbol arms, a decision
about which header holds them, not a script.
"""
import collections
import pathlib
import re
import sys

ROOT = pathlib.Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tools_src"))
import port_kg as P  # noqa: E402

HEADER = ROOT / "include" / "kg_types.h"
MARK = "/* Ported from krystalgamer"
INCLUDE_LINE = '#include "kg_types.h"\n'
BASE = {"u8", "s8", "u16", "s16", "u32", "s32"}
TAGDEF = re.compile(r"^(struct|union|enum)\s*([A-Za-z_]\w*)?\s*\{")   # `enum { K = 3 };` has no tag
FORWARD = re.compile(r"^(struct|union|enum)\s+([A-Za-z_]\w*)\s*;$")


def ported_files():
    return [p for p in sorted((ROOT / "src").glob("func_*.c"))
            if p.read_text(errors="replace").startswith(MARK)]


def norm(u):
    return re.sub(r"\s+", " ", u).strip()


def kind_of(u):
    n = norm(u)
    if P.is_def(u):
        return "def"
    if n.startswith("typedef"):
        return "typedef"
    if TAGDEF.match(n):
        return "tagdef"
    if FORWARD.match(n):
        return "forward"
    if n.startswith("extern") and "(" not in P.strip_bodies(n.split("=")[0].split("__attribute__")[0]):
        return "extern"
    if n.startswith("#"):
        return "directive"
    if "(" in n and n.endswith(";"):
        return "proto"
    return "other"


def units_of(path):
    """(kind, unit, start, end) for every file-scope unit after the provenance comment."""
    text = path.read_text(errors="replace")
    body_start = text.index("*/") + 2
    out, pos = [], body_start
    # A `#include` line has no `;`, so split_units would glue it to the unit
    # after it and the census would lose one extern or prototype per file
    # (measured: 139 units short on the first post-fold census). Directives
    # are units of their own, and the text between them is split as before.
    for m in re.finditer(r"(?m)^#[^\n]*\n|(?:(?!^#)[^\n]*\n?)+", text[body_start:]):
        chunk = m.group(0)
        if chunk.startswith("#"):
            i = body_start + m.start()
            out.append(("directive", chunk.strip(), i, i + len(chunk.strip())))
            continue
        for u in P.split_units(chunk):
            i = text.index(u, pos)
            out.append((kind_of(u), u, i, i + len(u)))
            pos = i + len(u)
    return text, out


def type_names(u):
    n = norm(u)
    m = TAGDEF.match(n) or FORWARD.match(n)
    names = set(P.definers(u)) if n.startswith("typedef") else set()
    if m and m.group(2):
        names.add(m.group(1) + " " + m.group(2))
    elif m:
        names |= set(P.definers(u))     # an anonymous enum defines its constants
    return names


def census():
    files = ported_files()
    cat = collections.Counter()
    typetexts = collections.defaultdict(set)
    externs = collections.defaultdict(set)
    protos = collections.defaultdict(set)
    files_with_types = 0
    for p in files:
        _, units = units_of(p)
        has_type = False
        for k, u, _, _ in units:
            cat[k] += 1
            if k in ("typedef", "tagdef", "forward"):
                has_type = True
                if k != "forward":      # `struct X;` defines nothing to conflict with
                    for nme in type_names(u):
                        typetexts[nme].add(norm(u))
            elif k == "extern":
                for nme in P.definers(u):
                    externs[nme].add(re.sub(r"__attribute__\s*\(\(.*?\)\)", "", norm(u)))
            elif k == "proto":
                for nme in P.definers(u):
                    protos[nme].add(norm(u))
        files_with_types += has_type
    vh = (ROOT / "include/variables.h").read_text()
    vdecl = collections.defaultdict(set)
    for m in re.finditer(r"(?m)^\s*extern\s+([^;]+?)\s+\**(D_[0-9A-F]{8})\s*(\[[^\]]*\])?\s*(?:__attribute__\(\(.*?\)\))?\s*;", vh):
        vdecl[m.group(2)].add((m.group(1).strip(), bool(m.group(3))))
    absent = diff = 0
    for k, v in externs.items():
        if not k.startswith("D_"):
            continue
        if k not in vdecl:
            absent += 1
            continue
        ours = {(re.sub(r"^extern\s+", "", x).rsplit(" ", 1)[0].strip().rstrip("*"), "[" in x) for x in v}
        if not any(o in vdecl[k] for o in ours):
            diff += 1
    print(f"ported files: {len(files)}")
    print("units by kind:", dict(sorted(cat.items())))
    print(f"files with file-scope type units: {files_with_types}   <- fold-types is done when this is 0")
    tconf = {k: v for k, v in typetexts.items() if len(v) > 1 and k not in BASE}
    print(f"type names: {len(typetexts)}, with >1 definition text: {len(tconf)} {sorted(tconf)[:10]}")
    econf = {k: v for k, v in externs.items() if len(v) > 1}
    print(f"extern symbols: {len(externs)}, with >1 declaration: {len(econf)}")
    print(f"D_ symbols absent from variables.h: {absent}; declared with a type variables.h lacks: {diff}")
    pconf = {k: v for k, v in protos.items() if len(v) > 1}
    print(f"prototypes: {len(protos)}, with >1 text: {len(pconf)}")
    ctrl = externs.get("D_800907D8")
    print("control D_800907D8 (two declarations expected while unfolded):", len(ctrl) if ctrl else 0)
    return 0


def fold_types():
    files = ported_files()
    types_h = (ROOT / "include/types.h").read_text()
    base_texts = {norm(m.group(0)) for m in re.finditer(r"typedef [^;]+;", types_h)}
    emitted, order, by_name = set(), [], {}
    edits = []
    for p in files:
        text, units = units_of(p)
        spans = []
        for k, u, i, j in units:
            if k not in ("typedef", "tagdef", "forward"):
                continue
            n = norm(u)
            names = type_names(u)
            if names & BASE:
                assert n in base_texts, f"{p.name}: base typedef differs from types.h: {n}"
            elif n not in emitted:
                if k != "forward":      # a forward declaration is not a second definition
                    for nme in names:
                        assert by_name.get(nme, n) == n, f"{p.name}: {nme} has two definitions"
                        by_name[nme] = n
                emitted.add(n)
                order.append(u)
            spans.append((i, j))
        edits.append((p, text, spans))
    out = ["/* Types from krystalgamer/memories-decomp, as the ported units in src/\n",
           " * declare them (see each file's provenance header). Included ONLY by\n",
           " * those units: a non-ported unit never sees this file. Built by\n",
           " * tools_src/kg_decls.py fold-types from the units' own inline copies,\n",
           " * in first-seen order over the sorted file names, each definition once;\n",
           " * the six fixed-width names come from types.h, whose text is identical.\n",
           " * The layouts are his tree's and the build is the proof they did not\n",
           " * change on the way in. */\n",
           "#ifndef KG_TYPES_H\n#define KG_TYPES_H\n\n#include \"types.h\"\n\n"]
    for u in order:
        out.append(u + "\n")
    out.append("\n#endif /* KG_TYPES_H */\n")
    HEADER.write_text("".join(out))
    for p, text, spans in edits:
        for i, j in sorted(spans, reverse=True):
            k = j
            while k < len(text) and text[k] == "\n":
                k += 1
            text = text[:i] + text[k:]
        cut = text.index("*/") + 2
        assert INCLUDE_LINE not in text
        text = text[:cut] + "\n" + INCLUDE_LINE + text[cut:].lstrip("\n")
        p.write_text(text)
    print(f"kg_types.h: {len(order)} type units from {len(files)} files; {sum(len(s) for _, _, s in edits)} inline units removed")
    return 0


if __name__ == "__main__":
    cmd = sys.argv[1] if len(sys.argv) > 1 else "census"
    sys.exit({"census": census, "fold-types": fold_types}[cmd]())
