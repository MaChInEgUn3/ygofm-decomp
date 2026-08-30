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

/* Fourth and last member of the 4-way mode-dispatch family (func_80032184,
   func_8003BD14, func_8002FB78, this).  Two nested shared tails here:
   .L8003C28C (f1C store + the D_8009B0F4 mask) is shared by case2 and case3,
   and .L8003C29C (f46 = 1) by case1, case2 and case3.  Both are written out
   in full per arm and left to gcc's cross-jump pass, as in the siblings.

   m2c mis-decodes all three internal jumps as calls: 0x0800F0A8 = j to this
   function's own epilogue .L8003C2A0, 0x0800F0A7 = j .L8003C29C,
   0x0800F0A3 = j .L8003C28C.  0x2442F000 is addiu v0,v0,%lo(D_801AF000). */

struct Obj {
    s16 x;
    s16 y;
    s16 w;
    s16 h;
    s32 f8;
    s32 fC;
    char pad1[0x1C - 0x10];
    s32 f1C;
    char pad2[0x30 - 0x20];
    s16 f30;
    s16 f32;
    char pad3[0x46 - 0x34];
    u8 f46;
};

extern volatile u32 D_8009B0F4;
extern s32 D_8009B118;
extern u8 D_801AF000[];
extern void func_80081DE8(struct Obj *rect, s32 *data);

void func_8003C120(struct Obj *obj, s32 mode) {
    switch (mode) {
    case 0:
        obj->f32 = 0x100;
        obj->f30 = 0;
        obj->w = 0x40;
        obj->h = 0x10;
        D_8009B0F4 &= 0xFFDDFFFF;
        obj->f1C = 0x10000;
        D_8009B0F4 |= 0x10000;
        obj->f46 = 2;
        obj->f8 = D_8009B118;
        obj->fC = D_8009B118 + 0x800;
        break;

    case 1:
        obj->f1C = 0x800;
        D_8009B0F4 &= 0xFFDCFFFF;
        obj->fC = D_8009B118;
        obj->f8 = D_8009B118;
        obj->f46 = 1;
        break;

    case 2:
        obj->x = 0x100;
        obj->y = 0xF0;
        obj->w = 0x100;
        obj->h = 4;
        func_80081DE8(obj, (s32 *)D_8009B118);
        obj->fC = (s32)D_801AF000;
        obj->f8 = (s32)D_801AF000;
        obj->f1C = 0x800;
        D_8009B0F4 &= 0xFFDCFFFF;
        obj->f46 = 1;
        break;

    case 3:
        obj->fC = 0x80140000;
        obj->f8 = 0x80140000;
        obj->f1C = 0x8000;
        D_8009B0F4 &= 0xFFDCFFFF;
        obj->f46 = 1;
        break;
    }
}
