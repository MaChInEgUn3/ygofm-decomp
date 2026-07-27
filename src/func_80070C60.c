#include "common.h"

void func_80070C60(void) {
    s32 limit = D_800F5B98[func_8007058C()];
    s32 off = func_800705AC();

    if (func_8008E590() % 100 < limit) {
        off += (s32)D_800F5BE8[0].base;
        D_800F5BE8[0].cursor = (u8 *)off;
    }
}
