/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/duel_field_effect_steps.c (DuelEffect_ApplyCursebreaker), profile gcc_2_8_1_g8_split.
 * The declarations above the function are the subset of that tree's headers
 * this unit needs, preprocessed and with symbols renamed to this tree's
 * spelling (func_ADDR, D_ADDR); their types are that tree's. Byte-identical
 * under the flag row in tools_src/build.py. */
#include "kg_types.h"
#include "kg_variables.h"
#include "kg_functions.h"
extern u8 D_800907D8[2 ][20 ];
extern volatile u8 D_8009B1D5;
void func_800260D0(void) {
    DuelCardRecord *record;
    DuelEffectObject *object;
    DuelFieldPosition *position;
    u8 *positions;
    s32 card;
    s32 next;
    s32 base_slot;
    s32 x;
    s32 timer;
    s32 step;
    s32 position_index;
    u8 *grid;

    if (func_80024E24() == 0) {
        D_8009B20C[1] = -1;
        D_8009B1D0 = 0;
    }

    timer = D_8009B1D0 - 1;
    D_8009B1D0 = timer;
    if ((s16)timer > 0) {
        return;
    }

    D_8009B1D0 = 0x10;
    next = *(u16 *)&D_8009B20C[1] + 1;
    D_8009B20C[1] = next;
    if ((s16)next < 5 ) {
         






        do {
            grid = (u8 *)D_800907D8;
            base_slot = D_8009B1D5 * 20  +
                        10 ;
        } while ((s16)next == 0 && (s16)next != 0);
        card = grid[(s16)next + base_slot];
        record = &D_801A7AD8[card];
        object = (DuelEffectObject *)func_8002C604(8);
        positions = (u8 *)D_80090800;
        step = D_8009B20C[1];
         
        position_index = step + 10 ;
        object->field_1A = 3;
        position = (DuelFieldPosition *)(
            (u32)&((DuelFieldPosition *)0)[position_index] +
            D_8009B1D5 * (20  * sizeof(DuelFieldPosition))  +
            positions
        );
        x = *(u16 *)&position->x;
        object->y = 0;
        object->x = x;
        object->field_04 = *(u16 *)&position->y;
        object->field_14 = object->field_14 + step * 0x3000;
        func_8003FEE0(0x14);

        if ((record->flags & 0x8000 ) != 0) {
            if (record->stat_modifier < 0) {
                record->stat_modifier = 0;
                object->field_1A = 5;
            }
        }
    } else {
        D_8009B220 = 0;
    }
}
