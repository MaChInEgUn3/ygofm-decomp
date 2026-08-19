#include "common.h"

void func_800250C8(void) {
    s32 t;
    s32 n;
    u8 *r;
    u8 *p;
    s32 c;
    s32 v;
    s32 u;

    t = D_8009B1D2;
    n = t - 0x152;
    if (func_80024E24() == 0) {
        if (func_80025028(0x2B0) != 0) {
            n = t - 0x14D;
        }
        r = func_8002C68C(5);
        *(s16 *)(r + 0) = 0xA0;
        *(s16 *)(r + 2) = 0x78;
        *(s16 *)(r + 0x1A) = n;
        func_8003FEE0(0x14);
        return;
    }

    if ((D_8009B220 & 0x40) == 0) {
        D_8009B220 = D_8009B220 | 0x60;
        if (*(s16 *)&D_8009B22A == 0) {
            c = D_8009AF30[n];
            p = D_8009B1C8;
            v = *(u16 *)(p + 0x14) + c * 100;
            *(s16 *)(p + 0x14) = v;
            if (*(s16 *)(p + 0x16) < (s16)v) {
                *(s16 *)(p + 0x14) = *(u16 *)(p + 0x16);
            }
            goto done;
        }
        D_8009B210 = 0;
    }

    if ((D_8009B220 & 0x20) != 0) {
        if (func_8001F364() != 0) {
            return;
        }
        D_8009B220 = D_8009B220 & 0xFFDF;
        r = func_8002C68C(9);
        *(s16 *)(r + 0) = 0xA0;
        *(s16 *)(r + 2) = 0x78;
        *(s16 *)(r + 0x1A) = n;
        return;
    }

    c = D_8009AF30[n];
    p = D_8009B1C8;
    u = *(u16 *)(p + 0x14) - c * 100;
    *(s16 *)(p + 0x14) = u;
    if ((s16)u < 0) {
        *(s16 *)(p + 0x14) = 0;
    }

done:
    D_8009B220 = 0;
}
