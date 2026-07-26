#include "common.h"

void func_800471D0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4,
                   s32 arg5) {
    Cmd2C c;

    func_8004503C(-0x20, 0, 1);
    *(u16 *)(D_8009B45C + 0x40) |= 2;
    c.unk0 = 0x20;
    c.unk10 = arg5;
    c.unk14 = arg2;
    c.unk20 = arg1;
    c.unk28 = arg4;
    c.unk1C = arg0;
    c.unk24 = arg3;
    func_80045BE8(&c);
}
