#include "common.h"

s32 func_8001D5B4(u8 *arg0) {
    if (D_8009B162 != 0) {
        D_8009B160 = -1;

        return 1;
    }

    if (func_80024088(arg0, D_8009B160) == 0) {
        D_8009B160 = -1;

        if (D_8009B1D7 == *(s8 *)(arg0 + 0x10)) {
            if (D_8009B1D6 == *(s8 *)(arg0 + 0xF)) {
                return 0;
            }

            D_8009B160 = 0;

            if (D_8009B1D6 < *(s8 *)(arg0 + 0xF)) {
                D_8009B160 = 2;
            }
        } else {
            D_8009B160 = 1;

            if (D_8009B1D7 < *(s8 *)(arg0 + 0x10)) {
                D_8009B160 = 3;
            }
        }
    }

    return 1;
}
