#include "common.h"

void func_8002E060(u8 *arg0, s32 arg1, s32 arg2) {
    u8 *p = func_800400AC(func_8004002C(), 2);

    func_800404CC(p, 0, 0, 2, 0, 0, arg1, arg2);
    func_800428EC(p, (s8)arg2);
    arg0[0x10] = 1;

    if (arg2 == 2) {
        *(s16 *)(arg0 + 4) = 1;
        *(s32 *)(p + 4) |= 0x50000000;
    } else {
        *(s16 *)(arg0 + 4) = 0;
        *(s32 *)(p + 4) |= 0x1000000;
    }

    *(u8 **)arg0 = p;
}
