#include "common.h"

void func_800382A8(u8 *arg0) {
    u8 **pp;
    s32 c;

    *(u16 *)(arg0 + 0x34) &= 0xFEFF;
    pp = (u8 **)(arg0 + *(s8 *)(arg0 + 0x58) * 4);
    c = **pp;
    *pp = *pp + 1;

    if (c == 1) {
        arg0[0x5A] = 8;
        arg0[0x5B] = 8;
    } else if (c == 2) {
        arg0[0x5A] = 8;
        arg0[0x5B] = 0xC;
    }

    if (c == 1) {
        *(u16 *)(arg0 + 0x34) |= 0x100;
    }
}
