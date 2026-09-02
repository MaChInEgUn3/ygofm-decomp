#!/usr/bin/env python3
"""
Decoders for the fusion / equip / ritual / rank tables, derived by reading
the retail functions that index them:

  fusion  D_8017C2D8  read by checkFusion      func_80019A60  src/func_80019A60.c
  equip   D_8017A1D8  read by checkEquip       func_80019A08  src/func_80019A08.c
  ritual  D_801799D8  read by func_8002C7E8    (checkRitual)  src/func_8002C7E8.c
  rank    D_801798A8  read by rankScoreChange  func_80021558  src/func_80021558.c

NOT RUN as part of this extraction: at file offset (va - 0x8000F800) these
four ranges are all-zero in extracted/SLUS_014.11 (verified 2026-09-01;
see the extraction report). Terrain (D_800909D4) IS present statically and
was extracted directly -- see terrain.tsv.

This module exists so that whoever locates the real bytes (almost certainly
a CD-loaded resource, not static .data -- see docs/DISC.txt and the report
that shipped with this file) can decode them without re-deriving the record
formats. Pass it a `bytes` object containing the table starting at its own
byte 0 (i.e. slice the source so index 0 == the table's own base address).
"""
import struct


def decode_fusion(table: bytes, max_id: int = 1024):
    """table[0] is the byte at the fusion table's own base (was D_8017C2D8).

    Layout read from func_80019A60 (checkFusion):
      - u16 offset[max_id]  -- indexed by the SMALLER of the two card ids
                                (raw id, so index 0 is unused; ids are
                                1-based). offset==0 means "no fusions listed
                                for this id as the smaller partner".
      - at table+offset: a run of variable-length groups. Each group starts
        with a count byte `n`:
          * n == 0 (escape): real count = 0x1FF - table[offset+1]; the group
            header is 2 bytes instead of 1.
          * n != 0: n is the count directly; the group header is 1 byte.
        n counts in units of 2 (it decrements by 2 per 5-byte record and the
        group stops once n <= 0), so each 5-byte record packs TWO
        (partner, result) pairs:
          b       = record[0]   -- one byte packing four 2-bit hi-fields
          partner1 = ((b << 8) & 0x300) | record[1]   (bits 0-1 of b -> hi)
          result1  = ((b << 6) & 0x300) | record[2]   (bits 2-3 of b -> hi)
          partner2 = ((b << 4) & 0x300) | record[3]   (bits 4-5 of b -> hi)
          result2  = ((b << 2) & 0x300) | record[4]   (bits 6-7 of b -> hi)
        giving 10-bit ids (0-1023), room for the 722-card roster.

    Returns a list of (card_a, card_b, result) with card_a <= card_b as
    looked up (card_a is the offset-table index; card_b/result come from
    the packed record).
    """
    rows = []
    offs = struct.unpack('<%dH' % max_id, table[:max_id * 2])
    for card_a, off in enumerate(offs):
        if off == 0:
            continue
        p = off
        n = table[p]
        if n == 0:
            n = 0x1FF - table[p + 1]
            p += 1
        p += 1
        while n > 0:
            b = table[p]
            partner1 = ((b << 8) & 0x300) | table[p + 1]
            result1 = ((b << 6) & 0x300) | table[p + 2]
            partner2 = ((b << 4) & 0x300) | table[p + 3]
            result2 = ((b << 2) & 0x300) | table[p + 4]
            rows.append((card_a, partner1, result1))
            if n > 1:
                rows.append((card_a, partner2, result2))
            p += 5
            n -= 2
    return rows


def decode_equip(table: bytes):
    """table[0] is the byte at the equip table's own base (was D_8017A1D8).

    Layout read from func_80019A08 (checkEquip):
      repeat: u16 key; u16 n; u16 member[n];
      terminated by key == 0.
    checkEquip(equip_id, monster_id) succeeds if a group keyed by equip_id
    lists monster_id among its members. Returns one row per (key, member).
    """
    rows = []
    p = 0
    u16 = lambda o: struct.unpack_from('<H', table, o)[0]
    while True:
        key = u16(p)
        if key == 0:
            break
        n = u16(p + 2)
        p += 4
        for i in range(n):
            rows.append((key, u16(p + i * 2)))
        p += n * 2
    return rows


def decode_ritual(table: bytes):
    """table[0] is the byte at the ritual table's own base (was D_801799D8).

    Layout read from func_8002C7E8: 5x u16 records, terminated by key==0:
      u16 key; u16 tribute1; u16 tribute2; u16 tribute3; u16 trailing;
    tribute1..3 are matched against the field-record's offset+0xC (the
    "idxVal" field, confirmed elsewhere -- see func_800249E0.c -- to be the
    card's own 1-based id). `trailing` is what func_8002C7E8 returns.
    """
    rows = []
    p = 0
    u16 = lambda o: struct.unpack_from('<H', table, o)[0]
    while True:
        key = u16(p)
        if key == 0:
            break
        t1, t2, t3, trailing = u16(p + 2), u16(p + 4), u16(p + 6), u16(p + 8)
        rows.append((key, t1, t2, t3, trailing))
        p += 10
    return rows


def decode_rank(table: bytes, n_rows: int = 10, row_stride: int = 20):
    """table[0] is the byte at the rank table's own base (was D_801798A8).

    Layout read from func_80021558 (rankScoreChange) and confirmed against
    Unchiga's independent decomp (match/matched/func_80021558.c, same
    binary): row = arg0 * 20; each row is a run of {s16 threshold; s16
    value} 4-byte pairs, walked forward while arg1 >= threshold; the first
    pair whose threshold is > arg1 supplies the returned value.
    5 pairs/row is the declared shape (Threshold D_801798A8[][5] in
    include/variables.h) but the walk can stop earlier.
    """
    rows = []
    for r in range(n_rows):
        base = r * row_stride
        pairs = []
        for i in range(row_stride // 4):
            thr, val = struct.unpack_from('<hh', table, base + i * 4)
            pairs.append((thr, val))
        rows.append(pairs)
    return rows


if __name__ == '__main__':
    print(__doc__)
