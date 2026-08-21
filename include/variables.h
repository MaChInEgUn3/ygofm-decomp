#ifndef VARIABLES_H
#define VARIABLES_H

#include "types.h"

/*
 * Game globals, declared once here so that two source files can never
 * disagree about a variable's type or qualifiers -- a disagreement would
 * silently change codegen and break matching in a hard-to-trace way.
 *
 * Names are splat's auto-generated D_<address> form. Rename them (here and
 * at the use sites) as their purpose becomes clear.
 *
 * Two conventions matter for matching:
 *
 *  - `volatile` is not decoration. The retail code frequently stores and
 *    then reloads the same global, which a non-volatile access would let
 *    the compiler fold away. Mark a variable volatile only once a function
 *    actually requires it to match.
 *
 *  - Scalars vs. arrays is a *codegen* distinction here, not a stylistic
 *    one. We build with -G8, so a small scalar is placed in small data and
 *    accessed gp-relative (`lhu $v0, %gp_rel(sym)($gp)`). A symbol the
 *    retail code reaches with an explicit `%hi`/`%lo` pair was not small
 *    data in the original build -- almost certainly because it was an
 *    array or a struct rather than a scalar. Declaring those as
 *    unsized arrays here reproduces that. If a symbol is declared the
 *    wrong way round, the function using it will not match.
 */

/* --- small data: accessed gp-relative ------------------------------------ */

/* gp-relative in five functions and a %hi/%lo pair in two, which is the
 * ordinary per-file addressing disagreement: the aggregate arm is not small
 * data, so cc1psx emits its own pair and the scalars beside it stay
 * gp-relative at the default -G8 (func_80037B40). */
#ifdef D_8009B112_SIZED
/* Eight bytes it does not have. The gp-relative symbols beside it in
 * func_800257A0 are one and two bytes, so no real threshold separates them;
 * `[4]` clears cc's own -G8 (bare symbol, ONE instruction to the delay-slot
 * filler) and 8 > 4 takes it out of small data at `as -G4`. Retail leaves a
 * `nop` in the branch delay slot in front of the pair; the aggregate arm is
 * two instructions and gets the `lui` hoisted into it. */
extern volatile u16 D_8009B112[4];
#elif defined(D_8009B112_IS_AGGREGATE)
extern volatile u16 D_8009B112[];
#else
extern volatile u16 D_8009B112;
#endif

extern u8 D_8009B335;

extern u8 D_8009AFA0;
extern u8 Base2_8009AFA4[];
#ifdef D_8009AFA4_IS_AGGREGATE
extern u8 D_8009AFA4[];
#else
extern u8 D_8009AFA4;
#endif
extern u8 D_8009AFA2;
extern u8 D_8009AFA6;
extern u8 D_8009B060;
extern u8 D_8009B065;
extern u8 D_8009B066;
extern u8 D_8009B067;
extern u8 *D_8009B498;
extern u8 D_8009B063;
extern u8 D_8009B064;
extern u8 D_8009B078;
extern u8 D_8009B07B;
extern u8 D_8009B07C;
extern u8 D_8009B079;
extern s8 D_8009B07A;
extern u8 D_8009B141;
#ifdef D_8009B145_SIZED8
/* Eight bytes it does not have: func_8002E730 reaches it %hi/%lo while
 * four-byte gp-relative symbols in the same unit stay small, so it needs a
 * size above that function's `as -G4` and at or below cc's own -G8. */
extern u8 D_8009B145[8];
#else
extern u8 D_8009B145;
#endif
extern s8 D_8009B238;
extern u16 D_8009B244;
extern u8 D_8009B248;
extern u8 D_8009B24A;
extern u8 D_8009B3C6;
extern u8 D_8009B2EB;
/* Two bytes under the guard so an assembler at -G1 expands the bare reference
 * through the destination register while the one-byte D_8009B428 beside it
 * keeps %gp_rel (func_80043BCC). The size is a codegen knob. */
#ifdef D_8009B318_SIZED
extern u8 D_8009B318[2];
#else
extern u8 D_8009B318;
#endif
extern u8 D_8009B428;

/* func_800339D0 stores it through `lui $at` while the one-byte D_8009B2F8
 * beside it keeps %gp_rel; equal widths, so no real threshold exists and the
 * SIZED8 arm declares eight bytes with the unit at `as -G4`. */
#ifdef D_8009B140_SIZED8
extern u8 D_8009B140[8];
#else
extern u8 D_8009B140;
#endif
/* Read as a byte through %hi/%lo by func_8003D518, and gp-relatively as a
 * halfword everywhere else. */
#ifdef D_8009AF76_IS_AGGREGATE
extern u8 D_8009AF76[];
#else
extern u16 D_8009AF76;
#endif
/* Reached %hi/%lo by func_8003D46C. */
/* func_8003D46C needs this one to keep cc1psx's own %hi/%lo pair while the
 * same unit stores to D_8009B34D as a bare symbol; volatile is the only thing
 * that blocks the bare form per-symbol. */
#ifdef D_800EF6EA_IS_VOLATILE
extern volatile u8 D_800EF6EA[];
#else
extern u8 D_800EF6EA[];
#endif
extern u16 D_8009AF7A;
extern u16 D_8009AF92;
extern u16 D_8009AF96;
/* func_80061008 reaches both through the assembler's bare form (`lui $at`).
 * That is the scalar declaration plus a -G0 assembler, not a declaration
 * change: cc1psx emits `sh $0,D_8009B148` for a scalar either way, and it is
 * the assembler's -G that decides between %gp_rel and the $at expansion.
 * func_80037A58 needs the same bare form while *other* symbols in the same
 * function stay gp-relative, so it cannot use a -G0 assembler; there the
 * aggregate declaration plus -mno-split-addresses is the only route. */
#ifdef D_8009B146_SIZED
/* Eight bytes each so an assembler at -G4 treats them as non-small and expands
 * the bare stores through $at, while the four-byte D_8009B290 and the two-byte
 * D_8009B270/D_8009B27C in the same unit keep %gp_rel (func_8002E470). The
 * size is a codegen knob; see the -G-threshold section of DECISIONS.md. */
extern u16 D_8009B146[4];
extern u16 D_8009B148[4];
#elif defined(D_8009B146_IS_AGGREGATE)
extern u16 D_8009B146[];
extern u16 D_8009B148[];
#else
extern s16 D_8009B146;
extern s16 D_8009B148;
#endif
extern s16 D_8009B1A8;
extern s16 D_8009B1A0;
/* Reached as `%gp_rel(D_8009B20C + 0x2)` -- a member access on a small-data
 * object. The size has to be declared (an unsized array is never small
 * data, whatever -G says) and eight still clears -G8 (func_800260D0). */
#ifdef D_8009B20C_HALF
/* Two elements, not the four it has: func_80025D30 needs D_8009B260 out of
 * small data while this stays in it, and only a -G4 threshold opens that
 * window. Element [1] is the only one this unit touches. */
extern s16 D_8009B20C[2];
#else
extern s16 D_8009B20C[4];
#endif
extern u16 D_8009B1D0;
extern s16 D_8009B1D2;
extern s16 D_8009B33C;
extern u16 D_8009B22A;
extern u8 D_8009B1B8;
/* Passed to func_80040410 by func_80024E58; gp-relative there. */
extern u8 *D_8009B214;
extern u16 D_8009B220;
extern u16 D_8009B210;
/* func_80022D94 writes all thirteen: the five `sh` are the target values it
 * was handed, the eight `sw` are fixed-point accumulators (current << 16 |
 * 0x8000) and their per-step deltas. */
extern s16 D_8009B204;
extern s16 D_8009B1EE;
extern s16 D_8009B192;
extern s16 D_8009B190;
extern s16 D_8009B166;
extern s32 D_8009B1C4;
extern s32 D_8009B15C;
extern s32 D_8009B158;
extern s32 D_8009B224;
extern s32 D_8009B1FC;
extern s32 D_8009B198;
extern s32 D_8009B194;
extern s32 D_8009B168;
/* Indexed by a small offset and reached as `&D_8009AF38[i]`, which cc1psx
 * only spells `addiu $v0,$gp,%gp_rel(...)` while the symbol is small data.
 * The eight is a codegen knob for that -- it has to clear -G8 as small, and
 * the real extent is not known from the listing (func_8002525C). */
