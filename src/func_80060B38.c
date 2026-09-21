/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/card_list_render_deck_box_stats.c (CardList_RenderDeckBoxStats), profile gcc_2_8_1_g0_split.
 * The declarations above the function are the subset of that tree's headers
 * this unit needs, preprocessed and with symbols renamed to this tree's
 * spelling (func_ADDR, D_ADDR); their types are that tree's. Byte-identical
 * under the flag row in tools_src/build.py. */
#include "kg_types.h"
#include "kg_variables.h"
#include "kg_functions.h"
extern CardListRowSet D_801A8000[];
void func_80060B38(DisplayObject *obj, GsOT *ot) {
    u8 atk[8];
    u8 def[8];
    GsSPRITE *sp;
    u8 *tbl;
    CardListRowSet *rec;
    u16 *entries;
    s32 pri;
    s32 i;
    s32 j;
    s32 id;
    u8 d;

    tbl = D_80090DD8;
    sp = (GsSPRITE *)0x1F800320;
    rec = &D_801A8000[obj->field_6A];
    pri = *(s16 *)&obj->field_14;
    sp->attribute = obj->attribute;
    sp->tpage = 0xB;
    (*(u32 *)&( sp )->r)  = 0x808080 ;
    *(u32 *)&sp->w = 0x100010;
    sp->x = obj->field_30.h.field_30 + 0x22;
    sp->y = obj->field_30.h.field_32 - 0x18;
    sp->cy = 0xFB;
    i = 0;
    do {
        (*(u32 *)&( sp )->r)  = 0x202020;
        if (i == obj->field_69) {
            (*(u32 *)&( sp )->r)  = 0x808080 ;
        }
        sp->u = (tbl[0] & 0xF) * 8 - 0x80;
        sp->v = tbl[0] & 0xF0;
        sp->cx = (tbl[1] & 0xF0) | 0x200;
        func_800849F0(sp, ot, pri);
        sp->x += 0x14;
        i++;
        tbl += 2;
    } while (i < 6);

    if (rec->enabled != 0) {
        sp->attribute = obj->attribute;
        sp->x = obj->field_30.h.field_30 + 0x24;
        *(u32 *)&sp->w = 0x80008;
        entries = rec->card_entries;
        sp->y = obj->field_30.h.field_32;
        sp->tpage = 0xB;
        sp->cx = 0x290;
        sp->cy = 0xFA;
        sp->u = 0x80;
        sp->v = 0x70;
        i = 0;
        do {
            id = *entries & 0xFFF;
            if (id != 0) {
                if (((D_801D4244[id - 1] >> 26 ) &
                     0x1F ) < 20 ) {
                    sp->x = obj->field_30.h.field_30 + 0x24;
                    (*(u32 *)&( sp )->r)  = 0x808080 ;
                    if (*entries & 0x8000) {
                        (*(u32 *)&( sp )->r)  = 0x404040 ;
                    }
                    func_800357E8(
                        (D_801D4244[id - 1] & 0x1FF ) *
                            10 ,
                        4, atk);
                    func_800357E8(
                        ((D_801D4244[id - 1] >> 9 ) &
                         0x1FF ) * 10 ,
                        4, def);
                    for (j = 3; j >= 0; j--) {
                        d = atk[j];
                        if (d < 10 ) {
                            sp->u = d * 8 - 0x80;
                            func_800849F0(sp, ot, pri);
                        }
                        if (def[j] < 10 ) {
                            sp->y += 8;
                            sp->u = def[j] * 8 - 0x80;
                            func_800849F0(sp, ot, pri);
                            sp->y -= 8;
                        }
                        sp->x += 8;
                    }
                }
            }
            i++;
            sp->y += 0x16;
            entries++;
        } while (i < 7);
    }
}
