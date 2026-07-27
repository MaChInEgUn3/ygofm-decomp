#define D_8009B09C_IS_AGGREGATE
#include "common.h"

s32 func_80033BE8(void) {
    s32 a;
    s32 c;
    u8 *base;
    u8 *p;
    u8 *q;

    func_8008E590();

    a = D_8009B09C[0] & 0x3F;

    if (a >= 0x20) {
        a = 0x3F - a;
    }

    base = D_8009B2FC;
    c = a * 2 + 0x40;
    p = *(u8 **)(base + 0x2D38);
    q = *(u8 **)(base + 0x5A84);

    q[0xE] = c;
    q[0xD] = c;
    q[0xC] = c;
    p[0xE] = c;
    p[0xD] = c;
    p[0xC] = c;

    if (func_8002892C() == 0) {
        D_80090DF8[*(u16 *)(D_8009B2FC + 0x633E) & 0x3F](D_8009B2FC);
    }

    return *(u16 *)(D_8009B2FC + 0x633E);
}
