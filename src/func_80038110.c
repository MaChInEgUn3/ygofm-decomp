#include "common.h"

void func_80038110(u8 *arg0) {
    u8 **slot = (u8 **)(arg0 + *(s8 *)(arg0 + 0x58) * 4);
    u8 *p = *slot;
    s32 v = *p;

    *slot = p + 1;
    *(u16 *)(arg0 + 0x38) += v;
}
