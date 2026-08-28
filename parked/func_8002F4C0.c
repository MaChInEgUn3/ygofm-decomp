#include "common.h"

void func_8002F4C0(u8 *p, s32 mode) {
    s32 one;
    s32 m;
    s32 n;
    s32 t0;
    s32 u0;
    s32 t1;
    s32 t2;
    s32 v0;
    s32 v1;

    one = 1;
    switch (mode) {
    case 0:
        m = 0xFFDDFFFF;
        n = 0x18000;
        *(s16 *)(p + 0x30) = 0x1C0;
        *(s16 *)(p + 0x32) = 0x100;
        t0 = D_8009B0F4;
        *(s16 *)(p + 4) = 0x40;
        D_8009B0F4 = t0 & m;
        u0 = D_8009B0F4;
        *(s32 *)(p + 0x1C) = n;
        D_8009B0F4 = u0 | 0x10000;
        p[0x46] = 2;
        v0 = D_8009B118;
        *(s16 *)(p + 6) = 0x10;
        *(s32 *)(p + 8) = v0;
        *(s32 *)(p + 0xC) = v0 + 0x800;
        break;

    case 1:
        m = 0xFFDCFFFF;
        *(s32 *)(p + 0x1C) = 0x800;
        t1 = D_8009B0F4;
        v1 = D_8009B118;
        D_8009B0F4 = t1 & m;
        *(s32 *)(p + 0xC) = v1;
        *(s32 *)(p + 8) = v1;
        goto join;

    case 2:
        *(s16 *)(p + 2) = 0xF4;
        *(s16 *)(p + 6) = mode;
        *(s16 *)p = 0;
        *(s16 *)(p + 4) = 0x100;
        func_80081DE8(p, D_8009B118);
        m = 0xFFDCFFFF;
        *(s32 *)(p + 0xC) = (s32)D_801AF000;
        *(s32 *)(p + 8) = (s32)D_801AF000;
        t2 = D_8009B0F4;
        *(s32 *)(p + 0x1C) = 0x800;
        D_8009B0F4 = t2 & m;
join:
        p[0x46] = one;
        break;
    }
}
