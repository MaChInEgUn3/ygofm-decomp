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

struct Quad {
    u32 w0, w1, w2, w3;
};

/* D_800F2C40 is an array of 0xE20-byte records; only the 16-byte block at
   +0xDB0 is touched here. */
struct Rec {
    u8 pad[0xDB0];
    struct Quad q;
};

extern u8 D_800F2C40[];

/* Copies *a1 into record a0's field at +0xDB0, or (if a1 is null) resets
   its first three words to 0x1000 (the 4th word, w3, is left untouched). */
void func_800594C0(s32 a0, struct Quad *a1) {
    struct Rec *v1 = (struct Rec *)(D_800F2C40 + a0 * 0xE20);

    if (a1 != 0) {
        v1->q = *a1;
    } else {
        v1->q.w2 = 0x1000;
        v1->q.w1 = 0x1000;
        v1->q.w0 = 0x1000;
    }
}
