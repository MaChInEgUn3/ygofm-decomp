#include "common.h"

void func_8004D58C(s32 arg0, u8 *arg1) {
    u8 *t;
    u8 *c;
    u8 *q;
    u8 *e;
    u8 *p3;
    u8 *p2;
    u8 *g;
    u8 *k;
    u8 *s;
    u8 *u;
    u8 *v;
    s32 ff;
    s32 one;
    s32 i;
    s32 j;
    s32 n;
    s32 m;
    s32 a;
    s32 b;
    s32 w;
    s32 d;
    s32 x;
    s32 y;

    n = 0;
    m = 0;
    p3 = (u8 *)0;
    ff = 0xFFFF;
    p2 = (u8 *)0;
    i = 0;

    t = D_800F2C40 + arg0 * 0xE20;
    c = t;

    *(s16 *)(t + 0xE06) = 0;
    *(s16 *)(t + 0xE08) = 0;
    *(s32 *)(t + 0xDD8) = 0;
    *(s32 *)(t + 0xDDC) = 0;
    *(s32 *)(t + 0xDE0) = 0;
    *(s32 *)(t + 0xDE4) = 0;
    *(s32 *)(t + 0xDF0) = 0;

    do {
        *(s16 *)(c + 0x7C4) = 0;
        j = 0;
        a = n;
        b = m;
        do {
            u = t + a;
            a += 2;
            v = t + b;
            b += 2;
            j++;
            *(u16 *)(v + 0x2C8) = ff;
            *(s16 *)(u + 0x750) = 0;
        } while (j < 0x3A);
        n += 0x76;
        m += 0x74;
        i++;
        c += 0x76;
    } while (i < 0xA);

    i = 7;
    q = t + i;
    do {
        q[0xBEC] = 0;
        i--;
        q--;
    } while (i >= 0);

    e = *(u8 **)(arg1 + 0x10);
    if (e == (u8 *)0) {
        return;
    }

    do {
        if (*(s32 *)(e + 8) != 0) {
            w = e[0xF];
            if (w == 3) {
                p3 = *(u8 **)(e + 4);
            }
            if (w == 2) {
                p2 = *(u8 **)(e + 4);
            }
        }
        e = *(u8 **)e;
    } while (e != (u8 *)-1);

    if (p3 != (u8 *)0) {
        p3 += 8;
        k = *(u8 **)p3;
        p3 += 4;
        i = 0;
        if (*(u16 *)k != 0) {
            one = 1;
            g = k;
            do {
                d = i / 8;
                s = t + d;
                y = s[0xBEC];
                if ((*(s32 *)(g + 4) & 0x100) != 0) {
                    x = y | (one << (i % 8));
                } else {
                    x = y;
                }
                s[0xBEC] = x;
                g += 4;
                i++;
            } while ((u32)i < *(u16 *)k);
        }
        *(s32 *)(t + 0xDD8) = *(s32 *)p3;
        *(s32 *)(t + 0xDDC) = *(s32 *)(p3 + 4);
    }

    if (p2 != (u8 *)0) {
        p2 += 4;
        *(s32 *)(t + 0xDE0) = *(s32 *)p2;
        *(s32 *)(t + 0xDE4) = *(s32 *)(p2 + 4);
    }
}
