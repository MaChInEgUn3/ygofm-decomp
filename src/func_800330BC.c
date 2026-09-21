/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/card_list_sort.c (BuildDeck_UpdateCardListInput), profile gcc_2_8_1_g8_split.
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
void func_80032C48(CardList *list);
s32 func_800330BC(CardList *list);
void func_80032C48(CardList *list);
extern u8 D_80090DD8[];
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
extern volatile u16 D_8009B3A4 __attribute__((section(".data")));
extern volatile u16 D_8009B394 __attribute__((section(".data")));
void func_8003FEE0(u32);
s32 func_800330BC(CardList *list)
{
    s32 row;
    s32 sel;
    s32 icon;
    s32 slot;
    u8 *entry;

    row = list->first | list->cursor;
    if (row != 0) {
        row = (list->first + list->cursor + 1) * 152 /
              list->sort_row_count;
    }
    list->scroll_box->field_30.h.field_32 = row + 0x29;

top:
    if (list->first != list->first_target) {
        if (list->first_target < list->first) {
            *(u16 *)&list->first = *(u16 *)&list->first - 1;
        } else {
            *(u16 *)&list->first = *(u16 *)&list->first + 1;
        }
        func_80031E04(list, 8);
        return 1;
    }

    if ((D_8009B3A4 & (0x4  | 0x8 ) ) != 0) {
        sel = -1;
        row = list->first;
        if ((D_8009B3A4 & 0x8 ) != 0) {
            if (row == list->row_count - 8 &&
                list->cursor != 7) {
                sel = 7;
            }
            row += 8;
            if (list->row_count - 8 < row) {
                row = list->row_count - 8;
            }
        } else {
            if (row == 0 && list->cursor != 0) {
                sel = 0;
            }
            row -= 8;
        }
        if (row < 0) {
            row = 0;
        }
        list->first_target = row;
        if (list->first != row) {
            func_8003FEE0(6);
            goto top;
        }
    finish:
        if (sel >= 0) {
            list->cursor = sel;
            list->cursor_box->field_30.h.field_32 = sel * 22 + 0x2A;
            func_8003FEE0(6);
        }
        return 1;
    }

    if ((D_8009B394 & (0x1  | 0x2 ) ) != 0) {
        sel = -1;
        row = list->first;
        if ((D_8009B394 & 0x2 ) != 0) {
            if (row == list->row_count - 8 &&
                list->cursor != 7) {
                sel = 7;
            }
            row += 0x32;
            if (list->row_count - 8 < row) {
                row = list->row_count - 8;
            }
        } else {
            if (row == 0 && list->cursor != 0) {
                sel = 0;
            }
            row -= 0x32;
            if (row < 0) {
                row = 0;
            }
        }
        if (list->first != row) {
            func_8003FEE0(6);
            list->first_target = row;
            list->first = row;
            func_80031E04(list, 8);
            return 1;
        }
        goto finish;
    }

    if ((D_8009B394 & (0x1000  | 0x4000 ) ) != 0) {
        row = list->first;
        if ((D_8009B394 & 0x4000 ) != 0) {
            list->cursor += 1;
            if (list->cursor >= 8) {
                row += 1;
                list->cursor = 7;
            }
        } else {
            list->cursor -= 1;
            if (list->cursor < 0) {
                row -= 1;
                list->cursor = 0;
            }
        }
        list->cursor_box->field_30.h.field_32 =
            list->cursor * 22 + 0x2A;
        if (list->row_count - 8 < row) {
            return 1;
        }
        if (row < 0) {
            return 1;
        }
        func_8003FEE0(6);
        list->first_target = row;
        if (list->first != row) {
            goto top;
        }
        return 1;
    }

    if ((D_8009B394 & (0x100  | 0x800 )) !=
        0) {
        if ((D_8009B394 & 0x800 ) != 0) {
            list->sort_choice += 1;
            if (list->sort_choice >= 7) {
                list->sort_choice = 0;
            }
        } else {
            list->sort_choice -= 1;
            if (list->sort_choice < 0) {
                list->sort_choice = 6;
            }
        }
        func_8003FEE0(0x2F);
        icon = list->kind;
        slot = list->sort_choice;
        icon = icon << 4;
        slot = slot << 1;
        entry = D_80090DD8 + slot;
        icon = icon + (s32)entry;
        list->sort_mode = *(u8 *)(icon + 1) & 0xF;
        func_80032C48(list);
        return 1;
    }

    return 0;
}
