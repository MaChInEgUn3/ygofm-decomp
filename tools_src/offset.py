#!/usr/bin/env python3
"""
Turn a community file offset into a function, an instruction, and a diagnosis.

The Brazilian/Spanish/Vietnamese FM scene has been sharing cheats and patches
for years, and every one of them is stated as a FILE OFFSET into SLUS_014.11 --
krystalgamer's observation on 2026-09-01, and the reason that corpus has never
been usable by a decomp. This converts: offset -> vram (+0x8000F800) -> the
containing function -> the instruction the byte belongs to.

WORKED EXAMPLE, the one that motivated it. A tutorial credited to Markin Marcal:

    "Olho do Milenio, Offset 8864 no SLUS. No SLUS estara o codigo FF,
     substitua por 00 e voce vera a mao do NPC, substitua por 01 e voce vera
     as cartas ocultas mas com numeros respectivos a ordem do drop no deck."

`8864` is ambiguous between decimal and hex and the tutorials never say which.
The stated byte value disambiguates it for free: at decimal 8864 the byte is
0x00, at hex 0x8864 it is 0xFF, so the tutorial means hex. That check is built
in below -- pass --expect FF and it picks the reading that matches.

0x8864 -> 0x80018064, inside func_80018004:

    lb    $v0, 0x1F($v0)     load a signed byte from the card record
    bgez  $v0, .L8001806C    if it is >= 0, skip
    addiu $v0, $zero, 0xFF   <- the cheat byte is this immediate's low half
    sb    $v0, 0x67($a0)     store into +0x67 of the object

So +0x67 is a card's VISIBILITY marker (0xFF hidden), the `bgez` on +0x1F is
what decides a card is the opponent's, and patching the immediate to 0x00 or
0x01 makes hidden cards render. A community cheat, converted into a field
offset and a mechanism.

    .venv/bin/python tools_src/offset.py 8864 --expect FF
    .venv/bin/python tools_src/offset.py 0x8864
"""

import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
DELTA = 0x8000F800          # file offset -> vram, verified against splat's config
BIN = ROOT / "extracted" / "SLUS_014.11"
ASM = ROOT / "asm" / "nonmatchings" / "31D8"


def byte_at(off):
    with open(BIN, "rb") as f:
        f.seek(off)
        b = f.read(1)
    return b[0] if b else None


def containing(vram):
    best = None
    for p in ASM.glob("func_*.s"):
        a = int(p.stem[5:], 16)
        if a <= vram and (best is None or a > best[0]):
            best = (a, p)
    return best


def main():
    args = [a for a in sys.argv[1:] if not a.startswith("--")]
    if not args:
        print(__doc__)
        return 2
    raw = args[0]
    expect = None
    if "--expect" in sys.argv:
        expect = int(sys.argv[sys.argv.index("--expect") + 1], 16)

    # A bare number is ambiguous; the tutorials never say which base they mean.
    cands = []
    if raw.lower().startswith("0x"):
        cands = [int(raw, 16)]
    else:
        cands = [int(raw, 16), int(raw, 10)] if raw.isdigit() else [int(raw, 16)]
        cands = list(dict.fromkeys(cands))

    if expect is not None:
        keep = [c for c in cands if byte_at(c) == expect]
        if not keep:
            print("no reading of %r has byte 0x%02X:" % (raw, expect))
            for c in cands:
                print("  0x%X (dec %d) -> byte 0x%02X" % (c, c, byte_at(c)))
            return 1
        cands = keep

    for off in cands:
        vram = off + DELTA
        b = byte_at(off)
        print("file 0x%X (dec %d) -> vram 0x%08X   byte 0x%02X" % (off, off, vram, b))
        hit = containing(vram)
        if not hit:
            print("  no function covers it (data, or above the split)")
            continue
        a, p = hit
        print("  in %s%s" % (p.stem, "   [decompiled]"
                             if (ROOT / "src" / (p.stem + ".c")).exists() else ""))
        for l in open(p, errors="replace"):
            m = re.match(r"\s+/\* \w+ ([0-9A-F]{8}) \w+ \*/\s+(.*)", l)
            if m and abs(int(m.group(1), 16) - vram) <= 16:
                at = int(m.group(1), 16)
                mark = "  <-- the byte" if at <= vram < at + 4 else ""
                print("    %s  %s%s" % (m.group(1), m.group(2).strip(), mark))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
