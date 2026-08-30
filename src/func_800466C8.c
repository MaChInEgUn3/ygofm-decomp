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

/* D_8009B45C teardown (see func_8004703C.c / func_8004503C.c /
   func_800490F0.c for the sibling field accessors this struct
   shares): if (p->f40 & 0x80) { p->f1588 = 8; p->f1584 = 0xFF; } p->f49 = 0;
   p->f512 = -0x40; p->f40 &= ~4;

   Target loads the global pointer three times: once up front, a SECOND
   time only on the if-taken path (right after the f1588/f1584 writes --
   the skip path reuses the original untouched), and a THIRD time into a
   completely different register for the final f40 func_800738F0-modify-func_80073900.
   Reproduced via two register-pinned aliases matching target's exact
   $v1/$a0 split, each loaded fresh from its own extern reference. */
typedef struct {
    u8 pad0[0x40];
    u16 f40;
    u8 pad42[0x49 - 0x42];
    u8 f49;
    u8 pad4A[0x512 - 0x4A];
    s16 f512;
    u8 pad514[0x1584 - 0x514];
    u8 f1584;
    u8 pad1585[0x1588 - 0x1585];
    u16 f1588;
} S8009B45C;

extern S8009B45C *D_8009B45C;
extern S8009B45C *D_8009B45C;

void func_800466C8(void) {
    register S8009B45C *v1 asm("v1") = D_8009B45C;

    if (v1->f40 & 0x80) {
        v1->f1588 = 8;
        v1->f1584 = 0xFF;
        v1 = D_8009B45C;
    }
    v1->f49 = 0;
    {
        register S8009B45C *a0 asm("a0") = D_8009B45C;
        v1->f512 = -0x40;
        a0->f40 &= ~4;
    }
}
