/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/func_800283F4.c (DuelEffect_UpdateCardViewerState), profile gcc_2_8_1_g8_split.
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
int func_800282E8(void);
typedef struct {
	short x, y;		 
	short w, h;		 
} RECT;
extern volatile u8 D_8009B0C0 __attribute__((section(".data")));
void func_80029574(s32 index);
extern volatile u16 D_8009B398 __attribute__((section(".data")));
extern volatile u16 D_8009B39A __attribute__((section(".data")));
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
extern u8 D_8009B140 __attribute__((section(".data")));
void func_80015BD8(s32, s32);
extern DuelEffectChannel D_800EB0F8[4 ];
extern s16 D_8009B338 __attribute__((section(".data")));
extern u8 D_8009B248;
extern u8 D_8009B248;
extern u8 D_8009B254;
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
extern u16 D_8009B246;
extern DisplayObject *D_8009B240;
extern u8 D_8009B24B;
extern DisplayObject *D_8009B24C;
extern DuelEffectChannel *D_8009B250;
extern DisplayObject *D_8009B240;
extern DisplayObject *D_8009B24C;
extern DuelEffectChannel *D_8009B250;
struct DuelEffectChannel;
void func_80035B7C(struct DuelEffectChannel *record);
void *func_80035BE4(
    s32 index, s32 string_id, s32 x, s32 y, s32 width, s32 height
);
void func_8003FEE0(u32);
struct DisplayObject;
s32 func_8004002C(void);
void *func_800400AC(s32 index, s32 key);
void func_8004036C(void *object);
void func_800404CC(
    void *object, s32 x, s32 y, s32 field_67, s32 field_68,
    s32 field_69, s32 color, s32 texture
);
extern volatile u16 D_8009AF74[4] __attribute__((section(".data")));
s32 func_800428EC(DisplayObject *object, s8 value);
void func_80042918(DisplayObject *object);
u8 *func_800291E0(s32 index, s32 x, s32 y);
void func_80029528(s32 index);
extern volatile u32 D_8009B0F4_abs __attribute__((section(".data")));
extern u32 D_8009B134_abs __attribute__((section(".data")));
FileTransferDescriptor *func_80029164(s32 slot, s32 value);
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
struct DuelEffectChannel;
void func_80039934(struct DuelEffectChannel *record, s32 x, s32 y);
void func_80039A14(struct DuelEffectChannel *object);
extern s32 D_801D4244[];
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
void func_800283F4(void);
struct DuelEffectChannel;
extern u8 D_8009B26C __attribute__((section(".data")));
void func_800283F4(void)
{
    s32 slide_in;
    s32 slide_out;
    DisplayObject *obj;
    DisplayObject *bg;
    DuelEffectResourceRecord *p;
    DisplayObject *next_obj;
    s32 *stats;
    DuelEffectChannel *box;
    DuelEffectChannel *chan;
    DuelEffectChannel *pos_box;
    DuelEffectChannel *dead_box;
    s32 adj;
    s32 i;
    s32 kind;
    s32 masked;
    s32 speed;
    s32 test;
    u16 flags;
    u16 id;
    u16 objflags;
    u8 closing;
    u8 state;

    if (func_800282E8() == 0) {
        slide_in = -0x400;
        D_8009B0C0 = 1;
        func_80029574(3);
        p = &D_800EA0E8[0];
        p[3].src_y = 0x100;
        p[3].src_x = 0;
        p[3].field_2C = 0;
        p[3].field_2E = 0xFF;
        func_80029164(3, (s16)D_8009B246);
        obj = (DisplayObject *)func_800291E0(3, -1, -1);
        adj = D_8009B24B;
        *(s16 *)&obj->field_30.h.field_30 = -0x8C;
        obj->field_20.b.field_21 = 0x80;
        obj->field_30.h.field_32 += adj;
        obj->flags |= 0x04 ;
        func_80043178(((DisplayObjectSnapshot *)( obj )) );
        obj->field_60 = slide_in;
        func_80042918(obj);
        func_800428EC(obj, 0x14);
        D_8009B24C = obj;
        obj = func_800400AC(func_8004002C(), 2);
        func_800404CC((u8 *)obj, 0x148, D_8009B24B + 0xE, 0, 2, 0, 0xD, 0x107);
        obj->field_60 = slide_in;
        obj->flags |= 0x08 ;
        func_80042918(obj);
        func_800428EC(obj, 0x14);
        func_80043178(((DisplayObjectSnapshot *)( obj )) );
        obj->field_60 = slide_in;
        D_8009B240 = obj;
        D_8009B250 = 0;
        i = 0;
        stats = D_801D4244;
        chan = D_800EB0F8;
        for (; i < 3; i++, chan++) {
            if ((chan->flags_34 & 0x8000 ) == 0) {
                id = D_8009B246;
                D_8009B338 = id;
                kind = 3;
                if (((stats[(s16)id - 1] >> 26 ) &
                     0x1F ) >= 20 ) {
                    kind = 4;
                }
                box = func_80035BE4(i, kind, 0x148, 0xE, 0xA8, 0xC0);
                box->field_53 = 1;
                box->field_54 = 0;
                box->field_59 = 0x15;
                D_8009B250 = box;
                func_80039A14((struct DuelEffectChannel *)box);
                break;
            }
        }
        func_80015BD8(0x40, 2);
        D_8009B140 = *(u8 *)&D_8009AF74[1] - 0x13;
        func_8003FEE0(0x34);
        D_8009B248 |= 0x40;
        return;
    }

    state = D_8009B248;
    if (state & 0x40) {
        obj = D_8009B240;
        speed = obj->field_60;
        if (speed != 0) {
            if (state & 0x10) {
                func_80043230(((DisplayObjectPosition *)( obj )) ,
                                 0x148,
                                 *(s16 *)&obj->field_30.h.field_32,
                                 speed);
                flags = *(u16 *)&obj->field_60 - 0x55;
                obj->field_60 = flags;
                if ((s16)flags <= 0) {
                    *(s16 *)&obj->field_30.h.field_30 = 0x400;
                    obj->field_60 = 0;
                }
            } else {
                func_80043230(((DisplayObjectPosition *)( obj )) ,
                                 0x94,
                                 *(s16 *)&obj->field_30.h.field_32,
                                 speed);
                flags = *(u16 *)&obj->field_60 + 0x55;
                obj->field_60 = flags;
                if ((s16)flags >= 0) {
                    *(s16 *)&obj->field_30.h.field_30 = 0x94;
                    obj->field_60 = 0;
                }
            }
            pos_box = D_8009B250;
            if (pos_box != 0) {
                func_80039934(pos_box, *(s16 *)&obj->field_30.h.field_30,
                               *(s16 *)&obj->field_30.h.field_32);
            }
        }
        obj = D_8009B24C;
        speed = obj->field_60;
        if (speed != 0) {
            if (D_8009B248 & 0x10) {
                func_80043230(((DisplayObjectPosition *)( obj )) ,
                                 -0x8C,
                                 *(s16 *)&obj->field_30.h.field_32,
                                 speed);
                flags = *(u16 *)&obj->field_60 - 0x55;
                obj->field_60 = flags;
                if ((s16)flags <= 0) {
                    *(s16 *)&obj->field_30.h.field_30 = 0x400;
                    obj->field_60 = 0;
                }
            } else {
                func_80043230(((DisplayObjectPosition *)( obj )) ,
                                 2,
                                 *(s16 *)&obj->field_30.h.field_32,
                                 speed);
                flags = *(u16 *)&obj->field_60 + 0x55;
                obj->field_60 = flags;
                if ((s16)flags >= 0) {
                    *(s16 *)&obj->field_30.h.field_30 = 2;
                    obj->field_60 = 0;
                }
            }
        }
        if (((D_8009B0F4_abs & 0x02000030 ) |
             D_8009B134_abs) != 0) {
            return;
        }
        bg = D_8009B240;
        if (bg->field_60 != 0) {
            return;
        }
        if (D_8009B24C->field_60 != 0) {
            return;
        }
        closing = D_8009B248;
        masked = closing & 0xBF;
        test = closing & 0x10;
        D_8009B248 = masked;
        if (test == 0) {
            return;
        }
        func_8004036C(bg);
        func_80029528(3);
        dead_box = D_8009B250;
        if (dead_box != 0) {
            func_80035B7C(dead_box);
        }
        D_8009B0C0 = 0;
        D_8009B254 |= 0x40;
        return;
    }

    if ((state & 0x20) == 0) {
        obj = D_8009B24C;
        obj->field_20.b.field_21 += 0xC;
        if (obj->field_20.b.field_21 < 0x40) {
            objflags = obj->flags;
            obj->field_20.b.field_21 = 0;
            state = D_8009B248 | 0x20;
            obj->flags = objflags & 0xFFFB;
            D_8009B248 = state;
        }
        return;
    }

    if ((D_8009B26C & 0x1F) == 0xE) {
        if (((D_8009B398 | D_8009B39A) & 0x20) != 0) {
            goto press;
        }
        return;
    }
    if ((D_8009B398 & 0x20) == 0) {
        return;
    }
press:
    slide_out = 0x400;
    func_80043178(((DisplayObjectSnapshot *)( D_8009B240 )) );
    next_obj = D_8009B24C;
    D_8009B240->field_60 = slide_out;
    func_80043178(((DisplayObjectSnapshot *)( next_obj )) );
    D_8009B24C->field_60 = slide_out;
    func_80015BD8(0xFF, 2);
    func_8003FEE0(0x34);
    D_8009B248 |= 0x50;
}
