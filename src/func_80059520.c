#include "common.h"

u8 *func_80059520(s32 arg0) {
    u8 *p = &D_800F2C40[arg0 * 3616];
    u8 *q = p + 0xDC0;
    u8 m = p[0xDC7] % 6;

    if (m != 0 && q[3] == 0) {
        q = p + 0xDC4;
    }

    return q;
}
