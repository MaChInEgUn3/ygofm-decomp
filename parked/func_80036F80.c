/* Best with -fno-schedule-insns: 21 differing. */
#include "common.h"

void func_80036F80(u8 *arg0) {
    s32 c;
    s32 q;

    if ((D_8009B336 >> D_8009B34D) & 1) {
        c = 0xC0C0;
    } else {
        c = 0xC0;
    }

    *(s32 *)(*(u8 **)(arg0 + 0x30) + 0xC) = c;
    *(s32 *)(*(u8 **)(arg0 + 0x30) + 0x3C) = c;
    *(s32 *)(*(u8 **)(arg0 + 0x30) + 0x44) = c;

    q = c / 4;
    *(s32 *)(*(u8 **)(arg0 + 0x30) + 0x2C) = q;
    *(s32 *)(*(u8 **)(arg0 + 0x30) + 0x34) = q;
    *(s32 *)(*(u8 **)(arg0 + 0x30) + 0x4C) = q;
    *(s32 *)(*(u8 **)(arg0 + 0x30) + 0x54) = q;
    func_80036DBC(arg0);
}
