#include "common.h"

s32 func_8002CB80(s32 arg0, s32 arg1) {
    s32 n;

    arg0 -= 7;
    if (arg0 >= 0) {
        n = 4;
        arg1 -= 7;
        if (arg1 < 0) {
            return 0;
        }
    } else {
        n = 6;
        arg0 += n;
        arg1 -= 1;
        if (arg1 >= n) {
            return 0;
        }
    }

    arg0++;
    if (arg0 >= n) {
        arg0 = 0;
    }
    if (arg0 == arg1) {
        return 500;
    }

    arg0 -= 2;
    if (arg0 < 0) {
        arg0 += n;
    }
    if (arg0 == arg1) {
        return -500;
    }

    return 0;
}
