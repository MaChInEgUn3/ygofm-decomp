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

/* Object-init function. Stores each of 10 parameters (ptr + 9 scalar
   args, the first 3 in registers and the remaining 6 on the stack) into
   a distinct field of *ptr. Two of them (a3 and p4, the first stack
   arg) are additionally halved via the standard signed-div-by-2 idiom
   ((x + ((u32)x >> 31)) >> 1, i.e. plain C `x / 2` for a signed x) and
   stored a second time at a duplicate offset. Also sets flag bit 0x8 in
   the field at 0x8. */
typedef struct {
    char pad_0[0x8];
    u16 f8;   /* 0x8  -- flags |= 8 */
    char pad_A[0xE];
    s16 f18;  /* 0x18 -- a3 / 2 */
    s16 f1A;  /* 0x1A -- p4 / 2 */
    char pad_1C[0x14];
    s16 f30;  /* 0x30 -- a1 */
    s16 f32;  /* 0x32 -- a2 */
    char pad_34[0x8];
    s16 f3C;  /* 0x3C -- a3 */
    s16 f3E;  /* 0x3E -- p4 */
    s16 f40;  /* 0x40 -- p8 */
    s16 f42;  /* 0x42 -- p9 */
    char pad_44[0x4];
    s16 f48;  /* 0x48 -- a3 / 2 (dup of f18) */
    s16 f4A;  /* 0x4A -- p4 / 2 (dup of f1A) */
    char pad_4C[0x10];
    u8 f5C;   /* 0x5C -- p5 */
    u8 f5D;   /* 0x5D -- p6 */
    char pad_5E[0x8];
    u8 f66;   /* 0x66 -- p7 */
} Obj;

/* the object pointer is pinned to $v0: the ROM copies a0 into v0 as its
   very first instruction, which frees $a0 to be reloaded a few
   instructions later for the first stack argument (p4). An ordinary
   local alias for the pointer gets optimized back into keeping it in
   a0 the whole function (no register pressure forces the move); pinning
   it manufactures that pressure and reproduces the ROM's allocation. */
void func_80040510(Obj *a0, s32 a1, s32 a2, s32 a3, s32 p4, s32 p5, s32 p6,
                    s32 p7, s32 p8, s32 p9) {
    register Obj *o asm("v0") = a0;
    s32 half3;
    s32 p4v = p4;
    s32 half4;

    o->f3C = a3;
    half3 = a3 / 2;
    o->f30 = a1;
    o->f32 = a2;
    o->f18 = half3;
    o->f48 = half3;

    o->f8 |= 8;

    o->f3E = p4v;
    half4 = p4v / 2;
    o->f5C = (u8)p5;
    o->f5D = (u8)p6;
    o->f66 = (u8)p7;
    o->f40 = p8;
    o->f42 = p9;
    o->f1A = half4;
    o->f4A = half4;
}
