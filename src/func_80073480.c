#include "common.h"

void func_80073480(void) {
    s32 *tbl = D_800F5B98;
    s32 v = tbl[func_8007058C()];

    D_801AB000[v].unk6 |= 0x4000;
}
