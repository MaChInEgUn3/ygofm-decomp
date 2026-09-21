/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/func_80033DB0.c, profile gcc_2_8_1_g8_split_psyq_gte.
 * The declarations above the function are the subset of that tree's headers
 * this unit needs, preprocessed and with symbols renamed to this tree's
 * spelling (func_ADDR, D_ADDR); their types are that tree's. Byte-identical
 * under the flag row in tools_src/build.py. */
#include "kg_types.h"
#include "kg_variables.h"
#include "kg_functions.h"
extern u32 D_8009B300;
extern SortedEntry *D_8009B310;
extern u32 D_8009B314;
void func_80033CF8(s32 dx, s32 dy, s32 dz);
extern u32 *D_800FE240 __attribute__((section(".data")));
u32 *func_80033DB0(GsARGUNIT_NORMAL *arg);
u32 *func_8006151C(GsARGUNIT_NORMAL *arg);
u32 *func_80033DB0(GsARGUNIT_NORMAL *arg)
{
    long z;
    u32 flags;
    u32 mask;
    CVECTOR *white;
    s32 *scr;
    u32 *primp;
    PACKET *out;
    s32 n;
    u16 *rec;
    SVECTOR *vertop;
    SVECTOR *nortop;

    flags = D_8009B30C;
    if (flags & 8) {
        return func_8006151C(arg);
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

    if (flags & 4) {
        s32 x;
        s32 y;
        s32 w;
        do {
        while (--n != -1) {
            x = (vertop[rec[7]].vx + vertop[rec[9]].vx + vertop[rec[11]].vx) / 3;
            y = (vertop[rec[7]].vy + vertop[rec[9]].vy + vertop[rec[11]].vy) / 3;
            w = (vertop[rec[7]].vz + vertop[rec[9]].vz + vertop[rec[11]].vz) / 3;
            func_80033CF8(x >= 0 ? x : -x, y >= 0 ? y : -y, w >= 0 ? w : -w);
            rec += 11;
            rec++;
        }
        return primp + 2;
        } while (0);
    }

    if (flags & 3) {
        SVECTOR *v1;
        u32 c0;
        u32 c1;
        CVECTOR *grey = (CVECTOR *)0x1F8003D0;
        LINE_G4 *lg = (LINE_G4 *)0x1F800380;
        POLY_GT3 *gt = (POLY_GT3 *)0x1F800380;

        (*(u32 *)( white ))  = mask;
        (*(u32 *)( grey ))  = D_8009B300;
        while (--n != -1) {
            if (D_8009B30C & 2) {
                z = D_8009B310->sorted_position;
                D_8009B310++;
                if (z < D_8009B314) {
                    __asm__ volatile (	"lwc2	$0, 0( %0 );"	"lwc2	$1, 4( %0 )"	:	: "r"(  &vertop[rec[7]]  ) ) ;
                    __asm__ volatile (	"nop;"	"nop;"	".word 0x0000007f" ) ;
                    __asm__ volatile (	"swc2	$14, 0( %0 )"	:	: "r"(  &gt->x0  )	: "memory" ) ;
                    __asm__ volatile (	"cfc2	$12, $31;"	"nop;"	"sw	$12, 0( %0 )"	:	: "r"(  &scr[0]  )	: "$12", "memory" ) ;
                    __asm__ volatile (	"lwc2	$0, 0( %0 );"	"lwc2	$1, 4( %0 )"	:	: "r"(  &nortop[rec[6]]  ) ) ;
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
                    __asm__ volatile (	"cfc2	$12, $31;"	"nop;"	"sw	$12, 0( %0 )"	:	: "r"(  &scr[2]  )	: "$12", "memory" ) ;
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
                    (((P_TAG *)(  gt  ))->len  = (u8)(  9 )) ,  (((P_TAG *)(  gt  ))->code = (u8)(  0x34 ))  ;
                    *(u16 *)&gt->u0 = rec[0];
                    *(u16 *)&gt->u1 = rec[2];
                    *(u16 *)&gt->u2 = rec[4];
                    gt->tpage = rec[3];
                    gt->clut = rec[1];
                    (*( POLY_GT3  *)(  out ))  = *gt;
                    z = (scr[4] + scr[5] + scr[6]) / 3 >> 4;
                    (((P_TAG *)(   out  ))->addr = (u32)(  (u32)(((P_TAG *)(  &arg->tagp->org[z]  ))->addr)  )) , (((P_TAG *)(  &arg->tagp->org[z]  ))->addr = (u32)(    out  ))  ;
                    out += sizeof(POLY_GT3);
                    goto next;
                }
            }
            __asm__ volatile (	"lwc2	$0, 0( %0 );"	"lwc2	$1, 4( %0 )"	:	: "r"(  &vertop[rec[7]]  ) ) ;
            __asm__ volatile (	"nop;"	"nop;"	".word 0x0000007f" ) ;
            __asm__ volatile (	"swc2	$14, 0( %0 )"	:	: "r"(  &lg->x0  )	: "memory" ) ;
            __asm__ volatile (	"cfc2	$12, $31;"	"nop;"	"sw	$12, 0( %0 )"	:	: "r"(  &scr[0]  )	: "$12", "memory" ) ;
            __asm__ volatile (	"lwc2	$0, 0( %0 );"	"lwc2	$1, 4( %0 )"	:	: "r"(  &nortop[rec[6]]  ) ) ;
            __asm__ volatile (	"lwc2	$6, 0( %0 )"	:	: "r"(  white  ) ) ;
            __asm__ volatile (	"nop;"	"nop;"	".word 0x00000fff" ) ;
            __asm__ volatile (	"swc2	$22, 0( %0 )"	:	: "r"(  &lg->r0  )	: "memory" ) ;
            __asm__ volatile (	"mfc2	$12, $19;"	"nop;"	"sra	$12, $12, 2;"	"sw	$12, 0( %0 )"	:	: "r"(  &scr[4]  )	: "$12", "memory" ) ;
            c0 = ((u32 *)( lg )) [1];
            c1 = ((u32 *)( lg )) [2];
            v1 = &vertop[rec[9]];
            ((u32 *)( lg )) [7] = c0;
            ((u32 *)( lg )) [8] = c1;
            __asm__ volatile (	"lwc2	$0, 0( %0 );"	"lwc2	$1, 4( %0 )"	:	: "r"(  v1  ) ) ;
            __asm__ volatile (	"nop;"	"nop;"	".word 0x0000007f" ) ;
            __asm__ volatile (	"swc2	$14, 0( %0 )"	:	: "r"(  &lg->x1  )	: "memory" ) ;
            __asm__ volatile (	"cfc2	$12, $31;"	"nop;"	"sw	$12, 0( %0 )"	:	: "r"(  &scr[1]  )	: "$12", "memory" ) ;
            __asm__ volatile (	"lwc2	$0, 0( %0 );"	"lwc2	$1, 4( %0 )"	:	: "r"(  &nortop[rec[8]]  ) ) ;
            __asm__ volatile (	"lwc2	$6, 0( %0 )"	:	: "r"(  white  ) ) ;
            __asm__ volatile (	"nop;"	"nop;"	".word 0x00000fff" ) ;
            __asm__ volatile (	"swc2	$22, 0( %0 )"	:	: "r"(  &lg->r1  )	: "memory" ) ;
            __asm__ volatile (	"mfc2	$12, $19;"	"nop;"	"sra	$12, $12, 2;"	"sw	$12, 0( %0 )"	:	: "r"(  &scr[5]  )	: "$12", "memory" ) ;
            __asm__ volatile (	"lwc2	$0, 0( %0 );"	"lwc2	$1, 4( %0 )"	:	: "r"(  &vertop[rec[11]]  ) ) ;
            __asm__ volatile (	"nop;"	"nop;"	".word 0x0000007f" ) ;
            __asm__ volatile (	"swc2	$14, 0( %0 )"	:	: "r"(  &lg->x2  )	: "memory" ) ;
            __asm__ volatile (	"cfc2	$12, $31;"	"nop;"	"sw	$12, 0( %0 )"	:	: "r"(  &scr[2]  )	: "$12", "memory" ) ;
            __asm__ volatile (	"lwc2	$0, 0( %0 );"	"lwc2	$1, 4( %0 )"	:	: "r"(  &nortop[rec[10]]  ) ) ;
            __asm__ volatile (	"lwc2	$6, 0( %0 )"	:	: "r"(  white  ) ) ;
            __asm__ volatile (	"nop;"	"nop;"	".word 0x00000fff" ) ;
            __asm__ volatile (	"swc2	$22, 0( %0 )"	:	: "r"(  &lg->r2  )	: "memory" ) ;
            __asm__ volatile (	"mfc2	$12, $19;"	"nop;"	"sra	$12, $12, 2;"	"sw	$12, 0( %0 )"	:	: "r"(  &scr[6]  )	: "$12", "memory" ) ;
            if ((scr[0] | scr[1] | scr[2]) < 0) {
                goto next;
            }
            (((P_TAG *)(  lg  ))->len  = (u8)(  9 )) ,  (((P_TAG *)(  lg  ))->code = (u8)(  0x5c )) ,( lg )->pad = 0x55555555, ( lg )->p2 = 0, ( lg )->p3 = 0 ;
            (*( LINE_G4  *)(  out ))  = *lg;
            z = (scr[4] + scr[5] + scr[6]) / 3 >> 4;
            (((P_TAG *)(   out  ))->addr = (u32)(  (u32)(((P_TAG *)(  &arg->tagp->org[z]  ))->addr)  )) , (((P_TAG *)(  &arg->tagp->org[z]  ))->addr = (u32)(    out  ))  ;
            out += sizeof(LINE_G4);
        next:
            rec += 11;
            rec++;
        }
    } else {
        POLY_GT3 *gt = (POLY_GT3 *)0x1F800380;

        (*(u32 *)( white ))  = D_8009B300;
        while (--n != -1) {
            __asm__ volatile (	"lwc2	$0, 0( %0 );"	"lwc2	$1, 4( %0 )"	:	: "r"(  &vertop[rec[7]]  ) ) ;
            __asm__ volatile (	"nop;"	"nop;"	".word 0x0000007f" ) ;
            __asm__ volatile (	"swc2	$14, 0( %0 )"	:	: "r"(  &gt->x0  )	: "memory" ) ;
            __asm__ volatile (	"cfc2	$12, $31;"	"nop;"	"sw	$12, 0( %0 )"	:	: "r"(  &scr[0]  )	: "$12", "memory" ) ;
            __asm__ volatile (	"lwc2	$0, 0( %0 );"	"lwc2	$1, 4( %0 )"	:	: "r"(  &nortop[rec[6]]  ) ) ;
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
                (((P_TAG *)(  gt  ))->len  = (u8)(  9 )) ,  (((P_TAG *)(  gt  ))->code = (u8)(  0x34 ))  ;
                *(u16 *)&gt->u0 = rec[0];
                *(u16 *)&gt->u1 = rec[2];
                *(u16 *)&gt->u2 = rec[4];
                gt->tpage = rec[3];
                gt->clut = rec[1];
                (*( POLY_GT3  *)(  out ))  = *gt;
                z = (scr[4] + scr[5] + scr[6]) / 3 >> 4;
                (((P_TAG *)(   out  ))->addr = (u32)(  (u32)(((P_TAG *)(  &arg->tagp->org[z]  ))->addr)  )) , (((P_TAG *)(  &arg->tagp->org[z]  ))->addr = (u32)(    out  ))  ;
                out += sizeof(POLY_GT3);
            }
            rec += 11;
            rec++;
        }
    }
    D_800FE240 = (u32 *)out;
    return primp + 2;
}
