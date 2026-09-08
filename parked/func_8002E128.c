/* 146/146, censo VAZIO, 5 differing (2026-09-08). BEST THIS FUNCTION HAS EVER
 * BEEN -- the August park recorded 8 as its floor. src/ holds an ASSEMBLY-DEBT
 * transcription (Unchiga's port) with a 24-instruction `__asm__` block and
 * pins on s0/s1; the 8-difference C was never saved when that port replaced
 * it, and only its recipe survived in the PARKED.txt entry above.
 * gp=0, at=0, no addressing work.
 *
 * Rebuilt from the m2c draft, 36 -> 5, and every step is a rule already in
 * WORKFLOW:
 *   - the +0x3C field is a HALFWORD. The draft stored it through `s32` and
 *     the CENSUS read `lw +1, sw +2, sh -2, lh -1`; `*(s16 *)` there and on
 *     `p + 4` is 36 -> 34 -> 33 with an empty census. Nothing in the
 *     difference count pointed at either.
 *   - `n` is REUSED for the decoded BCD index (`n = ((n >> 4) & 0xF) * 10 +
 *     (n & 0xF);`), which is what retail's `addu $s1,$v1,$v0` says -- it
 *     writes the index back into the argument's register. 33 -> 22, and all
 *     three placements of the decode score the same, so the NAME is the
 *     lever and the position is not.
 *   - `p[0x10] = 1;` goes BELOW the two read-modify-writes. 22 -> 14. The
 *     August entry says "above ... (22 -> 19)" and that was measured on a
 *     base without the `n` reuse; on this base above is 22 and below is 14.
 *   - the D_80090BA8 base local is assigned AFTER the else branch's index,
 *     not before: 14 -> 9. Before it is 14 again.
 *   - and the else index is `s32 k`, not `s16 k`: 9 -> 5. The August entry
 *     records `s16` as 8 and `s32` as 19 -- both measured while the three
 *     faults above were open, which is why the sequence inverted. A spelling
 *     rejected on a broken base has not been measured.
 *
 * Measured and DEAD: dropping the D_80090BA8 base local entirely (+4/145, it
 * is load-bearing); `u8 m`, `s16 m`, and the flag read as `*(u8 *)(b + k*2)`
 * (all 9 on that base); four declaration orders and a named entry pointer
 * (all 9); borrowing the other arm's `t` (+2/145) or `o` (35) for the table.
 *
 * Residue is FIVE instructions and one register pair: retail keeps the table
 * pointer in $s0 and the flag byte in $s1, and we have them exchanged.
 * Permuter next. The debt is NOT retired until this matches.
 */
#include "common.h"

void func_8002E128(u8 *p, s32 arg1) {
    s32 n;
    u8 *o;
    u8 *t;
    u8 *b;
    s32 k;
    s32 m;

    n = arg1;
    if (n < 0) {
        n = *(s16 *)(p + 0x3C);
    }
    *(s16 *)(p + 0x3C) = n;
    if (n >= 0x200) {
        o = func_800400AC(func_8004002C(), 3);
        func_80040510(o, 0, 0, 0x200, 0x100, 0, 0, 0x10, 0, 0xF0);
        n = ((n >> 4) & 0xF) * 10 + (n & 0xF);
        *(s32 *)(o + 4) |= 0x1000000;
        *(u16 *)(o + 8) &= 0xFFF7;
        p[0x10] = 1;
        *(s32 *)p = (s32)o;
        t = &D_80090C00[n * 6];
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
            k = ((n >> 4) & 0xF) * 10 + (n & 0xF);
            b = D_80090BA8;
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
