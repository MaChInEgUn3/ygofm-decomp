/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/func_800283F4.c (DuelEffect_UpdateCardViewerState), profile gcc_2_8_1_g8_split.
 * The declarations above the function are the subset of that tree's headers
 * this unit needs, preprocessed and with symbols renamed to this tree's
 * spelling (func_ADDR, D_ADDR); their types are that tree's. Byte-identical
 * under the flag row in tools_src/build.py. */
#include "kg_types.h"
#include "kg_variables.h"
#include "kg_functions.h"
int func_800282E8(void);
extern volatile u8 D_8009B0C0 __attribute__((section(".data")));
void func_80029574(s32 index);
extern volatile u16 D_8009B398 __attribute__((section(".data")));
extern volatile u16 D_8009B39A __attribute__((section(".data")));
extern u8 D_8009B140 __attribute__((section(".data")));
void func_80015BD8(s32, s32);
extern DuelEffectChannel D_800EB0F8[4 ];
extern s16 D_8009B338 __attribute__((section(".data")));
extern u8 D_8009B248;
extern u8 D_8009B248;
extern u8 D_8009B254;
extern u16 D_8009B246;
extern DisplayObject *D_8009B240;
extern u8 D_8009B24B;
extern DisplayObject *D_8009B24C;
extern DuelEffectChannel *D_8009B250;
extern DisplayObject *D_8009B240;
extern DisplayObject *D_8009B24C;
extern DuelEffectChannel *D_8009B250;
void func_80035B7C(struct DuelEffectChannel *record);
void *func_80035BE4(
    s32 index, s32 string_id, s32 x, s32 y, s32 width, s32 height
);
void func_8003FEE0(u32);
s32 func_8004002C(void);
void *func_800400AC(s32 index, s32 key);
void func_8004036C(void *object);
void func_800404CC(
    void *object, s32 x, s32 y, s32 field_67, s32 field_68,
    s32 field_69, s32 color, s32 texture
);
extern volatile u16 D_8009AF74[4] __attribute__((section(".data")));
s32 func_800428EC(DisplayObject *object, s8 value);
void func_80042918(DisplayObject *object);
u8 *func_800291E0(s32 index, s32 x, s32 y);
void func_80029528(s32 index);
extern u32 D_8009B134_abs __attribute__((section(".data")));
FileTransferDescriptor *func_80029164(s32 slot, s32 value);
void func_80043178(DisplayObjectSnapshot *object);
void func_80043230(
    DisplayObjectPosition *object,
    int target_x,
    int target_y,
    int phase);
