#include "common.h"

s32 func_800705AC(void) {
    u8 *p = D_800F5BE8[0].cursor;

    D_800F5BE8[0].cursor = p + 2;

    return p[0] | (p[1] << 8);
}
