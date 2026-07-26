#include "common.h"

s32 func_80033998(void) {
    u8 *p = D_8009B2FC + 0x2D50;
    s32 i;

    for (i = 0; i < 0x28; i++) {
        if (p[0xD] == 0) {
            return 1;
        }
        p += 0x10;
    }

    return 0;
}
