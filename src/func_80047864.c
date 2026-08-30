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

/* Sets D_8009B45C's voice-mask field to 1<<(20+voice), mode to 3, and
   computes both channel volumes as (raw_vol * scale) >> 8 before handing
   the struct off to func_80077450. */

struct S8009B45C {
    char pad[0x3C4];
    s32 f3C4;
    s32 f3C8;
    u16 f3CC;
    u16 f3CE;
};

extern struct S8009B45C *D_8009B45C;
extern void func_80077450(void *a0);

void func_80047864(s32 voice) {
    register s32 mask asm("v1");
    struct S8009B45C *a0;
    u8 *v1;
    u8 *a2;
    u16 volL, volR;
    u8 scale;

    mask = 0x100000;
    if (voice != 0) {
        mask <<= voice;
    }

    a0 = D_8009B45C;
    a0->f3C4 = mask;

    v1 = (u8 *)a0 + voice * 2;
    a2 = (u8 *)a0 + voice;
    a0->f3C8 = 3;

    volL = *(u16 *)(v1 + 0x414);
    scale = a2[0x424];
    a0->f3CC = (u32)(volL * scale) >> 8;

    volR = *(u16 *)(v1 + 0x41C);
    scale = a2[0x424];
    a0->f3CE = (u32)(volR * scale) >> 8;

    func_80077450(&a0->f3C4);
}
