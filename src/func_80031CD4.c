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

/* Element of the array at the front of the a0 object, indexed by
   (a0->f2D3C + a1). */
struct SubEntry {
    char pad0[4];
    u16 f4;                    /* 0x4 */
    char pad1[0xD - 0x6];
    u8 fD;                     /* 0xD */
    char pad2[0x10 - 0xE];
};

struct Obj3 {
    char pad[8];
    u16 f8;                    /* 0x8 */
};

struct Obj2 {
    char pad0[0x28];
    struct Obj3 *f28;          /* 0x28 */
    char pad1[0x34 - 0x2C];
    u16 f34;                   /* 0x34 */
    char pad2[0x3A - 0x36];
    s16 f3A;                   /* 0x3A */
    u16 f3C;                   /* 0x3C */
    char pad3[0x54 - 0x3E];
    u8 f54;                    /* 0x54 */
};

extern u16 D_8009B338;
extern void *func_80035BE4(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5);
extern void func_80039A14(void *a0);

/* Looks up the SubEntry at (a0->f2D3C + a1) and mirrors its f4 field to
   D_8009B338. Allocates an Obj2 via func_80035BE4, tags it
   with a1's slot index (f3A) and clears its f28 object's 0x8 bit, then
   re-reads the SubEntry to copy its high bit into f54. Finally applies a
   couple of a0/a1-derived flags (f3C, f34) before handing the object off
   to func_80039A14. */
void func_80031CD4(void *a0, s32 a1) {
    s16 idx;
    struct SubEntry *e;
    struct Obj2 *obj;
    s32 flag;

    idx = *(s16 *)((u8 *)a0 + 0x2D3C);
    e = (struct SubEntry *)((u8 *)a0 + (idx + a1) * 0x10);
    {
        register u16 val asm("v1") = e->f4;

        asm volatile("" ::: "memory");
        idx = *(s16 *)((u8 *)a0 + 0x2D3C);
        e = (struct SubEntry *)((u8 *)a0 + (idx + a1) * 0x10);
        D_8009B338 = val;
    }
    flag = 0;
    if (e->fD != 0) {
        flag = 6;
    }

    obj = func_80035BE4(*(u8 *)((u8 *)a0 + 0x2D47) + 1, flag, 0x22, 0x2B, 0x120, 0xB0);
    obj->f3A = (s16)(a1 * 22);
    obj->f28->f8 = obj->f28->f8 & 0xFFF7;

    idx = *(s16 *)((u8 *)a0 + 0x2D3C);
    e = (struct SubEntry *)((u8 *)a0 + (idx + a1) * 0x10);
    if (e->fD & 0x80) {
        obj->f54 = 4;
    }

    if (*(u8 *)((u8 *)a0 + 0x2D47) != 0) {
        obj->f3C = obj->f3C + 0x160;
    }

    if (a1 != 0) {
        obj->f34 = obj->f34 | 0x40;
    }

    func_80039A14(obj);
}
