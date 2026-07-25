#include "common.h"

s32 func_8004002C(void) {
    Slot70 *p = D_800F0548;
    s32 i;

    for (i = 0x10; i < 0x60; i++) {
        if (!(p->flags & 0x80)) {
            return i;
        }
        p++;
    }

    return -1;
}
