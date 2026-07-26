#include "common.h"

s32 func_80036D3C(u8 *arg0) {
    u8 **slot = (u8 **)(arg0 + *(s8 *)(arg0 + 0x58) * 4);
    u8 *p = *slot;

    *slot = p + 2;

    return p[0] | (p[1] << 8);
}
