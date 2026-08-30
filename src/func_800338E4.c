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

/* Scroll-follow interpolation step.  While the gate func_80032B38 reports
   idle, re-arms a 16-tick glide from the current scroll position
   D_8009B146 toward this object's target f5AA4: f5AA8 becomes the per-tick
   step and f5AAC the tick counter.  Every call then advances D_8009B146 by
   one step and ticks the counter down; on the tick that reaches zero the
   position snaps exactly to the target, f6342 latches whether that target
   was non-zero, and f633E takes f6340.

   D_8009B146 sits just past $gp's small-data window in this TU's view, so
   -G0 addressing materializes its address fresh at each of the four access
   sites -- that is the target's shape and the reason for the flags.

   The one-instruction asm barrier is the constant-anchor lever: gcc sinks
   `arg = 30` down to the call, leaving the divide's bgez delay slot empty,
   and target has the `li a0,30` in it.  The barrier keeps the constant live
   across the divide so the delay-slot filler can use it, and emits no
   instructions of its own.  Its position matters in both directions: any
   earlier and the `li` gets pulled into the preceding bnez's delay slot
   instead. */

struct Obj {
    char pad0[0x5AA4];
    s32 f5AA4;                  /* target scroll position */
    s32 f5AA8;                  /* per-tick step */
    s32 f5AAC;                  /* ticks remaining */
    char pad1[0x633E - 0x5AB0];
    s16 f633E;
    u16 f6340;
    u8 f6342;                   /* arrival flag */
};

extern u16 D_8009B146;          /* live scroll position */
extern s32 func_80032B38(void);
extern void func_8003FEE0(s32 a0);

void func_800338E4(struct Obj *arg0) {
    s32 ticks;

    if (func_80032B38() == 0) {
        s32 diff;
        s32 arg;

        diff = arg0->f5AA4 - (s16) D_8009B146;
        arg = 30;
        arg0->f5AA8 = diff / 16;
        __asm__ volatile("" : "+r" (arg));
        arg0->f5AAC = 16;
        func_8003FEE0(arg);
    }

    D_8009B146 = D_8009B146 + (u16) arg0->f5AA8;

    ticks = arg0->f5AAC - 1;
    arg0->f5AAC = ticks;
    if (ticks == 0) {
        u16 pos = (u16) arg0->f5AA4;
        arg0->f6342 = 0;
        D_8009B146 = pos;
        if (((s32) pos << 16) != 0) {
            arg0->f6342 = 1;
        }
        arg0->f633E = arg0->f6340;
    }
}
