#include "common.h"

void func_8005969C(s32 arg0, s32 arg1) {
    u8 *p = &D_800F2C40[arg0 * 3616];

    if (arg1 < 4 || arg1 > 0x20) {
        arg1 = 8;
    }

    p[0xE0D] = arg1;
    if (p[0xE16] == 0x3E) {
        func_80059700(arg0, 1);
    }
}
