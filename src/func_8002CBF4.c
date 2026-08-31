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

/* Reads card record D_801D4244[idx - 1], takes either its low 9 bits or bits
   9..17 depending on `shift`, multiplies that by 10, adds
   func_8002497C(record >> 26 & 0x1F), and clamps the sum to 0..9999.

   MATCHED 0/45 by w1 (2026-08-28), exact word count, on both split combos
   (G8:split and G0:split; both nosplit combos give 42/45).

   THE 11/45 RESIDUAL WAS THE CLAMP, and the recorded diagnosis had it as a
   wall. Inherited note: "target's bltz delay slot holds the real needed
   value `move v0,zero` directly, but candidate's gets opportunistically
   filled with `move v0,s0` instead ... No known lever forces gcc to pick the
   'right' filler among two equally-valid delay-slot candidates." Two general
   levers (a nested-ternary clamp, a goto-to-shared-return restructure) and a
   `"+r"` barrier had each been tried and failed, the barrier with literally
   zero effect.

   There was no filler to choose between. Reading target's tail as three
   unconditional assignments -- because a delay slot runs on both paths --
   gives the shape directly:

       bltz s0,exit / move v0,zero      ->  result = 0;   then test s0 < 0
       slti / bnez  / move v0,s0        ->  result = s0;  then test s0 >= 10000
       li s0,9999   / move v0,s0        ->  s0 = 9999;    result = s0;

   Writing it that way took 11/45 to 9/45. The last piece is that target
   emits `move v0,s0` TWICE from ONE source statement: it clamps s0 in place
   and assigns the result once afterwards, and gcc duplicates that single
   assignment into the branch's delay slot as well as after the clamp. So

       if (s0 >= 10000) { s0 = 9999; }
       result = s0;

   rather than assigning the result on both arms. That is 0/45. Writing the
   result on each arm instead makes gcc emit `li v0,9999` and skip the copy,
   which is the extra word.

   Trimmed and re-measured rather than inherited: the `register s32 result
   asm("v0")` pin that was needed at the intermediate 9/45 stage is NOT
   needed once the clamp shape is right (still 0/45 without it), so it is
   gone. The two things that ARE still load-bearing, both re-checked by
   removal: the raw-asm v1*10 sequence (plain `s0 = v1 * 10` gives 25/45,
   because gcc lands the intermediate v1*5 directly in $s0 and skips
   target's v0-then-s0 two-register shape), and the v1 pins on the record
   load (dropping them gives 7/45). The two disjoint-lifetime v1 pins --
   the branch-local `t` and the outer `v1` -- coexist deliberately. */

extern s32 D_801D4244[];
extern s32 func_8002497C(s32);

s32 func_8002CBF4(s32 idx, s32 shift) {
    register s32 v1 asm("v1");
    s32 s0;
    s32 field;
    s32 result;

    if (shift) {
        register s32 t asm("v1") = D_801D4244[idx - 1];
        v1 = t >> 9;
    } else {
        register s32 t asm("v1") = D_801D4244[idx - 1];
        v1 = t;
    }
    v1 &= 0x1FF;
    __asm__ volatile(
        "sll $2, %1, 2\n\t"
        "addu $2, $2, %1\n\t"
        "sll %0, $2, 1"
        : "=r" (s0)
        : "r" (v1)
        : "$2"
    );
    field = (D_801D4244[idx - 1] >> 26) & 0x1F;
    s0 += func_8002497C(field);

    result = 0;
    if (s0 >= 0) {
        if (s0 >= 10000) {
            s0 = 9999;
        }
        result = s0;
    }
    return result;
}
