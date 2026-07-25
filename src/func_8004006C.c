#include "common.h"

s32 func_8004006C(void) {
    Slot70 *p = D_800EFE48;
    s32 i;

    for (i = 0; i < 0x60; i++) {
        if (!(p->flags & 0x80)) {
            return i;
        }
        p++;
    }

    return -1;
}
