#include "common.h"

s32 func_80018CF8(void) {
    s16 buf[5];
    s32 i;
    s32 k;
    s16 *q;
    u8 *p = (u8 *)D_8009B1C8;
    u8 *t;
    s32 base;

    for (i = 0; i < 5; i++) {
        buf[i] = (s8)p[i + 0x1A];
    }

    t = (u8 *)D_8015C424;
    base = 0x48000;
    i = 0;
    k = 0x11;

outer:
    q = buf;

inner:
    if (*q >= 0 && *(s16 *)(t + *q * 6 + base + 0x39FC) == k) {
        *q = -1;
        k++;

        if (k < 0x16) {
            i = 0;
            goto outer;
        }

        return 1;
    }

    i++;

    if (i < 5) {
        q++;
        goto inner;
    }

    return 0;
}
