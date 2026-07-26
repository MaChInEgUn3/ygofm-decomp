#include "common.h"

void func_80070B3C(void) {
    s32 a = func_8007058C();
    s32 b = func_8007058C();
    s32 c = func_800705AC();

    if (D_800F5B98[a] != D_800F5B98[b]) {
        u8 *p = D_800F5BE8[0].base;

        D_800F5BE8[0].cursor = c + p;
    }
}
