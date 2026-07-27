#include "common.h"

u8 *func_800429BC(u8 *arg0, u8 *arg1) {
    s32 off = (arg1[1] << 8) | arg1[0];

    return *(u8 **)(arg0 + 0x54) + off;
}
