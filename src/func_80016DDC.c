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

/* Blacklist reclamation (config/blacklist.txt, was stuck at 27/37 -- one
   word short -- across several sessions). Diff-clamp step function: as
   the gap between f12 and f14 grows, the per-tick correction step grows
   too (9/19/47/97 for |diff| < 300/1000/3000/inf).

   The tier chain compiles to gcc's "fallthrough-accumulate" shape only
   when written as three INDEPENDENT (non-nested, non-elseif) sequential
   ifs each unconditionally overwriting `step` -- a flat if/elseif chain
   or an equivalent chained ternary both compile 1 word short instead
   (skip-around branches, not the accumulate-then-branch-to-merge shape
   the ROM actually uses). `step` also needs pinning to $a2 (register
   asm("a2")) -- left unpinned, gcc func_8008FAF0 it in the "wrong" half of an
   a1/a2 register-role swap with `mag` that costs nothing in isolation
   but is required for later instructions (the diff-clamp store) to line
   up. `mag`, unpinned, still needs `register T x asm(reg)`-style help
   for exactly one instruction: the abs-value negation. gcc naturally
   copies diff into mag's register in the branch's delay slot (shared by
   both signs, since mag=diff happens unconditionally as the bgez's
   delay-slot fill) but then negates through the ORIGINAL diff register
   instead of the fresh mag copy when diff<0 (a CSE/equivalence
   substitution) -- target does a genuine in-place `negu $r,$r` off the
   copy. A raw `negu %0, %0` (same register for src and dst) inside the
   if-block forces the in-place form. Verified 0/37 via MCP match. */

struct Obj {
    char pad[0x12];
    s16 f12;
    s16 f14;
};

void func_80016DDC(struct Obj *a0) {
    s32 diff = a0->f12 - a0->f14;
    register s32 step asm("a2");
    s32 mag;

    if (diff == 0) {
        return;
    }

    mag = diff;
    if (mag < 0) {
        __asm__ volatile("negu %0, %0" : "+r" (mag));
    }

    step = 9;
    if (mag >= 300) {
        step = 19;
    }
    if (mag >= 1000) {
        step = 47;
    }
    if (mag >= 3000) {
        step = 97;
    }

    if (diff > 0) {
        diff -= step;
        if (diff < 0) {
            diff = 0;
        }
    } else {
        diff += step;
        if (diff > 0) {
            diff = 0;
        }
    }

    a0->f12 = (u16) a0->f14 + diff;
}
