/* ASSEMBLY DEBT -- this is a TRANSCRIPTION, not a decompilation.
 * Ordinary MIPS written into an inline asm block to force a match. It is
 * byte-exact and therefore invisible to build.py, which is exactly the
 * problem: the oracle cannot tell transcribed assembly from real C, so
 * nothing but this comment stops it being counted as done.
 * Counted by tools_src/asm_debt.py; the standard is in docs/ASM_DEBT.md.
 */
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

/* SEAM DOCUMENTATION (base-EXE<->overlay boundary, USER PRIORITY DIRECTIVE
   #1, 2026-08-29): this is the PHASE WRITER half of the seam, paired with
   func_8002C6C8 (src/func_8002C6C8.c) which is the READER/
   DISPATCHER half. Both operate on the same D_800EAD88[8] pool of 0x20-byte
   duel-participant records (see that file's struct Rec for the fully-named
   layout). This function's `phase` parameter IS the phase value: the
   instruction at 0x8002C638 (`sh s0,24(a0)`, s0 holding the original a0
   saved across the func_8002C5CC allocator call) writes it straight into
   the freshly-allocated record's f18 -- the exact field
   func_8002C6C8 later reads as `rec->f18` (byte offset 0x18,
   confirmed live at RAM address 0x800EADA0 for pool slot 0) and passes as
   func_801462B0's first argument. func_801462B0 is the disc-streamed
   overlay dispatcher (0x8014xxxx-0x8015xxxx region, currently nops in
   asm_803E0.s -- w5's overlay-split lane); its arg0 is how the base EXE
   hands the current duel phase across that seam into overlay code. Live
   capture evidence (opponent-turn-2026-08-20_134333/opponent_turn.pst,
   func_800738F0 directly via tools/scout.py peek): pool slot 0's f18 reads 0x0002
   during an opponent-turn snapshot, confirming phase value 2 is live
   during the opponent's turn.

   Allocates a free D_800EAD88[] pool entry (func_8002C5CC) and, if one was
   free, initializes it: marks it in-use (f1C=0x80), stashes the phase at
   f18, copies fC/f8 from D_800E9D90.f4/f8, sets f10=8, zeroes
   f0/f2/f4/f12/f1A/f1D, and computes f14 as *(s32 *)D_80010000 + 0x3800.
   Returns the entry pointer (or the allocator's null/failure value).

   LANDED 0/34 (w1, 2026-08-29) -- G8:split, exact word count. History: a
   24/34 hand-analysis baseline (single a0/a1 register-role swap) was cut to
   3/34 by a decomp-permuter PERMUTABLE-REORDER pass (601,948 iterations
   across two 90-min windows, see WORKFLOW.md NOT-A-WALL:reorder-multiset-
   residuals), then sat at 3/34 through six exhausted hand levers across two
   workers and a further ~557k directed-permuter iterations, and was marked
   PERMUTER-IMMUNE. That mark is now RETRACTED as moot: the residual was a
   pure 3-word cyclic rotation -- target emits `li v0,128; lui v1,0x8001;
   lw v1,0(v1)` (v1 self-clobbering as both the D_80010000 address AND the
   loaded result, which is only possible because v0 is already BUSY holding
   the 0x80 constant across the load); every plain-C shape instead emits
   `lui v0,0x8001; lw v1,0(v0); li v0,128`, materializing the constant
   after the load because gcc sinks/rematerializes a dead-simple immediate
   down to its single use.

   THE LEVER (new, generalizable): anchor the constant in a register with an
   empty func_800738F0-func_80073900 asm BEFORE the load that must not use that register --
       flag = 0x80;
       __asm__ volatile("" : "+r" (flag));
   The asm emits no instructions of its own (`#APP`/`#NO_APP` with nothing
   between) but makes the value live at that program point, so gcc must
   emit the `li` there instead of sinking it, and the register allocator --
   now unable to reuse v0 for the load's address temp -- falls back to v1
   and coalesces address with destination exactly as target does. The `li`
   still floats into the branch's delay slot because it is a real gcc
   instruction, not asm (a raw `__asm__("li ...")` cannot fill a delay slot,
   which is why the earlier combined-asm-block attempts all cost extra
   words). Works with or without a `register ... asm("v0")` pin on `flag`
   (both tested 0/34); the plain local is kept as the simpler form. */

struct Rec {
    s16 f0;
    s16 f2;
    s16 f4;
    s32 f8;
    s32 fC;
    s16 f10;
    s16 f12;
    s32 f14;
    s16 f18;
    s16 f1A;
    u8 f1C;
    u8 f1D;
    u8 pad1E[2];
};

struct D800E9D90Type {
    char pad[0x4];
    s32 f4;
    s32 f8;
};

extern struct Rec *func_8002C5CC(void);
extern struct D800E9D90Type D_800E9D90;
extern s32 D_80010000[4];

struct Rec *func_8002C604(s16 phase) {
    struct Rec *rec;
    struct Rec *obj;
    struct D800E9D90Type *base;
    s32 tick;
    s32 val;
    s32 flag;

    rec = func_8002C5CC();
    do { obj = rec; } while (0);
    if (obj != 0) {
        flag = 0x80;
        __asm__ volatile("" : "+r" (flag));
        tick = D_80010000[0];
        obj->f1C = flag;
        obj->f18 = phase;
        obj->f1A = 0;
        obj->f1D = 0;
        val = tick;
        base = &D_800E9D90;
        obj->f14 = val + 0x3800;
        obj->f8 = base->f8;
        val = base->f4;
        obj->f10 = 8;
        obj->f0 = 0;
        obj->f2 = 0;
        obj->f4 = 0;
        obj->f12 = 0;
        obj->fC = val;
    }
    return obj;
}
