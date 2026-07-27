#include "common.h"

void func_800734DC(void) {
    s32 *t = D_800F5B98;
    s32 a = t[func_8007058C()];
    s32 b = t[func_8007058C()];
    s32 off = func_8007058C() * 4;
    s32 v;

    if (b == 0) {
        u8 *g = D_800917F0;

        v = *(s8 *)(g + a * 9 + 1) * 100;
    } else {
        u8 *g = D_800917F0;
        s32 k = a * 9;

        k++;
        v = *(s8 *)&g[b + k];
    }

    *(s32 *)(off + (s32)t) = v;
}
