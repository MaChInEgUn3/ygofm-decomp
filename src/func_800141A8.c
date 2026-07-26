#include "common.h"

void func_800141A8(u8 arg0) {
    if (arg0 == 5) {
        D_8009B130++;
        func_8007B1F4(9, 0, func_800141A8, -1);
    } else if (arg0 == 2) {
        D_800E9EA7[0] = 1;
        D_8009B0F4 &= ~0x400;
    }
}
