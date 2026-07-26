#include "common.h"

void func_800176D0(void) {
    u8 *p = (u8 *)D_800EA030;
    s32 i;

    for (i = 0; i < 5; i++) {
        *(s32 *)(p + 4) = 0;
        *(s32 *)p = 0;
        p[9] = 0;
        p += 0xC;
    }
}
