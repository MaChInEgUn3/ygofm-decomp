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

extern s32 func_80036D3C(void *a0);
extern void func_8003FF88(void);
extern void func_8003FEE0(void);
extern u16 D_8009B33C;
extern s32 D_8009B350;

/* Checks the low-16-bit flags word from func_80036D3C(a0); if bit 0x8000 is
   set, runs func_8003FF88(), stashes a second func_80036D3C(a0)
   result into D_8009B33C, marks a0->f51=0x11 and D_8009B350=1; otherwise
   runs func_8003FEE0(). Target keeps a genuine `andi ,0xffff` mask
   instruction even though it's logically redundant for a later `&0x8000`
   test (masking to 16 bits doesn't change bit 15) -- an explicit `& 0xFFFF`
   on a full-width local (not an implicit (u16) truncation, which gcc folds
   away here) reproduces the real instruction. */
void func_80038798(u8 *a0) {
    register u8 *s0 asm("s0") = a0;
    register u32 flags asm("a0") = func_80036D3C(a0) & 0xFFFF;
    register s32 bit asm("v0");

    asm volatile("" : "+r"(flags));
    bit = flags & 0x8000;
    if (bit) {
        func_8003FF88();
        D_8009B33C = (u16) func_80036D3C(s0);
        s0[0x51] = 0x11;
        D_8009B350 = 1;
    } else {
        func_8003FEE0();
    }
}
