#include "common.h"

s32 func_80021810(s32 arg0) {
    u16 *p = (u16 *)(arg0 * 1460 + (s32)D_8017878C);
    s32 limit = (func_8008E590() & 0x7FF) + 1;
    s32 sum = 0;
    s32 i = 0;

    do {
        sum += *p;

        if (sum >= limit) {
            return i + 1;
        }

        i++;
        p++;
    } while (i < 0x2D2);

    return 0;
}
