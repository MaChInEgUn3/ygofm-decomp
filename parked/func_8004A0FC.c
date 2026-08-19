#include "common.h"

void func_8004A0FC(u8 *p, u8 *q) {
    s32 vol;
    s32 t;
    s32 l;
    s32 r;

    if (D_8009B458[0x815] != 0) {
        vol = 0x40;
    } else {
        vol = D_8009B458[0x4BF] + p[0xA] + p[0xB] + q[1] - 0xC0;
    }

    if (vol < 0) {
        vol = 0;
    }
    if (vol >= 0x80) {
        vol = 0x7F;
    }

    p[0xC] = vol;

    t = D_8009B458[0x4BC] * *(u16 *)(D_8009B458 + 0x512);
    t = t * q[5];
    t = t * q[3];
    t = t >> 14;
    t = t * p[8];
    t = t * p[9];
    t = t >> 14;

    if (vol >= 0x40) {
        l = t;
        if (vol == 0x40) {
            r = t;
        } else {
            r = (0x40 - (vol & 0x3F)) * (t * 2) >> 7;
        }
    } else {
        r = t;
        l = vol * (t * 2) >> 7;
    }

    r = r * *(s16 *)(D_8009B458 + 0x7E4);
    l = l * *(s16 *)(D_8009B458 + 0x7E6);
    *(s16 *)(p + 0x14) = ((r >> 7) * (p[0xE] & 0x7F)) >> 7;
    *(s16 *)(p + 0x16) = ((l >> 7) * (p[0xE] & 0x7F)) >> 7;
}
