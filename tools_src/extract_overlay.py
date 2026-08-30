#!/usr/bin/env python3
"""Extract the duel overlay's resident image from your own Yu-Gi-Oh! FM disc.

PROVENANCE: the algorithm in this file is Unchiga's (`tools/extract_overlay.py`
in the tree he shared on 2026-08-30), kept verbatim below the docstring. It is
here because it VERIFIED, not because he said so: run against our own
YUGIOH.img it produces a 90,112-byte image whose sha1 is
`77b6430db58439e9577533d4f4fa2762996cf6fc`, byte-identical to the copy he
shipped. Two independent discs, one extractor, the same bytes -- that is what
turns "his reference" into "a reference".

What it settles, against docs/DISC.txt. That file lists three open steps --
(a) find which archive holds the overlay, (b) work out the container format,
(c) extract exact bytes -- and calls a compressed image inside `SU.MRG` or
`WA_MRG.MRG` the live hypothesis. The archive is `/DATA/WA_MRG.MRG` and the
image is NOT compressed: it sits as seven identical raw copies, 235 sectors
apart, and the base EXE reserves 0x80146000-0x8015C000 and leaves it zeroed
(one stray non-zero byte in 90,112). So DISC.txt was right about the archive
family and wrong about the compression, and the reason `disc.py` could not see
it is worth writing down rather than guessing at: it measures instruction
density over whole archives, and the overlay is 90 KB of code inside a 36 MB
file.

The loader is case 7 of func_800171A8 -- which is still assembly here, and is
in candidates.py's own `dup-%hi` list.

Same bring-your-own-disc rule as SLUS_014.11: this reads YOUR disc and writes
a gitignored file. Nothing disc-derived is committed.

    .venv/bin/python tools_src/extract_overlay.py --disc YUGIOH.img
    .venv/bin/python tools_src/extract_overlay.py --disc YUGIOH.img \
        --expect-sha1 77b6430db58439e9577533d4f4fa2762996cf6fc

A separate build target would be needed to make anything of it: the overlay
cannot be a segment of config/slus01411.yaml, because the EXE's bytes there
are zero -- attaching it to the main oracle would make a build emitting
CORRECT overlay code go red and one emitting zeros stay green.
"""
import argparse, hashlib, struct, sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent

RAW_SECTOR = 2352      # MODE2/2352 raw image
DATA_OFF   = 24        # Mode2 Form1 user data starts here
DATA_LEN   = 2048

LOAD_BASE  = 0x80146000
IMAGE_LEN  = 0x16000    # from the loader itself: lui 0x1 / ori 0x6000

# module 0's first 0x14 bytes, then the effect-sequencer debug strings.
SIG_HEAD   = bytes.fromhex("18000000") + bytes.fromhex("00100000") * 3
SIG_STR    = b"Error:In Effect"


def sector(disc: bytes, lba: int) -> bytes:
    off = lba * RAW_SECTOR + DATA_OFF
    return disc[off:off + DATA_LEN]


def read_range(disc: bytes, lba: int, nbytes: int) -> bytes:
    out = bytearray()
    while len(out) < nbytes:
        out += sector(disc, lba)
        lba += 1
    return bytes(out[:nbytes])


def walk_iso(disc: bytes):
    """Yield (path, lba, size) for every file, via the PVD at LBA 16."""
    pvd = sector(disc, 16)
    if pvd[1:6] != b"CD001":
        sys.exit("not an ISO9660 disc image (no CD001 at LBA 16) -- "
                 "is this a MODE2/2352 .bin?")
    root = pvd[156:156 + 34]
    yield from _walk_dir(disc, struct.unpack("<I", root[2:6])[0],
                         struct.unpack("<I", root[10:14])[0], "")


def _walk_dir(disc, lba, size, prefix):
    data = read_range(disc, lba, size)
    i = 0
    while i < len(data):
        rlen = data[i]
        if rlen == 0:
            i = (i // DATA_LEN + 1) * DATA_LEN     # next sector
            continue
        rec = data[i:i + rlen]
        ext = struct.unpack("<I", rec[2:6])[0]
        sz = struct.unpack("<I", rec[10:14])[0]
        flags = rec[25]
        nlen = rec[32]
        name = rec[33:33 + nlen].decode("latin-1").split(";")[0]
        i += rlen
        if nlen == 1 and rec[33] in (0, 1):
            continue                                 # "." / ".."
        path = prefix + "/" + name
        if flags & 0x02:
            yield from _walk_dir(disc, ext, sz, path)
        else:
            yield path, ext, sz


def find_modules(disc: bytes, lba: int, size: int):
    """Sector-aligned scan of one archive for the overlay module header."""
    hits = []
    for s in range(lba, lba + (size + DATA_LEN - 1) // DATA_LEN):
        d = sector(disc, s)
        if d[:len(SIG_HEAD)] == SIG_HEAD and SIG_STR in d[:0x100]:
            hits.append(s)
    return hits


def main():
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--disc", default=str(ROOT / "YUGIOH.img"), help="path to your own .bin (MODE2/2352)")
    ap.add_argument("--out", default=str(ROOT / "duel_overlay.bin"))
    ap.add_argument("--module", type=int, default=0,
                    help="which of the 7 identical disc copies (default 0)")
    ap.add_argument("--expect-sha1", default=None,
                    help="fail unless the extracted image hashes to this")
    ap.add_argument("--list", action="store_true", help="list the disc's files and exit")
    args = ap.parse_args()

    disc = Path(args.disc).read_bytes()
    if len(disc) % RAW_SECTOR:
        sys.exit(f"{args.disc}: not a multiple of {RAW_SECTOR} bytes; "
                 "this reads raw MODE2/2352 images only")

    files = list(walk_iso(disc))
    if args.list:
        for p, l, s in files:
            print(f"  {s:>10}  LBA {l:>7}  {p}")
        return

    arc = [f for f in files if f[0].upper().endswith("/WA_MRG.MRG")]
    if not arc:
        sys.exit("no /DATA/WA_MRG.MRG on this disc")
    path, lba, size = arc[0]
    print(f"{path}: LBA {lba}, {size} bytes")

    mods = find_modules(disc, lba, size)
    if not mods:
        sys.exit("no overlay module header found in WA_MRG.MRG")
    stride = mods[1] - mods[0] if len(mods) > 1 else 0
    print(f"overlay modules: {len(mods)} copies at LBA "
          f"{'/'.join(str(m) for m in mods)}"
          + (f" (stride {stride} sectors)" if stride else ""))
    if not 0 <= args.module < len(mods):
        sys.exit(f"--module must be 0..{len(mods) - 1}")

    img = read_range(disc, mods[args.module], IMAGE_LEN)
    sha = hashlib.sha1(img).hexdigest()
    print(f"resident image: {LOAD_BASE:#010x}-{LOAD_BASE + IMAGE_LEN:#010x} "
          f"({IMAGE_LEN} bytes)  sha1 {sha}")
    if args.expect_sha1 and sha != args.expect_sha1:
        sys.exit(f"MISMATCH: expected {args.expect_sha1}")
    Path(args.out).write_bytes(img)
    print(f"wrote {args.out}")


if __name__ == "__main__":
    main()
