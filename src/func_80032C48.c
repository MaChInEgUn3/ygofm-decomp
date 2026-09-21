/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/card_list_sort.c, profile gcc_2_8_1_g8_split.
 * The declarations above the function are the subset of that tree's headers
 * this unit needs, preprocessed and with symbols renamed to this tree's
 * spelling (func_ADDR, D_ADDR); their types are that tree's. Byte-identical
 * under the flag row in tools_src/build.py. */
#include "kg_types.h"
#include "kg_variables.h"
#include "kg_functions.h"
extern void func_8008E400(void *, size_t, size_t, int (*)());
void func_80031E04(CardList *list, s32 count);
s32 func_80032B60(
    CardListSortItem *left,
    CardListSortItem *right
);
s32 func_80032BD4(CardListSortItem *left, CardListSortItem *right);
void func_80032C48(CardList *list);
s32 func_800358FC(s32 divisor);
extern s32 D_801D4244[];
extern BuildDeckTransitionState *D_8009B2FC;
s32 func_80032B60(
    CardListSortItem *arg0,
    CardListSortItem *arg1
);
s32 func_80032BD4(
    CardListSortItem *arg0,
    CardListSortItem *arg1
);
void func_80032C48(CardList *list)
{
    CardListSortItem *row;
    s32 i;
    s32 n;

    n = list->sort_row_count;
    row = (CardListSortItem *)list;
    switch (list->sort_mode) {
    case 1:
        if (list->kind != 0) {
            for (i = 0; i < n; i++, row++) {
                row->key = 0xFFFF;
                if (row->field_0D != 0) {
                    row->key = row->card_id;
                }
            }
        } else {
            for (i = 0; i < n; row++, i++) {
                row->key = row->card_id;
            }
        }
        func_8008E400(list, n, sizeof(CardListSortItem), func_80032BD4);
        break;
    case 2:
        for (i = 0; i < n; row++, i++) {
            row->key = -1;
            if (row->field_0D != 0) {
                row->key = 0;
            }
        }
        func_8008E400(list, n, sizeof(CardListSortItem), func_80032BD4);
        break;
    case 3:
        for (i = 0; i < n; row++, i++) {
            row->key = 0;
            if (row->field_0D != 0) {
                if ((D_801D4244[row->card_id - 1] & 0x1FF ) * 10  >=
                    ((D_801D4244[row->card_id - 1] >> 9 ) & 0x1FF ) *
                        10 ) {
                    row->key =
                        (((D_801D4244[row->card_id - 1] & 0x1FF ) * (10  / 2))
                         << 17) |
                        ((((D_801D4244[row->card_id - 1] >> 9 ) &
                           0x1FF ) *
                          (10  / 2))
                         << 3) |
                        1;
                } else {
                    row->key =
                        ((((D_801D4244[row->card_id - 1] >> 9 ) &
                           0x1FF ) *
                          (10  / 2))
                         << 17) |
                        (((D_801D4244[row->card_id - 1] & 0x1FF ) * (10  / 2))
                         << 3) |
                        1;
                }
            }
        }
        func_8008E400(list, n, sizeof(CardListSortItem), func_80032B60);
        break;
    case 4:
        for (i = 0; i < n; row++, i++) {
            row->key = 0;
            if (row->field_0D != 0) {
                row->key =
                    (((D_801D4244[row->card_id - 1] & 0x1FF ) * (10  / 2))
                     << 17) |
                    ((((D_801D4244[row->card_id - 1] >> 9 ) & 0x1FF ) *
                      (10  / 2))
                     << 3) |
                    1;
            }
        }
        func_8008E400(list, n, sizeof(CardListSortItem), func_80032B60);
        break;
    case 5:
        for (i = 0; i < n; row++, i++) {
            row->key = 0;
            if (row->field_0D != 0) {
                row->key =
                    ((((D_801D4244[row->card_id - 1] >> 9 ) & 0x1FF ) *
                      (10  / 2))
                     << 17) |
                    (((D_801D4244[row->card_id - 1] & 0x1FF ) * (10  / 2))
                     << 3) |
                    1;
            }
        }
        func_8008E400(list, n, sizeof(CardListSortItem), func_80032B60);
        break;
    case 6:
        for (i = 0; i < n; row++, i++) {
            row->key = -1;
            if (row->field_0D != 0) {
                row->key = (D_801D4244[row->card_id - 1] >>
                            26 ) & 0x1F ;
            }
        }
        func_8008E400(list, n, sizeof(CardListSortItem), func_80032BD4);
        break;
    case 8:
        for (i = 0; i < n; row++, i++) {
            row->key = -1;
            if (row->field_0D != 0) {
                row->key = 0x100;
                if (D_8009B2FC->card_sort_rank[row->card_id] != 0) {
                    row->key = D_8009B2FC->card_sort_rank[row->card_id];
                }
            }
        }
        func_8008E400(list, n, sizeof(CardListSortItem), func_80032BD4);
        break;
    case 9:
        n = list->row_count;
        for (i = 0; i < n; row++, i++) {
            row->key = -1;
            if (row->field_0D != 0) {
                row->key = func_800358FC(0x1000);
            }
        }
        func_8008E400(list, n, sizeof(CardListSortItem), func_80032BD4);
        break;
    }
    func_80031E04(list, 8);
}
