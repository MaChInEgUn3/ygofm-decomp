#include "common.h"

s32 func_80045BE8(u8 *arg0) {
    u8 *p = D_8009B45C;
    s32 n = *(s16 *)(p + 0x4C);

    if (n < 0x10) {
        p[n * 48 + 0x80] = arg0[0];

        {
            u8 *q = D_8009B45C;

            *(Rec48 *)(q + *(s16 *)(q + 0x4C) * 48 + 0x80) = *(Rec48 *)arg0;
        }

        {
            u8 *r = D_8009B45C;

            *(u16 *)(r + 0x4C) = *(u16 *)(r + 0x4C) + 1;
        }

        return 1;
    }

    return 0;
}
