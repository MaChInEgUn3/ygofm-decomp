/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/duel_card_effects.c (DuelEffect_ApplyStatPenalty), profile gcc_2_8_1_g8_split.
 * The declarations above the function are the subset of that tree's headers
 * this unit needs, preprocessed and with symbols renamed to this tree's
 * spelling (func_ADDR, D_ADDR); their types are that tree's. Byte-identical
 * under the flag row in tools_src/build.py. */
#include "kg_types.h"
#include "kg_variables.h"
#include "kg_functions.h"
extern u8 D_8009B1D5;
void func_80025D30(void) {
    DuelCardRecord *record;
    DuelEffectObject *object;
    DisplayObject *card;
    s32 timer;
    s32 base_slot;

    if (func_80024E24() == 0) {
        D_8009B20C[1] = 0;
        D_8009B1D0 = 0;
    }

    if ((D_8009B220 & 0x40) != 0) {
        if ((D_8009B260 & 1) == 0) {
            D_8009B220 = 0;
        }
        return;
    }

    timer = *(u16 *)&D_8009B20C[1] - 1;
    D_8009B20C[1] = timer;
    if ((s16)timer > 0) {
        return;
    }
    D_8009B20C[1] = 0x10;

    base_slot = D_8009B1D5 * 20  +
                5 ;
    record = &D_801A7AD8[D_800907D8_flat[(s16)D_8009B1D0 + base_slot]];
    if ((record->flags & 0x8000 ) != 0) {
        card = ((DisplayObject *)( record->object )) ;
        object = (DuelEffectObject *)func_8002C604(0xD);
        object->x = card->field_30.h.field_30;
        object->y = card->field_30.h.field_32;
        object->field_04 = *(u16 *)&card->field_34;
        object->field_14 = object->field_14 + ((s16)D_8009B1D0 << 14);
        if (D_8009B1D2 == 349 ) {
            object->field_1A = 2;
            record->stat_modifier =
                record->stat_modifier - 500 ;
            object->field_12 = - 500 ;
        } else {
            object->field_1A = 1;
            record->stat_modifier =
                record->stat_modifier - 2 * 500 ;
            object->field_12 = -2 * 500 ;
        }
        func_8003FEE0(0x21);
    }

    D_8009B1D0 = D_8009B1D0 + 1;
    if ((s16)D_8009B1D0 >= 5 ) {
        D_8009B220 = D_8009B220 | 0x40;
    }
}
