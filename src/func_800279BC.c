/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/ai_turn_action.c, profile gcc_2_8_1_g8_split.
 * The declarations above the function are the subset of that tree's headers
 * this unit needs, preprocessed and with symbols renamed to this tree's
 * spelling (func_ADDR, D_ADDR); their types are that tree's. Byte-identical
 * under the flag row in tools_src/build.py. */
#include "kg_types.h"
#include "kg_variables.h"
#include "kg_functions.h"
extern u8 D_800907D8[];
extern u8 D_8009B1D5;
extern u16 D_8009B16C;
extern AiSelection D_800EAE88;
s32 func_800279BC(void)
{
    DuelCardRecord *pool[6];
    DuelCardRecord *listb[6];
    DuelCardRecord *lista[6];
    DuelCardRecord **pa;
    DuelCardRecord **pb;
    DuelCardRecord **pp;
    DuelCardRecord *ea;
    DuelCardRecord *eb;
    DuelCardRecord *rec;
    DuelCardRecord *scan;
    s32 slot;
    s32 n;
    s32 i;
    s32 mask;
    s32 res;
    s32 count;
    s32 v;
    u8 *grid;
    AiSelection *out;
    DuelCardRecord *recs;
    DuelCardRecord *scanbase;
    s32 t;

    D_800EAE88.field_09 = 0;
    if (D_8009B16C & 0x1000) {
        return 0;
    }
    if ((func_8008E590() & 3) != 0) {
        slot = 0xA;
        goto walk;
    }
    {
        func_80026D18((DuelCardRecord **)lista, 0xA, 0x17);
        func_80026D18((DuelCardRecord **)listb, 5, -1);
        ea = lista[0];
        if (ea != 0) {
            pa = lista;
            do {
                eb = listb[0];
                if (eb != 0) {
                    pb = listb;
                    do {
                        if (func_80019A08((s16)ea->card_id,
                                            (s16)eb->card_id)) {
                            goto found;
                        }
                        pb++;
                        eb = *pb;
                    } while (eb != 0);
                }
                pa++;
                ea = *pa;
            } while (ea != 0);
        }
        n = func_80026D18((DuelCardRecord **)lista, 0xA, 0x14);
        if (n == 0) {
            goto no_equip;
        }
        n--;
        if (n != 0) {
            n = func_800358FC(n + 1);
        }
        D_800EAE88.field_09 = (s8)lista[n]->table_index % 5 + 6;
        D_800EAE88.field_0A = 0;
        D_800EAE88.field_0B = 0;
        return 0;
found:
        D_800EAE88.field_09 = (s8)ea->table_index % 5 + 6;
        D_800EAE88.field_0A = (s8)eb->table_index % 5 + 1;
        D_800EAE88.field_0B = 0;
        return 0;
no_equip:
        slot = 0xA;
    }
walk:
    grid = D_800907D8;
    out = &D_800EAE88;
    recs = D_801A7AD8;
    scanbase = &D_801A7AD8[5];
loop:
    {
        do {
            n = D_8009B1D5 * 20;
            rec = (DuelCardRecord *)((s32)*(u8 *)(slot + n + (s32)grid) * 28 + (s32)recs);
             
            if ((*(u32 *)&rec->terrain_modifier & 0xC0000000) == 0x80000000) {
                v = func_800278A0((DuelSelectionSource *)rec);
                if (v >= 0) {
    have:
                    if (D_8009B1C8->swords_turns_remaining == 0) {
                        t = (s8)rec->table_index;
                        slot = t % 5 + 1;
                        out->field_0B = 0;
                        out->field_0A = v % 5 + 0x38;
                        out->field_09 = slot;
                        return 0;
                    }
                    goto none;
                }
                if ((func_8008E590() & 3) == 0) {
                    v = func_8002778C((DuelSelectionSource *)rec);
                    if (v >= 0) {
                        goto have;
                    }
    none:
                    v = (s8)rec->table_index % 15;
                    out->field_0A = 0;
                    res = (s8)v - 4;
                    out->field_0B = 1;
                    out->field_09 = res;
                    return 0;
                }
                if ((func_8008E590() & 1) != 0) {
                    count = 0;
                    i = 0;
                    scan = (DuelCardRecord *)((s32)((D_8009B1D5 ^ 1) * 15) * 28 + (s32)scanbase);
                    mask = 0x90000000;
                    pp = pool;
                    do {
                        if ((*(u32 *)&scan->terrain_modifier & mask)
                            == mask) {
                            *pp = scan;
                            pp++;
                            count++;
                        }
                        i++;
                        scan++;
                    } while (i < 5);
                    if (count != 0) {
                        v = count - 1;
                        if (v != 0) {
                            v = func_800358FC(count);
                        }
                        v = (s8)pool[v]->table_index;
                        goto have;
                    }
                }
                goto none;
            }
        } while (0);
        slot++;
    }
    if (slot < 0xF) {
        goto loop;
    }
    return 0;
}
