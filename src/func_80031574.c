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

/* Creates a slot-0x10..0x60 object (func_8004002C +
   func_800400AC(..., 1)), configures it via func_80040510,
   then looks up a 5-bit field packed into D_801D4244[idx-1] (bits 26-30)
   and, for values 0x14/0x17/0x15/0x16, bumps the object's f40 counter by
   0x10/0x10/0x20/0x30 respectively (any other value leaves f40 untouched).
   Finally calls func_80042918(obj) and func_800428EC(obj, 10),
   resets f44, stores the a3/a4 params into f18/f1A, points the f24
   callback at func_800313E8, and clears f8's 0x8 bit and f4's 0x08000000
   bit. */

struct Obj {
    char pad0[0x4];
    u32 f4;
    u16 f8;
    char pad2[0x18 - 0xA];
    s16 f18;
    s16 f1A;
    char pad3[0x24 - 0x1C];
    s32 f24;
    char pad4[0x40 - 0x28];
    u16 f40;
    char pad5[0x44 - 0x42];
    s32 f44;
};

extern s32 D_801D4244[];
extern void func_800313E8(void);

extern s32 func_8004002C(void);
extern struct Obj *func_800400AC(s32 slot, s32 kind);
extern void func_80040510(struct Obj *obj, s32 a1, s32 a2, s32 a3, s32 a5,
                           s32 a6, s32 a7, s32 a8, s32 a9, s32 a10);
extern void func_80042918(struct Obj *obj);
extern void func_800428EC(struct Obj *obj, s32 a1);

void func_80031574(s32 idx, s32 a1, s32 a2, s16 a3, s32 a4) {
    struct Obj *obj;
    s32 field;

    obj = func_800400AC(func_8004002C(), 1);
    func_80040510(obj, a1, a2, 0x10, 0x10, 0, 0xC8, 0xB, 0x260, 0xFC);

    field = (D_801D4244[idx - 1] >> 26) & 0x1F;
    switch (field) {
        case 0x14:
        case 0x17:
            obj->f40 = (u16) (obj->f40 + 0x10);
            break;
        case 0x15:
            obj->f40 = (u16) (obj->f40 + 0x20);
            break;
        case 0x16:
            obj->f40 = (u16) (obj->f40 + 0x30);
            break;
    }

    func_80042918(obj);
    func_800428EC(obj, 0xA);
    {
        s32 mask = 0xF7FFFFFF;
        register struct Obj *p asm("v0") = obj;
        p->f44 = 0;
        p->f18 = a3;
        p->f1A = (s16) a4;
        p->f24 = (s32) func_800313E8;
        p->f8 &= 0xFFF7;
        p->f4 &= mask;
    }
}
