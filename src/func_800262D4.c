/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/duel_ritual_effect.c (DuelEffect_ApplyRitual), profile gcc_2_8_1_g8_split.
 * The declarations above the function are the subset of that tree's headers
 * this unit needs, preprocessed and with symbols renamed to this tree's
 * spelling (func_ADDR, D_ADDR); their types are that tree's. Byte-identical
 * under the flag row in tools_src/build.py. */
#include "kg_types.h"
#include "kg_variables.h"
#include "kg_functions.h"
extern u16 D_8009B220;
extern s16 D_8009B1D2;
extern s16 D_8009B20C[2];
extern u16 D_8009B210;
s32 func_80024E24(void);
s32 func_8002C7E8(DuelRitualResult *out, s32 ritual_id);
extern s16 D_8009B1A0;
extern DisplayObject *D_8009B1C0;
extern u16 D_800EA128[22 ];
void func_80019CC8(void *card_id);
extern DuelCardRecord D_801A7AD8[];
u8 *func_80017F04(DuelCardRecord *arg0, s32 arg1, s32 arg2);
void func_80024914(DuelCardRecord *object);
void func_80024D34(s32 slot, s32 card_id);
extern u8 D_8018C2D8[];
extern u8 D_8015C424[];
extern DuelCardStagingDeckView D_8015C424_cards asm("D_8015C424");
u8 *func_8002C604(s32 id);
extern u8 *D_8009B17C;
extern u8 D_8009B1D5;
extern u8 D_8009B19C;
extern s8 D_8009B360[2 ] __attribute__((section(".data")));
extern DisplayObjectRitualWorkArea D_800E9EF0;
void *func_80042B40(s32 value);
s32 func_800428EC(DisplayObject *object, s8 value);
void func_800429D8(DisplayObjectVelocity *object);
void func_80042A28(DisplayObjectVelocity *object);
void func_80043178(DisplayObjectSnapshot *object);
void func_80043230(
    DisplayObjectPosition *object,
    int target_x,
    int target_y,
    int phase);
