/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/func_80031874.c, profile gcc_2_8_1_g8_split_no_strength_reduce.
 * The declarations above the function are the subset of that tree's headers
 * this unit needs, preprocessed and with symbols renamed to this tree's
 * spelling (func_ADDR, D_ADDR); their types are that tree's. Byte-identical
 * under the flag row in tools_src/build.py. */
#include "kg_types.h"
#include "kg_variables.h"
#include "kg_functions.h"
void func_80031874(DisplayObject *obj, GsOT *ot)
{
    u8 *text;
    GsSPRITE *sprite = (GsSPRITE *)0x1F800020;
    GsSPRITE *header = (GsSPRITE *)0x1F800060;
    CardList *list;
    u8 *row;
    s32 kind;
    s32 x0;
    s32 x;
    s32 vy;
    s32 y0;
    s32 y;
    s32 i;
    s32 ry;
    s32 id;
    s32 n;
    u32 attr;

    x0 = (s16)obj->field_30.h.field_30;
    y0 = (s16)obj->field_30.h.field_32;
    attr = obj->attribute;
    header->tpage = 0xB;
    sprite->tpage = 0xB;
    (*(u32 *)&( sprite )->r)  = 0x808080 ;
    *(u32 *)&sprite->w = 0x80008;
    *(u32 *)&header->w = 0x100010;
    sprite->cx = 0x290;
    sprite->cy = 0xFA;
    vy = D_8009B148;
    x = x0 - D_8009B146;
    header->attribute = attr;
    sprite->attribute = attr;
    kind = obj->field_67;
    y = y0 - vy;
    do {
    } while (0);
    list = &D_8009B2FC->lists[kind];
    row = (u8 *)&list->entries[list->first];
    text = (u8 *)0x1F800000;
    if (kind == 0) {
        header->x = x + 0x88;
        header->y = y + 0xF;
        func_80031784(header, ot, D_80090DD8, list->sort_mode);
    } else {
        header->x = x + 0x6A;
        header->y = y + 0xF;
        func_80031784(header, ot, &D_80090DD8[kind * 16],
                      list->sort_mode);
    }
    i = 0;
    ry = 0x2B;
    row += 8;
    do {
        sprite->x = x + 4;
        sprite->y = ry;
        if (row[5] != 0) {
            (*(u32 *)&( sprite )->r)  = 0x808080 ;
            id = *(s16 *)(row - 4);
            if (row[5] & 0x80) {
                (*(u32 *)&( sprite )->r)  = 0x404040 ;
            }
            if (kind != 0) {
                sprite->x = x + 0x11;
                func_800358A0(list->first + i + 1, 2, text);
                func_800316F0(sprite, ot, text, 2);
                sprite->x += 4;
            } else if (D_8009B2FC->card_sort_rank[id] != 0) {
                sprite->v = 0x68;
                sprite->w = 0x18;
                sprite->u = 0xE8;
                sprite->y += 8;
                func_800849F0(sprite, ot, 0);
                sprite->w = 8;
                sprite->y -= 8;
            }
            func_800358A0(id, 3, text);
            func_800316F0(sprite, ot, text, 3);
            sprite->x += 0x88;
            if (row[2] < 0x14) {
                 
                *(u16 *)&sprite->u = 0x58D0;
                func_800849F0(sprite, ot, 0);
                sprite->x += 8;
                func_800357E8(*(s16 *)(row - 2), 4, text);
                func_800316F0(sprite, ot, text, 4);
                 
                *(u16 *)&sprite->u = 0x58D8;
                sprite->x -= 0x28;
                sprite->y += 8;
                func_800849F0(sprite, ot, 0);
                sprite->x += 8;
                func_800357E8(*(s16 *)row, 4, text);
                func_800316F0(sprite, ot, text, 4);
                sprite->y -= 8;
            }
            if (kind == 0) {
                sprite->x = x + 0x107;
                sprite->y += 8;
                func_800357E8(
                    D_8009B2FC->chest_card_quantities[id], 3, text);
                func_800316F0(sprite, ot, text, 3);
                n = D_8009B2FC->deck_card_quantities[id];
                 

                if (n >= 3 || ((u32)(id - 0x11) < 5 && n != 0)) {
                    (*(u32 *)&( sprite )->r)  = 0x2020FF;
                }
                sprite->x = x + 0x122;
                func_800357E8(n, 2, text);
                func_800316F0(sprite, ot, text, 2);
                (*(u32 *)&( sprite )->r)  = 0x808080 ;
                sprite->y -= 8;
            }
        }
        row += sizeof(CardEntry);
        i++;
        ry += 0x16;
    } while (i < 8);
}
