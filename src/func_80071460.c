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

/* func_80071460 (0x80071460, 15 words).  Store the current value of the
 * D_8009B364 byte into slot func_8007058C() of the D_800F5B98 table.
 *
 * Sibling of func_80071424 (src/func_80071424.c) -- identical shape,
 * D_8009B364/u8 where that one has D_8009B361/s8.
 *
 * RE-DECOMPILED FROM ASSEMBLY 2026-08-29 (w1), under the operator's C-only
 * directive.  The previous source was 0/15 with two emitting asm blocks --
 * a `lui %hi / addiu %lo / sll` block plus a separate `addu` block -- filed
 * under WALL-FAMILY:final-addr-register-choice and pinned to
 * -G8 -msplit-addresses.  It is preserved at
 * match/attempts/func_80071460_asm_island_prior.c.  This version is plain C,
 * 0/15 at ALL FOUR -G/split combos, and the asm that remains emits nothing.
 *
 * WHAT THE ASSEMBLY WAS ACTUALLY FORCING.  The whole residual was three
 * words of ORDER, not addressing:
 *
 *     ROM    lui v1,0x800f / addiu v1,v1,23448 / sll v0,v0,0x2
 *     plain  sll v0,v0,0x2 / lui v1,0x800f / addiu v1,v1,23448
 *
 * Same three instructions, same registers, exact word count.  Both the
 * table-base materialisation and the index shift are priority-1
 * register-only insns, so SCHED-1 says the tie keeps SOURCE order -- and
 * with the table written as a subscript (`D_800F5B98[idx] = ...`) the shift
 * belongs to the same statement as the store, so nothing in the source sits
 * between the call and the shift.  Giving the base its own statement func_8008FAF0
 * it there.  The empty launder is what stops cse folding that statement
 * back into the subscript: measured, `s32 *base = D_800F5B98;` alone is
 * 6/15 at split and 10/15 at nosplit, and with the launder it is 0/15
 * everywhere.  A `register s32 *base asm("v1")` pin also reaches 0/15 but
 * only at the two split combos, so the launder is the better lever -- it
 * makes the unit flag-independent instead of flag-dependent.
 *
 * ADDR-1 NOTE, because this unit looks like a case for it and is not.  The
 * ROM carries a self-referencing `lui a0,0x800a / lbu a0,-19612(a0)` pair,
 * which reads as the gas macro expansion under -mno-split-addresses.  It is
 * not evidence for nosplit here: at nosplit this function is 14 words, ONE
 * SHORT, because the indexed store collapses into the three-word $at macro
 * form.  Consistent with w3's correction -- only the $at form is
 * decisive-nosplit, and a self-ref pair falls out of split compiles too.
 * Re-sweep all four combos per unit; never pin a flag off a self-ref pair.
 */

extern s32 func_8007058C(void);
extern s32 D_800F5B98[];
extern u8 D_8009B364[];

void func_80071460(void) {
    s32 idx = func_8007058C();
    s32 *base = D_800F5B98;

    /* Zero words -- see the header: keeps the base its own statement so the
       lui/addiu pair precedes the index shift. */
    __asm__("" : "+r"(base));

    base[idx] = D_8009B364[0];
}
