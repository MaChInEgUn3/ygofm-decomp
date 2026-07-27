#include "common.h"

void func_800316F0(u8 *arg0, s32 arg1, u8 *arg2, s32 arg3) {
    s32 i;

    arg0[0xF] = 0x70;
    i = arg3 - 1;

    if (i >= 0) {
        do {
            u8 c = arg2[i];

            if (c < 0xA) {
                arg0[0xE] = c * 8 - 0x80;
                func_800849F0(arg0, arg1, 0);
            }

            *(u16 *)(arg0 + 4) = *(u16 *)(arg0 + 4) + 8;
            i--;
        } while (i >= 0);
    }
}
