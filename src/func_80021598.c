/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/duel_result_runtime.c (Duel_CalcRankScore), profile gcc_2_8_1_g8_split.
 * The declarations above the function are the subset of that tree's headers
 * this unit needs, preprocessed and with symbols renamed to this tree's
 * spelling (func_ADDR, D_ADDR); their types are that tree's. Byte-identical
 * under the flag row in tools_src/build.py. */
#include "kg_types.h"
extern DuelSideState D_800E9FF0[2 ];
extern u8 D_8009B165;
s32 func_80021558(s32 rule, s32 value);
extern DuelResultDisplayState *D_8009B1E8;
void func_80021598(void);
extern TextStagingValues D_801D5608[];
s32 func_80021558(s32 arg0, s32 arg1);
void func_80021598(void) {
    DuelResultDisplayState *p;
    DuelSideState *e;
    s32 i;
    s32 v;
    s32 *q;

    p = D_8009B1E8;
    e = D_800E9FF0;
    q = &D_801D5608[0].rank_rows[0][0];
    p->page_text_ids[0] = 0x44;
    p->page_text_ids[1] = 0x40 ;
    p->page_text_ids[2] = 0x45;
    if (D_800E9FF0[D_8009B165].rank.result_adjustment ==
        40 ) {
        p->page_text_ids[1] = 0x42 ;
    }
    if (D_800E9FF0[D_8009B165].rank.result_adjustment ==
        (-40) ) {
        p->page_text_ids[1] = 0x41 ;
    }

    p->side_scores[1] = 50 ;
    p->side_scores[0] = 50 ;
    for (i = 0; i < 2 ; i++, e++, q++) {
        p->side_scores[i] += e->rank.result_adjustment;
        v = e->deck_draw_cursor; q[0 * 2 ] = v;
        p->side_scores[i] +=
            func_80021558(6 , v);
        v = e->life_points.signed_value; q[1 * 2 ] = v;
        p->side_scores[i] +=
            func_80021558(7 , v);
        q[2 * 2 ] = e->field_0E;
        q[3 * 2 ] = e->rank.field_0B;
        v = e->rank.effective_attacks; q[4 * 2 ] = v;
        p->side_scores[i] +=
            func_80021558(1 , v);
        q[5 * 2 ] = e->field_10;
        q[6 * 2 ] = e->rank.field_0C;
        v = e->rank.defensive_wins; q[7 * 2 ] = v;
        p->side_scores[i] +=
            func_80021558(2 , v);
        q[8 * 2 ] = e->rank.field_07;
        v = e->rank.face_down_plays; q[9 * 2 ] = v;
        p->side_scores[i] +=
            func_80021558(3 , v);
        v = e->rank.fusions_initiated; q[10 * 2 ] = v;
        p->side_scores[i] +=
            func_80021558(8 , v);
        v = e->rank.equips_used; q[11 * 2 ] = v;
        p->side_scores[i] +=
            func_80021558(9 , v);
        q[12 * 2 ] = e->rank.field_0A;
        v = e->rank.pure_magic_used; q[13 * 2 ] = v;
        p->side_scores[i] +=
            func_80021558(4 , v);
        v = e->rank.traps_triggered; q[14 * 2 ] = v;
        p->side_scores[i] +=
            func_80021558(5 , v);
        v = e->rank.turns_taken; q[15 * 2 ] = v;
        p->side_scores[i] +=
            func_80021558(0 , v);
    }
}
