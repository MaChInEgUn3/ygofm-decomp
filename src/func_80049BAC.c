#include "common.h"

void func_80049BAC(s32 arg0) {
    u8 *p;

    D_8009B458[0x500] = 1;
    p = D_8009B458;

    if (*(s16 *)(p + 0x7E0) == -1) {
        p[0x500] = 0;

        return;
    }

    *(s32 *)(p + 0x7EC) = 0x10000;
    *(s32 *)(p + 0x7DC) = *(s32 *)(p + 0x7E8);
    func_8004C77C();

    {
        u8 *q = D_8009B458;
        u8 *r;

        q[0x502] = 1;
        r = D_8009B458;
        *(s32 *)(q + 0x80C) = arg0;
        *(s16 *)(r + 0x7E2) = 1;
        r[0x500] = 0;
    }
}
