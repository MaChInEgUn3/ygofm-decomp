#include "common.h"

void func_80073380(void) {
    u16 *p = (u16 *)D_800F5BE8;
    s32 i;

    for (i = 0x1F; i >= 0; i--) {
        p[i + 0x1F] = 0;
    }
}
