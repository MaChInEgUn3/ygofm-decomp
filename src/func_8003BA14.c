#include "common.h"

void func_8003BA14(u8 *p, s32 mode) {
    s32 one;
    s32 v;
    s32 w;
    s32 d;
    s32 m;
    s32 v2;
    s32 w2;
    s32 d2;
    s32 k;
    s32 c;
    s32 hun;
    s32 n;
    s32 x;
    u8 *y;

    one = 1;

    if (mode == one) {
        goto m1;
    }
    if (mode < 2) {
        if (mode == 0) {
            goto m0;
        }
        return;
    }
    if (mode == 2) {
        goto m2;
    }
    if (mode == 3) {
        goto m3;
    }
    return;

m0:
    m = 0xFFDDFFFF;
    do {
        k = 0x18000;
    } while (0);
    c = 0x100;
    *(s16 *)(p + 0x30) = c;
    *(s16 *)(p + 0x32) = c;
    v = D_8009B0F4;
    *(s16 *)(p + 4) = 0x40;
    D_8009B0F4 = v & m;
    w = D_8009B0F4;
    n = 0x10000;
    do {
        *(s32 *)(p + 0x1C) = k;
        D_8009B0F4 = w | n;
        p[0x46] = 2;
        d = D_8009B118;
        *(s16 *)(p + 6) = 0x10;
    } while (0);
    *(s32 *)(p + 8) = d;
    *(s32 *)(p + 0xC) = d + 0x800;
    return;

m1:
    *(s16 *)(p + 0x30) = 0x1C0;
    *(s16 *)(p + 0x32) = 0x100;
    *(s16 *)(p + 4) = 0x40;
    v2 = D_8009B0F4;
    *(s16 *)(p + 6) = 0x10;
    D_8009B0F4 = v2 & 0xFFDDFFFF;
    w2 = D_8009B0F4;
    D_8009B0F4 = w2 | 0x10000;
    p[0x46] = 2;
    d2 = D_8009B118;
    *(s32 *)(p + 0x1C) = 0x8000;
    *(s32 *)(p + 8) = d2;
    *(s32 *)(p + 0xC) = d2 + 0x800;
    return;

m2:
    m = 0xFFDCFFFF;
    *(s32 *)(p + 0x1C) = 0x800;
    x = D_8009B0F4 & m;
    y = (u8 *)D_8009B118;
    goto tail;

m3:
    do {
        hun = 0x100;
    } while (0);
    *(s16 *)(p + 2) = 0xF0;
    k = D_8009B118;
    *(s16 *)(p + 0) = hun;
    *(s16 *)(p + 4) = hun;
    *(s16 *)(p + 6) = 4;
    func_80081DE8(p, k);
    m = 0xFFDCFFFF;
    *(s32 *)(p + 0x1C) = 0x7800;
    x = D_8009B0F4 & m;
    y = D_800101D8;

tail:
    D_8009B0F4 = x;
    *(s32 *)(p + 0xC) = (s32)y;
    *(s32 *)(p + 8) = (s32)y;
    p[0x46] = one;
}
