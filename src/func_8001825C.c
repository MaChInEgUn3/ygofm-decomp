/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/duel_phase_entry.c (DuelScene_UpdateResume), profile gcc_2_8_1_g8_split.
 * The declarations above the function are the subset of that tree's headers
 * this unit needs, preprocessed and with symbols renamed to this tree's
 * spelling (func_ADDR, D_ADDR); their types are that tree's. Byte-identical
 * under the flag row in tools_src/build.py. */
#include "kg_types.h"
#include "kg_variables.h"
#include "kg_functions.h"
extern u8 D_800907D8[];
extern DuelCardRecord D_801A7AD8[];
extern DuelCardRecord D_801A7B64[];
s32 func_800181EC(CardObject *object);
u8 *func_8002C604(s32 id);
DuelEffectRequest *func_8002C68C(s32 id);
void func_80024954(DuelCardRecord *object);
void func_80024D34(s32 slot, s32 card_id);
extern u8 D_8015C424[];
extern u8 D_8009B1D5;
extern DuelSideState *D_8009B1C8;
extern DuelFieldEffectObject
    *D_8009B1F0[2 ];
extern u16 D_8009B36A __attribute__((section(".data")));
extern s8 D_8009B208[8];
void func_8001825C(void);
extern s8 D_8009B1B9;
void func_8001352C(void);
void func_8001352C(void);
extern FadeTransitionState D_800E9EC8;
void func_800157DC(void);
extern u32 D_8009B134_abs __attribute__((section(".data")));
void func_8003FF08(u32);
void func_8003FEE0(u32);
void func_80018080(DuelCardDisplayObject *object);
void func_8001825C(void)
{
    DuelCardRecord *rec;
    DuelEffectRequest *obj;
    u8 *b;
    DisplayObject *card;
    s32 i;
    s32 keep;
    s32 y;
    u16 flags;
    s8 n;

    if ((D_8009B23A & 0x8000 ) == 0) {
        D_8009B23A |= 0x8000 ;
        rec = D_801A7B64;
        for (i = 5 ; i < 15 ; i++, rec++) {
            flags = rec->flags;
            if (flags & 0x8000 ) {
                keep = flags & 0x7A00;
                y = rec->stat_modifier;
                func_80024D34(i, ((s8 *)rec->data)[2]);
                rec->flags |= keep;
                rec->stat_modifier = y;
                func_80018080(
                    ((DuelCardDisplayObject *)( rec->object )) );
            }
        }
        rec = D_801A7B64 + 15;
        for (i = 20; i < 30 ; i++, rec++) {
            flags = rec->flags;
            if (flags & 0x8000 ) {
                keep = flags & 0x7A00;
                y = rec->stat_modifier;
                func_80024D34(i, ((s8 *)rec->data)[2]);
                rec->flags |= keep;
                rec->stat_modifier = y;
                func_80018080(
                    ((DuelCardDisplayObject *)( rec->object )) );
            }
        }
        func_8001352C();
        for (i = 0; i < 2 ; i++) {
            if (D_800E9FF0[i].swords_turns_remaining != 0) {
                obj = (DuelEffectRequest *)func_8002C604(0x15);
                obj->field_1A = i + 2;
                obj->flags |= 0x20 ;
                D_8009B1F0[i] =
                    (DuelFieldEffectObject *)obj;
            }
        }
        if (D_8009B1C8->rank.result_adjustment ==
            40 ) {
            D_8009B23A |= 0x2000;
            for (i = 0; i < 10 ; i++) {
                rec = &D_801A7AD8[D_800907D8[
                    i + D_8009B1D5 * 20 ]];
                if (rec->flags & 0x8000 ) {
                    func_80024954(rec);
                }
            }
        } else {
            if (D_800E9FF0[0].life_points.signed_value != 0 &&
                D_800E9FF0[1].life_points.signed_value != 0) {
                func_8003FF08(D_8009B36A);
            }
        }
        func_800157DC();
        return;
    }

    if ((D_8009B23A & 0x4000) == 0) {
        if (((D_8009B0F4_abs & 0x02000030 ) |
             D_8009B134_abs) != 0) {
            return;
        }
        if ((D_800E9EC8.flags & 0x80 ) != 0) {
            return;
        }
        D_8009B23A |= 0x4000;
        D_8009B1B9 = 2;
        if ((D_8009B23A & 0x2000) != 0) {
            D_8009B23A = 0xC;
        }
        return;
    }

    for (;;) {
        n = D_8009B1B9 - 1;
        D_8009B1B9 = n;
        if (n < 0) {
            D_8009B23A = 5;
            return;
        }
        if (D_8009B208[n] >= 0) {
            break;
        }
    }
    {
        s32 replay_offset = 0x48000 ;
        DuelCardReplayRecordBlock *replay;

        b = D_8015C424;
        replay = (DuelCardReplayRecordBlock *)(
            (u8 *)&((DuelCardRecord *)b)[D_8009B208[n]] + replay_offset);
        card = replay->record.object;
    }
    func_8001352C();
    obj = func_8002C68C(0xB);
    obj->field_00 = card->field_30.h.field_30;
    obj->field_02 = card->field_30.h.field_32;
    obj->field_04 = *(u16 *)&card->field_34;
    obj->field_1A = func_800181EC((CardObject *)card);
    func_80024954(&D_801A7AD8[card->field_6A]);
    func_8003FEE0(0x1F);
}
