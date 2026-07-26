#include "common.h"

s32 func_8003FCD8(void) {
    u8 v = D_8009B3ED;

    if (!(v & 0x80)) {
        D_8009B3ED = v | 0x80;
        D_8009B3C0 = 0x29;
    }

    return func_8003F8D4();
}
