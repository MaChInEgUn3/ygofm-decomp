#define D_8009B33A_IS_VOLATILE
#define D_8009B350_IS_VOLATILE
#include "common.h"

void func_80037D2C(u8 *arg0) {
    u8 **slot;
    u8 *p;
    s32 v;
    s32 h;

    slot = (u8 **)(arg0 + *(s8 *)(arg0 + 0x58) * 4);
    h = D_8009B33A - 0xF0;
    p = *slot;
    v = *p;
    *slot = p + 1;
    D_8009B33A = v | (h << 8);
    D_8009B350 = -1;
}
