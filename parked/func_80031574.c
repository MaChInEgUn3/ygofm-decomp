#include "common.h"

void func_80031574(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    u8 *o;
    u8 *e;
    s32 k;

    o = func_800400AC(func_8004002C(), 1);
    func_80040510(o, arg1, arg2, 0x10, 0x10, 0, 0xC8, 0xB, 0x260, 0xFC);

    k = (D_801D4244[arg0 - 1] >> 26) & 0x1F;

    switch (k) {
    case 0x14:
    case 0x17:
        *(s16 *)(o + 0x40) = *(u16 *)(o + 0x40) + 0x10;
        break;
    case 0x15:
        *(s16 *)(o + 0x40) = *(u16 *)(o + 0x40) + 0x20;
        break;
    case 0x16:
        *(s16 *)(o + 0x40) = *(u16 *)(o + 0x40) + 0x30;
        break;
    }

    func_80042918(o);
    func_800428EC(o, 0xA);

    e = o;
    *(s32 *)(e + 0x44) = 0;
    *(s16 *)(e + 0x18) = arg3;
    *(s16 *)(e + 0x1A) = arg4;
    *(s32 *)(e + 0x24) = (s32)func_800313E8;
    *(s32 *)(e + 4) = *(s32 *)(e + 4) & 0xF7FFFFFF;
    *(u16 *)(e + 8) = *(u16 *)(e + 8) & 0xFFF7;
}
