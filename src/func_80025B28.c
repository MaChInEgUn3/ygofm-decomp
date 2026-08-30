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

/* Same D_801A7AD8[] stat table (0x1C-byte stride) as
   table801a7ad8_row_search.c / func_8001EFD4.c. Advances a1->f22 by 8 every
   call; the first time it crosses 0x28 (and f6C's 0x80 "already advanced"
   bit isn't set yet), latches that bit, clears the table row's 0x2000 flag
   bit, and clears f67. Then, as long as the (just-advanced) f22 is still
   below 0x40, resets f22/f6C/f24 back to 0, clears the table row's 0x3400
   flag bits, and hands the object to func_80018080 -- i.e. func_80018080
   only fires while f22 hasn't yet climbed past 0x40 in a single +8 step. */
struct Table801A7AD8 {
    char pad0[0x16];
    u16 flags;                 /* 0x16 */
    char pad1[0x1C - 0x18];
};

struct Obj {
    char pad0[0x22];
    u8 f22;                    /* 0x22 */
    char pad1[0x24 - 0x23];
    s32 f24;                   /* 0x24 */
    char pad2[0x67 - 0x28];
    u8 f67;                    /* 0x67 */
    char pad3[0x6A - 0x68];
    u8 f6A;                    /* 0x6A */
    char pad4[0x6C - 0x6B];
    u8 f6C;                    /* 0x6C */
};

extern struct Table801A7AD8 D_801A7AD8[];
extern void func_80018080(struct Obj *a0);

void func_80025B28(struct Obj *a1) {
    register u8 orig asm("v0");
    register u8 newF22 asm("v1");
    u8 cmp;
    u8 flags;

    flags = a1->f6C;
    orig = a1->f22;
    newF22 = orig + 8;
    a1->f22 = newF22;
    cmp = newF22;
    if (!(flags & 0x80)) {
        if (cmp >= 0x28) {
            a1->f6C = flags | 0x80;
            D_801A7AD8[a1->f6A].flags &= 0xDFFF;
            a1->f67 = 0;
        }
    }
    if (a1->f22 < 0x40) {
        a1->f22 = 0;
        a1->f6C = 0;
        a1->f24 = 0;
        D_801A7AD8[a1->f6A].flags &= 0xCBFF;
        func_80018080(a1);
    }
}
