#define D_8009B34D_IS_AGGREGATE
#include "common.h"

u8 *func_8003D46C(s32 arg0, s32 arg1) {
    u8 *p;

    D_8009B34D[0] = -1;

    p = func_80035BE4(D_800EF6EA[0], arg0 & 0x7FFF, 0x20, 0x50, 0x100, 0x40);
    p[0x59] = D_8009AF76 - 1;

    if (arg1 != 0) {
        *(u16 *)(p + 0x34) |= 0x1008;
    } else if (arg0 & 0x8000) {
        func_80039A14(p);
    }

    return p;
}
