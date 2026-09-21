/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/display_object_updates.c (DisplayObject_RenderSpriteStrips), profile gcc_2_8_1_g8_split.
 * The declarations above the function are the subset of that tree's headers
 * this unit needs, preprocessed and with symbols renamed to this tree's
 * spelling (func_ADDR, D_ADDR); their types are that tree's. Byte-identical
 * under the flag row in tools_src/build.py. */
#include "kg_types.h"
#include "kg_variables.h"
#include "kg_functions.h"
extern s32 D_8009B424;
s32 func_80041F90(struct DisplayObject *obj, s32 x, s32 y,
                  struct ProjectionOut *out);
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
