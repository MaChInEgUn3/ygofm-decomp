/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/func_8004DE24.c, profile gcc_2_8_1_g8_split.
 * The declarations above the function are the subset of that tree's headers
 * this unit needs, preprocessed and with symbols renamed to this tree's
 * spelling (func_ADDR, D_ADDR); their types are that tree's. Byte-identical
 * under the flag row in tools_src/build.py. */
#include "kg_types.h"
#include "kg_variables.h"
#include "kg_functions.h"
extern void func_80089C20(SVECTOR *v0,CVECTOR *v1,CVECTOR *v2);
extern long func_80087AB0(SVECTOR *v0,SVECTOR *v1,SVECTOR *v2,SVECTOR *v3,
			long *sxy0,long *sxy1,long *sxy2,long *sxy3,
			long *p,long *flag);
extern int func_80086770(int a);
extern int func_800866A0(int a);
int     func_800857E0(int id, GsF_LIGHT * lt);
void    func_80085D50(long r, long g, long b);
void    func_800849F0(GsSPRITE * sp, GsOT * ot, unsigned short pri);
extern ModelSlot D_800F2C40[3 ];
void func_8004DE24(void);
void *func_80059220(void);
extern u8 *D_8009AF88;
extern s16 D_8009AF8E;
extern s16 D_8009AF90;
void func_8004E7B0(s32 force);
extern GsCOORDUNIT D_800F56A0;
void func_8004DE24(void)
{
    CVECTOR colors[5] = {
        {128, 128, 128, 0},
        {96, 64, 64, 0},
        {64, 42, 42, 0},
        {32, 21, 21, 0},
        {0, 0, 0, 0}
    };
    static const BackgroundNormals initial_normals = {
        {{4096, 0, 0, 0}, {0, -4096, 0, 0}}
    };
    BackgroundNormals normals = initial_normals;
    SVECTOR vertices[8];
    GsSPRITE sprite;
    POLY_G4 polygons[3];
    long projection[4];
    ModelSlot *slot = &D_800F2C40[2];
    u8 vbase;
    s32 height;
    s32 ubase;
    s16 y;
    u16 pitch_bits;
    s32 minimum_y;
    s32 amount;
    s32 phase;
    s32 cosine;
    s32 sine;
    s32 first_depth;
    s32 second_depth;

    vbase = D_8009AF88[0xAC];
    ubase = ((((ModelBackgroundRecord *)( D_8009AF88 )) ->field_AA)  & 0x3F) <<
        (2 - (((((ModelBackgroundRecord *)( D_8009AF88 )) ->field_A8)  >> 13) & 3));
    height = slot->field_D18->matrix.t[1] + 300;
    if (!slot->field_E1F)
        return;
    if (slot->field_DA0[0] == -4096 &&
        slot->field_DA0[1] == -4096 && slot->field_DA0[2] == -4096)
        return;
    func_8004E7B0(0);
    sprite.attribute = 0;
    if ((((ModelBackgroundRecord *)( D_8009AF88 )) ->field_A8)  & 0xE000)
        sprite.attribute = 0x01000000;
    func_800857E0(0, (GsF_LIGHT *)&slot->field_D70[0]);
    func_800857E0(1, (GsF_LIGHT *)&slot->field_D70[1]);
    func_800857E0(2, (GsF_LIGHT *)&slot->field_D70[2]);
    func_80085D50(slot->field_DA0[0], slot->field_DA0[1], slot->field_DA0[2]);
    func_80085600(&D_800F56A0.matrix);
    func_80089C20(&normals.values[0], &colors[0], ((CVECTOR *)( &sprite.r )) );
    sprite.tpage = (((((ModelBackgroundRecord *)( D_8009AF88 )) ->field_A8)  >> 6) & 0x180) |
        (((*(u16 *)(D_8009AF88 + ( 0xAC )))  & 0x100) >> 4) |
        (((((ModelBackgroundRecord *)( D_8009AF88 )) ->field_AA)  & 0x3FF) >> 6) |
        (((*(u16 *)(D_8009AF88 + ( 0xAC )))  & 0x200) << 2);
    sprite.cx = (*(u16 *)(D_8009AF88 + ( 0xAE ))) ;
    sprite.cy = (*(u16 *)(D_8009AF88 + ( 0xB0 ))) ;
    sprite.w = 64;
    pitch_bits = *(u16 *)&D_8009AF90;
    y = pitch_bits - 48;
    sprite.u = ubase;
    sprite.v = vbase;
    sprite.h = 256;
    sprite.y = y;
    minimum_y = -((((ModelBackgroundRecord *)( D_8009AF88 )) ->field_A8)  & 0x1FFF);
    if ((s16)pitch_bits >= minimum_y && y >= minimum_y) {
        if (y > 0)
            sprite.y = 0;
        if (sprite.y < 0) {
            sprite.v = __builtin_abs(sprite.y);
            sprite.y = 0;
        }
        {
            s32 end = sprite.y + 256;
            s32 edge = ((((ModelBackgroundRecord *)( D_8009AF88 )) ->field_A8)  & 0x1FFF) + (s16)pitch_bits;
            s32 full_height;
            s32 amount;
            if (edge < 241) {
                if (edge >= end)
                    goto second_clip;
            } else if (end < 241) {
                goto second_clip;
            }
            full_height = sprite.h;
            amount = sprite.y + full_height -
                (((((ModelBackgroundRecord *)( D_8009AF88 )) ->field_A8)  & 0x1FFF) + D_8009AF90);
            sprite.h = full_height - (amount < full_height ? amount : full_height);
        }
second_clip:
        {
            s32 end = sprite.v + sprite.h;
            s32 edge = (((ModelBackgroundRecord *)( D_8009AF88 )) ->field_A8)  & 0x1FFF;
            s32 full_height;
            s32 amount;
            if ((u32)edge < 241) {
                if (edge < end)
                    goto trim_texture;
                goto tiles;
            }
            if (end < 241)
                goto tiles;
trim_texture:
            full_height = sprite.h;
            amount =
                sprite.v + full_height - ((((ModelBackgroundRecord *)( D_8009AF88 )) ->field_A8)  & 0x1FFF);
            sprite.h = full_height - (amount < full_height ? amount : full_height);
        }
tiles:
        sprite.x = (s16)*(u16 *)&D_8009AF8E / 10 -
            160 * (u16)((((ModelBackgroundRecord *)( D_8009AF88 )) ->texture_width)  / 0x500u);
        while (sprite.x < 320) {
            if (sprite.x + sprite.w > 0)
                func_800849F0(&sprite, D_800E9D90[3],
                    (u16)((1u << D_800E9D90[3]->length) - 1));
            amount = (sprite.u + sprite.w) %
                (u16)((((ModelBackgroundRecord *)( D_8009AF88 )) ->texture_width)  / 10u);
            sprite.x += sprite.w;
            sprite.u = amount + ubase;
        }
    }
    if (!(D_8009AF88[0xA1] & 1))
        return;
    func_80089C20(&normals.values[1], &colors[1],
                   ((CVECTOR *)( &polygons[0].r0 )) );
    func_80089C20(&normals.values[1], &colors[1],
                   ((CVECTOR *)( &polygons[0].r1 )) );
    func_80089C20(&normals.values[1], &colors[2],
                   ((CVECTOR *)( &polygons[0].r2 )) );
    func_80089C20(&normals.values[1], &colors[2],
                   ((CVECTOR *)( &polygons[0].r3 )) );
    func_80089C20(&normals.values[1], &colors[2],
                   ((CVECTOR *)( &polygons[1].r0 )) );
    func_80089C20(&normals.values[1], &colors[2],
                   ((CVECTOR *)( &polygons[1].r1 )) );
    func_80089C20(&normals.values[1], &colors[3],
                   ((CVECTOR *)( &polygons[1].r2 )) );
    func_80089C20(&normals.values[1], &colors[3],
                   ((CVECTOR *)( &polygons[1].r3 )) );
    func_80089C20(&normals.values[1], &colors[3],
                   ((CVECTOR *)( &polygons[2].r0 )) );
    func_80089C20(&normals.values[1], &colors[3],
                   ((CVECTOR *)( &polygons[2].r1 )) );
    func_80089C20(&normals.values[1], &colors[4],
                   ((CVECTOR *)( &polygons[2].r2 )) );
    func_80089C20(&normals.values[1], &colors[4],
                   ((CVECTOR *)( &polygons[2].r3 )) );
    (((P_TAG *)(  &polygons[0]  ))->len  = (u8)(  8 )) ,  (((P_TAG *)(  &polygons[0]  ))->code = (u8)(  0x38 ))  ;
    (((P_TAG *)(  &polygons[1]  ))->len  = (u8)(  8 )) ,  (((P_TAG *)(  &polygons[1]  ))->code = (u8)(  0x38 ))  ;
    (((P_TAG *)(  &polygons[2]  ))->len  = (u8)(  8 )) ,  (((P_TAG *)(  &polygons[2]  ))->code = (u8)(  0x38 ))  ;
    vertices[0].vx = 1000;
    vertices[2].vx = 1600;
    vertices[4].vx = 2200;
    vertices[0].vy = height;
    vertices[0].vz = 0;
    vertices[2].vy = height;
    vertices[2].vz = 0;
    vertices[4].vy = height;
    vertices[4].vz = 0;
    vertices[6].vx = 2800;
    vertices[6].vy = height;
    vertices[6].vz = 0;
    vertices[1].vy = height;
    vertices[3].vy = height;
    vertices[5].vy = height;
    vertices[7].vy = height;
    func_800855D0(func_80059220());
    phase = 256;
    do {
        cosine = func_80086770(phase);
        sine = func_800866A0(phase);
        vertices[1].vx = 1000 * cosine / 4096;
        vertices[1].vz = 1000 * sine / 4096;
        vertices[3].vx = 1600 * cosine / 4096;
        vertices[3].vz = 1600 * sine / 4096;
        vertices[5].vx = 2200 * cosine / 4096;
        vertices[5].vz = 2200 * sine / 4096;
        vertices[7].vx = 2800 * cosine / 4096;
        vertices[7].vz = 2800 * sine / 4096;
        first_depth = func_80087AB0(&vertices[0], &vertices[1], &vertices[2], &vertices[3],
            (long *)&polygons[0].x0, (long *)&polygons[0].x1,
            (long *)&polygons[0].x2, (long *)&polygons[0].x3,
            &projection[0], &projection[1]);
        second_depth = func_80087AB0(&vertices[4], &vertices[5], &vertices[6], &vertices[7],
            (long *)&polygons[2].x0, (long *)&polygons[2].x1,
            (long *)&polygons[2].x2, (long *)&polygons[2].x3,
            &projection[2], &projection[3]);
        polygons[1].x0 = (u16)polygons[0].x2;
        polygons[1].y0 = (u16)polygons[0].y2;
        polygons[1].x1 = (u16)polygons[0].x3;
        polygons[1].y1 = (u16)polygons[0].y3;
        polygons[1].x2 = (u16)polygons[2].x0;
        polygons[1].y2 = (u16)polygons[2].y0;
        polygons[1].x3 = (u16)polygons[2].x1;
        polygons[1].y3 = (u16)polygons[2].y1;
        if (first_depth >= 0) {
            func_80084320(&polygons[0], D_800E9D90[3],
                (u16)((1u << D_800E9D90[3]->length) - 1));
        } else if (second_depth < 0) {
            goto advance;
        }
        func_80084320(&polygons[1], D_800E9D90[3],
            (u16)((1u << D_800E9D90[3]->length) - 1));
        if (second_depth >= 0)
            func_80084320(&polygons[2], D_800E9D90[3],
                (u16)((1u << D_800E9D90[3]->length) - 1));
advance:
        phase += 256;
        vertices[0] = vertices[1];
        vertices[2] = vertices[3];
        vertices[4] = vertices[5];
        vertices[6] = vertices[7];
    } while (phase <= 4096);
}
