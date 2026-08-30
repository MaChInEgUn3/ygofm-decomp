/* PORTED from Unchiga's decompilation of SLUS_014.11, shared 2026-08-30.
 * His C, his comments; the identifiers are rewritten to this repo's address
 * form and nothing else was touched. Verified the only way that counts here:
 * tools_src/build.py rebuilds the retail image byte-for-byte with this in it.
 *
 * Self-contained by design -- it keeps his declarations rather than ours,
 * because a declaration is a codegen input and his are what this C matched
 * under. See docs/MERGE_UNCHIGA.md and tools_src/install_ported.py.
 */
//@ target 49934 8C
//@ sym D_800F2C40=0x800F2C40
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef short s16;
typedef int s32;

// Per-index (stride 0xE20) table; this function seeds 3 records of
// {s32,s32,s32,u8,u8,u8} at +0xD70/+0xD80/+0xD90 -- looks like X/Y/Z offsets
// plus an intensity-byte triple for a 3-point light/particle rig.
struct Entry {
    char pad0[0xE20];
};

extern struct Entry D_800F2C40[];

void func_80059134(s32 a0) {
    u8 *base = (u8 *)&D_800F2C40[a0];

    *(s32 *)(base + 0xD70) = 3000;
    *(s32 *)(base + 0xD74) = 5000;
    *(s32 *)(base + 0xD78) = 2000;
    *(base + 0xD7C) = 128;
    *(base + 0xD7D) = 128;
    *(base + 0xD7E) = 128;

    *(s32 *)(base + 0xD80) = -3000;
    *(s32 *)(base + 0xD84) = 5000;
    *(s32 *)(base + 0xD88) = -2000;
    *(base + 0xD8C) = 128;
    *(base + 0xD8D) = 128;
    *(base + 0xD8E) = 128;

    *(s32 *)(base + 0xD90) = 0;
    *(s32 *)(base + 0xD94) = -5000;
    *(s32 *)(base + 0xD98) = 0;
    *(base + 0xD9C) = 64;
    *(base + 0xD9D) = 64;
    *(base + 0xD9E) = 64;
}
