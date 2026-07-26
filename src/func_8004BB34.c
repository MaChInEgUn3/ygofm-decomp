#include "common.h"

u32 func_8004BB34(u8 *arg0) {
    s32 b = func_8004BAE4(arg0);
    s32 v;

    if (b == 0) {
        return 0;
    }

    if (b == 0xFF) {
        arg0[0x24] = 1;

        return 0;
    }

    v = b;

    if (!(v & 0x80)) {
        return v;
    }

    v &= 0x7F;

    do {
        b = func_8004BAE4(arg0);
        v = (v << 7) + (b & 0x7F);
    } while (b & 0x80);

    return v;
}
