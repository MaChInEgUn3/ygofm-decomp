#define D_8009B0F4_SIZED
#include "common.h"

void func_8003C328(u8 *p, s32 mode) {
    s32 one;
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
    return;

m0:
    *(s16 *)(p + 0x32) = 0x100;
    t = D_8009B0F4[0];
    *(s16 *)(p + 4) = 0x40;
    D_8009B0F4[0] = t & 0xFFDDFFFF;
    *(s16 *)(p + 0x30) = 0;
    *(s32 *)(p + 0x1C) = 0x18000;
    D_8009B0F4[0] = D_8009B0F4[0] | 0x10000;
    p[0x46] = 2;
    v = D_8009B118;
    *(s16 *)(p + 6) = 0x10;
    *(s32 *)(p + 8) = v;
    v += 0x800;
    *(s32 *)(p + 0xC) = v;
    return;

m1:
    *(s32 *)(p + 0x1C) = 0x800;
    D_8009B0F4[0] = D_8009B0F4[0] & 0xFFDCFFFF;
    *(s32 *)(p + 0xC) = D_8009B118;
    *(s32 *)(p + 8) = D_8009B118;
    goto tail;

m2:
    *(s16 *)(p + 2) = 0xF0;
    *(s16 *)(p + 4) = 0x100;
    *(s16 *)(p + 0) = 0;
    *(s16 *)(p + 6) = 4;
    func_80081DE8(p, D_8009B118);
    *(s32 *)(p + 0xC) = (s32)D_801AF000;
    *(s32 *)(p + 8) = (s32)D_801AF000;
    *(s32 *)(p + 0x1C) = 0x800;
    D_8009B0F4[0] = D_8009B0F4[0] & 0xFFDCFFFF;

tail:
    p[0x46] = one;
}
