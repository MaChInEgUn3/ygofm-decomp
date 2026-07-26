#include "common.h"

u8 *func_8002E3FC(void) {
    u8 *p = func_800400AC(func_8004006C(), 2);

    func_800404CC(p, 0x10, 0xB0, 0, 0, 0, 0xD, 0x100);
    *(u16 *)(p + 8) |= 8;
    func_80042918(p);

    return p;
}
