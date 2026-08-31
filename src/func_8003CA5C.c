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

/* Adapted from MaChInEgUn3's peer decomp candidate. This source is queued
   for license-gated integration; see work/peer_repo/README.md. */
extern u8 *D_8009B378;
extern u8 D_800E9ECE[];
extern u16 D_8009B398[];
extern void func_80042A00(void *);
extern void func_800429D8(void *);
extern void func_80040410(u8 *, s32);
extern s32 func_800358FC(s32);

s32 func_8003CA5C(void) {
    u8 *p;
    s16 w;
    register u32 tailBits asm("v1");

    p = (u8 *)D_8009B378;
    func_80042A00(p);
    w = *(s16 *)(p + 0x5A);
    if (w == 0) {
        switch (p[0x6C]) {
        case 0:
            func_80040410(p, 1);
            p[0x6C] = 1;
            *(s16 *)(p + 0x36) = -0xC0;
            break;
        case 1:
            func_800429D8(p);
            func_80040410(p, 2);
            p[0x6C] = 2;
            break;
        case 2:
            func_80040410(p, 0);
            p[0x6C] = 0;
            if (*(s16 *)(p + 0x30) < -0x2F) {
                *(s16 *)(p + 0x30) = 0x160;
                *(s16 *)(p + 0x32) = func_800358FC(0xB0) + 0x30;
            }
            break;
        }
    }
    if (D_800E9ECE[0] & 0x80) {
        return 1;
    }

    /* Keep the address high half and loaded value in one destructive
       lifetime, matching retail's lui/lhu pair in v1. */
    tailBits = 0x800A0000;
    asm volatile("" : "+r"(tailBits));
    tailBits = *(u16 *)(tailBits - 0x4C68);
    if (tailBits & 0xE0) {
        if (D_8009B378 != 0) {
            return 0;
        } else {
            return 0;
        }
    }
    return 1;
}
