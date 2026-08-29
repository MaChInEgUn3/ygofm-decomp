#define D_8009B0D8_IS_SCALAR
#include "common.h"

void func_8003AD6C(u8 *p) {
    s32 dd[2];
    u8 *r;
    s32 a;
    s32 b;
    s32 d;
    s32 m;
    s16 n;
    s32 c;
    s32 w;
    s32 x;
    s16 y;
    u8 *o;

    if (func_80039F1C() == 0) {
        p[0x32] = p[0x32] | 0x10;
        r = *(u8 **)p;
        a = r[0x67];
        b = *(s8 *)(r + 0x16);
        func_80039F90(p);
        func_8003A1EC(p, p, p[0x31]);
        func_8003A440((u8 **)p, 0x50000000, b);
        func_8003A1EC(p, p + 0xC, p[0x31]);
        d = b - 1;
        func_8003A440((u8 **)(p + 0xC), 0x60000000, d);
        func_8003A1EC(p, p + 0x18, a);
        func_8003A440((u8 **)(p + 0x18), 0x50000000, b);
        func_8003A1EC(p, p + 0x24, a);
        func_8003A440((u8 **)(p + 0x24), 0x60000000, d);
        *(s16 *)(p + 0x40) = 0x80;
    }
    n = *(u16 *)(p + 0x40) - D_8009B0D8 * 8;
    *(u16 *)(p + 0x40) = n;
    if (n <= 0) {
        p[0x33] = 0;
        func_8003A440((u8 **)p, 0, *(s8 *)(*(u8 **)p + 0x16));
        func_8003A920(p, *(s16 *)(p + 0x34), *(s16 *)(p + 0x36));
        func_80039F90(p + 0xC);
        func_80039F90(p + 0x18);
        func_80039F90(p + 0x24);
        p[0x32] = p[0x32] & 0xEF;
        return;
    }
    c = n;
    c = c | ((c << 8) | (c << 0x10));
    for (m = 2; m >= 0; m--) {
        o = *(u8 **)(p + m * 4 + 0x18);
        if (o != (u8 *)0) {
            *(s32 *)(o + 0xC) = c;
        }
        o = *(u8 **)(p + m * 4 + 0x24);
        if (o != (u8 *)0) {
            *(s32 *)(o + 0xC) = c;
        }
    }
    c = 0x80 - *(s16 *)(p + 0x40);
    c = c | ((c << 8) | (c << 0x10));
    for (m = 2; m >= 0; m--) {
        o = *(u8 **)(p + m * 4);
        if (o != (u8 *)0) {
            *(s32 *)(o + 0xC) = c;
        }
        o = *(u8 **)(p + m * 4 + 0xC);
        if (o != (u8 *)0) {
            *(s32 *)(o + 0xC) = c;
        }
    }
    dd[0] = *(s16 *)(p + 0x40) / 8;
    w = (0x80 - *(s16 *)(p + 0x40)) / 8;
    dd[1] = -w;
    if (p[0x3C] == 0) {
        dd[0] = -dd[0];
        dd[1] = w;
    }
    y = *(s16 *)(p + 0x36);
    x = *(s16 *)(p + 0x34) + dd[0];
    x = (s16)x;
    func_8003A920(p, x, y);
    func_8003A920(p + 0xC, x, y);
    x = *(s16 *)(p + 0x34) - dd[1];
    x = (s16)x;
    func_8003A920(p + 0x18, x, y);
    func_8003A920(p + 0x24, x, y);
}
