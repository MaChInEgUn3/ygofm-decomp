#include "common.h"

void func_8002E918(void) {
    u8 *p = D_8009B290;
    u8 *q = p + 2;
    s32 a;
    s32 c;

    D_8009B290 = q;
    a = p[0] | (p[1] << 8);
    c = a;

    if (a & 0x4000) {
        func_8002CCE4(a & 0xBFFF);
    } else {
        s32 b;

        D_8009B290 = p + 4;
        b = p[2] | (q[1] << 8);

        if (func_8002CCA8(c) != 0) {
            D_8009B290 = D_801A8000 + b;
        }
    }

    D_8009B27C = 0;
}
