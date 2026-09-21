/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/display_object_helpers.c (DisplayObject_SubmitPacket), profile gcc_2_8_1_g8_split.
 * The declarations above the function are the subset of that tree's headers
 * this unit needs, preprocessed and with symbols renamed to this tree's
 * spelling (func_ADDR, D_ADDR); their types are that tree's. Byte-identical
 * under the flag row in tools_src/build.py. */
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
typedef struct {		 
	short	vx, vy;
	short	vz, pad;
} SVECTOR;
typedef struct {		 
	u8	r, g, b, cd;
} CVECTOR;
typedef struct {		 
	short vx, vy;
} DVECTOR;
typedef struct {
	SVECTOR v;
	u8 uv[2]; u16 pad;	 
	CVECTOR c;
	DVECTOR sxy;
	u32  sz;		 
} RVECTOR;
typedef struct {
	RVECTOR r01,r02,r31,r32,rc;
	RVECTOR	*r0,*r1,*r2,*r3;
	u32 *rtn;
} CRVECTOR4;
typedef struct {
	u32 	ndiv;		 
	u32 	pih,piv;	 
	u16 clut,tpage;
	CVECTOR	rgbc;
	u32	*ot;
	RVECTOR r0,r1,r2,r3;
	CRVECTOR4 cr[5];
} DIVPOLYGON4;
extern long func_80087BC0(SVECTOR *v0,SVECTOR *v1,SVECTOR *v2,SVECTOR *v3,
			long *sxy0,long *sxy1,long *sxy2,long *sxy3,
			long *p,long *otz,long *flag);
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
	u32	tag;
	u8	r0, g0, b0, code;
	short	x0, 	y0;
	u8	u0, v0;	u16	clut;
	u8	r1, g1, b1, p1;
	short	x1,	y1;
	u8	u1, v1;	u16	tpage;
	u8	r2, g2, b2, p2;
	short	x2,	y2;
	u8	u2, v2;	u16	pad2;
	u8	r3, g3, b3, p3;
	short	x3,	y3;
	u8	u3, v3;	u16	pad3;
} POLY_GT4;
extern void func_80082840(void *p, int abe) ;
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
void    func_800844F0(GsSPRITE * sp, GsOT * ot, unsigned short pri);
void    func_800849F0(GsSPRITE * sp, GsOT * ot, unsigned short pri);
void    func_80084B70(GsSPRITE * sp, GsOT * ot, unsigned short pri);
void    func_80084320(void *pp, GsOT * ot, unsigned short pri);
POLY_FT4 *func_80089260(SVECTOR *v0, SVECTOR *v1, SVECTOR *v2, SVECTOR *v3,
			u32 *uv0, u32 *uv1, u32 *uv2, u32 *uv3,
			CVECTOR *rgbc, POLY_FT4 *s, u32 *ot, DIVPOLYGON4 *divp);
