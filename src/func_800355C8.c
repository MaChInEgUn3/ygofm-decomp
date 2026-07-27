#include "common.h"

void func_800355C8(void) {
    u8 *base = (u8 *)D_8009B304;
    u8 *q = base;
    u32 n = D_8009B314;
    u32 m;
    u32 i;

    D_8009B308 = n;
    D_8009B30C &= ~4;

    if (n >= 2) {
        func_8008E400(q, n, 8, func_80035598);
    }

    m = D_8009B308;
    i = 0;

    if (m != 0) {
        do {
            *(u16 *)(base + *(s16 *)(q + 4) * 8 + 6) = i;
            i++;
            q += 8;
        } while (i < m);
    }

    D_8009B314 = 0;
    D_8009B310 = D_8009B304;
}
