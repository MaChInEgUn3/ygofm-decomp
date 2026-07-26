#include "common.h"

void func_80071320(void) {
    s32 *p = D_800F5B98;
    s32 i = p[func_8007058C()];
    s32 k = func_8007058C();
    s32 r;

    if (D_801AB000[i].unk0 == 0) {
        r = 0;
    } else if (D_801AB000[i].unk6 & 0x1000) {
        r = 2;
    } else {
        r = 1;
    }

    D_800F5B98[k] = r;
}
