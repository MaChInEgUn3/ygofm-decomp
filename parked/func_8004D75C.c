#include "common.h"

void func_8004D75C(s32 arg0) {
    u8 *t;
    u8 *a;
    u8 *q;
    u8 *e;
    u8 *r;
    u8 *g;
    u8 *lim;
    u8 *b;
    s32 u;
    s32 z;
    s32 i;
    s32 j;
    s32 k;
    s32 s;
    s32 n;
    s32 o;
    s32 v;
    s32 w;
    u32 hi;

    t = D_800F2C40 + arg0 * 0xE20;

    if (*(s32 *)(t + 0xDD8) == 0) {
        return;
    }

    i = 0;
    if (t[0xE1B] != 0) {
        k = i;
        j = 0x74;
        while (1) {
            q = *(u8 **)(t + i * 4 + 0x1E0);
            s = 1;
            if (q == (u8 *)0) {
                break;
            }
            q[0x1A] = s;
            o = k;
            n = *(u16 *)(*(u8 **)(t + i * 4 + 0x1E0) + 0x18);
            a = *(u8 **)(t + 0xDD8) + n * 4;
            *(s16 *)(t + j + 0x2C8) = n;

            while (1) {
                v = *(s32 *)a;
                if (v >= 0) {
                    goto add;
                }
                s = (u32)v >> 16;
            s = s & 0x7F;
                if (s == 0) {
                    break;
                }
                g = t + (o + s * 0x74);
                if (*(u16 *)(g + 0x2C8) != 0xFFFF) {
                    a += 4;
                    continue;
                }
                *(s16 *)(g + 0x2C8) = *(u16 *)a;
                a = *(u8 **)(t + 0xDD8) + *(u16 *)a * 4;
                continue;
add:
                e = t + (o + s * 0x76);
                w = a[2];
                a += 4;
                *(s16 *)(e + 0x750) = *(u16 *)(e + 0x750) + w;
            }

            k += 2;
            j += 2;
            i++;
            if (i >= (s32)t[0xE1B]) {
                break;
            }
        }
    }

    r = t + 0x76;
    n = 0x76;
    lim = t + 0x49C;
    do {
        *(s16 *)(r + 0x7C4) = 0;
        z = 0;
        if (t[0xE1B] != 0) {
            b = r;
            u = n;
            do {
                hi = *(u16 *)(t + u + 0x750);
                if (*(u16 *)(b + 0x7C4) < hi) {
                    *(s16 *)(b + 0x7C4) = hi;
                }
                u += 2;
                z++;
            } while (z < (s32)t[0xE1B]);
        }
        r += 0x76;
        n += 0x76;
    } while ((s32)r < (s32)lim);
}
