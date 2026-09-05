/* 17 differing at 97/97 (2026-09-05; was +1 at 98/97 and 82, then 38, 22). RECOVERED from git
 * 2026-09-04 (the Unchiga merge deleted it and put a transcription in src/).
 *
 * The +1 is the third `andi $v0,$a1,0xFF`: gcc fills the `m != 0x3C` branch's
 * delay slot by copying the shared mask block's first instruction, where
 * retail's mask block BEGINS with `addu $a0,$s0,$zero` -- the func_8004BAE4
 * argument -- so that copy is what retail's slot holds. Eight spellings
 * measured 2026-09-04 and none of them reaches it:
 *   the argument named as `a = p;` at the `mask:` label                  +1
 *   the same pinned with `do { } while (0);`                            +1
 *   named at the top of the dispatcher, before `m` is read              +1
 *   named inside both shift arms with explicit gotos                    +5
 * (the park entry had already measured it at the `store:` join: +4). A named
 * call argument is constant-propagated back to the call from every position,
 * which is the func_80025F3C rule; that entry's answer was to name an
 * UNRELATED read in the same block instead, and that has not been tried here.
 * On the other recorded fault, the +0x808 store sinking past the divu:
 *   the divisor read BACK from +0x808 (func_80048F14's read-back rule)      +1, 82
 *   the store pinned with `do { } while (0);`                              +1, 83
 *   a base local for the first store so it shares p's load                 +1, 82
 *   read-back and base local together                                      +1, 82
 * All at +1, so none of these was measured on a sound instrument; re-try
 * them once the length is right.
 * 2026-09-05: default -G8 with as -G0, with and without split addresses,
 * is the same +1/82; every arm writing its own `c = v & 0xFF; goto store;`
 * tail is +1/81 under both flag rows and also puts the 0x1E arm inline.
 * Read off the listing: retail's `addu $a0,$s0,$zero` sits in its OWN block
 * (.L8004BDFC) between the two shift arms and the andi, and the two paths
 * that skip it carry it in their delay slots -- reorg's copy-the-target-
 * and-retarget-to-target+4 -- so the copy was a real instruction ahead of
 * the mask in the source's join, not the call's argument setup.
 *
 * +1 -> 0/39 (2026-09-05, permuter, decomposed): a `do { } while (0);` round
 * the seven statements from the +0x7F4 store to the func_8004BC2C call. The
 * extra andi was not an andi problem at all; with the block pinned the
 * dispatcher's join comes out with retail's copies and the length is exact.
 * The permuter's other two edits (`c = m;` for the test, a named address for
 * the last store) are worth nothing on their own or on top (41).
 * 39 -> 38: the +0x808 store inside the same pin. Dead at exact length: the
 * divisor read back (39), `p` pinned alone (+2), a named pointer for the
 * store block (39), the store pinned alone (+1).
 * What is left is register allocation throughout: retail loads the base into
 * $v1 and forms p before the first byte store; the reciprocal block runs in
 * $v0/$v1 where ours uses $a0/$a1; and the join's copy/andi order.
 * 38 -> 22 (permuter, decomposed): TWO COUPLED EDITS. `v = 8;` written
 * before the +0x518 store (borrowing the later result name) is 42 alone;
 * the clamp value split as `v = 60000000 / r; v = v * 100 / 115;` is 32
 * alone; together 22. A third edit in the same output, `r = call; r = r >>
 * 8;`, is worth nothing alone or on top. Same class as func_80026D18's
 * pair: each half reads as a regression until the other is in.
 * Dead at 22: the first byte store and word store moved inside the pin (24),
 * p as well (27), the dividend named (`k = 60000000;`, 22), a named pointer
 * for the store block (22), the +0x808 store back outside the pin (39).
 * 22 -> 17 (permuter, decomposed): NO `c` at all -- the arms only shift,
 * and the two halfword stores mask inline, `= v & 0xFF`. That closes the
 * join's copy/andi order entirely (rows 64-74). The output also split the
 * `>> 8` into `>> 5 >> 3` through a named 5, a passenger worth nothing.
 * What is left: the prologue (retail forms p = base + 0x518 before the
 * first byte store and copies it into $a0 before the two word stores; the
 * 8 in $v0, ours $a1) and the reciprocal block (retail: srl into $a1, lui
 * 915, base load, ori, sw, divu $v0,$a1; ours: base load, srl, sw, lui/ori,
 * divu $v1,$v0).
 * 17 -> 13 (2026-09-05, second pass, three coupled edits): a base local
 * `b = D_8009B458; p = b + 0x518; b[0x801] = 0;` so the +0x518 store goes
 * through the base loaded BEFORE the byte store (retail's `sw $v0,1304($v1)`
 * -- the sb through the pointee forces the reload every other store uses);
 * the dividend named INSIDE the pin right before the +0x808 store
 * (`k = 60000000;`, 17 -> 15 on its own; before the call it is 92, i.e. a
 * length change); and with the base local in, the `v = 8;` borrow that was
 * worth 20 on the old base is now WORSE -- the 8 written inline in the
 * store is 15 -> 13. Dead on this base: `a = p;` for the call argument (13),
 * `r = call; k = ...; r = r >> 8;` (13), p formed after the byte store (13),
 * k moved above the +0x7EC store (92), the p assignment pinned (87).
 * What is left: retail forms p and copies it into $a0 BEFORE the reload
 * and the two word stores (ours after them), and the reciprocal block's
 * order (retail srl into $a1, lui, base load, ori, sw, divu; ours lui/ori
 * first, srl into $v0).
 * Permuter from the 13-base (2026-09-05, ~4500 iterations, 13 outputs):
 * its best, `r = 0x3C; if (m != r)` (0x3C borrowed into the dead r), fixes
 * the reciprocal block's ORDER -- srl first, lui / base load / ori / sw /
 * divu exactly as retail -- but rotates r into $v1 and m into $a0, so it
 * reads 17 by position. The prologue half (p formed and copied before the
 * reload) is untouched by it. `k = 0x3C` is 19; `p = 0x518 + b` is nothing.
 *
 * 13 -> 7 (2026-09-05, permuter output-120-1 at ~9000 iterations): the
 * call result goes through the LATER result name -- `v = (u32)call >> 8;
 * r = v;` -- the func_8002A4A8 borrow (v's live range resumes at the
 * division), and the whole reciprocal block then comes out in retail's
 * order and registers. Chained `r = v = ...` and `v = r = ...` are the same
 * 7; the two-statement form is installed. On top of it the 0x3C borrow and
 * `r = 8` are nothing. What is left is the PROLOGUE only: retail forms
 * `addiu $s0,$v1,1304` before the byte store and copies it into $a0 before
 * the two word stores; re-measured dead here: `a = p` before or after the
 * sb (7, 7), p through the symbol before b (7), declaration order (7), the
 * p assignment pinned (87), the sb through p (88).
 */



