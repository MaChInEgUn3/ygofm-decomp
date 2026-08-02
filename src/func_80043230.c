#include "common.h"

void func_80043230(u8 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 dx = *(s16 *)(arg0 + 0x36) - arg1;
    s32 dy = *(s16 *)(arg0 + 0x38) - arg2;
    s32 c;

    if (arg3 < 0) {
        c = func_800866A0(arg3 + 0x400);
        *(s16 *)(arg0 + 0x30) = *(u16 *)(arg0 + 0x36) - dx * c / 4096;
        *(s16 *)(arg0 + 0x32) = *(u16 *)(arg0 + 0x38) - dy * c / 4096;
    } else {
        c = -func_800866A0(arg3);
        *(s16 *)(arg0 + 0x30) = arg1 - dx * c / 4096;
        *(s16 *)(arg0 + 0x32) = arg2 - dy * c / 4096;
    }
}
