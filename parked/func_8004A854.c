/* 11 differing at 36/36. Needs a -G8 compiler with a -G0 assembler.
 *
 * 2026-09-04: RECOVERED from git (the Unchiga merge deleted it and put a
 * transcription in src/), re-measured at 13, and taken to 11 by ONE character:
 * `bestv` initialised to -1 rather than 0xFFFF.
 *
 * Why that works. Retail masks before the compare -- `andi $v0,$t0,65535` then
 * `sltu $v0,$v0,$a2` -- and with `bestv = 0xFFFF` gcc folds the `(u16)` cast
 * away, because every value it can hold (0xFFFF, or a `u16` load) provably fits
 * sixteen bits. -1 is the same value through the cast and is NOT provably
 * bounded, so the mask survives. Two differences.
 *
 * What it costs, and this is the open half. Retail materialises the two
 * constants separately -- `addiu $t1,$zero,-1` for `best` and
 * `ori $t0,$zero,65535` for `bestv` -- because they are different 32-bit
 * values. Writing both as -1 makes them one value, so gcc materialises it once
 * and copies: `addu $t0,$t1,$zero`. That is the func_8003C7A0 rule
 * ("a literal and a variable holding the same value are two materialisations")
 * running against us. Something is needed that is 0xFFFF as a constant AND not
 * provably sixteen-bit, and `u16 bestv` is not it (13), nor is `u32` with the
 * cast (13).
 *
 * The rest of the residue is prologue ORDER, not registers: retail emits
 * `i = 0` as the loop guard's delay slot and derives `o = i` after it, where we
 * emit `o = 0` early and derive `i = o`. Writing the pair the other way round
 * in the source (`s32 o = 0; s32 i = o;`) does not swap them back (13).
 * 2026-09-05, all re-measured under default -G8 with as -G0 (the file's
 * -G0 -mno-split-addresses row scores the same 11): `u16 bestv = 0xFFFF`
 * with u16 or s32 v (13, 13), `s32 bestv = 0xFFFF` with an explicit `& 0xFFFF`
 * in the compare (13) or with s32 v (13), `o = 0; i = o;` (11), a shared
 * `z = 0` for both (11), and the guard-plus-do/while form for the `i++` in
 * the lh delay slot (-2). Three faults, each measured alone: the 0xFFFF that
 * must stay unbounded, the zero pair's direction, and the increment's slot.
 */
#include "common.h"

s32 func_8004A854(u8 arg0) {
    s32 best = -1;
    s32 bestv = -1;
    s32 i = 0;
    s32 o = i;

    while (i < *(s16 *)(D_8009B458 + 0x510)) {
        u8 *p = D_8009B458 + o;
        u16 v = *(u16 *)(p + 0x19E);

        if ((u16)bestv >= v && p[0x183] == arg0 && p[0x18D] != 0) {
            bestv = v;
            best = i;
        }
        i++;
        o += 0x28;
    }

    return best;
}
