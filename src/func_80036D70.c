#include "common.h"

/* Reads a little-endian word from the stream and advances the cursor. */
s32 func_80036D70(u8 *arg0) {
    u8 **pp = (u8 **)(arg0 + *(s8 *)(arg0 + 0x58) * 4);
    u8 *p = *pp;

    *pp = p + 4;

    return (p[3] << 24) | (p[2] << 16) | (p[1] << 8) | p[0];
}
