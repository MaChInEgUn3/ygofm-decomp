#define D_800EB184_IS_AGGREGATE
#include "common.h"

void func_80031354(void) {
    u8 v = D_8009B2EB;

    if ((v & 0x80) == 0) {
        D_8009B2EB = v | 0x80;
        D_8009B2DE = 0;
        func_8002FD10(0);
    }

    func_8003134C();

    if (D_8009B2DE == 0) {
        u8 *a = D_800EB184[0];
        u8 *b = D_8009B2E4;
        u16 g;

        *(u16 *)(a + 8) |= 0x40;
        g = *(u16 *)(b + 8);
        D_8009B2EB = 0;
        *(u16 *)(b + 8) = g | 0x40;
    } else {
        func_8003B378((u8 *)D_800EB010, func_800358FC(4));
    }
}
