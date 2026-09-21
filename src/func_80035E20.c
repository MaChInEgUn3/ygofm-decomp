/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/func_80035E20.c, profile gcc_2_8_1_g8_split_no_strength_reduce.
 * The declarations above the function are the subset of that tree's headers
 * this unit needs, preprocessed and with symbols renamed to this tree's
 * spelling (func_ADDR, D_ADDR); their types are that tree's. Byte-identical
 * under the flag row in tools_src/build.py. */
#include "kg_types.h"
#include "kg_variables.h"
#include "kg_functions.h"
extern void func_800878B0(long ofx,long ofy);
extern long func_80087BC0(SVECTOR *v0,SVECTOR *v1,SVECTOR *v2,SVECTOR *v3,
			long *sxy0,long *sxy1,long *sxy2,long *sxy3,
			long *p,long *otz,long *flag);
extern void func_80082980(POLY_GT4 *p) ;
void    func_800849F0(GsSPRITE * sp, GsOT * ot, unsigned short pri);
extern DuelEffectChannel D_800EB0F8[4 ];
extern s16 D_8009B146 __attribute__((section(".data")));
extern s16 D_8009B148 __attribute__((section(".data")));
void func_80035E20(DisplayObject *obj, GsOT *ot);
void func_80035E20(DisplayObject *obj, GsOT *ot)
{
    s32 x;
    s32 y;
    MATRIX *mat;
    s32 pri;
    u16 *code;
    POLY_FT4 *ft4;
    SVECTOR *vec;
    long *res;
    GsSPRITE *sprites[3];
    GsSPRITE *spr;
    POLY_GT4 *gt4;
    u8 *p;
    s32 nudge;
    s32 t;
    s32 i;
    s32 w;
    s32 su;
    s32 cyv;
    s32 c;
    u8 f;
    u32 b;
    s32 v78;
    s32 tt;
    s32 hw;

    func_800878D0(0x12C);
    x = (s16)obj->field_30.h.field_30;
    y = (s16)obj->field_30.h.field_32;
    pri = (s16)obj->field_14;
    if (!(obj->flags & 8)) {
        x = x - D_8009B146;
        y = y - D_8009B148;
    }
    ft4 = (POLY_FT4 *)0x1F800038;
    vec = (SVECTOR *)0x1F800060;
    mat = (MATRIX *)0x1F800078;
    res = (long *)0x1F8000A0;
    gt4 = (POLY_GT4 *)0x1F800000;
    sprites[0] = (GsSPRITE *)0x1F8000C0;
    sprites[1] = (GsSPRITE *)0x1F800100;
    sprites[2] = (GsSPRITE *)0x1F800140;
    func_80082980((POLY_GT4 *)0x1F800000);
    func_80082840((void *)0x1F800000, 1);
    *(u32 *)&ft4->r0 = 0x808080;
    (((P_TAG *)( ft4 ))->len  = (u8)(  9 )) ;
    (((P_TAG *)( ft4 ))->code = (u8)(  0x2C )) ;
    ft4->clut = (obj->field_40.h.field_42 << 6) |
                (((u16)obj->field_40.h.field_40 >> 4) & 0x3F);
    t = (obj->attribute >> 0x17) & 0x60;
    w = obj->attribute & 0x01000000;
    do {
        b = obj->field_66;
    } while (0);
    if (w) {
        b |= 0x80;
    }
    ft4->tpage = t | b;
    sprites[0]->attribute = sprites[1]->attribute = sprites[2]->attribute =
        obj->attribute | 0x08000000;
    (*(u32 *)&( sprites[0] )->r)  = obj->field_0C;
    (*(u32 *)&( sprites[1] )->r)  = obj->field_0C;
    (*(u32 *)&( sprites[2] )->r)  = obj->field_0C;
    *(u32 *)&sprites[0]->w = 0x100010;
    *(u32 *)&sprites[1]->w = 0x100010;
    *(u32 *)&sprites[2]->w = 0x80008;
    do {
        *(u32 *)&sprites[0]->cx = obj->field_40.word;
    } while (0);
    sprites[0]->tpage = obj->field_66;
    sprites[1]->tpage = sprites[2]->tpage = 0xB;
    code = (u16 *)D_800EB0F8[obj->field_67].entry_head_24;
    v78 = 0x78;
    p = (u8 *)code + 0x16;

    while (1) {
    loop:
        f = p[-5];
        c = *code;
        nudge = 0;
        if (!(f & 0x80)) {
            return;
        }
        if (f & 0x60) {
            if (f & 0x20) {
                sprites[1]->tpage = 0xB;
                res[0] = p[-6];
                spr = sprites[1];
                if (res[0] >= 0x22) {
                    tt = (u8)res[0];
                    spr->v = 0x80;
                    spr->cx = 0x200;
                    spr->cy = 0xFC;
                    tt *= 0x10;
                    tt -= 0x210;
                    spr->u = tt;
                    if ((tt & 0xFF) == 0x50) {
                        spr->cx = 0x210;
                    }
                } else {
                    spr->u = (((u8)res[0] & 7) * 0x10) - 0x80;
                    spr->v = ((u8)res[0] & 0x38) * 2;
                    if (res[0] >= 0x19) {
                        res[0] = 0x18;
                    }
                    su = (((u16)res[0] & 0xF) * 0x10) + 0x200;
                    tt = ((u8)res[0] >> 4) + 0xF9;
                    spr->cx = su;
                    spr->cy = tt;
                    spr->attribute = obj->attribute | 0x08000000;
                    spr->w = 0x10;
                    spr->h = 0x10;
                    if ((u8)p[1] >= 0x14 && (u8)p[-6] < 0x18) {
                        sprites[1]->tpage = 0x1E;
                        switch (p[1]) {
                        case 0x14:
                            cyv = 0xF2;
                            spr->u = 0;
                            break;
                        case 0x15:
                            spr->u = 0x40;
                            cyv = 0xF3;
                            break;
                        case 0x16:
                            spr->u = 0x60;
                            cyv = 0xF4;
                            break;
                        case 0x17:
                            spr->u = 0x20;
                            cyv = 0xF1;
                            break;
                        default:
                            cyv = 0xF1;
                            spr->u = 0;
                            break;
                        }
                        spr->cy = cyv;
                        spr->v = 0x60;
                        spr->w = 0x20;
                        spr->h = 0x10;
                        spr->cx = 0x100;
                        spr->attribute |= 0x01000000;
                    }
                }
            } else {
                spr = sprites[2];
                spr->cx = (p[0] * 0x10) + 0x290;
                spr->cy = 0xFA;
                spr->u = ((p[-6] & 0xF) * 8) - 0x80;
                spr->v = (u32)(p[-6] & 0xF0) >> 1;
            }
            spr->x = *(u16 *)(p - 0xA) + x;
            spr->y = *(u16 *)(p - 8) + y;
        } else {
            spr = sprites[0];
            switch (c) {
            case 0x8171:
            case 0x8173:
                c = 0x8183;
                break;
            case 0x8172:
            case 0x8174:
                c = 0x8184;
                break;
            }
            if ((u32)(c - 0x824F) < 0x4C) {
                if ((u32)(c - 0x8259) < 7 || (u32)(c - 0x827A) < 7) {
                    if (p[2] == 1) {
                        spr->u = 0;
                        spr->v = v78;
                    } else {
                        spr->u = 0;
                        spr->v = 0x30;
                    }
                } else {
                if (p[2] == 1) {
                    spr->u = (c & 0xF) * 0x10;
                    spr->v = (((s32)(c - 0x8240) >> 4) * 0x10) + 0x48;
                } else {
                    spr->u = (c & 0xF) * 8;
                    spr->v = ((s32)(c - 0x8240) >> 4) * 0xC;
                }
                }
            } else {
                {
                s32 tbl[30] = {
                    0x8149, 0x8168, 0x8194, 0x8190, 0x8193, 0x8195, 0x8166, 0x8169,
                    0x816A, 0x8196, 0x817B, 0x8143, 0x817C, 0x8144, 0x815E, 0x8146,
                    0x8147, 0x8183, 0x8181, 0x8184, 0x8148, 0x8140, 0x83BF, 0x83C0,
                    0x81C1, 0x81A9, 0x81A8, 0x81BC, 0x81BD, -1,
                };

                for (i = 0;; i++) {
                    if (c == tbl[i]) {
                        if (p[2] == 1) {
                            if (i < 0xF) {
                                spr->u = i * 0x10;
                                spr->v = 0x48;
                            } else if (i < 0x16) {
                                su = (i * 0x10) - 0x160;
                                spr->u = su;
                                spr->v = 0x58;
                            } else {
                                switch (c) {
                                case 0x83BF:
                                    spr->u = 0xD0;
                                    spr->v = 0x98;
                                    break;
                                case 0x83C0:
                                    spr->u = 0xE0;
                                    spr->v = 0x98;
                                    break;
                                case 0x81C1:
                                    spr->u = 0xF0;
                                    spr->v = 0x98;
                                    break;
                                case 0x81A9:
                                    spr->u = 0xB0;
                                    spr->v = v78;
                                    break;
                                case 0x81A8:
                                    spr->u = 0xC0;
                                    spr->v = v78;
                                    break;
                                case 0x81BC:
                                    nudge = 2;
                                    spr->u = 0xE0;
                                    spr->v = v78;
                                    break;
                                case 0x81BD:
                                    nudge = -2;
                                    spr->u = 0xF0;
                                    spr->v = v78;
                                    break;
                                }
                            }
                        } else {
                            if (i < 0xF) {
                                spr->u = i * 8;
                                spr->v = 0;
                            } else if (i < 0x16) {
                                spr->u = (i * 8) - 0x30;
                                spr->v = 0xC;
                            } else {
                                switch (c) {
                                case 0x83BF:
                                    spr->u = 0x68;
                                    spr->v = 0x3C;
                                    break;
                                case 0x83C0:
                                    spr->u = 0x70;
                                    spr->v = 0x3C;
                                    break;
                                case 0x81C1:
                                    spr->u = v78;
                                    spr->v = 0x3C;
                                    break;
                                case 0x81BD:
                                case 0x81BC:
                                case 0x81A9:
                                case 0x81A8:
                                    spr->u = 0;
                                    spr->v = 0x30;
                                    break;
                                }
                            }
                        }
                        break;
                    }
                    if (tbl[i] < 0) {
                        if (p[2] == 1) {
                            spr->u = 0;
                            spr->v = v78;
                        } else {
                            spr->u = 0;
                            spr->v = 0x30;
                        }
                        break;
                    }
                }
                }
            }
            spr->cx = 0x280;
            spr->cy = p[0] + 0xE8;
            if (p[2] == 1) {
                hw = 0x10;
                spr->w = hw;
            } else {
                spr->w = 8;
                hw = 0xC;
            }
            spr->h = hw;
            if (p[2] == 1) {
                if (nudge != 0) {
                    spr->x = *(u16 *)(p - 0xA) + x + nudge;
                    spr->y = *(u16 *)(p - 8) + y;
                } else {
                    spr->x = *(u16 *)(p - 0xA) + x;
                    spr->y = *(u16 *)(p - 8) + y;
                }
            } else if (p[2] == 2) {
                spr->x = *(u16 *)(p - 0xA) + x;
                spr->y = *(u16 *)(p - 8) + y - 2;
            } else {
                spr->x = *(u16 *)(p - 0xA) + x;
                spr->y = *(u16 *)(p - 8) + y + 2;
            }
        }
        switch (p[-1]) {
        case 0:
            func_800849F0(spr, ot, pri);
            break;
        case 1:
            if ((p[-0xC] | (p[-0xE] | p[-0xD])) != 0) {
                func_800878B0((s16)spr->x + 8, (s16)spr->y + 8);
                ft4->u0 = ft4->u2 = spr->u;
                ft4->u1 = ft4->u3 = spr->u + 0xF;
                ft4->v0 = ft4->v1 = spr->v;
                tt = spr->v + 0xF;
                mat->t[0] = 0;
                mat->t[1] = 0;
                mat->t[2] = 0x12C;
                ft4->v2 = ft4->v3 = tt;
                vec->vx = p[-0xE] * 0x10;
                vec->vy = p[-0xD] * 0x10;
                vec->vz = p[-0xC] * 0x10;
                func_80088C50(vec, mat);
                func_800855D0(mat);
                vec[1].vx = -8;
                vec[1].vy = -8;
                vec[1].vz = 0;
                vec[2].vx = 8;
                vec[2].vy = -8;
                vec[2].vz = 0;
                vec[3].vx = -8;
                vec[3].vy = 8;
                vec[3].vz = 0;
                vec[4].vx = 8;
                vec[4].vy = 8;
                vec[4].vz = 0;
                if (func_80087BC0(&vec[1], &vec[2], &vec[3], &vec[4],
                                     (long *)&ft4->x0, (long *)&ft4->x1,
                                     (long *)&ft4->x2, (long *)&ft4->x3,
                                     &res[0], &res[1], &res[2]) > 0) {
                    func_80084320(ft4, ot, pri);
                }
            } else {
                func_800849F0(spr, ot, pri);
            }
            break;
        case 2:
            gt4->r0 = gt4->g0 = gt4->b0 = p[-0x12];
            gt4->r1 = gt4->g1 = gt4->b1 = p[-0x11];
            gt4->r2 = gt4->g2 = gt4->b2 = p[-0x10];
            gt4->r3 = gt4->g3 = gt4->b3 = p[-0xF];
            gt4->x0 = gt4->x2 = spr->x;
            if (p[2] == 1 || (p[-5] & 0x20)) {
                gt4->x1 = gt4->x3 = spr->x + (p[-2] + 0x10);
                gt4->y0 = spr->y + ((u8)p[-2] >> 2);
                gt4->y1 = spr->y;
                gt4->y2 = gt4->y3 = spr->y + 0x10;
                gt4->u0 = gt4->u2 = spr->u;
                su = spr->u + 0x10;
                gt4->u1 = gt4->u3 = su;
                if (!(su & 0xFF)) {
                    gt4->u3 = 0xFF;
                    gt4->u1 = 0xFF;
                }
                gt4->v0 = gt4->v1 = spr->v;
                su = spr->v + 0x10;
            } else {
                gt4->x1 = gt4->x3 = spr->x + (p[-2] + 8);
                gt4->y0 = spr->y + ((u8)p[-2] >> 2);
                gt4->y1 = spr->y;
                gt4->y2 = gt4->y3 = spr->y + 0xC;
                gt4->u0 = gt4->u2 = spr->u;
                su = spr->u + 8;
                gt4->u1 = gt4->u3 = su;
                if (!(su & 0xFF)) {
                    gt4->u3 = 0xFF;
                    gt4->u1 = 0xFF;
                }
                gt4->v0 = gt4->v1 = spr->v;
                su = spr->v + 0xC;
            }
            gt4->v2 = gt4->v3 = su;
            if (!(su & 0xFF)) {
                gt4->v3 = 0xFF;
                gt4->v2 = 0xFF;
            }
            gt4->tpage = spr->tpage | 0x20;
            if (p[-5] & 0x20) {
                gt4->clut = (spr->cy << 6) | (((u16)spr->cx >> 4) & 0x3F);
            } else {
                gt4->clut = ((p[0] + 0xE8) << 6) | 0x28;
            }
            func_80084320(gt4, ot, pri);
            gt4->tpage = spr->tpage | 0x40;
            gt4->clut = 0x3FE2;
            func_80084320(gt4, ot, pri);
            break;
        }
        p += 0x1C;
        code += 0xE;
    }
}
