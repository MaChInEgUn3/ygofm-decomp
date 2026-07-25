#include "common.h"

void func_800590DC(s32 arg0) {
    u8 *p = &D_800F2C40[arg0 * 3616];
    s32 saved = p[0xE11];

    p[0xE11] = 1;
    func_800540B4(arg0);
    p[0xE11] = saved;
}
