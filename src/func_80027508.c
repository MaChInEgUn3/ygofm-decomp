/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/ai_turn_action.c, profile gcc_2_8_1_g8_split.
 * The declarations above the function are the subset of that tree's headers
 * this unit needs, preprocessed and with symbols renamed to this tree's
 * spelling (func_ADDR, D_ADDR); their types are that tree's. Byte-identical
 * under the flag row in tools_src/build.py. */
#include "kg_types.h"
extern int  func_8008E590(void);
extern DuelCardRecord D_801A7AD8[];
extern s32 D_801D4244[];
extern u8 D_8009B1D5;
s32 func_800358FC(s32 divisor);
s32 func_80026C0C(s32 start);
s32 func_80026DC8(void);
s32 func_80027060(void);
extern AiSelection D_800EAE88;
int func_8002712C(void);
s32 func_80027228(void);
s32 func_80027508(void) {
    DuelCardRecord *card;
    s32 slot;

    if ((func_8008E590() & 1) == 0 && func_80026DC8() == 0) {
        return 0;
    }
    if ((func_8008E590() & 1) == 0 && func_80027060() == 0) {
        return 0;
    }
    if ((func_8008E590() & 3) == 0 && func_8002712C() == 0) {
        return 0;
    }
    if (func_80027228() == 0) {
        return 0;
    }
    card = &D_801A7AD8[
        D_8009B1D5 * 15  +
        func_800358FC(5 )
    ];
    if (((D_801D4244[*(s16 *)&card->card_id - 1] >> 26 ) & 0x1F ) < 20 ) {
        s8 v;

        slot = func_80026C0C(5 );
        if (slot < 0) {
            slot = func_800358FC(5 );
        }
        v = card->table_index;
        D_800EAE88.field1 = 0;
        D_800EAE88.value = slot % 5  + 1;
        D_800EAE88.result = v % 5  + 0xB;
        D_800EAE88.zero = func_8008E590() & 1;
        D_800EAE88.random = 1;
    } else {
        s8 v;

        slot = func_80026C0C(10 );
        if (slot < 0) {
            slot = func_800358FC(5 );
        }
        v = card->table_index;
        D_800EAE88.field1 = 0;
        D_800EAE88.zero = 0;
        D_800EAE88.value = slot % 5  + 6;
        D_800EAE88.result = v % 5  + 0xB;
        D_800EAE88.random = func_8008E590() & 1;
        if (((D_801D4244[*(s16 *)&card->card_id - 1] >> 26 ) & 0x1F ) == 23 ) {
            D_800EAE88.random = 1;
        }
    }
    return 0;
}
