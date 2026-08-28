#include "common.h"

void func_80032184(u8 *p, s32 mode) {
    s32 one;
    s32 w;
    s32 v;
    s32 t0;
    s32 t1;
    s32 c;
    s32 n;
    s32 u;
    s16 *g;
    s32 m;
    s32 m2v;

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
    *(s16 *)(p + 0x30) = 0x300;
    *(s16 *)(p + 0x32) = 0x100;
    *(s16 *)(p + 4) = 0x40;
    t0 = D_8009B0F4;
    *(s16 *)(p + 6) = 0x10;
    D_8009B0F4 = t0 & m;
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
    m = 0xFFDDFFFF;
    *(s16 *)(p + 0x30) = 0x340;
    *(s16 *)(p + 4) = 0x40;
    t1 = D_8009B0F4;
    *(s16 *)(p + 6) = 0x10;
    D_8009B0F4 = t1 & m;
    u = D_8009B0F4;
    n = 0x10000;
    *(s16 *)(p + 0x32) = 0;
    D_8009B0F4 = u | n;
    p[0x46] = 2;
    v = D_8009B118;
    w = 0x4000;
    *(s32 *)(p + 0x1C) = w;
    *(s32 *)(p + 8) = v;
    v += 0x800;
    *(s32 *)(p + 0xC) = v;
    return;

m2:
    m2v = 0xFFDCFFFF;
    *(s32 *)(p + 0x1C) = 0x2000;
    D_8009B0F4 = D_8009B0F4 & m2v;
    *(s32 *)(p + 0xC) = D_8009B118;
    *(s32 *)(p + 8) = D_8009B118;
    p[0x46] = 1;
    return;

m3:
    g = D_800E9D70;
    c = 0x100;
    g[0] = c;
    g[1] = 0xF0;
    g[2] = c;
    g[3] = 0x10;
    func_80081DE8(g, D_8009B118);
}
