#!/usr/bin/env python3
"""
Read the retail CD image and answer one question: is there code outside
`SLUS_014.11`?

    python tools_src/disc.py [image]      # default: YUGIOH.img in the repo root

Prints the ISO9660 root listing, then for every file a MIPS-code density
measurement against the executable's own `.text` as the reference. The whole
point is the reference: "looks like data" is worthless without a number that
says what code looks like on this same disc.

Why this exists
---------------
`config/undefined_funcs_auto.txt` lists 24 addresses the game `jal`s into that
are not in the executable -- two tight clusters around 0x80168xxx and
0x80180xxx. The obvious reading is CD overlays, and the obvious next step is a
second splat target. Before spending anything on that, measure: this tool says
the disc carries no *uncompressed* MIPS anywhere outside the executable.

What it cannot tell you
-----------------------
Compression. A packed overlay is indistinguishable from data by this metric,
and that is the live hypothesis, not a closed question. Do not read a low
density as "no code here"; read it as "no code here in a form this measures".

The image is a CloneCD set (.ccd/.img/.sub), raw 2352-byte sectors. PS1 discs
are Mode 2 Form 1: 24 bytes of sync/header/subheader, 2048 bytes of user data,
then EDC/ECC. `.gitignore` covers `*.img`/`*.ccd`/`*.sub`; the disc is
copyrighted and must never be committed.
"""
import os
import struct
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
SECTOR, USER_OFF, USER_LEN = 2352, 24, 2048
JR_RA = bytes.fromhex("0800e003")          # jr $ra, little-endian
SAMPLE_SECTORS = 1500                      # ~3 MB per file is plenty
CODE_THRESHOLD = 200                       # per MB; .text measures ~3800


def sectors(f, lba, n):
    out = []
    for i in range(n):
        f.seek((lba + i) * SECTOR + USER_OFF)
        out.append(f.read(USER_LEN))
    return b"".join(out)


def listdir(f, lba, size):
    buf = sectors(f, lba, (size + USER_LEN - 1) // USER_LEN)
    out, i = [], 0
    while i < len(buf):
        length = buf[i]
        if length == 0:                     # padding to the end of the sector
            i = (i // USER_LEN + 1) * USER_LEN
            if i >= len(buf):
                break
            continue
        rec = buf[i:i + length]
        name = rec[33:33 + rec[32]].decode("ascii", "replace")
        out.append((name,
                    struct.unpack("<I", rec[2:6])[0],
                    struct.unpack("<I", rec[10:14])[0],
                    rec[25]))
        i += length
    return out


def density(blob):
    """`jr $ra` occurrences per megabyte."""
    return blob.count(JR_RA) / (len(blob) / 1e6) if blob else 0.0


def main():
    img = sys.argv[1] if len(sys.argv) > 1 else os.path.join(ROOT, "YUGIOH.img")
    if not os.path.exists(img):
        sys.exit(f"no disc image at {img}\n"
                 "Pass one as an argument. It is gitignored on purpose.")

    exe = os.path.join(ROOT, "extracted", "SLUS_014.11")
    ref = None
    if os.path.exists(exe):
        # .text is file 0x31D8-0x80EE0 per config/SLUS_014.11.yaml
        ref = density(open(exe, "rb").read()[0x31D8:0x80EE0])
        print(f"reference: {ref:.0f} 'jr $ra' per MB in the executable's .text\n")

    f = open(img, "rb")
    pvd = sectors(f, 16, 1)
    if pvd[1:6] != b"CD001":
        sys.exit("not an ISO9660 image (no CD001 at LBA 16)")
    root = pvd[156:156 + 34]
    entries = listdir(f, struct.unpack("<I", root[2:6])[0],
                      struct.unpack("<I", root[10:14])[0])

    files = []
    for name, lba, size, flags in entries:
        if name in ("\x00", "\x01"):
            continue
        if flags & 2:
            entries += [(name + "/" + n, l, s, fl)
                        for n, l, s, fl in listdir(f, lba, size)
                        if n not in ("\x00", "\x01")]
            continue
        files.append((name.split(";")[0], lba, size))

    print(f"{'file':<22} {'size':>12}  {'sampled':>8}  {'jr $ra/MB':>9}  verdict")
    for name, lba, size in sorted(files):
        n = min((size + USER_LEN - 1) // USER_LEN, SAMPLE_SECTORS)
        blob = sectors(f, lba, n)
        d = density(blob)
        exe_hdr = "  [PS-X EXE]" if b"PS-X EXE" in blob else ""
        verdict = "MIPS CODE" if d > CODE_THRESHOLD else "no uncompressed code"
        print(f"{name:<22} {size:>12,}  {n*USER_LEN/1e6:>7.1f}M  "
              f"{d:>9.1f}  {verdict}{exe_hdr}")

    print("\nA low number means no code *in a form this measures*. Packed or "
          "encrypted\noverlays read as data here; see the module docstring.")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
