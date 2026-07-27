#include "common.h"

void func_8003E46C(u8 arg0, s32 arg1) {
    u16 v;

    D_8009B3C6 = arg0;
    v = D_8009B3FA & 0xFF87;
    D_8009B3FA = v;
    Base2_8009B3FA = v | (arg1 | 0x80);
}
