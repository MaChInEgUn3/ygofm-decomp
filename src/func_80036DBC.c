#include "common.h"

void func_80036DBC(u8 *p) {
    u8 *q;
    s32 n;
    s32 m;
    u8 k;
    s32 a;
    s32 t;
    s16 t0;
    s16 t2;
    s32 b;
    s32 c;
    s32 v;
    s32 v0;
    s32 v2;
    s32 w;
    s32 x;
    s32 y;

    q = *(u8 **)(p + 0x30);
    n = *(u16 *)(p + 0x3C);
    *(s16 *)(q + 0x48) = n;
    *(s16 *)(q + 0x38) = n;
    *(s16 *)(q + 0x28) = n;
    m = *(u16 *)(p + 0x3C) + *(u16 *)(p + 0x3E);
    *(s16 *)(q + 0x50) = m;
    *(s16 *)(q + 0x40) = m;
    *(s16 *)(q + 0x30) = m;

    k = D_800EB288[*(u16 *)(D_80090E58 + p[0x57] * 2)].unk18 % 10;

    if (k == 1) {
        t = D_8009B34C & 0x30;
        a = t / 16 * 0x10;
        v = *(u16 *)(p + 0x40) + a + D_8009B34D * 0x10;
        *(s16 *)(q + 0x2A) = v;
        /* The copy has to land BETWEEN the two stores and gcc puts it before
         * both; three plain placements all score the same. `do { } while (0)`
         * is the documented lever for a pair that comes out in the wrong
         * order and will not permute -- and reads as a macro in the source. */
        do {
            w = v;
        } while (0);
        *(s16 *)(q + 0x32) = v;
        v = v + 0x10;
        w = w + 0x10;
        *(s16 *)(q + 0x42) = v;
        *(s16 *)(q + 0x3A) = v;
        *(s16 *)(q + 0x52) = w;
        *(s16 *)(q + 0x4A) = w;
        return;
    }

    if (k == 2) {
        t2 = D_8009B34C & 0x30;
        b = t2 / 16 * 0xC;
        v2 = *(u16 *)(p + 0x40) + b + D_8009B34D * 0xC;
        x = v2 - 2;
        y = v2 + 6;
    } else if (k == 0) {
        t0 = D_8009B34C & 0x30;
        c = t0 / 16 * 0xC;
        v0 = *(u16 *)(p + 0x40) + c + D_8009B34D * 0xC;
        x = v0 + 2;
        y = v0 + 0xA;
    } else {
        return;
    }

    *(s16 *)(q + 0x32) = x;
    *(s16 *)(q + 0x2A) = x;
    x = x + 0xC;
    *(s16 *)(q + 0x42) = y;
    *(s16 *)(q + 0x3A) = y;
    *(s16 *)(q + 0x52) = x;
    *(s16 *)(q + 0x4A) = x;
}
