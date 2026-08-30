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

/* Same *D_8009B45C struct as func_800490F0.c/func_8004544C.c.
   If the 0x157E slot is active, notifies func_80049C40() (and clears the
   0x80 flag bit) if that flag was set, resets the slot via
   func_80049CB0(), and marks it inactive. Separately, if the
   0x157A counter has run out, clears it via func_800498F8()
   and resets 0x157A/0x1578. Always zeroes 0x1586/0x1588. */

struct S8009B45C {
    char pad0[0x40];
    u16 f40;
    char pad1[0x1578 - 0x42];
    s16 f1578;
    s16 f157A;
    char pad2[0x157E - 0x157C];
    s16 f157E;
    char pad3[0x1586 - 0x1580];
    s16 f1586;
    s16 f1588;
};

extern struct S8009B45C *D_8009B45C;
extern void func_800498F8(s32 a0);
extern void func_80049C40(s16 a0);
extern void func_80049CB0(s16 a0);

void func_80049010(void) {
    if (D_8009B45C->f157E != -1) {
        if (D_8009B45C->f40 & 0x80) {
            func_80049C40(D_8009B45C->f157E);
            D_8009B45C->f40 = D_8009B45C->f40 & 0xFF7F;
        }
        func_80049CB0(D_8009B45C->f157E);
        D_8009B45C->f157E = -1;
    }

    if (D_8009B45C->f157A == 0) {
        func_800498F8(0);
        D_8009B45C->f157A = -1;
        D_8009B45C->f1578 = -1;
    }

    D_8009B45C->f1588 = 0;
    D_8009B45C->f1586 = 0;
}
