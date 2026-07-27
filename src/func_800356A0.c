#include "common.h"

/* memcpy in words, then a tail that over-copies by up to three bytes. Same
 * shape as func_80035748: `len >> 2` is recomputed in every switch arm rather
 * than held in a variable, and each case carries its own copy of the body so
 * the case labels stay distinct. */
void func_800356A0(u8 *dst, u8 *src, u32 len) {
    s32 i = (len >> 2) - 1;

    for (; i >= 0; i--) {
        *(s32 *)(dst + i * 4) = *(s32 *)(src + i * 4);
    }

    switch (len & 3) {
    case 0:
        break;

    case 1:
        *(s32 *)(dst + (len >> 2) * 4) = *(s32 *)(src + (len >> 2) * 4);
        break;

    case 2:
        *(s32 *)(dst + (len >> 2) * 4) = *(s32 *)(src + (len >> 2) * 4);
        break;

    case 3:
        *(s32 *)(dst + (len >> 2) * 4) = *(s32 *)(src + (len >> 2) * 4);
        dst[len - 1] = src[len - 1];
        break;
    }
}
