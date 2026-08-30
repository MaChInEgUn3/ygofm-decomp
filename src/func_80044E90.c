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

/* Sets D_8009B45C's f514/f515 byte fields from arg0: if arg0-1 is in
   [0,0x80) sets f514=-0x80-arg0, f515=0x80; else if arg0+0x80 is in
   [0,0x80) sets f514=0x80, f515=-0x80-arg0; else sets both to 0x80.
   Finishes by calling func_80044DC0(D_8009B45C->f510).

   Was stuck at 1/50 (see prior header, now superseded): the target keeps a
   single copy of arg0 in $a1 (set once, unconditionally, in the first
   branch's delay slot) and reuses that SAME register for both
   `-0x80-arg0` computations. A plain C alias for the value only got 3 of 4
   residual sites right (gcc keeps picking $a0 for one of the two sites
   since both registers hold the provably-equal value); an explicit
   register pin -- `register s32 a1 asm("a1") = arg0;`, used at BOTH sites
   -- forces gcc's hand and closed the last word. Confirmed via
   tools/msearch.py: 0/50, exact word count, -G0 -mno-split-addresses. */
struct S8009B45C {
    u8 pad0[0x510];
    s16 f510;
    u8 pad512[0x514 - 0x512];
    u8 f514;
    u8 f515;
};

extern struct S8009B45C *D_8009B45C;
extern void func_80044DC0(s32 a0);

void func_80044E90(s32 arg0) {
    register s32 a1 asm("a1") = arg0;

    if ((u16) (arg0 - 1) < 0x80) {
        D_8009B45C->f514 = (u8) (-0x80 - a1);
        D_8009B45C->f515 = 0x80;
    } else if ((u16) (arg0 + 0x80) < 0x80) {
        D_8009B45C->f514 = 0x80;
        D_8009B45C->f515 = (u8) (-0x80 - a1);
    } else {
        D_8009B45C->f514 = 0x80;
        D_8009B45C->f515 = 0x80;
    }
    func_80044DC0(D_8009B45C->f510);
}
