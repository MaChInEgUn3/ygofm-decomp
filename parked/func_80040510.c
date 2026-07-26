#include "common.h"

void func_80040510(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4,
                   s32 arg5, s32 arg6, s32 arg7, s32 arg8, s32 arg9) {
    *(u16 *)(arg0 + 0x3C) = arg3;
    arg3 /= 2;
    *(u16 *)(arg0 + 0x30) = arg1;
    *(u16 *)(arg0 + 0x32) = arg2;
    *(u16 *)(arg0 + 0x18) = arg3;
    *(u16 *)(arg0 + 0x48) = arg3;
    *(u16 *)(arg0 + 8) |= 8;
    *(u16 *)(arg0 + 0x3E) = arg4;
    arg4 /= 2;
    arg0[0x5C] = arg5;
    arg0[0x5D] = arg6;
    arg0[0x66] = arg7;
    *(u16 *)(arg0 + 0x40) = arg8;
    *(u16 *)(arg0 + 0x42) = arg9;
    *(u16 *)(arg0 + 0x1A) = arg4;
    *(u16 *)(arg0 + 0x4A) = arg4;
}
