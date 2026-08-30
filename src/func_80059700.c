/* PORTED from Unchiga's decompilation of SLUS_014.11, shared 2026-08-30.
 * His C, his comments; the identifiers are rewritten to this repo's address
 * form and nothing else was touched. Verified the only way that counts here:
 * tools_src/build.py rebuilds the retail image byte-for-byte with this in it.
 *
 * Self-contained by design -- it keeps his declarations rather than ours,
 * because a declaration is a codegen input and his are what this C matched
 * under. See docs/MERGE_UNCHIGA.md and tools_src/install_ported.py.
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef short s16;
typedef int s32;

extern s32 func_8005A468(s32 a0, s32 a1);

struct RecD800F2C40 {
    char pad[0xE0D];
    u8 field_e0d;
    char pad2[0xE16 - 0xE0D - 1];
    u8 field_e16;
    char pad3[0xE20 - 0xE16 - 1];
};

extern struct RecD800F2C40 D_800F2C40[];

/* CORRECTION (2026-08-28, w5): the nearmiss db's recorded "6/50, sha
 * 68b01375" baseline does not reproduce -- a clean /tmp/sw restage of the
 * identical committed source (match/attempts/tmp_best_80059700.c, byte-
 * diffed against this file's body) gives 13/50 via msearch, verify_match.py,
 * AND a fresh manual cmp.sh run alike; the original 6/50 measurement was
 * almost certainly a stale /tmp/sw include-dir artifact from that session,
 * never a real 13-diff regression introduced since. True baseline is 13/50,
 * with an extra, previously undocumented 7-word residual BEFORE the
 * already-known doubled/a1-a2 issue: the function's FIRST
 * `rec = &D_800F2C40[idx]` computes idx*0xE20 (sll/subu/sll/addu/sll) THEN
 * the D_800F2C40 base address (lui/addiu) THEN adds them; target computes
 * the BASE FIRST, then the offset, then adds -- pure scheduling tie, and
 * notably the SECOND identical `&D_800F2C40[idx]` expression later in this
 * same function (rec2, in L_after) already compiles offset-then-base like
 * my candidate, meaning target's own build is order-INCONSISTENT between
 * the two syntactically-identical expressions (each site schedules
 * differently depending on what surrounds it, confirming the general "no
 * copy-paste between sites" rule). Fixed by naming the base address as its
 * own local computed before the offset, for the FIRST occurrence only.
 *
 * Once that lands, the remaining 6/50 is the documented doubled=a2-vs-a1
 * residual (5 dead levers logged in nearmiss/db.jsonl, do not repeat):
 * target computes doubled=field_e0d*2 into a2, then does TWO separate
 * move-a1,a2 copies (one per use site); this compile always allocates a1
 * (not a2) for the multiply result, so gcc coalesces the "copy" away and
 * the flipped register choice cascades into beq/bne polarity + jump
 * targets on both dispatch branches downstream. 2 MORE dead levers tried
 * this pass on top of the 5 already logged (do not re-try): pinning
 * doubled to asm("a2") directly -- regressed to 26/50 (52w), re-confirming
 * the documented pin regression under the NEW (post base-fix) baseline;
 * an asm volatile keep-alive func_800738F0 of doubled right after computing it --
 * 8/50, still worse than plain. Also tried and confirmed NO EFFECT:
 * splitting doubled into two separately-scoped locals (d1/d2) at each use
 * site instead of reusing one variable -- gcc CSEs them back together,
 * byte-identical 6/50. Banking at 6/50 (7 total dead levers on this
 * specific residual now); needs a genuinely different idea or permuter
 * territory once someone re-triages under the corrected 6/50 baseline. */

