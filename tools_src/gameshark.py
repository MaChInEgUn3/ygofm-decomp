#!/usr/bin/env python3
"""
Decode PS1 GameShark / Pro Action Replay codes into this project's symbols.

krystalgamer asked on 2026-09-01 for a compilation of GameShark codes as
reference material. They are a better source than they look, and they are
COMPLEMENTARY to the community file offsets in docs/research/
community_offsets.md: a file offset points at an INSTRUCTION and names a
function, a GameShark code points at a RAM ADDRESS and names a VARIABLE.

A code is a claim that writing one value to one address produces one named
effect in the running game, tested by everyone who ever used it. Same
evidentiary standing as a cheat offset, and the same caveat: nobody here has
run it.

FORMAT (PS1, the only part that matters here):
    80AAAAAA VVVV   write halfword VVVV to 0x80AAAAAA   (the AAAAAA is
                    an offset from 0x80000000, so the address is 0x80|AAAAAA)
    30AAAAAA 00VV   write byte
    D0AAAAAA VVVV   execute the NEXT line only if [addr] == VVVV
    50NNNNII 0000   repeat the next line N times, stepping I bytes
Anything else is a device/master code and is skipped.

    .venv/bin/python tools_src/gameshark.py codes.txt
    echo "801D07E0 423F" | .venv/bin/python tools_src/gameshark.py -
"""

import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
CODE = re.compile(r"^\s*([0-9A-Fa-f]{8})\s+([0-9A-Fa-f]{4})\s*$")
KIND = {0x80: ("halfword write", 2), 0x30: ("byte write", 1),
        0xD0: ("equal-to test", 2), 0xE0: ("not-equal test", 2),
        0x50: ("repeat block", 0), 0x10: ("halfword write", 2)}


def symbols():
    """address -> (declared name, semantic name if any)."""
    out = {}
    v = ROOT / "include" / "variables.h"
    if v.exists():
        for m in re.finditer(r"\bD_([0-9A-F]{8})\b", v.read_text(errors="replace")):
            out.setdefault(int(m.group(1), 16), ["D_" + m.group(1), None])
    for f in ("names_gms.txt", "names_unchiga.txt"):
        p = ROOT / "config" / f
        if not p.exists():
            continue
        for l in p.read_text(errors="replace").splitlines():
            m = re.match(r"^0x([0-9A-Fa-f]{8})\s+\w+\s+\S+\s+(\S+)", l)
            if m:
                a = int(m.group(1), 16)
                out.setdefault(a, [None, None])[1] = m.group(2)
    return out


def nearest(syms, addr):
    """The declared symbol covering addr, and the offset into it."""
    best = None
    for a in syms:
        if a <= addr and (best is None or a > best):
            best = a
    return (best, addr - best) if best is not None else (None, None)


def main():
    src = sys.argv[1] if len(sys.argv) > 1 else None
    if not src:
        print(__doc__)
        return 2
    text = sys.stdin.read() if src == "-" else Path(src).read_text(errors="replace")
    syms = symbols()

    for line in text.splitlines():
        m = CODE.match(line)
        if not m:
            continue
        raw, val = int(m.group(1), 16), int(m.group(2), 16)
        kind, width = KIND.get(raw >> 24, ("unknown", 0))
        if width == 0:
            print("%s %s  -- %s, skipped" % (m.group(1), m.group(2), kind))
            continue
        addr = 0x80000000 | (raw & 0x00FFFFFF)
        base, off = nearest(syms, addr)
        where = "no symbol below it"
        if base is not None:
            names = syms[base]
            label = names[1] or names[0] or "D_%08X" % base
            where = label if off == 0 else "%s + 0x%X" % (label, off)
        print("%s %s  0x%08X  %-14s = 0x%X   %s"
              % (m.group(1), m.group(2), addr, kind, val, where))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
