/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/func_80031874.c, profile gcc_2_8_1_g8_split_no_strength_reduce.
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
	unsigned p:24;
	unsigned char num:8;
}       GsOT_TAG;
typedef struct {
	unsigned long length;
	GsOT_TAG *org;
	unsigned long offset;
	unsigned long point;
	GsOT_TAG *tag;
}       GsOT;
typedef struct {
	unsigned long attribute;
	short   x, y;
	unsigned short w, h;
	unsigned short tpage;
	unsigned char u, v;
	short   cx, cy;
	unsigned char r, g, b;
	short   mx, my;
	short   scalex, scaley;
	long    rotate;
}       GsSPRITE;
void    func_800849F0(GsSPRITE * sp, GsOT * ot, unsigned short pri);
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
void func_800357E8(s32 arg0, s32 arg1, u8 *arg2);
void func_800358A0(s32 value, s32 count_arg, u8 *data_arg);
extern u8 D_80090DD8[];
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
void func_800316F0(
    GsSPRITE *sprite, GsOT *ot, const u8 *digits, s32 count
);
void func_80031784(
    GsSPRITE *sprite, GsOT *ordering_table, u8 *data, s32 selected);
void func_80031784(
    GsSPRITE *sprite, GsOT *ordering_table, u8 *data, s32 selected);
extern s16 D_8009B146 __attribute__((section(".data")));
extern s16 D_8009B148 __attribute__((section(".data")));
void func_80031874(DisplayObject *obj, GsOT *ot);
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
