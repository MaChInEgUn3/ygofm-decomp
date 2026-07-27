#include "common.h"

s32 func_80044598(s32 arg0, s32 arg1, s32 arg2) {
    s32 i = 0;

    if (arg2 > 0) {
        do {
            if (func_8008E680(arg1, arg0) == 0) {
                return i;
            }

            i++;
            arg1 += 0x28;
        } while (i < arg2);
    }

    return -1;
}
