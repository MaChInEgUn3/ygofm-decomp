#include "common.h"

void func_800595C8(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    u8 *p = &D_800F2C40[arg0 * 3616];

    arg1 = (arg1 < -0x1000) ? -0x1000 : ((arg1 > 0x3000) ? 0x3000 : arg1);
    *(s32 *)(p + 0xDA0) = arg1;
    arg2 = (arg2 < -0x1000) ? -0x1000 : ((arg2 > 0x3000) ? 0x3000 : arg2);
    *(s32 *)(p + 0xDA4) = arg2;
    arg3 = (arg3 < -0x1000) ? -0x1000 : ((arg3 > 0x3000) ? 0x3000 : arg3);
    *(s32 *)(p + 0xDA8) = arg3;
    if (p[0xE11] != 4) {
        if (arg1 == 0x800 && arg2 == arg1 && arg3 == arg2) {
            p[0xE11] = 0;
        } else {
            p[0xE11] = 3;
        }
    }
}
