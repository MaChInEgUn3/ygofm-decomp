#include "common.h"

u8 *func_800591C0(s32 arg0, u32 arg1) {
    u8 *p;

    if (arg1 >= 3) {
        arg1 = 0;
    }

    p = D_800F39B0 + arg0 * 3616;

    return p + arg1 * 16;
}
