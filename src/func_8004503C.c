#include "common.h"

void func_8004503C(s16 arg0, u8 arg1) {
    u8 *p = D_8009B45C;

    *(s16 *)(p + 0x512) = arg0;
    p[0x49] = arg1;
}
