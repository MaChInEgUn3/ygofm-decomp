#include "common.h"

s32 func_8005C464(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    u8 *p = D_800F5750;

    if (func_8005C4F0(arg0, p) != 0) {
        return -1;
    }

    return func_8005B8A0(p, arg1, arg2,
                         func_8007E710((s32)p) +
                             ((u32)(*(s32 *)(p + 4) + 0x7FF) >> 11),
                         arg3, arg4);
}
