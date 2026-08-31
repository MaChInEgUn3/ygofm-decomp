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

/* Matched by claude-w1/claude-w2/codex-w5 collaboration. */

extern u8 *D_8009B45C;

extern void func_80044DC0(s32 a0);
extern s32 func_80049F50(void);
extern void func_80049C40(s32 a0);
extern void func_80049CB0(s32 a0);
extern void func_800498F8(s32 a0);
extern void func_80076ED0(s32 a0, s32 a1);

void func_80046DE8(void) {
    register s32 v1649 asm("v1") = D_8009B45C[0x1649];
    register s32 v164A asm("a1") = D_8009B45C[0x164A];
    s16 phase;
    s16 retval;
    s16 v157A;
    s32 i;

    asm volatile("" : "+r" (v1649), "+r" (v164A));
    *(u16 *) (D_8009B45C + 0x42) = v1649;
    *(u16 *) (D_8009B45C + 0x44) = v164A;
    func_80044DC0(0);

    {
        register u8 *p2 asm("v0") = D_8009B45C;
        register s32 phasev asm("v1") = *(s16 *) (p2 + 0x157E);
        *(u16 *) (p2 + 0x512) = 0;
        phase = (s16) phasev;
    }

    if (phase != -1) {
        retval = (s16) func_80049F50();
        if (retval != 1) {
            func_80049C40(*(s16 *) (D_8009B45C + 0x157E));
            *(u16 *) (D_8009B45C + 0x40) &= 0xFF7F;
        }
        func_80049CB0(*(s16 *) (D_8009B45C + 0x157E));
    }

    {
        register s32 neg1 asm("v1") = -1;
        register u8 *p3 asm("v0") = D_8009B45C;
        register s32 v157Av asm("a0") = *(s16 *) (p3 + 0x157A);
        asm volatile("" : "+r" (neg1));
        *(u16 *) (p3 + 0x157C) = neg1;
        *(u16 *) (p3 + 0x157E) = neg1;
        v157A = (s16) v157Av;
    }
    if (v157A != -1) {
        func_800498F8(v157A);
    }

    *(s16 *) (D_8009B45C + 0x1578) = -1;
    *(s16 *) (D_8009B45C + 0x157A) = -1;
    *(s16 *) (D_8009B45C + 0x1588) = 0;
    func_80076ED0(0, 0xFFFFFF);

    D_8009B45C[0x434] = 0;
    D_8009B45C[0x435] = 0;

    for (i = 0; i < 4; i++) {
        *(u8 *) ((u32) D_8009B45C + i + 0x40C) = 0;
        {
            u32 off = i * 2;
            *(u16 *) ((u32) D_8009B45C + off + 0x404) = 0;
        }
    }

    {
        u8 *base1 = D_8009B45C;
        base1[0x7C] = 0;
        {
            u8 *base2 = D_8009B45C;
            *(u16 *) (base1 + 0x4C) = 0;
            base2[0x7D] = 0;
            {
                u8 *base2b = D_8009B45C;
                base2b[0x7E] = 0;
                {
                    register u8 *base3 asm("v1") = D_8009B45C;
                    *(u16 *) (base2b + 0x4E) = 0;
                    *(u32 *) (base2b + 0x50) = 0;
                    *(u32 *) (base2b + 0x54) = 0;
                    *(u32 *) (base2b + 0x58) = 0;
                    *(u16 *) (base3 + 0x40) = 0;
                }
            }
        }
    }
}
