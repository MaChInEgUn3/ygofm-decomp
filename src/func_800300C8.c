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

struct Src {
    char pad[0x3C];
    s16 f3C;    /* base position */
    s16 f3E;    /* spacing (halved into layout) */
    u16 f40;    /* row base offset */
};

struct Dst {
    char pad[0x28];
    s16 f28;
    s16 f2A;
    char pad2[0x30 - 0x2C];
    s16 f30;
    s16 f32;
    char pad3[0x38 - 0x34];
    s16 f38;
    s16 f3A;
    char pad4[0x40 - 0x3C];
    s16 f40;
    s16 f42;
};

extern struct Src D_800EB15C;
extern struct Dst *D_8009B2E4;
extern s8 D_8009B2F1;

/* Lays out three column positions (each duplicated into two Dst fields, one
   pair 0x10 apart) from D_800EB15C's base/spacing/row values and the
   D_8009B2F1 item index: column 1 is the base position, nudged by half the
   spacing once the index reaches double digits; column 2 is column 1 plus
   another half-spacing; column 3 is the row base offset plus 16 times the
   index's ones digit (and its own +0x10 twin). */
void func_800300C8(void) {
    struct Src *src = &D_800EB15C;
    s32 pos1 = src->f3C;
    struct Dst *dst = D_8009B2E4;
    s32 idx = D_8009B2F1;
    s32 pos2;
    s32 pos3;

    if (idx >= 10) {
        register s32 v0reg asm("v0") = (s32)((u32)(u16)src->f3E << 16);
        register s32 v1reg asm("v1") = v0reg >> 16;
        v0reg = (s32)((u32)v0reg >> 31);
        v1reg = v1reg + v0reg;
        v1reg = v1reg >> 1;
        pos1 = pos1 - 0x10;
        pos1 = pos1 + v1reg;
    }
    dst->f38 = pos1;
    dst->f28 = pos1;

    pos2 = pos1 + src->f3E / 2 - 0x10;
    dst->f40 = pos2;
    dst->f30 = pos2;

    {
        s32 q = idx / 10;
        s8 rem = (s8)(idx - q * 10);
        pos3 = src->f40 + rem * 16;
    }
    dst->f32 = pos3;
    dst->f2A = pos3;
    pos3 = pos3 + 0x10;
    dst->f42 = pos3;
    dst->f3A = pos3;
}
