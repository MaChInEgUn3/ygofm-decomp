#include "common.h"

void func_80014294(u8 arg0) {
    if (arg0 == 5) {
        D_8009B130++;
        func_8007B1F4(0xD, &D_8009B11C, func_80014294, -1);
    } else if (arg0 == 2) {
        D_8009B100 = 4;
        D_8009B0F4 &= ~0x400;
    }
}