void func_80039934(struct DuelEffectChannel *record, s32 x, s32 y);
void func_80039A14(struct DuelEffectChannel *object);
extern s32 D_801D4244[];
extern DuelEffectResourceRecord D_800EA0E8[];
void func_800283F4(void);
extern u8 D_8009B26C __attribute__((section(".data")));
void func_800283F4(void)
{
    s32 slide_in;
    s32 slide_out;
    DisplayObject *obj;
    DisplayObject *bg;
    DuelEffectResourceRecord *p;
    DisplayObject *next_obj;
    s32 *stats;
    DuelEffectChannel *box;
    DuelEffectChannel *chan;
    DuelEffectChannel *pos_box;
    DuelEffectChannel *dead_box;
    s32 adj;
    s32 i;
    s32 kind;
    s32 masked;
    s32 speed;
    s32 test;
    u16 flags;
    u16 id;
    u16 objflags;
    u8 closing;
    u8 state;

    if (func_800282E8() == 0) {
        slide_in = -0x400;
        D_8009B0C0 = 1;
        func_80029574(3);
        p = &D_800EA0E8[0];
        p[3].src_y = 0x100;
        p[3].src_x = 0;
        p[3].field_2C = 0;
        p[3].field_2E = 0xFF;
        func_80029164(3, (s16)D_8009B246);
        obj = (DisplayObject *)func_800291E0(3, -1, -1);
        adj = D_8009B24B;
        *(s16 *)&obj->field_30.h.field_30 = -0x8C;
        obj->field_20.b.field_21 = 0x80;
        obj->field_30.h.field_32 += adj;
        obj->flags |= 0x04 ;
        func_80043178(((DisplayObjectSnapshot *)( obj )) );
        obj->field_60 = slide_in;
        func_80042918(obj);
        func_800428EC(obj, 0x14);
        D_8009B24C = obj;
        obj = func_800400AC(func_8004002C(), 2);
        func_800404CC((u8 *)obj, 0x148, D_8009B24B + 0xE, 0, 2, 0, 0xD, 0x107);
        obj->field_60 = slide_in;
        obj->flags |= 0x08 ;
        func_80042918(obj);
        func_800428EC(obj, 0x14);
        func_80043178(((DisplayObjectSnapshot *)( obj )) );
        obj->field_60 = slide_in;
        D_8009B240 = obj;
        D_8009B250 = 0;
        i = 0;
        stats = D_801D4244;
        chan = D_800EB0F8;
        for (; i < 3; i++, chan++) {
            if ((chan->flags_34 & 0x8000 ) == 0) {
                id = D_8009B246;
                D_8009B338 = id;
                kind = 3;
                if (((stats[(s16)id - 1] >> 26 ) &
                     0x1F ) >= 20 ) {
                    kind = 4;
                }
                box = func_80035BE4(i, kind, 0x148, 0xE, 0xA8, 0xC0);
                box->field_53 = 1;
                box->field_54 = 0;
                box->field_59 = 0x15;
                D_8009B250 = box;
                func_80039A14((struct DuelEffectChannel *)box);
                break;
            }
        }
        func_80015BD8(0x40, 2);
        D_8009B140 = *(u8 *)&D_8009AF74[1] - 0x13;
        func_8003FEE0(0x34);
        D_8009B248 |= 0x40;
        return;
    }

    state = D_8009B248;
    if (state & 0x40) {
        obj = D_8009B240;
        speed = obj->field_60;
        if (speed != 0) {
            if (state & 0x10) {
                func_80043230(((DisplayObjectPosition *)( obj )) ,
                                 0x148,
                                 *(s16 *)&obj->field_30.h.field_32,
                                 speed);
                flags = *(u16 *)&obj->field_60 - 0x55;
                obj->field_60 = flags;
                if ((s16)flags <= 0) {
                    *(s16 *)&obj->field_30.h.field_30 = 0x400;
                    obj->field_60 = 0;
                }
            } else {
                func_80043230(((DisplayObjectPosition *)( obj )) ,
                                 0x94,
                                 *(s16 *)&obj->field_30.h.field_32,
                                 speed);
                flags = *(u16 *)&obj->field_60 + 0x55;
                obj->field_60 = flags;
                if ((s16)flags >= 0) {
                    *(s16 *)&obj->field_30.h.field_30 = 0x94;
                    obj->field_60 = 0;
                }
            }
            pos_box = D_8009B250;
            if (pos_box != 0) {
                func_80039934(pos_box, *(s16 *)&obj->field_30.h.field_30,
                               *(s16 *)&obj->field_30.h.field_32);
            }
        }
        obj = D_8009B24C;
        speed = obj->field_60;
        if (speed != 0) {
            if (D_8009B248 & 0x10) {
                func_80043230(((DisplayObjectPosition *)( obj )) ,
                                 -0x8C,
                                 *(s16 *)&obj->field_30.h.field_32,
                                 speed);
                flags = *(u16 *)&obj->field_60 - 0x55;
                obj->field_60 = flags;
                if ((s16)flags <= 0) {
                    *(s16 *)&obj->field_30.h.field_30 = 0x400;
                    obj->field_60 = 0;
                }
            } else {
                func_80043230(((DisplayObjectPosition *)( obj )) ,
                                 2,
                                 *(s16 *)&obj->field_30.h.field_32,
                                 speed);
                flags = *(u16 *)&obj->field_60 + 0x55;
                obj->field_60 = flags;
                if ((s16)flags >= 0) {
                    *(s16 *)&obj->field_30.h.field_30 = 2;
                    obj->field_60 = 0;
                }
            }
        }
        if (((D_8009B0F4_abs & 0x02000030 ) |
             D_8009B134_abs) != 0) {
            return;
        }
        bg = D_8009B240;
        if (bg->field_60 != 0) {
            return;
        }
        if (D_8009B24C->field_60 != 0) {
            return;
        }
        closing = D_8009B248;
        masked = closing & 0xBF;
        test = closing & 0x10;
        D_8009B248 = masked;
        if (test == 0) {
            return;
        }
        func_8004036C(bg);
        func_80029528(3);
        dead_box = D_8009B250;
        if (dead_box != 0) {
            func_80035B7C(dead_box);
        }
        D_8009B0C0 = 0;
        D_8009B254 |= 0x40;
        return;
    }

    if ((state & 0x20) == 0) {
        obj = D_8009B24C;
        obj->field_20.b.field_21 += 0xC;
        if (obj->field_20.b.field_21 < 0x40) {
            objflags = obj->flags;
            obj->field_20.b.field_21 = 0;
            state = D_8009B248 | 0x20;
            obj->flags = objflags & 0xFFFB;
            D_8009B248 = state;
        }
        return;
    }

    if ((D_8009B26C & 0x1F) == 0xE) {
        if (((D_8009B398 | D_8009B39A) & 0x20) != 0) {
            goto press;
        }
        return;
    }
    if ((D_8009B398 & 0x20) == 0) {
        return;
    }
press:
    slide_out = 0x400;
    func_80043178(((DisplayObjectSnapshot *)( D_8009B240 )) );
    next_obj = D_8009B24C;
    D_8009B240->field_60 = slide_out;
    func_80043178(((DisplayObjectSnapshot *)( next_obj )) );
    D_8009B24C->field_60 = slide_out;
    func_80015BD8(0xFF, 2);
    func_8003FEE0(0x34);
    D_8009B248 |= 0x50;
}
