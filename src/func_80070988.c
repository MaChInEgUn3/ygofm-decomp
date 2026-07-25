#include "common.h"

void func_80070988(void) {
    s32 n = func_800705AC();

    D_800F5BE8[0].cursor = D_800F5BE8[0].base + n;
}
