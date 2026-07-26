#include "common.h"

void func_80073624(void) {
    s32 a = func_8007058C();
    s32 b = func_8007058C();
    s32 c = func_8007058C();

    D_800F5B98[c] = D_800F5B98[a] + D_800F5B98[b];
}
