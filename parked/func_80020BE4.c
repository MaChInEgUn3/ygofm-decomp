#include "common.h"

void func_80020BE4(u8 *p, s32 mode) {
    s32 v;

    switch (mode) {
    case 0:
        *(s16 *)(p + 0x32) = 0x100;
        v = D_8009B0F4;
        *(s16 *)(p + 0x30) = 0;
        *(s16 *)(p + 4) = 0x40;
        D_8009B0F4 = v & 0xFFDDFFFF;
        v = D_8009B0F4;
        *(s32 *)(p + 0x1C) = 0x10000;
        D_8009B0F4 = v | 0x10000;
        p[0x46] = 2;
        *(s16 *)(p + 6) = 0x10;
        *(s32 *)(p + 8) = D_8009B118;
        *(s32 *)(p + 0xC) = D_8009B118 + 0x800;
        break;

    case 1:
        *(s32 *)(p + 0x1C) = 0x800;
        D_8009B0F4 &= 0xFFDCFFFF;
        *(s32 *)(p + 0xC) = D_8009B118;
        *(s32 *)(p + 8) = D_8009B118;
        p[0x46] = 1;
        break;

    case 2:
        *(s16 *)(p + 2) = 0xF8;
        *(s16 *)(p + 4) = 0x100;
        *(s16 *)p = 0;
        *(s16 *)(p + 6) = 4;
        func_80081DE8(p, D_8009B118);
        *(s32 *)(p + 0xC) = (s32)D_801AF000;
        *(s32 *)(p + 8) = (s32)D_801AF000;
        *(s32 *)(p + 0x1C) = 0x800;
        D_8009B0F4 &= 0xFFDCFFFF;
        p[0x46] = 1;
        break;
    }
}
