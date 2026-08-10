#include "common.h"

void func_80060E70(u8 *p, s32 idx, s32 flag) {
    u16 *w;
    u8 *e;
    u8 *q;
    u8 *r;
    u8 *s;
    u8 *o;
    s32 i;
    s32 y;
    s32 base;
    s32 n;
    s32 m;
    s32 k;

    e = D_801A8000 + idx * 0x18;
    *(s16 *)(e + 8) = flag;
    (*(u8 **)e)[0x68] = flag;
    base = 0x18;
    if (flag != 0) {
        base = 0x1A;
    }

    i = 0;
    q = e;
    y = 0;
    s = p + 2;

    do {
        n = (*(u16 *)(q + 0xA) = *(u16 *)p);
        m = *(u16 *)p;
        if (m != 0) {
            n = m;
            m = base;
            if (((D_801D4244[n - 1] >> 26) & 0x1F) >= 0x14) {
                m = base + 1;
            }
            D_801D5608[0] = n;
            k = *(u16 *)s;
            D_8009B338 = n;
            D_801D5608[1] = k;
        }

        o = func_80035BE4(idx + 1, m, *(s16 *)(e + 4), *(s16 *)(e + 6),
                          0x120, 0xB0);
        *(s16 *)(o + 0x3A) = y;
        w = (u16 *)(q + 0xA);
        if (*(u16 *)s == 0) {
            o[0x54] = 4;
            *w = *w | 0x8000;
        }
        if (i != 0) {
            *(u16 *)(o + 0x34) = *(u16 *)(o + 0x34) | 0x40;
        }
        func_80039A14(o);
        s += 4;
        p += 4;
        q += 2;
        i++;
        y += 0x16;
    } while (i < 7);
}
