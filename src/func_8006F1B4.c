/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/func_8006F1B4.c, profile gcc_2_8_1_g8_split.
 * The declarations above the function are the subset of that tree's headers
 * this unit needs, preprocessed and with symbols renamed to this tree's
 * spelling (func_ADDR, D_ADDR); their types are that tree's. Byte-identical
 * under the flag row in tools_src/build.py. */
#include "kg_types.h"
#include "kg_variables.h"
#include "kg_functions.h"
extern MATRIX *func_80087D30(SVECTOR *r,MATRIX *m);
extern void func_800871D0();
extern void func_80087274();
extern void func_80087970(SVECTOR *v0,VECTOR *v1,long *flag);
extern long func_80087AB0(SVECTOR *v0,SVECTOR *v1,SVECTOR *v2,SVECTOR *v3,
			long *sxy0,long *sxy1,long *sxy2,long *sxy3,
			long *p,long *flag);
extern void *func_8008E3D0 ( );
extern int  func_8008E590(void);
s32 func_80058E1C(void);
void func_80058FB0(s32 idx, u16 *out);
GsOT *func_80058F10(void);
void func_8005B260(u32 *src, GsOT *ot, s32 idx, s32 flags);
s32 func_80058DCC(void);
void func_80059590(
    s32 slot,
    s32 mode,
    s32 target0,
    s32 target1,
    s32 target2
);
s32 func_8006F1B4(void *data, s32 arg1);
extern VECTOR D_8001189C;
void func_80059AEC(s32 value);
void *func_80059220(void);
void func_80048658(s32 id, s32 volume, s32 pan);
s32 func_8006F1B4(void *data, s32 arg1)
{
    MATRIX ls;
    MATRIX m;
    POLY_FT4 ft4;
    POLY_G4 g4;
    SVECTOR rot;
    SVECTOR pos;
    VECTOR scale;
    SVECTOR q[4];
    s32 flag;
    s32 p;
    s32 slot;
    GsOT *ot;
    s16 sign;
    ModelSparkEffect *e;
    s32 i;
    s32 j;
    s32 k;
    s32 otz;
    POLY_FT4 *f;
    POLY_G4 *g;

    f = &ft4;
    g = &g4;
    func_8008E3D0(&rot, 0, 8);
    func_8008E3D0(&pos, 0, 8);
    scale = D_8001189C;
    e = data;
    slot = func_80058DCC();

    if (arg1 >= 0) {
        e->tpage = 0xAE;
        e->clut = 0x3D20;
        for (i = 0; i < 32; i++) {
            ( &e->sparks[i] )->vx =   ((func_8008E590() - func_8008E590()) % 4096 * ( 320 ) / 4096)  , ( &e->sparks[i] )->vy =   0 , ( &e->sparks[i] )->vz =   ((func_8008E590() - func_8008E590()) % 4096 * ( 320 ) / 4096)   ;
            e->spark_colors[i].r = 0x60;
            e->spark_colors[i].g = 0x60;
            e->spark_colors[i].b = 0x7F;
            e->sizes[i].size = 8;
            e->sizes[i].grow = 0x100;
            ( &e->flashes[i] )->vx =   ((func_8008E590() - func_8008E590()) % 4096 * ( 320 ) / 4096)  , ( &e->flashes[i] )->vy =   (-(func_8008E590() % 4096 * ( 128 )) / 4096)  , ( &e->flashes[i] )->vz =   ((func_8008E590() - func_8008E590()) % 4096 * ( 320 ) / 4096)   ;
            e->flash_colors[i].r = 0x40;
            e->flash_colors[i].g = 0x40;
            e->flash_colors[i].b = 0x55;
        }
        for (i = 0; i < 64; i++) {
            ( &e->dust[i] )->vx =   ((func_8008E590() - func_8008E590()) % 4096 * ( 160 ) / 4096)  , ( &e->dust[i] )->vy =   0 , ( &e->dust[i] )->vz =   ((func_8008E590() - func_8008E590()) % 4096 * ( 160 ) / 4096)   ;
            ( &e->dust_speed[i] )->vx =   ((func_8008E590() - func_8008E590()) % 4096 * ( 24 ) / 4096)  , ( &e->dust_speed[i] )->vy =   (-(func_8008E590() % 4096 * ( 24 )) / 4096)  , ( &e->dust_speed[i] )->vz =   ((func_8008E590() - func_8008E590()) % 4096 * ( 24 ) / 4096)   ;
            e->dust_frame[i] = func_8008E590() % 4;
        }
        e->dust_r = 0;
        e->dust_g = 0;
        e->dust_b = 0;
        e->spark_count = 0;
        e->flash_count = 0;
        e->mode = 0;
        e->frame = 0;
        e->fade = 0x80;
        return 0;
    }

    ot = func_80058F10();
    func_80058E1C();
    func_80059AEC(1);
    func_800871D0();
    ls = *(MATRIX *)func_80059220();
    func_80058FB0(slot, (u16 *)&pos);
    pos.vy = 0;
    func_800855D0(&ls);
    func_80087970(&pos, (VECTOR *)m.t, (long *)&flag);
    func_80087D30(&rot, &m);
    func_80087670(&m, &scale);
    func_800855D0(&m);
    (((P_TAG *)(  f  ))->len  = (u8)(  9 )) ,  (((P_TAG *)(  f  ))->code = (u8)(  0x2c ))  ;
    f->tpage = e->tpage;
    f->clut = e->clut;
    ( f )->u0 = (  0x40 ),      ( f )->v0 = (  0 ),	( f )->u1 = (  0x40 )+(  0x3F ), ( f )->v1 = (  0 ),	( f )->u2 = (  0x40 ),      ( f )->v2 = (  0 )+(  0x3F ),	( f )->u3 = (  0x40 )+(  0x3F ), ( f )->v3 = (  0 )+(  0x3F ) ;
    (((P_TAG *)(  g  ))->len  = (u8)(  8 )) ,  (((P_TAG *)(  g  ))->code = (u8)(  0x38 ))  ;

    for (i = 0; i < e->spark_count; i++) {
        if (e->spark_colors[i].r != 0 || e->spark_colors[i].g != 0 ||
            e->spark_colors[i].b != 0) {
            ( f )->r0 =   e->spark_colors[i].r ,( f )->g0 =   e->spark_colors[i].g ,( f )->b0 =   e->spark_colors[i].b  ;
            ( g )->r0 =   0 ,( g )->g0 =   0 ,( g )->b0 =   0  ;
            ( g )->r1 =   0 ,( g )->g1 =   0 ,( g )->b1 =   0  ;
            if (e->spark_count < 32) {
                ( g )->r2 =   e->spark_colors[i].r >> 1 ,( g )->g2 =   e->spark_colors[i].g >> 1 ,( g )->b2 =  
                        e->spark_colors[i].b >> 1  ;
                ( g )->r3 =   e->spark_colors[i].r >> 1 ,( g )->g3 =   e->spark_colors[i].g >> 1 ,( g )->b3 =  
                        e->spark_colors[i].b >> 1  ;
            } else {
                ( g )->r2 =   e->spark_colors[i].r ,( g )->g2 =   e->spark_colors[i].g ,( g )->b2 =   e->spark_colors[i].b  ;
                ( g )->r3 =   e->spark_colors[i].r ,( g )->g3 =   e->spark_colors[i].g ,( g )->b3 =   e->spark_colors[i].b  ;
            }
            sign = 1;
            for (j = 0; j < 4; j++) {
                sign = sign * -1;
                ( &q[0] )->vx =   -((sign << 16) >> 9) , ( &q[0] )->vy =   j - 2 >= 0 ? -0x80 : 0x80 , ( &q[0] )->vz =   0  ;
                ( &q[1] )->vx =   0 , ( &q[1] )->vy =   j - 2 >= 0 ? -0x80 : 0x80 , ( &q[1] )->vz =   0  ;
                ( &q[2] )->vx =   -((sign << 16) >> 9) , ( &q[2] )->vy =   0 , ( &q[2] )->vz =   0  ;
                ( &q[3] )->vx =   0 , ( &q[3] )->vy =   0 , ( &q[3] )->vz =   0  ;
                for (k = 0; k < 4; k++) {
                    ( &q[k] )->vx += (  &e->sparks[i] )->vx,	( &q[k] )->vy += (  &e->sparks[i] )->vy,	( &q[k] )->vz += (  &e->sparks[i] )->vz ;
                }
                otz = func_80087AB0(&q[0], &q[1], &q[2], &q[3], (long *)&f->x0, (long *)&f->x1,
                                  (long *)&f->x2, (long *)&f->x3, (long *)&p, (long *)&flag);
                if (otz >= 0 && flag >= 0) {
                    func_8005B260((u32 *)f, ot, otz & 0xFFFF, 1);
                }
            }
            ( &q[0] )->vx =   -e->sizes[i].size , ( &q[0] )->vy =   -e->sizes[i].grow , ( &q[0] )->vz =   0  ;
            ( &q[1] )->vx =   e->sizes[i].size , ( &q[1] )->vy =   -e->sizes[i].grow , ( &q[1] )->vz =   0  ;
            ( &q[2] )->vx =   -e->sizes[i].size , ( &q[2] )->vy =   0 , ( &q[2] )->vz =   0  ;
            ( &q[3] )->vx =   e->sizes[i].size , ( &q[3] )->vy =   0 , ( &q[3] )->vz =   0  ;
            for (k = 0; k < 4; k++) {
                ( &q[k] )->vx += (  &e->sparks[i] )->vx,	( &q[k] )->vy += (  &e->sparks[i] )->vy,	( &q[k] )->vz += (  &e->sparks[i] )->vz ;
            }
            otz = func_80087AB0(&q[0], &q[1], &q[2], &q[3], (long *)&g->x0, (long *)&g->x1,
                              (long *)&g->x2, (long *)&g->x3, (long *)&p, (long *)&flag);
            if (otz >= 0 && flag >= 0) {
                func_8005B260((u32 *)g, ot, otz & 0xFFFF, 1);
            }
            if (e->mode == 0) {
                e->sizes[i].size += 2;
                e->sizes[i].grow += 0x80;
            }
            if ((s16)e->sizes[i].size > 0x20) {
                e->sizes[i].size = 0x20;
            }
            if ((s16)e->sizes[i].grow > 0x600) {
                e->sizes[i].grow = 0x600;
            }
            if (e->spark_count < 32 || e->mode == 1) {
                if (e->spark_colors[i].r >= 0x10) {
                    e->spark_colors[i].r = e->spark_colors[i].r - 0xF;
                } else {
                    e->spark_colors[i].r = 0;
                }
                if (e->spark_colors[i].g >= 0x10) {
                    e->spark_colors[i].g = e->spark_colors[i].g - 0xF;
                } else {
                    e->spark_colors[i].g = 0;
                }
                if (e->spark_colors[i].b >= 0x10) {
                    e->spark_colors[i].b = e->spark_colors[i].b - 0xF;
                } else {
                    e->spark_colors[i].b = 0;
                }
            } else {
                if (e->spark_colors[i].r >= 7) {
                    e->spark_colors[i].r = e->spark_colors[i].r - 4;
                } else {
                    e->spark_colors[i].r = 0;
                }
                if (e->spark_colors[i].g >= 7) {
                    e->spark_colors[i].g = e->spark_colors[i].g - 4;
                } else {
                    e->spark_colors[i].g = 0;
                }
                if (e->spark_colors[i].b >= 7) {
                    e->spark_colors[i].b = e->spark_colors[i].b - 4;
                } else {
                    e->spark_colors[i].b = 0;
                }
            }
            if (e->spark_colors[i].r == 0 && e->spark_colors[i].g == 0 &&
                e->spark_colors[i].b == 0 && e->mode == 0) {
                ( &e->sparks[i] )->vx =   ((func_8008E590() - func_8008E590()) % 4096 * ( 320 ) / 4096)  , ( &e->sparks[i] )->vy =   0 , ( &e->sparks[i] )->vz =   ((func_8008E590() - func_8008E590()) % 4096 * ( 320 ) / 4096)   ;
                e->spark_colors[i].r = 0xC0;
                e->spark_colors[i].g = 0xC0;
                e->spark_colors[i].b = 0xFF;
                e->sizes[i].size = 8;
                e->sizes[i].grow = 0x100;
            }
        }
    }

    ( f )->u0 = (  0x40 ),      ( f )->v0 = (  0x40 ),	( f )->u1 = (  0x40 )+(  0x3F ), ( f )->v1 = (  0x40 ),	( f )->u2 = (  0x40 ),      ( f )->v2 = (  0x40 )+(  0x3F ),	( f )->u3 = (  0x40 )+(  0x3F ), ( f )->v3 = (  0x40 )+(  0x3F ) ;
    for (i = 0; i < e->flash_count; i++) {
        if (e->flash_colors[i].r != 0 || e->flash_colors[i].g != 0 ||
            e->flash_colors[i].b != 0) {
            ( f )->r0 =   e->flash_colors[i].r ,( f )->g0 =   e->flash_colors[i].g ,( f )->b0 =   e->flash_colors[i].b  ;
            sign = 1;
            for (j = 0; j < 4; j++) {
                sign = sign * -1;
                ( &q[0] )->vx =   -sign * 0x50 , ( &q[0] )->vy =   j - 2 >= 0 ? -0x50 : 0x50 , ( &q[0] )->vz =   0  ;
                ( &q[1] )->vx =   0 , ( &q[1] )->vy =   j - 2 >= 0 ? -0x50 : 0x50 , ( &q[1] )->vz =   0  ;
                ( &q[2] )->vx =   -sign * 0x50 , ( &q[2] )->vy =   0 , ( &q[2] )->vz =   0  ;
                ( &q[3] )->vx =   0 , ( &q[3] )->vy =   0 , ( &q[3] )->vz =   0  ;
                for (k = 0; k < 4; k++) {
                    ( &q[k] )->vx += (  &e->flashes[i] )->vx,	( &q[k] )->vy += (  &e->flashes[i] )->vy,	( &q[k] )->vz += (  &e->flashes[i] )->vz ;
                }
                otz = func_80087AB0(&q[0], &q[1], &q[2], &q[3], (long *)&f->x0, (long *)&f->x1,
                                  (long *)&f->x2, (long *)&f->x3, (long *)&p, (long *)&flag);
                if (otz >= 0 && flag >= 0) {
                    func_8005B260((u32 *)f, ot, otz & 0xFFFF, 1);
                }
            }
            if (e->flash_colors[i].r >= 0x20) {
                e->flash_colors[i].r = e->flash_colors[i].r - 0x1F;
            } else {
                e->flash_colors[i].r = 0;
            }
            if (e->flash_colors[i].g >= 0x20) {
                e->flash_colors[i].g = e->flash_colors[i].g - 0x1F;
            } else {
                e->flash_colors[i].g = 0;
            }
            if (e->flash_colors[i].b >= 0x20) {
                e->flash_colors[i].b = e->flash_colors[i].b - 0x1F;
            } else {
                e->flash_colors[i].b = 0;
            }
            if (e->flash_colors[i].r == 0 && e->flash_colors[i].g == 0 &&
                e->flash_colors[i].b == 0) {
                ( &e->flashes[i] )->vx =   ((func_8008E590() - func_8008E590()) % 4096 * ( 320 ) / 4096)  , ( &e->flashes[i] )->vy =   (-(func_8008E590() % 4096 * ( 128 )) / 4096)  , ( &e->flashes[i] )->vz =   ((func_8008E590() - func_8008E590()) % 4096 * ( 320 ) / 4096)   ;
                e->flash_colors[i].r = 0x40;
                e->flash_colors[i].g = 0x40;
                e->flash_colors[i].b = 0x55;
            }
        }
    }

    if (e->mode == 0 && !(e->frame & 1)) {
        func_80048658(2, 0xFF, 0);
        e->spark_count++;
        if (e->spark_count > 32) {
            e->spark_count = 32;
        }
        if (!(e->frame & 1)) {
            e->flash_count++;
            if (e->flash_count > 32) {
                e->flash_count = 32;
            }
        }
    }
    func_80059590(slot, 5, e->fade, e->fade, e->fade);
    if (e->fade >= 4) {
        e->fade = e->fade - 2;
    } else {
        e->fade = 0;
    }
    if (e->spark_count == 32 && e->flash_count == e->spark_count && e->fade == 0) {
        e->dust_r = 0xC0;
        e->dust_g = 0xC0;
        e->dust_b = 0xFF;
        e->flash_colors[0].r = 0;
        e->flash_colors[0].g = 0;
        e->flash_colors[0].b = 0;
        e->flash_count = 0;
        e->mode = 1;
        func_80059590(slot, 5, 0, 0, 0);
    }
    if ((*(u16 *)((u8 *)( e ) + (  0x80E )))  != 0 || e->dust_b != 0) {
        if (e->mode == 1) {
            ( f )->r0 =   e->dust_r ,( f )->g0 =   e->dust_g ,( f )->b0 =   e->dust_b  ;
            for (i = 0; i < 64; i++) {
                ( f )->u0 = (  (e->dust_frame[i] % 2) << 5 ),      ( f )->v0 = (  (e->dust_frame[i] / 2 << 5) + 0x40 ),	( f )->u1 = (  (e->dust_frame[i] % 2) << 5 )+(  0x1F ), ( f )->v1 = (  (e->dust_frame[i] / 2 << 5) + 0x40 ),	( f )->u2 = (  (e->dust_frame[i] % 2) << 5 ),      ( f )->v2 = (  (e->dust_frame[i] / 2 << 5) + 0x40 )+( 
                        0x1F ),	( f )->u3 = (  (e->dust_frame[i] % 2) << 5 )+(  0x1F ), ( f )->v3 = (  (e->dust_frame[i] / 2 << 5) + 0x40 )+(                          0x1F ) ;
                ( &q[0] )->vx =   -0x10 , ( &q[0] )->vy =   -0x10 , ( &q[0] )->vz =   0  ;
                ( &q[1] )->vx =   0x10 , ( &q[1] )->vy =   -0x10 , ( &q[1] )->vz =   0  ;
                ( &q[2] )->vx =   -0x10 , ( &q[2] )->vy =   0x10 , ( &q[2] )->vz =   0  ;
                ( &q[3] )->vx =   0x10 , ( &q[3] )->vy =   0x10 , ( &q[3] )->vz =   0  ;
                for (j = 0; j < 4; j++) {
                    ( &q[j] )->vx += (  &e->dust[i] )->vx,	( &q[j] )->vy += (  &e->dust[i] )->vy,	( &q[j] )->vz += (  &e->dust[i] )->vz ;
                }
                otz = func_80087AB0(&q[0], &q[1], &q[2], &q[3], (long *)&f->x0, (long *)&f->x1,
                                  (long *)&f->x2, (long *)&f->x3, (long *)&p, (long *)&flag);
                if (otz >= 0 && flag >= 0) {
                    func_8005B260((u32 *)f, ot, otz & 0xFFFF, 1);
                }
                ( &e->dust[i] )->vx += (  &e->dust_speed[i] )->vx,	( &e->dust[i] )->vy += (  &e->dust_speed[i] )->vy,	( &e->dust[i] )->vz += (  &e->dust_speed[i] )->vz ;
                e->dust_frame[i] = (e->dust_frame[i] + 1) % 4;
            }
            if (e->dust_r >= 0xA) {
                e->dust_r = e->dust_r - 8;
            } else {
                e->dust_r = 0;
            }
            if (e->dust_g >= 0xA) {
                e->dust_g = e->dust_g - 8;
            } else {
                e->dust_g = 0;
            }
            if (e->dust_b >= 0xA) {
                e->dust_b = e->dust_b - 8;
            } else {
                e->dust_b = 0;
            }
        }
    }
    e->frame++;
    func_80087274();
    if ((*(u16 *)((u8 *)( e ) + (  0x78E )))  == 0 && e->flash_colors[0].b == 0 && (*(u16 *)((u8 *)( e ) + (  0x80E )))  == 0 &&
        e->dust_b == 0) {
        return 2;
    }
    return 0;
}
