#include "common.h"

void func_80071194(void) {
    s32 c = D_800F5B98[func_8007058C()];
    s32 n = func_8007058C();
    s32 *t = D_801D4244;
    s32 k = c - 1;
    s32 res;

    if (((t[k] >> 26) & 0x1F) < 0x14) {
        s32 lo = func_8002CBF4(c, 0);

        res = func_8002CBF4(c, 1) >= lo;
    } else {
        res = 0;
    }

    D_800F5B98[n] = res;
}
