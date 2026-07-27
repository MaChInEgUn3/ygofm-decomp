#include "common.h"

void func_800208D4(void) {
    u16 f = D_8009B23A;

    if (!(f & 0x8000)) {
        s32 a3;

        D_8009B23A = f | 0x8000;

        if (D_8009B1D5 != 0) {
            a3 = 0x400;
        } else {
            a3 = 0xC00;
        }

        func_80022D94(0x30, 0x258, 0x100, a3, 0);
        D_8009B162 = 0x10;
    }

    if (D_8009B162 == 0) {
        s32 i = D_8009B1D5 ^ 1;

        D_8009B1D5 = i;
        i &= 0xFF;
        D_8009B23A = 2;
        D_8009B1C8 = (u8 *)&D_800E9FF0[i];
        D_8009B22C = D_800907D8 + i * 20;
    }
}
