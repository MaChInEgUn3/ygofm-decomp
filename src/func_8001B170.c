/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/func_8001B170.c, profile gcc_2_8_1_g8_split.
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
extern u16 D_8009B23A;
extern u8 D_800EAE8F[];
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
extern DisplayObject *D_800E9EF0[];
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
void func_80043230(
    DisplayObjectPosition *object,
    int target_x,
    int target_y,
    int phase);
struct DisplayObject;
void func_8004036C(void *object);
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
void func_80018080(DuelCardDisplayObject *object);
typedef struct {
    s16 id;
     

    s8 deck_index;
    u8 data_block_index;
    u8 flags_04;
    u8 unk_05;
} DuelDeckCardRecord;
typedef struct {
    u8 pad_00000[0x4B6B4];
    DuelCardRecord field_cards[30 ];
    DuelDeckCardRecord cards[(40  * 2) ];
} DuelCardStagingDeckView;
extern u8 D_8015C424[];
extern DuelCardStagingDeckView D_8015C424_cards asm("D_8015C424");
void func_80024D34(s32 slot, s32 card_id);
extern u8 D_8009B1D5;
extern u8 D_8009B19C;
extern s16 D_8009B154;
extern s8 D_8009B360[2 ] __attribute__((section(".data")));
void func_8001B170(void);
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
extern u16 D_8009B210;
s32 func_8001F364(void);
extern ;
s16 func_8001B0CC(s32 index);
extern s8 D_8009B34D __attribute__((section(".data")));
struct DuelEffectChannel;
s32 func_8003700C(struct DuelEffectChannel *record);
struct DuelEffectChannel;
void func_80035B7C(struct DuelEffectChannel *record);
void *func_80035C38(
    s32 index, s32 string_id, s32 x, s32 y, s32 width, s32 height, s32 flags
);
void func_80039794(void);
s32 func_80025028(s32 card_id);
void func_8003B6AC(s32 range, s32 layout);
extern ;
extern u16 D_8009B398 __attribute__((section(".data")));
void func_8003FEE0(u32);
extern u16 D_8009B23A;
extern u8 D_8009B174;
struct DuelEffectChannel;
void func_8001B170(void)
{
    DisplayObject *object;
    DuelEffectChannel *box;
    DuelCardRecord *card;
    DuelCardRecord *scratch;
    DuelEffectRequest *request;
    u16 flags;
    u16 z;
    s32 slot;

    object = D_800E9EF0[0];
    if (!(D_8009B23A & 0x8000 )) {
        D_8009B23A |= 0x8000 ;
        if (D_8009B23A & 0x4000) {
            goto state_four;
        }
        if (D_8009B360[D_8009B1D5] >= 0 &&
            object->field_68 < 0x14) {
            D_801A7AD8[object->field_6A].flags &= ~0x200;
            if (D_800EAE8F[0] & 1) {
                D_801A7AD8[object->field_6A].flags |= 0x200;
            }
            goto state_four;
        }
        D_8009B174 = 1;
        func_80043178(((DisplayObjectSnapshot *)( object )) );
        object->field_60 = 0;
        if ((s16)object->field_30.h.field_30 == 0x86 ||
            (s16)object->field_30.h.field_32 == 0x2A) {
            D_8009B174 = 2;
            return;
        }
    }

    switch (D_8009B174 & 0xF) {
    case 1:
        func_8004318C(
            ((DisplayObjectPosition *)( object )) ,
            0x86, 0x2A, object->field_60);
        object->field_60 += 0x80;
        if (object->field_60 < 0x800) {
            break;
        }
        object->field_30.h.field_30 = 0x86;
        object->field_30.h.field_32 = 0x2A;
        D_8009B174 = 2;
         
    case 2:
        if (object->field_68 >= 0x14) {
            goto state_four;
        }
        D_8009B174 = 3;
         
    case 3:
        if (!(D_8009B174 & 0x80)) {
            D_8009B174 |= 0x80;
            D_8009B338 =
                D_8015C424_cards.field_cards[object->field_6A].card_id;
            func_8003B6AC(0, 0xB);
            box = func_80035C38(0, 0x21, 0x48, 0x6E, 0xB0, 0x30, 0x20);
            box->field_5A = 8;
            box->field_5B = 0x10;
            do {
                func_80039794();
            } while (box->field_30 == 0);
            break;
        }
        if (D_8009B174 & 0x10) {
            D_801A7AD8[object->field_6A].flags &= ~0x200;
            if (D_8009B34D) {
                D_801A7AD8[object->field_6A].flags |= 0x200;
            }
            func_80035B7C(D_800EB0F8);
state_four:
            D_8009B174 = 4;
            break;
        }
        if (!func_8003700C(D_800EB0F8) &&
            (D_8009B398 & 0xC0)) {
            func_8003FEE0(7);
            D_8009B174 |= 0x10;
        }
        break;
    case 4:
        if (!(D_8009B174 & 0x80)) {
            D_8009B174 |= 0x80;
            object->field_2C.h.field_2E = func_8001B0CC(D_8009B19C) - 0x1E;
            func_80043178(((DisplayObjectSnapshot *)( object )) );
            object->field_60 = 0x400;
        }
        if (!(D_8009B174 & 0x40)) {
            func_80043230(((DisplayObjectPosition *)( object )) ,
                             object->field_2C.h.field_2E, -0xBC,
                             object->field_60);
            object->field_60 -= 0x2A;
            if (object->field_60 > 0) {
                break;
            }
            D_8009B174 |= 0x40;
            scratch = (DuelCardRecord *)0x1F800000;
            *scratch = D_801A7AD8[object->field_6A];
            func_80024D34(D_8009B19C, object->field_6B);
            card = &D_801A7AD8[D_8009B19C];
            flags = card->flags | (scratch->flags & 0x7E00);
            card->flags = flags & ~0x400;
            if (!(flags & 0x1000)) {
                card->flags = flags & ~0x2400;
            }
            card->stat_modifier = scratch->stat_modifier;
            func_8004036C(object);
            D_800E9EF0[0] = card->object;
            object = D_800E9EF0[0];
            func_80018080((DuelCardDisplayObject *)object);
            ((DisplayObjectPosition *)( object )) ->out_y = -0xF0;
            func_80043178(((DisplayObjectSnapshot *)( object )) );
            object->field_60 = -0x400;
            break;
        }
        func_80043230(((DisplayObjectPosition *)( object )) ,
                         (s16)object->field_30.h.field_30, -0x18,
                         object->field_60);
        object->field_60 += 0x2A;
        if (object->field_60 < 0) {
            break;
        }
        ((DisplayObjectPosition *)( object )) ->out_y = -0x18;
        D_8009B174 = 5;
        func_8003FEE0(0xC);
        break;
    case 5:
        if (D_8009B154 &&
            func_80025028(689 )) {
            D_8009B174 = 6;
            break;
        }
        D_8009B23A = 5;
        break;
    case 6:
        if (!(D_8009B174 & 0x80)) {
            D_8009B174 |= 0xC0;
            D_8009B210 = 0;
        }
        if (D_8009B174 & 0x40) {
            if (func_8001F364()) {
                break;
            }
            request = func_8002C68C(0xD);
            request->field_00 = object->field_30.h.field_30;
            request->field_02 = object->field_30.h.field_32;
            z = object->field_34.h.field_34;
            request->field_12 = -D_8009B154;
            request->field_04 = z;
            func_8003FEE0(0x21);
            D_8009B174 &= ~0x40;
            break;
        }
        slot = object->field_6A;
        D_8009B23A = 5;
        card = &D_801A7AD8[slot];
        card->stat_modifier -= D_8009B154 * 2;
        break;
    }
}