extern u8 D_8009AF30[8];
extern u8 D_8009AF38[8];
#ifdef D_8009B2A8_IS_AGGREGATE
extern u16 D_8009B2A8[];
extern u16 Base2_8009B2A8[];
#else
extern u16 D_8009B2A8;
#endif
#ifdef D_8009B2AA_IS_AGGREGATE
extern u16 D_8009B2AA[];
extern u16 Base2_8009B2AA[];
extern u16 Base3_8009B2AA[];
extern u16 Base4_8009B2AA[];
#else
extern u16 D_8009B2AA;
#endif
#ifdef D_8009B29C_IS_AGGREGATE
extern u16 D_8009B29C[];
#else
extern u16 D_8009B29C;
#endif
#ifdef D_8009B270_IS_AGGREGATE
extern u16 D_8009B270[];
#else
extern u16 D_8009B270;
#endif
extern u16 D_8009B278;
extern s32 D_8009B284;
extern s32 D_8009B288;
extern s32 D_8009B294;
extern s32 D_8009B298;
#ifdef D_8009B27C_IS_AGGREGATE
extern u16 D_8009B27C[];
#else
extern u16 D_8009B27C;
/* Holds func_800400AC's result for func_8002E730; gp-relative there. */
extern u8 *D_8009B280;
#endif

/* Two words of PRNG state, mixed together by func_8003CE74. Eight bytes, so
 * still small data at -G8 even though func_8003CE74 takes its address. */
extern u32 D_8009AF64[2];
extern s32 D_8009AF68;

/* Four halfwords the code hands to func_8007FA38 by the address of the
 * first, but which splat named individually and retail reaches by name --
 * so they are four scalars, small data at -G8, and `&D_8009B468` gives the
 * `addiu $a0,$gp,%gp_rel(...)` the listing has (func_8004E9A0). */
/* A second four-halfword rectangle handed to the library by the address of
 * its first member, same shape as D_8009B468 (func_800582C0). */
extern s16 D_8009B470;
extern s16 D_8009B472;
extern s16 D_8009B474;
extern s16 D_8009B476;
extern s16 D_8009B468;
extern s16 D_8009B46A;
extern s16 D_8009B46C;
extern s16 D_8009B46E;
extern u8 *D_8009AF88;
extern u16 D_8009AF8C;
extern s16 D_8009AF8E;
extern s16 D_8009AF90;
extern u8 D_8009B478;
extern u8 D_8009B480;
/* Three small parallel arrays indexed by the slot number, reached as
 * `&D_8009B488[i]` -- so they carry declared sizes and stay small data
 * (func_80053248). */
extern s16 D_8009B488[4];
extern u8 D_8009B48E[2];
extern u8 D_8009B490[2];
extern s16 D_8009B35A;
extern u8 D_8009B356;
/* func_8004E7B0's previous-frame pair for D_8009B47A/D_8009B47C. */
extern s16 D_8009B482;
extern s16 D_8009B484;
extern u16 D_8009B47A;
extern u16 D_8009B47C;

/* --- aggregates reached with an explicit %hi/%lo pair --------------------- */
/* Declared unsized so they are never treated as small data. */

extern u8 D_800EAE90[];
extern s16 D_800EAFF8[];
/* A four-halfword rectangle: x, y, w, h. func_8001944C fills it twice and
 * hands its address to two library calls. */
extern s16 D_800E9D70[];
/* Sized under a guard: func_8002D458 assembles at -G2, where four bytes is
 * not small data, so this one goes through the assembler's `$at` while the
 * one-byte scalars beside it keep %gp_rel.  The size is a codegen knob, not a
 * measurement -- see the -G-threshold section in DECISIONS.md. */
#ifdef D_8009B27A_SIZED
extern u8 D_8009B27A[4];
#else
extern u8 D_8009B27A[];
#endif
/* A table of object pointers; func_8002CE64 passes its address as a u8 *. */
#ifdef D_800EAE98_IS_PTR_TABLE
extern u8 *D_800EAE98[];
#elif defined(D_800EAE98_SIZED)
/* Eight bytes it does not have -- func_8002FD10 reaches +0x3C. The size has to
 * sit in the window `4 < size <= 8`: at or below the compiler's own -G8 so
 * cc1psx keeps emitting the bare symbol, and above the assembler's -G4 so the
 * assembler expands it. A bare symbol is ONE instruction to the scheduler, so
 * the `lui`/`addiu` pair stays in the destination register instead of being
 * split across a temp. 0x40 does NOT work: it clears cc -G8 too, and cc1psx
 * emits its own splittable pair. Same knob as D_8009B146 above. */
extern u8 D_800EAE98[8];
#else
extern u8 D_800EAE98[];
#endif
extern u8 D_800F569F[];
extern u8 D_80091508[];
extern u8 D_800F5C7F[];
extern u16 D_800F5678[];
extern u8 D_80091008[];
extern u8 D_800F56A0[];
extern u8 D_800F56F0[];
extern u8 D_800F5710[];
extern u8 D_800F3A10[];
extern u8 D_800FE148[];
extern u8 D_800FE348[];
extern u8 D_800938AE[];

/* func_800386B8 reaches both of these through %hi/%lo and stores through $at,
 * so they are aggregates there and small data everywhere else. */
#ifdef D_8009B400_IS_AGGREGATE
extern s32 D_8009B400[];
extern s32 D_8009B404[];
#else
extern s32 D_8009B400;
extern s32 D_8009B404;
#endif
extern u8 D_8009B3EF;
extern u8 D_8009B3EB;
extern u8 D_800F5750[];
extern u8 D_800F5788[];
extern s32 D_80090E0C[];
extern s32 D_800F5B98[];
/* Four handles func_800440F0 hands to func_80043D48 in one go. */
extern s32 D_800F2AE0[];
extern u8 D_800EAE88[];
/* The byte at D_800EAE88[0xA] under its own name: func_80070F1C writes it
 * through both, and splat had already given the address a symbol. */
extern u8 D_800EAE92[];
extern u8 D_800EAE8E[];
extern u8 D_800EAE8F[];
/* Two bytes under the guard so an assembler at -G2 treats it as non-small (two would still be small):
 * func_80024200 stores it through $at and loads it through the destination
 * register while the two-byte gp-relative symbols beside it stay small. */
/* Sixteen, for a unit whose gp-relative neighbours include the eight-byte
 * D_8009B20C: the window 8 <= G < size needs a size above eight, and then
 * the default -G8 assembler is already enough (func_80025D30). */
#ifdef D_8009B260_SIZED16
extern u8 D_8009B260[16];
#elif defined(D_8009B260_SIZED)
/* Eight, not the four it has: func_80025BEC needs it non-small while a
 * four-byte pointer beside it stays %gp_rel, so the window is 4 <= G < size
 * and only a declared eight opens one. func_80024200 assembles at -G2 and
 * is unaffected -- four and eight are both non-small there (rechecked). */
extern u8 D_8009B260[8];
#else
extern u8 D_8009B260;
#endif
extern u8 *D_8009B17C;
extern u8 D_8009B261;
extern u8 *D_8009B264;
extern u8 D_800EAD88[];
extern s32 D_800EB12C[];
extern VoidFn D_80090C50[];
extern u8 *D_8009B2FC;
extern u8 D_80090DD8[];
#ifdef D_8009B0D1_IS_SCALAR
extern u8 D_8009B0D1;
#elif defined(D_8009B0D1_SIZED)
extern u8 D_8009B0D1[4];
#else
extern u8 D_8009B0D1[];
#endif
extern u8 D_801D3200[];
extern u8 D_80010384[];
/* Twenty bytes of Shift-JIS full-width digits, copied to the stack whole. */
extern u8 D_80010330[];
/* Scalar by default -- func_8003FCD8 reaches it gp-relatively. func_80030EC8
 * needs %hi/%lo and defines D_8009B3ED_IS_AGGREGATE. */
#ifdef D_8009B3ED_IS_AGGREGATE
extern u8 D_8009B3ED[];
#else
extern u8 D_8009B3ED;
#endif
/* Aggregate by default; func_8003FD14 reaches it gp-relatively. */
#ifdef D_8009B3EA_IS_SCALAR
extern u8 D_8009B3EA;
#else
extern u8 D_8009B3EA[];
#endif
extern u8 D_8009B3C0;
/* func_80038530 reaches this and its six neighbours through the assembler's
 * bare form, which needs the scalar declaration plus a -G0 assembler; every
 * other user takes them as unsized arrays. */
