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

extern u8 *D_8009B45C;
extern void func_80045334(s32 a0);
extern void func_80049138(s32 a0, s32 a1);

void func_800472A8(s32 a0) {
    u8 *p;
    u32 v0;
    s32 v1;

    p = D_8009B45C;
    v0 = p[0x4A];
    if ((v0 & 2) == 0) {
        return;
    }
    v1 = a0;
    /* Target snapshots a0 into its own register here even though a0 is
       still unmodified; without this barrier gcc proves the copy
       redundant and reuses a0 directly instead. */
    asm volatile("" : "+r"(v1));
    if ((a0 & 0x8000) != 0) {
        func_80045334(v1 & 0xFFFF);
        return;
    }
    v0 = v1 & 0xFFFF;
    if (v0 >= 0x7000) {
        a0 = a0 - 0x7000;
    }
    a0 = (s16) a0;
    func_80049138(a0, 1);
}
