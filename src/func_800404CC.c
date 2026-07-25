#include "common.h"

void func_800404CC(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4,
                   s32 arg5, s32 arg6, s32 arg7) {
    *(s16 *)(arg0 + 0x30) = arg1;
    *(s16 *)(arg0 + 0x32) = arg2;
    func_80040468(arg0, arg3, arg4, arg5, arg6, arg7);
}
