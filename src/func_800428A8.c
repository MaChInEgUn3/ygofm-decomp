#include "common.h"

void func_800428A8(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4,
                   s32 arg5, s32 arg6, s32 arg7, s32 arg8) {
    *(s32 *)(arg0 + 0x54) = arg8;
    func_800404CC(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7);
}
