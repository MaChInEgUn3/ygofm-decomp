/* 16 differing instructions.
 *
 * Retail materialises 0x48000 as a literal lui/ori and *adds* it to the formed
 * address, keeping 0x36B8 as the load displacement. Written as a constant in
 * the address expression -- which is what it looks like -- gcc folds it into
 * the relocation and emits %hi(D_8015C424+5)/%lo(D_8015C424-18760). Holding it
 * in a local instead is worse (30), so it is not simply "a variable".
 *
 * D_8015C424 + 0x48000 + 0x36B8 is 0x801A80DC, four bytes past D_801A7AD8 --
 * the same 0x1C-stride table func_8002C938 uses. So the source may name a
 * symbol splat did not, or index one array where splat split two. Worth
 * checking the surrounding functions for the same base+0x48000 pattern before
 * guessing again.
 */
#include "common.h"

void func_80024D34(s32 arg0) {
    s32 **slot = (s32 **)func_800249E0();
    s32 i = arg0;
    u8 *p;

    if (arg0 & 0x80) {
        i = (arg0 & 0x7F) + 0xF;
    }

    p = *(u8 **)(D_8015C424 + i * 28 + 0x48000 + 0x36B8);
    *slot = (s32 *)func_80024C1C(*(s16 *)p, D_800908A0[i * 2],
                                 D_800908A0[i * 2 + 1]);
    ((u8 *)*slot)[0x6A] = i;
}
