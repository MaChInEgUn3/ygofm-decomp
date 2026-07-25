#include "common.h"

void func_80030E30(void) {
    u8 v = D_8009B2EB;

    if (!(v & 0x80)) {
        D_8009B2EB = v | 0x80;
        D_8009B254[0] = 3;
    }
    if (func_8002892C() == 0) {
        D_8009B2EB = 0;
    }
}
