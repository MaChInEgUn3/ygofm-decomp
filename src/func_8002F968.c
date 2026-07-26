#include "common.h"

void func_8002F968(void) {
    s32 v;

    if (func_8002E3B4() == 0) {
        u8 *p = D_8009B290;

        D_8009B290 = p + 2;
        D_8009B278 = p[0] | (p[1] << 8);
    }

    v = D_8009B278 - 1;
    D_8009B278 = v;
    if ((s16)v <= 0) {
        D_8009B27C = 0;
    }
}
