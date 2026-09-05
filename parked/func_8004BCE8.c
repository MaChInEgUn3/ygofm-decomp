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
 */
#include "common.h"

s32 func_8004BCE8(void) {
    u8 *p;
    u32 r;
    u32 v;
    s32 m;

    p = D_8009B458 + 0x518;
    D_8009B458[0x801] = 0;
    *(s32 *)(D_8009B458 + 0x7F0) = 0;
    do {
        *(s32 *)(D_8009B458 + 0x7F4) = 0;
        v = 8;
        *(s32 *)(D_8009B458 + 0x518) = v;
        *(s16 *)(D_8009B458 + 0x7FC) = func_8004BCA8(p);
        *(s16 *)(D_8009B458 + 0x7FA) = 1;
        *(s16 *)(D_8009B458 + 0x7F8) = 0;
        *(s32 *)(D_8009B458 + 0x7EC) = 0x10000;
        r = (u32)func_8004BC2C(p) >> 8;
        *(s32 *)(D_8009B458 + 0x808) = r;
    } while (0);

    v = 60000000 / r;
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
