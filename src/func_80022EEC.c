#include "common.h"

void func_80022EEC(u8 *arg0) {
    u8 *b = D_800E9F10;
    s32 off = *(s16 *)(arg0 + 0x2C) * 28;
    u8 *p;

    off += D_8009B1D5 * 112;
    p = *(u8 **)(b + off);

    if (p == 0) {
        func_8004036C((s32)arg0);
    } else {
        *(u16 *)(arg0 + 0x30) = *(u16 *)(p + 0x30) + *(u16 *)(arg0 + 0x28);
        *(u16 *)(arg0 + 0x32) = *(u16 *)(p + 0x32) + *(u16 *)(arg0 + 0x2A);

        if (p[0x6C] == 0) {
            arg0[0x6C] = 0;
            *(s32 *)(arg0 + 0x24) = 0;
        }
    }
}
