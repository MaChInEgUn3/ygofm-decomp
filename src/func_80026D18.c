#include "common.h"

s32 func_80026D18(u8 **out, s32 arg1, s32 arg2) {
    s32 count = 0;
    s32 i = 0;
    s32 d = D_8009B1D5;
    s32 *t = D_801D4244;
    u8 *r = D_801A7AD8 + (d * 15 + arg1) * 28;
    s32 k;

    do {
        /* The `do { } while (0)` is load-bearing and NOT a macro leftover:
         * it is 2 differences without it and 6 with `{ }` or `if (1) { }`
         * instead, because gcc's loop pass sees the extra loop node and
         * numbers the blocks differently. Coupled with `count` being
         * initialised before `i` -- that alone is 6. Found by the permuter;
         * see docs/PARKED.txt's former entry. */
        do {
            if (*(u16 *)(r + 0x16) & 0x8000) {
                if (arg2 < 0 || (k = *(s16 *)(r + 0xC), k--, ((t[k] >> 26) & 0x1F) == arg2)) {
                    *out++ = r;
                    count++;
                }
            }
        } while (0);
        i++;
        r += 0x1C;
    } while (i < 5);

    *out = 0;

    return count;
}
