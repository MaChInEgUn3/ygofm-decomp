#include "common.h"

void func_8005A6A8(s32 arg0, s32 arg1, u8 *arg2, u8 *arg3) {
    s32 a;
    s32 b;
    s32 c;
    s32 d;
    s32 f;
    s32 g;
    s32 h;
    s32 n;
    s32 q;
    s32 z;
    s32 u;
    s32 v;
    s32 w;

    a = *(s32 *)D_800F56F0 - arg0;
    b = *(s32 *)(D_800F56F0 + 8) - arg1;
    h = func_80086E50(a * a + b * b);
    q = *(s32 *)(D_800F56F0 + 8);
    c = *(s32 *)(D_800F56F0 + 0xC) * q;
    d = *(s32 *)(D_800F56F0 + 0x14) - q;
    f = *(s32 *)D_800F56F0 - *(s32 *)(D_800F56F0 + 0xC);
    g = c - *(s32 *)D_800F56F0 * *(s32 *)(D_800F56F0 + 0x14);
    n = func_80086E50(d * d + f * f);
    h = h - 0x2BC;

    *arg2 = 0xFF;
    *arg3 = 0;

    if (h > 0) {
        v = 0xFF - h / 12;
        if (v < 0x10) {
            v = 0x10;
        }
        *arg2 = v;
    }

    if (n != 0) {
        h = (arg0 * d + arg1 * f + g) / n;
        w = h / 16;
        v = w;
        if (v < 0) {
            v = -v;
        }
        if (v >= 0x80) {
            v = 0x7F;
        }
        w = v;
        if (h <= 0) {
            w = -w;
        }
        *arg3 = w;
    }
}
