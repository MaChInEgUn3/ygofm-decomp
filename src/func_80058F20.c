#include "common.h"

u8 *func_80058F20(s32 arg0, s32 arg1) {
    u8 *p = &D_800F2C40[arg0 * 3616];

    if (p[0xE17] < arg1) {
        arg1 = p[0xE18];
    }

    return *(u8 **)(p + 0xD14) + arg1 * 80;
}