#include "common.h"

s32 func_8004BCE8(void) {
    u8 *b;
    u8 *p;
    u32 r;
    u32 v;
    s32 m;
    u32 k;

    b = D_8009B458;
    p = b + 0x518;
    b[0x801] = 0;
    *(s32 *)(D_8009B458 + 0x7F0) = 0;
    do {
        *(s32 *)(D_8009B458 + 0x7F4) = 0;
        *(s32 *)(b + 0x518) = 8;
        *(s16 *)(D_8009B458 + 0x7FC) = func_8004BCA8(p);
        *(s16 *)(D_8009B458 + 0x7FA) = 1;
        *(s16 *)(D_8009B458 + 0x7F8) = 0;
        *(s32 *)(D_8009B458 + 0x7EC) = 0x10000;
        v = (u32)func_8004BC2C(p) >> 8;
        r = v;
        k = 60000000;
        *(s32 *)(D_8009B458 + 0x808) = r;
    } while (0);

    v = k / r;
    v = v * 100 / 115;
    if (v >= 0x100) {
        v = 0xFF;
    }

    m = *(u16 *)(D_8009B458 + 0x7FC);
    if (m == 0x1E) {
        goto sh2;
    }
    if (m < 0x1F) {
        if (m == 0x18) {
            goto sh1;
        }
        goto store;
    }
    if (m != 0x3C) {
        goto mask;
    }
sh1:
    v >>= 1;
    goto mask;
sh2:
    v >>= 2;
mask:
store:
    *(s16 *)(p + 0x16) = v & 0xFF;
    *(s16 *)(p + 0x14) = v & 0xFF;
    func_8004BAE4(p);

    if (*(u16 *)(D_8009B458 + 0x7FC) >= 0x60) {
        *(s32 *)(D_8009B458 + 0x804) = *(u16 *)(D_8009B458 + 0x7FC);
    } else {
        *(s32 *)(D_8009B458 + 0x804) = 0;
    }
    *(s32 *)(D_8009B458 + 0x804) = *(u16 *)(D_8009B458 + 0x7FC);
    return 1;
}
