#define D_8009B1D5_IS_AGGREGATE
#include "common.h"

void func_8002C938(s32 *arg0, s32 arg1) {
    s32 n = 0x14;
    u8 *p;

    if (D_8009B1D5[0] != 0) {
        n = 5;
    }
    if (arg1 != 0) {
        n += 5;
    }

    p = &D_801A7AD8[n * 28];
    for (n = 0; n < 5; n++) {
        if (*(u16 *)(p + 0x16) & 0x8000) {
            *arg0++ = *(s32 *)p;
        }
        p += 0x1C;
    }

    *arg0 = 0;
}
