#include "common.h"

s32 func_8005F1B8(s32 arg0, s32 arg1) {
    u8 sp10[8];
    s32 d;
    s32 x;

    if (arg0 < 2) {
        func_80059000(arg0, sp10);
        if (*(s16 *)(sp10 + 6) >= 0x32) {
            *(s16 *)(sp10 + 6) = 0x32;
        }
        *(u16 *)(sp10 + 6) -= 0x12C;
        d = *(s16 *)(sp10 + 6);
        if (d != 0) {
            x = arg1;
            if (d > 0) {
                x = arg1 / 2;
            }
            arg1 += d * x / 0x2EE;
        }
    }
    return arg1;
}
