#include "common.h"

void func_8002525C(void) {
    u8 *p;
    s32 s;
    s32 c;
    s32 u;
    s32 i;

    s = D_8009B1D2 - 0x157;

    if (func_80024E24() == 0) {
        if (func_80025028(0x2AF) != 0) {
            s = 5;
        }
        c = 6;
    } else {
        u = D_8009B220;
        if ((u & 0x40) == 0) {
            D_8009B220 = u | 0x60;
            if (*(s16 *)&D_8009B22A == 0) {
                i = D_8009B1D5 ^ 1;
                p = (u8 *)&D_800E9FF0[i];
                *(s16 *)(p + 0x14) = *(u16 *)(p + 0x14) - D_8009AF38[s] * 10;
                if (*(s16 *)(p + 0x14) < 0) {
                    *(s16 *)(p + 0x14) = 0;
                }
                D_8009B220 = 0;
                return;
            }
            D_8009B210 = 0;
        }
        if ((D_8009B220 & 0x20) == 0) {
            goto plain;
        }
        if (func_8001F364() != 0) {
            return;
        }
        D_8009B220 &= 0xFFDF;
        c = 7;
    }

    p = func_8002C68C(c);
    *(s16 *)p = 0xA0;
    *(s16 *)(p + 2) = 0x78;
    *(s16 *)(p + 0x1A) = s;
    func_8003FEE0(0x1C);
    return;

plain:
    i = D_8009B1D5;
    p = (u8 *)&D_800E9FF0[i];
    *(s16 *)(p + 0x14) = *(u16 *)(p + 0x14) - D_8009AF38[s] * 10;
    if (*(s16 *)(p + 0x14) < 0) {
        *(s16 *)(p + 0x14) = 0;
    }
    D_8009B220 = 0;
}
