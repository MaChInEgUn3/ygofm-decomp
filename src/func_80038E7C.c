#include "common.h"

void func_80038E7C(u8 *arg0) {
    u8 v = arg0[0x58] - 1;

    arg0[0x58] = v;

    if ((s8)v < 0) {
        u16 t = *(u16 *)(arg0 + 0x34);

        D_8009B350 = 1;
        *(u16 *)(arg0 + 0x34) = t | 0x2000;
    }
}
