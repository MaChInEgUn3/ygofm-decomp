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

/* Same *D_8009B45C struct as set_8009b45c_vals_matching_id.c (ids[4] table
   at 0x404). Builds a 4-bit mask (bits 20-23) marking which of the 4 ids
   are >= the threshold at f4, then hands it to func_80076ED0. */
struct S8009B45C {
    char pad0[4];
    u16 f4;    /* 0x4 - threshold */
    char pad1[0x404 - 6];
    u16 ids[4]; /* 0x404 */
};

extern struct S8009B45C *D_8009B45C;
extern void func_80076ED0(s32 a0, u32 a1);

void func_80047A68(void) {
    s32 i;
    u32 mask = 0x100000;
    u32 result = 0;
    u16 threshold = D_8009B45C->f4;

    for (i = 0; i < 4; i++) {
        if (D_8009B45C->ids[i] >= threshold) {
            result |= mask;
        }
        mask <<= 1;
    }
    func_80076ED0(0, result);
}
