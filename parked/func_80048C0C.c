#define D_8009B45C_IS_AGGREGATE
#include "common.h"

void func_80048C0C(u16 arg0, u8 arg1) {
    s32 i;
    s32 m;

    if (arg1 == 0) {
        return;
    }

    m = 1;
    for (i = 0; i < 4; i++) {
        u8 *p = D_8009B45C[0];
        s32 o = i * 2;
        u8 *q;

        q = p + o;
        if (*(u16 *)(q + 0x404) == arg0 && (p[0x434] & m)) {
            q = p + i;
            q[0x428] = arg1;
        }
        m <<= 1;
    }
}
