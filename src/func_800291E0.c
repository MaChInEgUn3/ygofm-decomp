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

/* Same D_800EFE48-pooled display-object family as func_80019564.c
   / func_8003B054.c (func_800400AC / func_80040510 /
   func_800404CC / func_80042918 /
   func_800428EC all reused from those). Only the fields this
   function actually touches are named; f30/f32 and f3C/f3E are adjacent
   u16 pairs that get bulk-initialized together via one 32-bit store and
   later individually overwritten, hence the unions. f5E/f5F are likewise
   an adjacent u8 pair set together once via a single u16 store. */
union U32Pair {
    u32 w;
    struct { u16 lo, hi; } h;
};

union U16Pair {
    u16 w;
    struct { u8 lo, hi; } h;
};

struct Obj {
    char pad4[0x4];
    u32 f4;                    /* flags */
    u16 f8;
    char pad10[0x10 - 0xA];
    void *f10;                 /* callback fn pointer (2nd obj only) */
    char pad18[0x18 - 0x14];
    u16 f18;
    u16 f1A;
    char pad30[0x30 - 0x1C];
    union U32Pair u30;         /* lo=f30, hi=f32 */
    char pad3C[0x3C - 0x34];
    union U32Pair u3C;         /* lo=f3C, hi=f3E */
    char pad48[0x48 - 0x40];
    u16 f48;
    u16 f4A;
    void *f4C;                 /* callback fn pointer (1st obj only) */
    char pad54[0x54 - 0x50];
    struct Obj *f54;           /* cross-ref: 1st obj -> 2nd obj */
    char pad5E[0x5E - 0x58];
    union U16Pair u5E;         /* lo=f5E, hi=f5F */
    char pad65[0x65 - 0x60];
    u8 f65;
    char pad67[0x67 - 0x66];
    u8 f67;                    /* copy of the container index (arg0) */
    u8 f68;                    /* dispatch code (0-0x1F) */
    char pad6A[0x6A - 0x69];
    u8 f6A;                    /* dispatch code, 2nd obj */
};

/* One D_800EA0E8 container-array entry (stride 0x40). Same array as
   clear_entry_fields_800ea0e8.c, but this function needs its position and
   pooled-object-pointer fields instead. */
struct Entry {
    struct Obj *f0;             /* primary pooled object (2nd obj) */
    struct Obj *f4;              /* secondary pooled object (1st obj) */
    char pad28[0x28 - 0x8];
    u16 f28;
    u16 f2A;
    s16 f2C;
    s16 f2E;
    s16 f30;                      /* 1-based index into D_801D4244 */
    s16 f32;                       /* x */
    s16 f34;                        /* y */
    s16 f36;
    s16 f38;
    u8 f3A;
    u8 f3B;
    u8 f3C;
    char pad40[0x40 - 0x3D];
};

extern s32 func_8004002C(void);
extern struct Obj *func_800400AC(s32 a0, s32 a1);
extern void func_80040510(struct Obj *a0, s32 a1, s32 a2, s32 a3, s32 a5, s32 a6, s32 a7, s32 a8, s32 a9, s32 a10);
extern void func_800404CC(struct Obj *a0, s32 a1, s32 a2, s32 a3, s32 a5, s32 a6, s32 a7, s32 a8);
extern void func_80042918(struct Obj *a0);
extern void func_800428EC(struct Obj *a0, s32 a1);
extern void func_80028B08(void);
extern void func_80029108(void);
extern struct Entry D_800EA0E8[];
extern s32 D_801D4244[];
extern u8 D_801D5332[];

/* Initializes D_800EA0E8[arg0]: allocates a first pooled object (type 6)
   and looks up a 5-bit dispatch code from D_801D4244[entry->f30 - 1] (bits
   26-30). Four special dispatch codes (0x14-0x17) skip straight to the
   shared tail with a small preset state (s3/s0); every other code falls
   into the "default" path, which does more field setup on the first
   object and derives the entry's x/y (f32/f34) either from arg1/arg2
   directly or, when negative, from two more bit-slices of the same
   D_801D4244 table entry (bits 0-8 and 9-17). The shared tail then reads
   a nibble pair from D_801D5332[entry->f30], stashes a callback pointer
   (func_80028B08) on the first object, registers it, allocates a second
   pooled object (type 2) via the func_800404CC init call,
   sets its own callback pointer (func_80029108), registers it, and
   cross-links both objects into the entry (entry->f0 = 2nd obj,
   entry->f4 = 1st obj, 1st->f54 = 2nd obj). arg1 is a dead parameter: it
   is only ever copied into the local dispatch-state variable, which every
   code path overwrites before it is func_800738F0. */
