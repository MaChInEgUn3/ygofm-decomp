#include "common.h"

void func_800490F0(s16 arg0, u8 arg1) {
    u8 *p = D_8009B45C;

    *(s16 *)(p + 0x1582) = arg0;
    p[0x1584] = arg1;
}
