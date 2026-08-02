#include "common.h"

void func_80029590(void) {
    s32 i = 0;
    u8 **slot = (u8 **)D_800EA1E8;

    for (; i < 8; i++, slot++) {
        u8 *p = func_800400AC(func_8004002C(), 2);

        func_800404CC(p, 8, (i >> 1) * 178 + 8, 0, 3, i, 0x19, 0x106);
        if (i & 1) {
            *(s16 *)(p + 0x30) = 0xA8;
        }
        *(s32 *)(p + 4) |= 0x1000000;
        *(u16 *)(p + 8) &= 0xFFF7;
        func_8004293C(p);
        func_800428EC(p, 0);
        slot[9] = p;
    }
}
