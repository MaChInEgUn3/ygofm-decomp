#include "common.h"

u8 *func_80013A94(s32 arg0, s32 arg1) {
    u8 *p;

    if (D_8009B0F4 & 0x20) {
        return 0;
    }

    p = D_800E9E18;
    func_80013940(p, arg0 & 0xF, arg1, 0);
    p[0x46] = 0;
    *(s32 *)(p + 0x2C) = 0x100000;
    D_8009B0F4 |= 0x20;

    return p;
}
