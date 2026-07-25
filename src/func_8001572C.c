#include "common.h"

void func_8001572C(void) {
    u8 *p;

    if (D_8009B145 != 0) {
        *(s32 *)D_800E9EC8 = 0xFFFFFF;
        p = D_800E9EC8;
        p[6] = 0x90;
        p[7] = 0xC;
        D_8009B14C = 1;
        D_8009B144 = 1;
        D_8009B14B = 1;
        D_8009B143 = 1;
        D_8009B14A = 1;
        D_8009B142 = 1;
    }
}
