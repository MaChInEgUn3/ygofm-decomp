#include "common.h"

u8 *func_80019564(u8 *arg0) {
    u8 *p = func_800400AC(func_8004002C(), 1);

    func_80040510(p, *(s16 *)(arg0 + 0x30), *(s16 *)(arg0 + 0x32), 0x8C, 0xC4,
                  0, 0, 0x15, 0, 0);
    *(s16 *)(p + 0x18) = 0x46;
    *(s16 *)(p + 0x48) = 0x46;
    *(s16 *)(p + 0x1A) = 0x62;
    *(s16 *)(p + 0x4A) = 0x62;
    func_80042918(p);
    *(s32 *)(p + 4) |= 0x2000000;
    return p;
}
