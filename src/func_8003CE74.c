#include "common.h"

/* Mixes the two words of PRNG state in place and returns the new low word. */
u32 func_8003CE74(void) {
    u32 *p = D_8009AF64;
    u32 hi = p[1];
    u32 lo = D_8009AF64[0];
    u32 v;

    v = ((hi << 31) | (lo >> 1)) ^ (lo << 12);
    hi += hi + (lo & 1);
    v ^= v >> 20;
    p[1] = hi;
    D_8009AF64[0] = v;

    return v;
}
