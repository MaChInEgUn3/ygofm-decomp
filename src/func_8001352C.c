#include "common.h"

void func_8001352C(void) {
    u8 *p = D_800F2848;
    s32 n = -*(s16 *)D_800F2848;
    s32 x = n * func_80086770(*(s16 *)(p + 4)) / 4096;
    s32 z = n * func_800866A0(*(s16 *)(p + 4)) / 4096;
    s32 y = x * func_800866A0(*(s16 *)(p + 2)) / 4096;
    s32 w = x * func_80086770(*(s16 *)(p + 2)) / 4096;

    x = w;
    func_800134E0(p, x, z, y);
}