/* UPDATE (2026-08-28, w1): still 6/50 by COUNT, but the residual is a
 * different and much better-shaped one -- the a1/a2 half is SOLVED and the
 * whole branch-polarity cascade with it. Do not restore the old body.
 *
 * The old note framed this as "target computes doubled into a2 then does TWO
 * separate move-a1,a2 copies; this compile always allocates a1 for the
 * multiply result, so gcc coalesces the copy away and the flipped register
 * choice cascades into beq/bne polarity + jump targets on both dispatch
 * branches" -- 7 dead levers, all aimed at the register choice. The register
 * choice was the symptom. The cause is that the C put `a1 = doubled` INSIDE
 * the v1 == 60 arm, while target executes it UNCONDITIONALLY: it sits in the
 * delay slot of `beq v1,v0,0x800597ac`, and the `a1 = 0` in the v1 < 61 arm
 * is likewise the delay slot of that arm's own beq. Same rule as
 * project_delay_slot_computation_is_unconditional_hoist_it. Hoisting both
 * assignments out of their branches is what fixes the polarity: gcc then
 * emits target's beq-into-the-call instead of bne-away-to-the-return, and
 * both jump targets follow.
 * Hoisting alone is not enough, and this is the coupled part: with
 * `a1 = doubled` unconditional, gcc coalesces the two variables and computes
 * the shift straight into a1 (22/50, one word short). It needs, together:
 *   - a1 pinned to a1 AND doubled pinned to a2 (pinning only doubled is the
 *     26/50 regression the old note recorded -- correct, but it was only ever
 *     half the lever), and
 *   - an empty register-only `__asm__("" : "+r" (a1));` right after the
 *     unconditional `a1 = doubled;` to block the coalesce. Zero words.
 * That yields both `move a1,a2` copies exactly where target has them.
 *
 * REMAINING 6/50 is now ONE contiguous window, 0x80059764-0x80059778, same
 * instruction multiset rotated by one:
 *     target:    lbu v0,e0d / lbu v1,e16 / sll a2,v0,1 / li v0,60 / beq / move a1,a2
 *     candidate: li v0,60 / lbu a2,e0d / lbu v1,e16 / sll a2,a2,1 / move a1,a2 / beq
 * i.e. gcc loads the byte straight into the pinned a2 and shifts in place,
 * then hoists `li v0,60` up to fill the load-delay slot target fills with the
 * second lbu. Textbook PERMUTABLE-REORDER; re-triage and stage.
 * Dead this pass, do not repeat: an inline-asm `sll` from an unpinned or
 * v0-pinned temp DOES fix the lbu/sll pair (sll a2,v0,1 exact) but the asm
 * block is unschedulable, so the second lbu can no longer fill the first
 * one's load-delay slot and the tail shifts -- 24/50 either way; an
 * inline-asm `move a1,a2` at BOTH copy sites 21/50 and at the first site
 * only 6/50 (same shape as this file, but the asm move cannot sit in the
 * beq delay slot, so the launder version is strictly better); a "+r" launder
 * on doubled instead of on a1 7/50; splitting the field reads into a named
 * e0d temp, pinned or not, no effect. */

/* MATCHED 0/50 (2026-08-28, w1) at -msplit-addresses, both -G8 and -G0;
 * both -mno-split combos give 18, so the unit needs split addresses.
 *
 * HOW IT CLOSED, in three stages, because only the first was hand work:
 *   1. HAND, 6/50 (see the UPDATE above, kept): the a1/a2 half was never a
 *      register-allocation tie -- `a1 = doubled` and `a1 = 0` are both
 *      UNCONDITIONAL in target, sitting in their respective beq delay slots,
 *      and hoisting them out of their branches is what fixes the whole
 *      beq/bne polarity cascade. Needs the a1+a2 pins AND an empty
 *      register-only launder on a1 to stop gcc coalescing the two.
 *   2. PERMUTER WINDOW 1, 6 -> 4: its entire edit was MOVING that launder
 *      from before `if (v1 == 60)` to after it.
 *   3. PERMUTER WINDOW 2, 4 -> 0: it moved the launder again, this time
 *      INSIDE the L_after block ahead of a1's first assignment, and split
 *      `doubled` into two reads -- one for the unconditional `a1 = doubled`
 *      and a separate named copy for the else arm's `a1 = doubled_copy`.
 *      That is [[project_fresh_name_defeats_recompute_swap]] applied to a
 *      value, not an address: two names for one value give the allocator the
 *      freedom to keep target's second `move a1,a2`.
 * The permuter emitted the copy as `char new_var`, which is a byte
 * truncation the generated code does not actually perform. Retyped to s32
 * here and re-verified 0/50 -- do not restore the char, it made the C say
 * something the bytes do not.
 *
 * PLACEMENT OF A ZERO-COST LAUNDER IS A REAL KNOB: three different positions
 * of the same `__asm__("" : "+r" (a1));` scored 6, 4 and 0. Search it before
 * concluding a launder does not help.
 */


void func_80059700(s32 idx, s32 sign) {
    struct RecD800F2C40 *rec;
    s32 doubled_copy;
    s32 v1;
    register s32 a1 asm("a1");
    register s32 doubled asm("a2");

    {
        struct RecD800F2C40 *base = D_800F2C40;
        rec = base + idx;
    }

    if (sign > 0) {
        goto L_62;
    }
    if (sign >= 0) {
        goto L_35;
    }
    rec->field_e16 = 60;
    goto L_after;
L_35:
    rec->field_e16 = 35;
    goto L_after;
L_62:
    rec->field_e16 = 62;

L_after:
    {
        struct RecD800F2C40 *rec2 = &D_800F2C40[idx];
        doubled = rec2->field_e0d * 2;
        v1 = rec2->field_e16;
        __asm__("" : "+r" (a1));
    }
    doubled_copy = doubled;
    a1 = doubled;
    if (v1 == 60) {
        goto L_negate;
    }
    if (v1 < 61) {
        a1 = 0;
        if (v1 == 35) {
            goto L_call;
        }
        return;
    } else {
        a1 = doubled_copy;
        if (v1 == 62) {
            goto L_call;
        }
        return;
    }

L_negate:
    a1 = -a1;

L_call:
    func_8005A468(idx, a1);
}
