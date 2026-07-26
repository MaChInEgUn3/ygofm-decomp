#include "common.h"

void func_80031E5C(u8 *arg0) {
    u8 *p;

    D_801D5608[0] = *(s32 *)(arg0 + 0x5A9C);
    D_801D5608[1] = *(s32 *)(arg0 + 0x5AA0);
    p = func_80035C38(3, 0xE, 0x16, 0x17, 0x280, 0x10, 0x100);
    func_80039A14(p);
    *(u16 *)(*(u8 **)(p + 0x28) + 8) &= 0xFFF7;
}
