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

/* D_8009B458 loop: for i in [0,count) at 0x7FA: record[i].byte(+0x53C
   base, absolute D_8009B458+0x53C+i*0x2C)=1; record[i].word(+0x518 base,
   absolute D_8009B458+0x518+i*0x2C)=0 -- two PARALLEL 44-byte-stride
   sub-arrays overlaid via a shared running byte offset. D_8009B458 is
   reloaded FRESH from ROM every iteration (not loop-invariant-hoisted).

   Landed via 3 fixes on top of the oversized-extern-array trick (forces
   absolute addressing under G8 without G0's more aggressive LICM):
   1. Register pins matching target's exact physical registers (v1=base,
      a1=i, a0=off, a2=the constant 1) -- 13/23 -> 9/23.
   2. Target self-reuses ONE register for both the symbol's hi-half and
      the final loaded value (`lui v1,%hi(sym); lw v1,%lo(sym)(v1)`)
      for BOTH the initial load and the per-iteration reload; a plain C
      func_800738F0 always materializes the hi-half into a separate scratch
      register instead. Forced via raw `__asm__` for both occurrences --
      9/23 -> 5/23.
   3. The per-iteration reload must act as a genuine memory barrier (an
      empty "memory"-clobbered volatile asm) or gcc reorders the
      `base[off+0x53C]=1` store to AFTER the reload+increment instead of
      before it (both semantically safe since off/one don't change, but
      byte-different) -- 5/23 -> 1/23. The remaining 1-word residual was
      a commutative addu operand-order tie (`v1+a0` vs `a0+v1`), fixed by
      writing the index expression as `(off + base)[0x53C]` instead of
      `base[off + 0x53C]` -- 1/23 -> 0/23.
   Confirmed via tools/verify_match.py: 0 diffs, exact word count,
   -G8 -msplit-addresses. */
extern u8 *D_8009B458[3];
extern u8 *D_8009B458[3];

void func_8004CA60(void) {
    register u8 *base asm("v1");
    u16 count;
    register s32 i asm("a1");
    register s32 off asm("a0");
    register s32 one asm("a2");

    __asm__(
        "lui %0, %%hi(D_8009B458)\n\t"
        "lw %0, %%lo(D_8009B458)(%0)"
        : "=r" (base)
    );
    count = *(u16 *) (base + 0x7FA);

    if (count == 0) {
        return;
    }

    i = 0;
    one = 1;
    off = 0;
    do {
        (off + base)[0x53C] = (u8) one;

        __asm__ volatile(
            "lui %0, %%hi(D_8009B458)\n\t"
            "lw %0, %%lo(D_8009B458)(%0)"
            : "+r" (base)
            :
            : "memory"
        );
        i += 1;
        *(s32 *) (base + off + 0x518) = 0;
        count = *(u16 *) (base + 0x7FA);

        off += 0x2C;
    } while (i < count);
}
