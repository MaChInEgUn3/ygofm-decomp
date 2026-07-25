#include "common.h"

s32 func_80058DD8(s32 arg0) {
    u8 *p = &D_800F2C40[arg0 * 3616];

    if (p[0xE14] != 0xFF) {
        return 2;
    }

    return p[0xE1F] != 0;
}
