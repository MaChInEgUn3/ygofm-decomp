#include "common.h"

void func_800427DC(u8 *arg0, s32 arg1) {
    *(s32 *)(arg0 + 0x54) = 0;
    *(s32 *)(arg0 + 0x4C) = 0;
    *(s32 *)(arg0 + 0x44) = 0;
    *(s32 *)(arg0 + 0x3C) = 0;
    *(s32 *)(arg0 + 0x34) = 0;
    *(s32 *)(arg0 + 0x2C) = 0;
    *(s32 *)(arg0 + 0x10) = 0;
    arg0[0x21] = 0;
    arg0[0x20] = 0;
    arg0[0x22] = 0;
    *(s16 *)(arg0 + 0x1C) = 0;
    *(s16 *)(arg0 + 0x1A) = 0;
    *(s16 *)(arg0 + 0x18) = 0;
    arg0[0x5A] = arg1;
    *(u16 *)(arg0 + 8) |= 8;
}
