#include "common.h"

s32 func_8002A6B8(void) {
    s8 a = D_8009B259;
    s8 b = D_8009B258;
    s8 q;
    s8 r;
    s32 t;

    q = a / 10;
    r = a % 10;
    t = q * 200 + r * 10;

    if (b >= 10) {
        t += 100;
    }

    t = t + 1 + (s8)(b % 10);

    if (t >= 0x2D3) {
        return 0;
    }

    return t;
}
