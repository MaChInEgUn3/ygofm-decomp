#include "common.h"

s32 func_8002C4DC(s32 arg0) {
    u16 *p = (u16 *)D_801D0200;
    s32 i;

    for (i = 0; i < 0x28; i++) {
        if (*p == arg0) {
            return i;
        }
        p++;
    }

    return -1;
}
