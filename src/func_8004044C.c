#include "common.h"

void func_8004044C(u8 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    arg0[0x67] = arg1;
    arg0[0x68] = arg2;
    arg0[0x69] = arg3;
    *(u16 *)(arg0 + 8) &= 0xFFEF;
}
