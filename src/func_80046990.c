#include "common.h"

void func_80046990(s32 arg0, s32 arg1, s32 arg2) {
    *(s32 *)(D_8009B45C + 0x3C) = 0;

    if (arg0 == 0) {
        D_8009B45C[0x4A] &= 0xFE;
    }
    if (arg1 == 0) {
        D_8009B45C[0x4A] &= 0xFD;
    }
    if (arg2 == 0) {
        D_8009B45C[0x4A] &= 0xBF;
    }

    *(u16 *)(D_8009B45C + 0x40) |= 0xA;
}
