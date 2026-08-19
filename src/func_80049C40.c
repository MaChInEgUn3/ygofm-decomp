#define FUNC_80049C40_VOID
#include "common.h"

void func_80049C40(void) {
    u8 *p = D_8009B458;

    if (*(s16 *)(p + 0x7E0) != -1) {
        u8 *q;
        u8 *r;

        p[0x500] = 1;
        func_8004CA60();
        func_8004A518();
        q = D_8009B458;
        q[0x500] = 0;
        r = D_8009B458;
        *(s16 *)(q + 0x7E6) = 0x7F;
        *(s16 *)(q + 0x7E4) = 0x7F;
        *(s16 *)(q + 0x7E2) = 2;
        r[0x502] = 0;
    }
}
