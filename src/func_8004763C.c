#define D_8009B45C_IS_AGGREGATE
#include "common.h"

void func_8004763C(void) {
    u8 *p = D_8009B45C[0];
    s32 i = *(u16 *)(p + 4);

    *(u16 *)(p + 0x442) = 0xFFFF;
    while (i < *(u16 *)p) {
        *(u16 *)(*(u8 **)(p + 0x43C) + i * 2) = 0xFFFF;
        i++;
    }
    {
        u8 *q = D_8009B45C[0];

        *(u16 *)(q + 0x440) = *(u16 *)(q + 4);
        *(s32 *)(q + 0x438) = *(s32 *)(*(u8 **)(q + 0x448) + 4) + 0x1010;
    }
}
