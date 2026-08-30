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

/* Arms a 16.16 interpolation from the current camera/reference record at
   D_800F2848 toward a caller-supplied target, over arg0 steps.

   For each of the four tracked components -- f0, f4, f2 and the 32-bit
   field at 0x24 -- it stores
     * the raw target value (D_8009B204/B1EE/B192/B190, plus arg4 into
       D_8009B166),
     * the reference value as a 0x8000-biased 16.16 accumulator seed
       (D_8009B1C4/B15C/B158/B224), i.e. (ref << 16) | 0x8000, and
     * the per-step delta ((target - ref) << 16) / arg0
       (D_8009B1FC/B198/B194/B168).

   NOTE FOR ANY FUTURE EDIT -- `base->f24` MUST STAY A STRUCT MEMBER
   REFERENCE.  Spelling it `*(s32 *)((char *)base + 0x24)` is byte-for-byte
   the same load, but the cast is not a COMPONENT_REF so gcc leaves
   MEM_IN_STRUCT_P clear on the MEM.  sched.c's anti_dependence() only
   disambiguates a pointer-based load from a bare-symbol store when the load
   has MEM_IN_STRUCT_P set, so the cast form makes all four `sh` argument
   stores below anti-depend on that load.  That lifts their scheduling
   priority from 1 to 2, which func_8008FAF0 them in the same schedule_select group
   as the sll/ori pack pairs, where a store's larger potential_hazard wins
   the tie and -- the list scheduler emits a block backwards -- pushes the
   four stores past the packs.  Cost of getting this wrong: 8/86 words. */

struct D800F2848Rec {
    s16 f0;         /* 0x00 */
    s16 f2;         /* 0x02 */
    s16 f4;         /* 0x04 */
    s16 pad06[4];   /* 0x06 */
    s16 fE;         /* 0x0E */
    s16 pad10[8];   /* 0x10 */
    s32 f20;        /* 0x20 */
    s32 f24;        /* 0x24 */
};

extern struct D800F2848Rec D_800F2848;

extern s32 D_8009B158;
extern s32 D_8009B15C;
extern s16 D_8009B166;
extern s32 D_8009B168;
extern s16 D_8009B190;
extern s16 D_8009B192;
extern s32 D_8009B194;
extern s32 D_8009B198;
extern s32 D_8009B1C4;
extern s16 D_8009B1EE;
extern s32 D_8009B1FC;
extern s16 D_8009B204;
extern s32 D_8009B224;

void func_80022D94(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    struct D800F2848Rec *base = &D_800F2848;

    D_8009B1FC = ((s32) (arg1 - base->f0) << 0x10) / arg0;
    D_8009B198 = ((s32) (arg2 - base->f4) << 0x10) / arg0;
    D_8009B194 = ((s32) (arg3 - base->f2) << 0x10) / arg0;
    D_8009B168 = ((s32) (arg4 - base->f24) << 0x10) / arg0;

    D_8009B204 = arg0;
    D_8009B1EE = arg1;
    D_8009B192 = arg2;
    D_8009B190 = arg3;
    D_8009B166 = (s16) arg4;
    D_8009B1C4 = (base->f0 << 0x10) | 0x8000;
    D_8009B15C = (base->f4 << 0x10) | 0x8000;
    D_8009B158 = (base->f2 << 0x10) | 0x8000;
    D_8009B224 = (base->f24 << 0x10) | 0x8000;
}
