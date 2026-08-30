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

/* Starts an animated cursor move for the single object at D_800EA1E8: given a
   destination grid cell and a frame count, it writes the target position, the
   per-frame 16.16 velocity to reach it, the frame counter and the active flag,
   and func_8002A3CC then steps the object once per frame until f16 hits zero.

   Caller is card_list_cursor_move (0x8002AF88), which documents the arguments
   as func_8002A4A8(row, col, step) with row 0-0x13 and col 0-0x27. Read off
   the bytes, `row` drives the object's X axis and `col` its Y:
       x = (row % 10) * 14  + (row >= 10 ? 0xAE : 0xE)   two banks of ten
       y = (col / 10) * 178 + (col % 10) * 16 + 0xE      four banks of ten
   D_8009B258/D_8009B259 cache the cell the cursor was last sent to, so a
   repeat request for the same cell returns without disturbing an animation
   already in flight.

   The velocities are (target - current) << 16 / frames, i.e. 16.16 fixed
   point, matching the f8:fC / fA:fE high:low pairs func_8002A3CC advances.
   The fractional halves start at 0x8000 (one half) so the per-frame rounding
   lands on the nearer pixel rather than always truncating down.

   MATCHED 0/110, -G8 -msplit-addresses --keep-large-ori, w1 2026-08-29, from
   a banked 14/110. Pure C, no inline asm beyond the one inherited $t1 pin.
   THIS UNIT NEEDS --keep-large-ori: `t0->fE = 0x8000` is a genuine
   `ori v0,zero,0x8000`, and without the flag ccpsx.sh rewrites it to a
   sign-extending `addiu v0,zero,-32768`.

   THREE THINGS CLOSED IT, and the first two were both already sitting in the
   landed sibling src/func_8002A3CC.c, which describes the very same struct:

   1. THE STRUCT WAS TWO BYTES SHORT. The banked sketch had no field at 0x10,
      so f12/f14/f16/f17 all sat two bytes early and four of the residual's
      words were wrong-offset stores (sb 20 vs 22, sh 16 vs 18, sh 18 vs 20,
      sb 21 vs 23) that four passes had func_800738F0 as register-choice ties. The fNN
      names were right the whole time; the layout was not. 14 -> 11.

   2. fC AND fE ARE u16, NOT s16. As s16, `= 0x8000` constant-folds to -32768
      and gcc materialises it with `addiu`; the ROM has `ori ...,0x8000`, i.e.
      the constant is +32768 in a 32-bit sense. This is the last word, and no
      compiler flag reaches it -- --keep-large-ori preserves an `ori` that gcc
      chose, it does not turn an `addiu` into one. 1 -> 0.

   3. ONE VALUE CHAIN THROUGH ONE VARIABLE. The ROM runs both `(delta << 16)`
      dividends through $v0, each dead at its divide, and the shift writes
      back into the same register (`sll v0,v0,0x10`). Two separate delta
      locals cannot express that, and one local used as `(delta << 16)` in an
      expression cannot either -- the shift's result is then a fresh temp and
      local-alloc gives it a fresh register. The shift has to ASSIGN BACK to
      the same variable:
          delta = (s16)outA3 - t0->f8;
          delta = delta << 16;          <- not `(delta << 16)` inline
          result1 = delta / a2;
      11 -> 1, closing both divide clusters at once. Watch the scope: with a
      single `delta` spanning both divides the pseudo dies twice, so
      combine_regs refuses to tie the *subtraction's* destination -- that is
      why the subu also needed the shared variable rather than two locals.

   `delta = 1; t0->f17 = delta;` at the end is the inherited permuter-found
   constant-carrier lever (a dead local given the constant so gcc re-uses its
   register instead of materialising a fresh one) and is still load-bearing. */

struct RenderPos {
    char pad[0x30];
    u16 f30;
    u16 f32;
};

struct Obj {
    char pad0[8];
    s16 f8;                     /* 0x08  x, integer half */
    s16 fA;                     /* 0x0A  y, integer half */
    u16 fC;                     /* 0x0C  x, fractional half */
    u16 fE;                     /* 0x0E  y, fractional half */
    char pad1[2];               /* 0x10 */
    u16 f12;                    /* 0x12  x rest/target position */
    u16 f14;                    /* 0x14  y rest/target position */
    u8 f16;                     /* 0x16  frames remaining */
    u8 f17;                     /* 0x17  active flag */
    s32 f18;                    /* 0x18  x velocity, 16.16 */
    s32 f1C;                    /* 0x1C  y velocity, 16.16 */
    char pad2[0x44 - 0x20];
    struct RenderPos *f44;
};

extern struct Obj D_800EA1E8;
extern s8 D_8009B258;           /* last row the cursor was sent to */
extern s8 D_8009B259;           /* last col the cursor was sent to */

void func_8002A4A8(s32 row, s32 col, s32 frames) {
    register s32 colr asm("t1") = col;
    struct Obj *obj = &D_800EA1E8;
    s32 x;
    s32 colc;
    s32 delta;

    if (row == D_8009B258 && colr == D_8009B259) {
        return;
    }

    colc = colr;
    D_8009B258 = (s8)row;
    D_8009B259 = (s8)colr;
    obj->f16 = (u8)frames;

    if (row >= 10) {
        x = (row % 10) * 14 + 0xAE;
    } else {
        x = (row % 10) * 14 + 0xE;
    }

    {
        s32 vx;
        s32 vy;
        s32 bank = colc / 10;
        s32 y;

        delta = (s16)x - obj->f8;
        delta = delta << 16;
        vx = delta / frames;
        y = bank * 178 + (colc % 10) * 16 + 0xE;
        delta = (s16)y - obj->fA;
        delta = delta << 16;
        vy = delta / frames;
        obj->f12 = (s16)x;
        obj->f14 = (s16)y;
        obj->fE = 0x8000;
        obj->fC = 0x8000;
        delta = 1;
        obj->f17 = delta;
        obj->f18 = vx;
        obj->f1C = vy;
    }
}
