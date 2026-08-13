#include "common.h"

/* The countdown at +0x60 is also func_80043230's fourth argument, and that
 * is the whole function. Written as a three-argument call, gcc folds the
 * sign extension into the branch -- `sll 16` then `bgtz` on the shifted
 * value tests the same thing as `(s16)x > 0` -- and retail's `sra $a3` has
 * nowhere to come from. Passing d as the fourth argument keeps it, in $a3,
 * which is where the sra writes. The callee is prototypeless here and takes
 * four parameters; the call site setting only three was the tell. */

void func_8003D614(u8 *p) {
    u8 *q;
    Rec64 *r;
    s32 d;

    if ((D_8009B3C1 & 0x80) == 0) {
        q = *(u8 **)p;
        D_8009B3C1 |= 0x80;
        func_80043178(q);
        *(s16 *)(q + 0x60) = 0x400;
    }

    r = &D_800EB0F8[p[0x1A]];
    q = *(u8 **)p;

    if (q != 0) {
        *(s16 *)(q + 0x60) = *(u16 *)(q + 0x60) - 0x40;
        d = *(s16 *)(q + 0x60);
        if (d <= 0) {
            func_8004036C((s32)q);
            *(s32 *)p = 0;
        } else {
            func_80043230(q, 0x20, -0x40, d);
            func_80039934((u8 *)r, *(s16 *)(q + 0x30), *(s16 *)(q + 0x32));
        }
    }

    q = *(u8 **)(p + 4);

    if (q != 0) {
        *(s16 *)(q + 0x4A) = *(u16 *)(q + 0x4A) + 8;
        *(s16 *)(q + 0x48) = *(u16 *)(q + 0x48) + 8;
        if (*(s16 *)(q + 0x48) >= 0xC0) {
            func_8004036C((s32)q);
            *(s32 *)(p + 4) = 0;
        }
    }

    if (*(s32 *)p == 0 && *(s32 *)(p + 4) == 0) {
        D_8009B3C1 = 0;
    }
}
