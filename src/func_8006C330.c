#include "common.h"

/* Averages three bytes pairwise into the destination. */
void func_8006C330(u8 *arg0, u8 *arg1, u8 *arg2) {
    arg0[0] = (arg1[0] + arg2[0]) >> 1;
    arg0[1] = (arg1[1] + arg2[1]) >> 1;
    arg0[2] = (arg1[2] + arg2[2]) >> 1;
}
