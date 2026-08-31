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

/* Looks up two indices into D_800F5B98's table, then writes a scaled
   D_800917F0 lookup back into the table at a third index: if the second
   lookup value is 0, the func_80073900 uses valA*9+one; otherwise
   lookupB+(valA*9+one).

   w3 permuter pass (2026-08-27/28): closed the last 2/49 -> 1/49 -> 0/49
   residual (w2's 2/49 seed, then a plateau-harvest reseed to 1/49) via
   decomp-permuter blind search. No C-level lever closed the final
   register/operand-order tie across 2 prior sessions; the permuter's own
   operand reordering did. D_800F5B98 needs the standard raw
   lui-into-v0-then-addiu-into-s2 trick (far-global address materialized
   through v0, then moved into the register the rest of the function keeps
   it pinned in) to match target's absolute addressing; tbl/valA stay
   register-pinned (s2/s0). The unused `deadS1` s1-pin, the `one` local
   (rather than a bare literal 1), and the stray empty statement after it
   are exactly what the permuter's winning candidate had -- all three are
   load-bearing for the register allocation (confirmed by hand: removing
   any one of them regresses to 3/49) despite looking removable, so kept
   verbatim rather than "cleaned up". */

extern s32 func_8007058C(void);
extern s32 D_800F5B98[];
extern s8 D_800917F0[];

void func_800734DC(void) {
    register s32 *tbl asm("s2");
    register s32 valA asm("s0");
    s32 lookupB;
    s32 idxA;
    register s32 deadS1 asm("s1");
    s32 idxB;
    s32 idxC;
    s32 one;

    {
        register s32 hi asm("v0") = 0x800f0000;
        asm("addiu %0, %1, 0x5b98" : "=r" (tbl) : "r" (hi));
    }
    idxA = func_8007058C();
    valA = tbl[idxA];
    idxB = func_8007058C();
    lookupB = tbl[idxB];
    one = 1;
    ;
    idxC = func_8007058C();
    if (!lookupB) {
        tbl[idxC] = D_800917F0[valA * 9 + one] * 100;
    } else {
        tbl[idxC] = D_800917F0[lookupB + (valA * 9 + one)];
    }
}
