#include "common.h"

s32 func_8002EE5C(void) {
    u16 *p = (u16 *)D_801D0200;
    s32 i;

    for (i = 0; i < 0x28; i++) {
        if (*p == 0) {
            return 0;
        }
        p++;
    }

    return 1;
}
