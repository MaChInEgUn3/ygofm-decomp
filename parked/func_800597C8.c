#include "common.h"

void func_800597C8(s32 arg0, s32 arg1, s32 arg2) {
    u8 *p = D_800F2C40 + arg0 * 3616;
    s32 i = 0;
    s32 w;

    arg2 <<= 4;
    *(s16 *)(p + 0xE06) = arg2;
    w = (u16)arg2;

    if (p[0xE1B] != 0) {
        u8 *q = p;

        do {
            s32 v = p[0xBF5];

            if (arg1 != 0) {
                *(u8 *)(*(s32 *)(q + 0x1E0) + 0xC) = arg1;
                v = arg1;
            }

            func_8004DC38(p, i, v, w);
            i++;
            q += 4;
        } while (i < p[0xE1B]);
    }

    if (arg1 != 0) {
        p[0xBF5] = arg1;
    }

    *(s16 *)(p + 0xDCE) = 0;
}
