/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/duel_ritual_effect.c (DuelEffect_ApplyRitual), profile gcc_2_8_1_g8_split.
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
extern u16 D_8009B220;
extern s16 D_8009B1D2;
extern s16 D_8009B20C[2];
extern u16 D_8009B210;
s32 func_80024E24(void);
typedef struct DuelRitualResult {
    void *tribute_objects[3 ];
    s32 field_0C;
} DuelRitualResult;
s32 func_8002C7E8(DuelRitualResult *out, s32 ritual_id);
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
extern s16 D_8009B1A0;
extern DisplayObject *D_8009B1C0;
extern u16 D_800EA128[22 ];
void func_80019CC8(void *card_id);
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
u8 *func_80017F04(DuelCardRecord *arg0, s32 arg1, s32 arg2);
void func_80024914(DuelCardRecord *object);
void func_80024D34(s32 slot, s32 card_id);
typedef struct {
    s16 id;
     

    s8 deck_index;
    u8 data_block_index;
    u8 flags_04;
    u8 unk_05;
} DuelDeckCardRecord;
extern u8 D_8018C2D8[];
typedef struct {
    u8 pad_00000[0x4B6B4];
    DuelCardRecord field_cards[30 ];
    DuelDeckCardRecord cards[(40  * 2) ];
} DuelCardStagingDeckView;
extern u8 D_8015C424[];
extern DuelCardStagingDeckView D_8015C424_cards asm("D_8015C424");
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
extern u8 D_8009B1D5;
extern u8 D_8009B19C;
extern s8 D_8009B360[2 ] __attribute__((section(".data")));
typedef union {
    DisplayObject *slots[5 ];
    struct {
        DisplayObject *effects[2];
        DuelRitualResult result;
    } ritual;
} DisplayObjectRitualWorkArea;
extern DisplayObjectRitualWorkArea D_800E9EF0;
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
void func_80042A28(DisplayObjectVelocity *object);
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
void func_80043230(
    DisplayObjectPosition *object,
    int target_x,
    int target_y,
    int phase);
