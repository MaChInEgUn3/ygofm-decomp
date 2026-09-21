/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/display_object_updates.c (DisplayObject_RenderSpriteStrips), profile gcc_2_8_1_g8_split.
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
extern void func_80082840(void *p, int abe) ;
typedef void (*DisplayObjectCallback)(u8 *);
typedef struct DisplayObject {
    s16 previous;                   
    s16 next;                       
    u32 attribute;                  
    u16 flags;                      
    u8 field_0A;                    
    u8 field_0B;                    
    u32 field_0C;                   
    u32 field_10;                   
     









    u16 field_14;                   
    s8 field_16;                    
     









    u8 ot_index;                    
    u16 field_18;                   
    u16 field_1A;                   
    u16 field_1C;                   
    s16 field_1E;                   
     



     




    union {
        u32 word;
        struct {
            u16 field_20;
            u8 field_22;
            u8 field_23;
        } h;
        struct {
            u8 field_20;
            u8 field_21;
            u8 field_22;
            u8 field_23;
        } b;
    } field_20;                     
    DisplayObjectCallback update;   
     



    union {
        struct {
            u16 field_28;
            u16 field_2A;
        } h;
        s32 word;
    } position;                     
     













    union {
        u32 word;
        struct {
            u16 field_2C;
            s16 field_2E;
        } h;
    } field_2C;                     
    union {
        struct {
            u16 field_30;
            u16 field_32;
        } h;
        s32 word;
    } field_30;                     
     











    union {
        u32 word;
        struct {
            s16 field_34;
            s16 field_36;
        } h;
    } field_34;                     
     






























    union {
        u32 word;
        struct {
            s16 field_38;
            s16 field_3A;
        } h;
    } field_38;                     
     

    union {
        s32 word;
        struct {
            u16 field_3C;
            u16 field_3E;
        } h;
    } field_3C;                     
     






    union {
        u32 word;
        struct {
            s16 field_40;
            s16 field_42;
        } h;
    } field_40;                     
     


























    union {
        u32 word;
        struct {
            s16 field_44;
            s16 field_46;
        } h;
    } field_44;                     
    union {
        u32 word;
        struct {
            s16 field_48;
            s16 field_4A;
        } h;
    } field_48;                     
     



















    s32 field_4C;                   
     

















     







    union {
        s32 word;
        struct {
            s16 field_50;
            s16 field_52;
        } h;
    } field_50;                     
    void *field_54;                 
     






    s16 field_58;                   
    s16 field_5A;                   
    u16 field_5C;                   
    u16 field_5E;                   
     







    s16 field_60;                   
    u8 pad_62[2];                   
     




    u8 field_64;                    
    u8 field_65;                    
    u8 field_66;                    
     


    u8 field_67;                    
     








    u8 field_68;                    
     


    u8 field_69;                    
     


    u8 field_6A;                    
     



    u8 field_6B;                    
    u8 field_6C;                    
    u8 pad_6D[0x70  - 0x6D];
} DisplayObject;
extern s32 D_8009B424;
struct ProjectionOut {
    s16 f0;
    s16 f2;
    s32 f4;
};
struct DisplayObject;
s32 func_80041F90(struct DisplayObject *obj, s32 x, s32 y,
                  struct ProjectionOut *out);
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
    u32 unk0;
    u32 flag;
    u8 pad8[0x18];
    u8 out[4];
} ClipState;
struct DisplayObject;
void func_80042188(SpritePrim *sprite, u8 *packet, s32 ot, s32 mode, u8 *extra);
extern s16 D_8009B146 __attribute__((section(".data")));
extern s16 D_8009B148 __attribute__((section(".data")));
void func_800408D0(DisplayObject *e, s32 tex, s32 mode_arg);
void func_800408D0(DisplayObject *e, s32 tex, s32 mode_arg) {
    u16 mode16 = mode_arg;
    SpritePrim *p;
    ClipState *c;
    POLY_FT4 *g;
    s32 step;
    s32 mode;
    s32 remaining;
    s32 tag;
    s32 fl;

    c = (ClipState *)0x1F800378;
    p = (SpritePrim *)0x1F800320;
    g = (POLY_FT4 *)0x1F800344;
    step = 1;

    tag = e->attribute;
    p->attribute = tag;
    if (tag & 0x02000000 ) {
        step = 4;
    } else if (tag & 0x01000000 ) {
        step = 2;
    }
    p->tpage = e->field_66;
    p->xy.word = e->field_30.word;
    p->cxcy.word = e->field_40.word;
    p->rgb = e->field_0C;
    fl = e->flags;
    p->uv.word = e->field_5C;
    if ((fl & 0x08 ) == 0) {
        p->xy.h.x = p->xy.h.x - D_8009B146;
        p->xy.h.y = p->xy.h.y - D_8009B148;
    }
    p->extent.wh.h = e->field_3C.h.field_3E;
    remaining = e->field_3C.h.field_3C;
    c->flag = p->attribute & (1<<27) ;
    mode = mode16 | 0x10000;

    if ((e->flags & 0x04 ) != 0) {
        D_8009B424 = 0;
        if (func_80041F90(e, (s16)p->xy.h.x + (s16)e->field_18,
                          (s16)p->xy.h.y + (s16)e->field_1A,
                          (struct ProjectionOut *)c->out) <= 0) {
            return;
        }
        (((P_TAG *)( g ))->len  = (u8)(  9 )) ;
        *(s32 *)&g->r0 = p->rgb;
        g->code = 0x2C;
        if ((p->attribute & (1<<30) ) != 0) {
            func_80082840(g, 1);
        }
        c->flag = (1<<27) ;
        mode = mode16 | 0xF0000;
    } else if ((p->attribute & (1<<27) ) == 0) {
        p->rotate = e->field_20.h.field_22 * 5760;
        p->scale = e->field_44.word;
        mode = mode16 | 0x30000;
        p->mxmy.word = e->field_48.word;
        p->xy.h.x = p->xy.h.x + p->mxmy.h.x;
        p->xy.h.y = p->xy.h.y + p->mxmy.h.y;
    }

    do {
        p->extent.wh.w.word = 0x40;
        if (remaining < 0x40) {
            p->extent.wh.w.word = remaining;
        }
        if (p->uv.b.lo + p->extent.wh.w.word > 0x100) {
            p->extent.wh.w.word = 0x100 - p->uv.b.lo;
        }
        func_80042188(p, (u8 *)g, tex, mode, c->out);
        if (c->flag != 0) {
            p->xy.h.x = p->xy.h.x + p->extent.wh.w.word;
        } else {
            p->mxmy.h.x = p->mxmy.h.x - p->extent.wh.w.word;
        }
        if (p->uv.b.lo + p->extent.wh.w.word >= 0x100) {
            p->tpage = p->tpage + step;
        }
        p->uv.b.lo = p->uv.b.lo + p->extent.wh.w.b.lo;
        remaining -= p->extent.wh.w.word;
    } while (remaining != 0);
}
