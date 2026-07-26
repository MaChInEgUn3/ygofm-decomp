#include "common.h"

s16 func_80049F50(void) {
    if (*(s16 *)(D_8009B458 + 0x7E2) == 1) {
        s32 v = (s16)func_8004CABC();

        if (v == 3) {
            *(s16 *)(D_8009B458 + 0x7E2) = v;
        }
    }

    return *(s16 *)(D_8009B458 + 0x7E2);
}
