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

/* Sets up the GTE geometry offset/screen distance, builds a rotation matrix
   from a packed 24-bit Euler angle (arg0, split into 8-bit X/Y/Z fields) via
   the PSX scratchpad SVECTOR/MATRIX at 0x1F800308/0x1F8002D0, installs it as
   the light-source matrix, then runs an average-normal-clip test over three
   zeroed scratchpad SVECTORs (0x1F800308/0x1F800310/0x1F800318, the last one
   passed twice) and returns the resulting OTZ (GTE data register 24, func_800738F0
   via raw swc2 since there's no C-level accessor for it). Also fills out
   *arg3 with the raw (arg1, arg2, 0) offset it was given. */
struct Out {
    s16 f0;
    s16 f2;
    s32 f4;
};

struct Mat {
    char pad14[0x14];
    s32 f14;
    s32 f18;
    s32 f1C;
};

struct Vec308 {
    s16 f0;
    s16 f2;
    s16 f4;
    char pad8[0x8 - 0x6];
    s16 f8;
    char pad12[0x12 - 0xA];
    s16 f12;
};

struct Vec310 {
    char pad2[0x2];
    s16 f2;
    s16 f4;
};

struct Vec318 {
    s16 f0;
    char pad4[0x4 - 0x2];
    s16 f4;
};

extern void func_800878B0(s32 a0, s32 a1);
extern void func_800878D0(s32 a0);
extern void func_80088C50(struct Vec308 *a0, struct Mat *a1);
extern void func_800855D0(struct Mat *a0);
extern s32 func_80089CF0(struct Vec308 *a0, struct Vec310 *a1, struct Vec318 *a2, struct Vec318 *a3);

s32 func_80041E7C(u32 arg0, s32 arg1, s32 arg2, struct Out *arg3) {
    struct Vec308 *v308;
    struct Mat *mtx;
    s32 otz;

    arg3->f0 = arg1;
    arg3->f2 = arg2;
    arg3->f4 = 0;

    func_800878B0(arg1, arg2);
    func_800878D0(0x12C);

    mtx = (struct Mat *)0x1F8002D0;
    v308 = (struct Vec308 *)0x1F800308;

    v308->f0 = (s16)((arg0 & 0xFF) * 0x10);
    v308->f2 = (s16)((arg0 >> 4) & 0xFF0);
    v308->f4 = (s16)((arg0 >> 0xC) & 0xFF0);

    func_80088C50(v308, mtx);

    mtx->f14 = 0;
    mtx->f18 = 0;
    mtx->f1C = 0x12C;

    func_800855D0(mtx);

    {
        register struct Vec318 *v318 asm("a3") = (struct Vec318 *)0x1F800318;
        struct Vec310 *v310 = (struct Vec310 *)0x1F800310;

        v318->f0 = 0;
        v308->f0 = 0;
        v308->f8 = 0x200;
        v310->f2 = 0;
        v308->f2 = 0;
        v308->f12 = 0x200;
        v318->f4 = 0;
        v310->f4 = 0;
        v308->f4 = 0;

        func_80089CF0(v308, v310, v318, v318);
    }

    {
        s32 *p = &otz;
        __asm__ volatile("swc2 $24, 0(%0)" : : "r"(p) : "memory");
    }

    return otz;
}