void func_8001EC70(u8 *object);
void func_8004036C(void *object);
void func_8001944C(DisplayObject *object);
void func_8001944C(DisplayObject *object);
DisplayObject *func_80019564(DisplayObjectConfigView *source);
u8 *func_800291E0(s32 index, s32 x, s32 y);
void func_80029528(s32 index);
extern DuelEffectChannel D_800EB0F8[4 ];
extern s16 D_8009B338 __attribute__((section(".data")));
void func_80035B7C(struct DuelEffectChannel *record);
void *func_80035C38(
    s32 index, s32 string_id, s32 x, s32 y, s32 width, s32 height, s32 flags
);
s32 func_8003700C(struct DuelEffectChannel *record);
extern s8 D_8009B34D __attribute__((section(".data")));
extern u16 D_8009B398 __attribute__((section(".data")));
void func_8003FEE0(u32);
void func_8003FF88(u32);
void func_80039794(void);
extern int  func_8008E590(void);
extern int func_8007F9D8(RECT *rect, u32 *p);
void func_800262D4(void);
void func_800262D4(void)
{
    DisplayObject *object;
    DuelCardRecord *card;
    DuelEffectChannel *text;
    s32 value;
    s32 timer;
    u16 flags;

    if (!func_80024E24()) {
        D_8009B1A0 = func_8002C7E8(
            &D_800E9EF0.ritual.result, D_8009B1D2);
        if (D_8009B1A0) {
            func_80019CC8((void *)(s32)D_8009B1A0);
            D_8009B17C = func_8002C604(22);
            D_8009B210 = 0;
            ((DuelEffectRequest *)D_8009B17C)->field_1A = D_8009B1D2;
            func_8003FF88(0x8022);
        } else {
            goto done;
        }
        return;
    }
    switch (D_8009B210 & 0xF) {
    case 0:
        if (((DuelEffectRequest *)D_8009B17C)->field_1D) {
            D_8009B19C = D_800E9EF0.slots[3]->field_6A;
            func_80024914(&D_801A7AD8[D_800E9EF0.slots[2]->field_6A]);
            func_80024914(&D_801A7AD8[D_800E9EF0.slots[3]->field_6A]);
            func_80024914(&D_801A7AD8[D_800E9EF0.slots[4]->field_6A]);
            D_8009B210 = 1;
        }
        break;
    case 1: {
        u16 scale;
        s32 countdown;
        object = D_8009B1C0;
        if (!(D_8009B210 & 0x80)) {
            s32 attribute;
            s16 object_flags;
            D_8009B210 |= 0x80;
            object = (DisplayObject *)func_800291E0(1, -1, -1);
            object->field_30.h.field_30 = 90;
             


            *(s16 *)&object->field_30.h.field_32 = -34;
            object->field_60 = 24;
            attribute = object->attribute;
            object_flags = object->flags;
            object->field_44.h.field_46 = 0;
            object->field_44.h.field_44 = 0;
            object->attribute = attribute & 0xF7FFFFFF;
            object->flags = object_flags | 4;
            func_800429D8((DisplayObjectVelocity *)object);
            object->field_38.h.field_38 = 597;
            D_8009B1C0 = object;
            func_8003FEE0(0x26);
        }
        func_80042A28((DisplayObjectVelocity *)object);
        scale = (u16)object->field_44.h.field_44 + 170;
        countdown = (u16)object->field_60 - 1;
        object->field_44.h.field_44 = scale;
        object->field_44.h.field_46 = scale;
        object->field_60 = countdown;
        if ((s32)((u32)countdown << 16) <= 0) {
            s32 attribute;
            s16 object_flags;
            object->field_44.h.field_46 = 4096;
            object->field_44.h.field_44 = 4096;
            object->field_30.h.field_32 = 22;
            D_8009B210 = 2;
            attribute = object->attribute | 0x08000000;
            object_flags = object->flags & 0xFFFB;
            object->attribute = attribute;
            object->flags = object_flags;
        }
        break;
    }
    case 2:
        object = D_8009B1C0;
        if (!(D_8009B210 & 0x80)) {
            D_8009B210 |= 0x80;
            D_8009B20C[1] = 32;
        }
        if (!(D_8009B210 & 0x40)) {
            timer = *(u16 *)&D_8009B20C[1] - 1;
            D_8009B20C[1] = timer;
            if ((s32)((u32)timer << 16) <= 0) {
                D_8009B210 |= 0x40;
                func_8001944C(object);
                D_800E9EF0.slots[0] =
                    func_80019564(
                        (DisplayObjectConfigView *)object);
                D_800E9EF0.slots[0]->attribute |= 0x50000000;
                D_800E9EF0.slots[0]->attribute &= ~0x08000000;
                D_800E9EF0.slots[1] =
                    func_80019564(
                        (DisplayObjectConfigView *)object);
                func_800428EC(D_800E9EF0.slots[1], -1);
                D_800E9EF0.slots[1]->attribute |= 0x60000000;
                D_800E9EF0.slots[1]->attribute &= ~0x08000000;
                func_80029528(1);
            }
        } else {
            DisplayObject *first = D_800E9EF0.slots[0];
            DisplayObject *second = D_800E9EF0.slots[1];
            value = first->field_44.h.field_44 + 128;
            second->field_44.h.field_46 = value;
            second->field_44.h.field_44 = value;
            first->field_44.h.field_46 = value;
            first->field_44.h.field_44 = value;
            value = *(u8 *)&D_800E9EF0.slots[0]->field_0C;
            value -= 4;
            if (value < 0)
                value = 0;
            value = value | ((value << 16) | (value << 8));
            D_800E9EF0.slots[0]->field_0C = value;
            D_800E9EF0.slots[1]->field_0C = value;
            if (!value) {
                func_8004036C(D_800E9EF0.slots[0]);
                func_8004036C(D_800E9EF0.slots[1]);
                D_8009B210 = 3;
            }
        }
        break;
    case 3: {
        u16 state = D_8009B210;
        u16 *rects = D_800EA128;
        u8 *data;
        card = &D_801A7AD8[D_8009B19C];
        if (!(state & 0x80)) {
            u16 ritual;
            u16 y;
             


            *(u16 *)card->data = ritual = D_8009B1A0;
            data = *(u8 **)&card->data;
            D_8009B210 = state | 0x80;
            card->card_id = ritual;
            value = data[3];
            y = rects[21];
            rects[4] = rects[20] + 56;
            rects[6] = 8;
            rects[7] = 88;
            rects[5] = y;
            func_8007F9D8((RECT *)&rects[4],
                (u32 *)(D_8018C2D8 + 1408 * value));
            break;
        }
        func_80024D34(D_8009B19C, ((s8 *)card->data)[2]);
        object = card->object;
        D_800E9EF0.slots[0] = object;
        *(s16 *)&object->field_30.h.field_32 = -240;
        if (D_8009B360[D_8009B1D5] >= 0) {
            card->flags &= ~0x200;
            if (func_8008E590() & 1)
                card->flags |= 0x200;
            goto state_five;
        }
        D_800E9EF0.slots[1] = (DisplayObject *)func_80017F04(card, 134, 240);
        D_8009B210 = 4;
    }
    case 4:
        object = D_800E9EF0.slots[1];
        if (!(D_8009B210 & 0x80)) {
            D_8009B210 |= 0x80;
            object->position.h.field_28 = 134;
            object->position.h.field_2A = 42;
            object->field_2C.h.field_2C = 16;
            object->field_6C = 1;
            object->update = func_8001EC70;
        } else if (!(D_8009B210 & 0x40)) {
            if (!func_80042B40(1)) {
                D_8009B338 =
                    D_8015C424_cards.field_cards[object->field_6A].card_id;
                text = func_80035C38(0, 33, 72, 110, 176, 48, 32);
                text->field_5A = 8;
                text->field_5B = 16;
                do {
                    func_80039794();
                } while (!text->field_30);
                D_8009B210 |= 0x40;
            }
        } else if (!(D_8009B210 & 0x20)) {
            if (!func_8003700C(D_800EB0F8) &&
                (D_8009B398 & 0xC0)) {
                func_8003FEE0(7);
                object->position.h.field_28 = 134;
                *(s16 *)&object->position.h.field_2A = -128;
                object->field_2C.h.field_2C = 16;
                object->field_6C = 1;
                object->update = func_8001EC70;
                card = &D_801A7AD8[object->field_6A];
                flags = card->flags & ~0x200;
                card->flags = flags;
                if (D_8009B34D)
                    card->flags = flags | 0x200;
                func_80035B7C(D_800EB0F8);
                D_8009B210 |= 0x20;
            }
        } else if (!func_80042B40(1)) {
            func_8004036C(object);
state_five:
            D_8009B210 = 5;
        }
        break;
    case 5: {
        s16 phase;
        object = D_800E9EF0.slots[0];
        if (!(D_8009B210 & 0x80)) {
            D_8009B210 |= 0x80;
            func_80043178((DisplayObjectSnapshot *)object);
            object->field_60 = -1024;
        }
        func_80043230((DisplayObjectPosition *)object,
            (s16)object->field_30.h.field_30, -24, object->field_60);
        phase = (u16)object->field_60 + 42;
        object->field_60 = phase;
        if (phase >= 0) {
            *(s16 *)&object->field_30.h.field_32 = -24;
done:
            D_8009B220 = 0;
        }
        break;
    }
    }
}
