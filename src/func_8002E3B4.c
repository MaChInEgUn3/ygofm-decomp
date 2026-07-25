#include "common.h"

/* Sets the flag if clear, returning whether it was already set.
 * The clear case is the if body so the branch polarity matches. */
s32 func_8002E3B4(void) {
    u16 v = D_8009B27C;

    if (!(v & 0x8000)) {
        D_8009B27C = v | 0x8000;
        return 0;
    }
    return 1;
}
