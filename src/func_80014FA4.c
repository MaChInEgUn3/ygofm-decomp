#include "common.h"

void func_80014FA4(void) {
    if (((D_8009B0F4 & 0x2000030) | D_8009B134) != 0) {
        if ((D_8009B0F4 & 0x10) && (D_8009B0F4 & 0x80000)) {
            func_80015010();
        }

        D_8009B134 = 0x80;
    }
}
