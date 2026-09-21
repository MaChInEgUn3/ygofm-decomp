/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/debug_effect_screen.c, profile gcc_2_8_1_g8_split.
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
u8 *func_800291E0(s32 index, s32 x, s32 y);
void func_80029528(s32 index);
struct DisplayObject;
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
void func_800137E4(void);
FileTransferDescriptor *func_80029164(s32 slot, s32 value);
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
void func_80012D84(s32 count);
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
void func_8001944C(DisplayObject *object);
extern ;
extern volatile u16 D_8009B398 __attribute__((section(".data")));
extern volatile u16 D_8009B3A4 __attribute__((section(".data")));
extern volatile u16 D_8009B394 __attribute__((section(".data")));
u8 *func_80017F04(DuelCardRecord *arg0, s32 arg1, s32 arg2);
extern u16 D_8009B23A;
extern u16 D_8009B23A;
extern u16 D_800908A0[];
extern u8 D_8009B16C[4];
extern u8 gDebugEffect_abPreviewState[6];
extern u8 *D_8009B180;
extern u8 *D_8009B184;
extern DuelCardRecord D_801A7B80[];
u8 gDebugEffect_abPreviewState[6] __attribute__((section(".sdata"))) = {0};
void func_800220B8(void);
void func_800222F4(void) {
    DisplayObject *obj;
    DuelEffectRequest *p;

    if (D_8009B3A4 & 0x800 ) {
        func_800220B8();
    }
    if ((D_8009B23A & 0x8000 ) == 0) {
        D_8009B23A |= 0xC000;
        D_8009B16C[2] = 0;
        gDebugEffect_abPreviewState[4]  = 0;
        gDebugEffect_abPreviewState[0]  = 0;
        (&gDebugEffect_abPreviewState[2]) [1] = 0;
        D_8009B184 = 0;
        D_8009B180 = 0;
    }
    if (D_8009B23A & 0x4000) {
        D_8009B23A &= 0xBFFF;
        func_80029528(0);
        func_8004036C(D_8009B180);
        func_8004036C(D_8009B184);
        D_8009B184 = 0;
        D_8009B180 = 0;
        switch (gDebugEffect_abPreviewState[4] ) {
        case 0:
            break;
        case 1:
            func_80029164(0, 1);
            func_800137E4();
            obj = (DisplayObject *)func_800291E0(0, -1, -1);
            obj->field_30.h.field_30 = 0x5A;
            obj->field_30.h.field_32 = 0x16;
            func_80012D84(4);
            func_8001944C(obj);
            break;
        case 2:
            D_8009B180 = func_80017F04(D_801A7B80, 0x86, 0x52);
            break;
        case 3:
            D_8009B180 = func_80017F04(D_801A7B80, 0x5C, 0x52);
            D_8009B184 = func_80017F04(&D_801A7B80[1], 0xB0, 0x52);
            break;
        }
    } else if (D_8009B398 & 0x100 ) {
        D_8009B23A |= 0x4000;
        gDebugEffect_abPreviewState[4] ++;
        if (gDebugEffect_abPreviewState[4]  >= 4) {
            gDebugEffect_abPreviewState[4]  = 0;
        }
    } else if (D_8009B398 & (0x8000  | 0x2000 )) {
        gDebugEffect_abPreviewState[0]  ^= 1;
    } else if (D_8009B394 & (0x1000  | 0x4000 )) {
        (&gDebugEffect_abPreviewState[2]) [gDebugEffect_abPreviewState[0] ]++;
        if (D_8009B394 & 0x4000 ) {
            (&gDebugEffect_abPreviewState[2]) [gDebugEffect_abPreviewState[0] ] -= 2;
        }
    } else if (D_8009B398 & 0x40 ) {
        p = (DuelEffectRequest *)func_8002C604(
            (&gDebugEffect_abPreviewState[2]) [0]);
        D_8009B16C[2] = (D_8009B16C[2] + 1) & 7;
        p->field_1A = (&gDebugEffect_abPreviewState[2]) [1];
        switch (gDebugEffect_abPreviewState[4] ) {
        case 0:
            p->field_00 = D_800908A0[0xC];
            p->field_02 = -0x18;
            p->field_04 = D_800908A0[0xD];
            break;
        case 1:
            p->field_00 = 0xA0;
            p->field_02 = 0x78;
            break;
        case 2:
            p->field_00 = 0xA0;
            p->field_02 = 0x70;
            break;
        case 3:
            p->field_00 = 0xA0;
            p->field_02 = 0x70;
            break;
        }
    }
}
