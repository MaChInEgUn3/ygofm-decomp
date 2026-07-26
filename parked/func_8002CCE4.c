#include "common.h"

void func_8002CCE4(s32 arg0) {
    s32 i = (arg0 & 0x7FF) >> 3;

    if (arg0 & 0x8000) {
        s32 m = 0x80 >> (arg0 & 7);
        u8 *p = &D_801D0000[i];

        p[0x618] &= ~m;

        return;
    }
    {
        s32 m = 0x80 >> (arg0 & 7);
        u8 *p = &Base2_801D0000[i];

        p[0x618] |= m;
    }
}
