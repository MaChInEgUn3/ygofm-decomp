#include "common.h"

void func_8003A01C(u8 *p, s32 mode) {
    s32 v;
    s32 w;
    s32 n;
    s32 b;
    s32 t;

    switch (mode) {
    case 0:
        v = D_8009B0F4;
        *(s32 *)(p + 0x1C) = 0x18000;
        n = *(s32 *)(p + 0x3C);
        *(s16 *)(p + 0x32) = 0x100;
        *(s16 *)(p + 4) = 0x40;
        *(s16 *)(p + 6) = 0x10;
        v &= 0xFFDDFFFF;
        D_8009B0F4 = v;
        w = D_8009B0F4;
        w |= 0x10000;
        D_8009B0F4 = w;
        p[0x46] = 2;
        b = D_8009B118;
        *(s16 *)(p + 0x30) = 0x340 - n * 192;
        *(s32 *)(p + 8) = b;
        *(s32 *)(p + 0xC) = b + 0x800;
        break;

    case 1:
        *(s32 *)(p + 0x1C) = 0x800;
        v = D_8009B0F4;
        t = D_8009B118;
        v &= 0xFFDCFFFF;
        D_8009B0F4 = v;
        *(s32 *)(p + 0xC) = t;
        *(s32 *)(p + 8) = t;
        p[0x46] = 1;
        break;

    case 2:
        *(s16 *)p = 0x200;
        *(s16 *)(p + 6) = 2;
        *(s16 *)(p + 4) = 0x100;
        *(s16 *)(p + 2) = *(s32 *)(p + 0x3C) * 2 + 0xF0;
        func_80081DE8(p, D_8009B118);
        *(s32 *)(p + 0x1C) = 0x800;
        v = D_8009B0F4;
        t = *(s32 *)(p + 0x38);
        v &= 0xFFDCFFFF;
        D_8009B0F4 = v;
        *(s32 *)(p + 0xC) = t;
        *(s32 *)(p + 8) = t;
        p[0x46] = 1;
        break;
    }
}
