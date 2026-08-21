#define D_8009B0F4_SIZED
#define D_8009B134_SIZED
#include "common.h"

void func_80050584(s32 arg0) {
    u8 *p;
    u8 *b;
    u8 *b0;
    u8 *q;
    u8 *r;
    u8 *s;
    s32 v;
    s32 t;
    s32 a;
    s32 m1;

    b0 = D_800F2C40;
    p = b0 + arg0 * 0xE20;
    if (p[0xE1F] == 0) {
        if (p[0xE14] == 0xFF) {
            if (((D_8009B0F4[0] & 0x2000030) | D_8009B134[0]) == 0) {
                do {
                    t = func_8008E590() >> 8;
                    v = t % 722;
                } while (v < 0 || v >= 0x2D2 ||
                         (v >= 0x12C && v < 0x15E) ||
                         (v >= 0x28A && v < 0x2BC) ||
                         v == 0x2D0);
                m1 = -1;
                func_80056504(arg0 | 0x80, v, m1, m1, m1, m1, 0);
            }
        } else {
            func_80056828(arg0);
        }

        b = D_800F2C40;
        if ((b + arg0 * 0xE20)[0xE1F] != 0) {
            q = b + (arg0 ^ 1) * 0xE20;
            a = 0x400;
            if (q[0xE1F] != 0) {
                r = *(u8 **)(q + 0xD18);
                if (r != (u8 *)0) {
                    t = *(s16 *)(r + 0x46) + 0x400;
                    a = t / 0x1000;
                    a = t - a * 0x1000;
                }
            }
            s = D_800F2C40 + arg0 * 0xE20;
            if (*(s32 *)(s + 0xD18) != 0) {
                *(s16 *)(*(s32 *)(s + 0xD18) + 0x44) = 0;
                *(s16 *)(*(s32 *)(s + 0xD18) + 0x46) = a;
                *(s16 *)(*(s32 *)(s + 0xD18) + 0x48) = 0;
                *(s32 *)(*(s32 *)(s + 0xD18) + 0x18) = 0;
                *(s32 *)(*(s32 *)(s + 0xD18) + 0x1C) = 0;
                *(s32 *)(*(s32 *)(s + 0xD18) + 0x20) = 0;
            }
            func_8005922C(*(u8 **)(s + 0xD18), 0);
            func_80059DD8(arg0);
            s[0xE15] = 0;
        }
    }
}
