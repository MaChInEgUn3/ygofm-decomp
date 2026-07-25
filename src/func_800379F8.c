#include "common.h"

void func_800379F8(u8 *arg0) {
    u8 v = arg0[0x51];
    s32 n;

    if (!(v & 0x80)) {
        arg0[0x51] = v | 0x80;
        D_8009B322 = func_80036D3C(arg0);
    }
    n = D_8009B322 - 1;
    D_8009B322 = n;
    if ((s16)n == 0) {
        arg0[0x51] = 0;
    }
}
