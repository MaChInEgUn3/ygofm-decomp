#include "common.h"

void func_80059DD8(s32 arg0) {
    u8 *base = D_800F2C40 + arg0 * 3616;
    u8 *p = base;
    s32 (*fn)(s32) = func_8005FC1C;
    u8 *q;
    u8 *r;
    s32 i;

    if (base[0xE1F] == 0) {
        return;
    }

    for (i = 0; i < base[0xE1A]; i++, p += 8) {
        q = *(u8 **)(p + 4);
        if (q != (u8 *)0) {
            while (1) {
                if (*(s32 *)(q + 8) != 0) {
                    func_8005A53C(fn, q + 0xC, *(s32 *)(q + 4),
                                  *(s32 *)(q + 8));
                }
                r = *(u8 **)q;
                if (r == (u8 *)-1) {
                    break;
                }
                q = r;
            }
        }
    }
}
