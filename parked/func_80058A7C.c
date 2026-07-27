#include "common.h"

s32 func_80058A7C(s32 arg0, s32 arg1, Words7 *w) {
    u8 *p = (u8 *)w;
    s32 sh;
    s32 t;
    s32 x;
    s32 hi;
    s32 lo;

    arg0 &= 1;
    sh = arg0 << 8;
    x = *(u16 *)(p + 4);
    t = *(s16 *)(p + 0x12);
    x -= 0x280;
    x += sh;
    *(s16 *)(p + 4) = x;

    if (t < 0x100) {
        x = *(u16 *)(p + 0x10) - 0x80;
        *(s16 *)(p + 0x10) = x;

        if (*(s16 *)(p + 0x12) == 8) {
            *(s16 *)(p + 0x12) = arg0 + 0xF2;
        }
    } else {
        x = *(u16 *)(p + 0x10) - 0x280;
        x += sh;
        *(s16 *)(p + 0x10) = x;
    }

    hi = ((*(u16 *)p & 3) << 7) | ((arg1 & 3) << 5);
    hi |= (s16)(*(u16 *)(p + 6) & 0x100) >> 4;
    hi |= (*(u16 *)(p + 4) & 0x3FF) >> 6;
    hi |= (*(u16 *)(p + 6) & 0x200) << 2;
    lo = ((*(u16 *)(p + 0x12) << 6) | ((*(u16 *)(p + 0x10) >> 4) & 0x3F)) & 0xFFFF;

    return (hi << 16) | lo;
}
