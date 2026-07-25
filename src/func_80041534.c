#include "common.h"

s32 func_80041534(u8 *arg0, u8 *arg1) {
    s32 hi;
    s32 lo;

    *(s32 *)(arg0 + 4) |= 0x8000000;
    arg0[0x22] = arg1[0];
    *(s16 *)(arg0 + 0x4A) = *(s8 *)(arg1 + 1);
    hi = arg1[3];
    lo = arg1[2];
    *(s32 *)(arg0 + 0x50) += 4;
    *(s16 *)(arg0 + 0x48) = (hi << 8) | lo;

    return 1;
}
