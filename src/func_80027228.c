/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/ai_turn_action.c, profile gcc_2_8_1_g8_split.
 * The declarations above the function are the subset of that tree's headers
 * this unit needs, preprocessed and with symbols renamed to this tree's
 * spelling (func_ADDR, D_ADDR); their types are that tree's. Byte-identical
 * under the flag row in tools_src/build.py. */
#include "kg_types.h"
#include "kg_variables.h"
#include "kg_functions.h"
extern AiSelection D_800EAE88;
s32 func_80027228(void) {
    DuelCardRecord *list1[6];
    DuelCardRecord *list0[6];
    DuelCardRecord *e1;
    DuelCardRecord *e2;
    s32 count;
    s32 slot;
    s32 i;
    s32 j;

    count = func_80026C6C(list0, 0, 20 );
    if (count == 0) {
        return 1;
    }
    count--;
    if (count != 0) {
        func_800358FC(count + 1);
    }
    if ((func_8008E590() & 1) == 0) {
        return 1;
    }
    func_80026D18(list1, 5 , -1);
    for (i = 0; (e1 = list0[i]) != 0; i++) {
        for (j = 0; (e2 = list1[j]) != 0; j++) {
            if (func_80019A60(*(s16 *)&e1->card_id, *(s16 *)&e2->card_id)) {
                goto found1;
            }
        }
    }
    slot = func_80026C0C(5 );
    if (slot >= 0) {
        goto phase2;
    }
    return 1;

found1:
    {
    AiSelection *st;
    s8 v;

    st = &D_800EAE88;
    v = e1->table_index;
    st->field1 = 0;
    st->result = v % 5  + 0xB;
    v = e2->table_index;
    st->value = v % 5  + 1;
    st->zero = func_8008E590() & 1;
    st->random = 0;
    return 0;
    }

found2:
    {
    AiSelection *st;
    s8 v;
    s8 w;

    st = &D_800EAE88;
    v = e1->table_index;
    st->result = v % 5  + 0xB;
    w = e2->table_index;
    st->field_02 = 0;
    st->value = slot % 5  + 1;
    st->field1 = w % 5  + 0xB;
    st->zero = func_8008E590() & 1;
    st->random = 0;
    return 0;
    }

phase2:
    func_80026C6C(list1, 0, 20 );
    for (i = 0; (e1 = list0[i]) != 0; i++) {
        for (j = 0; (e2 = list1[j]) != 0; j++) {
            if (*(s8 *)&e1->table_index != *(s8 *)&e2->table_index &&
                func_80019A60(*(s16 *)&e1->card_id, *(s16 *)&e2->card_id)) {
                goto found2;
            }
        }
    }
    return 1;
}
