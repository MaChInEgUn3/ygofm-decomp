/* 16 differing at 22/22. First REAL C ever written for this function
 * (src/ holds Unchiga's transcription: raw asm for the constant and an asm
 * barrier to keep an increment alive). Two faults, both understood.
 *
 * 1. THE INCREMENT IS NOT SOURCE. Retail's `addiu $v1,$v1,1` on the flag-exit
 *    path is gcc's own correction for an induction variable whose decrement
 *    it moved into the loop-back delay slot. The transcription kept it alive
 *    with `asm volatile("" :: "r"(v1))`; it is not needed. Written as
 *        for (n = 0x7FFFFFFF; n > 0; n--) { if (D_8009B062 != 0) break; }
 *        if (n <= 0) func_8008FBE0(1);
 *    gcc emits the +1 itself because the post-loop test keeps n live: 22/22.
 *    Every shape with an explicit `n++` is 21 (gcc deletes it as dead), and
 *    `return n & 0` does not save it (21). What is left of this fault is
 *    layout: ours tests n TWICE (the rotated loop condition and the post-loop
 *    test) where retail has one `bgtz` at the head with the timeout call as
 *    its fall-through, and the flag-exit path jumping past the call.
 *
 * 2. THE CONSTANT IS A MASPSX EMULATION GAP, not a source question. Retail
 *    materialises 0x7FFFFFFF as `lui $v1,0x8000; addiu $v1,$v1,-1` -- the
 *    %hi/%lo-style split with the sign carry, which splat then symbolises as
 *    D_7FFFFF (and mis-records as 0x7FFFFF in undefined_syms_auto.txt; the
 *    bytes 3C038000 2463FFFF say 0x7FFFFFFF). cc1psx emits `li $v1,0x7fffffff`
 *    and maspsx's expand_load_immediate turns it into `lui 0x7FFF; ori 0xFFFF`
 *    -- same value, different bytes -- and upstream maspsx (mkst, checked
 *    2026-09-04) still does. Binary-wide scan: retail contains ZERO
 *    `lui r,K; ori r,r,M` pairs with M >= 0x8000, so aspsx 2.79 never emits
 *    the lui/ori form for such a value; the sign-adjusted form is what it
 *    does, and the count of such pairs the scan found is below.
 *    auto-symbols that are NOT RAM/scratchpad addresses (true constants): 10 ['0x7fffff', '0x80210000', '0x8021007a', '0x8021007b', '0x8021007c', '0x8021007d', '0x8021007e', '0x8021007f', '0xa000df80', '0xa000dfac']
 *    lui/addiu pairs on a TRUE constant (aspsx sign-adjusted form): 2
 *        func_8008B5C4 D_A000DFAC 0xa000dfac
 *        func_8008B5C4 D_A000DF80 0xa000df80
 *    (A first version of this scan counted 740 pairs, 392 with bit 15 set,
 *    and was WRONG: undefined_syms_auto.txt is mostly real RAM addresses that
 *    lack a declared symbol, and cc1psx forms those pairs itself with no
 *    maspsx involvement. Only values outside the RAM ranges are constants.)
 *    The fix belongs in build.py as a post-maspsx rewrite, the
 *    SMALL_DATA_NOP_FUNCS precedent -- versioned, per function, documented as
 *    an emulation gap -- not in the gitignored tools/maspsx checkout and not
 *    by spelling a constant as `&D_7FFFFF` in the source.
 */
#include "common.h"

s32 func_8005C5D4(void) {
    s32 n;

    if (D_8009B062 == 0) {
        for (n = 0x7FFFFFFF; n > 0; n--) {
            if (D_8009B062 != 0) {
                break;
            }
        }
        if (n <= 0) {
            func_8008FBE0(1);
        }
    }
    D_8009B062 = 0;
    return 0;
}
