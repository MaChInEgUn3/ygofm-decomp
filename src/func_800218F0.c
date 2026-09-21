/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/func_800218F0.c (DuelScene_UpdateResultRewards), profile gcc_2_8_1_g8_split.
 * The declarations above the function are the subset of that tree's headers
 * this unit needs, preprocessed and with symbols renamed to this tree's
 * spelling (func_ADDR, D_ADDR); their types are that tree's. Byte-identical
 * under the flag row in tools_src/build.py. */
#include "kg_types.h"
#include "kg_variables.h"
#include "kg_functions.h"
extern SaveDataState *D_8009B1D8[2];
extern DuelResultDisplayState D_801799D8;
extern u16 D_8009B16C;
extern s16 D_8009B338 __attribute__((section(".data")));
extern u16 D_8009B398 __attribute__((section(".data")));
extern u16 D_8009B394 __attribute__((section(".data")));
void func_800218F0(void)
{
    DisplayObject *object;
    s32 score;
    s32 sound;
    s32 count;
    s32 offset;
    s32 x;
    s16 dropped_card;
    u16 value;
    s8 page;
    u8 opponent;

    D_800F2848.angle = (u16)D_800F2848.angle + 2;
    func_8001352C();
    if (!(D_8009B23A & 0x8000)) {
        D_8009B23A |= 0x8000;
        func_80015C84();
        func_80015BD8(128, 2);
        D_8009B1E8 = &D_801799D8;
        D_8009B148 = 0;
        D_8009B146 = 0;
        D_8009B34E = 0;
        D_8009B355 = 0;
        D_801D5708[0] = 4;
        D_801D5708[1] = 4;
        D_801D5708[D_8009B165] = 0;
        sound = 0x72E1;
        if (D_8009B165) {
            sound = 0x72F1;
            opponent = (u8)D_8009B361;
            D_8009B355 = 1;
            D_8009B32E = (s8)opponent - 31960;
        }
        func_8003FF08(sound);
        if (D_8009B360[0] < 0 && D_8009B361 < 0) {
            D_8009B34E = 1;
            D_8009B355 += 2;
        }
        D_8009B1E8->is_tec_rank = 0;
        func_80021598();
        score = D_8009B1E8->side_scores[D_8009B165];
        if (score < 50) {
            D_8009B1E8->is_tec_rank = 1;
            if (score < 0)
                score = 0;
            score = 99 - score;
        }
        if (score >= 100)
            score = 99;
        score -= 50;
        D_8009B1E8->rank_tier = score / 10;
        D_8009B1E8->page_index = 0;
        object = func_800400AC(func_8004002C(), 2);
        func_800404CC(object, 32, 16, 3, 1, 2, 11, 524);
        func_80042918(object);
        object->flags |= 0x28;
        object = func_800400AC(func_8004002C(), 2);
        func_800404CC(object, 288, 16, 3, 1, 0, 11, 524);
        func_80042918(object);
        count = 9;
        object->flags |= 0x28;
        object = func_800400AC(func_8004002C(), 2);
        func_800428A8(object, 0, 8, 0, 4, 0, 16, 8, D_801AF000);
        func_80042918(object);
        func_800428EC(object, -1);
        object->flags |= 0x20;
        D_8009B1E8->root = object;
        do {
            D_8009B1E8->children[count] = 0;
            count--;
        } while (count >= 0);
        D_8009B338 = 0;
        if (D_8009B360[0] < 0 && D_8009B361 >= 0) {
            if (D_8009B165)
                goto side_result;
            D_8009B1E8->starchip_prize = D_8009B1E8->rank_tier + 1;
            score = 2 * (D_8009B1E8->is_tec_rank != 0);
            if (D_8009B1E8->rank_tier < 3)
                score = 1;
            dropped_card = func_80021810(score);
            count = 0;
            D_8009B338 = dropped_card;
            D_8009B1E8->dropped_card_id = dropped_card;
            D_801D56A8[0] = dropped_card;
            offset = 8;
            if (D_8009B1E8->starchip_prize) {
                x = 160;
                do {
                    count++;
                    object = func_800400AC(func_8004002C(), 2);
                    func_800404CC(object, x, 192, 3, 4, 0, 11, 524);
                    func_80042918(object);
                    x += 20;
                    object->flags |= 0x20;
                    *(DisplayObject **)((u8 *)D_8009B1E8 + offset + 4) = object;
                    offset += 4;
                } while (count < D_8009B1E8->starchip_prize);
            }
        }
side_result:
        if (D_8009B360[D_8009B165] < 0) {
            object = func_800400AC(func_8004002C(), 2);
            func_800428A8(object, 0, 16, 0, 5, D_8009B1E8->is_tec_rank,
                16, 8, D_801AF000);
            func_80042918(object);
            func_800428EC(object, -2);
            object->flags |= 0x20;
            D_8009B1E8->children[0] = object;
            object = func_800400AC(func_8004002C(), 2);
            func_800428A8(object, 0, 16, 0, 6, D_8009B1E8->rank_tier,
                16, 8, D_801AF000);
            func_80042918(object);
            func_800428EC(object, -1);
            object->flags |= 0x20;
            D_8009B1E8->children[1] = object;
        }
        goto show_page;
    }
    if (D_8009B23A & 0x4000) {
        if (!(((FadeTransitionState *)D_800E9EC8_arr)->flags & 0x80)) {
            if (!(D_8009B23A & 0x2000)) {
                D_8009B23A |= 0x2000;
                func_80015904();
                ((FadeTransitionState *)D_800E9EC8_arr)->level = 255;
                func_800156B8(255);
            } else {
                 


                SaveDataState *save = D_8009B1D8[D_8009B165];
                D_8009B16C |= 0x2000;
                if (save) {
                    if (D_8009B360[0] < 0 && D_8009B361 >= 0) {
                        D_8009B1D8[0]->starchips +=
                            D_8009B1E8->starchip_prize;
                        if (D_8009B1D8[0]->starchips > 999999)
                            D_8009B1D8[0]->starchips = 999999;
                        func_80021894(D_8009B1E8->dropped_card_id);
                    } else {
                        value = D_8009B1D8[D_8009B165]->duel_wins + 1;
                        D_8009B1D8[D_8009B165]->duel_wins = value;
                        if (value >= 10000)
                            D_8009B1D8[D_8009B165]->duel_wins = 9999;
                        value = D_8009B1D8[D_8009B165 ^ 1]
                                    ->duel_losses + 1;
                        D_8009B1D8[D_8009B165 ^ 1]->duel_losses = value;
                        if (value >= 10000)
                            D_8009B1D8[D_8009B165 ^ 1]
                                ->duel_losses = 9999;
                    }
                }
            }
        }
    } else if (D_8009B394 & 0xA000) {
        D_8009B1E8->page_index++;
        if (D_8009B394 & 0x8000) {
            page = D_8009B1E8->page_index - 2;
            D_8009B1E8->page_index = page;
            if (page < 0)
                D_8009B1E8->page_index = 2;
        }
        if ((s8)D_8009B1E8->page_index >= 3)
            D_8009B1E8->page_index = 0;
        func_8003FEE0(6);
show_page:
        func_80021480((s8)D_8009B1E8->page_index);
    } else if (D_8009B398 & 0x40) {
        D_8009B23A |= 0x4000;
        func_80015BD8(0, 6);
        func_8003FEE0(0x30);
    }
}
