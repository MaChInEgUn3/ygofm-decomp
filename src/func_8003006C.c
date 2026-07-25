#include "common.h"

/* Reads a little-endian halfword from the stream and advances the cursor. */
s32 func_8003006C(void) {
    u8 *p = D_8009B290;

    D_8009B290 = p + 2;
    return p[0] | (p[1] << 8);
}
