#include "common.h"

void func_800144B8(void) {
    D_8009B0F4 &= 0x60;

    if ((D_8009B0F4 & 0x20) && !(D_8009B0F4 & 0x40)) {
        func_800143DC();

        if (D_8009B134 != 0) {
            if ((D_8009B0F4 & 0x10) && (D_8009B0F4 & 0x80000)) {
                func_80015010();
            }
            D_8009B134 = 0x80;
        }
    } else {
        D_8009B134 = 0;
    }
}
