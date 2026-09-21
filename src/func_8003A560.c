/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/display_effect_resource_setup.c, profile gcc_2_8_1_g8_split.
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
	short x, y;		 
	short w, h;		 
} RECT;
extern int func_8007F978(RECT *rect, u32 *p);
extern int func_8007F9D8(RECT *rect, u32 *p);
extern int func_80082324(int max_count);
typedef struct {
     


























    s32 grid[4][3];
    s8 field_30;
     


    u8 field_31;
    u8 field_32;
    u8 display_effect_step;
    u16 field_34;
     




    u16 field_36;
    u8 pad_38[2];
    u8 field_3A;
    u8 field_3B;
     



    u8 field_3C;
    u8 pad_3D;
     



    u16 field_3E;
     




















    s16 field_40;
    s16 field_42;
    s16 field_44;
    s16 field_46;
    s16 field_48;
    s16 field_4A;
} MenuRecord;
typedef struct {
    u8 pad_00[0x31];
    u8 field_31;
    u8 field_32;
    u8 state;
    u16 field_34;
    u16 field_36;
    u8 pad_38[0x06];
    u16 field_3E;
} DisplayEffectState;
s32 func_80039F1C(DisplayEffectState *object);
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
extern u8 D_801AF000[];
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
FileTransferDescriptor *func_80014EEC(
    s32, u8 *, s32, s32, FileTransferCallback, s32, s32
);
extern volatile u32 D_8009B0F4_abs __attribute__((section(".data")));
extern u32 D_8009B134_abs __attribute__((section(".data")));
void func_800356A0(u8 *destination, u8 *source, u32 length);
void func_8003A01C(
    FileTransferDescriptor *descriptor, s32 mode);
extern 
s32 func_8003A1EC(
    MenuRecord *record, DisplayObject **out, s32 resource_index);
typedef struct {
    u8 pad_00[0x30];
    s8 field_30;
    u8 field_31;
    u8 field_32;
    u8 state;
    u16 field_34;
    u16 field_36;
    u8 pad_38[0x04];
    u8 field_3C;
    u8 pad_3D;
    u16 field_3E;
} DisplayEffectVramState;
typedef struct {
    u8 image[0x18000];
    u8 clut[0x400];
    u8 extra[0x800];
    RECT image_rect;
    RECT clut_rect;
} DisplayEffectVramSlot;
extern s8 D_8009B326;
extern s8 D_8015C410[];
void func_8003A560(DisplayEffectVramState *state);
extern u8 D_801AF800[];
extern u8 *D_80010000 __attribute__((section(".data")));
extern 
void func_8003A560(DisplayEffectVramState *a)
{
    DisplayEffectVramSlot *slots;
    DisplayEffectVramSlot *slot;
    FileTransferDescriptor *req;
    s32 i;

    if (func_80039F1C((DisplayEffectState *)a) == 0) {
        slots = (DisplayEffectVramSlot *)D_80010000;
        D_8009B326 = 0;
         



        slot = &slots[5  - 1];
        for (i = 5  - 1; i >= 0; i--) {
            if (D_8015C410[i] < 0) {
                D_8009B326 = i;
            }
            if (D_8015C410[i] == a->field_30) {
                while (func_80082324(10) != 0) {
                    ;
                }
                slot->image_rect.x = 832 - a->field_3C * 192;
                slot->image_rect.y = 256;
                slot->image_rect.w = 192;
                slot->image_rect.h = 256;
                func_8007F978(&slot->image_rect, (u32 *)slot->image);
                slot->clut_rect.x = 512;
                slot->clut_rect.y = a->field_3C * 2 + 240;
                slot->clut_rect.w = 256;
                slot->clut_rect.h = 2;
                func_8007F978(&slot->clut_rect, (u32 *)slot->clut);
                if (a->field_3C != 0) {
                    func_800356A0(D_801AF800, slot->extra, 0x800);
                } else {
                    func_800356A0(D_801AF000, slot->extra, 0x800);
                }
                a->state |= 0x40;
                return;
            }
            slot--;
        }
        if (((D_8009B0F4_abs & 0x02000030 ) |
             D_8009B134_abs) != 0) {
            a->state &= 0x7F;
            return;
        }
        req = func_80014EEC(
            0, 0, a->field_30 * 50 + 15182, 50, func_8003A01C, 0, 0
        );
        req->callback_data = D_801AF000;
        req->position = a->field_3C;
        if (a->field_3C != 0) {
            req->callback_data = D_801AF800;
        }
        D_8009B0F4_abs = req->status_flags | 0x10 ;
    } else if ((a->state & 0x40) == 0) {
        if (((D_8009B0F4_abs & 0x02000030 ) |
             D_8009B134_abs) != 0) {
            return;
        }
        a->state |= 0x40;
        D_8015C410[D_8009B326] = a->field_30;
        while (func_80082324(10) != 0) {
            ;
        }
        slot = &((DisplayEffectVramSlot *)D_80010000)[D_8009B326];
        slot->image_rect.x = 832 - a->field_3C * 192;
        slot->image_rect.y = 256;
        slot->image_rect.w = 192;
        slot->image_rect.h = 256;
        func_8007F9D8(&slot->image_rect, (u32 *)slot->image);
        slot->clut_rect.x = 512;
        slot->clut_rect.y = a->field_3C * 2 + 240;
        slot->clut_rect.w = 256;
        slot->clut_rect.h = 2;
        func_8007F9D8(&slot->clut_rect, (u32 *)slot->clut);
        if (a->field_3C != 0) {
            func_800356A0(slot->extra, D_801AF800, 0x800);
        } else {
            func_800356A0(slot->extra, D_801AF000, 0x800);
        }
    } else {
        func_8003A1EC(
            (MenuRecord *)a, (DisplayObject **)a, a->field_31);
        a->state = 0;
        a->field_32 |= 0x40;
    }
}
