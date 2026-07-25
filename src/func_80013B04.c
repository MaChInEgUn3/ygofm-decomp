#include "common.h"

u8 *func_80013B04(s32 arg0, s32 arg1) {
    u8 *p;
    s32 v;

    if (((D_8009B0F4 & 0x2000030) | D_8009B134) == 0) {
        p = D_800E9E60;
        v = D_800E9EA8[arg0];
        p[0x46] = 0;
        D_8009B0F4 = 0x100010;
        *(s32 *)(p + 0x24) = v + arg1;

        return p;
    }

    return 0;
}
