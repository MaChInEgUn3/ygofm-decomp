/* 8 differing at 27/27. First REAL C written for this function 2026-09-04
 * (src/ holds Unchiga's transcription). Needs -G0 (PER_FUNC_FLAGS/AS_FLAGS
 * already carry it for the transcription).
 *
 * The lever that gets to exact length is the one the old park entry recorded
 * for THIS function and warned is wrong for its sibling func_8004A764: the
 * table read split into an address and a value, `t = &D_80011434[arg0];
 * p = D_8009B458; v = *t;`, so the address is formed before the pointer load
 * the way retail has it. Inline it is 11 with the constant store first and
 * +1 with the table store first.
 *
 * The residue is WHERE the 0x60100 constant is born. Retail's `lui $a2,6` is
 * the first instruction after the frame and its `ori` comes after the table
 * value load -- a long-lived pseudo the scheduler splits around the whole
 * block. Ours materialises it just before its store. Eleven spellings and
 * none moves it: `k = 0x60100;` as the first statement (8), the same pinned
 * with do/while (+1), k declared first (8), p declared last (8), t/p order
 * swapped (8), the +0x4C4 store inline at the top through the symbol (+1),
 * the store moved above `v = *t` (+1), the two word stores in the other
 * order (10), `v` named without `t` (+1), and the two +1 shapes with k.
 * Two of the eight are the D_8009B458 pair self-referencing through $v1 in
 * retail and through $v0 here, which follows from the same allocation.
 * Untried: naming an UNRELATED read in the block (the func_80025F3C rule).
 */
#include "common.h"

void func_8004A6F8(s32 arg0, u8 *arg1) {
    s32 *t;
    u8 *p;
    s32 k;
    s32 v;

    k = 0x60100;
    t = &D_80011434[arg0];
    p = D_8009B458;
    v = *t;
    *(s32 *)(p + 0x4C4) = k;
    *(s32 *)(p + 0x4C0) = v;
    *(u16 *)(p + 0x4FA) = *(u16 *)(arg1 + 0x20);
    *(u16 *)(p + 0x4FC) = *(u16 *)(arg1 + 0x22);
    *(s32 *)(p + 0x4E4) = *(u16 *)(arg1 + 0x24);

    func_80077450(p + 0x4C0);
}
