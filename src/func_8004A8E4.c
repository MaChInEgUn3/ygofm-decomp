/* PORTED from Unchiga's decompilation of SLUS_014.11, shared 2026-08-30.
 * His C, his comments; the identifiers are rewritten to this repo's address
 * form and nothing else was touched. Verified the only way that counts here:
 * tools_src/build.py rebuilds the retail image byte-for-byte with this in it.
 *
 * Self-contained by design -- it keeps his declarations rather than ours,
 * because a declaration is a codegen input and his are what this C matched
 * under. See docs/MERGE_UNCHIGA.md and tools_src/install_ported.py.
 */
/* Decrements a per-record counter in the D_8009B458 table: reads the type
   byte at rec[3] of entry idx, and unless it is 99, walks to the record at
   base + type*24 and decrements the low nibble of its byte 6 if nonzero.

   MATCHED 0/23 on ALL FOUR flag combos (2026-08-28, w1). History: 7/23 ->
   2/23 (w1, chain pins, see below), 2/23 -> 0/23 (w1, same pass as
   func_8003A198's func_80073910).

   WHAT CLOSED THE LAST 2. Residual was 0x8004a8f8/0x8004a8fc: target does
   addiu v0,v0,384 then addu a1,a2,v0, this compile folded the addiu into
   the a1-pinned pointer (addiu a1,v0,384 then addu a1,a2,a1). Right
   destination, WRONG TEMP REGISTER -- gcc homes the offset temp in the
   pinned destination register itself because that register is free.
   The general fix, confirmed on two functions in one pass: route the final
   add through a minimal 2-input inline asm addu, which takes the pinned
   destination out of the temp's candidate set. Here the operand must stay
   UNPINNED (plain s32 off) -- gcc then picks v0 on its own, exactly what
   target does. Pinning off to v0 as well regresses to 21/23. Contrast
   func_8003A198, where the same asm-addu lever needed its operand pinned
   to $v1; so the rule is: try the asm addu with unpinned operands FIRST,
   and only add an operand pin if the temp still lands wrong.
   A single combined asm ("addiu %0,%0,0x180; addu %1,%2,%0" with "+r"(mult)
   and "=r"(rec1)) also reaches 0/23 -- kept the two-statement form because
   it matches the rest of this file and leaves both instructions
   schedulable.
   Dead ends re-measured from the 2/23 base: v0-pinned off with the asm addu
   21/23; v0-pinned mult reused in place for the +0x180 3/23; v0-pinned off
   with plain-C addition 6/23; dropping the a1 pin entirely 8/23.

   CORRECTNESS TRAP, REPRODUCED AND THEN AVOIDED -- func_800738F0 this before touching
   the *24 chain. Pinning ONLY the output to v1 scores better (7 -> 5) and is
   WRONG: with a plain "=r" output and no early-clobber, gcc is free to
   allocate %0 == %1, and it does, emitting sll v1,v1,1 then addu v1,v1,v1,
   which computes v*4 and then v*32 instead of v*3 and v*24. The byte-diff
   counter still improved, by coincidence. This function's own history
   records the same trap once before. Pinning BOTH ends makes the aliasing
   impossible without needing "=&r"; adding "=&r" instead of the second pin
   regresses to 17/23, so early-clobber is not a substitute here.
   ALWAYS func_800738F0 the operand registers in the disassembly after touching this
   chain -- the diff count alone will not tell you it is broken. Verified on
   the winning 0/23: sll v0,a0,2 / addu v0,v0,a0 / sll v0,v0,3 and
   sll v1,v0,1 / addu v1,v1,v0 / sll v1,v1,3, both non-aliasing.

   WHAT CLOSED THE EARLIER 5: target's move v0,v1 in the beq delay slot is
   not an opportunistic filler, it is the copy forced by target keeping the
   *24 chain OUTPUT in v1 -- the same register the loaded byte already
   occupies -- so the chain SOURCE has to be copied out to v0 first. v0 is
   free at that point precisely because the li v0,99 it held was consumed by
   the beq immediately before. The single pointer variable pinned to a1 and
   reused for both records (rather than a separate rec1/rec2) is also
   required and is worth 0 on its own -- it only pays off combined with the
   chain pins. */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef short s16;
typedef int s32;

extern u8 *D_8009B458[3];

s32 func_8004A8E4(s32 idx) {
    s32 mult;
    register u8 *base asm("a2");
    register u8 *rec1 asm("a1");
    u8 v;
    __asm__(
        "sll %0, %1, 2\n\t"
        "addu %0, %0, %1\n\t"
        "sll %0, %0, 3"
        : "=r" (mult)
        : "r" (idx)
    );
    __asm__(
        "lui %0, %%hi(D_8009B458)\n\t"
        "lw %0, %%lo(D_8009B458)(%0)"
        : "=r" (base)
    );
    {
        s32 off;
        __asm__("addiu %0, %1, 0x180" : "=r" (off) : "r" (mult));
        __asm__("addu %0, %1, %2" : "=r" (rec1) : "r" (base), "r" (off));
    }
    v = rec1[3];

    if (v != 99) {
        register s32 scaled asm("v1");
        register s32 vcopy asm("v0") = (s32) v;
        u8 f6;

        __asm__(
            "sll %0, %1, 1\n\t"
            "addu %0, %0, %1\n\t"
            "sll %0, %0, 3"
            : "=r" (scaled)
            : "r" (vcopy)
        );
        rec1 = base + scaled;
        f6 = rec1[6];
        if (f6 & 0xF) {
            rec1[6] = f6 - 1;
        }
    }
    return idx;
}
