"""Field-usage evidence extracted from the 1108 byte-exact functions in src/.

WHY THIS EXISTS. krystalgamer opened issue #2500 on his tree ("derive global
types and function parameter types from their usage") because the decompiled
sources are full of `*(s16 *)(var + offset)` and nobody knows the real record
layouts. His agents guess the layouts back from m2c's output, which is where
they get stuck. This project has a different asset: every file in `src/` is
byte-exact against the retail binary, so every cast in it is a MEASUREMENT of
a field's offset, width and signedness -- not a guess. This tool reads those
measurements out.

WHAT IT REPORTS, and how strong each row is:
  * DIRECT   -- `*(T *)(D_XXXXXXXX + K)` or `D_XXXXXXXX[K]` written against
                the symbol itself. The symbol, the offset, the width and the
                signedness are all in the source of a function that matches.
  * ALIAS    -- the same access through a local that the same file assigns
                from the symbol exactly once (`p = D_XXXXXXXX;`). Same
                strength in practice, but the resolution is this tool's, so
                it is labelled separately.
  * STRIDE   -- an index expression `D_XXXXXXXX + i * S` or `[i * S + K]`.
                S is the record size, and it is the single most useful number
                for turning a symbol into an array of structs.

WHAT IT IS NOT. It reports what the matched sources DO, so an offset absent
here is an offset no matched function touches -- not proof that the field
does not exist. And a width is the width of the ACCESS: a `u8` read of a
`u16` field is legal C and shows up as a byte. Read the whole offset set for
a symbol before declaring a struct, and prefer a layout that explains every
row rather than one that fits the widest.

Usage:  .venv/bin/python tools_src/field_usage.py [--min N] > docs/FIELD_USAGE.txt
"""
import collections
import glob
import os
import re
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
SRC = os.path.join(ROOT, "src")
VARS = os.path.join(ROOT, "include", "variables.h")

TYPES = "u8|s8|u16|s16|u32|s32|f32"
SYM = r"D_[0-9A-F]{8}"
NUM = r"(?:0x[0-9A-Fa-f]+|\d+)"

# *(T *)(BASE + K) / (BASE - K); BASE may carry a (u8 *) cast
CAST = re.compile(
    r"\*\(\s*(" + TYPES + r")\s*\*\s*\)\s*\(\s*(?:\(\s*u8\s*\*\s*\)\s*)?"
    r"([A-Za-z_]\w*)\s*([-+])\s*(" + NUM + r")\s*\)")
# *(T *)BASE  -- offset zero
CAST0 = re.compile(
    r"\*\(\s*(" + TYPES + r")\s*\*\s*\)\s*(?:\(\s*u8\s*\*\s*\)\s*)?"
    r"([A-Za-z_]\w*)\b(?!\s*[-+\[])")
# BASE[K] with a literal index -- one byte per element for a u8 * base
INDEX = re.compile(r"\b([A-Za-z_]\w*)\s*\[\s*(" + NUM + r")\s*\]")
# BASE + i * S  and  [i * S + K]  -- record stride
STRIDE = re.compile(r"\b([A-Za-z_]\w*)\s*\+\s*\w+\s*\*\s*(" + NUM + r")\b")
# p = D_XXXXXXXX;  or  p = (u8 *)D_XXXXXXXX;  or  p = &D_XXXXXXXX;
ALIAS = re.compile(
    r"\b([A-Za-z_]\w*)\s*=\s*(?:\(\s*[\w ]+\*\s*\)\s*)?&?\s*(" + SYM + r")\s*;")

WIDTH = {"u8": 1, "s8": 1, "u16": 2, "s16": 2, "u32": 4, "s32": 4, "f32": 4}


def num(s):
    return int(s, 16) if s.lower().startswith("0x") else int(s)


def strip(text):
    text = re.sub(r"/\*.*?\*/", " ", text, flags=re.S)
    return re.sub(r"//[^\n]*", " ", text)


def declared():
    """symbol -> the first declaration variables.h gives it."""
    out = {}
    for line in open(VARS):
        m = re.match(r"\s*extern\s+(.*?)\b(" + SYM + r")\b(.*);", line)
        if m and m.group(2) not in out:
            out[m.group(2)] = ("extern " + m.group(1) + m.group(2)
                               + m.group(3)).strip() + ";"
    return out


def main():
    lim = 1
    if "--min" in sys.argv:
        lim = int(sys.argv[sys.argv.index("--min") + 1])
    decl = declared()
    # sym -> (off, width, sign) -> {kind: set(files)}
    fields = collections.defaultdict(lambda: collections.defaultdict(
        lambda: collections.defaultdict(set)))
    strides = collections.defaultdict(lambda: collections.defaultdict(set))
    files = sorted(glob.glob(os.path.join(SRC, "func_*.c")))
    for path in files:
        name = os.path.basename(path)[:-2]
        body = strip(open(path).read())
        alias = {}
        for var, sym in ALIAS.findall(body):
            if var in alias and alias[var] != sym:
                alias[var] = None          # two sources: not resolvable
            else:
                alias.setdefault(var, sym)
        alias = {k: v for k, v in alias.items() if v}

        def base_of(tok):
            if re.fullmatch(SYM, tok):
                return tok, "DIRECT"
            if tok in alias:
                return alias[tok], "ALIAS"
            return None, None

        for ty, tok, sign, off in CAST.findall(body):
            sym, kind = base_of(tok)
            if not sym:
                continue
            k = num(off) * (-1 if sign == "-" else 1)
            fields[sym][(k, WIDTH[ty], ty[0])][kind].add(name)
        for ty, tok in CAST0.findall(body):
            sym, kind = base_of(tok)
            if sym:
                fields[sym][(0, WIDTH[ty], ty[0])][kind].add(name)
        for tok, idx in INDEX.findall(body):
            sym, kind = base_of(tok)
            if sym:
                fields[sym][(num(idx), 1, "?")][kind].add(name)
        for tok, s in STRIDE.findall(body):
            sym, kind = base_of(tok)
            if sym and num(s) > 1:
                strides[sym][num(s)].add(name)

    rows = sorted(fields.items(),
                  key=lambda kv: (-len(kv[1]), kv[0]))
    nsym = sum(1 for _, f in rows if len(f) >= lim)
    print(__doc__.strip())
    print()
    print("=" * 72)
    print("%d files scanned, %d symbols with at least %d distinct field(s)."
          % (len(files), nsym, lim))
    print("=" * 72)
    for sym, f in rows:
        if len(f) < lim:
            continue
        users = set()
        for kinds in f.values():
            for s in kinds.values():
                users |= s
        print()
        print("%s  --  %d field(s), %d file(s)" % (sym, len(f), len(users)))
        if sym in decl:
            print("    declared: %s" % decl[sym])
        if sym in strides:
            ss = ", ".join("%d (%d file(s))" % (s, len(u))
                           for s, u in sorted(strides[sym].items()))
            print("    stride evidence: %s" % ss)
        for (off, w, sg) in sorted(f):
            kinds = f[(off, w, sg)]
            tag = "+".join(sorted(kinds))
            n = len({x for s in kinds.values() for x in s})
            print("    %+#7x  %d byte(s)  %-8s %-12s %d file(s)"
                  % (off, w, {"u": "unsigned", "s": "signed", "?": "byte-index"}[sg],
                     tag, n))


main()
