#include "common.h"

void func_80020BE4(u8 *p, s32 mode) {
    s32 one;
    s32 v;
    s32 w;
    s32 e;
    s32 x;
    s32 m;
    s32 d;

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
    return;

m0:
    *(s16 *)(p + 0x32) = 0x100;
    *(s16 *)(p + 0x30) = 0;
    v = D_8009B0F4;
    *(s16 *)(p + 4) = 0x40;
    m = 0xFFDDFFFF;
    D_8009B0F4 = v & m;
    w = D_8009B0F4;
    m = 0x10000;
    *(s32 *)(p + 0x1C) = m;
    D_8009B0F4 = w | m;
    p[0x46] = 2;
    d = D_8009B118;
    *(s16 *)(p + 6) = 0x10;
    *(s32 *)(p + 8) = d;
    *(s32 *)(p + 0xC) = d + 0x800;
    return;

m1:
    *(s32 *)(p + 0x1C) = 0x800;
    D_8009B0F4 = D_8009B0F4 & 0xFFDCFFFF;
    *(s32 *)(p + 0xC) = D_8009B118;
    *(s32 *)(p + 8) = D_8009B118;
    goto tail;

m2:
    *(s16 *)(p + 2) = 0xF8;
    *(s16 *)(p + 4) = 0x100;
    e = D_8009B118;
    *(s16 *)(p + 0) = 0;
    *(s16 *)(p + 6) = 4;
    func_80081DE8(p, e);
    *(s32 *)(p + 0xC) = (s32)D_801AF000;
    *(s32 *)(p + 8) = (s32)D_801AF000;
    x = D_8009B0F4;
    *(s32 *)(p + 0x1C) = 0x800;
    D_8009B0F4 = x & 0xFFDCFFFF;

tail:
    p[0x46] = one;
}
