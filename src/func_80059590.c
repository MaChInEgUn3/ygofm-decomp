#include "common.h"

void func_80059590(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    u8 *p = D_800F2C40 + arg0 * 3616;

    p[0xDC3] = arg1;
    p[0xDC0] = arg2;
    p[0xDC1] = arg3;
    p[0xDC2] = arg4;
}
