#define D_8009B1D5_IS_AGGREGATE
#include "common.h"

void func_8007154C(void) {
    s32 *p = D_800F5B98;
    s32 i = p[func_8007058C()];

    p[func_8007058C()] = D_800E9FF0[(D_8009B1D5[0] ^ 1) ^ i].unk19 != 0;
}
