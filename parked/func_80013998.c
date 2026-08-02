#include "common.h"

u8 *func_80013998(u8 *arg0, s32 arg1, u8 *arg2, s32 arg3, s32 arg4, void *arg5,
                  s32 arg6, s32 arg7) {
    *(u8 **)(arg0 + 0x18) = arg2;
    func_80013940(arg0, arg1, arg3, -arg4);
    arg0[0x46] = 1;
    arg0[0x47] = 0;
    *(s16 *)(arg0 + 0x44) = 0;
    *(s32 *)(arg0 + 0x1C) = 0;
    *(void **)(arg0 + 0x20) = arg5;
    *(s32 *)(arg0 + 0x40) = arg6;
    if (arg7 != 0) {
        if (arg1 & 0x1000000) {
            *(s32 *)(arg0 + 0x34) = arg7;
        } else {
            *(s32 *)(arg0 + 0x1C) = *(s32 *)(arg0 + 0x10);
            if (arg7 < 0) {
                arg0[0x46] = 1;
                *(s32 *)(arg0 + 0xC) = arg7;
                *(s32 *)(arg0 + 8) = arg7;
            } else {
                arg1 |= 0x10000;
                arg0[0x46] = 2;
                *(s16 *)(arg0 + 0x32) = (u32)arg7 >> 16;
                *(s16 *)(arg0 + 4) = 0x40;
                *(s16 *)(arg0 + 0x30) = arg7;
                *(s16 *)(arg0 + 6) = 0x10;
                *(s32 *)(arg0 + 8) = D_8009B118;
                *(s32 *)(arg0 + 0xC) = D_8009B118 + 0x800;
            }
        }
    }
    *(s32 *)(arg0 + 0x2C) = arg1;
    return arg0;
}
