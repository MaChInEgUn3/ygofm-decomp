#include "common.h"

typedef struct {
    u8 r;
    u8 g;
    u8 b;
} Rgb3;

void func_8005ABA0(u8 *arg0, s32 h, s32 s, s32 v, u8 lim) {
    Rgb3 *out = (Rgb3 *)arg0;
    u32 c[3];
    Rgb3 t;
    s32 x;
    s32 k;
    s32 m;
    s32 i0;
    s32 i1;
    u32 sa;
    s32 va;
    s32 n;
    s32 L;
    s32 q;
    s32 d;
    s32 w;
    s32 y;
    s32 z;
    u32 e0;
    u32 e2;
    u32 r0;
    u32 r1;
    u32 r2;

    x = h;
    if (h < 0) {
        x = h + 0xFFF;
    }
    k = ((x >> 12) + 1) % 6;
    m = k / 2;

    if ((k & 1) != 0) {
        i1 = (m + 1) % 3;
        i0 = (m + 2) % 3;
    } else {
        i0 = (m + 1) % 3;
        i1 = (m + 2) % 3;
    }

    sa = s & 0xFFFF;
    va = v & 0xFFFF;

    if (sa < 0x801) {
        n = sa * (0x1000 - va);
        if (n < 0) {
            n += 0xFFF;
        }
        L = lim & 0xFF;
        q = (n >> 12) * L;
        c[i0] = q;
        d = sa * 2;
        c[m] = d * L - q;
    } else {
        n = sa * (0x1000 - va);
        if (n < 0) {
            n += 0xFFF;
        }
        L = lim & 0xFF;
        q = ((n >> 12) + va) * L;
        c[m] = q;
        d = sa * 2;
        c[i0] = d * L - q;
    }

    w = (h + 0x1000) % 24576 - (m << 13);
    y = w - 0x1000;
    if (y < 0) {
        y = 0x1000 - w;
    }
    z = c[i0];
    c[i1] = ((u32)((c[m] - z) * y) >> 12) + z;

    r0 = (c[0] + 0x800) >> 12;
    r1 = (c[1] + 0x800) >> 12;
    c[0] = r0;
    c[1] = r1;
    r2 = (c[2] + 0x800) >> 12;
    c[2] = r2;

    if (r0 >= 0x100) {
        r0 = 0xFF;
    }
    t.r = r0;
    if (r1 >= 0x100) {
        r1 = 0xFF;
    }
    t.g = r1;
    e2 = r2;
    if (e2 >= 0x100) {
        e2 = 0xFF;
    }
    t.b = e2;

    *out = t;
}
