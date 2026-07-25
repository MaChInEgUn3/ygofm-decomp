#include "common.h"

/* Sets the flag if clear, returning whether it was already set.
 * The clear case is the if body so the branch polarity matches. */
s32 func_80039AAC(u8 *arg0) {
    u8 v = arg0[0x13];

    if (!(v & 0x80)) {
        arg0[0x13] = v | 0x80;
        return 0;
    }
    return 1;
}
