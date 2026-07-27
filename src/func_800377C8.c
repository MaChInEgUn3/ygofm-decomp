#include "common.h"

void func_800377C8(u8 *arg0) {
    u8 v = arg0[0x51];
    u8 *p;

    if (!(v & 0x80)) {
        arg0[0x51] = v | 0x80;
    }

    p = D_8009B328;

    if (p[0x33] != 0) {
        return;
    }

    {
        u8 w = arg0[0x51];

        if ((w & 0x40) || *(s8 *)(p + 0x30) >= 0x41) {
            arg0[0x51] = 0;

            return;
        }

        arg0[0x51] = w | 0x40;
    }

    {
        u8 *q = D_8009B328;

        q[0x33] = q[0x40];
    }

    {
        u8 *r = D_8009B328;

        *(u16 *)(r + 0x40) = 0x68;

        if (r[0x3C] != 0) {
            *(u16 *)(r + 0x40) = 0xD8;
        }
    }

    {
        u8 *s = D_8009B328;

        *(u16 *)(s + 0x42) = 0xB2;
        *(s16 *)(s + 0x44) = -0x10;
    }
}
