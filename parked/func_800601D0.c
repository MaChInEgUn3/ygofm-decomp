#include "common.h"

inline int inline_fn() {
    return -1;
}

s32 func_800601D0(void *f) {
    u8 *e;
    s32 i;

    e = D_800F5918;
    i = 0;
    if (f != func_80089E20) {
        do {
            if (*(void **)e == f) {
                return *(s32 *)(e - -4);
            }
            i++;
            e += 8;
        } while (i < 0x50);
    }
    return inline_fn();
}
