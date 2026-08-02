#include "common.h"

void func_800610E0(s32 arg0) {
    u8 *a;
    u8 *b;

    D_8009B34E = arg0;
    a = func_80035BE4(3, 0xA, 0x30, 0x78, 0x120, 0x10);
    a[0x59] = 0x12;
    func_80039A14(a);
    b = func_800400AC(func_8004002C(), 2);
    func_800404CC(b, *(s16 *)(a + 0x3C) + arg0 * 160, *(s16 *)(a + 0x40), 0,
                  4, 0xE, 0xC, 0x208);
    *(u16 *)(b + 8) |= 0x28;
    func_80042918(b);
    func_800428EC(b, 0x11);
    *(u8 **)(a + 0x2C) = b;
}
