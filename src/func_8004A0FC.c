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

/* Stereo pan and volume for one sound object, in 1.14/1.7 fixed point.

   `a2` is the pan position, 0..0x7F with 0x40 dead centre: taken from the
   global at D_8009B458[0x4BF] plus the object's own two trim bytes and the
   source's byte 1, less 0xC0, then clamped to 0..0x7F -- unless the global
   flag at [0x815] is set, which forces dead centre. It is written back to
   obj[0xC] before being used, so the clamped value is what the rest of the
   engine sees. The level is a chain of fixed-point multiplies -- a master
   pair from the globals, the source's two per-sound scalars, the object's
   two -- and the two channels are then scaled by the halfword pair at
   D_8009B458 + 0x7E4/0x7E6 and by obj[0xE]'s low 7 bits before landing in
   the halfwords at obj+0x14 and obj+0x16.

   THE THREE ABSOLUTE RELOADS NEED THREE ALIASES AND THREE LOCALS.
   D_8009B458 is func_800738F0 at three points and the target re-materialises the
   address each time. Under -G0 -mno-split-addresses that falls out, but only
   with BOTH a distinct extern alias per site (D_8009B458 / _b / _c, all
   registered allow_duplicated) AND a distinct local per site (g1/g2/g3). One
   shared local makes gcc keep a single register live across all three and
   costs about 45 diffs on its own -- the aliases alone are not enough.

   obj[0xE] IS READ TWICE AND gcc WILL CSE THE SECOND AWAY. Both reads are
   `*(volatile u8 *)`; without that the function is 95 words against 96 and
   the diff count stops meaning anything.

   THE == 0x40 ARM RECOMPUTES A VALUE IT ALREADY HAS, AND THAT IS THE POINT.
   All three arms want the same level in $a0; the centre case is just
   `a1v = a0v`. Written that way gcc emits `move a1,v1` instead of the
   target's `move a1,a0`, because a0v is a copy of v1 and copy propagation
   substitutes the source of the copy. Nothing about spelling reaches it:
   assigning from v1 explicitly, flipping the inner branch, reordering the
   two setup statements, giving a0v a second use, pinning v1, and unpinning
   a0v were all measured and all stay at 1/96 or regress. What works is
   REDEFINING a0v with an expression first --
   `a0v = (a2 * (a1v << 1)) >> 7; a1v = a0v;` -- which is the a2 < 0x40 arm's
   own formula and reduces to exactly a0v when a2 is 0x40, so it is a no-op
   in value and costs no instruction. Once a0v is the result of an expression
   rather than a copy, there is no copy for gcc to propagate through and the
   move reads $a0. It has to be TWO statements: folding it into one
   (`a1v = (a2 * (a0v << 1)) >> 7`) is 44/96 at 97 words, and using a1v as
   the operand of a single statement is back to 1/96. Found by
   decomp-permuter after the hand search was exhausted, at internal score 30
   against a base of 35 -- a non-zero score, so `harvest` would have left it
   parked. */

extern u8 *D_8009B458;
extern u8 *D_8009B458;
extern u8 *D_8009B458;

void func_8004A0FC(u8 *o, u8 *src) {
    register u8 *obj asm("a3");
    s32 a2;
    u8 *g1;
    u8 *g2;
    u8 *g3;
    s32 v1;
    s32 vt;
    s32 a1v;
    register s32 a0v asm("a0");
    s32 c40;

    obj = o;
    g1 = D_8009B458;
    if (g1[0x815] != 0) {
        a2 = 0x40;
    } else {
        a2 = g1[0x4BF] + obj[0xA] + obj[0xB] + src[1] - 0xC0;
    }
    if (a2 < 0) {
        a2 = 0;
    }
    if (a2 >= 0x80) {
        a2 = 0x7F;
    }
    obj[0xC] = a2;

    g2 = D_8009B458;
    v1 = g2[0x4BC] * *(u16 *)(g2 + 0x512);
    v1 = v1 * src[5];
    v1 = v1 * src[3];
    v1 = v1 >> 14;

    v1 = v1 * obj[8];
    vt = v1 * obj[9];
    v1 = vt >> 14;

    a1v = v1;
    if (a2 >= 0x40) {
        a0v = v1;
        c40 = 0x40;
        if (a2 == c40) {
            a0v = (a2 * (a1v << 1)) >> 7;
            a1v = a0v;
        } else {
            a1v = ((c40 - (a2 & 0x3F)) * (a0v << 1)) >> 7;
        }
    } else {
        __asm__("" : "+r"(a1v));
        a0v = (a2 * (a1v << 1)) >> 7;
    }

    g3 = D_8009B458;
    a2 = a1v * *(s16 *)(g3 + 0x7E4);
    a0v = a0v * *(s16 *)(g3 + 0x7E6);
    a1v = a2 >> 7;
    v1 = a1v * (*(volatile u8 *)(obj + 0xE) & 0x7F);
    a0v = a0v >> 7;
    a2 = a0v * (*(volatile u8 *)(obj + 0xE) & 0x7F);
    *(u16 *)(obj + 0x14) = v1 >> 7;
    *(u16 *)(obj + 0x16) = a2 >> 7;
}
