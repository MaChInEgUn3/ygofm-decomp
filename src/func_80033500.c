#include "common.h"

s32 func_80033500(u8 *arg0) {
    u8 *p = arg0 + (*(s16 *)(arg0 + 0x2D3C) + *(s8 *)(arg0 + 0x2D48)) * 16;

    if (p[0xD] == 0) {
        return 0;
    }

    return *(s16 *)(p + 4);
}
