/* 146/146, censo VAZIO, 33 differing (2026-09-08). REBUILT: src/ holds an
 * ASSEMBLY-DEBT transcription (Unchiga's port) with a 24-instruction
 * `__asm__` block and register pins on s0/s1; the 8-difference C this tree
 * reached on 2026-08-21 was never saved when that port replaced it, and only
 * its recipe survived in the PARKED.txt entry above. This is that recipe
 * rebuilt from the m2c draft; it is not yet back to 8.
 * gp=0, at=0, no addressing work.
 *
 * The five recorded levers are all in and were NOT enough by themselves --
 * `s32 arg1` rather than s16, the else branch's flag byte in its own name
 * `m`, `p[0x10] = 1;` above the two read-modify-writes, a base local for
 * D_80090BA8, and the else branch's index as a fresh `s16 k`.
 *
 * What the old entry does not record, and what the CENSUS found in one read:
 * the +0x3C field is a HALFWORD. The first draft stored it `*(s32 *)` and
 * censused `lw +1, sw +2, sh -2, lh -1`; `*(s16 *)(p + 0x3C)` is 36 -> 34 and
 * `*(s16 *)(p + 4) = 0` is 34 -> 33 with an EMPTY census. Nothing in the
 * difference count pointed at either.
 *
 * Residue is ordering: retail runs the whole BCD decode before `p[0x10] = 1`
 * and the two read-modify-writes, and we emit the stores first. Measured and
 * DEAD, three spellings all 33: the table address hoisted above `p[0x10]`,
 * hoisted to just after the func_80040510 call, and the index split into its
 * own `s16 j` first. gcc reorders the block whatever the source order, so
 * this is the wrong axis and the next one is naming or widths inside the
 * two read-modify-writes. The debt is NOT retired until this matches.
 */
#include "common.h"

void func_8002E128(u8 *p, s32 arg1) {
    s32 n;
    u8 *o;
    u8 *t;
    u8 *b;
    s16 k;
    s32 m;

    n = arg1;
    if (n < 0) {
        n = *(s16 *)(p + 0x3C);
    }
    *(s16 *)(p + 0x3C) = n;
    if (n >= 0x200) {
        o = func_800400AC(func_8004002C(), 3);
        func_80040510(o, 0, 0, 0x200, 0x100, 0, 0, 0x10, 0, 0xF0);
        p[0x10] = 1;
        *(s32 *)(o + 4) |= 0x1000000;
        *(u16 *)(o + 8) &= 0xFFF7;
        *(s32 *)p = (s32)o;
        t = &D_80090C00[(((n >> 4) & 0xF) * 10 + (n & 0xF)) * 6];
        *(s16 *)(p + 4) = 0;
        if (t[0] & 1) {
            func_8002E060(p + 0x14, 0x14, 1);
            *(s16 *)(*(s32 *)(p + 0x14) + 0x30) = t[1];
            *(s16 *)(*(s32 *)(p + 0x14) + 0x32) = t[2];
        }
        if (t[0] & 2) {
            func_8002E060(p + 0x28, 0x16, 2);
            *(s16 *)(*(s32 *)(p + 0x28) + 0x30) = t[3];
            *(s16 *)(*(s32 *)(p + 0x28) + 0x32) = t[4];
            *(s16 *)(p + 0x2C) = t[5];
            if (t[0] & 0x80) {
                *(u16 *)(*(s32 *)(p + 0x28) + 8) |= 8;
            }
        }
    } else {
        func_8002E060(p, 0x10, 0);
        if (n >= 0x100) {
            b = D_80090BA8;
            k = ((n >> 4) & 0xF) * 10 + (n & 0xF);
            m = b[k * 2];
            if (m & 1) {
                func_8002E060(p + 0x14, 0x12, 1);
            }
            if (m & 2) {
                func_8002E060(p + 0x28, 0x14, 2);
                *(s16 *)(p + 0x2C) = b[k * 2 + 1];
            }
        } else {
            *(s32 *)(p + 0x14) = 0;
            *(s32 *)(p + 0x28) = 0;
        }
    }
}
