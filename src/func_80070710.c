/* ASSEMBLY DEBT -- this is a TRANSCRIPTION, not a decompilation.
 * Ordinary MIPS written into an inline asm block to force a match. It is
 * byte-exact and therefore invisible to build.py, which is exactly the
 * problem: the oracle cannot tell transcribed assembly from real C, so
 * nothing but this comment stops it being counted as done.
 * Counted by tools_src/asm_debt.py; the standard is in docs/ASM_DEBT.md.
 */
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

/* Looks up D_800917F0[D_8009B361[0]*9] (9-byte-stride record array, byte
   0). Documented as permuter-immune (45 PERM/ALT variants tied, 2.5M+
   permuter iterations, zero movement) with the residual described as a
   "v0/v1 register-role swap vs original" -- that framing undersold the
   real issue.

   Target computes the D_8009B361 index byte's ADDRESS directly into $a0
   (lui a0,%hi; lb a0,%lo(a0), self-referencing, same pattern already
   seen on func_80047B68/func_80024200), not into a scratch register the
   way a plain array func_800738F0 naturally would. But the bigger structural
   piece: table's address is split HI-first/LO-last around idx's whole
   block, specifically so the LO half (`addiu v0,...`, independent of
   a0) fills the one-cycle MIPS I load-delay slot after `lb a0` for
   free -- computing table's address as one atomic unit (either fully
   before or fully after idx) always left nothing to fill that slot,
   forcing a real wasted `nop` and costing an extra word. No amount of
   register pinning alone reaches this; it needed the address split
   into two raw asm halves with idx's own block sandwiched between them,
   matching target's literal instruction order. */

extern s8 D_800917F0[];
extern s8 D_8009B361[];

s8 func_80070710(void) {
    register s8 *table asm("v0");
    register s32 idx asm("a0");

    __asm__("lui %0,%%hi(D_800917F0)" : "=r" (table));
    __asm__("lui %0,%%hi(D_8009B361)" : "=r" (idx));
    __asm__("lb %0,%%lo(D_8009B361)(%1)" : "=r" (idx) : "r" (idx));
    __asm__("addiu %0,%1,%%lo(D_800917F0)" : "=r" (table) : "r" (table));
    return table[idx * 9];
}
