#include "common.h"

void func_800380D4(u8 *arg0) {
    u8 **slot = (u8 **)(arg0 + *(s8 *)(arg0 + 0x58) * 4);
    u8 *p;
    u8 v;

    *(s16 *)(arg0 + 0x38) = 0;
    p = *slot;
    v = *p;
    *slot = p + 1;
    *(u16 *)(arg0 + 0x3A) += (s8)v;
}
