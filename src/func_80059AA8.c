#include "common.h"

s32 func_80059AA8(s32 arg0, s32 arg1) {
    u8 *base = D_800F2C40;
    u8 *p = base + arg0 * 3616;
    s32 old = p[0xE12];

    if (arg1 >= 0) {
        p[0xE12] = arg1;
    }

    return old;
}
