#include "common.h"

void func_800338E4(u8 *arg0) {
    s32 g;
    s32 h;
    s32 c;

    if (func_80032B38(arg0) == 0) {
        s32 d = *(s32 *)(arg0 + 0x5AA4) - D_8009B146;

        if (d < 0) {
            d += 0xF;
        }

        *(s32 *)(arg0 + 0x5AA8) = d >> 4;
        *(s32 *)(arg0 + 0x5AAC) = 0x10;
        func_8003FEE0(0x1E);
    }

    g = (u16)D_8009B146;
    h = *(u16 *)(arg0 + 0x5AA8);
    c = *(s32 *)(arg0 + 0x5AAC);
    D_8009B146 = g + h;
    c--;
    *(s32 *)(arg0 + 0x5AAC) = c;

    if (c == 0) {
        s32 t = *(u16 *)(arg0 + 0x5AA4);

        arg0[0x6342] = 0;
        D_8009B146 = t;

        if ((s16)t != 0) {
            arg0[0x6342] = 1;
        }

        *(u16 *)(arg0 + 0x633E) = *(u16 *)(arg0 + 0x6340);
    }
}
