#include "common.h"

void func_800611D0(s32 arg0) {
    u8 *a;
    u8 *b;

    D_801D5708[2] = 4;
    D_801D5708[1] = 4;
    D_801D5708[0] = 4;
    D_801D5708[arg0] = 0;
    a = func_80035BE4(3, 0x20, 0x58, 0x40, 0xA0, 0x80);
    a[0x59] = 0x15;
    func_80039A14(a);
    b = func_800400AC(func_8004002C(), 2);
    func_800404CC(b, *(s16 *)(a + 0x3C) + 8, *(s16 *)(a + 0x40), 0,
                  4, 0xD, 0xC, 0x208);
    *(u16 *)(b + 8) |= 0x28;
    func_80042918(b);
    func_800428EC(b, 0x14);
    *(u8 **)(a + 0x2C) = b;
}
