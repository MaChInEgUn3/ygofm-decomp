#define D_8009B254_IS_SCALAR
#include "common.h"

s32 func_8002892C(void) {
    u8 v = D_8009B254;

    if (v == 0) {
        return 0;
    }

    if ((v & 0x80) == 0) {
        D_8009B24A = v;
        D_8009B254 = v | 0x80;
        D_8009B248 = 0;

        return 1;
    }

    if (v & 0x40) {
        D_8009B254 = 0;

        return 0;
    }

    D_80090B3C[D_8009B24A]();

    return 1;
}
