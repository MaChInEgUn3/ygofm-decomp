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

/* Damage-style scaling curve keyed off a1&0xFF against a threshold of 0x40:
   below it, scales -a0[0x11] by the distance under 0x40 (0 if that field is
   unset); at or above it, scales a0[0x10] by the distance over 0x3F (0 at
   exactly 0x40, or if that field is unset). */
s16 func_8004A3BC(u8 *a0, s32 a1) {
    u8 v1 = a1 & 0xFF;
    s32 v0;

    if (v1 < 0x40) {
        if (a0[0x11] == 0)
            return 0;
        v0 = -((s32)(a0[0x11] << 1) * (0x40 - (a1 & 0xFF)));
    } else {
        if (v1 == 0x40)
            return 0;
        if (a0[0x10] == 0)
            return 0;
        v0 = (s32)(a0[0x10] << 1) * ((a1 & 0xFF) - 0x3F);
    }
    return (s16)v0;
}
