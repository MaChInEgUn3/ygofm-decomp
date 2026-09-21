/* Variables from krystalgamer/memories-decomp, as the ported units in src/
 * declare them. Included ONLY by those units, like kg_types.h: a
 * non-ported unit never sees this file. Built by
 * tools_src/kg_decls.py fold-externs from the units' own inline copies,
 * in first-seen order over the sorted file names, each text once. A
 * symbol two ported units declare differently is NOT here -- that
 * disagreement is a codegen knob (.data, volatile, const, width,
 * array-versus-scalar) and it stays inline in the unit that wants it. */
#ifndef KG_VARIABLES_H
#define KG_VARIABLES_H

#include "kg_types.h"

extern u8 D_8009B318 __attribute__((section(".data")));
extern u16 D_8009B098;
extern DISPENV D_800E9D28;
extern u8 D_8009B0AC;
extern GraphicsFrameBuffer D_8009B4A8[];
extern GraphicsFrameBuffer *D_8009B0B4;
extern u8 D_800A5768[];
extern u8 D_8009B0AD;
extern u8 D_8009B0D0;
extern u8 D_8009B0A8;
extern u8 D_8009B141 __attribute__((section(".data")));
extern GsOT *D_800E9D90[4];
extern u8 D_8009AFA2 __attribute__((section(".data")));
extern volatile u8 D_8009B14A __attribute__((section(".data")));
extern volatile u8 D_8009B14B __attribute__((section(".data")));
extern volatile u8 D_8009B14C __attribute__((section(".data")));
extern DISPENV D_800FE0A8;
extern volatile u8 D_8009B0A1;
extern volatile u8 D_8009B0A2;
extern volatile u8 D_8009B0A3;
extern volatile u32 D_8009B0F4;
extern FileTransferDescriptor *D_8009AF18;
extern u32 *D_8009B0F8;
extern u8 D_8009B114;
extern s32 D_8009B138;
extern u16 D_8009B0EC;
extern volatile u16 D_8009B112;
extern FileTransferDescriptor D_800E9E60;
extern char D_8009B11C[1];
extern volatile u16 D_8009B100;
extern char D_8009B104[1];
extern MATRIX D_800FE148;
extern volatile u32 D_8009B0F4_abs __attribute__((section(".data")));
extern RECT D_800E9D70[2];
extern u16 D_8017A1D8[];
extern u16 D_8017C2D8[];
extern u8 D_801A9800[];
extern u8 *D_80010000 __attribute__((section(".data")));
extern u8 *D_800101DC __attribute__((section(".data")));
extern u16 D_8009B23A;
extern DuelSideState D_800E9FF0[2 ];

#endif /* KG_VARIABLES_H */