#ifdef D_8009B364_SIZED8
/* Eight bytes it does not have, so that at `as -G4` it is not small data while
 * the four-byte gp scalars beside it are (func_80024E58, recipe branch 3).
 * Still at or below cc's own -G8, so cc1psx keeps emitting the bare symbol and
 * the assembler expands the store through $at. */
/* Data Crystal RAM map, UNVERIFIED: terrain type */
extern u8 D_8009B364[8];
#elif defined(D_8009B364_SIZED)
/* Two bytes for the same reason as D_8009B0C0; see func_8002D180. */
/* Data Crystal RAM map, UNVERIFIED: terrain type */
extern u8 D_8009B364[2];
#elif defined(D_8009B364_IS_SCALAR)
extern u8 D_8009B364;
#else
extern u8 D_8009B364[];
#endif
extern u16 D_800F5C80[];
extern u8 D_8009AF94;
extern u8 D_8009AF9B;
extern s32 D_8009AF9C;
extern u8 D_800F5C82[];
extern u8 D_800F5C83[];
/* Read twice in a row by func_80015038, once per condition, so the
 * hardware register it shadows is not cached across the test. */
/* Non-volatile in the aggregate arm: both users read it once, and volatile
 * blocks the bare-symbol form whose assembler expansion reuses the
 * destination register -- which is what retail shows.
 * NARROWED 2026-08-20: that is true at -G4, not in general. func_80032184
 * assembles at -G0 and uses the VOLATILE scalar arm, and still gets the bare
 * form -- `lui $at` stores and destination-register loads. It needs volatile
 * for a different reason: two read-modify-writes back to back with no store
 * between them, where gcc otherwise folds the second read into the value it
 * just wrote and one whole RMW disappears. 81 differences to 33 on that
 * declaration alone. So: volatile and the bare form are compatible at -G0,
 * and the note above should be read as being about -G4. */
#ifdef D_8009B0F4_SIZED
/* Eight bytes: at -G4 that is not small data, so the reference stays a single
 * bare pseudo-instruction and the assembler expands it -- which is what stops
 * the scheduler interleaving its %hi with a neighbour's (func_8002E470). */
extern s32 D_8009B0F4[2];
#elif defined(D_8009B0F4_IS_AGGREGATE)
extern s32 D_8009B0F4[];
extern s32 Base2_8009B0F4[];
extern s32 Base3_8009B0F4[];
#else
extern volatile s32 D_8009B0F4;
#endif
/* A table of (threshold, value) halfword pairs, five per row: the retail
 * code indexes rows by arg0 * 20 and then walks pairs four bytes at a time. */
typedef struct {
    s16 threshold;
    s16 value;
} Threshold;

/* Data Crystal RAM map, UNVERIFIED: table of score change to rank, 200 bytes */
extern Threshold D_801798A8[][5];
extern u8 D_801AB00C[];
extern u8 D_801AB2A0[];  /* &D_801AB00C[0x37] under its own name */
/* Scalar by default -- three functions reach it gp-relatively. func_8007154C
 * needs %hi/%lo and defines D_8009B1D5_IS_AGGREGATE. */
#ifdef D_8009B1D5_IS_AGGREGATE
extern u8 D_8009B1D5[];
#else
extern u8 *D_8009B1B4;
extern u8 *D_8009B1C8;
extern u8 *D_8009B1F0[2];
extern u8 *D_8009B1F8;
extern u8 D_8009B1D5;
#endif
extern u8 D_8009B164;
extern u16 D_8009B16C;
extern u8 D_8009B174;
extern u8 D_800EB224[];
extern VoidFn D_80090998[];
extern u16 D_8009B23A;
extern u16 D_8009B162;
/* func_800240B0 reaches these three through the assembler's bare form while
 * keeping %gp_rel on the one- and two-byte symbols beside them, so they carry
 * a declared size of four and the unit assembles at -G2. The size is a codegen
 * knob; see the -G-threshold section of DECISIONS.md. */
#ifdef D_8009B246_SIZED
extern u16 D_8009B246[2];
extern u8 D_8009B24B[4];
#else
extern u16 D_8009B246;
extern u8 D_8009B24B;
#endif
extern u8 D_8009B1D4;
extern s8 D_8009B160;
extern s8 D_8009B1D6;
extern s8 D_8009B1D7;
extern u8 *D_8009B22C;
/* Two independent symbols; one guard each, because func_80030F40 wants both
 * as scalars and func_8002DC38 wants D_8009B368 sized while leaving
 * D_8009B36A alone. */
#ifdef D_8009B36A_IS_SCALAR
extern u16 D_8009B36A;
#else
extern u16 D_8009B36A[];
#endif
#ifdef D_8009B368_SIZED
/* Two bytes so an assembler at -G1 treats it as non-small and expands the bare
 * store through $at, while the one-byte D_8009B26C beside it keeps %gp_rel.
 * The size is a codegen knob; see DECISIONS.md. */
extern u8 D_8009B368[2];
#elif defined(D_8009B368_IS_SCALAR) || defined(D_8009B36A_IS_SCALAR)
extern u8 D_8009B368;
#else
extern u8 D_8009B368[];
#endif
#ifdef D_8009B33A_IS_VOLATILE
extern volatile u16 D_8009B33A;
#else
extern u16 D_8009B33A;
#endif
extern u8 D_8009B327;
extern u8 D_8009B336;
#ifdef D_8009B34D_SIZED
extern s8 D_8009B34D[4];
#elif defined(D_8009B34D_IS_AGGREGATE)
extern s8 D_8009B34D[];
#else
extern s8 D_8009B34D;
#endif
/* Aggregate by default; files that need the bare form so the *assembler*
 * expands it through $at define D_8009B363_IS_SCALAR first. */
#ifdef D_8009B363_IS_SCALAR
extern u8 D_8009B363;
#else
extern u8 D_8009B363[];
#endif
/* Scanned in 0x70-byte records; only the halfword at +8 is known. */
typedef struct {
    s16 unk0;
    s16 unk2;
    u8 unk4[4];
    u16 flags;     /* +0x08 */
    u8 unkA[0x1A];
    ObjFn unk24;   /* +0x24 -- called with the record as its argument by
                    * func_80040CAC, which walks the list through unk2. */
    s32 unk28;     /* +0x28 */
    u8 unk2C[0x44];
} Slot70;

extern Slot70 D_800F0548[];
extern Slot70 D_800EFE48[];
#ifdef D_80010000_SIZED
/* Eight bytes it does not have, for the same reason as D_800EAE98: at -G4 the
 * symbol is non-small, so the `lui`/`lw` pair the assembler expands stays in
 * one register (func_8002FD10). */
extern u8 *D_80010000[2];
#elif defined(D_80010000_IS_AGGREGATE)
extern u8 *D_80010000[];
#else
/* 48-byte record: func_80045BE8 appends one with a struct assignment,
 * which is where the four-word block-move loop comes from. */
typedef struct {
    s32 w[12];
} Rec48;

extern u8 *D_80010000;
#endif
extern u8 D_800E9D90[];
/* Walked backwards in 0x4C-byte records from index 2; only the signed byte
 * at +0x30 is known. Declared as an array so the base lands in a register
 * before the element offset -- 0x98 is exactly two records. */
typedef struct {
    s32 w[12];      /* 0x00 */
    s8 unk30;
    u8 unk31;
    u8 unk32;
    u8 unk33[7];
    u8 unk3A;
    u8 unk3B;
    u8 unk3C[0x10];
} Rec4C;

extern Rec4C D_800EB010[];
/* Opcode handlers for the 0xF0..0xFF escapes, indexed by op ^ 0xFF; they
 * return -1 to stop the interpreter loop, so they are not ObjFn. */
extern s32 (*D_80090FEC[])(u8 *);
extern ObjFn D_80090F68[];
/* Dispatch table func_80070650 runs, indexed by the byte reader. */
extern ObjFn D_800916E0[];
/* Dispatch table func_80033BE8 indexes with the low six bits of a state word. */
extern ObjFn D_80090DF8[];
extern u8 D_8009B2EA;
extern s32 D_8009B2EC;
extern u8 D_8009B2B4;
extern u8 D_8009B2B5;
extern u8 D_8009B2B6;
extern u16 D_8009B2DE;
extern u8 *D_8009B2E4;
extern u8 D_8009B2F0;
extern u8 D_8009B2E9;
extern u8 D_8009B2E8;
/* Data Crystal RAM map, UNVERIFIED: debug menu scene ID, or sound ID */
extern u16 D_8009B2C8;
extern u8 D_8009B2DC;
extern u8 D_8009B2B8;
extern u8 D_8009B2C0;
/* func_800307B8 passes its address to func_80030250 through cc1psx's own
 * %hi/%lo pair, so unsized. */
