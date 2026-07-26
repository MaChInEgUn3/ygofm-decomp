#include "common.h"

void func_8001778C(void) {
    u8 *p = D_801A7AD8;
    s32 i;

    for (i = 0; i < 0x1E; i++) {
        *(s32 *)p = 0;
        *(s32 *)(p + 4) = 0;
        *(s16 *)(p + 0x16) = 0;
        p += 0x1C;
    }
}
