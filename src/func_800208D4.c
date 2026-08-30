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

extern u16 D_8009B23A;
extern u8 D_8009B1D5;
extern u16 D_8009B162;
extern s32 D_8009B1C8;
extern s32 D_8009B22C;
extern void func_80022D94(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4);
extern u8 D_800E9FF0[16];
extern u8 D_800907D8[16];

/* One-shot init guarded by D_8009B23A's 0x8000 bit: kicks off
   func_80022D94 with a duration selected by D_8009B1D5, and arms
   D_8009B162 as a busy-flag. Once that flag clears, toggles D_8009B1D5's
   low bit and recomputes two lookup pointers (D_8009B1C8, D_8009B22C)
   from D_800E9FF0/D_800907D8 indexed by the new value. */
void func_800208D4(void) {
    s32 a0;
    s32 v1;
    s32 v0;
    s32 a3;

    a0 = D_8009B23A;
    if ((a0 & 0x8000) == 0) {
        v1 = D_8009B1D5;
        D_8009B23A = (u16) (a0 | 0x8000);
        if (v1 != 0) {
            a3 = 1024;
        } else {
            a3 = 3072;
        }
        func_80022D94(48, 600, 256, a3, 0);
        D_8009B162 = 16;
    }
    if (D_8009B162 != 0) {
        return;
    }
    v0 = D_8009B1D5;
    v0 = v0 ^ 1;
    D_8009B1D5 = (u8) v0;
    asm volatile("" ::: "memory");
    a0 = v0 & 0xFF;
    v0 = 2;
    v1 = a0 << 5;
    D_8009B23A = (u16) v0;
    v0 = (s32) D_800E9FF0;
    v1 = v1 + v0;
    D_8009B1C8 = v1;
    v0 = a0 << 2;
    v0 = v0 + a0;
    v0 = v0 << 2;
    v1 = (s32) D_800907D8;
    v0 = v0 + v1;
    D_8009B22C = v0;
}
