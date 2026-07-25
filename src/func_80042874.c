#include "common.h"

void func_80042874(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4,
                   s32 arg5, s32 arg6) {
    *(s32 *)(arg0 + 0x54) = arg6;
    func_80040468(arg0, arg1, arg2, arg3, arg4, arg5);
}
