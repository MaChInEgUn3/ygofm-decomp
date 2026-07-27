#include "common.h"

s32 func_80043DA0(s32 *arg0, s32 arg1) {
    do {
        if (func_80073880(arg0[0]) == 1) {
            return 0;
        }

        if (func_80073880(arg0[1]) == 1) {
            return 1;
        }

        if (func_80073880(arg0[2]) == 1) {
            return 2;
        }

        if (func_80073880(arg0[3]) == 1) {
            return 3;
        }
    } while (arg1 == 0);

    return -1;
}
