#include "common.h"

void func_80070BB8(void) {
    s32 a = func_8007058C();
    s32 b = func_8007058C();
    s32 c = func_8007058C();
    s32 off = func_800705AC();
    s32 av = D_800F5B98[a];

    if (av <= D_800F5B98[b] && D_800F5B98[c] <= av) {
        off += (s32)D_800F5BE8[0].base;
        D_800F5BE8[0].cursor = (u8 *)off;
    }
}
