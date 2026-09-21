/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/func_80060E70.c, profile gcc_2_8_1_g8_split_no_strength_reduce.
 * The declarations above the function are the subset of that tree's headers
 * this unit needs, preprocessed and with symbols renamed to this tree's
 * spelling (func_ADDR, D_ADDR); their types are that tree's. Byte-identical
 * under the flag row in tools_src/build.py. */
#include "kg_types.h"
#include "kg_variables.h"
#include "kg_functions.h"
extern s32 D_801D4244[];
extern CardListRowSet D_801A8000[];
void func_80060E70(u16 *entries, s32 side, s32 flag, s32 ignored);
extern s16 D_8009B338 __attribute__((section(".data")));
void *func_80035BE4(
    s32 index, s32 string_id, s32 x, s32 y, s32 width, s32 height
);
void func_80039A14(struct DuelEffectChannel *object);
extern TextStagingValues D_801D5608[];
void func_80060E70(u16 *e, s32 idx, s32 flag, s32 ignored)
{
    CardListRowSet *s;
    DuelEffectChannel *box;
    s32 i;
    s32 y;
    s32 style;
    s32 base;
    s32 id;
    u16 *q;
    CardListRowSet *w;
    TextStagingValues *dst;

    s = &D_801A8000[idx];
    base = 0x18;
    s->enabled = flag;
    s->object->field_68 = flag;
    if (flag != 0) {
        base = 0x1A;
    }
    i = 0;
    dst = D_801D5608;
    w = s;
    y = 0;
    q = e + 1;
    for (i = 0; i < 7; i++) {
        w->card_entries[0] = e[0];
        style = e[0];
        if (style != 0) {
            id = style;
            style = base;
            if (((D_801D4244[id - 1] >> 26 ) &
                 0x1F ) >= 20 ) {
                style = base + 1;
            }
            do {
                D_801D5608[0].card.card_id = id;
                dst->card.count = q[0];
                D_8009B338 = id;
            } while (0);
        }
        box = func_80035BE4(idx + 1, style, s->x, s->y, 0x120, 0xB0);
        box->field_3A = y;
        if (q[0] == 0) {
            box->field_54 = 4;
            w->card_entries[0] |= 0x8000;
        }
        if (i != 0) {
            box->flags_34 |= 0x40;
        }
        func_80039A14(box);
        q += 2;
        e += 2;
        w = (CardListRowSet *)((u8 *)w + 2);
        y += 0x16;
    }
}
