#include "common.h"

s32 func_800282E8(void) {
    u8 v = D_8009B248;

    if (!(v & 0x80)) {
        D_8009B248 = v | 0x80;
        return 0;
    }
    return 1;
}
