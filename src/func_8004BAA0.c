#include "common.h"

/* Compares arg2 bytes; returns the difference at the first mismatch. */
s32 func_8004BAA0(u8 *arg0, u8 *arg1, s32 arg2) {
    if (arg2 == 0) {
        return -1;
    }

    while (--arg2 != 0 && *arg0 == *arg1) {
        arg0++;
        arg1++;
    }

    return *arg0 - *arg1;
}
