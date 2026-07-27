#define D_8009B45C_IS_AGGREGATE
#include "common.h"

s32 func_80049138(s16 arg0, s32 arg1) {
    u8 *p = D_8009B45C[0];

    if (**(u16 **)(p + 0x1564) != arg0 >> 4) {
        u8 *q;
        u8 *e;
        s32 off;

        func_80046294();
        func_80049010();
        func_80077FF0(0);

        q = Base2_8009B45C[0];
        *(u16 *)(q + 0x40) |= 2;
        off = (arg0 & 0xFF0) >> 1;
        e = (u8 *)(off + *(s32 *)(q + 0x1560));

        func_800471D0(*(s32 *)(e + 4), *(s32 *)(q + 0x1564), *(u16 *)(e + 2),
                      e[0] << 11, e[1] << 11, 0x20);

        **(u16 **)(Base3_8009B45C[0] + 0x1564) = 0xFFFF;
    }

    return 0;
}
