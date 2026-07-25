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

extern s32 D_8009AF64;
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

extern s32 D_8009B450[];

/* --- scalars belonging to units built with -G0 ---------------------------- */
/*
 * These are ordinary scalars, but the functions touching them reach them
 * with %hi/%lo rather than gp-relative, so those units were compiled with
 * -G0. The declaration here stays a plain scalar; it is the *function* that
 * carries the -G0 override (see PER_FUNC_FLAGS in tools_src/build.py).
 */

extern u16 D_8009B398;
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
extern u8 *D_8009B45C;

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
extern u8 D_8009B357;
extern u8 D_8009AFA3;
extern s32 D_8009B074;
extern s32 D_8009B304;
extern s32 D_8009B310;
extern s32 D_8009B314;
extern s32 D_8009B300;
extern s32 D_8009B30C;
extern s32 D_8009B350;

/* Cursor advanced by the reader in func_80030050. */
extern u8 *D_8009B290;

/* Table of 8-byte entries. */
extern u8 D_80091570[];

/* Tables reached by address, so never small data. */
extern u8 D_800E9EC8[];
extern u8 D_800EA0E8[];
extern u8 D_800F39F0[];
extern u8 D_800E9EF0[];
extern u8 D_800FE040[];
/* The retail code forms this object's base address and then reaches the
 * cursor at +8, which is what a struct field access compiles to -- reaching
 * it as D_800F5BE8[8] instead lets gcc fold the +8 into the %lo and comes
 * out one instruction short. */
typedef struct {
    u8 unk0[8];
    u8 *cursor;
} ByteReader;

extern ByteReader D_800F5BE8;

/* --- more scalars in -G0 units -------------------------------------------- */

/* Reached via %hi/%lo from a -G0 unit and from a -G8 one, so these must
 * never be small data: declared unsized rather than as scalars. */
extern u8 D_8009B26C[];
extern u8 D_8009B269[];
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
