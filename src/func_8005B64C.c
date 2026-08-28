#include "common.h"

typedef struct {
    u8 b[8];
} Blk8;

void func_8005B64C(u8 *p, s32 mode) {
    Blk8 sp10;
    s32 m;
    s32 m1;
    s32 v1;
    s32 w1;
    s32 d1;
    s32 v;
    s32 w;
    s32 d;
    s32 x;
    s32 n;
    s32 f;
    u8 *y;

    switch (mode) {
    case 0:
        m = 0xFFDDFFFF;
        *(s16 *)(p + 0x30) = 0x200;
        *(s16 *)(p + 0x32) = 0x100;
        *(s16 *)(p + 4) = 0x40;
        v = D_8009B0F4;
        *(s16 *)(p + 6) = 0x10;
        D_8009B0F4 = v & m;
        w = D_8009B0F4;
        D_8009B0F4 = w | 0x10000;
        p[0x46] = 2;
        d = D_8009B118;
        *(s32 *)(p + 0x1C) = 0x20000;
        *(s32 *)(p + 8) = d;
        *(s32 *)(p + 0xC) = d + 0x800;
        break;

    case 1:
        do {
            m1 = 0xFFDDFFFF;
        } while (0);
        *(s16 *)(p + 0x30) = 0x380;
        do {
            v1 = D_8009B0F4;
        } while (0);
        f = 0x40;
        do {
            *(s16 *)(p + 0x32) = 0;
        } while (0);
        *(s16 *)(p + 4) = f;
        D_8009B0F4 = v1 & m1;
        w1 = D_8009B0F4;
        m1 = 0x10000;
        *(s32 *)(p + 0x1C) = m1;
        do {
            D_8009B0F4 = w1 | m1;
            p[0x46] = 2;
            d1 = D_8009B118;
            *(s16 *)(p + 6) = 0x10;
        } while (0);
        *(s32 *)(p + 8) = d1;
        *(s32 *)(p + 0xC) = d1 + 0x800;
        break;

    case 2:
        m = 0xFFDCFFFF;
        *(s32 *)(p + 0xC) = (s32)D_801DD000;
        *(s32 *)(p + 8) = (s32)D_801DD000;
        do {
            x = D_8009B0F4;
            n = 0x1000;
        } while (0);
        goto tail2;

    case 3:
        sp10 = *(Blk8 *)D_8009B058;
        func_80081DE8(&sp10, D_801DD000);
        m = 0xFFDCFFFF;
        *(s32 *)(p + 0x1C) = 0x8000;
        x = D_8009B0F4;
        y = D_8001002C;
        D_8009B0F4 = x & m;
        *(s32 *)(p + 0xC) = (s32)y;
        *(s32 *)(p + 8) = (s32)y;
        p[0x46] = 1;
        break;

    case 4:
        do {
            m = 0xFFDCFFFF;
        } while (0);
        *(s32 *)(p + 0xC) = (s32)D_801AF800;
        *(s32 *)(p + 8) = (s32)D_801AF800;
        x = D_8009B0F4;
        do {
            n = 0x800;
        } while (0);
    tail2:
        do {
            *(s32 *)(p + 0x1C) = n;
        } while (0);
        D_8009B0F4 = x & m;
    tail3:
        p[0x46] = 1;
        break;
    }
}
