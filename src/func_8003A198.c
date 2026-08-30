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

/* func_8003A198 -- no confirmed real name. 3-level chained u16-offset table
   walk: base+i1*2 -> off1; base+off1+i2*2 -> off2; base+off2+i3*2 -> off3;
   return off3!=0.

   MATCHED 0/21 on ALL FOUR flag combos (2026-08-28, w1). History:
   14/21 -> 4/21 (w5: shared `goto fail` tail for both early exits, and an
   explicit `if (off != 0) return 1;` third entry into that same tail
   instead of a boolean `return off != 0;`), 4/21 -> 2/21 (w1: stage 3's
   `addu` written as a minimal 2-input inline asm so the pinned $a1 is the
   destination), 2/21 -> 0/21 (w1, below).

   WHAT CLOSED THE LAST 2. The residual was stage 2's `addu` landing in $v0
   instead of the pinned $a1, and every earlier attempt to fix it with the
   SAME asm form that fixed stage 3 regressed to 5-7/21 -- the note on file
   concluded stage 2 "sits too func_80073910 to stage 1's scheduling window" for any
   raw-asm def of `addr`. That diagnosis was wrong. Two separate register
   choices are involved and they have to be fixed TOGETHER:
     - `addr`'s destination register ($a1), fixed by the asm `addu`; and
     - the `i2*2` temporary's register. Target func_8008FAF0 it in $v1
       (`sll v1,a2,1`), and once `addr` is forced into $a1 gcc reuses $a1
       itself as that temporary's home (`sll a1,a2,1; addu a1,v0,a1`) --
       correct destination, wrong operand. Fixing only one of the two makes
       the other wrong, which is why every single-lever attempt scored
       WORSE than leaving both wrong.
   So stage 2 pins the index temp: `register s32 idx2 asm("v1") = i2 * 2;`
   feeding the asm `addu` as its second operand. Note the ASYMMETRY -- the
   same $v1 pin added to stage 3 (variant G) regresses to 4/21, and pinning
   idx2 to $v1 with a plain-C `addr = base + off + idx2` instead of the asm
   (variant F) gives 6/21. Stage 3 must stay on unpinned locals.

   Dead ends confirmed this pass, all fully re-measured from the 2/21 base:
     - `__asm__("" : "+r" (addr))` laundering after a plain-C stage 2 does
       force `addu a1,...` + `lhu v0,0(a1)` (still 2/21, but the residual
       moves to the `sll` destination) -- a real half-fix, not a wall;
     - laundering the unpinned `idx2` as well: 5/21;
     - stage 3's exact asm form on stage 2 with unpinned locals: 5/21;
     - pinning idx2 to $v1 and laundering it: 8/21 (the pin's longer live
       range then cascades back into stage 1's `off`). */

s32 func_8003A198(u8 *base, s32 i1, s32 i2, s32 i3) {
    register u8 *addr asm("a1");
    u16 off;

    addr = base + i1 * 2;
    off = *(u16 *) addr;
    if (off == 0) {
        goto fail;
    }
    {
        u8 *baseoff2 = base + off;
        register s32 idx2 asm("v1") = i2 * 2;
        __asm__("addu %0, %1, %2" : "=r" (addr) : "r" (baseoff2), "r" (idx2));
    }
    off = *(u16 *) addr;
    if (off == 0) {
        goto fail;
    }
    {
        u8 *baseoff3 = base + off;
        s32 idx3 = i3 * 2;
        __asm__("addu %0, %1, %2" : "=r" (addr) : "r" (baseoff3), "r" (idx3));
    }
    off = *(u16 *) addr;
    if (off != 0) {
        return 1;
    }
fail:
    return 0;
}