extern u8 D_80090CB4[];
/* func_800307B8's saved/live pairs: C4/C8, C6/CC, DA/CA. */
extern u16 D_8009B2C4;
extern u16 D_8009B2C6;
extern u16 D_8009B2CA;
extern u16 D_8009B2CC;
extern u16 D_8009B2DA;
extern u8 D_8009B2C1;
extern u8 D_8009B2C2;
extern u8 D_8009B2E0;
extern u8 D_800117C8[];
/* .rodata halfwords. func_80049FB4 indexes it as rows of 128 with a row
 * number taken modulo 12 -- twelve rows is what the code implies, not
 * something measured against the data. */
extern u16 D_80010834[];
/* Sixteen words of .rodata, indexed by a pad code's high nibble. */
extern s32 D_80011484[];
/* Same knob as D_8009B142 below: two bytes under the guard, so that an
 * assembler at -G1 expands the reference through $at while the one-byte
 * gp-relative symbols in the same unit stay small (func_80013154). */
#ifdef D_8009B14A_SIZED
extern u8 D_8009B14A[2];
#else
extern u8 D_8009B14A;
#endif
#ifdef D_8009B14B_SIZED
extern u8 D_8009B14B[2];
#else
extern u8 D_8009B14B;
#endif
#ifdef D_8009B14C_SIZED
extern u8 D_8009B14C[2];
#else
extern u8 D_8009B14C;
#endif
/* Word-entry lookup table walked by func_8003BC40: the low halfword is the
 * key and a zero word terminates it. */
extern u32 D_801D9000[];
/* A table of four-byte entries terminated by a zero word: a big-endian
 * halfword key and two more bytes. Searched by func_8003B5C8. */
extern u8 D_801D9004[];
extern s16 D_801DA000[];
extern u8 D_801D9174[];
/* Alias for D_801D9174; see config/symbol_aliases.txt. */
extern u8 KeyTable_801D9174[];
extern s32 D_8009B3B8;
/* Source block func_8003D03C copies from. */
extern u8 D_801D4000[];
extern u8 D_8009B3EE;
extern u8 *D_8009B3D8;
extern u8 D_801B125A[];
extern s32 D_800E9E90[];
/* Data Crystal RAM map, UNVERIFIED: shuffled deck (player), 80 bytes */
extern u8 D_80177FE8[];
/* Aggregate by default; func_8002892C reaches it gp-relatively and defines
 * D_8009B254_IS_SCALAR. */
#ifdef D_8009B254_SIZED
extern u8 D_8009B254[4];
#elif defined(D_8009B254_IS_SCALAR)
extern u8 D_8009B254;
#else
extern u8 D_8009B254[];
#endif
extern s8 D_8009B345;
extern u8 D_8009B34C;
/* A handler pointer, cleared by func_80037CE0 and called by func_80038E1C. */
extern ObjFn D_8009B340;
extern s32 D_801D4244[];
extern s16 D_801D4D8E[];
extern u8 D_801D5708[];
extern u8 D_800EB15C[];
extern u8 D_800F2B20[];
#ifdef D_8009B142_SIZED
extern u8 D_8009B142[2];
#elif defined(D_8009B142_IS_AGGREGATE)
extern u8 D_8009B142[];
#else
extern u8 D_8009B142;
#endif
#ifdef D_8009B143_SIZED
extern u8 D_8009B143[2];
#elif defined(D_8009B143_IS_AGGREGATE)
extern u8 D_8009B143[];
#else
extern u8 D_8009B143;
#endif
#ifdef D_8009B144_SIZED
extern u8 D_8009B144[2];
#elif defined(D_8009B144_IS_AGGREGATE)
extern u8 D_8009B144[];
#else
extern u8 D_8009B144;
#endif
/* Data Crystal RAM map, UNVERIFIED: read by the duel-end path (wiki gives a function offset that does not resolve to any boundary in asm/nonmatchings -- unresolved) */
#ifdef D_8009B360_IS_SCALAR
extern s8 D_8009B360;
#else
extern s8 D_8009B360[];
#endif
extern u8 D_800F5918[];
extern u8 D_801A8000[];
extern u8 D_801B122B[];
extern u8 D_801B1238[];
extern u8 D_801D1200[];
extern u8 D_801D160C[];
extern s32 D_801D5608[];
/* Data Crystal RAM map, UNVERIFIED: selected card ID */
extern s16 D_8009B338;
extern u8 D_8009B320;
extern u8 D_801D07DC[];
#ifdef D_8009B3D4_SIZED
extern u8 D_8009B3D4[4];
#else
extern u8 D_8009B3D4[];
#endif
extern u16 D_801D07BC[];
/* 0x64-byte records. Declared by record type so a scaled index cannot be
 * reassociated past the base; see the base-formation recipe in DECISIONS.md. */
typedef struct {
    u8 unk0[0x28];
    s32 unk28;
    s32 unk2C;
    s32 unk30;
    s16 unk34;
    s16 unk36;
    s16 unk38;
    s16 unk3A;
    u8 unk3C[0x17];
    u8 unk53;
    u8 unk54;
    u8 unk55[2];
    u8 unk57;
    u8 unk58;
    u8 unk59;
    u8 unk5A;
    u8 unk5B;
    s16 unk5C;
    s16 unk5E;
    u8 unk60;
    u8 unk61;
    u8 unk62[2];
} Rec64;

extern Rec64 D_800EB0F8[];
extern u16 D_8009B234;
extern u16 D_8009B236;
/* func_80012B50 stores it through $at while four-byte gp-relative symbols in
 * the same unit stay small, so it carries a declared size of eight and the
 * unit assembles at -G4. The threshold is `<=`: four would still be small. */
/* The object is a *byte* -- func_80012B50 stores it with `sb` -- but the plain
 * arm keeps `u16` on purpose: func_8002DC38 only takes its address, and it
 * assembles at -G1, where a one-byte symbol becomes small data and the `la`
 * collapses from two instructions to one. Declaring the truth here costs that
 * function an instruction. The size is a codegen knob in both arms. */
#ifdef D_8009B230_SIZED
extern u8 D_8009B230[8];
#else
extern u16 D_8009B230;
#endif
extern u8 D_8009B4A8[];
extern u8 D_800E9EC0[];
extern s32 D_8009B0B4;
extern u8 D_80178130[];
extern u8 D_8017808C[];
extern u8 D_8018C2D8[];
extern u8 D_8018C7D8[];
extern u8 D_80177EA4[];
/* Data Crystal RAM map, UNVERIFIED: player's hand, 30 bytes */
extern u8 D_801A7E20[];
extern u8 D_8015C424[];
extern s16 D_800908A0[];
extern s8 D_8015C410[];
extern u8 D_801A7AD8[];
/* D_801A7AD8 + 0x8C, i.e. record 5 of the same 28-byte table, under its own
 * splat symbol; func_8002C9B4 walks it and D_801A7B64+0x1A4 in lockstep. */
extern u8 D_801A7B64[];
/* Ten-byte records: an id halfword, three lookup halfwords and a result. */
extern u8 D_801799D8[];
extern u16 D_800F2B22[];
extern u8 D_800E9EA7[];
extern s32 D_800E9EA8[];
extern u8 D_801DC000[];
extern u8 *D_8009078C[];
extern u8 D_800E9DF0[];
/* The size is a codegen knob rather than a fact, so it sits behind a guard
 * like every other per-file disagreement here: func_800136E4 assembles at -G2,
 * where a symbol bigger than two bytes is not small data, so cc1psx's bare
 * `la` gets expanded by the assembler through the destination register -- one
 * instruction at schedule time, which is what stops the %hi being hoisted out
 * of the loop the way retail does not. */
#ifdef D_80010038_SIZED
extern u8 D_80010038[4];
#else
extern u8 D_80010038[];
#endif
extern u8 D_8009B0E0;
extern u8 D_8017A1D8[];
/* Twelve-byte records. Declared as an array of the record type so the index
 * scales naturally; see the base-formation notes in docs/DECISIONS.md. */
