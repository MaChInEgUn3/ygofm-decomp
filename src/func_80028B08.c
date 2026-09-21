/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/func_80028B08.c, profile gcc_2_8_1_g8_split.
 * The declarations above the function are the subset of that tree's headers
 * this unit needs, preprocessed and with symbols renamed to this tree's
 * spelling (func_ADDR, D_ADDR); their types are that tree's. Byte-identical
 * under the flag row in tools_src/build.py.
 * NOT his C verbatim: `*(u32 *)&PRM->extent = 0x00100010;` is spelled
 * `*(u32 *)((u8 *)PRM + 8) = 0x00100010;` here. With his spelling cc1psx emits that store five
 * instructions early (above the `sh 4($a0)`), the one residue of this unit; the byte-address
 * cast, or writing the store after the `xy.h.y` line, both give retail's order (measured
 * 2026-09-21: 5 differences, then MATCH either way; the member spelling `PRM->extent.word`
 * is still 5). Same marking difference as func_8001BD88 and func_8001F55C. */
#include "kg_types.h"
#include "kg_variables.h"
#include "kg_functions.h"
void func_800357E8(s32 arg0, s32 arg1, u8 *arg2);
s32 func_80041F90(struct DisplayObject *obj, s32 x, s32 y,
                  struct ProjectionOut *out);
