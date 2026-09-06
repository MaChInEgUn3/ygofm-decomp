/* MATCH 2026-09-06. Parked at 14, then 6, both times as the dispatcher's
 * delay slots and one register pair; the permuter closed both. The arms sit
 * inside ONE do/while(0) pin round the region from m0's return through m2
 * (an outer pin round all the arms as well is 6, not a match), and the +4
 * halfword copy in m1 is written with the store address assigned INSIDE the
 * expression, `*(d = (u16 *)(e + 4)) = *(u16 *)q34;` with q34 = p + 0x34
 * named on the line above -- the same statement as two plain assignments is
 * 6. The 0x48000 base split (r local, then g = r + idx * 0x1C + 0x48000)
 * and the nested if in m1 rather than an early return are load-bearing too.
 */
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
    u8 *q34;
    u16 *d;

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
    q34 = p + 0x34;
    *(d = (u16 *)(e + 4)) = *(u16 *)q34;
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
