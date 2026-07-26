#include "common.h"

s32 func_80058F74(s32 arg0) {
    u8 *p = D_800F2C40 + arg0 * 3616;
    s32 i = p[0xE18];

    return *(s32 *)(p + 0xD14) + i * 80;
}
