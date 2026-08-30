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

/* Geometry record: f30/f32 are a center point, f3C/f3E/f4A are extents
   from that center, f18/f1A/f28/f2A/f38/f3A/f40/f42/f48/f50/f52 are the
   derived edge/corner fields written by this function. */
struct Layout {
    char pad18[0x18];
    u16 f18;
    u16 f1A;
    char pad28[0x28 - 0x1C];
    u16 f28;
    u16 f2A;
    char pad30[0x30 - 0x2C];
    u16 f30;
    u16 f32;
    char pad38[0x38 - 0x34];
    u16 f38;
    u16 f3A;
    u16 f3C;
    u16 f3E;
    u16 f40;
    u16 f42;
    char pad48[0x48 - 0x44];
    u16 f48;
    u16 f4A;
    char pad50[0x50 - 0x4C];
    u16 f50;
    u16 f52;
};

struct Outer {
    char pad28[0x28];
    struct Layout *f28; /* source layout */
    struct Layout *f2C; /* destination layout */
};

/* Copies f18/f1A straight across, then derives dst's edge fields from
   src's center (f30/f32) and extents (f3C/f3E/f4A), each with a paired
   "raw" and "+/-8 margin" copy (e.g. f48/f28 = center_x, f38 = center_x-8,
   f50/f30 = center_x+f3C, f40 = center_x+f3C+8). */
void func_80039140(struct Outer *self) {
    struct Layout *src = self->f28;
    struct Layout *dst = self->f2C;
    u16 v;

    dst->f18 = src->f18;
    dst->f1A = src->f1A;

    v = src->f30;
    dst->f48 = v;
    dst->f28 = v;
    dst->f38 = v - 8;

    v = src->f30 + src->f3C;
    dst->f50 = v;
    dst->f30 = v;
    dst->f40 = v + 8;

    v = src->f32 - 8;
    dst->f32 = v;
    dst->f2A = v;

    v = src->f32 + src->f4A;
    dst->f42 = v;
    dst->f3A = v;

    v = src->f32 + src->f3E + 8;
    dst->f52 = v;
    dst->f4A = v;
}
