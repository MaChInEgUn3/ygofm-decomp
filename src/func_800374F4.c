#include "common.h"

u8 *func_800374F4(u8 *arg0) {
    u8 *p = func_800400AC(func_8004006C(), 2);

    func_800404CC(p, *(s16 *)(arg0 + 0x3C) + *(s16 *)(arg0 + 0x3E) - 0x10,
                  *(s16 *)(arg0 + 0x40) + *(s16 *)(arg0 + 0x42) - 0x10,
                  3, 0, 0, 0xB, 0x20C);

    *(u16 *)(p + 8) |= 0x28;

    func_80042918(p);
    func_800428EC(p, (s8)(arg0[0x59] + 1));

    return p;
}
