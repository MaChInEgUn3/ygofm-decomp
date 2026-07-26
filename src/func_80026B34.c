#include "common.h"

s32 func_80026B34(void) {
    if (D_8009B220 & 0x8000) {
        s32 i = D_80090AD4[D_8009B1A8] * 2;

        if (D_8009B220 & 0x4000) {
            i++;
        }

        D_80090A5C[i]();
    }

    return D_8009B220;
}
