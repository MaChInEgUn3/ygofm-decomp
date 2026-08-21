/* Two parameters, and func_80024D34 calls it with none -- see the guard in
 * functions.h. Three levers here: the 0x48000 wants its own name so it is not
 * folded into %hi/%lo with the 0x39FC displacement (func_8001B938's shape);
 * `m = idx * 2 + 1` must exist before the call so it survives in a
 * callee-saved register the way retail's $s1 does; and `base` must be a local,
 * because retail materialises D_80177EA4 *before* the index shift and reuses
 * the same register for both records. */
#define FUNC_800249E0_FULL
#include "common.h"

u8 *func_800249E0(s32 a, s32 b) {
    u8 *p;
    u8 *q;
    u8 *r;
    u8 *tb;
    u8 *base;
    u8 *g;
    s32 idx;
    s32 m;
    s32 off;
    s32 n;
    s32 v;

    if ((a & 0x80) != 0) {
        idx = (a & 0x7F) + 0xF;
    } else {
        idx = a;
    }

    p = D_801A7AD8 + idx * 0x1C;
    *(u16 *)(p + 0x16) = 0x8000;

    if (a >= 0xF && b < 0x28) {
        b += 0x28;
    }
    if ((b & 0x80) != 0) {
        b = (b & 0x7F) + 0x28;
    }

    n = b * 6;
    tb = D_8015C424;
    *(s32 *)(p + 4) = (s32)(D_801A7E20 + n);
    p[0x18] = idx;

    g = tb + n + 0x48000;
    v = *(u16 *)(g + 0x39FC);
    *(u16 *)(p + 0xC) = v;
    *(s16 *)(p + 0xE) = (D_801D4244[(s16)v - 1] & 0x1FF) * 0xA;
    m = idx * 2 + 1;
    *(s16 *)(p + 0x10) =
        ((D_801D4244[*(s16 *)(p + 0xC) - 1] >> 9) & 0x1FF) * 0xA;
    *(s16 *)(p + 0x12) = 0;
    *(s16 *)(p + 0x14) =
        func_8002497C((D_801D4244[*(s16 *)(p + 0xC) - 1] >> 26) & 0x1F);

    base = D_80177EA4;
    q = base + idx * 0x10;
    off = *(u8 *)(*(s32 *)(p + 4) + 3) * 0x580;
    *(s16 *)(q + 4) = 0x14;
    *(s16 *)(q + 6) = 0x20;
    *(s16 *)(q + 0) = (idx % 5) * 0x14 + 0x380;
    *(s16 *)(q + 2) = (idx / 5) * 0x20;
    func_8007F978(q, D_8018C2D8 + off);

    r = base + m * 8;
    *(s16 *)(r + 0) = 0x380;
    *(s16 *)(r + 2) = idx + 0xE0;
    *(s16 *)(r + 4) = 0x40;
    *(s16 *)(r + 6) = 1;
    func_8007F978(r, D_8018C7D8 + off);

    return p;
}
