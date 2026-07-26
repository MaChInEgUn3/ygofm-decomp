#include "common.h"

s32 func_80032B60(u8 *arg0, u8 *arg1) {
    u32 a = *(u32 *)arg0;
    u32 b = *(u32 *)arg1;

    if (a == b) {
        if (D_801D4D8E[*(s16 *)(arg0 + 4) - 1] <
            D_801D4D8E[*(s16 *)(arg1 + 4) - 1]) {
            return -1;
        }

        return 1;
    }
    if (a < b) {
        return 1;
    }

    return -1;
}
