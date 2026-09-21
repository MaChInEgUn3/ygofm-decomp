/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/func_8006CD78.c, profile gcc_2_8_1_g8_split.
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
	long	vx, vy;
	long	vz, pad;
} VECTOR;
typedef struct {		 
	short	vx, vy;
	short	vz, pad;
} SVECTOR;
extern MATRIX *func_80087480(MATRIX *m0,MATRIX *m1);
extern MATRIX *func_80087D30(SVECTOR *r,MATRIX *m);
extern MATRIX *func_80087670(MATRIX *m,VECTOR *v);
extern void func_800871D0();
extern void func_80087274();
extern void func_80087970(SVECTOR *v0,VECTOR *v1,long *flag);
extern long func_80087AB0(SVECTOR *v0,SVECTOR *v1,SVECTOR *v2,SVECTOR *v3,
			long *sxy0,long *sxy1,long *sxy2,long *sxy3,
			long *p,long *flag);
extern int func_80086920(int a);
extern int func_80086BB0(int a);
typedef struct {
	short x, y;		 
	short w, h;		 
} RECT;
typedef struct {
	unsigned	addr: 24;
	unsigned 	len:   8;
	u8		r0, g0, b0, code;
} P_TAG;
typedef struct {
	u32	tag;
	u8	r0, g0, b0, code;
	short	x0, 	y0;
	u8	u0, v0;	u16	clut;
	short	x1,	y1;
	u8	u1, v1;	u16	tpage;
	short	x2,	y2;
	u8	u2, v2;	u16	pad1;
	short	x3,	y3;
	u8	u3, v3;	u16	pad2;
} POLY_FT4;
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
void    func_800855D0(MATRIX * mp);
extern void *func_8008E3D0 ( );
extern int  func_8008E590(void);
typedef struct {
    s16 x;
    s16 y;
    s16 z;
    s16 max;
} ModelEffectAdjustment;
extern VECTOR D_8001188C;
void func_80057E20(s32 index, ModelEffectAdjustment *out);
s32 func_80058E1C(void);
void func_80058FB0(s32 idx, u16 *out);
GsOT *func_80058F10(void);
void func_8005B260(u32 *src, GsOT *ot, s32 idx, s32 flags);
s32 func_80058DCC(void);
typedef struct {
    u8 r;
    u8 g;
    u8 b;
    u8 pad;
} ModelBurstColor;
typedef struct {
    u8 r[3];
    u8 g[3];
    u8 b[3];
} ModelBurstPalette;
typedef struct {
    u16 mode;
    u16 unk_02;
    RECT prect;
    u32 *paddr;
    RECT crect;
    u32 *caddr;
} ModelBurstImage;
typedef struct {
    u16 tpage;
    u16 clut;
} ModelBurstTexture;
typedef struct {
    ModelBurstPalette *table;
    s32 frame;
    SVECTOR rings[3];
    SVECTOR ring_speed[3];
    SVECTOR dust[64];
    SVECTOR dust_speed[64];
    SVECTOR sparks[32];
    SVECTOR spark_drift[32];
    SVECTOR spark_rise[32];
    SVECTOR embers[32];
    SVECTOR smoke[64];
    SVECTOR smoke_speed[64];
    SVECTOR origin;
    u16 dust_frame[64];
    u16 spark_frame[32];
    u16 smoke_frame[64];
    u16 radius;
    u16 phase;
    u16 stage;
    u16 spark_count;
    u8 fade;
    u8 pad_d89;
    u16 tpage;
    u16 clut;
    ModelBurstTexture spark_texture[1];
    ModelBurstColor colors[3];
    u8 flash_r;
    u8 flash_g;
    u8 flash_b;
    u8 pad_da1;
    ModelBurstColor spark_colors[32];
    u8 smoke_r;
    u8 smoke_g;
    u8 smoke_b;
} ModelBurstEffect;
s32 func_8006CD78(void *data, s32 arg1);
extern u16 D_80091610[];
extern u32 D_800916D4[];
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
void func_80059590(
    s32 slot,
    s32 mode,
    s32 target0,
    s32 target1,
    s32 target2
);
void func_80059AEC(s32 value);
void *func_80059220(void);
void func_80048658(s32 id, s32 volume, s32 pan);
s32 func_8006CD78(void *data, s32 arg1)
{
    MATRIX ls;
    MATRIX m;
    POLY_FT4 ft4;
    SVECTOR rot;
    SVECTOR pos;
    VECTOR scale;
    SVECTOR q[4];
    s32 flag;
    s32 p;
    s32 slot;
    GsOT *ot;
    s16 sign;
    ModelBurstEffect *e;
    s32 j;
    s32 k;
    s32 l;
    s32 i;
    s32 otz;
    POLY_FT4 *f;

    f = &ft4;
    func_8008E3D0(&rot, 0, 8);
    func_8008E3D0(&pos, 0, 8);
    scale = D_8001188C;
    e = data;
    slot = func_80058DCC();

    if (arg1 >= 0) {
        e->table = (ModelBurstPalette *)D_800916D4;
        e->tpage = 0xAE;
        e->clut = 0x3D20;
        for (i = 0; i < 1; i++) {
            e->spark_texture[i].tpage = (((( ((ModelBurstImage *)D_80091610) [i].mode )&0x3)<<7)|(((  1 )&0x3)<<5)|((( 
                                                 ((ModelBurstImage *)D_80091610) [i].prect.y )&0x100)>>4)|(((  ((ModelBurstImage *)D_80091610) [i].prect.x )&0x3ff)>>6)| (((                                                   ((ModelBurstImage *)D_80091610) [i].prect.y )&0x200)<<2)) ;
            e->spark_texture[i].clut = (((  ((ModelBurstImage *)D_80091610) [i].crect.y )<<6)|((( ((ModelBurstImage *)D_80091610) [i].crect.x )>>4)&0x3f)) ;
        }
        func_80057E20(slot, (ModelEffectAdjustment *)&pos);
        for (i = 0; i < 3; i++) {
            ( &e->rings[i] )->vx =   ((s16)(( pos ).vz < ( pos ).vx ? ( pos ).vx : ( pos ).vz))  * (func_80086920(i * 0x555) << 1) / 4096 , ( &e->rings[i] )->vy =   0 , ( &e->rings[i] )->vz =  
                      ((s16)(( pos ).vz < ( pos ).vx ? ( pos ).vx : ( pos ).vz))  * (func_80086BB0(i * 0x555) << 1) / 4096  ;
            ( &e->ring_speed[i] )->vx =   -e->rings[i].vx / 48 , ( &e->ring_speed[i] )->vy =   0 , ( &e->ring_speed[i] )->vz =   -e->rings[i].vz / 48  ;
            e->colors[i].r = e->table->r[i] >> 3;
            e->colors[i].g = e->table->g[i] >> 3;
            e->colors[i].b = e->table->b[i] >> 3;
        }
        e->radius = ((s16)(( pos ).vz < ( pos ).vx ? ( pos ).vx : ( pos ).vz))  / 2 + 200;
        if (e->radius > 0x200) {
            e->radius = 0x200;
        }
        e->flash_r = 0x80;
        e->flash_g = 0x80;
        e->flash_b = 0x80;
        for (i = 0; i < 64; i++) {
            l = (func_8008E590() - func_8008E590()) % 4096;
            j = (func_8008E590() - func_8008E590()) % 4096;
            ( &e->dust[i] )->vx =   e->radius * l / 4096 , ( &e->dust[i] )->vy =   0 , ( &e->dust[i] )->vz =   e->radius * j / 4096  ;
            ( &e->dust_speed[i] )->vx =   l * 24 / 4096 , ( &e->dust_speed[i] )->vy =   -(func_8008E590() % 4096 * 24) / 4096 , ( &e->dust_speed[i] )->vz =  
                      j * 24 / 4096  ;
            e->dust_frame[i] = func_8008E590() % 4;
        }
        for (i = 0; i < 32; i++) {
            ( &e->sparks[i] )->vx =   e->radius * func_80086920(i << 7) / 4096 , ( &e->sparks[i] )->vy =   0 , ( &e->sparks[i] )->vz =  
                      e->radius * func_80086BB0(i << 7) / 4096  ;
            ( &e->spark_drift[i] )->vx =   -e->sparks[i].vx / 128 , ( &e->spark_drift[i] )->vy =   -0x10 , ( &e->spark_drift[i] )->vz =   -e->sparks[i].vz / 128  ;
            ( &e->spark_rise[i] )->vx =   func_80086920(i << 7) / 128 , ( &e->spark_rise[i] )->vy =   0 , ( &e->spark_rise[i] )->vz =   func_80086BB0(i << 7) / 128  ;
            e->spark_frame[i] = func_8008E590() % 8;
            e->spark_colors[i].r = 1;
            e->spark_colors[i].g = 1;
            e->spark_colors[i].b = 1;
        }
        for (i = 0; i < 32; i++) {
            ( &e->embers[i] )->vx =   (func_8008E590() - func_8008E590()) % 4096 * 0xA0 / 4096 , ( &e->embers[i] )->vy =  
                      (func_8008E590() - func_8008E590()) % 4096 * 0xA0 / 4096 , ( &e->embers[i] )->vz =  
                      (func_8008E590() - func_8008E590()) % 4096 * 0xA0 / 4096  ;
        }
        for (i = 0; i < 64; i++) {
            ( &e->smoke[i] )->vx =   0 , ( &e->smoke[i] )->vy =   0 , ( &e->smoke[i] )->vz =   0  ;
            ( &e->smoke_speed[i] )->vx =   (func_8008E590() - func_8008E590()) % 4096 * 0x60 / 4096 , ( &e->smoke_speed[i] )->vy =  
                      (func_8008E590() - func_8008E590()) % 4096 * 0x18 / 4096 , ( &e->smoke_speed[i] )->vz =  
                      (func_8008E590() - func_8008E590()) % 4096 * 0x60 / 4096  ;
            e->smoke_frame[i] = func_8008E590() % 4;
        }
        e->smoke_r = 0x80;
        e->smoke_g = 0x40;
        e->smoke_b = 0x79;
        func_80058FB0(slot, (u16 *)&rot);
        rot.vy = 0;
        ( &e->origin )->vx = (  &rot )->vx, ( &e->origin )->vy = (  &rot )->vy, ( &e->origin )->vz = (  &rot )->vz ;
        e->phase = 0;
        e->stage = 0;
        e->frame = 0;
        e->spark_count = 1;
        e->fade = 0;
        func_80048658(0, 0xFF, 0);
        return 0;
    }

    ot = func_80058F10();
    func_80058E1C();
    func_80059AEC(1);
    func_800871D0();
    ls = *(MATRIX *)func_80059220();
    func_80058FB0(slot, (u16 *)&pos);
    pos.vy = 0;
    ( &e->origin )->vx = (  &pos )->vx, ( &e->origin )->vy = (  &pos )->vy, ( &e->origin )->vz = (  &pos )->vz ;
    if (e->phase == 0) {
        rot.vx = 0;
        rot.vy = (e->frame * 0xA0) & 0xFFF;
        rot.vz = 0;
    }
    func_800855D0(&ls);
    func_80087970(&e->origin, ((VECTOR *)( m.t )) , (long *)&flag);
    func_80087D30(&rot, &m);
    func_80087480(&ls, &m);
    func_80087670(&m, &scale);
    func_800855D0(&m);
    (((P_TAG *)(  f  ))->len  = (u8)(  9 )) ,  (((P_TAG *)(  f  ))->code = (u8)(  0x2c ))  ;
    f->tpage = e->tpage;
    f->clut = e->clut;
    ( f )->u0 = (  0 ),      ( f )->v0 = (  0 ),	( f )->u1 = (  0 )+(  0x3F ), ( f )->v1 = (  0 ),	( f )->u2 = (  0 ),      ( f )->v2 = (  0 )+(  0x3F ),	( f )->u3 = (  0 )+(  0x3F ), ( f )->v3 = (  0 )+(  0x3F ) ;

    if (e->phase == 0) {
        for (i = 0; i < 3; i++) {
            if (e->colors[i].r != 0 || e->colors[i].g != 0 || e->colors[i].b != 0) {
                sign = 1;
                ( f )->r0 =   e->colors[i].r ,( f )->g0 =   e->colors[i].g ,( f )->b0 =   e->colors[i].b  ;
                for (j = 0; j < 4; j++) {
                    sign = sign * -1;
                    for (k = 0; k < 4; k++) {
                        s32 lo;
                        s32 hi;
                        for (l = 0, lo = -1, hi = 1; l < 4; lo--, l++, hi++) {
                            ( &q[0] )->vx =   (sign * -(e->radius >> 2) * ( k + 1 ))  , ( &q[0] )->vy =   0 , ( &q[0] )->vz =   (-(e->radius >> 2) * ( j - 2 < 0 ? lo : hi ))   ;
                            ( &q[1] )->vx =   (sign * -(e->radius >> 2) * ( k ))  , ( &q[1] )->vy =   0 , ( &q[1] )->vz =   (-(e->radius >> 2) * ( j - 2 < 0 ? lo : hi ))   ;
                            ( &q[2] )->vx =   (sign * -(e->radius >> 2) * ( k + 1 ))  , ( &q[2] )->vy =   0 , ( &q[2] )->vz =   (-(e->radius >> 2) * ( j - 2 < 0 ? -l : l ))   ;
                            ( &q[3] )->vx =   (sign * -(e->radius >> 2) * ( k ))  , ( &q[3] )->vy =   0 , ( &q[3] )->vz =   (-(e->radius >> 2) * ( j - 2 < 0 ? -l : l ))   ;
                            ( &q[0] )->vx += (  &e->rings[i] )->vx,	( &q[0] )->vy += (  &e->rings[i] )->vy,	( &q[0] )->vz += (  &e->rings[i] )->vz ;
                            ( &q[1] )->vx += (  &e->rings[i] )->vx,	( &q[1] )->vy += (  &e->rings[i] )->vy,	( &q[1] )->vz += (  &e->rings[i] )->vz ;
                            ( &q[2] )->vx += (  &e->rings[i] )->vx,	( &q[2] )->vy += (  &e->rings[i] )->vy,	( &q[2] )->vz += (  &e->rings[i] )->vz ;
                            ( &q[3] )->vx += (  &e->rings[i] )->vx,	( &q[3] )->vy += (  &e->rings[i] )->vy,	( &q[3] )->vz += (  &e->rings[i] )->vz ;
                            ( f )->u0 = (  (3 - k) * 16 ),      ( f )->v0 = (  (3 - l) * 16 ),	( f )->u1 = (  (3 - k) * 16 )+(  0xF ), ( f )->v1 = (  (3 - l) * 16 ),	( f )->u2 = (  (3 - k) * 16 ),      ( f )->v2 = (  (3 - l) * 16 )+(  0xF ),	( f )->u3 = (  (3 - k) * 16 )+(  0xF ), ( f )->v3 = (  (3 - l) * 16 )+(  0xF ) ;
                            otz = func_80087AB0(&q[0], &q[1], &q[2], &q[3], (long *)&f->x0,
                                              (long *)&f->x1, (long *)&f->x2,
                                              (long *)&f->x3, (long *)&p, (long *)&flag);
                            if (otz >= 0 && flag >= 0) {
                                func_8005B260(((u32 *)( f )) , ot, otz & 0xFFFF, 1);
                            }
                        }
                    }
                }
                if ((( e->rings[i].vx ) >= 0 ? ( e->rings[i].vx ) : -( e->rings[i].vx ))  >= 0x21 || (( e->rings[i].vy ) >= 0 ? ( e->rings[i].vy ) : -( e->rings[i].vy ))  >= 0x21 ||
                    (( e->rings[i].vz ) >= 0 ? ( e->rings[i].vz ) : -( e->rings[i].vz ))  >= 0x21) {
                    ( &e->rings[i] )->vx += (  &e->ring_speed[i] )->vx,	( &e->rings[i] )->vy += (  &e->ring_speed[i] )->vy,	( &e->rings[i] )->vz += (  &e->ring_speed[i] )->vz ;
                } else {
                    if (e->phase == 0) {
                        e->phase = 1;
                    }
                    ( &e->rings[i] )->vx =   0 , ( &e->rings[i] )->vy =   0 , ( &e->rings[i] )->vz =   0  ;
                }
                if (e->phase == 0) {
                    if (e->colors[i].r < (e->table->r[i] >> 1) - 9) {
                        e->colors[i].r = e->colors[i].r + 8;
                    } else {
                        e->colors[i].r = e->table->r[i] >> 1;
                    }
                    if (e->colors[i].g < (e->table->g[i] >> 1) - 9) {
                        e->colors[i].g = e->colors[i].g + 8;
                    } else {
                        e->colors[i].g = e->table->g[i] >> 1;
                    }
                    if (e->colors[i].b < (e->table->b[i] >> 1) - 9) {
                        e->colors[i].b = e->colors[i].b + 8;
                    } else {
                        e->colors[i].b = e->table->b[i] >> 1;
                    }
                } else {
                    e->colors[0].r = 0x80;
                    e->colors[0].g = 0x20;
                    e->colors[0].b = 0x20;
                    e->colors[1].r = 0x20;
                    e->colors[1].g = 0x80;
                    e->colors[1].b = 0x20;
                    e->colors[2].r = 0x20;
                    e->colors[2].g = 0x20;
                    e->colors[2].b = 0x80;
                }
            }
        }
        if (e->phase == 0) {
            goto stage_test;
        }
    }

    if ((*(u32 *)((u8 *)( e ) + (  0xD9C )) & 0xFFFF0000)  != 0 || e->flash_b != 0) {
        ( f )->r0 =   e->flash_r ,( f )->g0 =   e->flash_g ,( f )->b0 =   e->flash_b  ;
        sign = 1;
        for (j = 0; j < 4; j++) {
            sign = sign * -1;
            for (i = 0; i < 4; i++) {
                s32 lo;
                s32 hi;
                for (l = 0, lo = -1, hi = 1; l < 4; lo--, l++, hi++) {
                    ( &q[0] )->vx =   (sign * -(e->radius >> 2) * ( i + 1 ))  , ( &q[0] )->vy =   0 , ( &q[0] )->vz =   (-(e->radius >> 2) * ( j - 2 < 0 ? lo : hi ))   ;
                    ( &q[1] )->vx =   (sign * -(e->radius >> 2) * ( i ))  , ( &q[1] )->vy =   0 , ( &q[1] )->vz =   (-(e->radius >> 2) * ( j - 2 < 0 ? lo : hi ))   ;
                    ( &q[2] )->vx =   (sign * -(e->radius >> 2) * ( i + 1 ))  , ( &q[2] )->vy =   0 , ( &q[2] )->vz =   (-(e->radius >> 2) * ( j - 2 < 0 ? -l : l ))   ;
                    ( &q[3] )->vx =   (sign * -(e->radius >> 2) * ( i ))  , ( &q[3] )->vy =   0 , ( &q[3] )->vz =   (-(e->radius >> 2) * ( j - 2 < 0 ? -l : l ))   ;
                    ( f )->u0 = (  (3 - i) * 16 ),      ( f )->v0 = (  (3 - l) * 16 ),	( f )->u1 = (  (3 - i) * 16 )+(  0xF ), ( f )->v1 = (  (3 - l) * 16 ),	( f )->u2 = (  (3 - i) * 16 ),      ( f )->v2 = (  (3 - l) * 16 )+(  0xF ),	( f )->u3 = (  (3 - i) * 16 )+(  0xF ), ( f )->v3 = (  (3 - l) * 16 )+(  0xF ) ;
                    otz = func_80087AB0(&q[0], &q[1], &q[2], &q[3], (long *)&f->x0,
                                      (long *)&f->x1, (long *)&f->x2,
                                      (long *)&f->x3, (long *)&p, (long *)&flag);
                    if (otz >= 0 && flag >= 0) {
                        func_8005B260(((u32 *)( f )) , ot, otz & 0xFFFF, 1);
                    }
                }
            }
        }
        if (e->stage >= 2) {
            if (e->flash_r >= 9) {
                e->flash_r = e->flash_r - 8;
            } else {
                e->flash_r = 0;
            }
            if (e->flash_g >= 9) {
                e->flash_g = e->flash_g - 8;
            } else {
                e->flash_g = 0;
            }
            if (e->flash_b >= 9) {
                e->flash_b = e->flash_b - 8;
            } else {
                e->flash_b = 0;
            }
            e->radius += 2;
        } else if (e->phase == 1) {
            if (e->flash_r < 0xF6) {
                e->flash_r = e->flash_r + 8;
            } else {
                e->flash_r = 0xFF;
            }
            if (e->flash_g < 0xF6) {
                e->flash_g = e->flash_g + 8;
            } else {
                e->flash_g = 0xFF;
            }
            if (e->flash_b < 0xF6) {
                e->flash_b = e->flash_b + 8;
            } else {
                e->flash_b = 0xFF;
            }
            e->radius += 4;
            if ((*(u32 *)((u8 *)( e ) + (  0xD9C )) & 0xFFFF0000)  == 0xFFFF0000 && e->flash_b == 0xFF) {
                e->phase = 2;
            }
        } else if (e->phase == 2) {
            if (e->flash_r < 0x89) {
                e->flash_r = 0x80;
            } else {
                e->flash_r = e->flash_r - 8;
            }
            if (e->flash_g < 0x89) {
                e->flash_g = 0x80;
            } else {
                e->flash_g = e->flash_g - 8;
            }
            if (e->flash_b < 0x89) {
                e->flash_b = 0x80;
            } else {
                e->flash_b = e->flash_b - 8;
            }
            e->radius -= 2;
            if ((*(u32 *)((u8 *)( e ) + (  0xD9C )) & 0xFFFF0000)  == 0x80800000 && e->flash_b == 0x80) {
                e->phase = 1;
            }
        }
    }

    if (((*(u32 *)((u8 *)( e ) + (  0xD90 )) & 0xFFFF0000)  != 0 || e->colors[0].b != 0) &&
        ((*(u32 *)((u8 *)( e ) + (  0xD94 )) & 0xFFFF0000)  != 0 || e->colors[1].b != 0) &&
        ((*(u32 *)((u8 *)( e ) + (  0xD98 )) & 0xFFFF0000)  != 0 || e->colors[2].b != 0)) {
        func_800855D0(&ls);
        func_80087970(&e->origin, ((VECTOR *)( m.t )) , (long *)&flag);
        func_80087D30(&rot, &m);
        func_80087670(&m, &scale);
        func_800855D0(&m);
        for (i = 0; i < 64; i++) {
            ( f )->r0 =   e->colors[i % 3].r ,( f )->g0 =   e->colors[i % 3].g ,( f )->b0 =   e->colors[i % 3].b  ;
            ( f )->u0 = (  (e->dust_frame[i] % 2) << 5 ),      ( f )->v0 = (  (e->dust_frame[i] / 2 << 5) + 0x40 ),	( f )->u1 = (  (e->dust_frame[i] % 2) << 5 )+(  0x1F ), ( f )->v1 = (  (e->dust_frame[i] / 2 << 5) + 0x40 ),	( f )->u2 = (  (e->dust_frame[i] % 2) << 5 ),      ( f )->v2 = (  (e->dust_frame[i] / 2 << 5) + 0x40 )+(  0x1F ),	( f )->u3 = (  (e->dust_frame[i] % 2) << 5 )+(  0x1F ), ( f )->v3 = (  (e->dust_frame[i] / 2 << 5) + 0x40 )+(  0x1F ) ;
            ( &q[0] )->vx =   -0x20 , ( &q[0] )->vy =   -0x20 , ( &q[0] )->vz =   0  ;
            ( &q[1] )->vx =   0x20 , ( &q[1] )->vy =   -0x20 , ( &q[1] )->vz =   0  ;
            ( &q[2] )->vx =   -0x20 , ( &q[2] )->vy =   0x20 , ( &q[2] )->vz =   0  ;
            ( &q[3] )->vx =   0x20 , ( &q[3] )->vy =   0x20 , ( &q[3] )->vz =   0  ;
            for (l = 0; l < 4; l++) {
                ( &q[l] )->vx += (  &e->dust[i] )->vx,	( &q[l] )->vy += (  &e->dust[i] )->vy,	( &q[l] )->vz += (  &e->dust[i] )->vz ;
            }
            otz = func_80087AB0(&q[0], &q[1], &q[2], &q[3], (long *)&f->x0, (long *)&f->x1,
                              (long *)&f->x2, (long *)&f->x3, (long *)&p, (long *)&flag);
            if (otz >= 0) {
                if (flag >= 0) {
                    func_8005B260(((u32 *)( f )) , ot, otz & 0xFFFF, 1);
                }
            }
            ( &e->dust[i] )->vx += (  &e->dust_speed[i] )->vx,	( &e->dust[i] )->vy += (  &e->dust_speed[i] )->vy,	( &e->dust[i] )->vz += (  &e->dust_speed[i] )->vz ;
            e->dust_frame[i] = (e->dust_frame[i] + 1) % 4;
        }
        for (i = 0; i < 3; i++) {
            if (e->colors[i].r >= 0x10) {
                e->colors[i].r = e->colors[i].r - 0xF;
            } else {
                e->colors[i].r = 0;
            }
            if (e->colors[i].g >= 0x10) {
                e->colors[i].g = e->colors[i].g - 0xF;
            } else {
                e->colors[i].g = 0;
            }
            if (e->colors[i].b >= 0x10) {
                e->colors[i].b = e->colors[i].b - 0xF;
            } else {
                e->colors[i].b = 0;
            }
        }
    }

    f->tpage = e->spark_texture[0].tpage;
    f->clut = e->spark_texture[0].clut;
    ( &q[0] )->vx =   -0x40 , ( &q[0] )->vy =   -0x100 , ( &q[0] )->vz =   0  ;
    ( &q[1] )->vx =   0x40 , ( &q[1] )->vy =   -0x100 , ( &q[1] )->vz =   0  ;
    ( &q[2] )->vx =   -0x40 , ( &q[2] )->vy =   0 , ( &q[2] )->vz =   0  ;
    ( &q[3] )->vx =   0x40 , ( &q[3] )->vy =   0 , ( &q[3] )->vz =   0  ;
    for (i = 0; i < e->spark_count; i++) {
        if (e->spark_colors[i].r != 0 || e->spark_colors[i].g != 0 ||
            e->spark_colors[i].b != 0) {
            ( &pos )->vx = (  &e->origin )->vx, ( &pos )->vy = (  &e->origin )->vy, ( &pos )->vz = (  &e->origin )->vz ;
            ( &pos )->vx += (  &e->sparks[i] )->vx,	( &pos )->vy += (  &e->sparks[i] )->vy,	( &pos )->vz += (  &e->sparks[i] )->vz ;
            func_800855D0(&ls);
            func_80087970(&pos, ((VECTOR *)( m.t )) , (long *)&flag);
            func_80087D30(&rot, &m);
            func_80087670(&m, &scale);
            func_800855D0(&m);
            ( f )->u0 = (  e->spark_frame[i] * 32 ),      ( f )->v0 = (  0 ),	( f )->u1 = (  e->spark_frame[i] * 32 )+(  0x1F ), ( f )->v1 = (  0 ),	( f )->u2 = (  e->spark_frame[i] * 32 ),      ( f )->v2 = (  0 )+(  0x3F ),	( f )->u3 = (  e->spark_frame[i] * 32 )+(  0x1F ), ( f )->v3 = (  0 )+(  0x3F ) ;
            ( f )->r0 =   e->spark_colors[i].r ,( f )->g0 =   e->spark_colors[i].g ,( f )->b0 =   e->spark_colors[i].b  ;
            otz = func_80087AB0(&q[0], &q[1], &q[2], &q[3], (long *)&f->x0, (long *)&f->x1,
                              (long *)&f->x2, (long *)&f->x3, (long *)&p, (long *)&flag);
            if (otz >= 0 && flag >= 0) {
                func_8005B260(((u32 *)( f )) , ot, otz & 0xFFFF, 1);
            }
            e->spark_frame[i] = (e->spark_frame[i] + 1) % 8;
            if (e->stage < 2) {
                if (e->spark_colors[i].r < 0x61) {
                    e->spark_colors[i].r = e->spark_colors[i].r + 0x1F;
                } else {
                    e->spark_colors[i].r = 0x80;
                }
                if (e->spark_colors[i].g < 0x61) {
                    e->spark_colors[i].g = e->spark_colors[i].g + 0x1F;
                } else {
                    e->spark_colors[i].g = 0x80;
                }
                if (e->spark_colors[i].b < 0x61) {
                    e->spark_colors[i].b = e->spark_colors[i].b + 0x1F;
                } else {
                    e->spark_colors[i].b = 0x80;
                }
            }
            if (e->stage == 1) {
                ( &e->sparks[i] )->vx += (  &e->spark_drift[i] )->vx,	( &e->sparks[i] )->vy += (  &e->spark_drift[i] )->vy,	( &e->sparks[i] )->vz += (  &e->spark_drift[i] )->vz ;
            }
            if (e->stage == 2) {
                ( &e->sparks[i] )->vx += (  &e->spark_rise[i] )->vx,	( &e->sparks[i] )->vy += (  &e->spark_rise[i] )->vy,	( &e->sparks[i] )->vz += (  &e->spark_rise[i] )->vz ;
                e->spark_rise[i].vy += 2;
                if (e->spark_colors[i].r >= 9) {
                    e->spark_colors[i].r = e->spark_colors[i].r - 8;
                } else {
                    e->spark_colors[i].r = 0;
                }
                if (e->spark_colors[i].g >= 9) {
                    e->spark_colors[i].g = e->spark_colors[i].g - 8;
                } else {
                    e->spark_colors[i].g = 0;
                }
                if (e->spark_colors[i].b >= 9) {
                    e->spark_colors[i].b = e->spark_colors[i].b - 8;
                } else {
                    e->spark_colors[i].b = 0;
                }
            }
        }
    }

    if ((e->spark_colors[e->spark_count - 1].r >= 0x41 ||
         e->spark_colors[e->spark_count - 1].g >= 0x41 ||
         e->spark_colors[e->spark_count - 1].b >= 0x41) &&
        e->stage == 0) {
        if ((u16)(e->spark_count % 3) == 0) {
            func_80048658(1, 0xFF, 0);
        }
        e->spark_count++;
        if (e->spark_count > 32) {
            e->spark_count = 32;
            e->stage = 1;
        }
    }
stage_test:
    if (e->stage >= 2 && ((*(u32 *)((u8 *)( e ) + (  0xE20 )) & 0xFFFF0000)  != 0 || e->smoke_b != 0)) {
        f->tpage = e->tpage;
        f->clut = e->clut;
        ( &pos )->vx =   0 , ( &pos )->vy =   -0x220 , ( &pos )->vz =   0  ;
        ( &pos )->vx += (  &e->origin )->vx,	( &pos )->vy += (  &e->origin )->vy,	( &pos )->vz += (  &e->origin )->vz ;
        func_800855D0(&ls);
        func_80087970(&pos, ((VECTOR *)( m.t )) , (long *)&flag);
        func_80087D30(&rot, &m);
        func_80087670(&m, &scale);
        func_800855D0(&m);
        sign = 1;
        for (i = 0; i < 4; i++) {
            sign = sign * -1;
            ( &q[0] )->vx =   -((sign << 16) >> 9) , ( &q[0] )->vy =   i - 2 >= 0 ? -0x80 : 0x80 , ( &q[0] )->vz =   0  ;
            ( &q[1] )->vx =   0 , ( &q[1] )->vy =   i - 2 >= 0 ? -0x80 : 0x80 , ( &q[1] )->vz =   0  ;
            ( &q[2] )->vx =   -((sign << 16) >> 9) , ( &q[2] )->vy =   0 , ( &q[2] )->vz =   0  ;
            ( &q[3] )->vx =   0 , ( &q[3] )->vy =   0 , ( &q[3] )->vz =   0  ;
            ( f )->r0 =   e->smoke_r ,( f )->g0 =   e->smoke_g ,( f )->b0 =   e->smoke_b  ;
            ( f )->u0 = (  0x40 ),      ( f )->v0 = (  0 ),	( f )->u1 = (  0x40 )+(  0x3F ), ( f )->v1 = (  0 ),	( f )->u2 = (  0x40 ),      ( f )->v2 = (  0 )+(  0x3F ),	( f )->u3 = (  0x40 )+(  0x3F ), ( f )->v3 = (  0 )+(  0x3F ) ;
            otz = func_80087AB0(&q[0], &q[1], &q[2], &q[3], (long *)&f->x0, (long *)&f->x1,
                              (long *)&f->x2, (long *)&f->x3, (long *)&p, (long *)&flag);
            if (otz >= 0) {
                if (flag >= 0) {
                    func_8005B260(((u32 *)( f )) , ot, otz & 0xFFFF, 1);
                }
            }
            ( f )->r0 =   e->smoke_r >> 1 ,( f )->g0 =   e->smoke_g >> 1 ,( f )->b0 =   e->smoke_b >> 1  ;
            ( f )->u0 = (  0x40 ),      ( f )->v0 = (  0x40 ),	( f )->u1 = (  0x40 )+(  0x3F ), ( f )->v1 = (  0x40 ),	( f )->u2 = (  0x40 ),      ( f )->v2 = (  0x40 )+(  0x3F ),	( f )->u3 = (  0x40 )+(  0x3F ), ( f )->v3 = (  0x40 )+(  0x3F ) ;
            otz = func_80087AB0(&q[0], &q[1], &q[2], &q[3], (long *)&f->x0, (long *)&f->x1,
                              (long *)&f->x2, (long *)&f->x3, (long *)&p, (long *)&flag);
            if (otz >= 0 && flag >= 0) {
                func_8005B260(((u32 *)( f )) , ot, otz & 0xFFFF, 1);
            }
        }
        ( f )->u0 = (  0 ),      ( f )->v0 = (  0x80 ),	( f )->u1 = (  0 )+(  0x1F ), ( f )->v1 = (  0x80 ),	( f )->u2 = (  0 ),      ( f )->v2 = (  0x80 )+(  0x7F ),	( f )->u3 = (  0 )+(  0x1F ), ( f )->v3 = (  0x80 )+(  0x7F ) ;
        ( &q[0] )->vx =   -4 , ( &q[0] )->vy =   0 , ( &q[0] )->vz =   0  ;
        ( &q[1] )->vx =   4 , ( &q[1] )->vy =   0 , ( &q[1] )->vz =   0  ;
        ( f )->r0 =   e->smoke_r >> 2 ,( f )->g0 =   e->smoke_g >> 2 ,( f )->b0 =   e->smoke_b >> 2  ;
        for (i = 0; i < 32; i++) {
            ( &q[2] )->vx =   -2 , ( &q[2] )->vy =   0 , ( &q[2] )->vz =   0  ;
            ( &q[3] )->vx =   2 , ( &q[3] )->vy =   0 , ( &q[3] )->vz =   0  ;
            ( &q[2] )->vx += (  &e->embers[i] )->vx,	( &q[2] )->vy += (  &e->embers[i] )->vy,	( &q[2] )->vz += (  &e->embers[i] )->vz ;
            ( &q[3] )->vx += (  &e->embers[i] )->vx,	( &q[3] )->vy += (  &e->embers[i] )->vy,	( &q[3] )->vz += (  &e->embers[i] )->vz ;
            otz = func_80087AB0(&q[0], &q[1], &q[2], &q[3], (long *)&f->x0, (long *)&f->x1,
                              (long *)&f->x2, (long *)&f->x3, (long *)&p, (long *)&flag);
            if (otz >= 0 && flag >= 0) {
                func_8005B260(((u32 *)( f )) , ot, otz & 0xFFFF, 1);
            }
        }
        for (i = 0; i < 64; i++) {
            ( f )->r0 =   e->smoke_r ,( f )->g0 =   e->smoke_g ,( f )->b0 =   e->smoke_b  ;
            ( f )->u0 = (  (e->smoke_frame[i] % 2) << 5 ),      ( f )->v0 = (  (e->smoke_frame[i] / 2 << 5) + 0x40 ),	( f )->u1 = (  (e->smoke_frame[i] % 2) << 5 )+(  0x1F ), ( f )->v1 = (  (e->smoke_frame[i] / 2 << 5) + 0x40 ),	( f )->u2 = (  (e->smoke_frame[i] % 2) << 5 ),      ( f )->v2 = (  (e->smoke_frame[i] / 2 << 5) + 0x40 )+( 
                    0x1F ),	( f )->u3 = (  (e->smoke_frame[i] % 2) << 5 )+(  0x1F ), ( f )->v3 = (  (e->smoke_frame[i] / 2 << 5) + 0x40 )+(                      0x1F ) ;
            ( &q[0] )->vx =   -0x20 , ( &q[0] )->vy =   -0x20 , ( &q[0] )->vz =   0  ;
            ( &q[1] )->vx =   0x20 , ( &q[1] )->vy =   -0x20 , ( &q[1] )->vz =   0  ;
            ( &q[2] )->vx =   -0x20 , ( &q[2] )->vy =   0x20 , ( &q[2] )->vz =   0  ;
            ( &q[3] )->vx =   0x20 , ( &q[3] )->vy =   0x20 , ( &q[3] )->vz =   0  ;
            for (l = 0; l < 4; l++) {
                ( &q[l] )->vx += (  &e->smoke[i] )->vx,	( &q[l] )->vy += (  &e->smoke[i] )->vy,	( &q[l] )->vz += (  &e->smoke[i] )->vz ;
            }
            otz = func_80087AB0(&q[0], &q[1], &q[2], &q[3], (long *)&f->x0, (long *)&f->x1,
                              (long *)&f->x2, (long *)&f->x3, (long *)&p, (long *)&flag);
            if (otz >= 0) {
                if (flag >= 0) {
                    func_8005B260(((u32 *)( f )) , ot, otz & 0xFFFF, 1);
                }
            }
            ( &e->smoke[i] )->vx += (  &e->smoke_speed[i] )->vx,	( &e->smoke[i] )->vy += (  &e->smoke_speed[i] )->vy,	( &e->smoke[i] )->vz += (  &e->smoke_speed[i] )->vz ;
            e->smoke_frame[i] = (e->smoke_frame[i] + 1) % 4;
            e->smoke_speed[i].vy += 2;
        }
        if (e->smoke_r >= 0x10) {
            e->smoke_r = e->smoke_r - 0xF;
        } else {
            e->smoke_r = 0;
        }
        if (e->smoke_g >= 0x10) {
            e->smoke_g = e->smoke_g - 0xF;
        } else {
            e->smoke_g = 0;
        }
        if (e->smoke_b >= 0x10) {
            e->smoke_b = e->smoke_b - 0xF;
        } else {
            e->smoke_b = 0;
        }
    }

    if ((s8)e->fade >= 0) {
        func_80059590(slot, 5, e->fade, e->fade, e->fade);
    } else {
        func_80059590(slot, 0, 0x80, 0x80, 0x80);
    }
    if (e->stage != 0) {
        if (e->fade < 0x7C) {
            e->fade = e->fade + 4;
        } else {
            e->fade = 0x80;
            e->stage = 2;
        }
    }
    e->frame++;
    func_80087274();
    if ((*(u32 *)((u8 *)( e ) + (  0xE20 )) & 0xFFFF0000)  == 0 && e->smoke_b == 0 && (*(u32 *)((u8 *)( e ) + (  0xDA0 )) & 0xFFFF0000)  == 0 &&
        e->spark_colors[0].b == 0 && (*(u32 *)((u8 *)( e ) + (  0xD9C )) & 0xFFFF0000)  == 0 && e->flash_b == 0) {
        return 2;
    }
    return 0;
}
