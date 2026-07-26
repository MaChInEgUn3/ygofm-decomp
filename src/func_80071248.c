#include "common.h"

void func_80071248(void) {
    s32 *p = D_800F5B98;
    s32 i;

    i = p[func_8007058C()] - 1;
    p[func_8007058C()] = (D_801D4244[i] >> 26) & 0x1F;
}
