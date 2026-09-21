/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/duel_field_display_objects.c, profile gcc_2_8_1_g8_split.
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
    u8 pad_00[0xF];
    s8 col;
    s8 row;
} DuelFieldCursor;
union DuelSideLifePoints {
    u16 unsigned_value;
    s16 signed_value;
};
typedef struct {
    s8 result_adjustment;
    u8 turns_taken;
    u8 effective_attacks;
    u8 defensive_wins;
    u8 face_down_plays;
    u8 pure_magic_used;
    u8 traps_triggered;
    u8 field_07;
    u8 fusions_initiated;
    u8 equips_used;
    u8 field_0A;
    u8 field_0B;
    u8 field_0C;
} DuelRankStatistics;
typedef struct {
    DuelRankStatistics rank;
    u8 field_0D;
    s16 field_0E;
    s16 field_10;
     



    s16 displayed_life_points;
    union DuelSideLifePoints life_points;
    s16 max_life_points;
     

    s8 deck_draw_cursor;
    s8 swords_turns_remaining;
     


    s8 hand[5 ];
     

    s8 card_view_mode;
} DuelSideState;
extern u8 D_8009B1D5;
extern DuelSideState D_800E9FF0[2 ];
extern DuelSideState *D_8009B1C8;
struct DisplayObject;
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
typedef struct {
    void *object;
    void *data;
    u8 pad_08[4];
    s16 card_id;
    s16 attack;
    s16 defense;
    s16 stat_modifier;
    s16 terrain_modifier;
    u16 flags;
    u8 table_index;
    u8 pad_19[3];
} DuelCardRecord;
extern DuelCardRecord D_801A7AD8[];
extern s32 D_801D4244[];
s32 func_800170C8(DuelCardRecord *card);
struct DisplayObject;
typedef struct DisplayLinkEntry {
    DisplayObject *object;
    DisplayObject *field_04;
    u8 pad_08[4];
} DisplayLinkEntry;
typedef struct {
    DisplayObject *field_00;
    DisplayObject *object;
    DisplayLinkEntry *entries;
    s16 field_0C;
    u8 pad_0E[1];
    s8 x;
    s8 y;
    u8 pad_11[2];
    u8 field_13;
    u8 field_14;
    u8 pad_15[1];
    s8 field_16;
    u8 table_index;
    u8 field_18;
} DuelFieldDisplaySource;
s32 func_80023090(DuelFieldCursor *cursor_a, DuelFieldCursor *cursor_b);
void func_80023144(DuelFieldDisplaySource *source, s32 index);
typedef struct {
    u16 code_00;
    u16 pad_02;
    s32 field_04;
    s32 field_08;
    s16 x_0C;
    s16 y_0E;
    u8 field_10;
    u8 flags_11;
    u8 field_12;
    u8 field_13;
    u8 pad_14;
    u8 field_15;
     
    u8 field_16;
    u8 field_17;
    u8 field_18;
    u8 pad_19[3];
} DuelEffectEntry;
struct DuelEffectChannel;
struct DisplayObject;
typedef struct DuelEffectChannel {
    u8 *text_00;
     










    u8 field_04;
    u8 field_05;
    u8 field_06;
    u8 field_07;
    u8 field_08;
    u8 field_09;
    u8 field_0A;
    u8 pad_0B;
    u16 field_0C;
    u16 field_0E;
     



    u8 field_10;
    u8 field_11;
    u8 pad_12;
    u8 field_13;
    u8 field_14;
    u8 field_15;
    u8 pad_16[10];
    DuelEffectEntry *entry_end_20;
    DuelEffectEntry *entry_head_24;
     



    struct DisplayObject *field_28;
     



    struct DisplayObject *field_2C;
    struct DisplayObject *field_30;
    u16 flags_34;
    u16 field_36;
    u16 field_38;
    u16 field_3A;
    s16 field_3C;
    s16 field_3E;
    s16 field_40;
    s16 field_42;
     

    u8 text_44[0x0D];
     

    u8 state_51;
     

    u8 delay_52;
    u8 field_53;
    u8 field_54;
    u8 pad_55;
    u8 field_56;
    u8 index_57;
     

    s8 stream_58;
    u8 field_59;
    u8 field_5A;
    u8 field_5B;
    u16 range_start_5C;
    u16 range_count_5E;
    u8 field_60;
    u8 field_61;
     


    u8 field_62;
    u8 pad_63;
} DuelEffectChannel;
typedef struct {
    u32 lo;
    u32 hi;
} Pair;
extern u8 D_8009B344 __attribute__((section(".data")));
extern u8 D_8009B34E __attribute__((section(".data")));
extern u8 D_8009B355 __attribute__((section(".data")));
extern u8 D_8009B320 __attribute__((section(".data")));
extern s16 D_8009B338 __attribute__((section(".data")));
struct DisplayObject;
extern u8 D_800E9F48[];
struct DuelEffectChannel;
void *func_80035BE4(
    s32 index, s32 string_id, s32 x, s32 y, s32 width, s32 height
);
struct DuelEffectChannel;
void func_80039A14(struct DuelEffectChannel *object);
typedef union {
    struct {
        s32 attack;
        s32 defense;
        s32 rank;
    } card_stats;
    struct {
        s32 card_id;
        s32 count;
    } card;
    struct {
        s32 chest;
        s32 deck;
    } build_deck;
    struct {
        s32 used;
        s32 needed;
    } blocks;
    struct {
        s32 field_00[16];
        s32 invalid_side;
    } deck_validation;
    s32 library_count;
     
    s32 starchips;
    s32 rank_rows[16][2 ];
    Pair pair;
} TextStagingValues;
extern TextStagingValues D_801D5608[];
struct DuelEffectChannel;
s32 func_80023090(DuelFieldCursor *cursor_a, DuelFieldCursor *cursor_b);
void func_80023144(DuelFieldDisplaySource *source, s32 index)
{
    DuelCardRecord *record = &D_801A7AD8[index];
    DuelEffectChannel *box;
    s32 *table;
    s32 style;
    s32 id;
    s32 value;
    s32 stats;

    D_8009B34E = 0;
    D_8009B355 = 0;
    style = 0x50;
    if (record->flags & 0x8000) {
        table = D_801D4244;
        id = (s16)record->card_id;
        stats = *(s32 *)((s32)table + ((id - 1) << 2));
        D_8009B34E = 1;
        D_8009B338 = id;
        if (((stats >> 26 ) & 0x1F ) <
            20 ) {
            if (record->flags & 0x200) {
                D_8009B344 =
                    (stats >> 18 ) &
                    0xF ;
            } else {
                D_8009B344 =
                    (stats >> 22 ) &
                    0xF ;
            }
            D_8009B344 = D_8009B344 + 0x17;
            value = func_800170C8(record);
            D_801D5608[0].card_stats.attack = (s16)value;
            D_801D5608[0].card_stats.defense = value >> 16;
        } else {
            style = 0x51;
        }
        if (index % 15  >= 5 ) {
            D_8009B34E = 2;
            if (record->flags & 0x1000) {
                D_8009B34E = 3;
            }
            value = index >= 15 ;
            if (value == D_8009B1D5 &&
                D_8009B1C8->card_view_mode == 0) {
                D_8009B34E = 2;
            }
        } else {
            if (record->flags & 0x2000) {
                D_8009B34E = 0;
            }
        }
    }
    value = source->table_index;
    if (value == 3) {
        s32 rank;
        TextStagingValues *dst = D_801D5608;

        style += 4;
        rank = D_800E9FF0[D_8009B1D5 ^ 1].swords_turns_remaining;
        dst->card_stats.rank = rank;
        if (rank != 0) {
            if (rank < 0 || rank > 3) {
                dst->card_stats.rank = 3;
            }
            D_8009B355 = 1;
        }
        if (D_8009B34E != 0) {
            D_8009B355 = D_8009B355 | 2;
            D_8009B320 = func_80023090(
                (DuelFieldCursor *)source,
                (DuelFieldCursor *)
                    &D_800E9F48[D_8009B1D5 * (4  * 0x1C ) ]
            );
        }
    }
    if (source->table_index == 2 && source->field_18 != 0) {
        s32 rank;
        TextStagingValues *dst;
        s32 side;

        side = D_8009B1D5;
        if (source->y < 2) {
            side = side ^ 1;
        }
        dst = D_801D5608;
        rank = D_800E9FF0[side].swords_turns_remaining;
        dst->card_stats.rank = rank;
        if (rank != 0) {
            if (rank < 0 || rank > 3) {
                dst->card_stats.rank = 3;
            }
            D_8009B355 = 1;
        }
        style += 2;
    }
    box = func_80035BE4(
        source->field_14, style,
        *(s16 *)&source->field_00->field_30.h.field_30 + 0x10,
        *(s16 *)&source->field_00->field_30.h.field_32 + source->field_16,
        0x120, 0x40
    );
    box->field_59 = *(u8 *)&source->field_00->field_16 + 1;
    func_80039A14((struct DuelEffectChannel *)box);
}
