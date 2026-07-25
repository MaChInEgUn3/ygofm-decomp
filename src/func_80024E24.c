#include "common.h"

/* Sets the flag if clear, returning whether it was already set. */
s32 func_80024E24(void) {
    u16 v = D_8009B220;

    if (!(v & 0x80)) {
        D_8009B220 = v | 0x80;
        return 0;
    }
    return 1;
}