void func_8001EC70(u8 *object);
struct DisplayObject;
void func_8004036C(void *object);
void func_8001944C(DisplayObject *object);
void func_8001944C(DisplayObject *object);
struct DisplayObject;
typedef struct {
    u8 pad_00[0x08];
    u16 flags;
    u8 pad_0A[0x0E];
    s16 half_height;
    s16 half_width;
    u8 pad_1C[0x14];
    s16 x;
    s16 y;
    u8 pad_34[0x08];
    s16 height;
    s16 width;
    s16 field_40;
    s16 field_42;
    u8 pad_44[0x04];
    s16 half_height_2;
    s16 half_width_2;
    u8 pad_4C[0x10];
    u8 field_5C;
    u8 field_5D;
    u8 pad_5E[0x08];
    u8 field_66;
} DisplayObjectConfigView;
DisplayObject *func_80019564(DisplayObjectConfigView *source);
u8 *func_800291E0(s32 index, s32 x, s32 y);
void func_80029528(s32 index);
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
extern DuelEffectChannel D_800EB0F8[4 ];
extern s16 D_8009B338 __attribute__((section(".data")));
struct DuelEffectChannel;
void func_80035B7C(struct DuelEffectChannel *record);
void *func_80035C38(
    s32 index, s32 string_id, s32 x, s32 y, s32 width, s32 height, s32 flags
);
struct DuelEffectChannel;
s32 func_8003700C(struct DuelEffectChannel *record);
extern s8 D_8009B34D __attribute__((section(".data")));
extern u16 D_8009B398 __attribute__((section(".data")));
void func_8003FEE0(u32);
void func_8003FF88(u32);
void func_80039794(void);
extern int  func_8008E590(void);
typedef struct {
	short x, y;		 
	short w, h;		 
} RECT;
extern int func_8007F9D8(RECT *rect, u32 *p);
void func_800262D4(void);
struct DuelEffectChannel;
struct DuelRitualResult;
void func_800262D4(void)
{
    DisplayObject *object;
    DuelCardRecord *card;
    DuelEffectChannel *text;
    s32 value;
    s32 timer;
    u16 flags;

    if (!func_80024E24()) {
        D_8009B1A0 = func_8002C7E8(
            &D_800E9EF0.ritual.result, D_8009B1D2);
        if (D_8009B1A0) {
            func_80019CC8((void *)(s32)D_8009B1A0);
            D_8009B17C = func_8002C604(22);
            D_8009B210 = 0;
            ((DuelEffectRequest *)D_8009B17C)->field_1A = D_8009B1D2;
            func_8003FF88(0x8022);
        } else {
            goto done;
        }
        return;
    }
    switch (D_8009B210 & 0xF) {
    case 0:
        if (((DuelEffectRequest *)D_8009B17C)->field_1D) {
            D_8009B19C = D_800E9EF0.slots[3]->field_6A;
            func_80024914(&D_801A7AD8[D_800E9EF0.slots[2]->field_6A]);
            func_80024914(&D_801A7AD8[D_800E9EF0.slots[3]->field_6A]);
            func_80024914(&D_801A7AD8[D_800E9EF0.slots[4]->field_6A]);
            D_8009B210 = 1;
        }
        break;
    case 1: {
        u16 scale;
        s32 countdown;
        object = D_8009B1C0;
        if (!(D_8009B210 & 0x80)) {
            s32 attribute;
            s16 object_flags;
            D_8009B210 |= 0x80;
            object = (DisplayObject *)func_800291E0(1, -1, -1);
            object->field_30.h.field_30 = 90;
             


            *(s16 *)&object->field_30.h.field_32 = -34;
            object->field_60 = 24;
            attribute = object->attribute;
            object_flags = object->flags;
            object->field_44.h.field_46 = 0;
            object->field_44.h.field_44 = 0;
            object->attribute = attribute & 0xF7FFFFFF;
            object->flags = object_flags | 4;
            func_800429D8((DisplayObjectVelocity *)object);
            object->field_38.h.field_38 = 597;
            D_8009B1C0 = object;
            func_8003FEE0(0x26);
        }
        func_80042A28((DisplayObjectVelocity *)object);
        scale = (u16)object->field_44.h.field_44 + 170;
        countdown = (u16)object->field_60 - 1;
        object->field_44.h.field_44 = scale;
        object->field_44.h.field_46 = scale;
        object->field_60 = countdown;
        if ((s32)((u32)countdown << 16) <= 0) {
            s32 attribute;
            s16 object_flags;
            object->field_44.h.field_46 = 4096;
            object->field_44.h.field_44 = 4096;
            object->field_30.h.field_32 = 22;
            D_8009B210 = 2;
            attribute = object->attribute | 0x08000000;
            object_flags = object->flags & 0xFFFB;
            object->attribute = attribute;
            object->flags = object_flags;
        }
        break;
    }
    case 2:
        object = D_8009B1C0;
        if (!(D_8009B210 & 0x80)) {
            D_8009B210 |= 0x80;
            D_8009B20C[1] = 32;
        }
        if (!(D_8009B210 & 0x40)) {
            timer = *(u16 *)&D_8009B20C[1] - 1;
            D_8009B20C[1] = timer;
            if ((s32)((u32)timer << 16) <= 0) {
                D_8009B210 |= 0x40;
                func_8001944C(object);
                D_800E9EF0.slots[0] =
                    func_80019564(
                        (DisplayObjectConfigView *)object);
                D_800E9EF0.slots[0]->attribute |= 0x50000000;
                D_800E9EF0.slots[0]->attribute &= ~0x08000000;
                D_800E9EF0.slots[1] =
                    func_80019564(
                        (DisplayObjectConfigView *)object);
                func_800428EC(D_800E9EF0.slots[1], -1);
                D_800E9EF0.slots[1]->attribute |= 0x60000000;
                D_800E9EF0.slots[1]->attribute &= ~0x08000000;
                func_80029528(1);
            }
        } else {
            DisplayObject *first = D_800E9EF0.slots[0];
            DisplayObject *second = D_800E9EF0.slots[1];
            value = first->field_44.h.field_44 + 128;
            second->field_44.h.field_46 = value;
            second->field_44.h.field_44 = value;
            first->field_44.h.field_46 = value;
            first->field_44.h.field_44 = value;
            value = *(u8 *)&D_800E9EF0.slots[0]->field_0C;
            value -= 4;
            if (value < 0)
                value = 0;
            value = value | ((value << 16) | (value << 8));
            D_800E9EF0.slots[0]->field_0C = value;
            D_800E9EF0.slots[1]->field_0C = value;
            if (!value) {
                func_8004036C(D_800E9EF0.slots[0]);
                func_8004036C(D_800E9EF0.slots[1]);
                D_8009B210 = 3;
            }
        }
        break;
    case 3: {
        u16 state = D_8009B210;
        u16 *rects = D_800EA128;
        u8 *data;
        card = &D_801A7AD8[D_8009B19C];
        if (!(state & 0x80)) {
            u16 ritual;
            u16 y;
             


            *(u16 *)card->data = ritual = D_8009B1A0;
            data = *(u8 **)&card->data;
            D_8009B210 = state | 0x80;
            card->card_id = ritual;
            value = data[3];
            y = rects[21];
            rects[4] = rects[20] + 56;
            rects[6] = 8;
            rects[7] = 88;
            rects[5] = y;
            func_8007F9D8((RECT *)&rects[4],
                (u32 *)(D_8018C2D8 + 1408 * value));
            break;
        }
        func_80024D34(D_8009B19C, ((s8 *)card->data)[2]);
        object = card->object;
        D_800E9EF0.slots[0] = object;
        *(s16 *)&object->field_30.h.field_32 = -240;
        if (D_8009B360[D_8009B1D5] >= 0) {
            card->flags &= ~0x200;
            if (func_8008E590() & 1)
                card->flags |= 0x200;
            goto state_five;
        }
        D_800E9EF0.slots[1] = (DisplayObject *)func_80017F04(card, 134, 240);
        D_8009B210 = 4;
    }
    case 4:
        object = D_800E9EF0.slots[1];
        if (!(D_8009B210 & 0x80)) {
            D_8009B210 |= 0x80;
            object->position.h.field_28 = 134;
            object->position.h.field_2A = 42;
            object->field_2C.h.field_2C = 16;
            object->field_6C = 1;
            object->update = func_8001EC70;
        } else if (!(D_8009B210 & 0x40)) {
            if (!func_80042B40(1)) {
                D_8009B338 =
                    D_8015C424_cards.field_cards[object->field_6A].card_id;
                text = func_80035C38(0, 33, 72, 110, 176, 48, 32);
                text->field_5A = 8;
                text->field_5B = 16;
                do {
                    func_80039794();
                } while (!text->field_30);
                D_8009B210 |= 0x40;
            }
        } else if (!(D_8009B210 & 0x20)) {
            if (!func_8003700C(D_800EB0F8) &&
                (D_8009B398 & 0xC0)) {
                func_8003FEE0(7);
                object->position.h.field_28 = 134;
                *(s16 *)&object->position.h.field_2A = -128;
                object->field_2C.h.field_2C = 16;
                object->field_6C = 1;
                object->update = func_8001EC70;
                card = &D_801A7AD8[object->field_6A];
                flags = card->flags & ~0x200;
                card->flags = flags;
                if (D_8009B34D)
                    card->flags = flags | 0x200;
                func_80035B7C(D_800EB0F8);
                D_8009B210 |= 0x20;
            }
        } else if (!func_80042B40(1)) {
            func_8004036C(object);
state_five:
            D_8009B210 = 5;
        }
        break;
    case 5: {
        s16 phase;
        object = D_800E9EF0.slots[0];
        if (!(D_8009B210 & 0x80)) {
            D_8009B210 |= 0x80;
            func_80043178((DisplayObjectSnapshot *)object);
            object->field_60 = -1024;
        }
        func_80043230((DisplayObjectPosition *)object,
            (s16)object->field_30.h.field_30, -24, object->field_60);
        phase = (u16)object->field_60 + 42;
        object->field_60 = phase;
        if (phase >= 0) {
            *(s16 *)&object->field_30.h.field_32 = -24;
done:
            D_8009B220 = 0;
        }
        break;
    }
    }
}
