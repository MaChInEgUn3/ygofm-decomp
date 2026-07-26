#include "common.h"

void func_8003B6AC(s32 arg0, s32 arg1) {
    u8 *t = D_80090E58;
    u8 *lo = t + arg0 * 2;
    u8 *hi = t + (arg0 + 1) * 2;
    s32 i = *(u16 *)lo;

    if (i < *(u16 *)hi) {
        u8 *base = (u8 *)D_800EB288;
        u8 *p = base + i * 28;

        do {
            p[0x18] = arg1;
            p += 0x1C;
            i++;
        } while (i < *(u16 *)hi);
    }
}