void func_800291E0(s32 arg0, s32 arg1, s32 arg2) {
    struct Entry *s2;
    struct Obj *s1;
    s32 s0;
    s32 s3;
    s32 a0;
    u8 v0;

    s3 = arg1; /* dead: overwritten on every path before use */
    s2 = &D_800EA0E8[arg0];

    s1 = func_800400AC(func_8004002C(), 6);
    func_80040510(s1, 0, 0, 0x66, 0x60, 0, 0,
        ((s16) s2->f28 >> 6) + (((s16) s2->f2A >> 8) << 4),
        s2->f2C, s2->f2E);

    s1->u30.w = 0x001F0048;
    s1->u3C.w = 0x00100038;
    s1->u5E.w = 0x9E00;
    s1->f4 |= 0x01000000;

    a0 = s2->f30;
    s0 = (D_801D4244[a0 - 1] >> 26) & 0x1F;
    s1->f67 = arg0;
    s1->f68 = (u8) s0;

    if (s0 == 0x15) {
        goto disp_15;
    }
    if (s0 >= 0x16) {
        goto disp_ge16;
    }
    if (s0 == 0x14) {
        goto disp_14;
    }
    s1->u30.h.lo = 0x48;
    goto path_a;

disp_ge16:
    if (s0 == 0x16) {
        goto disp_16;
    }
    if (s0 == 0x17) {
        goto disp_17;
    }
    s1->u30.h.lo = 0x48;
    goto path_a;

disp_16:
    s3 = 0x103;
    s0 = 1;
    goto shared_tail;

disp_17:
    v0 = s1->u5E.h.hi;
    v0 = (u8) (v0 + 0x20);
    s1->u5E.h.hi = v0;
    /* fallthrough */
disp_14:
    s3 = 0x101;
    s0 = 1;
    goto shared_tail;

disp_15:
    s3 = 0x102;
    v0 = s1->u5E.h.hi;
    s0 = 1;
    v0 = (u8) (v0 + 0x10);
    s1->u5E.h.hi = v0;
    goto shared_tail;

path_a:
    s1->u30.h.hi = 0x9E;
    s1->u5E.h.hi = 0xCE;
    s1->u3C.h.lo = 0x18;
    s1->u3C.h.hi = 0xC;

    {
        s16 c3 = s3;
        s2->f32 = c3;
        if (c3 < 0) {
            s2->f32 = (s16) ((D_801D4244[a0 - 1] & 0x1FF) * 10);
        }
    }
    {
        s16 c4 = arg2;
        s2->f34 = c4;
        if (c4 < 0) {
            s2->f34 = (s16) (((D_801D4244[a0 - 1] >> 9) & 0x1FF) * 10);
        }
    }
    s3 = 0x100;
    s0 = 0;
    s2->f38 = 0;
    s2->f36 = 0;

shared_tail:
    s2->f3B = (u8) (D_801D5332[a0] >> 4);
    s2->f3A = (u8) (D_801D5332[a0] & 0xF);
    s2->f3C = 0;

    s1->f4C = (void *) func_80028B08;
    func_80042918(s1);

    s2->f4 = s1;

    s1 = func_800400AC(func_8004002C(), 2);
    func_800404CC(s1, 2, 4, 1, 0, s0, 0x1C, s3 + 8);

    s1->f18 = 0x46;
    s1->f48 = 0x46;
    s1->f1A = 0x62;
    s1->f4A = 0x62;
    s1->f6A = (u8) s0;
    s1->f4 |= 0x01000000;
    s1->f8 |= 8;

    func_80042918(s1);
    func_800428EC(s1, -1);

    s2->f4->f65 = 3;
    s1->f65 = 3;
    s1->f10 = (void *) func_80029108;
    asm volatile("" ::: "memory");

    {
        struct Obj *firstObj = s2->f4;
        struct Obj *tmp;
        asm volatile("" ::: "memory");
        tmp = s1;
        asm volatile("" : "+r"(tmp));
        s2->f0 = tmp;
        firstObj->f54 = tmp;
    }
}
