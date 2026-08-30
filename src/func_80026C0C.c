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

/* Scans 5 stride-28 entries starting at index
   v1=D_8009B1D5*15+a0 for one with field22's 0x8000 bit clear, returns
   v1+a1 or -1. */

struct Rec {
    char pad0[22];
    u16 f22;
    char pad24[28 - 24];
};

extern u8 D_8009B1D5;
extern struct Rec D_801A7AD8[];

s32 func_80026C0C(s32 a0) {
    register s32 v1 asm("v1");
    register s32 addr asm("a0");
    s32 a1;
    s32 v0;

    v1 = D_8009B1D5 * 15 + a0;
    addr = v1 * 8 - v1;
    addr = addr * 4;
    addr = addr + (s32) D_801A7AD8;
    a1 = 0;
    do {
        if (!(((struct Rec *) addr)->f22 & 0x8000)) {
            v0 = v1 + a1;
            goto exit;
        }
        a1++;
        addr += 28;
    } while (a1 < 5);
    v0 = -1;
exit:
    return v0;
}
