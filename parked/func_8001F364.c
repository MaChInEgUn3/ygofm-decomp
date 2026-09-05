/* 14 -> 6 (2026-09-05, permuter, 5275 iterations): a second do/while(0)
 * nested inside the arm pin, round the `return 1;` after m0 through the end
 * of m2 -- semantically nothing, and both dispatcher delay slots come right.
 * The 6 left: the D_8015C424 base local and the D_8009B1B8 index exchanged
 * in $v1/$a1; the index named before or after the base, the sum regrouped,
 * and the scaled index named (+1) all stay at 6.
 * 2026-09-05, still 14: the two dispatcher delay slots. Retail fills the
 * `v < 2` branch's slot with the >=2 block's own first instruction (addiu 2)
 * and the `v == 0` branch's slot with the fall-through's `addiu $v0,1`; we
 * leave the first a nop and hoist m0's `addiu $a0,0x10` into the second, so
 * gcc predicts the second branch taken where retail's did not. An explicit
 * `if (v >= 2) goto hi;` with the >=2 block written after the return, and the
 * nested if/else form, are both 14 -- the layout is already retail's, the
 * filler's thread choice is what differs. Permuter next. */
#include "common.h"

s32 func_8001F364(void) {
    u8 *e;
    u8 *g;
    u8 *p;
    u8 *q;
    u8 *r;
    s32 one;
    s32 v;
    u16 t;

    if (D_8009B162 != 0) {
        return 1;
    }

    one = 1;
    v = D_8009B210 & 0xF;

    if (v == one) {
        goto m1;
    }
    if (v < 2) {
        if (v == 0) {
            goto m0;
        }
        return 1;
    }
    if (v == 2) {
        goto m2;
    }
    if (v == 3) {
        goto m3;
    }

    do {
    return 1;

m0:
    func_80022D94(0x10, 0x208, 0x200, D_800F284A[0],
                  0xB2 - D_8009B1D5 * 0x164);
    D_8009B162 = 0x10;
    D_8009B210 = one;
    D_8009B1D0 = 0x14;
    do {
    return 1;

m1:
    t = D_8009B1D0 - 1;
    D_8009B1D0 = t;
    if ((s16)t <= 0) {
    r = D_8015C424;
    g = r + D_8009B1B8 * 0x1C + 0x48000;
    p = *(u8 **)(g + 0x36B4);
    e = func_8002C68C(8);
    *(u16 *)(e + 0) = *(u16 *)(p + 0x30);
    *(u16 *)(e + 2) = *(u16 *)(p + 0x32);
    *(u16 *)(e + 4) = *(u16 *)(p + 0x34);
    func_80024954(D_801A7AD8 + p[0x6A] * 0x1C);
    func_8003FEE0(0x17);
    D_8009B210 = 2;
    }
    return 1;

m2:
    func_80022D94(0x10, 0x258, 0x100, D_800F284A[0], 0);
    D_8009B162 = 0x10;
    D_8009B210 = 3;
    D_8009B1D0 = 0x14;
    } while (0);
    } while (0);
    return 1;

m3:
    t = D_8009B1D0 - 1;
    D_8009B1D0 = t;
    if ((s16)t > 0) {
        return 1;
    }
    q = (u8 *)D_800E9FF0 + (D_8009B1D5 ^ 1) * 0x20;
    q[6] = q[6] + 1;
    return 0;
}
