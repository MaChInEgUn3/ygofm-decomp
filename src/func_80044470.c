#include "common.h"

s32 func_80044470(s32 arg0, s32 arg1, u8 *arg2, s32 *arg3) {
    u8 sp10[32];
    s32 i;
    s32 n;

    func_8008F200(sp10, D_80010538, arg0, arg1);

    i = 5;
    while ((u8 *)func_80073AC0(sp10, arg2) != arg2) {
        i--;
        if (i < 0) {
            return 0;
        }
    }

    i = 5;
    n = 1;
    arg2 += 0x28;
    do {
        if ((u8 *)func_80073920(arg2) != arg2) {
            i--;
            if (i < 0) {
                break;
            }
        } else {
            i = 5;
            arg2 += 0x28;
            n++;
        }
    } while (n < 0xF);

    if (arg3 != (s32 *)0) {
        *arg3 = n;
    }
    return n;
}
