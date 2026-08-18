#include "common.h"

void func_80050F24(s32 arg0) {
    u8 *p;
    u8 *q;
    s32 n;
    s32 v;
    s32 w;
    s32 o;

    p = D_800F2C40 + arg0 * 3616;
    q = D_800F2C40 + 0xCF8 + arg0 * 3616;
    n = p[0xDFE] + 3;
    o = n * 118;
    v = *(u16 *)(p + o + 0x7C4);

    if (v != 0) {
        func_80057AF4(arg0, n, 1);
    }

    v = v * 2 / 3;
    if (v < 0x3C) {
        v = 0x3C;
    }

    o = p[0xDFE] * 2;
    w = *(u16 *)(q + o + 0xC);
    if (w != 0) {
        v = w;
    }

    func_80059F18(1, -1, arg0 ^ 1, v);
    o = p[0xDFE];
    func_8005F180((((q + o)[0xA] & 0x80) == 0) * 2);

    o = p[0xDFE];
    if (((q + o)[0xA] & 0x40) != 0) {
        func_8005F180(1);
    }
}
