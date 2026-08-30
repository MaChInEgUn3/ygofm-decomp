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

/* Per-frame step for the single animated object at D_800EA1E8: advances a
   16.16 fixed-point x/y position by its per-frame velocity, counts the
   remaining frames down, and on the last frame snaps the object back to its
   rest position, fires a sound cue and hands off to func_8002A2F4. The
   integer halves of x and y are then published to the object's render record.
   Returns the still-active flag (f17), which is also the early-out: an
   inactive object does nothing and returns 0.

   f8/fC and fA/fE are the high and low halves of the two fixed-point
   coordinates -- they are separate struct fields rather than one s32 each,
   which is why the C recombines them by hand every frame.

   MATCHED 0/55 by w1 (2026-08-28) on both split combos (G8:split and
   G0:split; both nosplit combos give 3/55), from a banked 2/55.

   PROVENANCE: this body is decomp-permuter output, adopted verbatim apart
   from the header and the shared typedefs -- and finding it says more about
   the queue than about this function. permuter_queue's `harvest` only
   collects outputs whose INTERNAL SCORE is 0, and it had been reporting
   "no score-0 outputs yet" for this run all session. This is
   `output-20-1`, internal score 20, and it is byte-exact. The score is not
   a diff count and, as this shows, is not even monotonic with one: the run
   also produced score-10 outputs that verify at 2/55, WORSE than the score-20
   one that matches. So a finished match can sit parked in a run directory
   indefinitely while status prints "best 20" and harvest prints nothing.
   Re-verify every parked output against the ROM, not just the score-0 ones.

   The hand seed this run started from is match/sketches/func_8002A3CC.c at
   2/55; that residual was a register-role tie, which is the permuter's
   actual sweet spot, so this is the tool working as intended -- it was only
   the collection step that hid it. */

struct RenderPos {
    char pad[0x30];
    u16 f30;
    u16 f32;
};

struct Obj {
    char pad0[8];
    s16 f8;              /* x, integer half */
    s16 fA;              /* y, integer half */
    u16 fC;              /* x, fractional half */
    u16 fE;              /* y, fractional half */
    char pad1[2];
    u16 f12;             /* x rest position */
    u16 f14;             /* y rest position */
    u8 f16;              /* frames remaining */
    u8 f17;              /* active flag */
    s32 f18;             /* x velocity, 16.16 */
    s32 f1C;             /* y velocity, 16.16 */
    char pad2[0x44 - 0x20];
    struct RenderPos *f44;
};

extern struct Obj D_800EA1E8;
extern void func_8003FEE0(s32 a0);
extern void func_8002A2F4(struct Obj *a0);

s32 func_8002A3CC(void) {
    struct Obj *obj = &D_800EA1E8;

    if (!obj->f17) {
        return obj->f17;
    }
    {
        s32 pos;

        pos = (((s32) obj->f8) << 16) | obj->fC;
        pos = pos + obj->f18;
        obj->fC = (u16) pos;
        obj->f8 = (s16) (pos >> 16);

        pos = (((s32) obj->fA) << 16) | obj->fE;
        pos = pos + obj->f1C;
        obj->fA = (s16) (pos >> 16);
        obj->fE = (u16) pos;
    }
    if ((--obj->f16) == 0) {
        obj->f17 = 0;
        obj->f8 = obj->f12;
        obj->fA = obj->f14;
        func_8003FEE0(0x35);
        func_8002A2F4(obj);
    }
    obj->f44->f30 = obj->f8;
    obj->f44->f32 = obj->fA;
    return obj->f17;
}
