#include "common.h"

void func_8004DC38(u8 *t, s32 a, s32 c, s32 d) {
    u8 *q;
    u8 *e;
    u8 *f;
    u8 *cur;
    u8 *b;
    s32 j;
    s32 k;
    s32 n;
    s32 w;
    s32 m;
    s32 r;
    s32 i;
    s32 g;
    s32 v;
    s32 x;

    k = a * 4;
    j = a * 2;
    n = *(u16 *)(t + (j + c * 0x74) + 0x2C8);
    e = *(u8 **)(t + 0xDD8) + n * 4;
    q = *(u8 **)(t + k + 0x1E0);

    if (q == (u8 *)0) {
        return;
    }
    if (n == 0xFFFF) {
        return;
    }

    w = *(u16 *)(t + (j + c * 0x76) + 0x750);
    if (w == 0) {
        return;
    }

    m = w * 0x10;
    r = (u32)d % (u32)m;
    f = e - 4;
    if (r == 0 && d != 0 && t[0xE16] != 0x3C) {
        r = m;
    }

    v = *(u16 *)f;
    i = 0;
    if (v == 0) {
        return;
    }

    g = t[0xE16];
    cur = e + 4;
    do {
        if (g != 0x3C) {
            if (r - (cur[-2] << 4) <= 0) {
                goto done;
            }
        } else {
            if (r - (cur[-2] << 4) < 0) {
                goto done;
            }
        }
        r = r - (cur[-2] << 4);
        if (*(s32 *)cur < 0) {
            goto done;
        }
        cur += 4;
        i++;
        e += 4;
    } while (i < v);

done:
    v = *(u16 *)f;
    if (i >= v) {
        return;
    }
    b = e;
    while (1) {
        if (*(s32 *)(b + 4) < 0) {
            break;
        }
        i++;
        if (i >= v) {
            break;
        }
        b += 4;
    }

    x = (e - *(u8 **)(t + 0xDD8)) >> 2;
    *(s16 *)(q + 0x16) = x;
    if (x != 0) {
        x = x - 1;
    } else {
        x = (b - *(u8 **)(t + 0xDD8)) >> 2;
    }
    *(s16 *)(q + 0x14) = x;

    x = e[2] << 4;
    *(s16 *)(q + 0x12) = x;
    *(s16 *)(q + 0x10) = x - r;

    if (t[0xE16] == 0x3C) {
        if ((s16)(x - r) >= *(u16 *)(q + 0x12)) {
            *(s16 *)(q + 0x10) = 0x6000;
        }
    }
}
