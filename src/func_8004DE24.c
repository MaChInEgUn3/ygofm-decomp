/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/func_8004DE24.c, profile gcc_2_8_1_g8_split.
 * The declarations above the function are the subset of that tree's headers
 * this unit needs, preprocessed and with symbols renamed to this tree's
 * spelling (func_ADDR, D_ADDR); their types are that tree's. Byte-identical
 * under the flag row in tools_src/build.py. */
typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
typedef struct  {
	short	m[3][3];	 
        long    t[3];		 
} MATRIX;
typedef struct {		 
	short	vx, vy;
	short	vz, pad;
} SVECTOR;
typedef struct {		 
	u8	r, g, b, cd;
} CVECTOR;
extern void func_80089C20(SVECTOR *v0,CVECTOR *v1,CVECTOR *v2);
extern long func_80087AB0(SVECTOR *v0,SVECTOR *v1,SVECTOR *v2,SVECTOR *v3,
			long *sxy0,long *sxy1,long *sxy2,long *sxy3,
			long *p,long *flag);
extern int func_80086770(int a);
extern int func_800866A0(int a);
typedef struct {
	unsigned	addr: 24;
	unsigned 	len:   8;
	u8		r0, g0, b0, code;
} P_TAG;
typedef struct {
	u32	tag;
	u8	r0, g0, b0, code;
	short	x0, 	y0;
	u8	r1, g1, b1, pad1;
	short	x1,	y1;
	u8	r2, g2, b2, pad2;
	short	x2,	y2;
	u8	r3, g3, b3, pad3;
	short	x3,	y3;
} POLY_G4;
typedef struct {
	int     vx, vy, vz;
	unsigned char r, g, b;
}       GsF_LIGHT;
typedef struct {
	unsigned p:24;
	unsigned char num:8;
}       GsOT_TAG;
typedef struct {
	unsigned long length;
	GsOT_TAG *org;
	unsigned long offset;
	unsigned long point;
	GsOT_TAG *tag;
}       GsOT;
typedef struct {
	unsigned long attribute;
	short   x, y;
	unsigned short w, h;
	unsigned short tpage;
	unsigned char u, v;
	short   cx, cy;
	unsigned char r, g, b;
	short   mx, my;
	short   scalex, scaley;
	long    rotate;
}       GsSPRITE;
int     func_800857E0(int id, GsF_LIGHT * lt);
void    func_80085D50(long r, long g, long b);
void    func_800849F0(GsSPRITE * sp, GsOT * ot, unsigned short pri);
void    func_80084320(void *pp, GsOT * ot, unsigned short pri);
void    func_80085600(MATRIX * mp);
void    func_800855D0(MATRIX * mp);
typedef struct _GsCOORDUNIT {
	unsigned long		flg;
	MATRIX			matrix;
	MATRIX			workm;
	SVECTOR			rot;
	struct _GsCOORDUNIT	*super;
}	GsCOORDUNIT;
typedef struct {
    u32 field_00;
    void *field_04;
} ModelSlotHeadEntry;
typedef struct {
    u16 values[58 ];
    u16 max;
} ModelSlotRow;
typedef struct {
    u32 rewrite_idx;
    u16 size;
    u16 num;
    u16 ii;
    u16 aframe;
    u8 sid;
    s8 speed;
    u16 srcii;
    s16 rframe;
    u16 tframe;
    u16 ci;
    u16 ti;
    u16 start;
    u8 start_sid;
    u8 traveling;
} ModelSlotPart;
typedef struct {
    u8 frame;
    u8 id;
    u16 flags;
} ModelSlotSoundEntry;
typedef struct {
    s32 field_00;
    s32 field_04;
    s32 field_08;
    u8 field_0C[3];
    u8 pad_0F;
} ModelSlotLightEntry;
typedef struct {
    s32 field_00;
    s32 field_04;
    s32 field_08;
    s32 field_0C;
} ModelSlotS32Quad;
typedef union {
    struct {
        u8 field_00[0xA];
        u8 field_0A[2];
    } bytes;
    struct {
        u16 field_00;
        u16 field_02;
        u8 field_04[4];
        u32 field_08;
    } values;
     




    struct {
        u8 pad_00[7];
        u8 min_x;
        u8 min_y;
        u8 min_z;
        u8 pad_0A[2];
    } thresholds;
} ModelSlotCF8Prefix;
typedef struct {
    ModelSlotCF8Prefix prefix;
    u16 field_0C[2];
    s32 field_10;
    s32 field_14;
    s32 field_18;
} ModelSlotCF8Block;
typedef struct {
    ModelSlotHeadEntry field_000[60 ];
    ModelSlotPart *field_1E0[58 ];
     



    u16 field_2C8[10 ][58 ];
    ModelSlotRow field_750[10 ];
     



    u8 field_BEC[8];
    u8 field_BF4;
    u8 field_BF5;
    u8 field_BF6;
    u8 field_BF7;
    ModelSlotSoundEntry sound_entries[64 ];
    ModelSlotCF8Block field_CF8;
    u8 *entries;
     



    struct _GsCOORDUNIT *field_D18;
     

    struct _GsCOORDUNIT *field_D1C;
    u8 pad_D20[0x50];
    ModelSlotLightEntry field_D70[3];
    s32 field_DA0[3];
    u8 pad_DAC[4];
    ModelSlotS32Quad field_DB0;
    u8 field_DC0[8];
    u16 field_DC8[4];
    s16 field_DD0[4];
     



    s32 *field_DD8;
    u8 *field_DDC;
    u8 *field_DE0;
    u8 *field_DE4;
     

    s32 field_DE8;
    s32 field_DEC;
     



    s32 field_DF0;
    s32 field_DF4;
    u16 field_DF8;
    u16 field_DFA;
    u16 field_DFC;
    u8 field_DFE;
    u8 field_DFF;
     


    u16 field_E00;
     
    u16 field_E02;
    u16 field_E04;
    u16 field_E06;
     



    u16 field_E08;
     


    u16 field_E0A;
     


    u8 field_E0C;
    u8 field_E0D;
    u8 field_E0E;
    u8 field_E0F;
    u8 field_E10;
    u8 field_E11;
    u8 field_E12;
    u8 field_E13;
    u8 field_E14;
    u8 field_E15;
    u8 field_E16;
    u8 entry_count;
    u8 field_E18;
    u8 field_E19;
    u8 field_E1A;
    u8 field_E1B;
    u8 field_E1C;
     



    u8 field_E1D;
    u8 field_E1E;
    u8 field_E1F;
} ModelSlot;
typedef char ModelSlot_field_750_max_offset_must_be_0x7C4[
    ((u32)&((( ModelSlot  *)0)->  field_750[0].max ))  == 0x7C4 ? 1 : -1
];
extern ModelSlot D_800F2C40[3 ];
typedef struct {
    u8 pad_00[0xA4];
    u16 stage_height;
    u16 texture_width;
     
    u16 field_A8;
     
    u16 field_AA;
    u8 pad_AC[0x06];
} ModelBackgroundRecord;
typedef struct {
    SVECTOR values[2];
} BackgroundNormals;
void func_8004DE24(void);
void *func_80059220(void);
extern u8 *D_8009AF88;
extern s16 D_8009AF8E;
extern s16 D_8009AF90;
void func_8004E7B0(s32 force);
extern GsCOORDUNIT D_800F56A0;
extern GsOT *D_800E9D90[4];
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
