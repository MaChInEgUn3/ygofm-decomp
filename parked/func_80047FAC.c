#define D_8009B45C_IS_AGGREGATE
#include "common.h"

s16 func_80047FAC(u16 arg0) {
    s16 buf[4];
    s32 count = 0;
    s32 i;

    i = 0;

    do {
        u8 *p;

        func_80077C50(i + 0x14, buf);

        p = D_8009B45C[0];
        p += i * 2;

        if (*(u16 *)(p + 0x404) == arg0 && buf[0] != 0) {
            count++;
        }

        i++;
    } while (i < 4);

    return count;
}
