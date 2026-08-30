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

/* Appends one 8-byte record to a ring buffer: D_8009B310 is the func_80073900 cursor,
   D_8009B314 the running record count.

   Given a displacement (dx, dy, dz), stores the xz-plane distance in f2 and
   packs the xz bearing into f0's high byte with dy>>4 in the low byte.  The
   bearing is func_800899A0's full-circle value scaled down by 16 and clamped to a
   single byte; dy is only shifted, not clamped.  f6 is always zeroed. */

struct Rec {
    s16 f0;     /* (clamped bearing << 8) | (dy >> 4) */
    s16 f2;     /* xz-plane distance */
    s16 f4;     /* record index at insert time */
    s16 f6;     /* always 0 */
};

extern struct Rec *D_8009B310;
extern u32 D_8009B314;
extern s32 func_80086E50(s32 v);
extern s32 func_800899A0(s32 y, s32 x);

void func_80033CF8(s32 dx, s32 dy, s32 dz) {
    struct Rec *p;
    s32 q;
    s32 v;

    D_8009B310->f2 = func_80086E50(dx * dx + dz * dz);
    q = func_800899A0(dx, dz) / 16;
    if (q >= 256) {
        q = 255;
    }
    v = q << 8;

    p = D_8009B310;
    p->f0 = v | (dy >> 4);
    p->f4 = D_8009B314;
    p->f6 = 0;

    D_8009B310 = p + 1;
    D_8009B314 = D_8009B314 + 1;
}
