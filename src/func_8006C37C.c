/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/model_disc_effect.c (Model_UpdateDiscEffect), profile gcc_2_8_1_g8_split.
 * The declarations above the function are the subset of that tree's headers
 * this unit needs, preprocessed and with symbols renamed to this tree's
 * spelling (func_ADDR, D_ADDR); their types are that tree's. Byte-identical
 * under the flag row in tools_src/build.py. */
#include "kg_types.h"
extern MATRIX *func_80087D30(SVECTOR *r,MATRIX *m);
extern MATRIX *func_80087670(MATRIX *m,VECTOR *v);
extern void func_800871D0();
extern void func_80087274();
extern void func_80087970(SVECTOR *v0,VECTOR *v1,long *flag);
extern long func_80089C70(long sz0,long sz1,long sz2);
extern void func_80087CC0(SVECTOR *v0,DVECTOR *v1,u16 *sz,u16 *p,
			u16 *flag,long n);
extern int func_80086920(int a);
extern int func_80086BB0(int a);
extern void func_800828E0(POLY_G3 *p) ;
extern void func_80082960(POLY_G4 *p) ;
void    func_800855D0(MATRIX * mp);
extern void *func_8008E3D0 ( );
extern ModelDiscEffectConfig D_80091604;
extern VECTOR D_8001187C;
s32 func_8006C37C(ModelDiscEffectState *arg0, s32 arg1);
void func_80057E20(s32 index, ModelEffectAdjustment *out);
s32 func_80058E1C(void);
s32 func_80058DCC(void);
void *func_80059220(void);
void func_80058FB0(s32 idx, u16 *out);
GsOT *func_80058F10(void);
void func_8005B260(u32 *src, GsOT *ot, s32 idx, s32 flags);
s32 func_8006C37C(ModelDiscEffectState *arg0, s32 arg1)
{
    ModelDiscEffectState *e;
    MATRIX ls;
    MATRIX m;
    POLY_G3 g3;
    POLY_G4 g4;
    SVECTOR rot;
    SVECTOR pos;
    VECTOR scale;
    ModelEffectAdjustment adj;
     
    u8 unused_c8[0x18];
    DVECTOR sxy[68];
    u16 sz[68];
    u16 p[68];
    u16 flags[68];
    s32 flag;
    GsOT *ot;
    u8 step;
    ModelDiscEffectConfig *t;
    s32 i;
    s32 r;
    s32 v;
    s32 s;
    s32 otz;
    SVECTOR *pt;
    s32 c0;
    s32 c1;
    s32 c2;
    u16 u;
    s32 w;
    s32 k3;

    func_8008E3D0(&rot, 0, 8);
    func_8008E3D0(&pos, 0, 8);
    scale = D_8001187C;
    e = arg0;
    func_80058DCC();
    step = func_80058E1C();

    if (arg1 >= 0) {
        e->table = &D_80091604;
        t = e->table;
        func_80057E20(func_80058DCC(), &adj);
        if (adj.y < adj.z) {
            v = adj.z;
        } else {
            v = adj.y;
        }
        if (v == adj.z) {
            u = adj.z;
            if (v < adj.x) {
                u = adj.x;
            }
        } else {
            u = adj.y;
            if (adj.y < adj.x) {
                u = adj.x;
            }
        }
        w = u << 16;
        v = w >> 16;
        v = v * 5 / 4;
        r = t->min_radius;
        if (v >= r) {
            r = 0x2BC;
            if (v < 0x2BD) {
                r = v;
            }
        }
        v = r;
        pt = e->points;
        k3 = v / 3;
        pt->vx = k3;
        pt->vy = k3;
        pt->vz = 0;
        pt++;
        for (i = 0; i < 33; i++) {
            pt->vx = v * func_80086920(i << 7) / 4096;
            pt->vy = v * func_80086BB0(i << 7) / 4096;
            pt->vz = v * func_80086BB0(i << 7) / 32768;
            pt++;
        }
        v = v * 4 / 5;
        for (i = 0; i < 33; i++) {
            pt->vx = v * func_80086920(i << 7) / 4096;
            pt->vy = v * func_80086BB0(i << 7) / 4096;
            pt->vz = v * func_80086BB0(i << 7) / 32768;
            pt++;
        }
        e->b = (arg1 % 10 + 6) * 0x11;
        e->r = ((arg1 - arg1 % 100) / 100 + 6) * 0x11;
        e->g = ((arg1 % 100 - arg1 % 10) / 10 + 6) * 0x11;
        e->level = t->full_level;
        e->scale = 0;
        e->frame = 0;
        return 0;
    }

    t = e->table;
    ot = func_80058F10();
    func_800828E0(&g3);
    func_80082960(&g4);
    func_800871D0();
    ls = *(MATRIX *)func_80059220();
    func_800855D0(&ls);
    rot.vx = 0;
    rot.vy = 0;
    rot.vz = 0;
    v = (e->scale << 12) / t->full_scale + func_80086BB0((e->frame & 3) << 10) / 16;
    scale.vx = v;
    scale.vy = v;
    scale.vz = v;
    func_80058FB0(func_80058DCC(), (u16 *)&pos);
    func_800855D0(&ls);
    func_80087970(&pos, (VECTOR *)m.t, (long *)&flag);
    func_80087D30(&rot, &m);
    func_80087670(&m, &scale);
    func_800855D0(&m);
    c0 = e->r * e->level / t->full_level * e->scale / t->full_scale;
    c1 = e->g * e->level / t->full_level * e->scale / t->full_scale;
    c2 = e->b * e->level / t->full_level * e->scale / t->full_scale;
    g3.r0 = c0;
    g3.g0 = c1;
    g3.b0 = c2;
    c0 = t->r * e->level / t->full_level * e->scale / t->full_scale;
    c1 = t->g * e->level / t->full_level * e->scale / t->full_scale;
    c2 = t->b * e->level / t->full_level * e->scale / t->full_scale;
    g3.r1 = c0;
    g3.r2 = c0;
    g3.g1 = c1;
    g3.g2 = c1;
    g3.b1 = c2;
    g3.b2 = c2;
    func_80087CC0(e->points, sxy, sz, p, flags, 0x43);
    for (i = 0; i < 32; i++) {
        g3.x0 = sxy[0].vx;
        g3.y0 = sxy[0].vy;
        g3.x1 = sxy[i + 1].vx;
        g3.y1 = sxy[i + 1].vy;
        g3.x2 = sxy[i + 2].vx;
        g3.y2 = sxy[i + 2].vy;
        otz = func_80089C70(sz[0], sz[i + 1], sz[i + 2]) / 2;
        flag = (flags[0] | flags[1] | flags[2]) & 0x20;
        if (otz >= 0 && flag == 0) {
            func_8005B260((u32 *)&g3, ot, otz & 0xFFFF, 1);
        }
    }
    func_80087274();
    e->frame++;
    if (arg1 == -2) {
        e->level -= step;
    } else {
        s = e->scale + step;
        e->scale = s;
        s = s < 0 ? 0 : (s > t->full_scale ? t->full_scale : s);
        e->scale = s;
    }
    return (e->level < 1) * 2;
}
