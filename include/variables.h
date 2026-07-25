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

extern volatile u16 D_8009B112;

extern u8 D_8009AFA0;
extern u8 D_8009AFA4;
extern u8 D_8009AFA6;
extern u8 D_8009B063;
extern u8 D_8009B064;
extern u8 D_8009B078;
extern u8 D_8009B07B;
extern u8 D_8009B07C;
extern u8 D_8009B079;
extern s8 D_8009B07A;
extern u8 D_8009B141;
extern u8 D_8009B145;
extern u8 D_8009B248;
extern u8 D_8009B3C6;
extern u8 D_8009B2EB;
extern u8 D_8009B318;

extern u16 D_8009AF76;
extern u16 D_8009AF7A;
extern u16 D_8009AF92;
extern u16 D_8009AF96;
extern u16 D_8009B220;
extern u16 D_8009B27C;

/* Two words of PRNG state, mixed together by func_8003CE74. Eight bytes, so
 * still small data at -G8 even though func_8003CE74 takes its address. */
extern u32 D_8009AF64[2];
extern s32 D_8009AF68;

extern u8 D_8009B478;

/* --- aggregates reached with an explicit %hi/%lo pair --------------------- */
/* Declared unsized so they are never treated as small data. */

extern u8 D_800EAE90[];
extern u8 D_800F5C7F[];
extern u8 D_800F56A0[];
extern u8 D_800F56F0[];
extern u8 D_800FE148[];
extern u8 D_800FE348[];
extern u8 D_800938AE[];

extern s32 D_8009B400;
extern u8 D_8009B3EF;
extern u8 D_8009B3EB;
extern s32 D_800F5B98[];
extern u8 D_800EAE8F[];
extern u8 D_8009B260;
extern u8 D_8009B0D1[];
extern u8 D_801D3200[];
extern u8 D_80010384[];
extern u8 D_8009B3ED;
extern u8 D_8009B3C0;
extern u8 D_8009B364[];
extern u16 D_800F5C80[];
extern u8 D_8009AF94;
extern u8 D_800F5C82[];
extern u8 D_800F5C83[];
/* Read twice in a row by func_80015038, once per condition, so the
 * hardware register it shadows is not cached across the test. */
#ifdef D_8009B0F4_IS_AGGREGATE
extern volatile s32 D_8009B0F4[];
#else
extern volatile s32 D_8009B0F4;
#endif
/* A table of (threshold, value) halfword pairs, five per row: the retail
 * code indexes rows by arg0 * 20 and then walks pairs four bytes at a time. */
typedef struct {
    s16 threshold;
    s16 value;
} Threshold;

extern Threshold D_801798A8[][5];
extern u8 D_801AB00C[];
extern u8 D_8009B1D5;
extern u8 D_8009B164;
extern u16 D_8009B36A[];
extern u8 D_8009B368[];
extern u16 D_8009B33A;
extern u8 D_8009B363[];
/* Scanned in 0x70-byte records; only the halfword at +8 is known. */
typedef struct {
    u8 unk0[8];
    u16 flags;     /* +0x08 */
    u8 unkA[0x1E];
    s32 unk28;     /* +0x28 */
    u8 unk2C[0x44];
} Slot70;

extern Slot70 D_800F0548[];
extern Slot70 D_800EFE48[];
extern u8 *D_80010000;
/* Walked backwards in 0x4C-byte records from index 2; only the signed byte
 * at +0x30 is known. Declared as an array so the base lands in a register
 * before the element offset -- 0x98 is exactly two records. */
typedef struct {
    u8 unk0[0x30];
    s8 unk30;
    u8 unk31[0x1B];
} Rec4C;

