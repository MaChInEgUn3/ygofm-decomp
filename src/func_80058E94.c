#include "common.h"

s32 func_80058E94(s32 arg0) {
    u8 *p = D_800F2C40;

    return *(u16 *)(p + arg0 * 3616 + 0xE06) >> 4;
}
