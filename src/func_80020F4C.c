/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/duel_result_runtime.c (DuelScene_UpdateResultOutro), profile gcc_2_8_1_g8_split.
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
s32 func_8004002C(void);
void *func_800400AC(s32 index, s32 key);
extern u8 D_801AF000[];
void *func_80042B40(s32 value);
void func_800428A8(
    DisplayObject *object,
    s32 arg1,
    s32 arg2,
    s32 arg3,
    s32 arg4,
    s32 arg5,
    s32 arg6,
    s32 arg7,
    void *resource
);
void func_80042918(DisplayObject *object);
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
extern u16 D_8009B23A;
extern u16 D_801799D8[];
extern int  func_8008E590(void);
void func_8001EC70(DisplayObject *object);
extern volatile u16 D_8009B398 __attribute__((section(".data")));
s32 func_800358FC(s32 divisor);
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
extern DisplayObject *D_8009B214;
extern DisplayObject *D_8009B21C;
FileTransferDescriptor *func_80014E1C(
    s32, u8 *, s32, s32, FileTransferCallback, s32, s32
);
extern volatile u32 D_8009B0F4_abs __attribute__((section(".data")));
extern u32 D_8009B134_abs __attribute__((section(".data")));
void func_80020BE4(FileTransferDescriptor *descriptor, s32 mode);
void func_8003FF08(u32);
void func_8003FF34(void);
s32 func_8004703C(void);
void func_800472A8(s32 arg0);
extern FadeTransitionState D_800E9EC8;
extern u8 D_8009B165;
extern s8 D_8009B238;
extern u8 D_8009B362 __attribute__((section(".data")));
extern s8 D_8009B361 __attribute__((section(".data")));
void func_80020D4C(DisplayObject *object);
void func_80020EE8(DuelCardDisplayObject *object);
typedef struct {
    u8 x;
    u8 y;
    u8 kind;
    u8 tag;
} DuelResultSpriteSpec;
typedef struct {
    DisplayObject *object;
    u8 pad_04[0xC - 4];
} DuelResultSpriteSlot;
extern u16 D_8009B1E0;
void func_80020F4C(void);
extern DuelResultSpriteSpec D_80090928[][7 ];
extern DuelResultSpriteSpec D_80090960[][7 ];
struct DisplayObject;
extern u16 D_8009B162;
extern u16 D_8009B23A;
extern u8 D_8009B174;
extern u16 D_8009B1D0;
extern 
extern 
void func_80020F4C(void)
{
    DuelResultSpriteSlot *slots;
    DisplayObject *obj;
    DuelResultSpriteSpec *spec;
    s32 i;
    s32 flags;
    s32 state;
    s32 id;
    s32 timer;
    s32 mode;
    s32 v;

    slots = (DuelResultSpriteSlot *)D_801799D8;

    v = D_8009B23A;
    if ((v & 0x8000 ) == 0) {
        D_8009B23A = v | 0x8000 ;
        func_8003FF34();
        id = D_8009B165;
        D_8009B362 = 0;
        if (id != 0) {
            D_8009B362 = 1;
        }
        D_8009B238 = id;
        func_80014E1C(
            0, 0,
            0x1DAB ,
            0x22 ,
            func_80020BE4, 0, 0
        );
        mode = 0x72E0;
        if (D_8009B165 != 0) {
            if (D_8009B361 >= 0) {
                mode = 0x72F0;
            }
        }
        obj = D_8009B214;
        D_8009B1E0 = mode;
         




        *(s16 *)&obj->position.h.field_28 = -116;
        obj->field_2C.h.field_2C = 0x30;
        obj->field_6C = 1;
        obj->update = (DisplayObjectCallback)func_8001EC70;
        obj->position.h.field_2A = (s16)obj->field_30.h.field_32;
        obj = D_8009B21C;
        obj->position.h.field_28 = 0x198;
        obj->field_2C.h.field_2C = 0x30;
        obj->field_6C = 1;
        obj->update = (DisplayObjectCallback)func_8001EC70;
        D_8009B174 = 1;
        obj->position.h.field_2A = (s16)obj->field_30.h.field_32;
        return;
    }

    if (D_8009B162 != 0) {
        return;
    }

    flags = D_8009B174;
    state = flags & 0xF;
    switch (state) {
    case 1:
        if ((flags & 0x80) == 0) {
            if ((D_8009B0F4_abs & 0x02000030 ) |
                D_8009B134_abs) {
                return;
            }
            D_8009B174 = flags | 0x80;
            D_8009B162 = 8;
            id = D_8009B361;
            if (id < 0) {
                id = 1;
            }
            func_80014E1C(
                0, 0,
                id * 3  + 0x1D33 ,
                3 , 0, 0,
                (s32)((u8 *)slots - 0x1800));
            func_800472A8(D_8009B1E0);
        } else {
            if ((D_8009B0F4_abs & 0x02000030 ) |
                D_8009B134_abs) {
                return;
            }
            D_8009B174 = 2;
            func_8003FF08(D_8009B1E0);
        }
        break;
    case 2:
        if ((flags & 0x80) == 0) {
            D_8009B174 = flags | 0x80;
            for (i = 0; i < 7 ; i++) {
                if (D_8009B361 >= 0) {
                    spec = &D_80090928[D_8009B165][i];
                } else {
                    spec = &D_80090960[D_8009B165][i];
                }
                slots[i].object = 0;
                if (spec->kind != 0) {
                    obj = func_800400AC(func_8004002C(), 2);
                    func_800428A8(obj, spec->x, spec->y, 0,
                                  D_8009B165, spec->kind, 0x11, 9,
                                  D_801AF000);
                    if (obj->field_69 >= 0x1A) {
                        obj->field_40.h.field_40 =
                            (u16)obj->field_40.h.field_40 + 0x10;
                    }
                    obj->flags |= 0x20  |
                                  0x08 ;
                    obj->attribute |= ((1<<30)  | (1<<28) );
                    obj->field_48.h.field_48 = spec->tag;
                    obj->field_48.h.field_4A = 0x18;
                    func_80042918(obj);
                    obj->field_2C.word = obj->field_30.word;
                    obj->position.h.field_28 = (func_8008E590() & 0x3F) + 0x140;
                    obj->position.h.field_2A =
                        func_800358FC(0x1000 );
                    obj->field_6C = 1;
                    obj->update =
                        (DisplayObjectCallback)func_80020D4C;
                    slots[i].object = obj;
                }
            }
        } else {
            if ((D_8009B0F4_abs & 0x02000030 ) |
                D_8009B134_abs) {
                return;
            }
            if (func_80042B40(1) == 0) {
                D_8009B174 = 3;
            }
        }
        break;
    case 3:
        if ((flags & 0x80) == 0) {
            D_8009B174 = flags | 0x80;
            D_8009B1D0 = 0x258;
        }
        if ((D_8009B174 & 0x40) == 0) {
            timer = D_8009B1D0 - 1;
            D_8009B1D0 = timer;
            if ((s16)timer > 0) {
                if ((D_8009B398 &
                     (0x20   | (0x40  | 0x80 ) )) == 0) {
                    if ((func_8004703C() & 0x80) != 0) {
                        return;
                    }
                }
            }
            D_8009B174 = D_8009B174 | 0x40;
            for (i = 0; i < 7 ; i++) {
                obj = slots[i].object;
                if (obj != 0) {
                    obj->field_6C = 1;
                    obj->update = (DisplayObjectCallback)func_80020EE8;
                }
            }
        } else {
            if (func_80042B40(1) == 0) {
                D_8009B174 = 4;
            }
        }
        break;
    case 4:
        if ((flags & 0x80) == 0) {
            D_8009B174 = flags | 0x80;
        }
        if ((D_800E9EC8.flags & 0x80 ) == 0) {
            D_8009B23A = 0xD;
        }
        break;
    }
}
