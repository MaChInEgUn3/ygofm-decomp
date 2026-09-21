/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/duel_scene_card_placement.c (DuelScene_UpdateCardPlacement), profile gcc_2_8_1_g8_split_comm.
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
extern int  func_8008E590(void);
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
void func_8004036C(void *object);
typedef struct {
    u8 pad_00[0x30];
    s16 x;
    s16 y;
    s16 z;
    s16 velocity_x;
    s16 velocity_y;
    s16 velocity_z;
    u8 pad_3C[0x26];
    u8 fraction_x;
    u8 fraction_y;
    u8 fraction_z;
} DisplayObjectVelocity;
void *func_80042B40(s32 value);
s32 func_800428EC(DisplayObject *object, s8 value);
void func_800429D8(DisplayObjectVelocity *object);
void func_80042A00(DisplayObjectVelocity *object);
void func_80042A78(DisplayObjectVelocity *object);
s32 func_80042AD8(s32 value, s32 target, s32 step);
s32 func_80042B08(s32 value, s32 step);
typedef struct {
    u8 pad_00[0x30];
    u16 field_30;
    u16 field_32;
    u8 pad_34[2];
    u16 field_36;
    u16 field_38;
} DisplayObjectSnapshot;
typedef struct {
    u8 pad_00[0x30];
    s16 out_x;
    s16 out_y;
    u8 pad_34[0x02];
    s16 x;
    s16 y;
} DisplayObjectPosition;
void func_80043178(DisplayObjectSnapshot *object);
void func_8004318C(
    DisplayObjectPosition *object, s32 arg1, s32 arg2, s32 arg3);
extern DisplayObject *D_800E9EF0[];
extern u16 D_8009B23A;
typedef struct {
    u8 pad_00[0x0C];
    s16 field_0C;
    u8 pad_0E;
    s8 col;
    s8 row;
    u8 field_11;
    u8 field_12;
    u8 field_13;
    u8 pad_14[4];
    u8 field_18;
    u8 status;
} DuelCardPickCursor;
struct DisplayObject;
typedef struct {
    u8 *object;
    u8 *child;
    u8 pad_08;
    u8 active_09;
    u8 pad_0A[2];
} DuelHandSlot;
extern DuelHandSlot D_800EA030[5 ];
extern u8 D_800E9F10[];
extern DuelCardPickCursor *D_8009B1B4;
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
extern s16 D_8009B154;
extern DuelSideState *D_8009B1C8;
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
s32 func_800170C8(DuelCardRecord *card);
u8 *func_80017F04(DuelCardRecord *arg0, s32 arg1, s32 arg2);
void func_80024954(DuelCardRecord *object);
s32 func_80019A08(s32 equipment, s32 monster);
s32 func_80019A60(s32 card_a, s32 card_b);
typedef struct {
    s16 id;
     

    s8 deck_index;
    u8 data_block_index;
    u8 flags_04;
    u8 unk_05;
} DuelDeckCardRecord;
extern u8 D_8018C2D8[];
u8 *func_800249E0(s32, s32);
typedef struct {
    u8 pad_00000[0x4B6B4];
    DuelCardRecord field_cards[30 ];
    DuelDeckCardRecord cards[(40  * 2) ];
} DuelCardStagingDeckView;
extern u8 D_8015C424[];
extern DuelCardStagingDeckView D_8015C424_cards asm("D_8015C424");
extern u16 D_8009B210;
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
extern u8 *D_8009B17C;
extern int func_80086770(int a);
extern int func_800866A0(int a);
typedef struct {
	short x, y;		 
	short w, h;		 
} RECT;
extern int func_80081ED4(RECT *rect, u32 *p);
typedef struct DuelEffectResourceRecord {
     


    void *object_00;
    void *object_04;
    RECT rects[4];
    u16 src_x;
    u16 src_y;
    u16 field_2C;
    u16 field_2E;
     




    u16 field_30;
     









    s16 field_32;
    s16 field_34;
    s16 field_36;
    s16 field_38;
    u8 field_3A;
    u8 field_3B;
    u8 field_3C;
    u8 pad_3D[3];
} DuelEffectResourceRecord;
extern DuelEffectResourceRecord D_800EA0E8[];
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
typedef struct FileTransferDescriptor FileTransferDescriptor;
typedef void (*FileTransferCallback)();
struct FileTransferDescriptor {
    s16 x;
    s16 y;
    s16 w;
    s16 h;
    u32 value_08;
    u32 value_0C;
     

