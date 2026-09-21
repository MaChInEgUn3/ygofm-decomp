/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/duel_card_effects.c (DuelEffect_ApplyStatPenalty), profile gcc_2_8_1_g8_split.
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
extern u16 D_8009B1D0;
extern u8 D_800907D8_flat[] asm("D_800907D8");
void func_80025D30(void);
extern u8 D_8009B1D5;
extern u16 D_8009B220;
extern s16 D_8009B1D2;
extern s16 D_8009B20C[2];
s32 func_80024E24(void);
u8 *func_8002C604(s32 id);
extern u8 D_8009B260 __attribute__((section(".data")));
void func_8003FEE0(u32);
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
    u16 x;              
    u16 y;              
    u16 field_04;       
    u8 pad_06[0xC];     
    s16 field_12;       
    s32 field_14;       
    u8 pad_18[2];       
    s16 field_1A;       
} DuelEffectObject;
void func_80025D30(void) {
    DuelCardRecord *record;
    DuelEffectObject *object;
    DisplayObject *card;
    s32 timer;
    s32 base_slot;

    if (func_80024E24() == 0) {
        D_8009B20C[1] = 0;
        D_8009B1D0 = 0;
    }

    if ((D_8009B220 & 0x40) != 0) {
        if ((D_8009B260 & 1) == 0) {
            D_8009B220 = 0;
        }
        return;
    }

    timer = *(u16 *)&D_8009B20C[1] - 1;
    D_8009B20C[1] = timer;
    if ((s16)timer > 0) {
        return;
    }
    D_8009B20C[1] = 0x10;

    base_slot = D_8009B1D5 * 20  +
                5 ;
    record = &D_801A7AD8[D_800907D8_flat[(s16)D_8009B1D0 + base_slot]];
    if ((record->flags & 0x8000 ) != 0) {
        card = ((DisplayObject *)( record->object )) ;
        object = (DuelEffectObject *)func_8002C604(0xD);
        object->x = card->field_30.h.field_30;
        object->y = card->field_30.h.field_32;
        object->field_04 = *(u16 *)&card->field_34;
        object->field_14 = object->field_14 + ((s16)D_8009B1D0 << 14);
        if (D_8009B1D2 == 349 ) {
            object->field_1A = 2;
            record->stat_modifier =
                record->stat_modifier - 500 ;
            object->field_12 = - 500 ;
        } else {
            object->field_1A = 1;
            record->stat_modifier =
                record->stat_modifier - 2 * 500 ;
            object->field_12 = -2 * 500 ;
        }
        func_8003FEE0(0x21);
    }

    D_8009B1D0 = D_8009B1D0 + 1;
    if ((s16)D_8009B1D0 >= 5 ) {
        D_8009B220 = D_8009B220 | 0x40;
    }
}
