#include "common.h"

void func_80043328(u8 *p, s32 mode) {
    s32 one;
    s32 v;
    s32 q;
    s32 b;
    s32 m;

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
    *(s16 *)(p + 0x30) = 0x280;
    *(s16 *)(p + 4) = 0x40;
    m = 0xFFDDFFFF;
    D_8009B0F4 &= m;
    *(s16 *)(p + 0x32) = 0;
    b = 0x18000;
    *(s32 *)(p + 0x1C) = b;
    D_8009B0F4 |= 0x10000;
    p[0x46] = 2;
    q = D_8009B118;
    *(s16 *)(p + 6) = 0x10;
    *(s32 *)(p + 8) = q;
    q += 0x800;
    *(s32 *)(p + 0xC) = q;
    return;

m1:
    *(s32 *)(p + 0x1C) = 0x1000;
    m = 0xFFDCFFFF;
    v = D_8009B0F4 & m;
    q = D_8009B118;
    goto tail;

m2:
    b = D_8009B118;
    *(s16 *)(p + 0) = 0x200;
    *(s16 *)(p + 2) = 0xF8;
    *(s16 *)(p + 4) = 0x100;
    *(s16 *)(p + 6) = 8;
    func_80081DE8(p, b);
    *(s32 *)(p + 0x1C) = 0x800;
    m = 0xFFDCFFFF;
    v = D_8009B0F4 & m;
    q = D_8009B118 + 0x1000;
    goto tail;

m3:
    b = D_8009B118;
    *(s16 *)(p + 0) = 0x280;
    *(s16 *)(p + 2) = 0xE8;
    *(s16 *)(p + 4) = 0x10;
    *(s16 *)(p + 6) = 8;
    func_80081DE8(p, b + 0x1000);
    *(s32 *)(p + 0x1C) = 0x1800;
    m = 0xFFDCFFFF;
    v = D_8009B0F4 & m;
    q = (s32)D_800101D8;

tail:
    D_8009B0F4 = v;
    *(s32 *)(p + 0xC) = q;
    *(s32 *)(p + 8) = q;
    p[0x46] = one;
}
