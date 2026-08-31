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

/* Sets up the GTE geometry offset/screen distance, then builds and installs
   a light-source rotation matrix for `obj`, using its packed rotation-angle
   bytes and (unless a flag bit is set) an extra per-axis scale derived from
   two of its fields. Runs an average-normal-clip test over three zeroed
   scratchpad SVECTORs to get the OTZ (GTE data register 24, no C-level
   accessor exists so it's func_800738F0 via raw swc2), then optionally invokes a
   callback stored on `obj`. If the result is still negative after that, the
   rotation matrix's X and Z columns are negated (a mirror flip) and the
   clip test is redone. Returns the final OTZ. Also fills out *out with the
   raw (arg1, arg2, obj->field65) triple it was given.

   function_ranges.txt originally split this single 126-instruction function
   into 14 bogus F entries (0x80041F90..0x80042060); it is one function that
   runs through to 0x80042188. */

struct Out {
    s16 f0;
    s16 f2;
    s32 f4;
};

/* PSYQ LIBGTE.H MATRIX: 3x3 rotation (short, with one short of padding to
   4-byte-align the translation) followed by a 3-entry translation vector. */
struct Mat {
    s16 m[3][3];
    s16 pad12;
    s32 t[3];
};

/* SVECTOR-shaped scratch struct at 0x1F800308, used both as the rotation
   input to func_80088C50 and (zeroed) as one of the three vectors fed to
   func_80089CF0. */
struct Vec308 {
    s16 f0;
    s16 f2;
    s16 f4;
    char pad6[0x8 - 0x6];
    s16 f8;
    char pad10[0x12 - 0xA];
    s16 f12;
};

/* Same 0x1F800308 scratch address, reinterpreted as a 32-bit-component
   VECTOR for the func_80087670 call. */
struct VecScale {
    s32 x;
    s32 y;
    s32 z;
};

struct Vec310 {
    char pad0[0x2];
    s16 f2;
    s16 f4;
};

struct Vec318 {
    s16 f0;
    char pad2[0x4 - 0x2];
    s16 f4;
};

struct Obj {
    char pad0[0x4];
    u32 field4;    /* flags; bit 0x8000000 disables the func_80087670 step */
    char pad8[0x10 - 0x8];
    s32 field10;   /* optional callback(obj, otz), called if < 0 (raw
                      pointer-value sign test, not a null check) */
    char pad14[0x20 - 0x14];
    u8 field20;    /* rotation angle bytes (X/Y/Z), each scaled by 16 into
                      the func_80088C50 input */
    u8 field21;
    u8 field22;
    char pad23[0x44 - 0x23];
    s16 field44;   /* scale-vector X/Y (Z is always 0x1000 = 1.0 in 4.12) */
    s16 field46;
    char pad48[0x65 - 0x48];
    u8 field65;
};

typedef void (*ObjCallback)(struct Obj *, s32);

#include "gte.h"

extern void func_800878B0(s32 a0, s32 a1);
extern void func_800878D0(s32 a0);
extern void func_80088C50(struct Vec308 *a0, struct Mat *a1);
extern void func_80087670(struct Mat *a0, struct VecScale *a1);
extern void func_800855D0(struct Mat *a0);
extern s32 func_80089CF0(struct Vec308 *a0, struct Vec310 *a1, struct Vec318 *a2, struct Vec318 *a3);
extern void func_800877B0(struct Mat *a0);

s32 func_80041F90(struct Obj *obj, s32 arg1, s32 arg2, struct Out *out) {
    struct Mat *mtx = (struct Mat *)0x1F8002D0;
    struct Vec308 *v308 = (struct Vec308 *)0x1F800308;
    s32 otz;

    out->f0 = arg1;
    out->f2 = arg2;
    out->f4 = obj->field65;

    func_800878B0(arg1, arg2);
    func_800878D0(0x12C);

    v308->f0 = (s16)(obj->field20 * 0x10);
    v308->f2 = (s16)(obj->field21 * 0x10);
    v308->f4 = (s16)(obj->field22 * 0x10);
    func_80088C50(v308, mtx);

    mtx->t[0] = 0;
    mtx->t[1] = 0;
    mtx->t[2] = 0x12C;

    if (!(obj->field4 & 0x8000000)) {
        /* reuse v308's already-computed address (s1) for the field stores,
           but a fresh cast for the call argument -- matches target, which
           recomputes 0x1F800308 separately for the func_80087670 arg. */
        ((struct VecScale *)v308)->x = obj->field44;
        ((struct VecScale *)v308)->y = obj->field46;
        ((struct VecScale *)v308)->z = 0x1000;
        func_80087670(mtx, (struct VecScale *)0x1F800308);
    }

    func_800855D0(mtx);

    {
        /* v318 pinned to $a3: target keeps this one address alive in a3
           across everything below (including calls) and reuses it as the
           4th argument of both func_80089CF0 calls without ever
           reloading it. */
        register struct Vec318 *v318 asm("a3") = (struct Vec318 *)0x1F800318;
        struct Vec310 *v310 = (struct Vec310 *)0x1F800310;
        s32 *otzp;

        v318->f0 = 0;
        v308->f0 = 0;
        v308->f8 = 0x200;
        v310->f2 = 0;
        v308->f2 = 0;
        v308->f12 = 0x200;
        v318->f4 = 0;
        v310->f4 = 0;
        v308->f4 = 0;
        func_80089CF0(v308, v310, v318, v318);

        otzp = &otz;
        gte_stopz(otzp);

        {
            s32 cb = obj->field10;
            if (cb != 0) {
                if (cb < 0) {
                    ((ObjCallback)cb)(obj, otz);
                }
                if (otz >= 0) {
                    return otz;
                }

                /* mirror flip: negate the rotation matrix's X and Z
                   columns, leave the Y column untouched */
                mtx->m[0][0] = -mtx->m[0][0];
                mtx->m[1][0] = -mtx->m[1][0];
                mtx->m[2][0] = -mtx->m[2][0];
                mtx->m[0][2] = -mtx->m[0][2];
                mtx->m[1][2] = -mtx->m[1][2];
                mtx->m[2][2] = -mtx->m[2][2];
                func_800877B0(mtx);

                /* fresh cast (not v318) for the 3rd argument here -- target
                   recomputes 0x1F800318 into $a2 instead of reusing $a3,
                   unlike the earlier call. */
                func_80089CF0(v308, v310, (struct Vec318 *)0x1F800318, v318);

                otzp = &otz;
                gte_stopz(otzp);
            }
        }
    }

    return otz;
}
