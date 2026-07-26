#include "common.h"

void func_800713B8(void) {
    s32 *p = D_800F5B98;
    s32 i;

    i = p[func_8007058C()];
    p[func_8007058C()] = D_800E9FF0[1 - i].unk14;
}
