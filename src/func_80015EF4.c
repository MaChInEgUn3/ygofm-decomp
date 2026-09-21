/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/func_80015EF4.c, profile gcc_2_8_1_g8_split_psyq_rtps.
 * The declarations above the function are the subset of that tree's headers
 * this unit needs, preprocessed and with symbols renamed to this tree's
 * spelling (func_ADDR, D_ADDR); their types are that tree's. Byte-identical
 * under the flag row in tools_src/build.py. */
#include "kg_types.h"
#include "kg_variables.h"
#include "kg_functions.h"
void func_80015EF4(void *record, POLY_GT4 *prim, POLY_FT4 *sprite, s32 *color)
{
    DuelCardRenderHolder *holder = record;
    GsOT **tab;
    DisplayObject *obj;
    s32 a;
    s32 c;
    s32 d;
    s32 y;
    MATRIX *lm;
    SVECTOR *q;
    VECTOR *scale;
    SVECTOR *up;
    SVECTOR *rot;
    s32 *depth;
    SVECTOR *q1;
    SVECTOR *q2;
    SVECTOR *q3;
    SVECTOR *c1;
    SVECTOR *c2;
    SVECTOR *c3;

    obj = (DisplayObject *)holder->model;
    if ((obj->flags & 0x40) == 0) {
        return;
    }

    lm = (MATRIX *)0x1F8002C0;
    q = (SVECTOR *)0x1F800300;
    scale = (VECTOR *)0x1F800320;
    up = (SVECTOR *)0x1F800380;
    rot = (SVECTOR *)0x1F8003A0;
    depth = (s32 *)0x1F8003E0;
    up->vx = 0;
    up->vy = 0x1000;
    up->vz = 0;
    *color = obj->field_0C;
    rot[0].vx = obj->field_20.b.field_20 << 4;
    y = obj->field_20.b.field_21 << 4;
    rot[0].vy = y;
    rot[0].vz = obj->field_20.b.field_22 << 4;
    if (holder->field_18 >= 0xF) {
        rot[0].vy = y + 0x800;
    }
    lm->t[0] = *(s16 *)(((u8 *)( obj ))  + 0x30);
    a = *(s16 *)(((u8 *)( obj ))  + 0x32);
    lm->t[1] = a;
    d = *(s16 *)(((u8 *)( obj ))  + 0x34);
    lm->t[2] = d;
    a += 0xFF;
    if (a < 0) {
        a = 0;
    }
    sprite->b0 = a;
    sprite->g0 = a;
    sprite->r0 = a;
    func_80088C50(rot, lm);
    if ((obj->flags & (1<<27) ) == 0) {
        scale->vx = obj->field_44.h.field_44;
        scale->vy = 0x1000;
        scale->vz = obj->field_44.h.field_46;
        func_80087670(lm, scale);
    }

    q2 = (SVECTOR *)0x1F800310;
    q3 = (SVECTOR *)0x1F800318;
    q1 = (SVECTOR *)0x1F800308;
    q[0].vx = q2->vx = -0x19;
    q[1].vx = q3->vx = 0x1A;
    q[0].vz = q1->vz = 0x1D;
    q[2].vz = q3->vz = -0x1E;
    q[0].vy = q1->vy = q2->vy = q3->vy = 0;
    func_800855D0(lm);

    func_80089CC0(&q[0], &rot[0], (long *)depth);
    func_80089CC0(&q[1], &rot[1], (long *)depth);
    func_80089CC0(&q[2], &rot[2], (long *)depth);
    func_80089CC0(&q[3], &rot[3], (long *)depth);

    c1 = (SVECTOR *)0x1F8003C8;
    c2 = (SVECTOR *)0x1F8003D0;
    c3 = (SVECTOR *)0x1F8003D8;
    *(Bytes8 *)&rot[4] = *(Bytes8 *)&rot[0];
    *(Bytes8 *)c1 = *(Bytes8 *)&rot[1];
    *(Bytes8 *)c2 = *(Bytes8 *)&rot[2];
    *(Bytes8 *)c3 = *(Bytes8 *)&rot[3];

    func_80085600(lm);
    func_800855D0(&D_800FE148);

    depth[4] = func_80087C70(&rot[0], up, ((CVECTOR *)( color )) ,
                (long *)&prim->x0, ((CVECTOR *)( &prim->r0 )) ,
                (long *)&depth[0]);
    depth[5] = func_80087C70(&rot[1], up, ((CVECTOR *)( color )) ,
                (long *)&prim->x1, ((CVECTOR *)( &prim->r1 )) ,
                (long *)&depth[1]);
    depth[6] = func_80087C70(&rot[2], up, ((CVECTOR *)( color )) ,
                (long *)&prim->x2, ((CVECTOR *)( &prim->r2 )) ,
                (long *)&depth[2]);
    depth[7] = func_80087C70(&rot[3], up, ((CVECTOR *)( color )) ,
                (long *)&prim->x3, ((CVECTOR *)( &prim->r3 )) ,
                (long *)&depth[3]);

    if ((depth[0] | depth[1] | depth[2]
         | depth[3]) < 0) {
        return;
    }

    prim->u0 = prim->u2 = ((u8 *)( obj )) [0x5C];
    prim->v0 = prim->v1 = ((u8 *)( obj )) [0x5D];
    if (func_800879A0(*(long *)&prim->x0, *(long *)&prim->x1,
                   *(long *)&prim->x2) <= 0) {
        prim->u2 = 0x38;
        prim->u0 = 0x38;
        prim->v1 = 0x80;
        prim->v0 = 0x80;
    }
    c = prim->u0;
    d = prim->v0;
    c += 0x34;
    d += 0x3C;
    prim->u3 = c;
    prim->u1 = c;
    prim->v3 = d;
    prim->v2 = d;
    prim->clut = (((u16)obj->field_40.h.field_42 + 0xF1) << 6) | 0x10;
    (((P_TAG *)(  prim  ))->len  = (u8)(  12 )) , (((P_TAG *)(  prim  ))->code = (u8)(  0x3c ))  ;
    func_80082840(prim, 0);
    prim->tpage = prim->tpage & 0xFF9F;
    prim->tpage = prim->tpage | ((obj->attribute >> 23) & 0x60);
    if ((obj->attribute & (1<<30) ) != 0) {
        func_80082840(prim, 1);
        sprite->r0 = ((u8 *)( obj )) [0xC];
        sprite->g0 = ((u8 *)( obj )) [0xD];
        sprite->b0 = ((u8 *)( obj )) [0xE];
    }

    depth[0] = (depth[4] + depth[5]
                          + depth[6] + depth[7]) / 4 >> 2;
    tab = D_800E9D90;
    func_80084320(prim, tab[2], *(u16 *)depth);

    c3->vy = 0;
    c2->vy = 0;
    c1->vy = 0;
    rot[4].vy = 0;
    __asm__ volatile (	"lwc2	$0, 0( %0 );"	"lwc2	$1, 4( %0 )"	:	: "r"(  (SVECTOR *)0x1F8003C0  ) ) ;
    __asm__ volatile (	"nop;"	"nop;"	".word 0x0000007f" ) ;
    __asm__ volatile (	"swc2	$14, 0( %0 )"	:	: "r"(  &sprite->x0  )	: "memory" ) ;
    __asm__ volatile (	"lwc2	$0, 0( %0 );"	"lwc2	$1, 4( %0 )"	:	: "r"(  (SVECTOR *)0x1F8003C8  ) ) ;
    __asm__ volatile (	"nop;"	"nop;"	".word 0x0000007f" ) ;
    __asm__ volatile (	"swc2	$14, 0( %0 )"	:	: "r"(  &sprite->x1  )	: "memory" ) ;
    __asm__ volatile (	"lwc2	$0, 0( %0 );"	"lwc2	$1, 4( %0 )"	:	: "r"(  (SVECTOR *)0x1F8003D0  ) ) ;
    __asm__ volatile (	"nop;"	"nop;"	".word 0x0000007f" ) ;
    __asm__ volatile (	"swc2	$14, 0( %0 )"	:	: "r"(  &sprite->x2  )	: "memory" ) ;
    __asm__ volatile (	"lwc2	$0, 0( %0 );"	"lwc2	$1, 4( %0 )"	:	: "r"(  (SVECTOR *)0x1F8003D8  ) ) ;
    __asm__ volatile (	"nop;"	"nop;"	".word 0x0000007f" ) ;
    __asm__ volatile (	"swc2	$14, 0( %0 )"	:	: "r"(  &sprite->x3  )	: "memory" ) ;
    func_80084320(sprite, tab[2], 0xFFF);
}
