#include "common.h"

void func_80073420(void) {
    s32 i = 0x18;
    u8 *p = (u8 *)D_800F5BE8 + i;

    do {
        p[0x7E] = 0;
        i--;
        p--;
    } while (i >= 0);
}
