#include "common.h"

void func_80038898(u8 *arg0) {
    u8 **pp = (u8 **)(arg0 + *(s8 *)(arg0 + 0x58) * 4);
    u8 *p = *pp;
    u8 v = *p;

    *pp = p + 1;
    D_8009B26C[0] = 5;
    D_8009B363[0] = v;
}
