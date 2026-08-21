#include "common.h"

void func_8003BF00(u8 *p, s32 mode) {
    u8 *e;
    s32 b;
    s32 v;
    s32 m;
    s32 q;

    e = p;

    switch (mode) {
    case 0:
        *(s32 *)(e + 0x1C) = 0x3000;
        m = 0xFFDCFFFF;
        v = D_8009B0F4;
        v &= m;
        q = (s32)D_800101D8;
        goto tail;

    case 1:
        m = 0xFFDCFFFF;
        *(s32 *)(e + 0x1C) = 0x43000;
        v = D_8009B0F4;
        v &= m;
        q = (s32)D_80010000;
        goto tail;

    case 2:
        *(s32 *)(e + 0xC) = (s32)D_801AF000;
        *(s32 *)(e + 8) = (s32)D_801AF000;
        *(s32 *)(e + 0x1C) = 0x800;
        m = 0xFFDCFFFF;
        D_8009B0F4 &= m;
        e[0x46] = 1;
        break;

    case 3:
        *(s16 *)(e + 0x30) = 0x1C0;
        *(s16 *)(e + 0x32) = 0x100;
        *(s16 *)(e + 4) = 0x40;
        *(s16 *)(e + 6) = 0x10;
        m = 0xFFDDFFFF;
        D_8009B0F4 &= m;
        D_8009B0F4 |= 0x10000;
        e[0x46] = 2;
        b = D_8009B118;
        *(s32 *)(e + 0x1C) = 0x8000;
        *(s32 *)(e + 8) = b;
        b += 0x800;
        *(s32 *)(e + 0xC) = b;
        break;

    case 4:
        *(s32 *)(e + 0x1C) = 0x800;
        m = 0xFFDCFFFF;
        v = D_8009B0F4;
        v &= m;
        q = D_8009B118;
    tail:
        D_8009B0F4 = v;
        *(s32 *)(e + 0xC) = q;
        *(s32 *)(e + 8) = q;
        e[0x46] = 1;
        break;

    case 5:
        b = D_8009B118;
        *(s16 *)(e + 0) = 0x100;
        *(s16 *)(e + 4) = 0x100;
        *(s16 *)(e + 2) = 0xF0;
        *(s16 *)(e + 6) = 4;
        func_80081DE8(p, b);
        break;
    }
}
