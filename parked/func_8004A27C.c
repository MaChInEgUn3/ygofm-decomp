/* 6 differing at 31/31 (2026-09-12; was 9, was 11). The listing has no %gp_rel
 * and no lui $at, so D_8009B458 takes its real POINTER-SCALAR declaration with
 * the assembler at -G0 (WORKFLOW step 0, branch 1).
 *
 * 9 -> 6 is ONE LINE MOVED: the table read sits BETWEEN the two zero stores,
 * not after them. The permuter found it; it is ordinary C. What it buys is the
 * address materialisation -- with the read after both stores, gcc emits the
 * lui/addiu pair late and the first product's mflo lands before the stores.
 *
 * Measured and dead on the NAMING axis, eight spellings, seven of them flat at
 * 9 and one at 20: borrowing arg1 for the second halfword, borrowing arg1 plus
 * a named first product, the products written above the zero stores, borrowing
 * arg0 for the first product, both products in fresh names, the table read
 * hoisted to the top of the function (20), borrowing arg2 for the second
 * product, and borrowing arg1 and arg2 together. The FLAG axis is dead too --
 * sweep_try over 23 combinations, and the installed O2 G8 / as G0 is the best
 * of them.
 *
 * The 6 left: retail loads the second halfword into $a1 (arg1's register, dead
 * after the first mult) and keeps the first product in $a3. */
#include "common.h"

void func_8004A27C(s32 arg0, s32 arg1, s32 arg2) {
    u8 *p = D_8009B458;
    s32 t;

    *(u16 *)(p + 0x4CC) = 0;
    t = D_80011434[arg0];
    *(u16 *)(p + 0x4CE) = 0;
    *(s32 *)(p + 0x4C4) = 0xF;
    *(s32 *)(p + 0x4C0) = t;
    *(u16 *)(p + 0x4C8) = (arg1 * *(u16 *)(p + 0x514)) >> 7;
    *(u16 *)(p + 0x4CA) = (arg2 * *(u16 *)(p + 0x516)) >> 7;

    func_80077450(p + 0x4C0);
}