typedef struct {
    s16 unk0;
    u8 unk2[4];
    u16 unk6;
    s8 unk8;
    u8 unk9[3];
} Rec12;

/* 0x2D0 halfword weights, walked as a running total by func_800243F4.
 * Tier 0 of a tiered table: func_80021810 runs the SAME weighted pick --
 * `(func_8008E590() & 0x7FF) + 1` against a running total -- over
 * D_8017878C + tier * 1460, and D_8017878C - D_801781D8 is exactly 1460.
 * The stride is measured from that function's own shift chain
 * (8a, 9a, 72a, 73a, 292a, 365a, 1460a), not assumed. */
extern u8 D_801781D8[];
extern Rec12 D_801AB000[];
extern s16 D_800EFE3A[];
extern s16 D_800EFE3C[];
extern s16 D_800EFE44[];
extern s16 D_800EFE3E[];
extern s16 D_800EFE40[];
/* The second halfword of the same object, and splat gives it its own symbol
 * because func_80041068 reaches it directly. Written as D_800EFE40[1] the
 * relocation comes out `%lo(D_800EFE40+2)`, which is the same address and a
 * different symbol -- two phantom differences. */
extern s16 D_800EFE42[];
extern u8 D_8009AF40[];
extern u8 D_800907D8[];
/* Two tables of per-card display flags, indexed by the BCD card id decoded
 * as `((n >> 4) & 0xF) * 10 + (n & 0xF)`: six bytes per entry at 0xC00 and
 * two at 0xBA8 (func_8002E128). */
extern u8 D_80090C00[];
extern u8 D_80090BA8[];
/* The debug format string "             MAP = %02X\n". */
extern u8 D_80090D0C[];
extern u8 D_801D0200[];
extern u8 D_801D0250[];
extern u8 D_8009B114;
/* Eight bytes under the guard, four in truth. func_8003C120 assembles at -G4
 * for D_8009B0F4's sake and needs this one non-small at that threshold too,
 * or every reference comes out one instruction short of retail's %hi/%lo
 * pair. Its sibling func_8003C328 is the counterexample: there only SOME of
 * the references want expanding, so the guard makes it worse. */
#ifdef D_8009B118_SIZED
extern s32 D_8009B118[2];
#else
extern s32 D_8009B118;
#endif
extern u8 *D_800101D8;
extern u8 D_801AF000[];
extern u8 D_801AF800[];
extern u8 D_8009B110;
extern volatile u16 D_8009B100;
extern s32 D_8009B104;
extern u8 D_8009B108;
extern s32 D_8009B11C;
/* func_80046768 stores both through `lui $at` while the four-byte pointers
 * beside them keep %gp_rel, and the widths are equal, so no real threshold
 * separates them: the SIZED arms declare eight bytes, which still clears
 * cc1psx's own -G8 (so the bare symbol survives) but not an `as -G4`. */
#ifdef D_8009B120_SIZED
extern s32 D_8009B120[2];
#else
extern s32 D_8009B120;
#endif
#ifdef D_8009B0F0_SIZED
extern s32 D_8009B0F0[2];
#else
extern s32 D_8009B0F0;
#endif
extern s32 D_8009B138;
/* func_8003798C reaches it through %hi/%lo, everyone else gp-relatively. */
#ifdef D_8009B134_SIZED
extern s32 D_8009B134[2];
#elif defined(D_8009B134_IS_AGGREGATE)
extern s32 D_8009B134[];
extern s32 Base2_8009B134[];
#else
extern s32 D_8009B134;
#endif
extern u16 D_8009B32E;
extern u8 D_8009B165;
extern u8 *D_8009B1E8;
extern s32 D_8009B10C;
extern s32 D_8009B12C;
extern u16 D_8009B124;
extern s32 D_8009B0E8;
extern s32 D_8009B130;
extern s32 D_8009B0FC;
#ifdef D_8009B374_IS_SCALAR
extern u16 D_8009B374;
#else
extern u16 D_8009B374[];
#endif
#ifdef D_8009B370_SIZED8
/* Eight bytes it does not have, so the reference is a single bare pseudo:
 * cc1psx will not hoist a bare symbol's memory access into a delay slot the
 * way it hoists half of its own %hi/%lo pair (func_8002CEE8). */
extern u16 D_8009B370[4];
#elif defined(D_8009B370_IS_SCALAR)
extern u16 D_8009B370;
#else
extern u16 D_8009B370[];
#endif
#ifdef D_8009B372_IS_SCALAR
extern u16 D_8009B372;
#else
extern u16 D_8009B372[];
#endif
#ifdef D_8009B369_SIZED8
/* Eight bytes it does not have: cc1psx keeps the bare symbol and an assembler
 * below -G8 expands it, so the reference is one instruction to the scheduler
 * (func_8002CEE8). */
extern u8 D_8009B369[8];
#elif defined(D_8009B369_IS_SCALAR)
extern u8 D_8009B369;
#else
extern u8 D_8009B369[];
#endif
/* func_80040588 reaches it `%gp_rel`, which needs the scalar form: as an
 * unsized array cc1psx emits a %hi/%lo pair, gcc hoists the %hi out of the
 * loop into a callee-saved register, and the function is five instructions
 * long and one saved register too many. */
#ifdef D_8009B424_IS_VOLATILE
extern volatile s32 D_8009B424;
#elif defined(D_8009B424_IS_SCALAR)
extern s32 D_8009B424;
#else
extern s32 D_8009B424[];
#endif
extern u8 D_8009AF0C;
/* Scalar by default; func_80037110 reaches it %hi/%lo and defines
 * D_8009B09C_IS_AGGREGATE. */
#ifdef D_8009B09C_IS_AGGREGATE
extern volatile s32 D_8009B09C[];
#else
extern volatile s32 D_8009B09C;
#endif
extern u8 D_8009B0C3;
/* Non-volatile in the aggregate form: func_8003D0F4 stores it once and
 * volatile blocks the bare-symbol form the assembler expands through $at. */
#ifdef D_8009B0C4_SIZED
/* Eight bytes so that an `as -G4` unit treats it as non-small and expands the
 * bare reference through the destination register, while the four-byte
 * D_8009B3B8 beside it keeps %gp_rel (func_8003D03C). */
extern volatile s32 D_8009B0C4[2];
#elif defined(D_8009B0C4_IS_AGGREGATE)
extern s32 D_8009B0C4[];
#else
extern volatile s32 D_8009B0C4;
#endif
#ifdef D_8009B0C8_IS_AGGREGATE
extern volatile s32 D_8009B0C8[];
#else
extern volatile s32 D_8009B0C8;
#endif
/* func_80013154 reaches it gp-relatively; the array arm is for the units that
 * take its address. */
#ifdef D_8009B0A3_SIZED8
/* Eight bytes it does not have. cc1psx at -G8 still sees 8 <= 8 and emits the
 * bare symbol; an assembler at -G1 sees 8 > 1 and expands the store through
 * $at, which is what func_8002CEE8 has while the one-byte D_8009B26C and
 * D_8009B26E beside it keep %gp_rel. */
extern u8 D_8009B0A3[8];
#elif defined(D_8009B0A3_IS_SCALAR)
extern u8 D_8009B0A3;
#else
extern u8 D_8009B0A3[];
#endif
extern u8 D_8009B0A0;
extern u8 D_8009B0A1;
extern u8 D_8009B0A2;
extern u8 D_8009B0A8;
extern u8 D_8009B0AD;
extern u8 D_8009B0D0;
extern u8 D_800FE048[];
extern u8 D_800FE0A8[];
#ifdef D_8009B0AC_SIZED8
/* Eight bytes it does not have, so that at `as -G4` the reference is bare and
 * the assembler's expansion keeps the pair in one register (func_8002E730). */
extern u8 D_8009B0AC[8];
#elif defined(D_8009B0AC_IS_AGGREGATE)
extern u8 D_8009B0AC[];
#else
extern u8 D_8009B0AC;
#endif
/* func_80012DB4 reaches this gp-relatively AND re-reads it every iteration of
 * its wait loop, next to the volatile D_8009B0C8 -- without volatile gcc hoists
 * this load out of the loop and the loop head moves. */
#ifdef D_8009B0C0_IS_VOLATILE
extern volatile u8 D_8009B0C0;
#elif defined(D_8009B0C0_SIZED)
/* Two bytes so an assembler at -G1 treats it as non-small and expands the bare
 * store through $at, while the one-byte D_8009B26C in the same unit keeps
 * %gp_rel (func_8002D180). The size is a codegen knob; see DECISIONS.md. */
