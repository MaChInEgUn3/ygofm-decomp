#include "common.h"

void func_8003C950(void) {
    u8 *o;

    o = func_800400AC(func_8004002C(), 3);
    func_80040510(o, 0, 0, 0x140, 0xF0, 0, 0, 0x10, 0, 0xF0);
    *(s32 *)(o + 4) = *(s32 *)(o + 4) | 0x1000000;

    o = func_800400AC(func_8004002C(), 2);
    func_800428A8(o, 0x1C0, 0xC0, 0, 0, 0, 0x12, 1, D_801AF000);
    o[0x5E] = 0x80;
    func_800428EC(o, 4);
    o[0x6C] = 0;
    *(u16 *)(o + 8) = *(u16 *)(o + 8) | 0x28;
    func_800429D8(o);
    D_8009B378 = (s32)o;
    func_8003FF08(0x7300);
    func_800157DC();
    D_800E9ECF[0] = 2;
}
