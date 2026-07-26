#include "common.h"

/* memset in words, then a tail that over-writes by up to three bytes.
 * `len >> 2` is recomputed in every switch arm rather than held in a
 * variable, and the fill word is a variable distinct from `c` -- with
 * `c = ... | c` the final `or` reads $a1 first, which retail does not. */
void func_80035748(u8 *dst, s32 c, u32 len) {
    s32 i = (len >> 2) - 1;
    s32 v;

    c &= 0xFF;
    v = (c << 24) | (c << 16) | (c << 8) | c;

    for (; i >= 0; i--) {
        *(s32 *)(dst + i * 4) = v;
    }

    switch (len & 3) {
    case 0:
        break;

    case 1:
        *(s32 *)(dst + (len >> 2) * 4) = v;
        break;

    case 2:
        *(s32 *)(dst + (len >> 2) * 4) = v;
        break;

    case 3:
        *(s32 *)(dst + (len >> 2) * 4) = v;
        dst[len - 1] = v;
        break;
    }
}
