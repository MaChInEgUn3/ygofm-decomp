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

struct Foo {
    s32 field0;
    char pad4[4];
    s32 field8;
    s32 fieldC;
    s32 field10;
};

extern s32 func_8004BBBC(s32 a0);
extern s32 func_8004BC2C(struct Foo *a0);

s32 func_8004C560(struct Foo *a0) {
    s32 r1 = func_8004BBBC(a0->field0);
    a0->field0 = r1;

    if (r1 == -1) {
        return 1;
    }

    {
        a0->field8 = func_8004BC2C(a0);
        a0->field10 = a0->field0;
        a0->fieldC = a0->field0 + a0->field8;
    }
    return 0;
}
