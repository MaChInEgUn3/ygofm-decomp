#include "common.h"

void func_80039BE0(u8 *arg0) {
    u8 v;

    if (func_80039AAC(arg0) == 0) {
        arg0[0x15] = 2;
        *(s32 *)(arg0 + 4) = 0x80808080;
        arg0[0x14] = 0;
    }

    v = arg0[0x13];

    if (!(v & 0x40)) {
        s32 d = arg0[4] - D_8009B0D8[0] * 16;

        if (d <= 0) {
            arg0[0x13] = v | 0x40;
            d = 0;
        }

        arg0[4] = d;
        arg0[5] = d;
    } else {
        s32 d = arg0[6] - D_8009B0D8[0] * 16;

        if (d <= 0) {
            func_80039AD4(arg0);
            d = 0;
        }

        arg0[6] = d;
        arg0[7] = d;
    }
}
