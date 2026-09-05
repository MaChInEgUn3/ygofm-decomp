#define D_8009B246_IN_DATA
#define D_8009B254_IN_DATA
#define D_8009B3A4_IS_AGGREGATE
#include "common.h"

void func_800240B0(u8 *p) {
    s32 f;
    s32 r;
    s32 i;

    f = D_8009B1D4;
    if ((f & 0x80) == 0) {
        D_8009B1D4 = f | 0xC0;
        p[0x12] = 4;
        *(s16 *)(p + 0xC) = 0x74;
        p[0x18] = 0;
        p[0x11] = 0;
        p[0x19] = 0;
        D_8009B162 = 3;
    }

    f = D_8009B1D4;
    if (f & 0x40) {
        if (D_8009B162 == 0) {
            D_8009B1D4 = f & 0xBF;
            if (f & 0x20) {
                D_8009B1D4 = 0;
            }
        }
        return;
    }

    if (func_80024060(p) != 0) {
        return;
    }

    i = D_800907D8[*(s8 *)(p + 0x10) * 5 + *(s8 *)(p + 0xF) + D_8009B1D5 * 20];
    r = func_80017034(&D_801A7AD8[i * 28]);
    if (r != 0) {
        D_8009B246 = r;
        D_8009B24B = 0x14;
        D_8009B254 = 2;
        return;
    }

    if ((D_8009B3A4[0] & 3) == 0) {
        D_8009B162 = 0xC;
        D_8009B1D4 = D_8009B1D4 | 0x60;
    }
}
