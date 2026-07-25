#include "common.h"

void func_8002CCE4(s32 arg0) {
    s32 i = (arg0 & 0x7FF) >> 3;
    s32 m;
    u8 *p;

    if (arg0 & 0x8000) {
        m = 0x80 >> (arg0 & 7);
        p = &D_801D0000[i];
        p[0x618] &= ~m;

        return;
    }
    m = 0x80 >> (arg0 & 7);
    p = &Base2_801D0000[i];
    p[0x618] |= m;
}
