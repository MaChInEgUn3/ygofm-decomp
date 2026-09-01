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
BIN = ROOT / "extracted" / "SLUS_014.11"
DELTA = 0x8000F800          # vram -> file offset is the inverse
SCOPE = 0x80073840          # below this is game code; above, SDK
CODE = re.compile(r"^\s*([0-9A-Fa-f]{8})\s+([0-9A-Fa-f]{4})\s*$")
# Every type EXCEPT the 0x50 repeat directive carries an address. Treating the
# C0/C2/D2/D3 conditionals as address-less directives silently dropped 13
# addresses from a compilation that claimed to be complete.
KIND = {0x80: ("halfword write", 2), 0x30: ("byte write", 1),
        0x10: ("halfword write", 2), 0x11: ("halfword write", 2),
        0xD0: ("equal-to test", 2), 0xD1: ("not-equal test", 2),
        0xD2: ("less-than test", 2), 0xD3: ("greater-than test", 2),
        0xE0: ("not-equal test", 2), 0xE2: ("test", 2),
        0xC0: ("test", 2), 0xC2: ("test", 2),
        0x50: ("repeat block", 0)}


def image_halfword(vram):
    """The halfword at `vram` as the retail image holds it, or None if outside."""
    off = vram - DELTA
    if not BIN.exists() or off < 0 or off + 2 > BIN.stat().st_size:
        return None
    with open(BIN, "rb") as f:
        f.seek(off)
        b = f.read(2)
    return b[0] | (b[1] << 8)          # little-endian


def verify_guard(vram, expected):
    """Check a D0/E0 guard against our own binary.

    STRONG only for CODE addresses. A guard on a code address asserts an
    instruction halfword, which never changes -- so a mismatch proves the code
    was written for a different build and the row must be dropped. That is the
    gate that keeps PAL/JP codes out of a compilation labelled NTSC-U.

    A guard on a DATA address asserts a runtime value the game overwrites, and
    the file only holds its initial value, so a mismatch there means nothing.
    Reporting those as REJECTED would be the tool answering a question it did
    not measure -- they come back UNCHECKABLE instead.
    """
    got = image_halfword(vram)
    if got is None:
        return "OUTSIDE", None
    if vram >= SCOPE:
        return "UNCHECKABLE", got       # data or SDK, not an instruction
    if vram >= 0x80010000 and vram < SCOPE:
        return ("VERIFIED" if got == expected else "REJECTED"), got
    return "UNCHECKABLE", got


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
