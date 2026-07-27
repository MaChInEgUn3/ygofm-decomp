#define D_8009B458_IS_AGGREGATE
#include "common.h"

void func_80049AF4(s32 arg0) {
    u8 *p;

    D_8009B458[0][0x500] = 1;

    p = D_8009B458[0];

    if (*(s16 *)(p + 0x7E0) == -1) {
        p[0x500] = 0;
        return;
    }

    *(s32 *)(p + 0x7EC) = 0x10000;
    *(s32 *)(p + 0x7DC) = *(s32 *)(p + 0x7E8);

    func_8004C77C();

    if ((arg0 & 0xFF) == 0) {
        *(u16 *)(D_8009B458[0] + 0x7E2) = 4;
    } else {
        D_8009B458[0][0x502] = 1;
        *(u16 *)(D_8009B458[0] + 0x7E2) = 1;
    }

    D_8009B458[0][0x500] = 0;
}
