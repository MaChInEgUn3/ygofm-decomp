#include "common.h"

s32 func_8002CBF4(s32 arg0, s32 arg1) {
    s32 v;
    s32 s;

    if (arg1 != 0) {
        v = D_801D4244[arg0 - 1] >> 9;
    } else {
        v = D_801D4244[arg0 - 1];
    }

    v &= 0x1FF;
    s = v * 10;
    s += func_8002497C((D_801D4244[arg0 - 1] >> 26) & 0x1F);

    if (s < 0) {
        return 0;
    }

    if (s < 0x2710) {
        return s;
    }

    s = 0x270F;

    return s;
}
