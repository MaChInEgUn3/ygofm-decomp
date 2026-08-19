#define D_8009B408_SIZED
#include "common.h"

void func_8003C628(void) {
    u8 *o;
    s8 v;

    o = func_800400AC(func_8004002C(), 2);
    func_800428A8(o, 0, 0, 0, 0, 0, 0x10, 0x100, D_801AF000);
    func_800428EC(o, -5);

    D_8009B37C = 1;
    v = D_8009B408[0];
    D_8009B37D = v;
    *(u16 *)(o + 8) = *(u16 *)(o + 8) | 0x28;
    if (v < 0) {
        D_8009B37D = 0;
    }
    D_8009B384 = 0;
    func_8003C4E0(0);

    o = func_800400AC(func_8004002C(), 2);
    func_800404CC(o, 0x18, 0x48, 3, 4, 0, 0xB, 0x20C);
    D_8009B388 = o;
    *(u16 *)(o + 8) = *(u16 *)(o + 8) | 0x28;

    o = func_800400AC(func_8004002C(), 1);
    func_80040510(o, 0x68, 0x48, 0x10, 0x10, 0x50, 0x80, 0xB, 0x210, 0xFC);
    D_8009B380 = o;
    func_8003C568(D_8009B384);
    func_8003FF08(0x7350);
}
