#include "common.h"

/* Fills arg2 words with arg1. */
void func_8005B5FC(s32 *arg0, s32 arg1, s32 arg2) {
    s32 i = arg2 - 1;

    if (arg2 == 0) {
        return;
    }
    do {
        *arg0++ = arg1;
    } while (--i != -1);
}
