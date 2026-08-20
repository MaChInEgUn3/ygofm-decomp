#include "common.h"

void func_800243F4(s32 src, u8 *out16, u8 *out8) {
    u8 buf[0x2D2];
    u8 *b16;
    u8 *b8;
    u8 *e;
    u8 *t;
    u8 *q;
    s32 i;
    s32 n;
    s32 acc;
    s32 lim;
    s32 x;
    s32 y;
    s32 t16;
    s32 t8;
    s32 u16b;
    s32 u8b;

    b16 = out16;
    b8 = out8;

    if (src == 0) {
        for (i = 0x2D1; i >= 0; i--) {
            buf[i] = 0;
        }

        t = D_801781D8;
        n = 0;
        while (n < 0x28) {
            lim = (func_8008E590() & 0x7FF) + 1;
            acc = 0;
            i = 0;
            e = t;
            while (1) {
                acc += *(u16 *)e;
                if (acc >= lim) {
                    q = buf + i;
                    if (*q < 3) {
                        *(s16 *)out16 = i + 1;
                        *out8 = n;
                        n++;
                        out16 += 2;
                        out8 += 1;
                        /* `t16` is the block-copy temp forty lines down; its
                         * live range resumes there, and borrowing the name
                         * here is 10 differences against 4. A fresh local is
                         * not the same thing (the permuter found this). */
                        t16 = *q + 1;
                        *q = t16;
                    }
                    break;
                }
                i++;
                e += 2;
                if (i >= 0x2D0) {
                    break;
                }
            }
        }
    } else {
        for (i = 0; i < 0x28; i++) {
            *(s16 *)out16 = *(u16 *)src;
            src += 2;
            *out8 = i;
            out8++;
            out16 += 2;
        }
    }

    for (i = 0; i < 0xA0; i++) {
        x = func_800358FC(0x28);
        y = func_800358FC(0x28);
        t16 = *(u16 *)(b16 + x * 2);
        u16b = *(u16 *)(b16 + y * 2);
        *(s16 *)(b16 + x * 2) = u16b;
        *(s16 *)(b16 + y * 2) = t16;
        t8 = b8[x];
        u8b = b8[y];
        b8[x] = u8b;
        b8[y] = t8;
    }
}
