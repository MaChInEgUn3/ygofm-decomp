#include "common.h"

void func_800134E0(u8 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 *p = (s32 *)(arg0 + 0x10);

    arg1 += p[3];
    p[0] = arg1;
    arg2 += p[4];
    arg3 += p[5];
    p[1] = arg2;
    p[2] = arg3;

    func_8008AD50(p, arg1, arg2, arg3);
}
