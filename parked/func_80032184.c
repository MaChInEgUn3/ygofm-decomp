#include "common.h"

void func_80032184(u8 *p, s32 mode) {
    s32 one;
    s32 w;
    s32 v;
    s32 t;

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
    *(s16 *)(p + 0x30) = 0x300;
    *(s16 *)(p + 0x32) = 0x100;
    *(s16 *)(p + 4) = 0x40;
    t = D_8009B0F4;
    *(s16 *)(p + 6) = 0x10;
    D_8009B0F4 = t & 0xFFDDFFFF;
    D_8009B0F4 = D_8009B0F4 | 0x10000;
    p[0x46] = 2;
    v = D_8009B118;
    w = 0x20000;
    *(s32 *)(p + 0x1C) = w;
    *(s32 *)(p + 8) = v;
    v += 0x800;
    *(s32 *)(p + 0xC) = v;
    return;

m1:
    *(s16 *)(p + 0x30) = 0x340;
    *(s16 *)(p + 4) = 0x40;
    t = D_8009B0F4;
    *(s16 *)(p + 6) = 0x10;
    D_8009B0F4 = t & 0xFFDDFFFF;
    *(s16 *)(p + 0x32) = 0;
    D_8009B0F4 = D_8009B0F4 | 0x10000;
    p[0x46] = 2;
    v = D_8009B118;
    w = 0x4000;
    *(s32 *)(p + 0x1C) = w;
    *(s32 *)(p + 8) = v;
    v += 0x800;
    *(s32 *)(p + 0xC) = v;
    return;

m2:
    *(s32 *)(p + 0x1C) = 0x2000;
    D_8009B0F4 = D_8009B0F4 & 0xFFDCFFFF;
    *(s32 *)(p + 0xC) = D_8009B118;
    *(s32 *)(p + 8) = D_8009B118;
    p[0x46] = 1;
    return;

m3:
    D_800E9D70[0] = 0x100;
    D_800E9D70[1] = 0xF0;
    D_800E9D70[2] = 0x100;
    D_800E9D70[3] = 0x10;
    func_80081DE8(D_800E9D70, D_8009B118, p, 1);
}
