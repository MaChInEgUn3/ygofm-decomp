#include "common.h"

void func_80035AB8(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    u8 *p = (u8 *)D_800EB0F8 + arg0 * 100;

    *(s16 *)(p + 0x3C) = arg1;
    *(s16 *)(p + 0x40) = arg2;
    *(s16 *)(p + 0x3E) = arg3;
    *(s16 *)(p + 0x42) = arg4;
}