extern Rec4C D_800EB010[];
extern u8 D_8009B2EA;
extern s32 D_8009B2EC;
extern u8 D_8009B2B4;
extern u8 D_8009B2B5;
extern u8 D_8009B2B6;
extern u8 D_8009B2E9;
extern u8 D_8009B2DC;
extern u8 D_8009B2B8;
extern u8 D_8009B2C0;
extern u8 D_8009B2C1;
extern u8 D_8009B2C2;
extern u8 D_8009B2E0;
extern u8 D_800117C8[];
extern u8 D_8009B14A;
extern u8 D_8009B14B;
extern u8 D_8009B14C;
extern u8 D_801D9174[];
/* Alias for D_801D9174; see config/symbol_aliases.txt. */
extern u8 KeyTable_801D9174[];
extern s32 D_8009B3B8;
extern s32 D_800E9E90[];
extern u8 D_80177FE8[];
extern u8 D_8009B254[];
extern s8 D_8009B345;
extern u8 D_8009B34C;
/* A handler pointer, cleared by func_80037CE0 and called by func_80038E1C. */
extern ObjFn D_8009B340;
extern u8 D_801D5708[];
extern u8 D_800F2B20[];
extern u8 D_8009B142;
extern u8 D_8009B143;
extern u8 D_8009B144;
extern s8 D_8009B360[];
extern u8 D_800F5918[];
extern u8 D_801A8000[];
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
extern u8 D_801A7AD8[];
extern u16 D_800F2B22[];
extern s32 D_800E9EA8[];
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

extern Rec12 D_801AB000[];
extern u8 D_800907D8[];
extern u8 D_801D0200[];
extern s32 D_8009B118;
extern u8 D_8009B110;
extern u8 D_8009B108;
extern s32 D_8009B120;
extern s32 D_8009B0F0;
extern s32 D_8009B134;
extern s32 D_8009B10C;
extern s32 D_8009B12C;
extern u16 D_8009B124;
extern s32 D_8009B0E8;
extern s32 D_8009B130;
extern s32 D_8009B0FC;
extern u16 D_8009B374[];
extern u16 D_8009B370[];
extern u16 D_8009B372[];
extern u8 D_8009B369[];
extern s32 D_8009B424[];
extern u8 D_8009B0C0[];
extern u8 D_8009B39C[];
extern u8 D_8009B3A2[];
extern u8 *D_8009B328;
extern ObjFn D_80090EAC[];
extern u8 D_801D1880[];
extern u8 *D_8009B3E0;
extern u16 D_8009B322;
extern u8 D_80090E58[];
extern s8 D_8009B408;
extern u8 D_800F2878[];
extern u8 D_800EFE38[];
extern u16 D_8009B410;
extern u16 D_8009B412;
extern s32 D_8009B440;
extern s32 D_8009B444;
extern s32 D_8009B450[];

/* --- scalars belonging to units built with -G0 ---------------------------- */
/*
 * These are ordinary scalars, but the functions touching them reach them
 * with %hi/%lo rather than gp-relative, so those units were compiled with
 * -G0. The declaration here stays a plain scalar; it is the *function* that
 * carries the -G0 override (see PER_FUNC_FLAGS in tools_src/build.py).
 */

extern s8 D_8009B361[];
/* Holds a callback; reached through $at, so its unit was built -G0. */
extern void (*D_8009B128)(void);
/* Reached gp-relative in most files but through %hi/%lo in func_8001BD48,
 * which also needs gp-relative access to another symbol -- so -G0 is not an
 * option for it and the *declaration* has to differ per file, exactly as it
 * would have in the original build's per-unit headers. Define the guard before
 * including common.h to get the aggregate form in one file only.
 *
 * This is the third knob for the same symptom, alongside -G0 and declaring a
 * symbol unsized globally; see the -G0-prediction section of DECISIONS.md. */
#ifdef D_8009B398_IS_AGGREGATE
extern u16 D_8009B398[];
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
extern u8 *D_8009B458;
/* Alias for D_8009B458; see config/symbol_aliases.txt. */
extern u8 *Base2_8009B458;
extern u8 *D_8009B45C;
/* Alias for D_8009B45C; see config/symbol_aliases.txt. */
extern u8 *Base2_8009B45C;

