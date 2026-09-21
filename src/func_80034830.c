/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/func_80034830.c, profile gcc_2_8_1_g8_split_psyq_gte.
 * The declarations above the function are the subset of that tree's headers
 * this unit needs, preprocessed and with symbols renamed to this tree's
 * spelling (func_ADDR, D_ADDR); their types are that tree's. Byte-identical
 * under the flag row in tools_src/build.py. */
#include "kg_types.h"
extern u32 D_8009B300;
extern u32 D_8009B30C;
extern SortedEntry *D_8009B310;
extern u32 D_8009B314;
void func_80033CF8(s32 dx, s32 dy, s32 dz);
extern u32 *D_800FE240 __attribute__((section(".data")));
u32 *func_80034830(GsARGUNIT_NORMAL *arg);
u32 *func_80061A84(GsARGUNIT_NORMAL *arg);
u32 *func_80034830(GsARGUNIT_NORMAL *arg)
{
    long z;
    u32 flags;
    u32 mask;
    CVECTOR *white;
    s32 *scr;
    s32 *flg;
    u32 *primp;
    PACKET *out;
    s32 n;
    u16 *rec;
    SVECTOR *vertop;
    SVECTOR *nortop;
    GsOT *tg;

    flags = D_8009B30C;
    if (flags & 8) {
        return func_80061A84(arg);
    }
    mask = 0xFFFFFF;
    white = (CVECTOR *)0x1F8003C0;
    scr = (s32 *)0x1F8003E0;
    primp = (u32 *)arg->primp;
    out = arg->out_packetp;
    n = ((u16 *)primp)[1];
    rec = (u16 *)(arg->primtop + (primp[1] & mask));
    vertop = arg->vertop;
    nortop = arg->nortop;
    rec++;
    rec--;

    if (flags & 4) {
        s32 x;
        s32 y;
        s32 w;
        do {
        while (--n != -1) {
            do {
                x = (( (vertop[rec[7]].vx + vertop[rec[9]].vx + vertop[rec[11]].vx + vertop[rec[13]].vx) / 4 ) >= 0 ? ( (vertop[rec[7]].vx + vertop[rec[9]].vx + vertop[rec[11]].vx + vertop[rec[13]].vx) / 4 ) : -( (vertop[rec[7]].vx + vertop[rec[9]].vx + vertop[rec[11]].vx + vertop[rec[13]].vx) / 4 )) ;
                y = (( (vertop[rec[7]].vy + vertop[rec[9]].vy + vertop[rec[11]].vy + vertop[rec[13]].vy) / 4 ) >= 0 ? ( (vertop[rec[7]].vy + vertop[rec[9]].vy + vertop[rec[11]].vy + vertop[rec[13]].vy) / 4 ) : -( (vertop[rec[7]].vy + vertop[rec[9]].vy + vertop[rec[11]].vy + vertop[rec[13]].vy) / 4 )) ;
                w = (( (vertop[rec[7]].vz + vertop[rec[9]].vz + vertop[rec[11]].vz + vertop[rec[13]].vz) / 4 ) >= 0 ? ( (vertop[rec[7]].vz + vertop[rec[9]].vz + vertop[rec[11]].vz + vertop[rec[13]].vz) / 4 ) : -( (vertop[rec[7]].vz + vertop[rec[9]].vz + vertop[rec[11]].vz + vertop[rec[13]].vz) / 4 )) ;
            } while (0);
            func_80033CF8(x, y, w);
            rec += 14;
        }
        return (u32 *)primp + 2;
        } while (0);
    }

    if (flags & 3) {
        LINE_G4 *lg = (LINE_G4 *)0x1F800380;
        POLY_GT4 *gt = (POLY_GT4 *)0x1F800380;
        CVECTOR *grey = (CVECTOR *)0x1F8003D0;

        (*(u32 *)( white ))  = mask;
        (*(u32 *)( grey ))  = D_8009B300;
        while (--n != -1) {
            flg = (s32 *)0x1F8003E8;
            if (D_8009B30C & 2) {
                z = D_8009B310->sorted_position;
                D_8009B310++;
                if (z < D_8009B314) {
                    __asm__ volatile (	"lwc2	$0, 0( %0 );"	"lwc2	$1, 4( %0 )"	:	: "r"(  &vertop[rec[7]]  ) ) ;
                    __asm__ volatile (	"nop;"	"nop;"	".word 0x0000007f" ) ;
                    __asm__ volatile (	"swc2	$14, 0( %0 )"	:	: "r"(  &gt->x0  )	: "memory" ) ;
                    __asm__ volatile (	"cfc2	$12, $31;"	"nop;"	"sw	$12, 0( %0 )"	:	: "r"(  &scr[0]  )	: "$12", "memory" ) ;
                    __asm__ volatile (	"lwc2	$0, 0( %0 );"	"lwc2	$1, 4( %0 )"	:	: "r"(  &nortop[rec[5]]  ) ) ;
                    __asm__ volatile (	"lwc2	$6, 0( %0 )"	:	: "r"(  grey  ) ) ;
                    __asm__ volatile (	"nop;"	"nop;"	".word 0x00000fff" ) ;
                    __asm__ volatile (	"swc2	$22, 0( %0 )"	:	: "r"(  &gt->r0  )	: "memory" ) ;
                    __asm__ volatile (	"mfc2	$12, $19;"	"nop;"	"sra	$12, $12, 2;"	"sw	$12, 0( %0 )"	:	: "r"(  &scr[4]  )	: "$12", "memory" ) ;
                    __asm__ volatile (	"lwc2	$0, 0( %0 );"	"lwc2	$1, 4( %0 )"	:	: "r"(  &vertop[rec[9]]  ) ) ;
                    __asm__ volatile (	"nop;"	"nop;"	".word 0x0000007f" ) ;
                    __asm__ volatile (	"swc2	$14, 0( %0 )"	:	: "r"(  &gt->x1  )	: "memory" ) ;
                    __asm__ volatile (	"cfc2	$12, $31;"	"nop;"	"sw	$12, 0( %0 )"	:	: "r"(  &scr[1]  )	: "$12", "memory" ) ;
                    __asm__ volatile (	"lwc2	$0, 0( %0 );"	"lwc2	$1, 4( %0 )"	:	: "r"(  &nortop[rec[8]]  ) ) ;
                    __asm__ volatile (	"lwc2	$6, 0( %0 )"	:	: "r"(  grey  ) ) ;
                    __asm__ volatile (	"nop;"	"nop;"	".word 0x00000fff" ) ;
                    __asm__ volatile (	"swc2	$22, 0( %0 )"	:	: "r"(  &gt->r1  )	: "memory" ) ;
                    __asm__ volatile (	"mfc2	$12, $19;"	"nop;"	"sra	$12, $12, 2;"	"sw	$12, 0( %0 )"	:	: "r"(  &scr[5]  )	: "$12", "memory" ) ;
                    __asm__ volatile (	"lwc2	$0, 0( %0 );"	"lwc2	$1, 4( %0 )"	:	: "r"(  &vertop[rec[11]]  ) ) ;
                    __asm__ volatile (	"nop;"	"nop;"	".word 0x0000007f" ) ;
                    __asm__ volatile (	"swc2	$14, 0( %0 )"	:	: "r"(  &gt->x2  )	: "memory" ) ;
                    __asm__ volatile (	"cfc2	$12, $31;"	"nop;"	"sw	$12, 0( %0 )"	:	: "r"(  flg  )	: "$12", "memory" ) ;
                    __asm__ volatile (	"lwc2	$0, 0( %0 );"	"lwc2	$1, 4( %0 )"	:	: "r"(  &nortop[rec[10]]  ) ) ;
                    __asm__ volatile (	"lwc2	$6, 0( %0 )"	:	: "r"(  grey  ) ) ;
                    __asm__ volatile (	"nop;"	"nop;"	".word 0x00000fff" ) ;
                    __asm__ volatile (	"swc2	$22, 0( %0 )"	:	: "r"(  &gt->r2  )	: "memory" ) ;
                    __asm__ volatile (	"mfc2	$12, $19;"	"nop;"	"sra	$12, $12, 2;"	"sw	$12, 0( %0 )"	:	: "r"(  &scr[6]  )	: "$12", "memory" ) ;
                    __asm__ volatile (	"mtc2	%0, $12;"	"mtc2	%2, $14;"	"mtc2	%1, $13"	:	: "r"(  *(s32 *)&gt->x0  ), "r"(   *(s32 *)&gt->x1  ), "r"(   *(s32 *)&gt->x2  ) ) ;
                    __asm__ volatile (	"nop;"	"nop;"	".word 0x0000117f" ) ;
                    __asm__ volatile (	"swc2	$24, 0( %0 )"	:	: "r"(  &z  )	: "memory" ) ;
                    if (z <= 0 || (scr[0] | scr[1] | scr[2]) < 0) {
                        goto next;
                    }
                    __asm__ volatile (	"lwc2	$0, 0( %0 );"	"lwc2	$1, 4( %0 )"	:	: "r"(  &vertop[rec[13]]  ) ) ;
                    __asm__ volatile (	"nop;"	"nop;"	".word 0x0000007f" ) ;
                    __asm__ volatile (	"swc2	$14, 0( %0 )"	:	: "r"(  &gt->x3  )	: "memory" ) ;
                    __asm__ volatile (	"cfc2	$12, $31;"	"nop;"	"sw	$12, 0( %0 )"	:	: "r"(  &scr[3]  )	: "$12", "memory" ) ;
                    __asm__ volatile (	"lwc2	$0, 0( %0 );"	"lwc2	$1, 4( %0 )"	:	: "r"(  &nortop[rec[12]]  ) ) ;
                    __asm__ volatile (	"lwc2	$6, 0( %0 )"	:	: "r"(  grey  ) ) ;
                    __asm__ volatile (	"nop;"	"nop;"	".word 0x00000fff" ) ;
                    __asm__ volatile (	"swc2	$22, 0( %0 )"	:	: "r"(  &gt->r3  )	: "memory" ) ;
                    __asm__ volatile (	"mfc2	$12, $19;"	"nop;"	"sra	$12, $12, 2;"	"sw	$12, 0( %0 )"	:	: "r"(  &scr[7]  )	: "$12", "memory" ) ;
                    (((P_TAG *)(  gt  ))->len  = (u8)(  12 )) , (((P_TAG *)(  gt  ))->code = (u8)(  0x3c ))  ;
                    *(u16 *)&gt->u0 = rec[0];
                    *(u16 *)&gt->u1 = rec[2];
                    *(u16 *)&gt->u2 = rec[4];
                    *(u16 *)&gt->u3 = rec[6];
                    gt->tpage = rec[3];
                    gt->clut = rec[1];
                    *(POLY_GT4 *)out = *gt;
                    z = (scr[4] + scr[5] + scr[6] + scr[7]) / 4 >> 4;
                    (((P_TAG *)(   out  ))->addr = (u32)(  (u32)(((P_TAG *)(  &arg->tagp->org[z]  ))->addr)  )) , (((P_TAG *)(  &arg->tagp->org[z]  ))->addr = (u32)(    out  ))  ;
                    out += 0x34;
                    goto next;
                }
            }
            __asm__ volatile (	"lwc2	$0, 0( %0 );"	"lwc2	$1, 4( %0 )"	:	: "r"(  &vertop[rec[7]]  ) ) ;
            __asm__ volatile (	"nop;"	"nop;"	".word 0x0000007f" ) ;
            __asm__ volatile (	"swc2	$14, 0( %0 )"	:	: "r"(  &lg->x0  )	: "memory" ) ;
            __asm__ volatile (	"cfc2	$12, $31;"	"nop;"	"sw	$12, 0( %0 )"	:	: "r"(  &scr[0]  )	: "$12", "memory" ) ;
            __asm__ volatile (	"lwc2	$0, 0( %0 );"	"lwc2	$1, 4( %0 )"	:	: "r"(  &nortop[rec[5]]  ) ) ;
            __asm__ volatile (	"lwc2	$6, 0( %0 )"	:	: "r"(  white  ) ) ;
            __asm__ volatile (	"nop;"	"nop;"	".word 0x00000fff" ) ;
            __asm__ volatile (	"swc2	$22, 0( %0 )"	:	: "r"(  &lg->r0  )	: "memory" ) ;
            __asm__ volatile (	"mfc2	$12, $19;"	"nop;"	"sra	$12, $12, 2;"	"sw	$12, 0( %0 )"	:	: "r"(  &scr[4]  )	: "$12", "memory" ) ;
            __asm__ volatile (	"lwc2	$0, 0( %0 );"	"lwc2	$1, 4( %0 )"	:	: "r"(  &vertop[rec[9]]  ) ) ;
            __asm__ volatile (	"nop;"	"nop;"	".word 0x0000007f" ) ;
            __asm__ volatile (	"swc2	$14, 0( %0 )"	:	: "r"(  &lg->x1  )	: "memory" ) ;
            __asm__ volatile (	"cfc2	$12, $31;"	"nop;"	"sw	$12, 0( %0 )"	:	: "r"(  flg  )	: "$12", "memory" ) ;
            __asm__ volatile (	"lwc2	$0, 0( %0 );"	"lwc2	$1, 4( %0 )"	:	: "r"(  &nortop[rec[8]]  ) ) ;
            __asm__ volatile (	"lwc2	$6, 0( %0 )"	:	: "r"(  white  ) ) ;
            __asm__ volatile (	"nop;"	"nop;"	".word 0x00000fff" ) ;
            __asm__ volatile (	"swc2	$22, 0( %0 )"	:	: "r"(  &lg->r1  )	: "memory" ) ;
            __asm__ volatile (	"mfc2	$12, $19;"	"nop;"	"sra	$12, $12, 2;"	"sw	$12, 0( %0 )"	:	: "r"(  &scr[5]  )	: "$12", "memory" ) ;
            __asm__ volatile (	"lwc2	$0, 0( %0 );"	"lwc2	$1, 4( %0 )"	:	: "r"(  &vertop[rec[13]]  ) ) ;
            __asm__ volatile (	"nop;"	"nop;"	".word 0x0000007f" ) ;
            __asm__ volatile (	"swc2	$14, 0( %0 )"	:	: "r"(  &lg->x2  )	: "memory" ) ;
            __asm__ volatile (	"cfc2	$12, $31;"	"nop;"	"sw	$12, 0( %0 )"	:	: "r"(  flg  )	: "$12", "memory" ) ;
            __asm__ volatile (	"lwc2	$0, 0( %0 );"	"lwc2	$1, 4( %0 )"	:	: "r"(  &nortop[rec[12]]  ) ) ;
            __asm__ volatile (	"lwc2	$6, 0( %0 )"	:	: "r"(  white  ) ) ;
            __asm__ volatile (	"nop;"	"nop;"	".word 0x00000fff" ) ;
            __asm__ volatile (	"swc2	$22, 0( %0 )"	:	: "r"(  &lg->r2  )	: "memory" ) ;
            __asm__ volatile (	"mfc2	$12, $19;"	"nop;"	"sra	$12, $12, 2;"	"sw	$12, 0( %0 )"	:	: "r"(  &scr[6]  )	: "$12", "memory" ) ;
            __asm__ volatile (	"lwc2	$0, 0( %0 );"	"lwc2	$1, 4( %0 )"	:	: "r"(  &vertop[rec[11]]  ) ) ;
            __asm__ volatile (	"nop;"	"nop;"	".word 0x0000007f" ) ;
            __asm__ volatile (	"swc2	$14, 0( %0 )"	:	: "r"(  &lg->x3  )	: "memory" ) ;
            __asm__ volatile (	"cfc2	$12, $31;"	"nop;"	"sw	$12, 0( %0 )"	:	: "r"(  &scr[3]  )	: "$12", "memory" ) ;
            __asm__ volatile (	"lwc2	$0, 0( %0 );"	"lwc2	$1, 4( %0 )"	:	: "r"(  &nortop[rec[10]]  ) ) ;
            __asm__ volatile (	"lwc2	$6, 0( %0 )"	:	: "r"(  white  ) ) ;
            __asm__ volatile (	"nop;"	"nop;"	".word 0x00000fff" ) ;
            __asm__ volatile (	"swc2	$22, 0( %0 )"	:	: "r"(  &lg->r3  )	: "memory" ) ;
            __asm__ volatile (	"mfc2	$12, $19;"	"nop;"	"sra	$12, $12, 2;"	"sw	$12, 0( %0 )"	:	: "r"(  &scr[7]  )	: "$12", "memory" ) ;
            if ((scr[0] | scr[1] | scr[2] | scr[3]) < 0) {
                goto next;
            }
            (((P_TAG *)(  lg  ))->len  = (u8)(  9 )) ,  (((P_TAG *)(  lg  ))->code = (u8)(  0x5c )) ,( lg )->pad = 0x55555555, ( lg )->p2 = 0, ( lg )->p3 = 0 ;
            *(LINE_G4 *)out = *lg;
            z = (scr[4] + scr[5] + scr[6] + scr[7]) / 4 >> 4;
            (((P_TAG *)(   out  ))->addr = (u32)(  (u32)(((P_TAG *)(  &arg->tagp->org[z]  ))->addr)  )) , (((P_TAG *)(  &arg->tagp->org[z]  ))->addr = (u32)(    out  ))  ;
            out += 0x28;
            *(u32 *)& ((LINE_G2 *)( out )) ->x0 = *(u32 *)&lg->x0;
            *(u32 *)& ((LINE_G2 *)( out )) ->x1 = *(u32 *)&lg->x3;
            *(u32 *)& ((LINE_G2 *)( out )) ->r0 = *(u32 *)&lg->r0;
            *(u32 *)& ((LINE_G2 *)( out )) ->r1 = *(u32 *)&lg->r3;
            (((P_TAG *)(  ((LINE_G2 *)( out ))   ))->len  = (u8)(  4 )) ,  (((P_TAG *)(  ((LINE_G2 *)( out ))   ))->code = (u8)(  0x50 ))  ;
            (((P_TAG *)(   out  ))->addr = (u32)(  (u32)(((P_TAG *)(  &arg->tagp->org[z]  ))->addr)  )) , (((P_TAG *)(  &arg->tagp->org[z]  ))->addr = (u32)(    out  ))  ;
            out += 0x14;
        next:
            rec += 14;
        }
    } else {
        POLY_GT4 *gt = (POLY_GT4 *)0x1F800380;

        (*(u32 *)( white ))  = D_8009B300;
        while (--n != -1) {
            __asm__ volatile (	"lwc2	$0, 0( %0 );"	"lwc2	$1, 4( %0 )"	:	: "r"(  &vertop[rec[7]]  ) ) ;
            __asm__ volatile (	"nop;"	"nop;"	".word 0x0000007f" ) ;
            __asm__ volatile (	"swc2	$14, 0( %0 )"	:	: "r"(  &gt->x0  )	: "memory" ) ;
            __asm__ volatile (	"cfc2	$12, $31;"	"nop;"	"sw	$12, 0( %0 )"	:	: "r"(  &scr[0]  )	: "$12", "memory" ) ;
            __asm__ volatile (	"lwc2	$0, 0( %0 );"	"lwc2	$1, 4( %0 )"	:	: "r"(  &nortop[rec[5]]  ) ) ;
            __asm__ volatile (	"lwc2	$6, 0( %0 )"	:	: "r"(  white  ) ) ;
            __asm__ volatile (	"nop;"	"nop;"	".word 0x00000fff" ) ;
            __asm__ volatile (	"swc2	$22, 0( %0 )"	:	: "r"(  &gt->r0  )	: "memory" ) ;
            __asm__ volatile (	"mfc2	$12, $19;"	"nop;"	"sra	$12, $12, 2;"	"sw	$12, 0( %0 )"	:	: "r"(  &scr[4]  )	: "$12", "memory" ) ;
            __asm__ volatile (	"lwc2	$0, 0( %0 );"	"lwc2	$1, 4( %0 )"	:	: "r"(  &vertop[rec[9]]  ) ) ;
            __asm__ volatile (	"nop;"	"nop;"	".word 0x0000007f" ) ;
            __asm__ volatile (	"swc2	$14, 0( %0 )"	:	: "r"(  &gt->x1  )	: "memory" ) ;
            __asm__ volatile (	"cfc2	$12, $31;"	"nop;"	"sw	$12, 0( %0 )"	:	: "r"(  &scr[1]  )	: "$12", "memory" ) ;
            __asm__ volatile (	"lwc2	$0, 0( %0 );"	"lwc2	$1, 4( %0 )"	:	: "r"(  &nortop[rec[8]]  ) ) ;
            __asm__ volatile (	"lwc2	$6, 0( %0 )"	:	: "r"(  white  ) ) ;
            __asm__ volatile (	"nop;"	"nop;"	".word 0x00000fff" ) ;
            __asm__ volatile (	"swc2	$22, 0( %0 )"	:	: "r"(  &gt->r1  )	: "memory" ) ;
            __asm__ volatile (	"mfc2	$12, $19;"	"nop;"	"sra	$12, $12, 2;"	"sw	$12, 0( %0 )"	:	: "r"(  &scr[5]  )	: "$12", "memory" ) ;
            __asm__ volatile (	"lwc2	$0, 0( %0 );"	"lwc2	$1, 4( %0 )"	:	: "r"(  &vertop[rec[11]]  ) ) ;
            __asm__ volatile (	"nop;"	"nop;"	".word 0x0000007f" ) ;
            __asm__ volatile (	"swc2	$14, 0( %0 )"	:	: "r"(  &gt->x2  )	: "memory" ) ;
            __asm__ volatile (	"cfc2	$12, $31;"	"nop;"	"sw	$12, 0( %0 )"	:	: "r"(  &scr[2]  )	: "$12", "memory" ) ;
            __asm__ volatile (	"lwc2	$0, 0( %0 );"	"lwc2	$1, 4( %0 )"	:	: "r"(  &nortop[rec[10]]  ) ) ;
            __asm__ volatile (	"lwc2	$6, 0( %0 )"	:	: "r"(  white  ) ) ;
            __asm__ volatile (	"nop;"	"nop;"	".word 0x00000fff" ) ;
            __asm__ volatile (	"swc2	$22, 0( %0 )"	:	: "r"(  &gt->r2  )	: "memory" ) ;
            __asm__ volatile (	"mfc2	$12, $19;"	"nop;"	"sra	$12, $12, 2;"	"sw	$12, 0( %0 )"	:	: "r"(  &scr[6]  )	: "$12", "memory" ) ;
            __asm__ volatile (	"mtc2	%0, $12;"	"mtc2	%2, $14;"	"mtc2	%1, $13"	:	: "r"(  *(s32 *)&gt->x0  ), "r"(   *(s32 *)&gt->x1  ), "r"(   *(s32 *)&gt->x2  ) ) ;
            __asm__ volatile (	"nop;"	"nop;"	".word 0x0000117f" ) ;
            __asm__ volatile (	"swc2	$24, 0( %0 )"	:	: "r"(  &z  )	: "memory" ) ;
            if (z > 0 && (scr[0] | scr[1] | scr[2]) >= 0) {
                __asm__ volatile (	"lwc2	$0, 0( %0 );"	"lwc2	$1, 4( %0 )"	:	: "r"(  &vertop[rec[13]]  ) ) ;
                __asm__ volatile (	"nop;"	"nop;"	".word 0x0000007f" ) ;
                __asm__ volatile (	"swc2	$14, 0( %0 )"	:	: "r"(  &gt->x3  )	: "memory" ) ;
                __asm__ volatile (	"cfc2	$12, $31;"	"nop;"	"sw	$12, 0( %0 )"	:	: "r"(  &scr[3]  )	: "$12", "memory" ) ;
                __asm__ volatile (	"lwc2	$0, 0( %0 );"	"lwc2	$1, 4( %0 )"	:	: "r"(  &nortop[rec[12]]  ) ) ;
                __asm__ volatile (	"lwc2	$6, 0( %0 )"	:	: "r"(  white  ) ) ;
                __asm__ volatile (	"nop;"	"nop;"	".word 0x00000fff" ) ;
                __asm__ volatile (	"swc2	$22, 0( %0 )"	:	: "r"(  &gt->r3  )	: "memory" ) ;
                __asm__ volatile (	"mfc2	$12, $19;"	"nop;"	"sra	$12, $12, 2;"	"sw	$12, 0( %0 )"	:	: "r"(  &scr[7]  )	: "$12", "memory" ) ;
                (((P_TAG *)(  gt  ))->len  = (u8)(  12 )) , (((P_TAG *)(  gt  ))->code = (u8)(  0x3c ))  ;
                *(u16 *)&gt->u0 = rec[0];
                *(u16 *)&gt->u1 = rec[2];
                *(u16 *)&gt->u2 = rec[4];
                *(u16 *)&gt->u3 = rec[6];
                gt->tpage = rec[3];
                gt->clut = rec[1];
                *(POLY_GT4 *)out = *gt;
                z = (scr[4] + scr[5] + scr[6] + scr[7]) / 4 >> 4;
                (((P_TAG *)(   out  ))->addr = (u32)(  (u32)(((P_TAG *)(  &arg->tagp->org[z]  ))->addr)  )) , (((P_TAG *)(  &arg->tagp->org[z]  ))->addr = (u32)(    out  ))  ;
                out += 0x34;
            }
            rec += 14;
        }
    }
    D_800FE240 = (u32 *)out;
    return (u32 *)primp + 2;
}
