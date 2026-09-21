/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/card_list_sort.c, profile gcc_2_8_1_g8_split.
 * The declarations above the function are the subset of that tree's headers
 * this unit needs, preprocessed and with symbols renamed to this tree's
 * spelling (func_ADDR, D_ADDR); their types are that tree's. Byte-identical
 * under the flag row in tools_src/build.py. */
typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
typedef unsigned int size_t;
extern void func_8008E400(void *, size_t, size_t, int (*)());
typedef struct {
    u8 pad_00[4];
    u16 id;
    u8 pad_06[7];
    u8 flags;
    u8 pad_0E[2];
} CardEntry;
typedef struct CardList {
    CardEntry entries[(722  + 1) ];
    u8 pad_2D30[4];
     





    struct DisplayObject *cursor_box;
    struct DisplayObject *scroll_box;
    s16 first;
     



    s16 first_target;
     














    s16 row_count;
    s16 sort_row_count;
    u8 pad_2D44;
     


    u8 sort_mode;
     

    s8 sort_choice;
    u8 kind;
     




    s8 cursor;
} CardList;
void func_80031E04(CardList *list, s32 count);
typedef struct {
    u32 key;
    s16 card_id;
    u8 pad_06[7];
    u8 field_0D;
    u8 pad_0E[2];
} CardListSortItem;
s32 func_80032B60(
    CardListSortItem *left,
    CardListSortItem *right
);
s32 func_80032BD4(CardListSortItem *left, CardListSortItem *right);
void func_80032C48(CardList *list);
s32 func_800358FC(s32 divisor);
extern s32 D_801D4244[];
typedef struct BuildDeckTransitionState {
    u16 *deck_cards;
    CardList lists[2];
    s32 chest_total;
    s32 deck_total;
    s32 viewport_target_x;
    s32 viewport_step_x;
    s32 transition_ticks;
    u8 pad_5AB0[0x14];
    u8 deck_card_quantities[(722  + 1) ];
    u8 chest_card_quantities[(722  + 1) ];
    u8 card_sort_rank[(722  + 1)  + 1];
    u16 state;
    u16 next_state;
    u8 pane_index;
    u8 pad_6343;
} BuildDeckTransitionState;
extern BuildDeckTransitionState *D_8009B2FC;
s32 func_80032B60(
    CardListSortItem *arg0,
    CardListSortItem *arg1
);
s32 func_80032BD4(
    CardListSortItem *arg0,
    CardListSortItem *arg1
);
typedef void (*DisplayObjectCallback)(u8 *);
typedef struct DisplayObject {
    s16 previous;                   
    s16 next;                       
    u32 attribute;                  
    u16 flags;                      
    u8 field_0A;                    
    u8 field_0B;                    
    u32 field_0C;                   
    u32 field_10;                   
     









    u16 field_14;                   
    s8 field_16;                    
     









    u8 ot_index;                    
    u16 field_18;                   
    u16 field_1A;                   
    u16 field_1C;                   
    s16 field_1E;                   
     



     




    union {
        u32 word;
        struct {
            u16 field_20;
            u8 field_22;
            u8 field_23;
        } h;
        struct {
            u8 field_20;
            u8 field_21;
            u8 field_22;
            u8 field_23;
        } b;
    } field_20;                     
    DisplayObjectCallback update;   
     



    union {
        struct {
            u16 field_28;
            u16 field_2A;
        } h;
        s32 word;
    } position;                     
     













    union {
        u32 word;
        struct {
            u16 field_2C;
            s16 field_2E;
        } h;
    } field_2C;                     
    union {
        struct {
            u16 field_30;
            u16 field_32;
        } h;
        s32 word;
    } field_30;                     
     











    union {
        u32 word;
        struct {
            s16 field_34;
            s16 field_36;
        } h;
    } field_34;                     
     






























    union {
        u32 word;
        struct {
            s16 field_38;
            s16 field_3A;
        } h;
    } field_38;                     
     

    union {
        s32 word;
        struct {
            u16 field_3C;
            u16 field_3E;
        } h;
    } field_3C;                     
     






    union {
        u32 word;
        struct {
            s16 field_40;
            s16 field_42;
        } h;
    } field_40;                     
     


























    union {
        u32 word;
        struct {
            s16 field_44;
            s16 field_46;
        } h;
    } field_44;                     
    union {
        u32 word;
        struct {
            s16 field_48;
            s16 field_4A;
        } h;
    } field_48;                     
     



















    s32 field_4C;                   
     

















     







    union {
        s32 word;
        struct {
            s16 field_50;
            s16 field_52;
        } h;
    } field_50;                     
    void *field_54;                 
     






    s16 field_58;                   
    s16 field_5A;                   
    u16 field_5C;                   
    u16 field_5E;                   
     







    s16 field_60;                   
    u8 pad_62[2];                   
     




    u8 field_64;                    
    u8 field_65;                    
    u8 field_66;                    
     


    u8 field_67;                    
     








    u8 field_68;                    
     


    u8 field_69;                    
     


    u8 field_6A;                    
     



    u8 field_6B;                    
    u8 field_6C;                    
    u8 pad_6D[0x70  - 0x6D];
} DisplayObject;
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
