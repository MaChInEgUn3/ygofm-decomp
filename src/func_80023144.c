/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/duel_field_display_objects.c, profile gcc_2_8_1_g8_split.
 * The declarations above the function are the subset of that tree's headers
 * this unit needs, preprocessed and with symbols renamed to this tree's
 * spelling (func_ADDR, D_ADDR); their types are that tree's. Byte-identical
 * under the flag row in tools_src/build.py. */
#include "kg_types.h"
#include "kg_variables.h"
#include "kg_functions.h"
extern u8 D_8009B1D5;
extern u8 D_8009B320 __attribute__((section(".data")));
extern s16 D_8009B338 __attribute__((section(".data")));
void func_80023144(DuelFieldDisplaySource *source, s32 index)
{
    DuelCardRecord *record = &D_801A7AD8[index];
    DuelEffectChannel *box;
    s32 *table;
    s32 style;
    s32 id;
    s32 value;
    s32 stats;

    D_8009B34E = 0;
    D_8009B355 = 0;
    style = 0x50;
    if (record->flags & 0x8000) {
        table = D_801D4244;
        id = (s16)record->card_id;
        stats = *(s32 *)((s32)table + ((id - 1) << 2));
        D_8009B34E = 1;
        D_8009B338 = id;
        if (((stats >> 26 ) & 0x1F ) <
            20 ) {
            if (record->flags & 0x200) {
                D_8009B344 =
                    (stats >> 18 ) &
                    0xF ;
            } else {
                D_8009B344 =
                    (stats >> 22 ) &
                    0xF ;
            }
            D_8009B344 = D_8009B344 + 0x17;
            value = func_800170C8(record);
            D_801D5608[0].card_stats.attack = (s16)value;
            D_801D5608[0].card_stats.defense = value >> 16;
        } else {
            style = 0x51;
        }
        if (index % 15  >= 5 ) {
            D_8009B34E = 2;
            if (record->flags & 0x1000) {
                D_8009B34E = 3;
            }
            value = index >= 15 ;
            if (value == D_8009B1D5 &&
                D_8009B1C8->card_view_mode == 0) {
                D_8009B34E = 2;
            }
        } else {
            if (record->flags & 0x2000) {
                D_8009B34E = 0;
            }
        }
    }
    value = source->table_index;
    if (value == 3) {
        s32 rank;
        TextStagingValues *dst = D_801D5608;

        style += 4;
        rank = D_800E9FF0[D_8009B1D5 ^ 1].swords_turns_remaining;
        dst->card_stats.rank = rank;
        if (rank != 0) {
            if (rank < 0 || rank > 3) {
                dst->card_stats.rank = 3;
            }
            D_8009B355 = 1;
        }
        if (D_8009B34E != 0) {
            D_8009B355 = D_8009B355 | 2;
            D_8009B320 = func_80023090(
                (DuelFieldCursor *)source,
                (DuelFieldCursor *)
                    &D_800E9F48[D_8009B1D5 * (4  * 0x1C ) ]
            );
        }
    }
    if (source->table_index == 2 && source->field_18 != 0) {
        s32 rank;
        TextStagingValues *dst;
        s32 side;

        side = D_8009B1D5;
        if (source->y < 2) {
            side = side ^ 1;
        }
        dst = D_801D5608;
        rank = D_800E9FF0[side].swords_turns_remaining;
        dst->card_stats.rank = rank;
        if (rank != 0) {
            if (rank < 0 || rank > 3) {
                dst->card_stats.rank = 3;
            }
            D_8009B355 = 1;
        }
        style += 2;
    }
    box = func_80035BE4(
        source->field_14, style,
        *(s16 *)&source->field_00->field_30.h.field_30 + 0x10,
        *(s16 *)&source->field_00->field_30.h.field_32 + source->field_16,
        0x120, 0x40
    );
    box->field_59 = *(u8 *)&source->field_00->field_16 + 1;
    func_80039A14((struct DuelEffectChannel *)box);
}
