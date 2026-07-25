#include "common.h"

void func_800134B4(void) {
    s32 *p = (s32 *)D_800E9DB0;
    s32 i;

    for (i = 3; i >= 0; i--) {
        *(p + i) = 0;
    }
    D_8009B0B8 = 0;
}
