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

extern u16 D_801C0000[];
extern u16 D_801D5800[];
extern u16 D_801B0000[];

/* Maps an index range into a 32-bit value: the high half of one of three
   fixed table bases OR'd with a 16-bit entry func_800738F0 from a (possibly
   different) table. a0 is unused. */
u32 func_8003B744(s32 a0, s32 a1) {
    s32 a2 = a1;

    if (a2 > 0xCFFF)
        return ((u32)D_801C0000 & 0xFFFF0000) | D_801C0000[a2 - 0xD000];

    if (a2 > 0x7FFF)
        return ((u32)D_801D5800 & 0xFFFF0000) | D_801D5800[a2 - 0x8000];

    if (a2 >= 0x500)
        a2 -= 0x100;

    return ((u32)D_801B0000 & 0xFFFF0000) | D_801C0000[a2];
}
