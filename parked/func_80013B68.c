#include "common.h"

u8 *func_80013B68(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    u8 *p;

    D_8009B0F4 &= ~0x20;
    p = D_800E9E18;

    if ((D_8009B0F4 & 0x10) && (D_8009B0F4 & 0x80000)) {
        func_80015010();
    }

    *(s32 *)(p + 0x24) = arg0;
    *(s32 *)(p + 0x34) = arg1;
    p[0x38] = arg2;
    p[0x39] = arg3;
    p[0x46] = 4;
    *(s32 *)(p + 0x2C) = 0x80000;
    D_8009B0F4 |= 0x20;

    return p;
}
