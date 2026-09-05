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
 * Tried 2026-09-05, the func_80025F3C rule (an UNRELATED read named): the
 * three arg1 halfwords named at the top (-2), only the first at the top (21),
 * all three after the base load (-2), the first after the constant (21). All
 * worse than the 8, and the permuter's nine outputs from this base are 8 to
 * 19. What retail does -- `lui $a2,6` right after the frame, `ori` after the
 * table load, the table address before the base pair, `sw $ra` late -- is
 * the same schedule the sibling func_8004A764 sits at 6 on.
 * (2026-09-05, eight more) The two halves are reachable SEPARATELY and
 * conflict: with the constant store written first and the table read
 * inline (`u8 *p = D_8009B458;` initialiser), `lui $a2,6` is born first as
 * retail has it -- but then the base load is hoisted above the table pair
 * and a load-delay nop appears (+1: b1, with a named k b4, with `t =
 * D_80011434 + arg0` before p b5). With the t/p/v split the table address
 * precedes the base and the constant is born late (8: parked, and 8 with
 * the constant inline instead of k). Table store first: inline through the
 * initialiser +1, `v` named before p is +1 with the base pair in $a0,
 * t/p/v split 10 (the two word stores swap), and a do/while pin round the
 * first store +2. func_8004A764 sits on the same wall from the other side.
 * Permuter from this base (2026-09-05, ~4000 iterations, ten outputs, none
 * below 8 by position): its best wraps the WHOLE body in `do { } while
 * (0);`, which gets `lui $a2,6` born first and the sll/addu in retail's
 * place -- the constant-first half without losing the address-first half
 * -- at the cost of `sw $ra` moving to the top and the base's `lui` being
 * hoisted above the table pair (10; with p assigned first inside the pin
 * 9; `t = sym + arg0`, k after t, v before k all 9; v inline 10; the p load
 * pinned alone inside 10; -mno-split-addresses on it 25). So the pin is a
 * third half-lever; what fixes the prologue store's position is not found.
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
