#define D_8009B0F4_IS_AGGREGATE
#include "common.h"

void func_8002DF2C(u8 *arg0, s32 arg1) {
    s32 idx;
    s32 kind;
    s32 base;
    s32 n;
    u8 *p;

    if (arg0 != (u8 *)0) {
        *(s16 *)(arg0 + 0x3C) = arg1;
    }
    idx = ((arg1 >> 4) & 0xF) * 10 + (arg1 & 0xF);
    kind = arg1 >> 8;
    switch (kind) {
    case 0:
        n = 0x21;
        base = 0;
        break;
    case 1:
        n = 0x51;
        base = 0x672;
        break;
    case 2:
        n = 0x71;
        base = 0x13BC;
        break;
    default:
        return;
    }
    p = func_80014EEC(0, (u8 *)0, base + idx * n + 0x21D5, n, func_8002DDFC, 0, 0);
    *(s32 *)(p + 0x38) = n - 1;
    D_8009B0F4[0] = *(s32 *)(p + 0x2C) | 0x10;
}
