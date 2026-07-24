#include "common.h"

void func_8004701C(s32 arg0) {
    u8 *p = D_8009B45C;

    p[0x4A] = (p[0x4A] & 0xF0) | arg0;
}
