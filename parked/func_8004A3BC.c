#include "common.h"

s16 func_8004A3BC(u8 *arg0, s32 arg1) {
    s32 b = arg1 & 0xFF;

    if (b < 0x40) {
        if (arg0[0x11] == 0) {
            return 0;
        }

        return -((arg0[0x11] * 2) * (0x40 - b));
    }

    if (b != 0x40) {
        if (arg0[0x10] == 0) {
            return 0;
        }

        return (arg0[0x10] * 2) * (b - 0x3F);
    }

    return 0;
}
