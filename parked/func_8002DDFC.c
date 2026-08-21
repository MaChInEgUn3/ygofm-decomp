#include "common.h"

void func_8002DDFC(u8 *p, s32 mode) {
    s32 m;

    if (mode == 1) {
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
    *(s16 *)(p + 4) = 0x40;
    m = 0xFFDDFFFF;
    D_8009B0F4 &= m;
    *(s16 *)(p + 6) = 0x10;
    *(s16 *)(p + 0x30) = 0;
    D_8009B0F4 |= 0x10000;
    p[0x46] = 2;
    *(s32 *)(p + 0x1C) = *(s32 *)(p + 0x38) << 11;
    *(s32 *)(p + 8) = D_8009B118;
    *(s32 *)(p + 0xC) = D_8009B118 + 0x800;
    return;

m1:
    *(s32 *)(p + 0x1C) = 0x800;
    m = 0xFFDCFFFF;
    D_8009B0F4 &= m;
    *(s32 *)(p + 0xC) = D_8009B118;
    *(s32 *)(p + 8) = D_8009B118;
    p[0x46] = 1;
    return;

m2:
    *(s16 *)(p + 2) = 0xF0;
    *(s16 *)(p + 4) = 0x100;
    *(s16 *)(p + 0) = 0;
    *(s16 *)(p + 6) = 4;
    func_80081DE8(p, D_8009B118);
}
