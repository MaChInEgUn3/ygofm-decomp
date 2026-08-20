#include "common.h"

void func_8003BD14(u8 *p, s32 mode) {
    s32 one;
    u8 *q;
    s32 m;
    s32 t;
    s32 v;

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
    *(s32 *)(p + 0x1C) = 0x20000;
    *(s32 *)(p + 8) = v;
    v += 0x800;
    *(s32 *)(p + 0xC) = v;
    return;

m1:
    *(s32 *)(p + 0x1C) = 0x2000;
    q = (u8 *)D_8009B118;
    m = D_8009B0F4 & 0xFFDCFFFF;
    goto join;

m2:
    *(s16 *)(p + 2) = 0xF0;
    *(s16 *)(p + 0) = 0x100;
    *(s16 *)(p + 4) = 0x100;
    *(s16 *)(p + 6) = 0x10;
    func_80081DE8(p, D_8009B118);
    *(s32 *)(p + 0xC) = (s32)D_801A8000;
    *(s32 *)(p + 8) = (s32)D_801A8000;
    *(s32 *)(p + 0x1C) = 0x1800;
    D_8009B0F4 = D_8009B0F4 & 0xFFDCFFFF;
    p[0x46] = 1;
    return;

m3:
    *(s32 *)(p + 0x1C) = 0x7800;
    q = D_800101D8;
    m = D_8009B0F4 & 0xFFDCFFFF;

join:
    D_8009B0F4 = m;
    *(s32 *)(p + 0xC) = (s32)q;
    *(s32 *)(p + 8) = (s32)q;
    p[0x46] = one;
}