    s32 total_bytes;
    s32 file_bytes;
    u8 *loader_argument;
     

    u32 phase_size;
    FileTransferCallback phase_callback;
    s32 absolute_lba;
    s32 phase_remaining;
    u32 status_flags;
     












    union {
        struct {
            u16 counter;
            u16 field_32;
        } h;
        u32 word;
    } field_30;
    s32 direct_destination;
    void *callback_data;
    u32 position;
    u32 result;
    u16 buffer_index;
    u8 done;
    u8 substate;
};
extern volatile u32 D_8009B0F4_abs __attribute__((section(".data")));
extern u32 D_8009B134_abs __attribute__((section(".data")));
FileTransferDescriptor *func_80029164(s32 slot, s32 value);
extern DisplayObject *D_8009B1C0;
void func_80019CC8(void *card_id);
void func_80019BA0(
    DisplayObject *object, u8 field_21, s16 x, s16 y
);
u8 *func_800291E0(s32 index, s32 x, s32 y);
void func_80029528(s32 index);
struct DuelEffectChannel;
void func_80035B7C(struct DuelEffectChannel *record);
extern DuelEffectChannel D_800EB0F8[4 ];
void func_8003FEE0(u32);
extern u16 D_8009B162;
extern u16 D_8009B23A;
extern u8 D_8009B174;
struct DuelEffectChannel;
extern u16 D_8009B150;
extern u8 D_8009B1B9;
extern s16 D_8009B206;
extern s8 D_8009B218;
typedef struct {
    s16 value;
} DuelPlacementCardIdCell;
void func_80019D18(void);
void func_80019BD0(DisplayObject *object);
extern s16 D_8009B206;;
static __inline__ s32 placement_velocity(s32 distance)
{
    return distance / 8;
}
void func_80019D18(void)
{
    DuelFieldDisplaySource *side = (DuelFieldDisplaySource *)
        (D_800E9F10 + D_8009B1D5 * (4  * 0x1C ) );
    DisplayObject *object;
    DuelCardRecord *card;
    DuelEffectRequest *effect;
    s32 n;
    s32 value;
    s32 phase_clear;
    s32 x;

    if (!(D_8009B23A & 0x8000)) {
        DisplayObject **slots;
        DisplayObject **cursor;
        DuelHandSlot *hand;
        s16 y;
        x = 260;
        value = 4;
        D_8009B23A |= 0x8000;
        D_8009B1B4 = (DuelCardPickCursor *)side;
        D_8009B218 = 0;
        D_8009B1B9 = 0;
        D_8009B154 = 0;
        n = 5;
        y = 82;
        slots = D_800E9EF0;
        cursor = slots + 5;
        do {
            object = *cursor;
            if (object) {
                (( object )->position.h.field_28)  = x;
                (( object )->position.h.field_2A)  = y;
                func_800428EC(object, value);
                x -= 16;
                value++;
            }
            n--;
            cursor--;
        } while (n > 0);
        object = D_800E9EF0[0];
        (( object )->position.h.field_28)  = 64;
        (( object )->position.h.field_2A)  = 82;
        func_800428EC(object, value);
        if ((u8)(object->field_6A % 15) < 5)
        D_8009B218 = 1;
        slots = D_800E9EF0;
        if (!slots[1]) {
            if (slots[0]->field_68 < 20)
            D_8009B218 = 1;
            D_8009B150 = (D_8015C424_cards.field_cards[( object )->field_6A]) .card_id;
            (( object )->position.h.field_28)  = 134;
            (( object )->position.h.field_2A)  = 42;
            D_8009B23A |= 0x4000;
        } else {
            D_8009B1C8->rank.field_07++;
        }
        n = 0;
        do {
            hand = &D_800EA030[n];
            if (hand->active_09) {
                u8 *child = hand->child;
                hand->object = 0;
                func_8004036C(child);
                hand->child = 0;
            }
            n++;
        } while (n < 5);
        func_8004036C(side->object);
        D_8009B162 = 8;
        side->object = 0;
        D_8009B174 = 1;
        return;
    }

    switch (D_8009B174 & 15) {
    case 1:
        {
            DisplayObject **slots;
            {
                DisplayObject **cursor;
                DuelCardRecord *cards;
                DisplayObjectCallback callback;
                s32 active;
                if (!(D_8009B174 & 0x80)) {
                    D_8009B174 |= 0x80;
                    if (D_8009B23A & 0x4000)
                    return;
                    n = 5;
                    cards = D_801A7AD8;
                    active = 1;
                    callback = (DisplayObjectCallback)func_80019BD0;
                    slots = D_800E9EF0;
                    cursor = slots + 5;
                    do {
                        object = *cursor;
                        if (object && (cards[object->field_6A].flags & 0x2000)) {
                            object->field_6C = active;
                            object->update = callback;
                        }
                        n--;
                        cursor--;
                    } while (n >= 0);
                    return;
                }
                if (func_80042B40(1))
                return;
                D_8009B174 = 2;
            }
        }
    case 2:
        {
            DisplayObject **slots;
            {
                DisplayObject **cursor;
                if (!(D_8009B174 & 0x80)) {
                    DisplayObject **cursor;
                    s32 active;
                    D_8009B174 |= 0x80;
                    n = 5;
                    active = 1;
                    slots = D_800E9EF0;
                    cursor = slots + 5;
                    do {
                        object = *cursor;
                        if (object) {
                            object->field_6C = active;
                            func_80043178((DisplayObjectSnapshot *)object);
                            object->field_60 = 0;
                        }
                        n--;
                        cursor--;
                    } while (n >= 0);
                }
                value = 0;
                n = 5;
                slots = D_800E9EF0;
                cursor = slots + 5;
                do {
                    object = *cursor;
                    if (object && object->field_6C) {
                        value = 1;
                        if (!(D_8009B23A & 0x4000) && (( object )->field_20.b.field_21) )
                        (( object )->field_20.b.field_21)  += 8;
                        if ((( object )->field_20.b.field_22) )
                        (( object )->field_20.b.field_22)  += 8;
                        func_8004318C((DisplayObjectPosition *)object,
                        (s16)(( object )->position.h.field_28) , (s16)(( object )->position.h.field_2A) , object->field_60);
                        object->field_60 += 128;
                        if (object->field_60 >= 2048) {
                            object->field_6C = 0;
                            (( object )->field_20.b.field_22)  = 0;
                            if (!(D_8009B23A & 0x4000))
                            (( object )->field_20.b.field_21)  = 0;
                            if (! (( object )->field_20.b.field_21) )
                            object->flags &= ~4;
                            (( object )->field_30.h.field_30)  = (( object )->position.h.field_28) ;
                            (( object )->field_30.h.field_32)  = (( object )->position.h.field_2A) ;
                        }
                    }
                    n--;
                    cursor--;
                } while (n >= 0);
                if (!(D_8009B162 | value)) {
                    D_8009B174 = 3;
                    if (D_8009B23A & 0x4000)
                    D_8009B23A = 8;
                }
            }
            break;
        }
    case 3:
        {
            DisplayObject **slots;
            if (!(D_8009B174 & 0x80)) {
                D_8009B174 |= 0x80;
                D_8009B1B9++;
                if ((s8)D_8009B1B9 >= 6) {
                    D_8009B174 = 8;
                    return;
                }
                {
                    DisplayObject *selected = D_800E9EF0[(s8)D_8009B1B9];
                    if (!selected) {
                        D_8009B174 = 8;
                        return;
                    }
                    object = selected;
                }
                D_800E9EF0[1] = object;
                func_800429D8(
                    ((DisplayObjectVelocity *)( object )) );
                object->field_60 = 8;
                (( object )->field_34.h.field_36)  = placement_velocity((64 - (s16)(( object )->field_30.h.field_30) ) * 256);
                (( object )->field_38.h.field_38)  = placement_velocity((82 - (s16)(( object )->field_30.h.field_32) ) * 256);
                func_800428EC(D_800E9EF0[0], (s8)((u8)object->field_16 - 1));
                func_8003FEE0(10);
                D_8009B150 = 0;
                if (D_800E9EF0[0]) {
                    s32 result = func_80019A60((D_8015C424_cards.field_cards[( D_800E9EF0[0] )->field_6A]) .card_id,
                    (D_8015C424_cards.field_cards[( object )->field_6A]) .card_id);
                    D_8009B150 = result;
                    if ((s16)result) {
                        D_8009B150 = result | 0x8000;
                    } else {
                        s32 equip_result = func_80019A08((D_8015C424_cards.field_cards[( object )->field_6A]) .card_id,
                        (D_8015C424_cards.field_cards[( D_800E9EF0[0] )->field_6A]) .card_id);
                        D_8009B150 = equip_result;
                        if ((s16)equip_result)
                        goto request_combination;
                        D_8009B150 = func_80019A08((D_8015C424_cards.field_cards[( D_800E9EF0[0] )->field_6A]) .card_id,
                        (D_8015C424_cards.field_cards[( object )->field_6A]) .card_id);
                    }
                    if (!((DuelPlacementCardIdCell *)&D_8009B150)->value)
                    return;
request_combination:
                    func_80029164(0, D_8009B150 & 0xFFF);
                }
                return;
            }
            slots = D_800E9EF0;
            object = slots[1];
            func_80042A00(
                ((DisplayObjectVelocity *)( object )) );
            object->field_60--;
            if (object->field_60)
            return;
            D_8009B210 = 0;
            if (!slots[0]) {
                slots[0] = object;
                D_8009B174 = 3;
                return;
            }
            object->field_30.word = slots[0]->field_30.word;
            if (!((DuelPlacementCardIdCell *)&D_8009B150)->value) {
                D_8009B174 = 7;
                D_8009B218 = -1;
            } else if (((DuelPlacementCardIdCell *)&D_8009B150)->value & 0x8000) {
                D_8009B218 = 1;
                D_8009B154 = 0;
                D_8009B174 = 6;
                D_8009B1C8->rank.fusions_initiated++;
            } else {
                D_8009B174 = 5;
                D_8009B154 += 500;
                D_8009B1C8->rank.equips_used++;
            }
            break;
        }
    case 4:
        {
            DisplayObject **slots;
            if ((D_8009B0F4_abs & 0x2000030) | D_8009B134_abs)
            return;
            if (!(D_8009B174 & 0x80)) {
                D_8009B174 |= 0x80;
                D_8009B210 = 0;
                return;
            }
            switch (D_8009B210 & 15) {
            case 0:
                {
                    DisplayObject **slots;
                    {
                        s32 card_index = D_800E9EF0[0]->field_6A;
                        DuelEffectResourceRecord *resource = D_800EA0E8;
                        card = &D_801A7AD8[card_index];
                        slots = D_800E9EF0;
                        if (!(D_8009B210 & 0x80)) {
                            D_8009B210 |= 0x80;
                            if ((s16)D_8009B150 & 0x8000) {
                                ((DuelDeckCardRecord *)card->data)->id = D_8009B150 & 0xFFF;
                                D_8009B210 |= 0x40;
                                card->card_id = D_8009B150 & 0xFFF;
                                value = ((DuelDeckCardRecord *)card->data)->data_block_index;
                                resource->rects[0].x = resource->src_x + 56;
                                resource->rects[0].y = resource->src_y;
                                resource->rects[0].w = 8;
                                resource->rects[0].h = 88;
                                func_80081ED4(&resource->rects[0], (u32 *)(D_8018C2D8 + value * 1408));
                            }
                            return;
                        }
                        if (D_8009B210 & 0x40) {
                            func_800249E0(
                                card_index,
                                ((DuelDeckCardRecord *)card->data)->deck_index
                            );
                            func_80024954(card);
                        }
                        value = func_800170C8(card);
                        object = (DisplayObject *)func_800291E0(0, value & 0xFFFF, value >> 16);
                        (( object )->field_30.h.field_32)  = 16;
                        (( object )->field_30.h.field_30)  = (( D_800E9EF0[0] )->field_30.h.field_30)  - 44;
                        object->flags &= ~0x40;
                        D_8009B1C0 = object;
                        func_80019BA0(D_800E9EF0[0], 0, 64, 8);
                        if (slots[1]) {
                            s32 second = (s16)(( slots[1] )->field_30.h.field_30) ;
                            s32 first = (s16)(( D_800E9EF0[0] )->field_30.h.field_30) ;
                            second += 52;
                            (( D_8009B1C0 )->field_30.h.field_30)  = (first + second) / 2 - 70;
                            func_80019BA0(slots[1], 0, 64, 8);
                        }
                        D_8009B210 = 1;
                    }
                    break;
                }
            case 1:
                {
                    DisplayObject **slots;
                    s32 alpha;
                    if (func_80042B40(1))
                    return;
                    if (!(D_8009B210 & 0x80)) {
                        slots = D_800E9EF0;
                        slots[0]->flags &= ~0x40;
                        D_8009B210 |= 0x80;
                        if (slots[1])
                        slots[1]->flags &= ~0x40;
                        (( D_8009B1C0 )->field_20.b.field_21)  = 192;
                        D_8009B1C0->flags |= 0x44;
                        return;
                    }
                    alpha = (( D_8009B1C0 )->field_20.b.field_21)  + 8;
                    (( D_8009B1C0 )->field_20.b.field_21)  = alpha;
                    if ((s8)alpha >= 0) {
                        DisplayObject *entry = D_8009B1C0;
                        u16 flags = entry->flags;
                        (( entry )->field_20.b.field_21)  = 0;
                        D_8009B210 = 2;
                        entry->flags = flags & ~4;
                    }
                    break;
                }
            case 2:
                {
                    DisplayObject **slots;
                    card = &D_801A7AD8[D_800E9EF0[0]->field_6A];
                    object = D_8009B1C0;
                    if (!(D_8009B210 & 0x80)) {
                        D_8009B210 |= 0x80;
                        object->field_60 = 30;
                        if (!((s16)D_8009B150 & 0x8000)) {
                            (( object )->position.h.field_28)  = 0;
                            (( object )->position.h.field_2A)  = 500;
                            D_8009B210 |= 0x40;
                            object->field_2C.h.field_2C = card->stat_modifier;
                            if (D_8009B206 == 0x291) {
                                (( object )->position.h.field_2A)  = 1000;
                                D_8009B154 += 500;
                            }
                        }
                    }
                    if (D_8009B210 & 0x40) {
                        s32 below;
                        u16 limit;
                        (( object )->position.h.field_28)  += 31;
                        below = (s16)(( object )->position.h.field_28)  < (s16)(( object )->position.h.field_2A) ;
                        limit = (( object )->position.h.field_2A) ;
                        if (!below) {
                            D_8009B210 &= ~0x40;
                            (( object )->position.h.field_28)  = limit;
                            object->field_60 = 16;
                        }
                        card->stat_modifier = object->field_2C.h.field_2C + (( object )->position.h.field_28) ;
                        value = func_800170C8(card);
                        D_800EA0E8[0].field_32 = value;
                        D_800EA0E8[0].field_34 = value >> 16;
                        return;
                    }
                    object->field_60--;
                    if (object->field_60 > 0)
                    return;
                    {
                        DisplayObject *entry = D_8009B1C0;
                        *(u16 *)((u32)entry + (u32)&((DisplayObject *)0)->flags) = entry->flags | 4;
                    }
                    slots = D_800E9EF0;
                    func_8004036C(slots[0]);
                    func_8004036C(slots[1]);
                    slots[1] = 0;
                    slots[0] = 0;
                    object = (DisplayObject *)func_80017F04(card, 64, 82);
                    D_800E9EF0[0] = object;
                    object->field_20.word = 0;
                    D_8009B210 = 3;
                    object->flags &= ~0x44;
                    break;
                }
            case 3:
                {
                    DisplayObject **slots;
                    s32 alpha;
                    object = D_800E9EF0[0];
                    if (!(D_8009B210 & 0x80)) {
                        alpha = (( D_8009B1C0 )->field_20.b.field_21)  + 8;
                        (( D_8009B1C0 )->field_20.b.field_21)  = alpha;
                        if ((u8)alpha < 64)
                        return;
                        {
                            u16 position = (( D_8009B1C0 )->field_30.h.field_30) ;
                            D_8009B210 |= 0x80;
                            (( object )->field_30.h.field_30)  = position + 44;
                        }
                        func_80019BA0(object, 192, 0, 8);
                        object->flags |= 0x40;
                        func_80029528(0);
                        return;
                    }
                    if (!func_80042B40(1))
                    D_8009B210 = 4;
                    break;
                }
            case 4:
                {
                    DisplayObject **slots;
                    object = D_800E9EF0[0];
                    if (!(D_8009B210 & 0x80)) {
                        D_8009B210 |= 0x80;
                        func_80043178((DisplayObjectSnapshot *)object);
                        object->field_60 = 0;
                    }
                    func_8004318C((DisplayObjectPosition *)object, 64, 82, object->field_60);
                    object->field_60 += 128;
                    if (object->field_60 >= 2048)
                    D_8009B174 = 3;
                    break;
                }
            }
            break;
        }
    case 5:
        {
            DisplayObject **slots;
            if (!(D_8009B174 & 0x80)) {
                DisplayObject **slots;
                slots = D_800E9EF0;
                slots[0]->flags &= ~0x40;
                D_8009B174 |= 0xC0;
                func_80019BA0(slots[1], 0, 64, 8);
                object = D_800E9EF0[0];
                if (object->field_68 != 23)
                object = slots[1];
                D_8009B206 = (D_8015C424_cards.field_cards[( object )->field_6A]) .card_id;
                return;
            }
            if (D_8009B174 & 0x40) {
                DisplayObject **slots;
                if (func_80042B40(1))
                return;
                {
                    s32 phase = D_8009B174;
                    if (phase & 0x20) {
                        phase_clear = phase & 0x9F;
                        goto finish_effect_step;
                    }
                }
                {
                    DisplayObject **release_slots = D_800E9EF0;
                    D_8009B174 |= 0x20;
                    if (release_slots[1]->field_68 < 20) {
                        func_8004036C(D_800E9EF0[0]);
                        D_800E9EF0[0] = release_slots[1];
                    } else {
                        func_8004036C(release_slots[1]);
                    }
                }
                {
                    DisplayObject **publish_slots = D_800E9EF0;
                    publish_slots[1] = 0;
                    D_800E9EF0[0]->flags |= 0x40;
                    func_80019BA0(D_800E9EF0[0], 192, 0, 8);
                }
                return;
            }
            if (!(D_8009B174 & 0x20)) {
                DisplayObject **slots;
                D_8009B174 |= 0x20;
                effect = ((DuelEffectRequest *)( 
                    func_8002C604(
                        ((u32)((u16)D_8009B206 - 301) < 2) * 4) )) ;
                effect->field_00 = (( D_800E9EF0[0] )->field_30.h.field_30)  + 26;
                D_8009B17C = (u8 *)effect;
                effect->field_02 = (( D_800E9EF0[0] )->field_30.h.field_32)  + 30;
                if (D_8009B206 == 302)
                effect->field_1A = 1;
                if (D_8009B206 == 0x291)
                effect->field_1A = 10;
                func_8003FEE0(22);
            } else if (((DuelEffectRequest *)( D_8009B17C )) ->field_1D) {
                D_8009B174 = 4;
            }
            break;
        }
    case 6:
        {
            DisplayObject **slots;
            if (!(D_8009B174 & 0x80)) {
                DisplayObject **slots;
                D_8009B174 |= 0xC0;
                func_80019CC8((void *)(u32)(D_8009B150 & 0xFFF));
                slots = D_800E9EF0;
                slots[0]->flags &= ~0x40;
                func_80019BA0(slots[1], 0, 64, 8);
            }
            if (D_8009B174 & 0x40) {
                DisplayObject **slots;
                if (func_80042B40(1))
                return;
                {
                    s32 phase = D_8009B174;
                    if (phase & 0x20) {
                        phase_clear = phase & 0x9F;
                        goto finish_effect_step;
                    }
                }
                slots = D_800E9EF0;
                D_8009B174 |= 0x20;
                func_80019BA0(slots[1], 192, 0, 8);
                (( slots[1] )->field_30.h.field_30)  = 140;
                D_800E9EF0[0]->flags |= 0x40;
                func_80019BA0(D_800E9EF0[0], 192, 0, 8);
                return;
finish_effect_step:
                D_8009B174 = phase_clear;
                return;
            }
            if (!(D_8009B174 & 0x20)) {
                DisplayObject **slots;
                D_800E9EF0[0]->field_60 = 0;
                (( D_800E9EF0[0] )->position.h.field_28)  = 1;
                (( D_800E9EF0[0] )->position.h.field_2A)  = 0x2680;
                D_8009B174 |= 0x20;
                D_800E9EF0[0]->field_2C.h.field_2E = 1;
                {
                    DuelEffectRequest *request;
                    request = ((DuelEffectRequest *)( 
                        func_8002C604(1) )) ;
                    request->field_00 = 128;
                    (*(s16 *)((u32)request + (u32)&((DuelEffectRequest *)0)->field_02)) = (( D_800E9EF0[0] )->field_30.h.field_32)  + 30;
                    D_8009B17C = (u8 *)request;
                    slots = D_800E9EF0;
                    if (slots[0]->field_68 >= 20 || slots[1]->field_68 >= 20)
                    request->field_1A = 1;
                }
                func_8003FEE0(24);
                return;
            }
            if (((DuelEffectRequest *)( D_8009B17C )) ->field_1D) {
                DisplayObject **slots;
                slots = D_800E9EF0;
                slots[0]->flags &= ~0x40;
                slots[1]->flags &= ~0x40;
                func_8003FEE0(25);
                D_8009B174 = 4;
            } else {
                object = D_800E9EF0[0];
                object->field_2C.h.field_2E += 8;
                object->field_60 += D_800E9EF0[0]->field_2C.h.field_2E;
                (( object )->position.h.field_2A)  -= object->field_60 / 12;
                n = (s16)(( object )->position.h.field_2A)  >> 8;
                x = func_80086770(object->field_60) * n / 4096;
                value = func_800866A0(object->field_60) * n / 4096;
                (( object )->field_30.h.field_30)  = 102 - x;
                (( object )->field_30.h.field_32)  = 82 - value;
                slots = D_800E9EF0;
                (( slots[1] )->field_30.h.field_30)  = x + 102;
                (( slots[1] )->field_30.h.field_32)  = value + 82;
            }
            break;
        }
    case 7:
        {
            DisplayObject **slots;
            slots = D_800E9EF0;
            object = slots[0];
            if (!(D_8009B174 & 0x80)) {
                D_8009B174 |= 0x80;
                object->flags |= 4;
                object->attribute &= ~0x08000000;
                func_8003FEE0(26);
                if (slots[1]->field_68 >= 20 && object->field_68 < 20) {
                    DisplayObject *other = slots[1];
                    slots[1] = object;
                    object = other;
                    slots[0] = other;
                }
                func_800429D8(
                    ((DisplayObjectVelocity *)( object )) );
                (( object )->field_34.h.field_36)  = -((func_8008E590() & 255) + 768);
                (( object )->field_38.h.field_38)  = -640;
            }
            (( object )->field_34.h.field_36)  = func_80042B08((( object )->field_34.h.field_36) , 8);
            (( object )->field_38.h.field_38)  = func_80042AD8((( object )->field_38.h.field_38) , 2048, 96);
            func_80042A78(
                ((DisplayObjectVelocity *)( object )) );
            if ((s16)(( object )->field_30.h.field_30)  < -52 || (s16)(( object )->field_30.h.field_32)  >= 240) {
                func_8004036C(object);
                D_800E9EF0[0] = D_800E9EF0[1];
                func_80035B7C(D_800EB0F8);
                D_8009B174 = 3;
            }
            break;
        }
    case 8:
        {
            DisplayObject *object;
            DuelCardRecord *card;
            DisplayObject **slots;
            object = D_800E9EF0[0];
            D_8009B23A = 6;
            if (object->field_68 < 20) {
                s32 index = object->field_6A;
                DuelCardRecord *base = D_801A7AD8;
                D_8009B23A = 0x4008;
                card = &base[index];
                card->flags &= ~0x1000;
                if (D_8009B218)
                D_8009B23A = 8;
            }
            break;
        }
    }
}
