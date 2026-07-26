#include "common.h"

void func_80037D6C(u8 *arg0) {
    u8 **slot = (u8 **)(arg0 + *(s8 *)(arg0 + 0x58) * 4);
    u8 *p = *slot;
    u8 v = *p;

    *slot = p + 1;
    arg0[0x51] = v;
    D_8009B350 = 1;
}
