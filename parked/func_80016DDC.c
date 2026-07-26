#include "common.h"

void func_80016DDC(u8 *arg0) {
    s32 d = *(s16 *)(arg0 + 0x12) - *(s16 *)(arg0 + 0x14);
    s32 a;
    s32 step;

    a = d == 0;
    if (a) {
        return;
    }

    a = d;
    if (a < 0) {
        a = -a;
    }

    step = 9;
    if (a >= 0x12C) {
        step = 0x13;
    }
    if (a >= 0x3E8) {
        step = 0x2F;
    }
    if (a >= 0xBB8) {
        step = 0x61;
    }

    if (d > 0) {
        d -= step;
        if (d < 0) {
            d = 0;
        }
    } else {
        d += step;
        if (d > 0) {
            d = 0;
        }
    }

    *(u16 *)(arg0 + 0x12) = *(u16 *)(arg0 + 0x14) + d;
}
