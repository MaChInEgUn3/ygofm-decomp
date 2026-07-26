#include "common.h"

void func_80014134(u8 arg0) {
    if (arg0 == 5) {
        D_8009B130++;
        func_8007B468(0xA0, &D_8009B104, 0x15, func_80014134, -1);
    } else if (arg0 == 2) {
        D_8009B0F4 &= ~0x400;
    }
}
