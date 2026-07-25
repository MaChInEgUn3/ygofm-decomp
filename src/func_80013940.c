#include "common.h"

void func_80013940(u8 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    arg1 &= 0xF;
    *(s32 *)(arg0 + 0x10) = arg3;
    if (arg3 < 0) {
        *(s32 *)(arg0 + 0x10) = -(arg3 << 11);
    }
    if (arg2 < 0) {
        *(s32 *)(arg0 + 0x14) = 0;
        *(s32 *)(arg0 + 0x24) = -arg2;

        return;
    }
    *(s32 *)(arg0 + 0x14) = arg2 << 11;
    *(s32 *)(arg0 + 0x24) = D_800E9EA8[arg1] + arg2;
}
