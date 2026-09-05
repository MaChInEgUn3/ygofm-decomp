#define D_8009B0D8_IN_DATA
#include "common.h"

/* D_8009B0D8 takes the scalar declaration and an assembler -G0: there is no
 * %gp_rel in the function, so recipe branch 1 applies and any -G is free.
 * Under the unsized-array arm cc1psx emits its own %hi/%lo pair, gcc hoists
 * the `lui` all the way into the first block, and the halves end up 30
 * instructions apart where retail has them adjacent. The bare form is one
 * instruction to gcc, so there is nothing to split. 79 differences to 2.
 *
 * The last two were the order of the loop's two preheader statements: the
 * counter is initialised before the cursor, not after. */

void func_8003AAE4(u8 *p) {
    u8 *q;
    u8 *e;
    u8 *c;
    s32 a;
    s32 b;
    s32 v;
    s32 m;
    s32 i;

    if (func_80039F1C(p) == 0) {
        *(s16 *)(p + 0x34) = 0x68;
        p[0x32] |= 0x10;
        if (p[0x3C] != 0) {
            *(s16 *)(p + 0x34) = 0xD8;
        }
        func_8003A920(p, *(s16 *)(p + 0x34), *(s16 *)(p + 0x36));
        q = *(u8 **)p;
        a = *(s8 *)(q + 0x16);
        b = q[0x67];
        func_8003A440((u8 **)p, 0x50000000, a);
        e = p + 0xC;
        func_8003A1EC(p, e, b);
        func_8003A440((u8 **)e, 0x60000000, a - 1);
        *(s16 *)(p + 0x40) = 0;
    }

    v = *(u16 *)(p + 0x40) + D_8009B0D8 * 8;
    *(s16 *)(p + 0x40) = v;

    if (*(s16 *)(p + 0x40) >= 0x80) {
        p[0x33] = 0;
        func_8003A440((u8 **)p, 0, *(s8 *)(*(u8 **)p + 0x16));
        func_80039F90(p + 0xC);
        p[0x32] &= 0xEF;
    } else {
        m = *(s16 *)(p + 0x40);
        m |= (m << 8) | (m << 16);
        for (i = 2, c = p + 8; i >= 0; i--, c -= 4) {
            if (*(u8 **)c != 0) {
                *(s32 *)(*(u8 **)c + 0xC) = m;
            }
            if (*(u8 **)(c + 0xC) != 0) {
                *(s32 *)(*(u8 **)(c + 0xC) + 0xC) = m;
            }
        }
    }
}
