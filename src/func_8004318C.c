#include "common.h"

void func_8004318C(u8 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 x = (*(s16 *)(arg0 + 0x36) + arg1) >> 1;
    s32 y = (*(s16 *)(arg0 + 0x38) + arg2) >> 1;
    s32 c = func_80086770(arg3);
    s32 d = c;

    *(u16 *)(arg0 + 0x30) = x + (*(s16 *)(arg0 + 0x36) - x) * c / 4096;
    *(u16 *)(arg0 + 0x32) = y + (*(s16 *)(arg0 + 0x38) - y) * d / 4096;
}
