/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/func_800323F8.c, profile gcc_2_8_1_g8_split_no_strength_reduce.
 * The declarations above the function are the subset of that tree's headers
 * this unit needs, preprocessed and with symbols renamed to this tree's
 * spelling (func_ADDR, D_ADDR); their types are that tree's. Byte-identical
 * under the flag row in tools_src/build.py. */
#include "kg_types.h"
#include "kg_variables.h"
#include "kg_functions.h"
void func_800323F8(u8 *base, void *deck, s32 other, s32 flags)
{
    u8 *state;
    u8 *lists;
    u8 *object;
    u8 *label;
    u8 *deck_list;
    u8 *chest_list;
    u8 *entry;
    u8 *quantity;
    u8 *counts;
    u8 *icon;
    u16 *drops;
    u16 *cards;
    u16 *drop;
    u8 *rank;
    u8 *rank_row;
    s32 *all_stats;
    s32 icons;
    s32 rows;
    s32 *stats;
    s32 pane;
    s32 j;
    s32 icon_addr;
    s32 id;
    s32 on;
    s32 held;
    s32 deck_total;
    s32 n;
    s32 v;

    func_80032328();
    func_8003FF08(0x70E0);
    D_8009B148 = 0;
    D_8009B146 = 0;
    state = base;
    func_80032370();
    pane = 0;
    on = 1;
    icons = (s32)D_80090DD8;
    all_stats = D_801D4244;
    lists = state + 4;
    D_8009B2FC = ((BuildDeckTransitionState *)( state )) ;
    state[0x6343] = flags;
    *(void **)state = deck;
    *(s32 *)(state + 0x6344) = other;
    ((BuildDeckTransitionState *)( state )) ->pane_index = 0;
    state[0xC686] = 0;
    do {
        if (*(s32 *)state != 0) {
            drops = (u16 *)D_801D07BC;
            lists[0x6066] = 0;
            j = 1;
            rank = state + j;
            do {
                rank[0x606A] = 0;
                n = 15;
                rank_row = rank;
                drop = drops + 15;
                do {
                    if ((s16)*drop == j) {
                        rank_row[0x606A] = n + 1;
                    }
                    n--;
                    drop--;
                } while (n >= 0);
                j++;
                rank++;
            } while (j < 0x2D3);
            deck_list = state + 0x2D50;
            deck_total = 0;
            ((CardList *)( lists )) [1].kind = on;
            j = deck_total;
            ((CardList *)( lists )) [1].first_target = 0;
            ((CardList *)( lists )) [1].first = 0;
            ((CardList *)( lists )) [1].cursor = 0;
            ((CardList *)( lists )) [1].sort_choice = 0;
            icon = (u8 *)(((CardList *)( lists )) [1].kind * 16 + icons);
            ((CardList *)( lists )) [1].sort_mode = icon[1] & 0xF;
            entry = state + 0x2D58;
            cards = *(u16 **)state;
            for (; j < 0x28; j++, entry += 0x10, cards++) {
                entry[5] = 0;
                *(s16 *)(entry - 4) = 0;
                v = *cards;
                if (v != 0) {
                    *(s16 *)(entry - 4) = v;
                    v--;
                    v *= 4;
                    v += (s32)all_stats;
                    entry[5] = on;
                    entry[2] = ((*(s32 *)( v ))  >> 26) & 0x1F;
                    *(s16 *)(entry - 2) = ((*(s32 *)( v ))  & 0x1FF) * 10;
                    deck_total++;
                    *(s16 *)entry =
                        (((*(s32 *)( v ))  >> 9) & 0x1FF) * 10;
                }
            }
            *(s16 *)(deck_list + 0x284) = -1;
            *(s32 *)(lists + 0x5A9C) = deck_total;
            ((CardList *)( lists )) [1].row_count = 0x28;
            ((CardList *)( lists )) [1].sort_row_count = 0x28;
            func_80032C48(((CardList *)( state + 0x2D50 )) );
            func_8003201C(((BuildDeckTransitionState *)( state )) );
            chest_list = lists;
            n = 0;
            j = n;
            held = 0x80;
            ((CardList *)( lists )) ->kind = 0;
            ((CardList *)( lists )) ->first_target = 0;
            ((CardList *)( lists )) ->first = 0;
            ((CardList *)( lists )) ->row_count = 0x2D2;
            ((CardList *)( lists )) ->cursor = 0;
            ((CardList *)( lists )) ->sort_choice = 0;
            icon_addr = ((CardList *)( lists )) ->kind * 16;
            icon_addr += icons;
            ((CardList *)( lists )) ->sort_mode = ((u8 *)icon_addr)[1] & 0xF;
            entry = lists + 0xD;
            stats = all_stats;
            quantity = *(u8 **)state + 0x50;
            for (; j < 0x2D2; stats++, j++, entry += 0x10, quantity++) {
                id = j + 1;
                entry[0] = 0;
                *(s16 *)(entry - 9) = id;
                entry[-3] = (*stats >> 26) & 0x1F;
                *(s16 *)(entry - 7) = (*stats & 0x1FF) * 10;
                *(s16 *)(entry - 5) = ((*stats >> 9) & 0x1FF) * 10;
                v = (s32)state + id;
                counts = (u8 *)v;
                counts[0x5D97] = *quantity;
                if (*quantity != 0) {
                    entry[0] = on;
                    n += *quantity;
                } else if (counts[0x5AC4] != 0) {
                    entry[0] = held;
                }
            }
            *(s16 *)(chest_list + 0x2D24) = 0;
            *(s32 *)(lists + 0x5A98) = n;
            rows = 0x2D2;
            ((CardList *)( lists )) ->sort_row_count = rows;
            ((CardList *)( lists )) ->row_count = rows;
            func_80032C48(((CardList *)( lists )) );
        }
        pane++;
        lists += 0x6344;
        state += 0x6344;
    } while (pane < 2);

    state = (u8 *)D_8009B2FC;
    object = func_800400AC(func_8004002C(), 2);
    func_800404CC(object, 0, 0, 0, 4, 0, 0xC, 0x208);
    label = func_800400AC(func_8004002C(), 6);
    label[0x67] = 0;
    *(s32 *)(label + 0x30) = *(s32 *)(object + 0x30);
    *(s32 *)(label + 0x4C) = (s32)func_80031874;
    object = func_800400AC(func_8004002C(), 2);
    func_800404CC(object, 0x140, 0, 0, 4, 1, 0xC, 0x208);
    label = func_800400AC(func_8004002C(), 6);
    label[0x67] = 1;
    *(s32 *)(label + 0x30) = *(s32 *)(object + 0x30);
    *(s32 *)(label + 0x4C) = (s32)func_80031874;
    ((BuildDeckTransitionState *)( state )) ->state = 2;
    object = func_800400AC(func_8004002C(), 2);
    func_800404CC(object, 0x136, 0x29, 0, 4, 0xC, 0xC, 0x208);
    *(u16 *)(object + 8) |= 0x20;
    func_800428EC(((DisplayObject *)( object )) , 8);
    *(u8 **)(state + 0x2D3C) = object;
    object = func_800400AC(func_8004002C(), 2);
    func_800404CC(object, 0x26A, 0x29, 0, 4, 0xC, 0xC, 0x208);
    *(u16 *)(object + 8) |= 0x20;
    func_800428EC(((DisplayObject *)( object )) , 8);
    *(u8 **)(state + 0x5A88) = object;
    object = func_800400AC(func_8004002C(), 2);
    func_800404CC(object, 0, 0x2A, 0, 4, 2, 0xC, 0x208);
    *(u16 *)(object + 8) |= 0x20;
    func_800428EC(((DisplayObject *)( object )) , 0xA);
    *(u8 **)(state + 0x2D38) = object;
    object = func_800400AC(func_8004002C(), 2);
    func_800404CC(object, 0x148, 0x2A, 0, 4, 3, 0xC, 0x218);
    *(u16 *)(object + 8) |= 0x20;
    func_800428EC(((DisplayObject *)( object )) , 0xA);
    *(u8 **)(state + 0x5A84) = object;
    object = func_800400AC(func_8004002C(), 2);
    func_800404CC(object, 0, 0, 0, 4, 9, 0xC, 0x208);
    *(u16 *)(object + 8) |= 0x20;
    func_800428EC(((DisplayObject *)( object )) , 0xA);
    object = func_800400AC(func_8004002C(), 2);
    func_800404CC(object, 0x140, 0, 0, 4, 0xA, 0xC, 0x208);
    *(u16 *)(object + 8) |= 0x20;
    func_800428EC(((DisplayObject *)( object )) , 0xA);
    object = func_800400AC(func_8004002C(), 2);
    func_800404CC(object, 0, 0, 0, 4, 0xB, 0xC, 0x208);
    *(u16 *)(object + 8) |= 0x20;
    func_800428EC(((DisplayObject *)( object )) , -4);
    object = func_800400AC(func_8004002C(), 2);
    func_800404CC(object, 0x140, 0, 0, 4, 0xB, 0xC, 0x208);
    *(u16 *)(object + 8) |= 0x20;
    func_800428EC(((DisplayObject *)( object )) , -4);
    object = func_800400AC(func_8004002C(), 2);
    func_800404CC(object, 0x140, 0, 3, 0, 3, 0xB, 0x2F8);
    func_800428EC(((DisplayObject *)( object )) , -4);
    func_80031E5C(((BuildDeckTransitionState *)( state )) );
}
