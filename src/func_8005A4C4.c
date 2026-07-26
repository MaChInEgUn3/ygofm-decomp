#include "common.h"

void func_8005A4C4(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    if (*(u8 **)(arg0 + 0xD18) != 0) {
        *(u16 *)(*(u8 **)(arg0 + 0xD18) + 0x44) = 0;
        *(u16 *)(*(u8 **)(arg0 + 0xD18) + 0x46) = arg4;
        *(u16 *)(*(u8 **)(arg0 + 0xD18) + 0x48) = 0;
        *(s32 *)(*(u8 **)(arg0 + 0xD18) + 0x18) = arg1;
        *(s32 *)(*(u8 **)(arg0 + 0xD18) + 0x1C) = arg2;
        *(s32 *)(*(u8 **)(arg0 + 0xD18) + 0x20) = arg3;
    }

    func_8005922C(*(u8 **)(arg0 + 0xD18), 0);
}
