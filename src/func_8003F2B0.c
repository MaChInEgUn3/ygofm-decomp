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

/* Runs func_80042B98(a0,a1,a2,a3); if it reports failure (0), falls back to
   func_80043178(a0). Then advances a0's f60 countdown by +-0x40 toward 0
   (whichever direction f60's current sign calls for), clamping f6C to 0 and
   f60 to 0 once the countdown crosses zero. Always runs func_80043230(a0,
   a1,a2), and, when a3 is a valid (non-negative) index, also notifies
   func_80039934 with a pointer into the a3'th 100-byte D_800EB0F8 slot plus
   a0's f30/f32 fields. Returns the (possibly just-cleared) f6C flag. */
struct Obj8003F2B0 {
    char pad0[0x30];
    s16 f30;                /* 0x30 */
    s16 f32;                  /* 0x32 */
    char pad1[0x60 - 0x34];
    s16 f60;                    /* 0x60 */
    char pad2[0x6C - 0x62];
    u8 f6C;                       /* 0x6C */
};

extern u8 D_800EB0F8[];

extern s32 func_80042B98(struct Obj8003F2B0 *a0, s32 a1, s32 a2, s32 a3);
extern void func_80043178(struct Obj8003F2B0 *a0);
extern void func_80043230(struct Obj8003F2B0 *a0, s32 a1, s32 a2);
extern void func_80039934(u8 *a0, s32 a1, s32 a2);

u8 func_8003F2B0(struct Obj8003F2B0 *s0, s32 a1, s32 a2, s32 a3) {
    s32 s1 = a3;
    register s32 f60 asm("a3");

    if (func_80042B98(s0, a1, a2, a3) == 0) {
        func_80043178(s0);
    }

    f60 = s0->f60;
    if (f60 < 0) {
        f60 = f60 + 0x40;
        if (f60 >= 0) {
            s0->f6C = 0;
            f60 = 0;
        }
    } else {
        f60 = f60 - 0x40;
        if (f60 <= 0) {
            s0->f6C = 0;
            f60 = 0;
        }
    }
    s0->f60 = f60;

    func_80043230(s0, a1, a2);

    if (s1 >= 0) {
        func_80039934(D_800EB0F8 + s1 * 100, s0->f30, s0->f32);
    }

    return s0->f6C;
}
