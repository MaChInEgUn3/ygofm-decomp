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

/* Same *D_8009B458 struct as func_800495DC.c / func_80049544.c /
   func_800498F8.c; sets the "idle/default" values for the
   fields those functions later check or clear individually (f814, f815,
   f4A4, f81C). Register pins reproduce the target's exact base-pointer
   coloring: p1(v1)/p2(v0) hold the reload for their field group, c7F(a0)
   and cM1(a1) hold the reused 0x7F/-1 constants across intervening
   reloads (see project_full_pin_solves_clean_permutation). */
struct S8009B458 {
    char pad0[0x4A4];
    s16 f4A4;                   /* 0x4A4 */
    char pad1[0x4BD - 0x4A6];
    u8 f4BD;                    /* 0x4BD */
    u8 f4BE;                    /* 0x4BE */
    u8 f4BF;                    /* 0x4BF */
    char pad2[0x500 - 0x4C0];
    u8 f500;                    /* 0x500 */
    u8 f501;                    /* 0x501 */
    u8 f502;                    /* 0x502 */
    char pad3[0x510 - 0x503];
    u16 f510;                   /* 0x510 */
    u16 f512;                   /* 0x512 */
    u16 f514;                   /* 0x514 */
    u16 f516;                   /* 0x516 */
    char pad4[0x7E0 - 0x518];
    s16 f7E0;                   /* 0x7E0 */
    u16 f7E2;                   /* 0x7E2 */
    u16 f7E4;                   /* 0x7E4 */
    u16 f7E6;                   /* 0x7E6 */
    char pad5[0x80C - 0x7E8];
    u32 f80C;                   /* 0x80C */
    u32 f810;                   /* 0x810 */
    u8 f814;                    /* 0x814 */
    u8 f815;                    /* 0x815 */
    char pad6[0x81C - 0x816];
    s32 f81C;                   /* 0x81C */
};

extern struct S8009B458 *D_8009B458;

void func_80049434(void) {
    register struct S8009B458 *p1 asm("v1");
    register struct S8009B458 *p2 asm("v0");
    register s32 c7F asm("a0");
    register s32 cM1 asm("a1");

    D_8009B458->f500 = 0;
    D_8009B458->f501 = 0;
    D_8009B458->f502 = 0;

    p1 = D_8009B458;
    p1->f510 = 0x14;
    p1->f814 = 0;
    c7F = 0x7F;
    p1->f512 = c7F;
    p1->f514 = c7F;
    p1->f516 = c7F;

    D_8009B458->f815 = 0;

    p2 = D_8009B458;
    p2->f4BD = c7F;
    cM1 = -1;
    p2->f4A4 = cM1;
    D_8009B458->f4BE = c7F;
    D_8009B458->f4BF = 0x40;

    p2 = D_8009B458;
    p2->f7E0 = cM1;
    p2->f7E2 = 0;
    p2->f7E6 = c7F;
    p2->f7E4 = c7F;
    p2->f80C = 0;
    p2->f810 = 0;
    p2->f81C = 0x1000;
}
