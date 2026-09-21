/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/ai_fusion.c (AiScript_FindBestCombo), profile gcc_2_8_1_g0_split.
 * The declarations above the function are the subset of that tree's headers
 * this unit needs, preprocessed and with symbols renamed to this tree's
 * spelling (func_ADDR, D_ADDR); their types are that tree's. Byte-identical
 * under the flag row in tools_src/build.py. */
#include "kg_types.h"
#include "kg_variables.h"
#include "kg_functions.h"
void func_800727C0(s32 card_id);
void func_800727C0(s32 arg0);
void func_80072A48(void)
{
    s32 depth;
    s32 sets;
    s32 dest;
    s32 n;
    s32 i;
    s32 slot;
    s32 card;
    u8 *e;
    s32 *table;

    table = D_800F5B98;
    depth = table[func_8007058C()];
    sets = table[func_8007058C()];
    depth = depth + 1;
    dest = func_8007058C();
    n = func_80070710();

    D_800F5BE8.fusion_count = n;
    D_800F5BE8.fusion_best_stat = 0;
    D_800F5BE8.fusion_depth = 0;
    D_800F5BE8.fusion_limit = depth;
    D_800F5BE8.fusion_set = sets;

    for (i = 0; i < D_800F5BE8.fusion_count; i++) {
        D_800F5BE8.fusion_used[i] = 0;
    }

    for (i = 0; i < 5 ; i++) {
        card = D_801AB000[i + 1 ].card_id;
        slot = i + 1;
        if (card == 0) {
            continue;
        }
        if (func_80070920(sets, slot) != 0) {
            continue;
        }
        D_800F5BE8.fusion_path[D_800F5BE8.fusion_depth] = slot;
        if (D_801AB000[i + 1 ].attack >
            D_800F5BE8.fusion_best_stat) {
            D_800F5BE8.fusion_best_stat =
                D_801AB000[i + 1 ].attack;
            D_800F5BE8.combo_cards[0] = slot;
            D_800F5BE8.combo_cards[1] = 0;
            D_800F5BE8.fusion_best_depth =
                D_800F5BE8.fusion_depth;
        }
        if (D_801AB000[i + 1 ].defense >
            D_800F5BE8.fusion_best_stat) {
            D_800F5BE8.fusion_best_stat =
                D_801AB000[i + 1 ].defense;
            D_800F5BE8.combo_cards[0] = slot;
            D_800F5BE8.combo_cards[1] = 0;
            D_800F5BE8.fusion_best_depth =
                D_800F5BE8.fusion_depth;
        }
        if (D_800F5BE8.fusion_limit >= 2) {
             



            e = (u8 *)&D_800F5BE8 + i;
            e[0xAA ] = 1;
            D_800F5BE8.fusion_depth =
                D_800F5BE8.fusion_depth + 1;
            func_800727C0(card);
            e[0xAA ] = 0;
            D_800F5BE8.fusion_depth =
                D_800F5BE8.fusion_depth - 1;
        }
    }

    for (i = 0; i < D_800F5BE8.fusion_count; i++) {
        card = D_801AB000[i + ((1  + 5 )  + 5 ) ].card_id;
        slot = i + ((1  + 5 )  + 5 ) ;
        if (card == 0) {
            continue;
        }
        if (func_80070920(sets, slot) != 0) {
            continue;
        }
        D_800F5BE8.fusion_path[D_800F5BE8.fusion_depth] = slot;
        if (D_801AB000[i + ((1  + 5 )  + 5 ) ].attack >
            D_800F5BE8.fusion_best_stat) {
            D_800F5BE8.fusion_best_stat =
                D_801AB000[i + ((1  + 5 )  + 5 ) ].attack;
            D_800F5BE8.combo_cards[0] = slot;
            D_800F5BE8.combo_cards[1] = 0;
            D_800F5BE8.fusion_best_depth =
                D_800F5BE8.fusion_depth;
        }
        if (D_801AB000[i + ((1  + 5 )  + 5 ) ].defense >
            D_800F5BE8.fusion_best_stat) {
            D_800F5BE8.fusion_best_stat =
                D_801AB000[i + ((1  + 5 )  + 5 ) ].defense;
            D_800F5BE8.combo_cards[0] = slot;
            D_800F5BE8.combo_cards[1] = 0;
            D_800F5BE8.fusion_best_depth =
                D_800F5BE8.fusion_depth;
        }
        if (D_800F5BE8.fusion_limit >= 3) {
             



            e = (u8 *)&D_800F5BE8 + i;
            e[0xAA ] = 1;
            D_800F5BE8.fusion_depth =
                D_800F5BE8.fusion_depth + 1;
            func_800727C0(card);
            e[0xAA ] = 0;
            D_800F5BE8.fusion_depth =
                D_800F5BE8.fusion_depth - 1;
        }
    }

    if (D_800F5BE8.combo_cards[0] != 0) {
        if (D_800F5BE8.combo_cards[0] >= 5  + 1) {
            D_800F5B98[dest] = 0;
        } else if (D_800F5BE8.combo_cards[1] != 0) {
            D_800F5B98[dest] = 1;
        } else {
            D_800F5B98[dest] = 2;
        }
    } else {
        D_800F5B98[dest] = 3;
    }
}
