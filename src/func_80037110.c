#define D_8009B09C_IS_AGGREGATE
#include "common.h"

void func_80037110(u8 *arg0) {
    u8 *q = arg0;
    s32 c = 0;
    s32 t = D_8009B09C[0] & 0x7F;

    if (t >= 0x40) {
        t = 0x7F - t;
    }

    t = t * 2 + 0x80;

    if (arg0[0xC] != 0) {
        c = t;
    }
    if (arg0[0xD] != 0) {
        c |= t << 8;
    }
    if (arg0[0xE] != 0) {
        c |= t << 16;
    }

    *(s32 *)(arg0 + 0x3C) = c;
    *(s32 *)(arg0 + 0x44) = c;

    c = (c & 0xFCFCFC) / 4;
    *(s32 *)(q + 0x2C) = c;
    *(s32 *)(q + 0x34) = c;
    *(s32 *)(q + 0x4C) = c;
    *(s32 *)(q + 0x54) = c;
}
