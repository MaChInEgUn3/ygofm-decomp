#include "common.h"

void func_80073310(void) {
    s32 *p = D_800F5B98;
    s32 v = p[func_8007058C()];
    u8 *q = (u8 *)D_800F5BE8;
    s32 i;

    for (i = 0; i < 0x20; i++) {
        u16 c = *(u16 *)(q + i * 2 + 0x3E);

        if (c == v) {
            return;
        }
        if (c == 0) {
            *(u16 *)(q + i * 2 + 0x3E) = v;

            return;
        }
    }
}
