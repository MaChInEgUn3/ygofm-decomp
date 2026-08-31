/* PARKED CANDIDATE PORTED from Unchiga's tree (docs/MERGE_UNCHIGA.md).
 * Installed here because HIS base is closer than the one this tree
 * reached: the counts are in PARKED.txt. Measure it with the flags on
 * the next line -- they are his unit's, and try_func's default flags
 * report a different number.
 * FLAGS: -G8 -msplit-addresses
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef short s16;
typedef int s32;

/* func_800260D0 -- no confirmed real name. Countdown-gated dispatcher:
   every call decrements D_8009B1D0; once it underflows to <=0, resets it
   to 0x10 and advances D_8009B20E (a rolling counter, reset to -1 by
   func_80024E24()'s cold-start branch). If the counter is < 5, spawns
   an Obj (func_8002C604(8)) seeded from a D_800907D8[] slot lookup and a
   D_80090800[] Row table entry, and conditionally clears a D_801A7AD8[]
   Rec's f12 flag; else clears D_8009B220.

   w5 near-miss refinement (2026-08-28): took the PERMUTER-IMMUNE 6/87
   candidate (match/sketches/func_800260D0_permuted140.c, harvested by w3
   from a 24->3-class permuter reorder run, itself stuck after 237K
   iterations) down to 2/87. The 6-diff residual was actually TWO
   independent, unrelated issues bundled together -- separating them
   mattered:
   1. offsets 0xb0-0xd0 (marker->f0/f2/f4 field-store block): NOT a
      scheduler tie at all, despite the 17:57:47Z note's diagnosis -- it
      was a plain wrong SOURCE STATEMENT ORDER. Target reads row->f0 and
      stores marker->f0 FIRST, THEN (much later, right before the
      following call) reads row->f2 and stores marker->f4 in the CALL's
      branch-delay slot. The inherited C had `marker->f4=row->f2;` as the
      very FIRST of the three field assignments -- swapping it with
      `marker->f0=row->f0;` (so f0 comes first, f4 third, `f2=0` stays in
      the middle) reproduced target exactly, 6->2. IMPORTANT: this is
      extremely order-position-sensitive at the WHOLE-FUNCTION level, not
      just locally -- moving `marker->f4=row->f2;` further down to sit
      immediately before the call() (the "obvious" reading of target's
      deferred-store timing) instead regressed catastrophically to 21/87,
      reshuffling register allocation all the way up at the function's
      TOP-level branch/compare code. Only the minimal adjacent swap (f0
      and f4 trade places, f2 stays put, nothing else moves) works.
   MATCHED 0/87 (2026-08-28, w1) under -G8 -msplit-addresses ONLY: the other
   three combos give 61/93/97, so this unit NEEDS that flag pair.

   HOW THE LAST 2 CLOSED, and why every single-lever attempt func_800738F0 as a wall.
   The residual at 0x78/0x7c was target addiu v0,v0,10 then addu v0,a1,v0
   ((player*20 + 10) + counter) against the candidate addiu v1,a1,10 then
   addu v0,v0,v1 (player*20 + (counter + 10)) -- the same multiset,
   reassociated. Forcing the grouping needs a barrier or a raw asm addu, and
   EVERY form of that regressed to 63-64/87, which the note on file func_800738F0 as
   "extremely fragile, PERM-immune, leave it alone". That reading was wrong,
   and the 63 was one clue misread as noise: the regression is not a
   reshuffle, it is TWO NOPS. Any extra local or asm in this block makes gcc
   sink the D_800907D8 base materialisation (lui a0,0x8009 / addiu a0,a0,2008)
   past the two slots target fills with it -- the beqz delay slot at 0x60 and
   the lbu load-delay slot at 0x68 -- so the whole tail shifts by 2 words and
   every later word "differs".
   So the fix is COUPLED, and neither half works alone:
     - pin the table base into its target register and materialise it FIRST
       (register u8 *tbl asm("a0") = D_800907D8; before the player load), which
       keeps it available to fill both delay slots; AND
     - force the addition grouping with a minimal 2-input asm addu into a
       v0-pinned index.
   Applying only the second gives 63/87; only the first was never the
   suspect. Same coupled-residual shape as func_8003A198 and func_8004A8E4,
   closed in the same pass: when one lever makes the count WORSE, func_800738F0 the
   regression instead of dropping the lever -- it can be naming the second
   half of the fix.
   Dead ends re-measured from the 2/87 base: named intermediate for
   player*20+10, at function scope, at if-block scope, or v0-pinned: 63/87
   each; scoped asm addu without the table pin: 63/87; empty +r launder on
   the intermediate: 63/87; counter instead of the D_8009B20E re-func_800738F0: 2/87
   (no change); (s32) casts at the add site: 2/87; D_8009B20E + (player*20+10):
   11/87.

*/

struct Obj {
    u16 f0;
    u16 f2;
    u16 f4;
    char pad[0x14 - 6];
    s32 f14;
    char pad2[0x1A - 0x18];
    u16 f1A;
};
struct Rec {
    char pad[0x12];
    s16 f12;
    char pad2[0x16 - 0x14];
    u16 f16;
    char pad3[0x1C - 0x18];
};
struct Row {
    u16 f0;
    u16 f2;
};

extern u16 D_8009B1D0;
extern u8 D_8009B1D5;
extern s16 D_8009B20E;
extern u16 D_8009B220;
extern u8 D_800907D8[];
extern struct Row D_80090800[];
extern struct Rec D_801A7AD8[];
s32 func_80024E24(void);
struct Obj *func_8002C604(s32);
void func_8003FEE0(u32);

void func_800260D0(void) {
    s16 counter;
    u8 player;
    u8 slot;
    struct Rec *rec;
    struct Obj *marker;
    struct Row *row;

    if (func_80024E24() == 0) {
        D_8009B20E = -1;
        D_8009B1D0 = 0;
    }
    D_8009B1D0 -= 1;
    if ((s16) D_8009B1D0 > 0) {
        return;
    }
    D_8009B1D0 = 0x10;
    counter = D_8009B20E + 1;
    D_8009B20E = counter;
    if (counter < 5) {
        register u8 *tbl asm("a0");
        register s32 pidx asm("v0");
        tbl = D_800907D8;
        player = D_8009B1D5;
        pidx = player * 20 + 10;
        __asm__("addu %0, %1, %2" : "=r" (pidx) : "r" ((s32) counter), "r" (pidx));
        slot = tbl[pidx];
        rec = &D_801A7AD8[slot];
        marker = func_8002C604(8);
        {
            char *rowbase = (char *) D_80090800;
            marker->f1A = 3;
            row = (struct Row *) (rowbase + (((D_8009B20E + 10) * 4) + (D_8009B1D5 * 80)));
        }
        marker->f0 = row->f0;
        marker->f2 = 0;
        marker->f4 = row->f2;
        marker->f14 += D_8009B20E * 0x3000;
        func_8003FEE0(0x14);
        if ((rec->f16 & 0x8000) && (rec->f12 < 0)) {
            rec->f12 = 0;
            marker->f1A = 5;
        }
    } else {
        D_8009B220 = 0;
    }
}
