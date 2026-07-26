#include "common.h"

s32 func_80075D30(u32 arg0) {
    u32 *p;

    arg0 <<= D_80092BB0[0];

    if (D_80092BF0[0] == 0) {
        return 0;
    }

    p = D_80092BF0[0];
    while (1) {
        u32 h = p[0];

        if (!(h & 0x80000000)) {
            if (h & 0x40000000) {
                break;
            }

            h &= 0x0FFFFFFF;
            if (h >= arg0) {
                return 1;
            }
            if (arg0 < h + p[1]) {
                return 1;
            }
        }
        p += 2;
    }

    return 0;
}
