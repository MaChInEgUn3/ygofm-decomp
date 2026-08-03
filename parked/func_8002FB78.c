#include "common.h"

void func_8002FB78(u8 *p, s32 mode) {
    s32 v;
    s32 w;
    s32 t;

    switch (mode) {
    case 0:
        *(s16 *)(p + 0x30) = 0x340;
        *(s16 *)(p + 4) = 0x40;
        v = D_8009B0F4;
        *(s16 *)(p + 6) = 0x10;
        v &= 0xFFDDFFFF;
        D_8009B0F4 = v;
        w = D_8009B0F4;
        *(s16 *)(p + 0x32) = 0;
        w |= 0x10000;
        D_8009B0F4 = w;
        p[0x46] = 2;
        t = D_8009B118;
        *(s32 *)(p + 0x1C) = 0x8000;
        *(s32 *)(p + 8) = t;
        *(s32 *)(p + 0xC) = t + 0x800;
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
        *(s16 *)p = 0x100;
        *(s16 *)(p + 2) = 0xF0;
        *(s16 *)(p + 4) = 0x100;
        *(s16 *)(p + 6) = 1;
        func_80081DE8(p, D_8009B118);
        *(s32 *)(p + 0xC) = (s32)D_801A8000;
        *(s32 *)(p + 8) = (s32)D_801A8000;
        *(s32 *)(p + 0x1C) = 0x1000;
        v = D_8009B0F4;
        v &= 0xFFDCFFFF;
        D_8009B0F4 = v;
        p[0x46] = 1;
        break;

    case 3:
        *(s32 *)(p + 0x1C) = 0xF000;
        v = D_8009B0F4;
        t = D_80010000;
        v &= 0xFFDCFFFF;
        D_8009B0F4 = v;
        *(s32 *)(p + 0xC) = t;
        *(s32 *)(p + 8) = t;
        p[0x46] = 1;
        break;
    }
}