/* --- more small data ------------------------------------------------------ */

extern s8 D_8009AF9A;
extern u8 D_8009B4A0;
extern u8 D_8009B4A1;
extern u8 D_8009B4A2;

extern u16 D_8009B394;
extern u16 D_8009B396;
extern u16 D_8009B39A;
extern u16 D_8009B39E;
extern u16 D_8009B3A0;
extern u16 D_8009B3A4;
extern u16 D_8009B3A6;
extern u16 D_8009B3AC;
extern u16 D_8009B3FA;
extern u8 D_8009B3DE;
extern u8 D_8009B3C1;
extern u8 D_8009B2F8;
extern u8 D_8009B324;
extern u8 D_8009B325;
extern u8 D_8009B344;
extern u8 D_8009B357;
extern u8 D_8009B3C7;
extern u8 D_8009B3CF;
extern u8 D_8009B3DD;
extern u16 D_8009B3CC;
/* Small-data table of halfwords: the retail code takes its address with
 * addiu $v1,$gp,%gp_rel(...), so it must stay inside the -G8 threshold. */
extern u16 D_8009AF74[4];
extern u8 D_8009AFA3;
extern s32 D_8009B074;
extern s32 D_8009B304;
extern s32 D_8009B310;
extern s32 D_8009B314;
extern s32 D_8009B300;
extern s32 D_8009B30C;
extern s32 D_8009B0B8;
extern s32 D_8009B330;
extern s32 D_8009B350;

/* Cursor advanced by the reader in func_80030050. */
extern u8 *D_8009B290;

/* Table of 8-byte entries. */
extern u8 D_80091570[];

/* Tables reached by address, so never small data. */
extern u8 D_800E9EC8[];
extern u8 D_800EA0E8[];
extern u8 D_800F39F0[];
extern u8 D_800EAF08[];
/* Walked with a 0x1C stride, two bytes cleared per record. Declared as an
 * array of the record type so the base lands in a register before any
 * field offset -- see the two-field addressing note in docs/DECISIONS.md. */
typedef struct {
    u8 unk0[0x11];
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
extern u8 D_800EF6E0[];
extern u8 D_801D0000[];
extern u8 D_800917F0[];
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
} ByteReader;

extern ByteReader D_800F5BE8[];

/* --- more scalars in -G0 units -------------------------------------------- */

/* Reached via %hi/%lo from a -G0 unit and from a -G8 one, so these must
 * never be small data: declared unsized rather than as scalars. */
extern u8 D_8009B268[];
/* Aggregate by default, because most users reach it through %hi/%lo. Files
 * that need the gp-relative form define D_8009B26C_IS_SCALAR first -- see the
 * per-file declaration note on D_8009B398. */
#ifdef D_8009B26C_IS_SCALAR
extern u8 D_8009B26C;
#else
extern u8 D_8009B26C[];
#endif
extern u8 D_8009B26D[];
/* Aggregate by default; func_8002D62C reaches it gp-relatively. See the
 * per-file declaration note on D_8009B398. */
#ifdef D_8009B269_IS_SCALAR
extern u8 D_8009B269;
#else
extern u8 D_8009B269[];
#endif
extern s32 D_800938A0[];
extern u16 *D_80092A90;
extern s32 *D_80094770;
extern s32 *D_8009A0BC;
extern u8 *D_800EB184;
extern s32 D_800FE240;
extern s32 D_800947B8;
extern u8 *D_80092B88;
extern s32 D_800F8394[];
extern s32 D_800F8398[];
extern s32 D_800F5D70;
extern s32 D_800F5D4C;
extern s32 D_800F5D6C;
extern s32 D_800FE424;
extern s32 D_800FE428;
extern s32 D_800FE42C;
extern s32 D_800FE430;
extern s32 D_800FE434;

#endif /* VARIABLES_H */
