#include "common.h"

void func_8003B808(u8 *p, s32 mode) {
    s32 v;
    s32 w;
    s32 d;

    switch (mode) {
    case 0:
        *(s16 *)(p + 0x32) = 0x100;
        v = D_8009B0F4;
        *(s16 *)(p + 0x30) = 0;
        *(s16 *)(p + 4) = 0x40;
        v &= 0xFFDDFFFF;
        D_8009B0F4 = v;
        w = D_8009B0F4;
        *(s32 *)(p + 0x1C) = 0x10000;
        w |= 0x10000;
        D_8009B0F4 = w;
        p[0x46] = 2;
        d = D_8009B118;
        *(s16 *)(p + 6) = 0x10;
        *(s32 *)(p + 8) = d;
        *(s32 *)(p + 0xC) = d + 0x800;
        break;

    case 1:
        *(s32 *)(p + 0x1C) = 0x800;
        v = D_8009B0F4;
        v &= 0xFFDCFFFF;
        D_8009B0F4 = v;
        *(s32 *)(p + 0xC) = D_8009B118;
        *(s32 *)(p + 8) = D_8009B118;
        p[0x46] = 1;
        break;

    case 2:
        *(s16 *)(p + 2) = 0xF0;
        *(s16 *)(p + 4) = 0x100;
        *(s16 *)p = 0;
        *(s16 *)(p + 6) = 4;
        func_80081DE8(p, D_8009B118);
        *(s32 *)(p + 0xC) = (s32)D_801AF000;
        *(s32 *)(p + 8) = (s32)D_801AF000;
        *(s32 *)(p + 0x1C) = 0x800;
        v = D_8009B0F4;
        v &= 0xFFDCFFFF;
        D_8009B0F4 = v;
        p[0x46] = 1;
        break;

    case 3:
        *(s32 *)(p + 0x1C) = 0x18000;
        v = D_8009B0F4;
        v &= 0xFFDCFFFF;
        D_8009B0F4 = v;
        *(s32 *)(p + 0xC) = (s32)D_80010000;
        *(s32 *)(p + 8) = (s32)D_80010000;
        p[0x46] = 1;
        break;

    case 4:
        *(s32 *)(p + 0x1C) = 0x2800;
        v = D_8009B0F4;
        v &= 0xFFDCFFFF;
        D_8009B0F4 = v;
        *(s32 *)(p + 0xC) = (s32)D_800101D8;
        *(s32 *)(p + 8) = (s32)D_800101D8;
        p[0x46] = 1;
        break;
    }
}
