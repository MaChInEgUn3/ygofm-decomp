#include "common.h"

u8 *func_80018150(s32 arg0, s32 arg1) {
    u8 *p = func_800400AC(func_8004006C(), 2);

    func_800404CC(p, arg0, arg1, 0, 1, 0, 0x1F, 0x100);
    func_80042918(p);
    func_800428EC(p, -2);
    *(u16 *)(p + 8) |= 8;

    return p;
}