extern DuelEffectResourceRecord D_800EA0E8[];
void func_80028B08(DisplayObject *object, s32 arg1);
void func_80042188(
    SpritePrim *sprite,
    Func80028B08Ctx *packet,
    s32 ot,
    s32 mode,
    Func80028B08Extra *extra
);
void func_80028B08(DisplayObject *obj, s32 arg1) {
    u8 buf1[5];
    u8 buf2[5];
    Func80028B08Extra *EXT;
    SpritePrim *PRM;
    Func80028B08Ctx *CTX;
    DisplayObject *win;
    DuelEffectResourceRecord *rec;
    s32 arg;
    s32 i;
    u16 flags;
    u32 f4;
    u32 tile;
    u32 lo;
    s32 wrap;
    u16 k;
    s32 white;
    s32 sa;
    s32 sb;
    u32 m;

    wrap = 0xFFFF;
    win = (DisplayObject *)obj->field_54;
    if ((obj->attribute & (1<<31) ) != 0) {
        return;
    }
    flags = win->flags;
    if ((obj->field_66 & m) ^ (obj->field_67 & k)) {
        win->flags = flags;
    }
    if ((flags & 0x40) == 0) {
        return;
    }
    EXT = (Func80028B08Extra *)0x1F800398;
    PRM = (SpritePrim *)0x1F800320;
    CTX = (Func80028B08Ctx *)0x1F800344;
    arg = (((s16)win->field_14 - 1) & 0xFFFF) | 0x10000;
    if (flags & 0x4) {
        obj->field_20.word = win->field_20.word;
        f4 = obj->attribute & ~(1<<27) ;
        obj->field_44.word = win->field_44.word;
        obj->attribute = f4;
        f4 = f4 | (win->attribute & 0x08000000);
        obj->attribute = f4;
        if (func_80041F90(
                (struct DisplayObject *)obj, (s16)win->field_30.h.field_30 + (s16)win->field_18,
                (s16)win->field_30.h.field_32 + (s16)win->field_1A, (struct ProjectionOut *)EXT
            ) <= 0) {
            return;
        }
        arg = (((s16)win->field_14 - 1) & 0xFFFF) | 0xF0000;
        *(u32 *)&CTX->field_4 = win->field_0C;
        CTX->field_3 = 9;
        CTX->field_7 = 0x2C;
    }

    PRM->attribute = obj->attribute;
    PRM->xy.h.x = win->field_30.h.field_30 + 0x13;
    PRM->xy.h.y = win->field_30.h.field_32 + 0x32;
    PRM->extent.wh.w.word = 0x66;
    PRM->extent.wh.h = 0x60;
    PRM->rgb = win->field_0C;
    PRM->cxcy.word = obj->field_40.word;
    PRM->uv.word = obj->field_5C;
    PRM->tpage = obj->field_66;
    func_80042188(PRM, CTX, arg1, arg, EXT);

    CTX->field_7 |= 2;
    PRM->xy.h.x = win->field_30.h.field_30 + 0xC;
    PRM->xy.h.y = win->field_30.h.field_32 + 0xE;
    PRM->uv.b.hi = PRM->uv.b.hi + 0x60;
    m = 0xFEFFFFFF;
    PRM->attribute = (PRM->attribute & m) | 0x60000000;
    PRM->extent.wh.w.word = 0x60;
    k = 0xE;
    PRM->extent.wh.h = k;
    PRM->cxcy.h.cx = 0x1E0;
    white = 0xF8;
    PRM->cxcy.h.cy = white;
    func_80042188(PRM, CTX, arg1, arg, EXT);

    EXT->field_4 = 0;
    rec = &D_800EA0E8[obj->field_67];
    PRM->tpage = 0x1F;
    PRM->cxcy.h.cx = PRM->cxcy.h.cx + 0x10;
    PRM->xy.h.x = win->field_30.h.field_30 + obj->field_30.h.field_30;
    PRM->xy.h.y = win->field_30.h.field_32 + obj->field_30.h.field_32;
    PRM->extent.word = obj->field_3C.word;
    PRM->uv.word = obj->field_5E;
    if (obj->field_68 < 0x14) {
        if (rec->field_3C & 0x80) {
            PRM->cxcy.h.cy = PRM->cxcy.h.cy + 1;
        }
        func_80042188(PRM, CTX, arg1, arg, EXT);
        PRM->cxcy.h.cy = white;
        PRM->uv.b.hi = PRM->uv.b.hi + *(u8 *)&PRM->extent.wh.h;
        PRM->xy.h.y = PRM->xy.h.y + (PRM->extent.wh.h + wrap);
        if (rec->field_3C & 0x40) {
            PRM->cxcy.h.cy = 0xF9;
        }
        func_80042188(PRM, CTX, arg1, arg, EXT);
        PRM->cxcy.h.cy = white;

        i = rec->field_32 + rec->field_36;
        if (i > 9999) {
            PRM->cxcy.h.cy = white;
        }
        if (i > 9999 ) {
            i = 9999 ;
        }
        func_800357E8(i, 4, buf1);
        i = rec->field_34 + rec->field_38;
        if (i > 9999 ) {
            i = 9999 ;
        }
        func_800357E8(i, 4, buf2);

        PRM->uv.b.hi = (PRM->uv.b.hi & 0x80) + 0x10;
        PRM->xy.h.x = win->field_30.h.field_30 + 0x61;
        PRM->xy.h.y = win->field_30.h.field_32 + 0x9D;
        *(u32 *)&PRM->extent = 0x000D0006;
        if (rec->field_3C & 0x80) {
            PRM->cxcy.h.cy = 0xF9;
        }
        i = 3;
        do {
            PRM->uv.b.lo = buf1[i] * 6 + 0x10;
            func_80042188(PRM, CTX, arg1, arg, EXT);
            PRM->xy.h.x = PRM->xy.h.x + 6;
            i--;
        } while (i >= 0);

        PRM->xy.h.x = win->field_30.h.field_30 + 0x61;
        PRM->xy.h.y = win->field_30.h.field_32 + 0xAB;
        PRM->cxcy.h.cy = 0xF8;
        if (rec->field_3C & 0x40) {
            PRM->cxcy.h.cy = 0xF9;
        }
        i = 3;
        do {
            PRM->uv.b.lo = buf2[i] * 6 + 0x10;
            func_80042188(PRM, CTX, arg1, arg, EXT);
            PRM->xy.h.x = PRM->xy.h.x + 6;
            i--;
        } while (i >= 0);

        sa = win->field_30.h.field_30;
        do { sb = 0x00090009; } while (0);
        PRM->xy.h.x = sa + 0x77;
        PRM->xy.h.y = win->field_30.h.field_32 + 0x20;
        *(u32 *)&PRM->extent = sb;
        PRM->uv.b.lo = 0;
        PRM->cxcy.h.cx = 0x1C0;
        PRM->cxcy.h.cy = 0xF8;
        if (rec->field_3A != 0) {
            i = 0;
            do {
                func_80042188(PRM, CTX, arg1, arg, EXT);
                PRM->xy.h.x = PRM->xy.h.x - 9;
                i++;
            } while (i < (s32)rec->field_3A);
        }
    } else {
        func_80042188(PRM, CTX, arg1, arg, EXT);
    }

    PRM->xy.h.x = win->field_30.h.field_30 + 0x6E;
    *(u32 *)((u8 *)PRM + 8) = 0x00100010;
    PRM->xy.h.y = win->field_30.h.field_32 + 0xD;
    lo = rec->field_3B << 4;
    PRM->uv.b.lo = lo;
    PRM->uv.b.hi = PRM->uv.b.hi & 0x80;
    tile = PRM->uv.b.lo;
    PRM->cxcy.h.cx = win->field_40.h.field_40 + tile;
    PRM->cxcy.h.cy = 0xFF;
    func_80042188(PRM, CTX, arg1, arg, EXT);
}