extern u8 D_8009B0C0[2];
#elif defined(D_8009B0C0_IS_SCALAR)
extern u8 D_8009B0C0;
#else
extern u8 D_8009B0C0[];
#endif
/* Scalar and gp-relative in func_80012B50 and func_80012DB4; func_80039794
 * reaches it %hi/%lo and defines D_8009B0C1_IS_AGGREGATE. */
#ifdef D_8009B0C1_IS_AGGREGATE
extern u8 D_8009B0C1[8];  /* a size it does not have: 8 > the -G4 this
                           * file assembles at, so the reference stays bare
                           * and gcc has no %hi to hoist out of the loop */
#else
extern u8 D_8009B0C1;
#endif
extern u16 D_8009B098;
/* Volatile in func_80012B50, which sets it beside the volatile D_8009B0C8 and
 * D_8009B09C and where retail keeps all four stores in source order -- which
 * only happens if this one is volatile too, otherwise gcc sinks the
 * non-volatile ones past the volatile ones.
 * Checked for consistency rather than assumed: func_80012DB4, the only other
 * scalar user, matches either way, so a single volatile declaration for the
 * whole program is consistent with everything measured. func_80037A58 takes
 * the aggregate arm and is untouched by this. */
#ifdef D_8009B0CC_IS_VOLATILE
extern volatile s32 D_8009B0CC;
#elif defined(D_8009B0CC_IS_AGGREGATE)
extern s32 D_8009B0CC[];
#else
extern s32 D_8009B0CC;
#endif
/* func_8003CBE8 reaches these two gp-relatively. */
#ifdef D_8009B39C_IS_SCALAR
extern u8 D_8009B39C;
#else
extern u8 D_8009B39C[];
#endif
#ifdef D_8009B3A2_IS_SCALAR
extern u8 D_8009B3A2;
#else
extern u8 D_8009B3A2[];
#endif
extern u8 *D_8009B328;
extern ObjFn D_80090EAC[];
extern u8 D_801D1880[];
extern u8 *D_8009B3E0;
extern u16 D_8009B322;
extern u16 D_8009B348[2];
extern s8 D_800909D4[][6];
extern VoidFn D_80090A5C[];
extern u8 D_80090AD4[];
extern VoidFn D_80090B3C[];
extern VoidFn D_80090B64[];
extern u8 D_801E0000[];
extern s32 D_8009B460;
extern u8 D_80010784[];  /* "SD_bgm.dat" */
extern u8 D_80010790[];  /* "SD_se.dat" */
extern u8 D_8001079C[];  /* "MASTER.XA" */
extern TickFn D_80090CAC[];
extern u8 D_80090E58[];
#ifdef D_8009B408_SIZED
/* Eight bytes, so any assembler -G below 8 treats it as non-small and expands
 * the bare reference through $at while the narrower symbols in the same unit
 * keep %gp_rel. Two users at different thresholds: func_8003C7A0 at -G1
 * (one-byte neighbours) and func_8003D03C's abandoned -G4 attempt (four-byte
 * ones). The size is a codegen knob; see DECISIONS.md. */
extern s8 D_8009B408[8];
#elif defined(D_8009B408_IS_AGGREGATE)
extern s8 D_8009B408[];
extern s8 Base2_8009B408[];
extern s8 Base3_8009B408[];
#else
extern s8 D_8009B408;
#endif
extern u8 D_800F2848[];
/* The halfword two bytes into D_800F2848, under its own name: func_8001F364
 * reaches it through %hi/%lo of this symbol, which is how splat lists it. */
extern s16 D_800F284A[];
extern u8 D_800F2878[];
extern u8 D_801AC000[];
extern u8 D_800EFE38[];
extern VoidFn D_80090FB0[];
extern u8 D_80090FCC[];
extern u8 D_80090FDC[];
extern u16 D_8009B410;
extern u16 D_8009B412;
extern u8 D_8009151C[];
extern u8 *D_800E9EB4[];
extern u8 D_80090800[];
extern u8 D_801D4200[];
extern u8 D_800E9E18[];
/* The second function inside the func_8002DD74 listing; splat has not split
 * it yet, so it is only reachable by address. func_8002DF2C passes it as a
 * callback. */
extern u8 D_800EA1E8[];
extern u8 D_800E9E60[];
extern s32 D_8009B440;
extern s32 D_8009B444;
/* Aggregate by default (four functions reach it through %hi/%lo);
 * func_800440B4 reaches it gp-relatively. */
/* func_80044038 spins on it and then tests it again, so that unit wants the
 * volatile form as well as the scalar one. */
#ifdef D_8009B450_IS_VOLATILE
extern volatile s32 D_8009B450;
#elif defined(D_8009B450_IS_SCALAR)
extern s32 D_8009B450;
#else
extern s32 D_8009B450[];
#endif
extern u8 D_8009B437;
extern u8 D_8009B43C;
extern u8 D_8009B43D;
extern s8 D_8009B43E;
extern s8 D_8009B44E;
extern u8 D_8009B44F;
extern u8 D_800F39B0[];

/* --- scalars belonging to units built with -G0 ---------------------------- */
/*
 * These are ordinary scalars, but the functions touching them reach them
 * with %hi/%lo rather than gp-relative, so those units were compiled with
 * -G0. The declaration here stays a plain scalar; it is the *function* that
 * carries the -G0 override (see PER_FUNC_FLAGS in tools_src/build.py).
 */

#ifdef D_8009B362_SIZED8
/* Eight bytes it does not have, so cc1psx keeps the bare symbol (8 <= its own
 * -G8) and an assembler at -G1 expands it -- one instruction to the
 * delay-slot filler either way, which is what stops func_8002CEE8 hoisting a
 * `lui %hi` into a branch slot retail leaves as a `nop`. */
extern u8 D_8009B362[8];
#else
extern u8 D_8009B362[];
#endif
/* Data Crystal RAM map, UNVERIFIED: opponent ID */
#ifdef D_8009B361_IS_SCALAR
extern s8 D_8009B361;
#elif defined(D_8009B361_IS_SIZED)
/* Eight bytes it does not have, so it clears an assembler -G4 and cc1psx's
 * bare reference survives as a macro: see func_800175A0, which tests it on
 * three paths and needs each `lui %hi` to be its own unhoistable instruction. */
extern s8 D_8009B361[8];
#else
extern s8 D_8009B361[];
#endif
/* Holds a callback; reached through $at, so its unit was built -G0. */
extern void (*D_8009B128)(void);
extern u16 D_8009B28C;
/* Set to 0 on entry to func_8002FD10 and to func_8002E3FC's result on the
 * way out, both gp-relative. */
extern u8 *D_8009B2A0;
extern u16 D_8009B2A4;
/* Reached gp-relative in most files but through %hi/%lo in func_8001BD48,
 * which also needs gp-relative access to another symbol -- so -G0 is not an
 * option for it and the *declaration* has to differ per file, exactly as it
 * would have in the original build's per-unit headers. Define the guard before
 * including common.h to get the aggregate form in one file only.
 *
 * This is the third knob for the same symptom, alongside -G0 and declaring a
 * symbol unsized globally; see the -G0-prediction section of DECISIONS.md. */
/* Two independent knobs, so four arms rather than a chain: a file that wants
 * the aggregate form *and* the re-reads would silently lose the volatile if
 * these shared one #elif ladder. func_8003C7A0 tests five different bits and
 * retail loads it afresh for every one; without volatile gcc commons the lot
 * into a single register. */
#ifdef D_8009B398_SIZED_VOLATILE
/* Eight bytes it does not have. func_800307B8 reads it three times with no
 * store between -- so volatile -- and needs the non-small form while the one-
 * and two-byte gp scalars around it stay %gp_rel, which puts the size in the
 * window `4 < N <= 8` at `as -G4`. */
extern volatile u16 D_8009B398[4];
#elif defined(D_8009B398_IS_AGGREGATE)
#ifdef D_8009B398_IS_VOLATILE
extern volatile u16 D_8009B398[];
#else
extern u16 D_8009B398[];
#endif
#elif defined(D_8009B398_IS_VOLATILE)
extern volatile u16 D_8009B398;
#else
extern u16 D_8009B398;
#endif
extern s32 D_800E9D98;
extern s32 D_80093788;
extern s32 D_800F5F80;
extern s32 D_800F5F84;
extern s32 D_800F5F88;
extern s32 D_800F5F8C;

