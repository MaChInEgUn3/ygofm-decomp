/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/duel_phase_entry.c (DuelScene_UpdateResume), profile gcc_2_8_1_g8_split.
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
typedef struct {
    u8 tint_r;
    u8 tint_g;
    u8 tint_b;
    u8 pad_03;
    u8 level;
    u8 target_level;
    u8 flags;
    u8 step;
    u16 field_08;
    u8 band_levels[30 ];
} FadeTransitionState;
extern u8 D_800907D8[];
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
extern DuelCardRecord D_801A7B64[];
typedef struct {
    char pad_00[0x22];
    u8 flag;
    char pad_23[0x45];
    u8 type;
} CardObject;
s32 func_800181EC(CardObject *object);
u8 *func_8002C604(s32 id);
typedef struct {
    s16 field_00;    
    s16 field_02;    
    s16 field_04;    
    u8 pad_06[2];    
    s32 field_08;    
    s32 field_0C;    
    s16 field_10;    
    s16 field_12;    
    void *buffer;    
    s16 id;          
    s16 field_1A;    
    u8 flags;        
    u8 field_1D;     
} DuelEffectRequest;
DuelEffectRequest *func_8002C68C(s32 id);
typedef struct {
    u8 pad_00[0x04];
    u32 attribute;
    u16 flags;
    u8 pad_0A[0x02];
    u32 color;
    void *field_10;
    u8 pad_14[0x0D];
    u8 field_21;
    u8 field_22;
    u8 pad_23[0x0D];
    s16 out_x;
    s16 out_y;
    s16 field_34;
    u8 pad_36[0x0C];
    u16 icon_variant;
    u8 pad_44[0x08];
    void *field_4C;
    u8 pad_50[0x0C];
    u8 icon_state;
    u8 field_5D;
    u8 pad_5E[0x09];
    u8 field_67;
    u8 field_68;
    u8 field_69;
    u8 card_index;
    u8 field_6B;
} DuelCardDisplayObject;
void func_80024954(DuelCardRecord *object);
void func_80024D34(s32 slot, s32 card_id);
typedef struct {
    u8 pad_0000[0x36B4];
    DuelCardRecord record;
} DuelCardReplayRecordBlock;
extern u8 D_8015C424[];
typedef struct DuelFieldEffectObject DuelFieldEffectObject;
struct DuelFieldEffectObject {
    s16 x;
    s16 y;
    u8 pad_04[0x16];
    s16 field_1A;
    u8 flags;
    u8 count;
    u8 pad_1E[4];
    u8 timer;
    u8 pad_23;
    void (*callback)(DuelFieldEffectObject *);
    u8 pad_28[0x3F];
    u8 mark;
    u8 pad_68[2];
    u8 index;
    u8 pad_6B;
    u8 active;
};
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
extern DuelFieldEffectObject
    *D_8009B1F0[2 ];
extern u16 D_8009B36A __attribute__((section(".data")));
extern u16 D_8009B23A;
extern s8 D_8009B208[8];
void func_8001825C(void);
extern s8 D_8009B1B9;
void func_8001352C(void);
void func_8001352C(void);
struct DisplayObject;
extern FadeTransitionState D_800E9EC8;
void func_800157DC(void);
extern volatile u32 D_8009B0F4_abs __attribute__((section(".data")));
extern u32 D_8009B134_abs __attribute__((section(".data")));
void func_8003FF08(u32);
void func_8003FEE0(u32);
extern u16 D_8009B23A;
void func_80018080(DuelCardDisplayObject *object);
void func_8001825C(void)
{
    DuelCardRecord *rec;
    DuelEffectRequest *obj;
    u8 *b;
    DisplayObject *card;
    s32 i;
    s32 keep;
    s32 y;
    u16 flags;
    s8 n;

    if ((D_8009B23A & 0x8000 ) == 0) {
        D_8009B23A |= 0x8000 ;
        rec = D_801A7B64;
        for (i = 5 ; i < 15 ; i++, rec++) {
            flags = rec->flags;
            if (flags & 0x8000 ) {
                keep = flags & 0x7A00;
                y = rec->stat_modifier;
                func_80024D34(i, ((s8 *)rec->data)[2]);
                rec->flags |= keep;
                rec->stat_modifier = y;
                func_80018080(
                    ((DuelCardDisplayObject *)( rec->object )) );
            }
        }
        rec = D_801A7B64 + 15;
        for (i = 20; i < 30 ; i++, rec++) {
            flags = rec->flags;
            if (flags & 0x8000 ) {
                keep = flags & 0x7A00;
                y = rec->stat_modifier;
                func_80024D34(i, ((s8 *)rec->data)[2]);
                rec->flags |= keep;
                rec->stat_modifier = y;
                func_80018080(
                    ((DuelCardDisplayObject *)( rec->object )) );
            }
        }
        func_8001352C();
        for (i = 0; i < 2 ; i++) {
            if (D_800E9FF0[i].swords_turns_remaining != 0) {
                obj = (DuelEffectRequest *)func_8002C604(0x15);
                obj->field_1A = i + 2;
                obj->flags |= 0x20 ;
                D_8009B1F0[i] =
                    (DuelFieldEffectObject *)obj;
            }
        }
        if (D_8009B1C8->rank.result_adjustment ==
            40 ) {
            D_8009B23A |= 0x2000;
            for (i = 0; i < 10 ; i++) {
                rec = &D_801A7AD8[D_800907D8[
                    i + D_8009B1D5 * 20 ]];
                if (rec->flags & 0x8000 ) {
                    func_80024954(rec);
                }
            }
        } else {
            if (D_800E9FF0[0].life_points.signed_value != 0 &&
                D_800E9FF0[1].life_points.signed_value != 0) {
                func_8003FF08(D_8009B36A);
            }
        }
        func_800157DC();
        return;
    }

    if ((D_8009B23A & 0x4000) == 0) {
        if (((D_8009B0F4_abs & 0x02000030 ) |
             D_8009B134_abs) != 0) {
            return;
        }
        if ((D_800E9EC8.flags & 0x80 ) != 0) {
            return;
        }
        D_8009B23A |= 0x4000;
        D_8009B1B9 = 2;
        if ((D_8009B23A & 0x2000) != 0) {
            D_8009B23A = 0xC;
        }
        return;
    }

    for (;;) {
        n = D_8009B1B9 - 1;
        D_8009B1B9 = n;
        if (n < 0) {
            D_8009B23A = 5;
            return;
        }
        if (D_8009B208[n] >= 0) {
            break;
        }
    }
    {
        s32 replay_offset = 0x48000 ;
        DuelCardReplayRecordBlock *replay;

        b = D_8015C424;
        replay = (DuelCardReplayRecordBlock *)(
            (u8 *)&((DuelCardRecord *)b)[D_8009B208[n]] + replay_offset);
        card = replay->record.object;
    }
    func_8001352C();
    obj = func_8002C68C(0xB);
    obj->field_00 = card->field_30.h.field_30;
    obj->field_02 = card->field_30.h.field_32;
    obj->field_04 = *(u16 *)&card->field_34;
    obj->field_1A = func_800181EC((CardObject *)card);
    func_80024954(&D_801A7AD8[card->field_6A]);
    func_8003FEE0(0x1F);
}
