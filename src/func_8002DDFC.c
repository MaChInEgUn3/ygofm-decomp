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

/* Twelfth member of the obj-mode-dispatch family.  Distinctive: no arm needs
   the object after a call, so gcc keeps it in caller-saved $a2 and the frame
   holds only $ra; case1's f46=1 comes free out of the mode register; and
   case2 does the rect + func_80081DE8 and nothing else -- no D_8009B0F4 work,
   no shared tail at all.  0x0800B7C7 is `j .L8002DF1C`, this function's own
   epilogue, not a call. */

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
    char pad3[0x38 - 0x34];
    s32 f38;
    char pad4[0x46 - 0x3C];
    u8 f46;
};

extern volatile u32 D_8009B0F4;
extern s32 D_8009B118;
extern void func_80081DE8(struct Obj *rect, s32 *data);

void func_8002DDFC(struct Obj *obj, s32 mode) {
    switch (mode) {
    case 0:
        obj->f32 = 0x100;
        obj->f30 = 0;
        obj->w = 0x40;
        obj->h = 0x10;
        D_8009B0F4 &= 0xFFDDFFFF;
        D_8009B0F4 |= 0x10000;
        obj->f46 = 2;
        obj->f1C = obj->f38 << 11;
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
        obj->x = 0;
        obj->y = 0xF0;
        obj->w = 0x100;
        obj->h = 4;
        func_80081DE8(obj, (s32 *)D_8009B118);
        break;
    }
}
