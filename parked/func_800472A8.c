#include "common.h"

void func_800472A8(s32 arg0) {
    if (D_8009B45C[0x4A] & 2) {
        if (arg0 & 0x8000) {
            func_80045334(arg0 & 0xFFFF);
        } else {
            if ((u32)(arg0 & 0xFFFF) >= 0x7000) {
                arg0 -= 0x7000;
            }

            func_80049138(arg0, 1);
        }
    }
}
