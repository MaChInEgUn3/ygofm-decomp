#include "common.h"

void func_80014220(u8 arg0) {
    s32 v = arg0;

    if (v == 5) {
        D_8009B130++;
        func_8007B1F4(9, 0, func_80014220, -1);
    } else if (v == 2) {
        D_8009B100 = v;
        D_8009B0F4 &= ~0x400;
    }
}
