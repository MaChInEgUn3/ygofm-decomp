#include "common.h"

void func_8005C6A0(s32 *arg0, u8 *arg1) {
    u8 *sp10[2];
    s32 n;

    if (*arg0 != 0x3800000) {
        *(ByteFn *)arg0[1] = func_80089E20;
    } else {
        *(ByteFn *)arg0[1] = func_8005C7BC;
        n = func_80089DD8(arg1 + ((arg1[0xE1B] << 2) + 0x1E0), arg0[1]);
        if (func_80089D30(arg0[1], 0) != 0) {
            while (1) {
                if (func_80089D30(0, sp10) == 0) {
                    break;
                }
                *(ByteFn *)sp10[1] = func_8005C768((s32)sp10[0]);
            }
            arg1[0xE1B] += n;
        }
    }
}
