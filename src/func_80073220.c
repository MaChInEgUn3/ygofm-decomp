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

/* Blacklist reclamation (sim=0.55 template_match, sibling filter_collect.c /
   func_800732A0: same D_800F5BE8[i+0x38] scan bounded by D_800F5BE8[0xA3],
   collecting values >=11 into D_800EAE88[]). This variant additionally
   zeroes D_800EAE88[0..5] first with a walking pointer (blacklist's own
   writeup misread the polarity as "<11 kept" -- it's actually ">=11 kept",
   same as the sibling).

   The previous blacklist attempt's "weird" upfront zero-trip test the
   analyst couldn't reproduce turned out not to need a manual `if` at all:
   it falls out naturally once `i` (the *first* loop's counter) and `j`
   (the running D_800EAE88 output index, live across BOTH loops from the
   very start) are register-pinned to a0/a1 respectively -- with i left
   an ordinary variable in the second loop, gcc's own for-loop lowering
   reproduces the target's degenerate "if (j != 0) skip" test on its own.
   The first loop also needed a genuine walking pointer computed through
   the pinned counter variable (`p = &D_800EAE88[i0]` with i0 already set,
   not `&D_800EAE88[5]` -- the latter constant-folds the whole address and
   drops the target's separate addu). 0/32. */

extern u8 D_800F5BE8[];
extern u8 D_800EAE88[];

void func_80073220(void) {
    register s32 j asm("a1");
    s32 i;

    j = 0;
    {
        register s32 i0 asm("a0");
        u8 *p;
        i0 = 5;
        p = &D_800EAE88[i0];
        for (; i0 >= 0; i0--) {
            *p = 0;
            p--;
        }
    }

    for (i = 0; i <= D_800F5BE8[0xA3]; i++) {
        register s32 v asm("v1") = D_800F5BE8[i + 0x38];
        if (v >= 11) {
            D_800EAE88[j] = v;
            j++;
        }
    }
}
