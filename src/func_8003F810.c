#include "common.h"

s32 func_8003F810(void) {
    s32 r = func_8003F70C();

    if (r != 0) {
        if (r == 1) {
            u8 *p = D_801D0200;

            func_800356A0(p, D_801D3200, 0x680);
            func_8003D0F4(p);
        }

        return r;
    }

    return 0;
}
