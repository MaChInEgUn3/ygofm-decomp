#include "common.h"

void func_800712B4(void) {
    s32 *p = D_800F5B98;
    s32 i;

    i = p[func_8007058C()];
    p[func_8007058C()] = D_801AB000[i].unk0;
}
