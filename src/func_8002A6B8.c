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

extern s8 D_8009B258;
extern s8 D_8009B259;

/* Combines two signed byte fields (D_8009B259, D_8009B258) into a single
   linear index below 723 (0x2D3), or 0 if the combination would exceed it.
   D_8009B259's tens/ones digits are weighted 200/10, D_8009B258 contributes
   its ones digit plus a flat +100 once it reaches double digits. */
s32 func_8002A6B8(void) {
    s32 month = D_8009B259;
    s32 q1 = month / 10;
    s8 q1b = (s8)q1;
    s32 acc = q1b * 200;
    s8 rem1 = (s8)(month - q1 * 10);
    s32 total;
    s32 day;
    s32 q2;
    s8 r2;
    register s32 result asm("v0");

    acc = acc + rem1 * 10;

    day = D_8009B258;
    if (day >= 10) {
        acc = acc + 0x64;
    }
    total = acc + 1;
    q2 = day / 10;
    r2 = (s8)(day - q2 * 10);
    acc = total + r2;
    result = 0;
    if (acc < 0x2D3) {
        result = acc;
    }
    return result;
}
