#include "common.h"

void func_80035CE4(void) {
    u8 *p = D_800EAF08;
    s32 i;

    for (i = 0xEF; i >= 0; i--) {
        *p++ = 0;
    }
    D_8009B324 = 0;
    D_8009B325 = 0;
}
