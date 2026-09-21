/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/duel_result_runtime.c (Duel_CalcRankScore), profile gcc_2_8_1_g8_split.
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
struct DisplayObject;
struct DisplayObject;
typedef struct {
    u32 lo;
    u32 hi;
} Pair;
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
extern DuelSideState D_800E9FF0[2 ];
extern u8 D_8009B165;
s32 func_80021558(s32 rule, s32 value);
typedef struct {
    DisplayObject *root;
    DisplayObject *children[10 ];
     


    s32 side_scores[2];
     

    u8 page_text_ids[3];
    u8 page_index;
    u8 rank_tier;
    u8 is_tec_rank;
    u8 starchip_prize;
    u8 pad_3B;
    s16 dropped_card_id;
    u8 pad_3E[2];
} DuelResultDisplayState;
extern DuelResultDisplayState *D_8009B1E8;
void func_80021598(void);
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
struct DisplayObject;
s32 func_80021558(s32 arg0, s32 arg1);
void func_80021598(void) {
    DuelResultDisplayState *p;
    DuelSideState *e;
    s32 i;
    s32 v;
    s32 *q;

    p = D_8009B1E8;
    e = D_800E9FF0;
    q = &D_801D5608[0].rank_rows[0][0];
    p->page_text_ids[0] = 0x44;
    p->page_text_ids[1] = 0x40 ;
    p->page_text_ids[2] = 0x45;
    if (D_800E9FF0[D_8009B165].rank.result_adjustment ==
        40 ) {
        p->page_text_ids[1] = 0x42 ;
    }
    if (D_800E9FF0[D_8009B165].rank.result_adjustment ==
        (-40) ) {
        p->page_text_ids[1] = 0x41 ;
    }

    p->side_scores[1] = 50 ;
    p->side_scores[0] = 50 ;
    for (i = 0; i < 2 ; i++, e++, q++) {
        p->side_scores[i] += e->rank.result_adjustment;
        v = e->deck_draw_cursor; q[0 * 2 ] = v;
        p->side_scores[i] +=
            func_80021558(6 , v);
        v = e->life_points.signed_value; q[1 * 2 ] = v;
        p->side_scores[i] +=
            func_80021558(7 , v);
        q[2 * 2 ] = e->field_0E;
        q[3 * 2 ] = e->rank.field_0B;
        v = e->rank.effective_attacks; q[4 * 2 ] = v;
        p->side_scores[i] +=
            func_80021558(1 , v);
        q[5 * 2 ] = e->field_10;
        q[6 * 2 ] = e->rank.field_0C;
        v = e->rank.defensive_wins; q[7 * 2 ] = v;
        p->side_scores[i] +=
            func_80021558(2 , v);
        q[8 * 2 ] = e->rank.field_07;
        v = e->rank.face_down_plays; q[9 * 2 ] = v;
        p->side_scores[i] +=
            func_80021558(3 , v);
        v = e->rank.fusions_initiated; q[10 * 2 ] = v;
        p->side_scores[i] +=
            func_80021558(8 , v);
        v = e->rank.equips_used; q[11 * 2 ] = v;
        p->side_scores[i] +=
            func_80021558(9 , v);
        q[12 * 2 ] = e->rank.field_0A;
        v = e->rank.pure_magic_used; q[13 * 2 ] = v;
        p->side_scores[i] +=
            func_80021558(4 , v);
        v = e->rank.traps_triggered; q[14 * 2 ] = v;
        p->side_scores[i] +=
            func_80021558(5 , v);
        v = e->rank.turns_taken; q[15 * 2 ] = v;
        p->side_scores[i] +=
            func_80021558(0 , v);
    }
}
