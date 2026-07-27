#include "common.h"

s32 func_80073758(s32 arg0, u8 *arg1, u32 arg2) {
    s32 total = 0;

    while (arg2 != 0) {
        s32 n = arg2;
        s32 got;

        if (arg2 > 0x8000) {
            n = 0x8000;
        }

        got = func_80073818(0, arg0, n, arg1);

        if (got == -1) {
            return -1;
        }

        total += got;
        arg1 += got;
        arg2 -= got;

        if (got < n) {
            break;
        }
    }

    return total;
}
