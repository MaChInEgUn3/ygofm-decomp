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
