#include "common.h"

/* Clears the slot and returns what was in it. */
s32 func_800498F8(void) {
    u8 *p = D_8009B458;
    s16 v = *(s16 *)(p + 0x4A4);

    if (v != -1) {
        *(s16 *)(p + 0x4A4) = -1;
    }
    return v;
}
