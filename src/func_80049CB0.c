#include "common.h"

void func_80049CB0(s32 arg0) {
    u8 *p;
    u8 *q;
    s32 m;

    p = D_8009B458;
    m = -1;
    if (*(s16 *)(p + 0x7E0) != m) {
        p[0x500] = 1;
        q = D_8009B458;
        *(s16 *)(q + 0x7E0) = m;
        *(s16 *)(q + 0x7E2) = 0;
        *(s16 *)(q + 0x7E6) = 0x7F;
        *(s16 *)(q + 0x7E4) = 0x7F;
        q[0x500] = 0;
    }
}
