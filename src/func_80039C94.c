#include "common.h"

void func_80039C94(u8 *arg0) {
    if (func_80039AAC(arg0) == 0) {
        s32 a;
        s32 b;

        arg0[0x15] = 1;
        a = *(u16 *)(arg0 + 0xC);
        b = *(u16 *)(arg0 + 0xE);
        arg0[8] = 0;
        arg0[9] = 0;
        arg0[0xA] = 0;
        arg0[4] = ((s16)a >> 4) + ((s16)b >> 3) + 1;
    }

    if (!(arg0[0x13] & 0x40)) {
        s32 v = arg0[4] - 1;

        arg0[4] = v;

        if ((u8)v == 0) {
            arg0[0x13] |= 0x40;
        }
    } else {
        s32 v = arg0[8] + 4;

        arg0[0xA] = v;
        arg0[9] = v;
        arg0[8] = v;

        if (v >= 0x40) {
            func_80039AD4(arg0);
        }
    }
}
