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

/* One D_800EFE48-style display-object slot, as touched by this function
   (see func_800400AC.c for the pool this comes from). fC is
   written both as a packed 0x00RRGGBB-style word and as individual bytes
   (a fade color), hence the union. */
union FadeColor {
    u32 w;
    struct { u8 b0, b1, b2, b3; } b;
};

struct FadeObj {
    char pad0[0x4];
    u32 f4;                 /* flags */
    char pad8[0xC - 0x8];
    union FadeColor fC;     /* color */
    char pad10[0x30 - 0x10];
    s16 f30;                /* x */
    s16 f32;                /* y */
    char pad34[0x40 - 0x34];
    u16 f40;
    u16 f42;
    u16 f44;
    u16 f46;
    char pad48[0x4A - 0x48];
    u16 f4A;
    char pad4C[0x5C - 0x4C];
    u8 f5C;
    u8 f5D;
    char pad5E[0x60 - 0x5E];
    s16 f60;                 /* fade/lifetime counter */
};

struct Entity {
    struct FadeObj *f0;      /* primary fade object */
    struct FadeObj *f4;      /* secondary fade object */
    char pad8[0x30 - 0x8];
    s8 f30;                  /* position seed byte */
    char pad31[0x33 - 0x31];
    u8 f33;
    s16 f34;                 /* x */
    s16 f36;                 /* y */
    char pad38[0x40 - 0x38];
    s16 f40;                 /* 0 = first-time spawn, nonzero = active/growing */
};

extern s32 func_80039F1C(void);
extern void func_80039FD4(struct Entity *a0);
extern s32 func_8004002C(void);
extern struct FadeObj *func_800400AC(s32 a0, s32 a1);
extern void func_80040510(struct FadeObj *a0, s32 a1, s32 a2, s32 a3, s32 a5, s32 a6, s32 a7, s32 a8, s32 a9, s32 a10);
extern void func_80042918(struct FadeObj *a0);
extern void func_800428EC(struct FadeObj *a0, s32 a1);
extern void func_8004036C(void *p);
extern u16 D_8009B0D8;

/* First-time init (arg0->f40 == 0) allocates two paired fade objects: the
   first positioned from arg0's own fields with a pseudo-random offset
   derived from arg0->f30, the second re-derived from the first's computed
   position. On every call (including re-entry with f40 != 0) it then steps
   f0's f60 lifetime counter by D_8009B0D8 (growing while f40 != 0, shrinking
   otherwise): once it drops to/below 0 the pair is torn down and f4 freed;
   once it reaches 0x14 (steady state) func_80039FD4 finishes the setup;
   in between it drives a color/size fade on both objects from the counter. */
void func_8003B054(struct Entity *arg0) {
    struct FadeObj *s1;
    struct FadeObj *s2;
    s8 posByte;
    s32 s0;
    s32 a1;
    s16 a0;
    u8 v0;
    s32 colorByte;
    register s32 mulTmp asm("v0");
    u16 f44tmp;
    register u16 f46tmp asm("s0");

    if (func_80039F1C() == 0) {
        if (arg0->f40 != 0) {
            s1 = arg0->f0;
            s1->f60 = 0;
        } else {
            posByte = arg0->f30;
            s0 = posByte - 0x41;
            s1 = func_800400AC(func_8004002C(), 1);
            func_80040510(s1, arg0->f34, arg0->f36, 0x30, 0x30, 0, 0, 0xE, 0x380, 0xF0);
            a1 = s0;
            s1->f40 = (u16) (s1->f40 + ((s0 >> 4) << 6));
            s1->f5C = (u8) ((s0 % 5) * 0x30);
            s1->f5D = (u8) ((s0 / 5) * 0x30);
            if (s0 < 0) {
                a1 = posByte - 0x32;
            }
            s1->f46 = 0;
            s1->fC.w = 0;
            s1->f42 = (u16) (s1->f42 + (s0 - ((a1 >> 4) * 0x10)));
            s1->f4 = s1->f4 | 0x51000000;
            func_80042918(s1);
            func_800428EC(s1, -8);
            arg0->f0 = s1;
            s1->f60 = 0x14;
        }

        s1->f4A = 0;
        s1->f4 = (s1->f4 | 0x50000000) & 0xF7FFFFFF;

        s2 = func_800400AC(func_8004002C(), 1);
        func_80040510(s2, s1->f30, s1->f32, 0x30, 0x30, (s32) s1->f5C, (s32) s1->f5D, 0xE, 0x200, 0xFD);
        s2->f4 = (s2->f4 | 0x61000000) & 0xF7FFFFFF;
        asm volatile("" ::: "memory");
        s2->f46 = s1->f46;
        s2->f4A = 0;
        func_80042918(s2);
        func_800428EC(s2, -9);
        arg0->f4 = s2;
    }

    s1 = arg0->f0;
    s2 = arg0->f4;

    if (arg0->f40 != 0) {
        s1->f60 = (s16) (s1->f60 + D_8009B0D8);
    } else {
        s1->f60 = (s16) (s1->f60 - D_8009B0D8);
    }

    a0 = s1->f60;
    if (a0 <= 0) {
        s32 mask = 0x8FFFFFFF;
        s1->fC.w = 0x808080;
        s1->f46 = 0x1000;
        s1->f4 = (s1->f4 & mask) | 0x08000000;
        func_8004036C(s2);
        arg0->f4 = 0;
        goto clear33;
    }

    if (a0 < 0x14) {
        goto fade;
    }

    func_80039FD4(arg0);

clear33:
    arg0->f33 = 0;
    goto end;

fade:
    v0 = (u8) (-0x80 - (a0 * 6));
    s2->fC.b.b2 = v0;
    s2->fC.b.b1 = v0;
    s2->fC.b.b0 = v0;
    s1->fC.b.b2 = v0;
    s1->fC.b.b1 = v0;
    s1->fC.b.b0 = v0;

    mulTmp = s1->f60 * 0xCC;
    f46tmp = (u16) (mulTmp + 0x1000);
    s2->f46 = f46tmp;
    colorByte = s1->fC.b.b0;
    s1->f46 = f46tmp;
    f44tmp = (u16) (colorByte << 5);
    s2->f44 = f44tmp;
    s1->f44 = f44tmp;

end:
    return;
}
