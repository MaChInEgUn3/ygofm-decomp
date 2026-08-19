#include "common.h"

void func_80052528(void) {
    u8 *b;
    s32 x;
    s32 f;
    s32 v;
    s32 lo;
    s32 c;
    s32 d;

    if (*(s16 *)&D_8009B47C >= 0x801) {
        b = D_800F56F0;
        x = *(s32 *)(b + 0x10);
        f = 0;
        if (x >= -0xC7 && *(s32 *)(b + 4) < x) {
            if (x < -0x64) {
                f = (-200 - x) * 4096 / -100;
            } else {
                f = 0x1000;
            }
        }

        v = (f * 3755 + (0x1000 - f) * 3968) / 4096;
        lo = v - 0x10;
        c = *(s16 *)&D_8009B47C;
        d = v + 0x10;

        if (d < c) {
            d = d - c;
            if (d < -1) {
                d = -1;
            }
            func_80058434(1, 0, d, 0, 0);
        } else if (c < 0xEAB) {
            func_80058434(1, 0, 0xEAB - c, 0, 0);
        } else if (c < lo) {
            d = lo - c;
            if (d >= 5) {
                d = 4;
            }
            func_80058434(1, 0, d, 0, 0);
        }
    } else {
        func_80058434(1, 0, -4, 0, 0);
    }
}
