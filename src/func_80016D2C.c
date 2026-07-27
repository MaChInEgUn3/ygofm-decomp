#include "common.h"

void func_80016D2C(u8 *arg0, u8 *arg1, s32 arg2, s32 arg3) {
    u8 buf[8];
    s32 i;

    func_800357E8(arg2, arg3, buf);

    i = arg3 - 1;

    if (i >= 0) {
        do {
            arg1[0xE] = buf[i] << 3;
            func_800849F0(arg1, *(s32 *)&D_800E9D90[arg0[0x17] * 4], *(u16 *)(arg0 + 0x14));
            *(u16 *)(arg1 + 4) = *(u16 *)(arg1 + 4) + 8;
            i--;
        } while (i >= 0);
    }
}
