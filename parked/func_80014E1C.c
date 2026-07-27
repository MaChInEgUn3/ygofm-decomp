#include "common.h"

void func_80014E1C(s32 arg0, u8 *arg1, s32 arg2, s32 arg3, void *arg4,
                   s32 arg5, s32 arg6) {
    u8 *p;

    D_8009B0F4 |= 0x40;
    if (D_8009B10C == 0) {
        if (((D_8009B0F4 & 0x2000030) | D_8009B134) != 0) {
            p = (u8 *)0;
            goto out;
        }
    } else {
        ((void (*)(void))D_8009B10C)();
    }
    func_80013998(D_800E9E60, arg0, arg1, arg2, arg3, arg4, arg5, arg6);
    p = D_800E9E60;
out:
    D_8009B0F4 = *(s32 *)(p + 0x2C) | 0x10;
}
