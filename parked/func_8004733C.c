#include "common.h"

void func_8004733C(s32 arg0, s32 arg1) {
    if (D_8009B45C[0x4A] & 2) {
        if (arg0 & 0x8000) {
            func_800473CC(0x7000);
            func_80045208(arg0 & 0xFFFF, arg1);
        } else {
            if ((u32)(arg0 & 0xFFFF) >= 0x7000) {
                arg0 -= 0x7000;
            }

            func_80049230(arg0, arg1);
        }
    }
}
