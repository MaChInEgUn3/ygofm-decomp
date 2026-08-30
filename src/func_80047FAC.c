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

// Scans 4 entries in D_8009B45C's array at +0x404 (stride 2, u16) for ones
// matching the low 16 bits of a0, counting how many also have a nonzero
// func_80077C50 result written to the stack-local it queries per entry.
extern u8 *D_8009B45C;

extern void func_80077C50(s32 a0, s16 *a1);

s16 func_80047FAC(s32 a0) {
    u16 s1 = 0;
    s32 s0;
    u16 s2 = a0 & 0xFFFF;

    for (s0 = 0; s0 < 4; s0++) {
        s16 local;
        u16 *entry;

        func_80077C50(s0 + 0x14, &local);

        entry = (u16 *)(D_8009B45C + s0 * 2 + 0x404);
        if (*entry == s2) {
            if (local != 0) {
                s1++;
            }
        }
    }

    return (s16)s1;
}