extern u32 *D_800FE240 __attribute__((section(".data")));
void func_8005B260(u32 *src, GsOT *ot, s32 idx, s32 flags);
typedef union {
    s32 word;
    struct {
        u16 x;
        u16 y;
    } h;
} SpritePos;
typedef union {
    u16 word;
    struct {
        u8 lo;
        u8 hi;
    } b;
} SpriteHalf;
typedef struct {
    u32 attribute;
    SpritePos xy;
    union {
        u32 word;
        struct {
            SpriteHalf w;
            u16 h;
        } wh;
    } extent;
    u16 tpage;
    SpriteHalf uv;
    union {
        u32 word;
        struct {
            u16 cx;
            u16 cy;
        } h;
    } cxcy;
    u32 rgb;
    SpritePos mxmy;
    u32 scale;
    s32 rotate;
} SpritePrim;
typedef struct {
    s16 x;
    s16 y;
    s32 divisions;
} DisplayObjectPacketOrigin;
void func_80042188(SpritePrim *sprite, u8 *packet, s32 ot, s32 mode, u8 *extra);
void func_80042188(SpritePrim *sprite, u8 *packet, s32 ot, s32 mode, u8 *extra)
{
    SVECTOR *v;
    long *otz;
    DisplayObjectPacketOrigin *origin = (DisplayObjectPacketOrigin *)extra;
    s32 pri = (s16)mode;

    switch ((u32)mode >> 16) {
    case 1:
        func_800849F0(((GsSPRITE *)( sprite )) , ((GsOT *)( ot )) , pri);
        return;
    case 2:
        func_80084B70(((GsSPRITE *)( sprite )) , ((GsOT *)( ot )) , pri);
        return;
    case 3:
        func_800844F0(((GsSPRITE *)( sprite )) , ((GsOT *)( ot )) , pri);
        return;
    case 4: {
        if ((u32)sprite & 0x04000000) {
            otz = (long *)0x1F8002E0;
            v = ((SVECTOR *)0x1F800300 + ( 0 )) ;
            v[0].vx = ((POLY_G4 *)( packet )) ->x0 - origin->x;
            v[0].vy = ((POLY_G4 *)( packet )) ->y0 - origin->y;
            v[1].vx = ((POLY_G4 *)( packet )) ->x1 - origin->x;
            v[1].vy = ((POLY_G4 *)( packet )) ->y1 - origin->y;
            v[2].vx = ((POLY_G4 *)( packet )) ->x2 - origin->x;
            v[2].vy = ((POLY_G4 *)( packet )) ->y2 - origin->y;
            v[3].vx = ((POLY_G4 *)( packet )) ->x3 - origin->x;
            v[3].vy = ((POLY_G4 *)( packet )) ->y3 - origin->y;
            ((SVECTOR *)0x1F800300 + ( 3 )) ->vz = 0;
            ((SVECTOR *)0x1F800300 + ( 2 )) ->vz = 0;
            ((SVECTOR *)0x1F800300 + ( 1 )) ->vz = 0;
            v[0].vz = 0;
            if (func_80087BC0(((SVECTOR *)0x1F800300 + ( 0 )) , ((SVECTOR *)0x1F800300 + ( 1 )) , ((SVECTOR *)0x1F800300 + ( 2 )) , ((SVECTOR *)0x1F800300 + ( 3 )) ,
                                 (long *)& ((POLY_G4 *)( packet )) ->x0, (long *)& ((POLY_G4 *)( packet )) ->x1,
                                 (long *)& ((POLY_G4 *)( packet )) ->x2, (long *)& ((POLY_G4 *)( packet )) ->x3,
                                 otz, otz + 1, otz + 2) <= 0) {
                return;
            }
        }
        if ((u32)sprite & 0x40000000) {
            func_8005B260((u32 *)packet, ((GsOT *)( ot )) , (u16)pri, ((u32)sprite >> 28) & 3);
        } else {
            func_80084320(packet, ((GsOT *)( ot )) , pri);
        }
        return;
    }
    case 5: {
        if ((u32)sprite & 0x04000000) {
            otz = (long *)0x1F8002E0;
            v = ((SVECTOR *)0x1F800300 + ( 0 )) ;
            v[0].vx = ((POLY_GT4 *)( packet )) ->x0 - origin->x;
            v[0].vy = ((POLY_GT4 *)( packet )) ->y0 - origin->y;
            v[1].vx = ((POLY_GT4 *)( packet )) ->x1 - origin->x;
            v[1].vy = ((POLY_GT4 *)( packet )) ->y1 - origin->y;
            v[2].vx = ((POLY_GT4 *)( packet )) ->x2 - origin->x;
            v[2].vy = ((POLY_GT4 *)( packet )) ->y2 - origin->y;
            v[3].vx = ((POLY_GT4 *)( packet )) ->x3 - origin->x;
            v[3].vy = ((POLY_GT4 *)( packet )) ->y3 - origin->y;
            ((SVECTOR *)0x1F800300 + ( 3 )) ->vz = 0;
            ((SVECTOR *)0x1F800300 + ( 2 )) ->vz = 0;
            ((SVECTOR *)0x1F800300 + ( 1 )) ->vz = 0;
            v[0].vz = 0;
            if (func_80087BC0(((SVECTOR *)0x1F800300 + ( 0 )) , ((SVECTOR *)0x1F800300 + ( 1 )) , ((SVECTOR *)0x1F800300 + ( 2 )) , ((SVECTOR *)0x1F800300 + ( 3 )) ,
                                 (long *)& ((POLY_GT4 *)( packet )) ->x0, (long *)& ((POLY_GT4 *)( packet )) ->x1,
                                 (long *)& ((POLY_GT4 *)( packet )) ->x2, (long *)& ((POLY_GT4 *)( packet )) ->x3,
                                 otz, otz + 1, otz + 2) <= 0) {
                return;
            }
        }
        if ((u32)sprite & 0x40000000) {
            func_8005B260((u32 *)packet, ((GsOT *)( ot )) , (u16)pri, ((u32)sprite >> 28) & 3);
        } else {
            func_80084320(packet, ((GsOT *)( ot )) , pri);
        }
        return;
    }
    case 0:
        return;
    default: {
        SVECTOR *v2;
        SVECTOR *v3;
        SVECTOR *v1;
        u32 attribute;

        otz = (long *)0x1F8002E0;
        v = ((SVECTOR *)0x1F800300 + ( 0 )) ;
        attribute = sprite->attribute;

         

        ((POLY_FT4 *)( packet )) ->tpage =
            sprite->tpage | (((attribute >> 17) & 0x180) | ((attribute >> 23) & 0x60));
        if (sprite->attribute & 0x40000000) {
            func_80082840(packet, 1);
        }
        ((POLY_FT4 *)( packet )) ->clut = (sprite->cxcy.h.cy << 6) | ((sprite->cxcy.h.cx >> 4) & 0x3F);
        if (sprite->attribute & 0x800000) {
             
            ((POLY_FT4 *)( packet )) ->u1 = ((POLY_FT4 *)( packet )) ->u3 = sprite->uv.b.lo;
            ((POLY_FT4 *)( packet )) ->u0 = ((POLY_FT4 *)( packet )) ->u2 =
                sprite->uv.b.lo + sprite->extent.wh.w.word - 1;
            ((POLY_FT4 *)( packet )) ->v0 = ((POLY_FT4 *)( packet )) ->v1 = sprite->uv.b.hi;
            ((POLY_FT4 *)( packet )) ->v2 = ((POLY_FT4 *)( packet )) ->v3 =
                sprite->uv.b.hi + sprite->extent.wh.h - 1;
        } else {
            ((POLY_FT4 *)( packet )) ->u0 = ((POLY_FT4 *)( packet )) ->u2 = sprite->uv.b.lo;
            ((POLY_FT4 *)( packet )) ->v0 = ((POLY_FT4 *)( packet )) ->v1 = sprite->uv.b.hi;
            if (sprite->attribute & 0x80) {
                ((POLY_FT4 *)( packet )) ->u1 = ((POLY_FT4 *)( packet )) ->u3 =
                    sprite->uv.b.lo + sprite->extent.wh.w.word;
                ((POLY_FT4 *)( packet )) ->v2 = ((POLY_FT4 *)( packet )) ->v3 =
                    sprite->uv.b.hi + sprite->extent.wh.h;
            } else {
                ((POLY_FT4 *)( packet )) ->u1 = ((POLY_FT4 *)( packet )) ->u3 =
                    sprite->uv.b.lo + sprite->extent.wh.w.word - 1;
                ((POLY_FT4 *)( packet )) ->v2 = ((POLY_FT4 *)( packet )) ->v3 =
                    sprite->uv.b.hi + sprite->extent.wh.h - 1;
            }
        }
        v1 = v + 1;
        v2 = v + 2;
        v3 = v + 3;
        v->vx = v[2].vx = sprite->xy.h.x - origin->x;
        v[1].vx = v[3].vx = v->vx + sprite->extent.wh.w.word;
        v->vy = v1->vy = sprite->xy.h.y - origin->y;
        v[2].vy = v3->vy = v->vy + sprite->extent.wh.h;
        v3->vz = 0;
        v2->vz = 0;
        v1->vz = 0;
        v->vz = 0;
        if (func_80087BC0(v, v1, v2, v3,
                             (long *)& ((POLY_FT4 *)( packet )) ->x0, (long *)& ((POLY_FT4 *)( packet )) ->x1,
                             (long *)& ((POLY_FT4 *)( packet )) ->x2, (long *)& ((POLY_FT4 *)( packet )) ->x3,
                             otz, otz + 1, otz + 2) > 0) {
            if (origin->divisions == 0) {
                func_80084320(packet, ((GsOT *)( ot )) , pri);
                return;
            }
            {
                u32 *rgbc = (u32 *)0x1F800280;
                u32 *uv = (u32 *)0x1F800290;
                DIVPOLYGON4 *divp = (DIVPOLYGON4 *)0x1F800000;

                divp->ndiv = origin->divisions;
                divp->pih = 320;
                divp->piv = 272;
                *rgbc = *(u32 *)& ((POLY_FT4 *)( packet )) ->r0;
                uv[0] = *(u32 *)& ((POLY_FT4 *)( packet )) ->u0;
                uv[1] = *(u32 *)& ((POLY_FT4 *)( packet )) ->u1;
                uv[2] = *(u32 *)& ((POLY_FT4 *)( packet )) ->u2;
                uv[3] = *(u32 *)& ((POLY_FT4 *)( packet )) ->u3;
                D_800FE240 = (u32 *)func_80089260(v, v1, v2, v3,
                                             uv, (u32 *)0x1F800294, (u32 *)0x1F800298, (u32 *)0x1F80029C,
                                             (CVECTOR *)rgbc, (POLY_FT4 *)D_800FE240,
                                             (u32 *)((GsOT *)( ot )) ->org + pri, divp);
            }
        }
        return;
    }
    }
}
