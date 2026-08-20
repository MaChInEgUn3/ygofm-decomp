#include "common.h"

s32 func_8004A940(s32 a, s32 b, s32 c, s32 d) {
    u8 *p;
    u8 *e;
    s32 i;
    s32 n;
    s32 bi;
    s32 r;
    s32 by;
    s32 o;

    p = D_8009B458;
    bi = -1;
    i = 0;

    if (*(s16 *)(D_8009B458 + 0x510) > 0) {
        d = 0x63;
        c = *(s16 *)(D_8009B458 + 0x510);
        do {
            r = i;
            if (p[0x183] == d) {
                goto out;
            }
            i++;
            p += 0x28;
        } while (i < c);
    }

    p = D_8009B458;
    n = *(s16 *)(p + 0x510);
    i = 0;
    if (n > 0) {
        c = n;
        do {
            if (p[0x18D] == 0) {
                goto founda;
            }
            i++;
            p += 0x28;
        } while (i < c);
        n = *(s16 *)(D_8009B458 + 0x510);
    }

    i = 0;
    if (n > 0) {
        d = b & 0xFF;
        o = 0;
        do {
            e = D_8009B458 + o;
            by = e[0x183];
            if (by == (a & 0xFF) && e[0x185] == d) {
                goto foundb;
            }
            i++;
            o += 0x28;
        } while (i < *(s16 *)(D_8009B458 + 0x510));
    }

    p = D_8009B458;
    n = *(s16 *)(p + 0x510);
    i = 0;
    if (n > 0) {
        do {
            if (p[0x18D] == 0) {
                goto founda;
            }
            i++;
            p += 0x28;
        } while (i < n);
    }

    c = -1;
    n = *(s16 *)(p + 0x510);
    i = 0;
    if (n > 0) {
        d = n;
        e = p;
        do {
            if (*(u16 *)(e + 0x19E) < (u32)c) {
                c = *(u16 *)(e + 0x19E);
                bi = i;
            }
            i++;
            e += 0x28;
        } while (i < d);
    }

    r = -1;
    if ((u32)c <= 0xFFFE) {
        i = bi;
founda:
        by = a & 0xFF;
foundb:
        r = func_8004A8E4(i, by, c, d);
    }

out:
    return r;
}
