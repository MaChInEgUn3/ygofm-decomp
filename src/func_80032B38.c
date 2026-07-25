#include "common.h"

/* Sets the flag if clear, returning whether it was already set.
 * The clear case is the if body so the branch polarity matches. */
s32 func_80032B38(u8 *arg0) {
    u16 v = *(u16 *)(arg0 + 0x633E);

    if (!(v & 0x8000)) {
        *(u16 *)(arg0 + 0x633E) = v | 0x8000;
        return 0;
    }
    return 1;
}
