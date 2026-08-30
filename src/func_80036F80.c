/* PORTED from Unchiga's decompilation of SLUS_014.11, shared 2026-08-30.
 * His C, his comments; the identifiers are rewritten to this repo's address
 * form and nothing else was touched. Verified the only way that counts here:
 * tools_src/build.py rebuilds the retail image byte-for-byte with this in it.
 *
 * Self-contained by design -- it keeps his declarations rather than ours,
 * because a declaration is a codegen input and his are what this C matched
 * under. See docs/MERGE_UNCHIGA.md and tools_src/install_ported.py.
 */
//@ target 27780 8C
//@ sym D_8009B336=0x8009B336
//@ sym D_8009B34D=0x8009B34D
//@ sym func_80036DBC=0x80036DBC
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef short s16;
typedef int s32;

// obj->sub fields touched here are timing/rate parameters for some
// battle-mode-dependent effect; 0xC0C0 is used in "special" mode, 0xC0
// otherwise, and values >= 0x8000 (i.e. the packed value func_800738F0 back as
// negative) get a +3 correction before being divided down by 4.
struct Sub {
    char pad0[0xC];
    s32 fC;
    char pad1[0x2C - 0x10];
    s32 f2C;
    char pad2[0x34 - 0x30];
    s32 f34;
    char pad3[0x3C - 0x38];
    s32 f3C;
    char pad4[0x44 - 0x40];
    s32 f44;
    char pad5[0x4C - 0x48];
    s32 f4C;
    char pad6[0x54 - 0x50];
    s32 f54;
};

struct Obj {
    char pad[0x30];
    struct Sub *sub;
};

extern u8 D_8009B336;
extern s8 D_8009B34D;
extern void func_80036DBC(struct Obj *a0);

void func_80036F80(struct Obj *a0) {
    s32 flag = (D_8009B336 >> D_8009B34D) & 1;
    struct Sub *sub0 = a0->sub;
    s32 a1;
    s32 v1;

    if (!flag) {
        a1 = 0xC0;
    } else {
        a1 = 0xC0C0;
    }

    sub0->fC = a1;
    a0->sub->f3C = a1;

    v1 = a1;
    a0->sub->f44 = a1;
    if (a1 < 0) {
        v1 = a1 + 3;
    }

    a1 = v1 >> 2;
    a0->sub->f2C = a1;
    a0->sub->f34 = a1;
    a0->sub->f4C = a1;
    a0->sub->f54 = a1;

    func_80036DBC(a0);
}
