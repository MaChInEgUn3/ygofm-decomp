/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/func_8001B938.c, profile gcc_2_8_1_g8_split.
 * The declarations above the function are the subset of that tree's headers
 * this unit needs, preprocessed and with symbols renamed to this tree's
 * spelling (func_ADDR, D_ADDR); their types are that tree's. Byte-identical
 * under the flag row in tools_src/build.py. */
#include "kg_types.h"
#include "kg_variables.h"
#include "kg_functions.h"
u8 *func_800249E0(s32, s32);
extern u8 D_800907CC[];
extern DuelCardRecord D_801A7AD8[];
extern u8 D_8009B1D5;
extern DuelSideState *D_8009B1C8;
extern AiActiveCard D_801AB000[];
DuelCardDisplayObject *func_80018004(
    DuelCardRecord *card, s32 x, s32 y
);
extern DuelHandSlot D_800EA030[5 ];
void func_8004036C(void *object);
extern u8 D_800EAE88[];
void func_8001BAF0(void)
{
    s8 sel[5 ];
    DuelDeckCardRecord tmp;
    DuelDeckCardRecord *rec;
    DuelDeckCardRecord *other;
    DuelCardDisplayObject *spawned;
    DuelHandSlot *slot;
    DuelCardRecord *records;
    AiActiveCard *card;
    u8 *order;
    s32 i;
    s32 j;
    s32 v;
    s32 id;
    s32 k;

    for (i = 0; i < 5 ; i++) {
        sel[i] = D_8009B1C8->hand[i];
    }
    for (i = 0; i < 5 ; i++) {
        v = D_800EAE88[i];
        if (v == 0) {
            break;
        }
        if (v < 0x10) {
            sel[v - 0xB] = -1;
        }
    }
    for (i = 0; i < 5 ; i++) {
        v = D_800EAE88[i];
        if (v == 0) {
            return;
        }
        if (v >= 0x10) {
            do {
                j = 0;
                order = D_800907CC;
                records = D_801A7AD8;
                slot = D_800EA030;
            search:
                if (sel[j] >= 0) {
                    card = &D_801AB000[v];
                    rec = ((DuelDeckCardRecord *)((u8 *)D_801AB000 - 0x31E0))  + sel[j];
                    other = ((DuelDeckCardRecord *)((u8 *)D_801AB000 - 0x31E0))  +
                            card->deck_index;
                    v = rec->deck_index;
                    rec->deck_index = other->deck_index;
                    other->deck_index = v;
                    tmp = *rec;
                    *rec = *other;
                    *other = tmp;
                    k = D_8009B1D5 * 5 ;
                    id = *(u8 *)((j + k) + (s32)order);
                    spawned = (DuelCardDisplayObject *)slot->object;
                    func_800249E0(id, rec->deck_index);
                    slot->object = (u8 *)func_80018004(
                        (DuelCardRecord *)(id * 0x1C  +
                                           (s32)records),
                        spawned->out_x, spawned->out_y);
                    func_8004036C(spawned);
                    D_8009B1C8->hand[j] = rec->deck_index;
                    D_800EAE88[i] = j + 0xB;
                    sel[j] = -1;
                    continue;
                }
                j++;
                slot++;
                if (j < 5 ) {
                    goto search;
                }
            } while (0);
        }
    }
}
