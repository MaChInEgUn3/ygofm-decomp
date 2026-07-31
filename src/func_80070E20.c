#include "common.h"

void func_80070E20(void) {
    s32 a = func_800705AC();
    s32 b = func_800705AC();
    s32 i = func_8007058C();

    D_800F5B98[i] = func_8008E590() % (b - a + 1) + a;
}
