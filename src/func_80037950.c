#include "common.h"

void func_80037950(u8 *arg0) {
    u8 *p = D_8009B328;
    u8 v = p[0x32];

    if (!(v & 3)) {
        p[0x32] = v | 0x10;
        D_8009B328[0x33] = 4;
        arg0[0x51] = 8;
    }
}
