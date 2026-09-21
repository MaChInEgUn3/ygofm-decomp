/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/func_8001B170.c, profile gcc_2_8_1_g8_split.
 * The declarations above the function are the subset of that tree's headers
 * this unit needs, preprocessed and with symbols renamed to this tree's
 * spelling (func_ADDR, D_ADDR); their types are that tree's. Byte-identical
 * under the flag row in tools_src/build.py. */
#include "kg_types.h"
#include "kg_variables.h"
#include "kg_functions.h"
extern DisplayObject *D_800E9EF0[];
extern u8 D_8009B1D5;
extern s16 D_8009B338 __attribute__((section(".data")));
extern ;
extern s8 D_8009B34D __attribute__((section(".data")));
extern ;
extern u16 D_8009B398 __attribute__((section(".data")));
void func_8001B170(void)
{
    DisplayObject *object;
    DuelEffectChannel *box;
    DuelCardRecord *card;
    DuelCardRecord *scratch;
    DuelEffectRequest *request;
    u16 flags;
    u16 z;
    s32 slot;

    object = D_800E9EF0[0];
    if (!(D_8009B23A & 0x8000 )) {
        D_8009B23A |= 0x8000 ;
        if (D_8009B23A & 0x4000) {
            goto state_four;
        }
        if (D_8009B360[D_8009B1D5] >= 0 &&
            object->field_68 < 0x14) {
            D_801A7AD8[object->field_6A].flags &= ~0x200;
            if (D_800EAE8F[0] & 1) {
                D_801A7AD8[object->field_6A].flags |= 0x200;
            }
            goto state_four;
        }
        D_8009B174 = 1;
        func_80043178(((DisplayObjectSnapshot *)( object )) );
        object->field_60 = 0;
        if ((s16)object->field_30.h.field_30 == 0x86 ||
            (s16)object->field_30.h.field_32 == 0x2A) {
            D_8009B174 = 2;
            return;
        }
    }

    switch (D_8009B174 & 0xF) {
    case 1:
        func_8004318C(
            ((DisplayObjectPosition *)( object )) ,
            0x86, 0x2A, object->field_60);
        object->field_60 += 0x80;
        if (object->field_60 < 0x800) {
            break;
        }
        object->field_30.h.field_30 = 0x86;
        object->field_30.h.field_32 = 0x2A;
        D_8009B174 = 2;
         
    case 2:
        if (object->field_68 >= 0x14) {
            goto state_four;
        }
        D_8009B174 = 3;
         
    case 3:
        if (!(D_8009B174 & 0x80)) {
            D_8009B174 |= 0x80;
            D_8009B338 =
                D_8015C424_cards.field_cards[object->field_6A].card_id;
            func_8003B6AC(0, 0xB);
            box = func_80035C38(0, 0x21, 0x48, 0x6E, 0xB0, 0x30, 0x20);
            box->field_5A = 8;
            box->field_5B = 0x10;
            do {
                func_80039794();
            } while (box->field_30 == 0);
            break;
        }
        if (D_8009B174 & 0x10) {
            D_801A7AD8[object->field_6A].flags &= ~0x200;
            if (D_8009B34D) {
                D_801A7AD8[object->field_6A].flags |= 0x200;
            }
            func_80035B7C(D_800EB0F8);
state_four:
            D_8009B174 = 4;
            break;
        }
        if (!func_8003700C(D_800EB0F8) &&
            (D_8009B398 & 0xC0)) {
            func_8003FEE0(7);
            D_8009B174 |= 0x10;
        }
        break;
    case 4:
        if (!(D_8009B174 & 0x80)) {
            D_8009B174 |= 0x80;
            object->field_2C.h.field_2E = func_8001B0CC(D_8009B19C) - 0x1E;
            func_80043178(((DisplayObjectSnapshot *)( object )) );
            object->field_60 = 0x400;
        }
        if (!(D_8009B174 & 0x40)) {
            func_80043230(((DisplayObjectPosition *)( object )) ,
                             object->field_2C.h.field_2E, -0xBC,
                             object->field_60);
            object->field_60 -= 0x2A;
            if (object->field_60 > 0) {
                break;
            }
            D_8009B174 |= 0x40;
            scratch = (DuelCardRecord *)0x1F800000;
            *scratch = D_801A7AD8[object->field_6A];
            func_80024D34(D_8009B19C, object->field_6B);
            card = &D_801A7AD8[D_8009B19C];
            flags = card->flags | (scratch->flags & 0x7E00);
            card->flags = flags & ~0x400;
            if (!(flags & 0x1000)) {
                card->flags = flags & ~0x2400;
            }
            card->stat_modifier = scratch->stat_modifier;
            func_8004036C(object);
            D_800E9EF0[0] = card->object;
            object = D_800E9EF0[0];
            func_80018080((DuelCardDisplayObject *)object);
            ((DisplayObjectPosition *)( object )) ->out_y = -0xF0;
            func_80043178(((DisplayObjectSnapshot *)( object )) );
            object->field_60 = -0x400;
            break;
        }
        func_80043230(((DisplayObjectPosition *)( object )) ,
                         (s16)object->field_30.h.field_30, -0x18,
                         object->field_60);
        object->field_60 += 0x2A;
        if (object->field_60 < 0) {
            break;
        }
        ((DisplayObjectPosition *)( object )) ->out_y = -0x18;
        D_8009B174 = 5;
        func_8003FEE0(0xC);
        break;
    case 5:
        if (D_8009B154 &&
            func_80025028(689 )) {
            D_8009B174 = 6;
            break;
        }
        D_8009B23A = 5;
        break;
    case 6:
        if (!(D_8009B174 & 0x80)) {
            D_8009B174 |= 0xC0;
            D_8009B210 = 0;
        }
        if (D_8009B174 & 0x40) {
            if (func_8001F364()) {
                break;
            }
            request = func_8002C68C(0xD);
            request->field_00 = object->field_30.h.field_30;
            request->field_02 = object->field_30.h.field_32;
            z = object->field_34.h.field_34;
            request->field_12 = -D_8009B154;
            request->field_04 = z;
            func_8003FEE0(0x21);
            D_8009B174 &= ~0x40;
            break;
        }
        slot = object->field_6A;
        D_8009B23A = 5;
        card = &D_801A7AD8[slot];
        card->stat_modifier -= D_8009B154 * 2;
        break;
    }
}
