/* MATCH 2026-09-05, pure C at default -O2 -G8 with the assembler at -G0
 * (PER_FUNC_AS_FLAGS). Replaces a transcription (asm reloads, register pins,
 * scheduling fences). Three loops of constant stores over D_8009B458 records
 * and one batch key-on of the OR-ed keys.
 *
 * Levers, in the order the residue gave them up:
 *   +2 -> 0/51  loop 2 (the one with calls) as a `goto` loop: gcc 2.8's loop
 *               pass runs only between for/while/do notes, so the literal 0x63
 *               is no longer hoisted into a seventh saved register
 *   51 -> 27    one pointer name per loop (r1, r3) rather than one `r`
 *   27 -> 20    loop 2 addressed off `base` itself, reloaded at the bottom
 *   20 -> 17    `tbl++; off += 0x28;` after the func_80076ED0 call
 *   17 -> 16    loop-3 constants named at their store widths (u8, u8, s32)
 *   16 -> 11    default -G8 / as -G0: D_80011434 as cc1psx's own pair
 *   11 ->  2    `do { } while (0);` round loop 2's guarded block (permuter;
 *               decomposed from a pin round the whole middle of the function)
 *    2 ->  0    the record address written INLINE at each store, `(base +
 *               off)[k]`, instead of assigned to base first (permuter): the
 *               CSE'd sum is scheduled after the call argument's copy, where
 *               a cursor assignment was scheduled before it.
 */
#include "common.h"

void func_8004A518(void) {
    u8 *base;
    u8 *r1;
    u8 *r3;
    s32 mask;
    s32 i;
    s32 o1;
    s32 off;
    s32 *tbl;
    s32 key;
    s32 k40;
    s32 c72;
    s32 cff;
    s32 one;
    s32 o18;
    u8 b40;
    u8 b7f;
    s32 w7f;

    mask = 0;
    i = mask;
    c72 = 0x72;
    one = 1;
    cff = 0xFF;
    o1 = 0x518;
    base = D_8009B458;
    *(s16 *)(base + 0x512) = 0x7F;
    do {
        r1 = D_8009B458 + o1;
        i++;
        *(s32 *)(r1 + 0) = 0;
        *(s32 *)(r1 + 4) = 0;
        r1[0x26] = 0;
        *(s32 *)(r1 + 0x1C) = 0;
        *(s32 *)(r1 + 8) = 0;
        *(s32 *)(r1 + 0xC) = 0;
        *(s16 *)(r1 + 0x14) = c72;
        *(s16 *)(r1 + 0x16) = c72;
        r1[0x24] = one;
        *(s32 *)(r1 + 0x10) = 0;
        *(s16 *)(r1 + 0x18) = 0;
        r1[0x27] = 0;
        r1[0x28] = cff;
        r1[0x29] = 0;
        r1[0x2B] = 0;
        o1 += 0x2C;
    } while (i < 16);

    do {
    base = D_8009B458;
    if (*(s16 *)(base + 0x510) > 0) {
        i = 0;
        k40 = 0x40;
        tbl = D_80011434;
        off = 0x180;
    top2:
            key = *tbl;
            (base + off)[3] = 0x63;
            (base + off)[0] = i;
            (base + off)[0xD] = 0;
            (base + off)[0xF] = 0;
            (base + off)[0xC] = 0x40;
            *(s16 *)(base + off + 0x1A) = k40;
            *(s16 *)(base + off + 0x1C) = k40;
            *(s16 *)(base + off + 0x1E) = 0;
            func_8004A764(i);
            func_80076ED0(0, key);
            tbl++;
            off += 0x28;
            base = D_8009B458;
            i++;
            mask |= key;
        if (i < *(s16 *)(base + 0x510)) goto top2;
    }
    } while (0);

    i = 0;
    b40 = 0x40;
    b7f = 0x7F;
    w7f = 0x7F;
    o18 = i;
    do {
        r3 = D_8009B458 + o18;
        i++;
        r3[1] = b40;
        r3[3] = b7f;
        r3[4] = 0;
        r3[5] = b7f;
        r3[7] = b40;
        *(s32 *)(r3 + 8) = w7f;
        *(s32 *)(r3 + 0xC) = w7f;
        r3[0x10] = 0;
        *(s16 *)(r3 + 0x14) = 0;
        r3[6] = 0;
        o18 += 0x18;
    } while (i < 16);

    func_80076ED0(0, mask);
}
