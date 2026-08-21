/* Three near-identical blocks, and the differences between them are all in
 * the source rather than in codegen: `m` holds 0x41000000 for the first two
 * and the THIRD writes the literal, because retail re-materialises it with a
 * fresh `lui $a0` there instead of reusing $s7. The two optional blocks are
 * `if`/`else` with the null in the else arm -- written as an unconditional
 * `p = 0;` before the test, gcc CSEs the zero out of the preceding call's
 * fourth argument and the branch delay slot goes empty. And the guard is two
 * explicit returns, not an accumulator: retail puts `addu $v0,$zero,$zero` in
 * the guard's own delay slot. */
#include "common.h"

s32 func_8003A1EC(u8 *a, u8 **out, s32 c) {
    u8 *p;
    u8 *tb;
    s32 f;
    s32 g;
    s32 h;
    s32 m;

    if (a[0x3C] != 0) {
        f = -0xA;
        tb = D_801AF800;
        g = 0x1A;
        h = 0x202;
    } else {
        f = -0xE;
        tb = D_801AF000;
        g = 0x1D;
        h = 0x200;
    }

    if (func_8003A198(tb, c, 0, 0) == 0) {
        return 0;
    }

    {
        m = 0x41000000;
        p = func_800400AC(func_8004002C(), 2);
        func_800428A8(p, *(s16 *)(a + 0x34), *(s16 *)(a + 0x36), c, 0, 0, g, h,
                      tb);
        func_80042918(p);
        func_800428EC(p, f);
        *(s32 *)(p + 4) = *(s32 *)(p + 4) | m;
        *(u16 *)(p + 8) = *(u16 *)(p + 8) | 8;
        out[0] = p;

        if (func_8003A198(tb, c, 1, 0) != 0) {
            p = func_800400AC(func_8004002C(), 2);
            func_800428A8(p, *(s16 *)(a + 0x34), *(s16 *)(a + 0x36), c, 1, 0, g,
                          h, tb);
            func_80042918(p);
            func_800428EC(p, f | 1);
            *(s32 *)(p + 4) = *(s32 *)(p + 4) | m;
            *(u16 *)(p + 8) = *(u16 *)(p + 8) | 8;
        } else {
            p = (u8 *)0;
        }
        out[1] = p;

        if (func_8003A198(tb, c, 2, 0) != 0) {
            p = func_800400AC(func_8004002C(), 2);
            func_800428A8(p, *(s16 *)(a + 0x34), *(s16 *)(a + 0x36), c, 2, 0, g,
                          h, tb);
            func_80042918(p);
            func_800428EC(p, f | 1);
            *(s32 *)(p + 4) = *(s32 *)(p + 4) | 0x41000000;
            *(u16 *)(p + 8) = *(u16 *)(p + 8) | 8;
        } else {
            p = (u8 *)0;
        }
        out[2] = p;
    }

    return 1;
}
