/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/duel_card_record_lifecycle.c (Duel_PopulateCombinedDeckData), profile gcc_2_8_1_g8_split.
 * The declarations above the function are the subset of that tree's headers
 * this unit needs, preprocessed and with symbols renamed to this tree's
 * spelling (func_ADDR, D_ADDR); their types are that tree's. Byte-identical
 * under the flag row in tools_src/build.py. */
#include "kg_types.h"
#include "kg_variables.h"
#include "kg_functions.h"
void func_80024824(void)
{
    u8 *dst = D_8018C2D8;
    DuelDeckCardRecord *rec = D_801A7E20;
    u8 *q;
    u8 *src;
    u8 *r;
    u16 *p;
    s32 i;
    s32 id;
    s32 w;
    u16 v;

    for (i = 0; i < (40  * 2) ; i++) {
        q = (u8 *)&((u16 *)D_8015C424)[i];
        v = *(u16 *)(q + 0x1BBC4 );
        rec->id = v;
        id = (s16)v;
        r = D_8015C424 + i;
        rec->flags_04 = r[0x1BB70 ];
        rec->deck_index = i;
        rec->data_block_index = i;

        src = D_8015C424;
        p = D_80178130;
    search:
        w = *p;
        p++;
        if (w != id) {
            src += 0x580 ;
            goto search;
        }
        func_800356A0(dst, src, 0x580 );
        dst += 0x580 ;
        rec++;
    }
}
