#include "common.h"

void func_800245EC(u8 *p, s32 mode) {
    s16 *q;
    s32 v;

    q = *(s16 **)(p + 0x38);

    if (mode == 0) {
        *(s32 *)(p + 0x1C) = 0x800;
        *(u16 *)(p + 0x30) = *(u16 *)q;
        D_8009B0F4 &= 0xFFDCFFFF;
        p[0x46] = 1;
        v = *(s32 *)(p + 0x3C);
        *(s32 *)(p + 0xC) = v;
        *(s32 *)(p + 8) = v;
        return;
    }

    if (mode == 1) {
        q++;
        *(s16 **)(p + 0x38) = q;
        *(s32 *)(p + 0x3C) = *(s32 *)(p + 0x3C) + 0x580;
    }

    v = *(u16 *)(p + 0x30) + 1;
    *(u16 *)(p + 0x30) = v;

    if ((v & 0xFFFF) == *q) {
        *(s32 *)(p + 0x1C) = 0x800;
        D_8009B0F4 &= 0xFFDCFFFF;
        *(s32 *)(p + 0x40) = 1;
        v = *(s32 *)(p + 0x3C);
        *(s32 *)(p + 0xC) = v;
        *(s32 *)(p + 8) = v;
        p[0x46] = 1;
        return;
    }

    *(s32 *)(p + 0x1C) = 0x800;
    D_8009B0F4 &= 0xFFFCFFFF;
    *(s32 *)(p + 0x40) = 2;
    D_8009B0F4 |= 0x200000;
    p[0x46] = 1;
}