extern s32 D_800F5EE8;
extern s32 D_800938BC;
extern s32 D_80093880;
extern s32 D_800FE000;
extern s32 D_800FE418;
extern s32 D_800FE41C;
extern s32 D_800FE420;

extern u8 D_800938AC;
extern u8 D_800938AD;
extern u8 D_800938B2;
extern u8 D_800938B3;
extern u8 D_80093898;
extern u8 D_8009466A;

extern s16 D_800FE0CC;

/* Pointers into larger runtime structures. Reached gp-relative from one
 * unit and via %hi/%lo from another, so the declaration stays a plain
 * scalar and the per-function -G override decides which form is emitted. */
/* Scalar by default; func_8004C84C reaches it %hi/%lo and defines
 * D_8009B458_IS_AGGREGATE. */
#ifdef D_8009B458_IS_AGGREGATE
#ifdef D_8009B458_IS_VOLATILE
extern u8 *volatile D_8009B458[];
#else
extern u8 *D_8009B458[];
#endif
extern u8 *Base2_8009B458[];
#else
extern u8 *D_8009B458;
#endif
extern u8 Base2_8009B364[];
/* Reached %hi/%lo from func_80048C0C's unit and gp-relatively elsewhere; see
 * the per-file declaration knob in docs/DECISIONS.md. */
extern u8 *Base2_8009B45C[];
extern u8 *Base3_8009B45C[];
extern u8 *Base4_8009B45C[];
#ifdef D_8009B45C_IS_AGGREGATE
extern u8 *D_8009B45C[];
#else
extern u8 *D_8009B45C;
#endif

/* --- more small data ------------------------------------------------------ */

extern u8 D_8009AF98;
extern s8 D_8009AF99;
extern s8 D_8009AF9A;
extern u8 D_8009B4A0;
extern u8 D_8009B4A1;
extern u8 D_8009B4A2;

extern u8 D_8009B37C;
extern s8 D_8009B384;
extern s32 D_8009B390;
extern s32 D_8009B3A8;
extern u8 D_800EF668[];
extern s32 D_8009B3B0;
extern s32 D_8009B3B4;
#ifdef D_8009B394_IS_VOLATILE
/* func_8003700C reads it three times on one path and gcc CSEs a plain read;
   retail re-loads for each test. */
extern volatile u16 D_8009B394;
#else
extern u16 D_8009B394;
#endif
extern u16 D_8009B396;
extern u16 D_8009B39A;
extern u16 D_8009B39E;
extern u8 D_8009B32C;
extern u16 D_8009B3A0;
/* func_80023FBC reads it five times in a row and retail reloads each time,
 * which only a volatile does. */
#ifdef D_8009B3A4_IS_VOLATILE_SIZED
/* Eight bytes it does not have: func_80013360 needs the bare form for this
 * symbol while D_8009B098, also two bytes, stays gp-relative, so no real
 * threshold separates them -- see WORKFLOW's third dup-%hi branch. Volatile
 * for the same reason as the plain volatile arm below. */
extern volatile u16 D_8009B3A4[4];
#elif defined(D_8009B3A4_IS_VOLATILE)
extern volatile u16 D_8009B3A4;
#elif defined(D_8009B3A4_IS_AGGREGATE)
extern u16 D_8009B3A4[];
#else
extern u16 D_8009B3A4;
#endif
extern u16 D_8009B3A6;
extern u16 D_8009B3AC;
extern u16 D_8009B3FA;
extern u16 Base2_8009B3FA;
extern u8 D_8009B3DE;
extern u8 D_8009B3C1;
#ifdef D_8009B2F8_SIZED8
/* Same knob as D_8009B0A3 above, for the same unit. */
extern u8 D_8009B2F8[8];
#elif defined(D_8009B2F8_IS_AGGREGATE)
extern u8 D_8009B2F8[];
#else
extern u8 D_8009B2F8;
#endif
extern u8 D_8009B324;
extern u8 D_8009B325;
extern u8 D_8009B344;
extern u8 D_8009B34E;
extern u8 D_8009B355;
extern u8 D_8009B357;
extern u8 D_8009B3C7;
extern u8 D_8009B3CF;
extern u8 D_8009B3DD;
extern u16 D_8009B3CC;
/* Small-data table of halfwords: the retail code takes its address with
 * addiu $v1,$gp,%gp_rel(...), so it must stay inside the -G8 threshold. */
extern u16 D_8009AF74[4];
/* func_80058E1C reads it twice across a branch and gcc would keep the first
 * load in a register; the reads are what the function is. */
/* Handed to func_8004BAA0 by address; %hi/%lo, so unsized. */
extern u8 D_8009AF80[];
/* The three debug strings and the two flag bytes func_80022618 prints. */
extern u8 D_80010074[];
extern u8 D_80010090[];
extern u8 D_800100A8[];
/* Table func_8004A764 indexes by word. */
extern s32 D_80011434[];
/* func_80044278 and func_80044380 write these two gp-relatively before
 * handing off; halfword and word. */
extern u16 D_8009B44C;
extern s32 D_8009B430;
/* func_8003F758's four gp-relative fields and the buffer it clears. */
extern u8 D_800EFE18[];
extern u8 D_8009B3F9;
extern u16 D_8009B3C2;
extern u16 D_8009B3C4;
extern u8 D_8009B3DC;
extern s32 D_8009B3D0;
/* Handle blocks next to D_800F2AE0. */
extern s32 D_800F2AF0[];
extern s32 D_800F2B00[];
/* "bu%02X:%s" */
extern u8 D_80010538[];
extern u16 D_8009B434;
/* 1460 bytes per entry, walked as halfwords by func_80021810. */
/* Data Crystal RAM map, UNVERIFIED: SA-POW card drops, 1444 bytes */
extern u8 D_8017878C[];
/* Two signed byte counters func_8002A6B8 turns into a score. */
extern u8 D_8009B258;
extern u8 D_8009B259;
extern u8 D_8009AF2A;
extern u8 D_8009AF2C;
extern u8 D_8009AF2D;
/* func_8005C5D4 spins on this until it is set, then clears it: volatile, or
 * gcc commons the read with the guard and propagates the flag as zero. */
extern volatile u8 D_8009B062;
/* func_80012DB4 stores to both of these through $at -- the bare-symbol form --
 * where func_80058E1C reads D_8009AFA3 gp-relatively. */
#ifdef D_8009AFA3_IS_AGGREGATE
extern u8 D_8009AFA3[];
#else
extern u8 D_8009AFA3;
#endif
extern u8 Base2_8009AFA3;
extern u8 D_800F5768[];
extern s32 D_8009B074;
extern s32 D_8009B304;
extern s32 D_8009B310;
extern s32 D_8009B314;
extern s32 D_8009B300;
extern s32 D_8009B30C;
extern s32 D_8009B308;
extern s32 D_8009B0B8;
extern s32 D_8009B0A4;
extern s32 D_8009B0B0;
extern s32 D_8009B0BC;
extern s32 D_8009B0D4;
extern s32 D_8009AF08;
extern s32 D_8009B330;
#ifdef D_8009B350_IS_VOLATILE
extern volatile s32 D_8009B350;
#else
extern s32 D_8009B350;
#endif

/* Cursor advanced by the reader in func_80030050. */
extern u8 D_8009AF5C[];
extern s8 D_8009B37D;
extern u8 *D_8009B380;
extern u8 *D_8009B388;
extern u8 *D_8009B274;
extern u8 *D_8009B290;
extern s8 D_8009B2F1;
extern u8 D_8009B2B2;
#ifdef D_8009B365_SIZED
extern u8 D_8009B365[4];
#elif defined(D_8009B365_IS_SCALAR)
extern u8 D_8009B365;
#else
extern u8 D_8009B365[];
#endif
extern u8 D_80090D68[];

/* Table of 8-byte entries. */
extern u8 D_80091550[];
extern u8 D_80091570[];

/* Tables reached by address, so never small data. */
/* Read once by func_800154E4 through cc1psx's own %hi/%lo pair, so unsized. */
extern s32 D_800E9D94[];
extern u8 D_800E9EC8[];
/* Stored by func_80015310 through cc1psx's own %hi/%lo pair, so unsized. */
extern u8 D_800E9ECC[];
extern u8 D_800E9ECE[];
extern u8 D_800E9ECF[];
extern s32 D_8009B378;
typedef struct {
    u8 unk0[0x14];
    s16 unk14;
    u8 unk16[3];
    s8 unk19;
    u8 unk1A[6];
} Rec20;

