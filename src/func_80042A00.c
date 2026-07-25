#include "common.h"

/* Accumulates a 16.8 fixed-point position by its velocity. */
void func_80042A00(u8 *arg0) {
    s32 v = (*(s16 *)(arg0 + 0x30) << 8) | arg0[0x62];

    v += *(s16 *)(arg0 + 0x36);
    arg0[0x62] = v;
    *(s16 *)(arg0 + 0x30) = v >> 8;
}
