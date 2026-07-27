#include "common.h"

void func_80045114(void) {
    u8 *p = D_8009B45C;
    s32 n;

    if (!(p[0x4A] & 0x80)) {
        return;
    }

    n = *(s16 *)(p + 0x4C);

    if (p[n * 48 + 0x80] == 0x11) {
        return;
    }

    if (n > 0) {
        if (p[(n - 1) * 48 + 0x80] == 0x11) {
            return;
        }

        if (n >= 2) {
            if (p[(n - 2) * 48 + 0x80] == 0x11) {
                return;
            }
        }
    }

    {
        u8 buf[0x30];

        func_8004503C(-0x20, 0, 1);
        buf[0] = 0x11;
        func_80045BE8(buf);
    }
}
