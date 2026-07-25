#include "common.h"

void func_80015870(void) {
    if (D_8009B145 != 0) {
        *(s32 *)D_800E9EC8 = 0xFFFFFF;
        D_800E9EC8[6] = 0xB0;
        D_800E9EC8[7] = 0xC;
        D_8009B14A = 0xFF;
        D_8009B14B = 0xFF;
        D_8009B14C = 0xFF;
    }
}
