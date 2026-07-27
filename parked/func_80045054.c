#define D_8009B45C_IS_AGGREGATE
#include "common.h"

s32 func_80045054(void) {
    u8 *p;
    s16 *q;
    s32 i;
    s32 v;

    v = func_80076D20(D_8009B45C[0] + 0x53C, 5);
    p = Base2_8009B45C[0];
    *(s32 *)(p + 0x538) = v;

    if (v == 0) {
        q = *(s16 **)(p + 0x153C);
    } else {
        q = *(s16 **)(p + 0x1540);
    }

    p = Base3_8009B45C[0];
    i = 0;
    *(s32 *)(p + 0x154C) = 0;
    *(s32 *)(p + 0x1550) = 0;

    do {
        s32 x = *q;

        i++;
        *(s32 *)(p + 0x154C) = *(s32 *)(p + 0x154C) + ((u32)(x * x) >> 8);
        q++;
    } while (i < 0x100);

    p = Base4_8009B45C[0];
    v = *(s16 *)(p + 0x154E);
    *(s32 *)(p + 0x154C) = v;
    *(s32 *)(p + 0x1550) = *(s16 *)(p + 0x1552);

    if ((*(u16 *)(p + 0x40) & 3) != 0) {
        v = 0;
    }

    return v;
}
