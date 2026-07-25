#include "common.h"

s32 func_8005A878(s32 arg0) {
    u8 *p = D_800F2B20;
    s32 r = 0;

    if (p[1] == 0 && (arg0 != 0 || p[0] == 0 || *(u16 *)(p + 2) == 0)) {
        r = 1;
    }

    return r;
}
