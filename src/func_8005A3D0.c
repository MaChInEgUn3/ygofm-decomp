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

/* Blacklist reclamation, 2026-08-28 (w2): 11/38 -> 0/38, matching at ALL FOUR
   flag combos, so this unit constrains no per-TU flag.

   Nested backlink search over obj->arr (0x50-byte records, a self-pointer
   field at 0x4C).  The outer loop finds the first record whose f4C equals
   `a1`; the inner loop then re-scans the same array for a record whose f4C
   points AT that record.  If one is found, the outer index is returned
   immediately; otherwise the outer scan continues, and if it runs out the
   final index is returned.  count is re-func_800738F0 from memory at each site the
   target re-reads it, because the inner loop's loads may alias it.

   WHAT THREE PASSES GOT WRONG, and it is one thing.  The recorded history
   reads: "pure register-color permutation" (31/38); then "NOT a recolor, the
   inner-loop CFG differs, needs a genuine loop-shape rework"; then a
   register-pinning pass 31 -> 12; then a v0-scoped comparison pin 12 -> 11;
   then two dead levers on the tail and the verdict "a source-shape-invariant
   branch-polarity choice specific to goto-based backward branches ... needs a
   genuinely different idea".

   It needed a rule already in the manual: A COMPUTATION IN A BRANCH DELAY
   SLOT IS UNCONDITIONAL, so hoist it out of the conditional.  The target's
   outer backedge is

       bnez  $v0, .L8005A3E8
        addiu $t2, $t2, 0x50      <- runs whether or not the branch is taken

   and every previous candidate kept that increment INSIDE the `if`.  gcc then
   has nothing to fill the delay slot with, so it emits a beqz-skip plus a
   separate backward `j` -- one word too many, after which every later diff
   position is shifted and the count is unreadable.  Hoisting `t2 += 1` above
   the test is the whole fix, and it is worth 11 diffs on top of the pins.
   The reported symptom ("beqz + explicit j instead of a bnez backedge") was
   accurate all three times; it is a CONSEQUENCE of the empty delay slot, not
   a branch-polarity property of goto loops.

   THE PINS ARE STILL LOAD-BEARING -- measured, not assumed.  A 32-shape sweep
   over every pin independently (with the hoist in place) matches on exactly
   two shapes: all pins present, and all pins present except the inner
   walking-pointer's v1 pin, which is the one that is optional.  The v1 alias
   is shared between `cnt` and `v1ptr` across disjoint scopes because the
   target reuses one physical register for both once cnt is dead. */

typedef struct {
    char pad[0x4C];
    void *field4C; /* 0x4C */
    char pad2[0x50 - 0x4C - 4];
} Rec;

typedef struct {
    char pad[0xD14];
    Rec *arr; /* 0xD14 */
    char pad2[0xE17 - 0xD14 - 4];
    u8 count; /* 0xE17 */
} Obj;

s32 func_8005A3D0(Obj *a0, void *a1) {
    register s32 t0 asm("t0");
    register s32 t3 asm("t3");
    register Rec *t2 asm("t2");
    register s32 a2 asm("a2");
    register s32 t1 asm("t1");
    register void *a3target asm("a3");

    {
        register s32 cnt asm("v1") = a0->count;
        t0 = 0;
        if (cnt == 0) {
            goto L_ret;
        }
        t3 = t0;
        t2 = a0->arr;

    L_outer:
        a2 = 0;
        if (t2->field4C != a1) {
            goto L_bottom;
        }
        if (cnt == 0) {
            goto L_bottom;
        }
        t1 = cnt;
        a3target = (u8 *) a0->arr + t3;
    }

    {
        register Rec *v1ptr asm("v1") = a0->arr;

    L_inner:
        if (v1ptr->field4C == a3target) {
            goto L_afterinner;
        }
        a2 += 1;
        if (a2 < t1) {
            v1ptr += 1;
            goto L_inner;
        }
    }

L_afterinner:
    {
        register s32 cmp asm("v0") = a2 < a0->count;
        if (cmp) {
            goto L_ret;
        }
    }

L_bottom:
    t3 += 0x50;
    t2 += 1;
    {
        register s32 cnt asm("v1") = a0->count;
        t0 += 1;
        if (t0 < cnt) {
            goto L_outer;
        }
    }

L_ret:
    return t0;
}
