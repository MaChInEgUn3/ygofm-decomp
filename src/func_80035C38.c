#include "common.h"

void func_80035C38(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4,
                   s32 arg5, s32 arg6) {
    u8 *p;

    func_80035AB8(arg0, arg2, arg3, arg4, arg5);
    p = func_80035AF0(arg0, arg1, 0);
    *(u16 *)(p + 0x34) |= arg6;
}
