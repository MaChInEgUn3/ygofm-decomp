#include "common.h"

s32 func_80037C74(u8 *arg0) {
    if (*(s16 *)(arg0 + 0x38) >= *(s16 *)(arg0 + 0x3E)) {
        *(s16 *)(arg0 + 0x38) = 0;
        *(u16 *)(arg0 + 0x3A) = *(u16 *)(arg0 + 0x3A) + arg0[0x5B];
    }

    if (*(s16 *)(arg0 + 0x42) < *(s16 *)(arg0 + 0x3A) + arg0[0x5B]) {
        *(u16 *)(arg0 + 0x3A) = *(u16 *)(arg0 + 0x3A) - arg0[0x5B];

        return 1;
    }

    return 0;
}
