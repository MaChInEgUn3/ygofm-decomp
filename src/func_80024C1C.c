#include "common.h"

u8 *func_80024C1C(s32 arg0, s32 arg1, s32 arg2) {
    u8 *o;
    s32 t;
    s32 w;

    o = func_800400AC(func_8004002C(), 0);

    *(s16 *)(o + 0x32) = -0x18;
    *(s16 *)(o + 0x30) = arg1;
    *(s16 *)(o + 0x34) = arg2;
    o[0x67] = 0;
    o[0x69] = 0;
    *(s32 *)(o + 4) = *(s32 *)(o + 4) | 0x1000000;
    w = D_801D4244[arg0 - 1];
    *(s32 *)(o + 0x10) = (s32)func_80016778;
    o[0x5C] = 0;
    o[0x5D] = 0xC0;
    *(s16 *)(o + 0x42) = 0;

    t = (w >> 26) & 0x1F;
    o[0x68] = t;

    if (t >= 0x14) {
        o[0x5C] = 0x38;
        switch (t) {
        case 0x17:
            *(s16 *)(o + 0x42) = 1;
            break;
        case 0x14:
            *(s16 *)(o + 0x42) = 1;
            break;
        case 0x15:
            *(s16 *)(o + 0x42) = 2;
            break;
        case 0x16:
            *(s16 *)(o + 0x42) = 3;
            break;
        }
    }
    return o;
}
