#include "common.h"

s32 func_80041464(u8 *arg0, u8 *arg1) {
    *(s16 *)(arg0 + 0x58) = 0;
    *(s32 *)(arg0 + 4) ^= 0x800000;
    *(s32 *)(arg0 + 0x50) = *(s32 *)(arg0 + 0x54) + ((arg1[1] << 8) | arg1[0]);

    return 1;
}
