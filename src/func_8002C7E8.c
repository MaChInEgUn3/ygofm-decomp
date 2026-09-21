/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/duel_check_ritual.c (Duel_CheckRitual), profile gcc_2_8_1_g8_split.
 * The declarations above the function are the subset of that tree's headers
 * this unit needs, preprocessed and with symbols renamed to this tree's
 * spelling (func_ADDR, D_ADDR); their types are that tree's. Byte-identical
 * under the flag row in tools_src/build.py. */
#include "kg_types.h"
#include "kg_variables.h"
#include "kg_functions.h"
extern u16 D_801799D8[];
s32 func_8002C7E8(DuelRitualResult *out, s32 ritual_id);
extern u8 D_8009B1D5 __attribute__((section(".data")));
extern DuelCardRecord D_801A7AD8[];
s32 func_8002C7E8(DuelRitualResult *out, s32 ritualId)
{
    DuelCardRecord *found[3 ];
    DuelCardRecord *cands[5 ];
    DuelCardRecord *card;
    DuelCardRecord **first;
    DuelCardRecord **dst;
    DuelCardRecord **w;
    DuelCardRecord *c;
    u16 *p;
    u16 *q;
    s32 i;
    s32 j;

    p = D_801799D8;
    while (1) {
        if (p[0] == 0) {
            return 0;
        }
        if (p[0] == ritualId) {
            break;
        }
        p += (3  + 2) ;
    }

    i = 5 ;
    if (D_8009B1D5 != 0) {
        i = 15  + 5 ;
    }
    c = &D_801A7AD8[i];
    i = 0;
    w = cands;
    for (i = 0; i < 5 ; i++) {
        *w = 0;
        if (c->flags & 0x8000 ) {
            *w = c;
        }
        w++;
        c++;
    }

    p++;
    j = 0;
    first = cands;
    dst = found;
    q = p;
    for (j = 0; j < 3 ; j++) {
        for (i = 0; i < 5 ; i++) {
            card = (c = first[i]);
            if (card != 0 && card->card_id == q[0]) {
                goto matched;
            }
        }
        return 0;
matched:
        *dst++ = card;
        first[i] = 0;
        q++;
    }

    if (out != 0) {
        for (i = 0; i < 3 ; i++) {
            out->tribute_objects[i] = found[i]->object;
        }
        out->field_0C = 0;
    }
    return p[3 ];
}
