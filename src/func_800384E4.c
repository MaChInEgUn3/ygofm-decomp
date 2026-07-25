#include "common.h"

void func_800384E4(u8 *arg0) {
    u8 **pp;
    u8 *p;
    s32 v;

    *(u16 *)(arg0 + 0x34) &= 0xEFFF;
    pp = (u8 **)(arg0 + *(s8 *)(arg0 + 0x58) * 4);
    p = *pp;
    v = *p;
    *pp = p + 1;
    if (v != 0) {
        *(u16 *)(arg0 + 0x34) |= 0x1000;
    }
}
