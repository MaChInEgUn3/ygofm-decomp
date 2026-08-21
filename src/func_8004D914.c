#include "common.h"

void func_8004D914(s32 arg0) {
    u8 *b;
    u8 *e;
    s32 *a;
    s32 *c;
    s32 *t;
    s32 *g;
    s32 i;
    s32 j;
    s32 k;
    s32 o;
    s32 w;
    s32 y;
    s32 x;
    u16 *yp;
    s32 v;
    s32 hi;
    s32 one;
    s32 ff;
    s32 mask;
    s32 bit;

    b = D_800F2C40 + arg0 * 0xE20;
    o = 0;
    if (*(volatile s32 *)(b + 0xDD8) == 0) {
        return;
    }
    i = 0;
    if (b[0xE1B] == 0) {
        return;
    }

    ff = 0xFFFF;
    mask = 0xFF80FFFF;
    bit = 0x10000;
    one = 1;
    o = i;
    e = b;

    do {
        j = 1;
        k = o + 0x74;
        g = (s32 *)(*(volatile s32 *)(b + 0xDD8) + *(u16 *)(e + 0x33C) * 4);

        do {
            w = *(u16 *)(b + k + 0x2C8);
            a = (s32 *)(*(volatile s32 *)(b + 0xDD8) + w * 4);
            if (w != ff) {
                t = a - 1;
                while (1) {
                    x = *a;
                    if (x < 0) {
                        hi = (u32)x >> 16;
                        hi = hi & 0x7F;
                        yp = (u16 *)(b + (o + hi * 0x74) + 0x2C8);
                        y = *yp;
                        c = (s32 *)(*(volatile s32 *)(b + 0xDD8) + y * 4);
                        if (hi == 0) {
                            goto zero;
                        }
                        *a = (x & 0xC07FFFFF) | ((((u32)x >> 16) & 0x7F) << 23);
                        if (y != ff) {
                            if (hi >= 2) {
                                if (c != (s32 *)0) {
                                    do {
                                        v = *c;
                                        if (v < 0) {
                                            if ((((u32)v >> 16) & 0x7F) == hi) {
                                                *c = (v & mask) | bit;
                                            }
                                            if ((*(u16 *)((u8 *)c + 2) & 0x7F) == one) {
                                                goto hit;
                                            }
                                        }
                                        c++;
                                    } while (c != (s32 *)0);
                                }
                            }
                        }
                    }
cont:
                    a++;
                }
hit:
                *(s16 *)c = g - (s32 *)*(volatile s32 *)(b + 0xDD8);
                *(s16 *)a = c - (s32 *)*(volatile s32 *)(b + 0xDD8);
                goto cont;
zero:
                *(s16 *)t = (a - (s32 *)*(volatile s32 *)(b + 0xDD8)) - 1;
                *(s16 *)a = (t - (s32 *)*(volatile s32 *)(b + 0xDD8)) + 1;
            }
            j++;
            k += 0x74;
        } while (j < 0xA);

        o += 2;
        e += 2;
        i++;
    } while (i < b[0xE1B]);
}
