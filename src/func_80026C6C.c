#include "common.h"

s32 func_80026C6C(u8 **out, s32 arg1, s32 arg2) {
    s32 count = 0;
    s32 i = 0;
    s32 d = D_8009B1D5;
    s32 *t = D_801D4244;
    u8 *r = D_801A7AD8 + (d * 15 + arg1) * 28;

    do {
        if (*(u16 *)(r + 0x16) & 0x8000) {
            s32 k = *(s16 *)(r + 0xC);

            k--;

            if (((t[k] >> 26) & 0x1F) < arg2) {
                *out++ = r;
                count++;
            }
        }
        i++;
        r += 0x1C;
    } while (i < 5);

    *out = 0;

    return count;
}
