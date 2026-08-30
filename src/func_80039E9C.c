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

/* Same *D_800EB010 struct as func_8002EB78.c (0x4C-byte stride). Resets
   all 3 records: f30=-1 (empty sentinel), f32/f3A/f3B=0, and zeroes the
   0x0-0x2F grid region. Then fills D_8015C410[0..4] with -1. */
struct Rec {
    s32 grid[4][3];
    s8 f30;
    char pad1[0x32 - 0x31];
    u8 f32;
    char pad2[0x3A - 0x33];
    u8 f3A;
    u8 f3B;
    char pad3[0x4C - 0x3C];
};

extern struct Rec D_800EB010[];
extern s8 D_8015C410[5];

void func_80039E9C(void) {
    s32 i;
    s32 c;
    register s32 j asm("a1");

    for (i = 2; i >= 0; i--) {
        struct Rec *r = &D_800EB010[i];

        r->f30 = -1;
        r->f32 = 0;
        r->f3A = 0;
        r->f3B = 0;
        for (c = 2; c >= 0; c--) {
            r->grid[0][c] = 0;
            r->grid[1][c] = 0;
            r->grid[2][c] = 0;
            r->grid[3][c] = 0;
        }
    }

    {
        s8 *p;
        register s32 neg1 asm("v1") = -1;
        j = 4;
        p = D_8015C410 + j;
        for (; j >= 0; j--) {
            *p = neg1;
            p--;
        }
    }
}