extern u8 D_800E9F10[];
/* 112-byte records indexed by D_8009B1D5; func_8001B938 caches the current
 * one in D_8009B1B4. */
extern u8 D_800E9F48[];
extern s16 D_800E9D28[];
extern Rec20 D_800E9FF0[];
/* The last byte of D_800E9FF0[1] under its own name: func_800175A0 stores -1
 * there through %hi/%lo of this symbol and the record's own base for the
 * neighbouring store, so the two cannot share one materialisation. */
extern s8 D_800EA02F[];
typedef struct {
    u8 *unk0;
    u8 unk4[5];
    u8 unk9;
    u8 unkA[2];
} Rec0C;

extern Rec0C D_800EA030[];
extern u8 D_800EA0E8[];
extern u8 D_800EF658[];
extern u8 D_800F3938[];
extern u8 D_800F39F0[];
extern u8 D_800EAF08[];
extern u8 D_80090D28[];
extern u8 D_80090D44[];
#ifdef D_8009B0D8_IS_SCALAR
extern s32 D_8009B0D8;
#elif defined(D_8009B0D8_IS_SIZED)
/* Eight bytes it does not have: the size is a codegen knob. func_8003CCD8
 * reads one byte of it inside a loop and retail re-materialises the address
 * every iteration, which needs the bare form (one instruction to gcc, so not
 * hoistable) while the four-byte scalars around it stay gp-relative. A
 * declared size clears an assembler -G4 where the real four would not. */
extern u8 D_8009B0D8[8];
#else
extern s32 D_8009B0D8[];
#endif
/* Walked with a 0x1C stride, two bytes cleared per record. Declared as an
 * array of the record type so the base lands in a register before any
 * field offset -- see the two-field addressing note in docs/DECISIONS.md. */
typedef struct {
    /* The head is four words, not seventeen bytes. It has to be:
     * func_80039D64 assigns one whole record to another and retail expands
     * that with aligned lw/sw, which gcc only emits when the struct's own
     * alignment is 4. All-u8 members give alignment 1 and the copy comes
     * out lwl/lwr. Byte offsets are unchanged, so every other user of the
     * type is unaffected -- checked with try_func, not assumed. */
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    u8 unk10;    /* +0x10 */
    u8 unk11;    /* +0x11 */
    u8 unk12;
    u8 unk13;    /* +0x13 */
    u8 unk14;
    u8 unk15;    /* +0x15 */
    u8 unk16[2];
    u8 unk18;    /* +0x18 */
    u8 unk19[3];
} Rec1C;

extern Rec1C D_800EB288[];
/* Dispatch table indexed by a record's unk13 masked to 0x1F; four entries,
 * but the mask is what the source spells, so the array stays unsized. */
typedef void (*Rec1CFn)(Rec1C *, u8 *);
extern Rec1CFn D_80090F58[];
extern u8 D_800EF6B0[];
extern u8 D_800EF6E0[];
extern u8 D_801B0000[];
/* Data Crystal RAM map, UNVERIFIED: fusion table, 65536 bytes */
extern u16 D_8017C2D8[];
extern u8 D_801C0000[];
extern u8 D_801D5800[];
extern u8 D_801D0000[];
extern u8 D_800917F0[];
extern u8 D_800A5768[];
extern u8 D_800F2B50[];
extern u8 D_800F2C40[];
extern u8 D_800E9DB0[];
extern u8 D_800E9EF0[];
/* Reached as a base plus two halfword offsets, which is what a struct
 * access compiles to; a bare array lets gcc fold the first store's offset
 * into the %lo and form the base only for the second. */
typedef struct {
    s16 x;
    s16 y;
    s16 unk4;
    s16 unk6;
} ScreenPos;

extern ScreenPos D_800FE040[];
/* The retail code forms this object's base address and then reaches the
 * cursor at +8, which is what a struct field access compiles to -- reaching
 * it as D_800F5BE8[8] instead lets gcc fold the +8 into the %lo and comes
 * out one instruction short. */
typedef struct {
    u8 unk0[4];
    u8 *base;   /* +4 */
    u8 *cursor; /* +8 */
    u8 unkC[8];
    /* Return-address stack for nested routines: func_80070DA8 pops
     * cursor = stack[--depth] and prints "ERROR:Can't Return From Routine"
     * when depth is already zero. */
    u8 depth;   /* +0x14 */
    u8 unk15[3];
    u8 *stack[8];  /* +0x18 */
} ByteReader;

extern ByteReader D_800F5BE8[];
extern s16 D_800F5C88[];
extern u8 D_800F5C8B[];
/* printf format and assert strings from src/hirata/H_mctrl1.c. */
extern u8 D_800118AC[];
/* Head of the heap block list: {header, size} pairs, header bit 31 free,
 * bit 30 end-of-list, low 28 bits the address. */
extern u32 *D_80092BF0[];
/* Shift applied to the address before the block-list walk. */
extern u32 D_80092BB0[];
extern u32 D_80092B14[];
/* "check_point\n" and the "---- %d ----" banner from the same debug pair. */
extern u8 D_80011908[];
extern u8 D_80011918[];
extern u8 D_800118E4[];
extern u8 D_800118CC[];
extern u8 D_8009B084[];

/* --- more scalars in -G0 units -------------------------------------------- */

/* Reached via %hi/%lo from a -G0 unit and from a -G8 one, so these must
 * never be small data: declared unsized rather than as scalars. */
#ifdef D_8009B268_IS_SCALAR
extern u8 D_8009B268;
#else
extern u8 D_8009B268[];
#endif
/* Aggregate by default, because most users reach it through %hi/%lo. Files
 * that need the gp-relative form define D_8009B26C_IS_SCALAR first -- see the
 * per-file declaration note on D_8009B398. */
#ifdef D_8009B26C_SIZED
extern u8 D_8009B26C[4];
#elif defined(D_8009B26C_IS_SCALAR)
extern u8 D_8009B26C;
#else
extern u8 D_8009B26C[];
#endif
extern u8 D_8009B26E;
#ifdef D_8009B26D_IS_SCALAR
extern u8 D_8009B26D;
#else
extern u8 D_8009B26D[];
#endif
/* Passed to func_8008FB8C by func_8002D730. */
extern u8 D_800E9DC0[];
/* Aggregate by default; func_8002D62C reaches it gp-relatively. See the
 * per-file declaration note on D_8009B398. */
#ifdef D_8009B269_SIZED
extern u8 D_8009B269[8];
#elif defined(D_8009B269_IS_SCALAR)
extern u8 D_8009B269;
#else
extern u8 D_8009B269[];
#endif
extern s32 D_800938A0[];
extern u16 *D_80092A90;
extern s32 *D_80094770;
extern s32 *D_8009A0BC;
/* Scalar by default; func_80031354 reaches it %hi/%lo and defines
 * D_800EB184_IS_AGGREGATE. */
#ifdef D_800EB184_IS_AGGREGATE
extern u8 *D_800EB184[];
#else
extern u8 *D_800EB184;
#endif
#ifdef D_800FE240_IS_AGGREGATE
/* Reached through an explicit %hi/%lo pair in func_8005A8C4, where the scalar
 * form would go gp-relative and collapse to one instruction. */
extern s32 D_800FE240[];
#else
extern s32 D_800FE240;
#endif
extern s32 D_800947B8;
/* Reached through %hi/%lo, so unsized rather than a scalar. Nothing had
 * used it before func_80077090; if a gp-relative user turns up, guard it. */
extern u8 *D_80092B88[];
extern s32 D_800F8394[];
extern s32 D_800F8398[];
extern s32 D_800F5D70;
/* Eight bytes under the guard, four in truth: func_8005C1F4 needs it out of
 * small data while the four-byte D_8009B498 stays gp-relative, and 4 <= G < 4
 * is empty -- so inflate this side and assemble at -G4 (recipe branch 3). */
#ifdef D_800F5D44_SIZED
extern s32 D_800F5D44[2];
#else
extern s32 D_800F5D44;
#endif
extern s32 D_800F5D4C;
extern s32 D_800F5D6C;
extern s32 D_800FE424;
extern s32 D_800FE428;
extern s32 D_800FE42C;
extern s32 D_800FE430;
extern s32 D_800FE434;

#endif /* VARIABLES_H */
