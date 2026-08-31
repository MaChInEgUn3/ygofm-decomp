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

/* Same D_800F5BE8 base as scan_table2_80070870.c etc. */
extern u8 D_800F5BE8[];

extern u8 D_800EAE88[];

/* Scans D_800F5BE8[56..56+limit] (limit at offset 163) and copies entries
   >= 11 into D_800EAE88. */
void func_800732A0(void) {
    s32 count, i;
    for (count = 0, i = 0; i <= D_800F5BE8[163]; i++) {
        s32 v = D_800F5BE8[i + 56];
        if (v >= 11) {
            D_800EAE88[count] = v;
            count++;
        }
    }
}
