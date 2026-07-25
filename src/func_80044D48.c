#include "common.h"

void func_80044D48(void) {
    u8 *p;

    func_80044DA0();
    func_80044DC0(0xFF);
    p = D_8009B45C;
    *(u8 **)(p + 0x153C) = p + 0x53C;
    *(u8 **)(p + 0x1540) = p + 0x73C;
    *(u8 **)(p + 0x1544) = p + 0x93C;
    *(s16 *)(p + 0x512) = 0;
    *(u8 **)(p + 0x1548) = p + 0xB3C;
}
