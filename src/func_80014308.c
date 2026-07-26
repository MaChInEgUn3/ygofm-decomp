#include "common.h"

void func_80014308(u8 arg0) {
    s32 v = arg0;

    if (v == 5) {
        D_8009B130++;
        func_8007B468(0x4A, &D_8009B104, 0x1B, func_80014308, -1);
    } else if (v == 2) {
        D_8009B100 = 5;
        D_8009B0F4 |= 0x1000;
        D_8009B0F4 &= ~0x400;
    }
}
