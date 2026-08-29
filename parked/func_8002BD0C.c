#include "common.h"

void func_8002BD0C(u8 *p, s32 mode) {
    s16 *g;
    s32 m;
    s32 m2;
    s32 n;
    s32 n2;
    s32 n3;
    s32 d3;
    s32 d;
    s32 t;
    s32 t2;
    s32 d2;
    s32 hun;
    s32 hun2;
    s32 ten;

    switch (mode) {
    case 0:
        m = 0xFFDDFFFF;
        *(s16 *)(p + 0x30) = 0x300;
        *(s16 *)(p + 0x32) = 0x100;
        *(s16 *)(p + 4) = 0x40;
        t = D_8009B0F4;
        *(s16 *)(p + 6) = 0x10;
        D_8009B0F4 = t & m;
        D_8009B0F4 = D_8009B0F4 | 0x10000;
        p[0x46] = 2;
        d = D_8009B118;
        do {
            n = 0x20000;
        } while (0);
        goto join1;

    case 1:
        m2 = 0xFFDCFFFF;
        n2 = 0x2000;
        goto join2;

    case 2:
        g = D_800E9D70;
        hun = 0x100;
        g[0] = hun;
        ten = 0x10;
        g[1] = 0xF0;
        g[2] = hun;
        g[3] = ten;
        func_80081DE8(g, D_8009B118);
        m = 0xFFDDFFFF;
        n3 = 0x18000;
        t2 = D_8009B0F4;
        *(s16 *)(p + 0x30) = 0x240;
        *(s16 *)(p + 0x32) = hun;
        *(s16 *)(p + 6) = ten;
        *(s32 *)(p + 0x1C) = n3;
        D_8009B0F4 = t2 & m;
        D_8009B0F4 = D_8009B0F4 | 0x10000;
        p[0x46] = 2;
        d2 = D_8009B118;
        *(s16 *)(p + 4) = 0x40;
        *(s32 *)(p + 8) = d2;
        *(s32 *)(p + 0xC) = d2 + 0x800;
        break;

    case 4:
        g = D_800E9D70;
        hun2 = 0x100;
        g[0] = hun2;
        g[1] = 0xF6;
        g[2] = hun2;
        g[3] = 2;
        func_80081DE8(g, D_8009B118);
        p[0x46] = 3;
        d = D_8009B118;
        n = 0x26810;
        *(s32 *)(p + 0x30) = n;
        n = 0xA000;
join1:
        *(s32 *)(p + 0x1C) = n;
        if (d2) {
            *(s32 *)(p + 8) = d;
            *(s32 *)(p + 0xC) = d + 0x800;
            break;
        } else {
            *(s32 *)(p + 8) = d;
            *(s32 *)(p + 0xC) = d + 0x800;
            break;
        }

    case 3:
    case 5:
        m2 = 0xFFDCFFFF;
        n2 = 0x800;
join2:
        *(s32 *)(p + 0x1C) = n2;
        D_8009B0F4 = D_8009B0F4 & m2;
        d3 = D_8009B118;
        *(s32 *)(p + 0xC) = d3;
        *(s32 *)(p + 8) = d3;
        p[0x46] = 1;
        break;

    case 6:
        func_80048D08(1, D_8009B118);
        break;
    }
}
