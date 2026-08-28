#include "common.h"

void func_80057544(u8 *p, s32 mode) {
    s16 a[4];
    s16 b[4];
    u8 *q;
    s32 m;
    s32 t0;
    s32 t1;
    s32 t2;
    s32 t3;
    s32 t4;
    s32 d;
    s32 one;
    s32 two;

    switch (mode) {
    case 0:
        m = 0xFFDCFFFF;
        *(s32 *)(p + 0x1C) = 0x9000;
        t0 = D_8009B0F4;
        d = D_80010008;
        D_8009B0F4 = t0 & m;
        *(s32 *)(p + 0xC) = d;
        *(s32 *)(p + 8) = d;
        p[0x46] = 1;
        break;

    case 1:
        m = 0xFFDDFFFF;
        *(s16 *)(p + 0x30) = 0x200;
        *(s16 *)(p + 0x32) = 0x100;
        *(s16 *)(p + 4) = 0x40;
        t1 = D_8009B0F4;
        *(s16 *)(p + 6) = 0x10;
        D_8009B0F4 = t1 & m;
        D_8009B0F4 = D_8009B0F4 | 0x10000;
        p[0x46] = 2;
        d = D_8009B118;
        do {
            *(s32 *)(p + 0x1C) = 0x20000;
        } while (0);
        *(s32 *)(p + 8) = d;
        *(s32 *)(p + 0xC) = d + 0x800;
        break;

    case 2:
        m = 0xFFDCFFFF;
        *(s32 *)(p + 0xC) = (s32)D_801DD800;
        *(s32 *)(p + 8) = (s32)D_801DD800;
        t2 = D_8009B0F4;
        *(s32 *)(p + 0x1C) = 0x800;
        D_8009B0F4 = t2 & m;
        p[0x46] = 1;
        break;

    case 3:
        q = D_801DD800;
        a[0] = 0x200;
        a[1] = 0xF1;
        a[2] = 0x100;
        one = 1;
        a[3] = one;
        func_80081DE8(a, q);
        m = 0xFFDCFFFF;
        q = q - 0x800;
        t3 = D_8009B0F4;
        *(s32 *)(p + 0xC) = (s32)q;
        *(s32 *)(p + 8) = (s32)q;
        *(s32 *)(p + 0x1C) = 0x800;
        D_8009B0F4 = t3 & m;
        p[0x46] = one;
        break;

    case 4:
        b[0] = 0x200;
        b[1] = 0xF4;
        b[2] = 0x100;
        two = 2;
        b[3] = two;
        func_80081DE8(b, D_801DD000);
        do {
            m = 0xFFDDFFFF;
        } while (0);
        *(s16 *)(p + 0x30) = 0x380;
        t4 = D_8009B0F4;
        *(s16 *)(p + 0x32) = 0;
        *(s16 *)(p + 4) = 0x40;
        D_8009B0F4 = t4 & m;
        t4 = D_8009B0F4;
        m = 0x10000;
        *(s32 *)(p + 0x1C) = m;
        D_8009B0F4 = t4 | m;
        p[0x46] = two;
        d = D_8009B118;
        *(s16 *)(p + 6) = 0x10;
        *(s32 *)(p + 8) = d;
        *(s32 *)(p + 0xC) = d + 0x800;
        break;

    case 5:
        D_800F5694 = 1;
        break;
    }
}
