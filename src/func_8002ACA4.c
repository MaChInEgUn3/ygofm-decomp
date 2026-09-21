/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/library_runtime.c, profile gcc_2_8_1_g8_split.
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
typedef struct  {
	short	m[3][3];	 
        long    t[3];		 
} MATRIX;
typedef struct {		 
	long	vx, vy;
	long	vz, pad;
} VECTOR;
typedef struct {		 
	short	vx, vy;
	short	vz, pad;
} SVECTOR;
extern int func_80086770(int a);
extern int func_800866A0(int a);
typedef struct {
	short x, y;		 
	short w, h;		 
} RECT;
int func_80058DD8(int index);
typedef struct {
	VECTOR  scale;
	SVECTOR rotate;
	VECTOR  trans;
}       GsCOORD2PARAM;
typedef struct _GsCOORDINATE2 {
	unsigned long flg;
	MATRIX  coord;
	MATRIX  workm;
	GsCOORD2PARAM *param;
	struct _GsCOORDINATE2 *super;
	struct _GsCOORDINATE2 *sub;
}       GsCOORDINATE2;
typedef struct {
	long    vpx, vpy, vpz;
	long    vrx, vry, vrz;
	long    rz;
	GsCOORDINATE2 *super;
}       GsRVIEW2;
void    func_800857C0(long h);
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
void func_80014FA4(void);
extern volatile u32 D_8009B0F4_abs __attribute__((section(".data")));
extern u32 D_8009B134_abs __attribute__((section(".data")));
extern volatile u8 D_8009B0C0 __attribute__((section(".data")));
extern s16 D_8009B146 __attribute__((section(".data")));
extern s16 D_8009B148 __attribute__((section(".data")));
void func_8002ACA4(u8 *state);
void func_80058FB0(s32 idx, u16 *out);
typedef struct {
    s16 field_00;
    s16 angle;
    s16 field_04;
    s16 field_06;
    s16 field_08;
    s16 field_0A;
    s16 field_0C;
    s16 projection;
    GsRVIEW2 view;
} ViewState;
extern ViewState D_800F2848;
void func_8001352C(void);
extern ;
struct DuelEffectChannel;
extern u8 D_800E9ECE[];
extern u8 D_800E9ECF[];
void func_80057AF4(s32 index, s32 anim, s32 flag);
void func_80029EC4(void);
struct DisplayObject;
s32 func_8004002C(void);
void *func_800400AC(s32 index, s32 key);
void func_8004036C(void *object);
void func_800404CC(
    void *object, s32 x, s32 y, s32 field_67, s32 field_68,
    s32 field_69, s32 color, s32 texture
);
extern void (*D_800E9DB0[4])(void);
struct DuelEffectChannel;
void func_80035B7C(struct DuelEffectChannel *record);
void *func_80035BE4(
    s32 index, s32 string_id, s32 x, s32 y, s32 width, s32 height
);
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
s32 func_800428EC(DisplayObject *object, s8 value);
void func_80042918(DisplayObject *object);
void func_8003FEE0(u32);
void func_80047EC4(void);
struct DuelEffectChannel;
void func_80039934(struct DuelEffectChannel *record, s32 x, s32 y);
struct DisplayObject;
typedef struct {
    u8 pad_00[8];
    u16 flags;
    u8 pad_0A[0x5D];
    u8 field_67;
    u8 field_68;
    u8 field_69;
} DisplayObjectConfig;
void func_80040410(DisplayObjectConfig *object, s32 value);
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
extern DuelEffectChannel D_800EB0F8[4 ];
extern s16 D_8009B338 __attribute__((section(".data")));
FileTransferDescriptor *func_80029164(s32 slot, s32 value);
void func_80015C0C(void);
void func_80015C84();
u8 *func_800291E0(s32 index, s32 x, s32 y);
void func_80029528(s32 index);
void func_80029934(void);
DisplayObject *func_8002ABB4(DisplayObject *src, int add);
void func_80039794(void);
s32 func_80059AA8(s32 index, s32 value);
extern volatile u16 D_8009B398 __attribute__((section(".data")));
s32 func_80056504(
    s32 slot, s32 model, s32 p2, s32 p3, s32 p4, s32 p5, s32 arg6
);
s32 func_8005F1B8(s32 level, s32 value);
void func_80056828(s32 index);
void func_800530C4(void);
void func_800533D8(void);
void func_800595C8(s32 index, s32 x, s32 y, s32 z);
void func_800597C8(s32 idx, s32 flag, s32 val);
unsigned char *func_800591C0(unsigned int index, unsigned int light);
void func_80059AE0(s32 value);
void func_8002ACA4(u8 *state)
{
    DuelEffectResourceRecord *rec;
    u8 *o;
    u8 *light;
    u8 *box;
    s32 flags;
    s32 sel;
    s32 mode;
    s32 id;
    s32 i;
    s32 b;
    s32 a;
    s32 c;
    s32 layout;
    GsRVIEW2 *rv;
    u8 *p;
    ViewState *vs;
    s32 bits;
    s32 attr;

    rec = D_800EA0E8;
    flags = state[0];
    if (!(flags & 0x80)) {
        state[0] = flags | 0x80;
        state[1] = 0;
        state[3] = 0;
        state[4] = 1;
        func_800530C4();
        func_800533D8();
        D_800F2848.field_00 = 0x334;
        D_800F2848.angle = 0x400;
        D_800F2848.field_04 = 0xC4;
        D_800F2848.field_0C = 0;
        D_800F2848.view.rz = 0;
        D_800F2848.view.super = 0;
        D_800F2848.projection = 0x12C;
        func_800857C0(0x12C);
        rv = &D_800F2848.view;
        rv->vrx = 0;
        D_800F2848.field_06 = 0;
        rv->vry = 0;
        D_800F2848.field_08 = 0;
        rv->vrz = 0;
        D_800F2848.field_0A = 0;
        func_8001352C();
        func_80029164(0, (*(u16 *)((u8 *)( state ) + (  6 ))) );
        func_80015C84();
        D_800E9ECF[0] = 6;
        (*(s32 *)((u8 *)( state ) + (  0x50 )))  = 0;
        return;
    }
    func_80039794();
    mode = state[4];
    if ((mode & 0xF) && ((D_8009B0F4_abs & 0x02000030) | D_8009B134_abs) == 0) {
        if (mode == 1) {
            state[4] = 0;
            id = (*(u16 *)((u8 *)( state ) + (  6 )))  - 1;
            if (((D_801D4244[id] >> 0x1A) & 0x1F) < 0x14) {
                func_80056504(0, id, 0, 0, 0, 0, 4);
                (*(s32 *)((u8 *)( state ) + (  0x20 )))  = 0x12C;
                state[4] = 2;
            }
        } else {
            func_80056828(0);
            if (func_80058DD8(0) == 1) {
                state[4] = 0;
                o = func_800400AC(func_8004002C(), 2);
                func_800404CC(o, 0x130, 0xCD, 3, 0, 2, 0xB, 0x20C);
                (*(u16 *)((u8 *)( o ) + (  8 )))  |= 0x28;
                func_80042918(((DisplayObject *)( o )) );
                func_800428EC(((DisplayObject *)( o )) , 0xA);
                (*(s32 *)((u8 *)( state ) + (  0x50 )))  = (s32)o;
            }
        }
    }

    flags = state[3];
    switch (flags & 0xF) {
    case 1:
        o = (u8 *)(*(s32 *)((u8 *)( state ) + (  0x4C ))) ;
        if (!(flags & 0x80)) {
            state[3] = flags | 0x80;
            (*(s16 *)((u8 *)( o ) + (  0x30 )))  = 0x148;
            (*(s16 *)((u8 *)( o ) + (  0x32 )))  = 0xE;
            func_80043178((void *)o);
            (*(s16 *)((u8 *)( o ) + (  0x60 )))  = -0x400;
        }
        (*(u16 *)((u8 *)( o ) + (  0x60 )))  += 0x33;
        if ((*(s16 *)((u8 *)( o ) + (  0x60 )))  >= 0) {
            (*(s16 *)((u8 *)( o ) + (  0x30 )))  = 0x94;
            (*(s16 *)((u8 *)( o ) + (  0x32 )))  = 0xE;
            state[3] = 0;
        } else {
            func_80043230((void *)o, 0x94, 0xE, (*(s16 *)((u8 *)( o ) + (  0x60 ))) );
        }
        func_80039934(&D_800EB0F8[0], (*(s16 *)((u8 *)( o ) + (  0x30 ))) , (*(s16 *)((u8 *)( o ) + (  0x32 ))) );
        break;
    case 2:
        o = (u8 *)(*(s32 *)((u8 *)( state ) + (  0x4C ))) ;
        if (!(flags & 0x80)) {
            state[3] = flags | 0x80;
            func_80043178((void *)o);
            (*(u16 *)((u8 *)( o ) + (  0x60 )))  = 0x400;
        }
        (*(u16 *)((u8 *)( o ) + (  0x60 )))  -= 0x33;
        if ((*(s16 *)((u8 *)( o ) + (  0x60 )))  <= 0) {
            (*(s16 *)((u8 *)( o ) + (  0x30 )))  = 0x148;
            (*(s16 *)((u8 *)( o ) + (  0x32 )))  = 0xE;
            state[3] = 0;
        } else {
            func_80043230((void *)o, 0x148, 0xE, (*(s16 *)((u8 *)( o ) + (  0x60 ))) );
        }
        func_80039934(&D_800EB0F8[0], (*(s16 *)((u8 *)( o ) + (  0x30 ))) , (*(s16 *)((u8 *)( o ) + (  0x32 ))) );
        break;
    }

    switch (state[1] & 0x1F) {
    case 0:
        (*((u8 *)( state + ((*(u16 *)((u8 *)( state ) + (  6 )))  << 2) ) + (  0x56 )))  &= 0x7F;
        o = func_800291E0(0, -1, -1);
        bits = (*(u16 *)((u8 *)( o ) + (  8 ))) ;
        bits |= 4;
        (*(u16 *)((u8 *)( o ) + (  8 )))  = bits;
        attr = (*(s32 *)((u8 *)( o ) + (  4 ))) ;
        attr &= 0xF7FFFFFF;
        (*(s32 *)((u8 *)( o ) + (  4 )))  = attr;
        id = (*(u16 *)((u8 *)( o ) + (  0x4A ))) ;
        (*(s16 *)((u8 *)( o ) + (  0x30 )))  = (*(u16 *)((u8 *)( state ) + (  0x12 )))  - D_8009B146 - (*(u16 *)((u8 *)( o ) + (  0x48 ))) ;
        (*(s16 *)((u8 *)( o ) + (  0x32 )))  = (*(u16 *)((u8 *)( state ) + (  0x14 )))  - D_8009B148 - id;
        (*(s16 *)((u8 *)( o ) + (  0x44 )))  = (*(s16 *)((u8 *)( o ) + (  0x46 )))  = 0;
        func_80043178((void *)o);
        (*(u16 *)((u8 *)( o ) + (  0x60 )))  = 0;
        func_8003FEE0(0x32);
        (*(s32 *)((u8 *)( rec->object_04 ) + (  4 )))  |= 0x80000000;
        o = func_800400AC(func_8004002C(), 2);
        func_800404CC(o, 0x148, 0xE, 0, 2, 0, 0x1B, 0x107);
        (*((u8 *)( o ) + (  0x5F )))  = 0x80;
        (*(s16 *)((u8 *)( o ) + (  0x60 )))  = -0x400;
        (*(u16 *)((u8 *)( o ) + (  8 )))  |= 8;
        func_80042918(((DisplayObject *)( o )) );
        func_800428EC(((DisplayObject *)( o )) , 4);
        (*(s32 *)((u8 *)( state ) + (  0x4C )))  = (s32)o;
        state[3] = 1;
        D_8009B338 = (*(u16 *)((u8 *)( state ) + (  6 ))) ;
        layout = 3;
        if (((D_801D4244[D_8009B338 - 1] >> 0x1A) & 0x1F) >= 0x14) {
            layout = 4;
        }
        box = func_80035BE4(0, layout, 0x94, 0xE, 0xA8, 0xC0);
        (*((u8 *)( box ) + (  0x54 )))  = 0;
        (*((u8 *)( box ) + (  0x53 )))  = 1;
        (*((u8 *)( box ) + (  0x59 )))  = 4;
        state[1] = 1;
        return;
    case 1:
        o = rec->object_00;
        func_8002ABB4(((DisplayObject *)( o )) , -1);
        if (!((*(s32 *)((u8 *)( o ) + (  4 )))  & 0x08000000)) {
            (*((u8 *)( o ) + (  0x22 )))  += 0xC;
            (*((u8 *)( o ) + (  0x21 )))  += 6;
            (*(u16 *)((u8 *)( o ) + (  0x46 )))  = (*(u16 *)((u8 *)( o ) + (  0x44 )))  += 0xCC;
            (*(u16 *)((u8 *)( o ) + (  0x60 )))  += 0x66;
            func_8004318C((void *)o, 2, 4, (*(s16 *)((u8 *)( o ) + (  0x60 ))) );
            if ((*(s16 *)((u8 *)( o ) + (  0x60 )))  >= 0x800) {
                (*(s32 *)((u8 *)( o ) + (  0x20 )))  = 0x8000;
                (*(s32 *)((u8 *)( o ) + (  0x30 )))  = 0x40002;
                (*(s32 *)((u8 *)( o ) + (  0x44 )))  = 0x10001000;
                (*(s32 *)((u8 *)( rec->object_04 ) + (  4 )))  &= 0x7FFFFFFF;
                (*(s32 *)((u8 *)( o ) + (  4 )))  |= 0x08000000;
            }
            if (!((*(s32 *)((u8 *)( o ) + (  4 )))  & 0x08000000)) {
                break;
            }
        }
        if (state[3] == 0) {
            state[1] = 2;
        }
        return;
    case 2:
        if (state[4] != 1 && !(D_800E9ECE[0] & 0x80)) {
            D_800E9DB0[3] = 0;
            i = 0;
            do {
                (*(u16 *)((u8 *)( (*(s32 *)((u8 *)( state + i * 4 ) + (  0x24 )))  ) + (  8 )))  &= 0xFFBF;
                i++;
            } while (i < 9);
            (*(u16 *)((u8 *)( D_800EB0F8[3].field_28 ) + (  8 )))  &= 0xFFBF;
            state[1] = 3;
            func_8003FEE0(0x31);
    case 3:
            o = rec->object_00;
            (*((u8 *)( o ) + (  0x21 )))  += 8;
            if (!((*((u8 *)( o ) + (  0x21 )))  & 0xFF)) {
                (*(u16 *)((u8 *)( o ) + (  8 )))  &= 0xFFFB;
                state[1] = 5;
                return;
            }
        }
        break;
    case 4:
        light = func_800591C0(0, 2);
        vs = &D_800F2848;
        a = -vs->field_00;
        b = a * func_80086770(vs->field_04) / 4096;
        c = a * func_800866A0(vs->field_04) / 4096;
        a = b * func_800866A0(vs->angle + 0x800) / 4096;
        b = b * func_80086770(vs->angle + 0x800) / 4096;
        (*(s32 *)((u8 *)( light ) + (  0 )))  = b;
        (*(s32 *)((u8 *)( light ) + (  4 )))  = c;
        (*(s32 *)((u8 *)( light ) + (  8 )))  = a;
        flags = state[1];
        if (!(flags & 0x80)) {
            state[1] = flags | 0x80;
            state[2] = 0;
            D_8009B0C0 = 1;
            D_800E9DB0[2] = (void (*)(void))func_80029934;
            flags = state[0];
            (*(u16 *)((u8 *)( state ) + (  0x10 )))  = 0;
            if (!(flags & 0x40)) {
                state[0] = flags | 0x40;
                light = func_800591C0(0, 0);
                (*(s32 *)((u8 *)( light ) + (  4 )))  = -0x1000;
                (*(s32 *)((u8 *)( light ) + (  0 )))  = 0;
                (*(s32 *)((u8 *)( light ) + (  8 )))  = 0;
                (*(s32 *)((u8 *)( light ) + (  0xC )))  = 0xFFFFFF;
                (*(s32 *)((u8 *)( light ) + (  0x10 )))  = 0;
                (*(s32 *)((u8 *)( light ) + (  0x14 )))  = 0x1000;
                (*(s32 *)((u8 *)( light ) + (  0x18 )))  = 0;
                (*(s32 *)((u8 *)( light ) + (  0x1C )))  = 0x404040;
                (*(s32 *)((u8 *)( light ) + (  0x2C )))  = 0xC0C0C0;
                func_800595C8(0, 0x400, 0x400, 0x400);
                func_80058FB0(0, (u16 *)0x80181000);
                p = (u8 *)0x80181000;
                D_800F2848.view.vrx = (*(s16 *)((u8 *)( p ) + (  0 ))) ;
                D_800F2848.view.vry = (s16)(*(u16 *)((u8 *)( p ) + (  2 ))) ;
                D_800F2848.view.vrz = (s16)(*(u16 *)((u8 *)( p ) + (  4 ))) ;
                D_800F2848.field_00 = func_8005F1B8(0, 0x334);
                func_80059AA8(0, 1);
                func_80059AE0(0);
            }
            func_80057AF4(0, 0, 1);
            func_800597C8(0, 1, 0);
            (*(s32 *)((u8 *)( state ) + (  0x20 )))  = 0x12C;
            state[3] = 2;
            o = rec->object_00;
            (*(u16 *)((u8 *)( o ) + (  8 )))  |= 4;
            func_80043178((void *)o);
            (*(u16 *)((u8 *)( o ) + (  0x60 )))  = 0;
            func_8003FEE0(0x34);
            func_80015C0C();
            return;
        }
        sel = state[2];
        switch (sel) {
        case 0:
            o = rec->object_00;
            if ((*(s16 *)((u8 *)( o ) + (  0x60 )))  < 0x800) {
                (*((u8 *)( o ) + (  0x21 )))  -= 4;
                if ((*((u8 *)( o ) + (  0x21 )))  < 0xD8) {
                    (*((u8 *)( o ) + (  0x21 )))  = 0xD8;
                }
                (*(u16 *)((u8 *)( o ) + (  0x60 )))  += 0xCC;
                func_8004318C((void *)o, -0x16, 4, (*(s16 *)((u8 *)( o ) + (  0x60 ))) );
                if ((*(s16 *)((u8 *)( o ) + (  0x60 )))  >= 0x800) {
                    (*((u8 *)( o ) + (  0x21 )))  = 0xD8;
                    (*(s16 *)((u8 *)( o ) + (  0x30 )))  = -0x16;
                    (*(s16 *)((u8 *)( o ) + (  0x32 )))  = 4;
                }
            }
            (*(u16 *)((u8 *)( state ) + (  0x10 )))  = (*(u16 *)((u8 *)( state ) + (  0x10 )))  + 0x2A;
            if ((*(s16 *)((u8 *)( state ) + (  0x10 )))  >= 0x400) {
                (*(u16 *)((u8 *)( state ) + (  0x10 )))  = 0x400;
                if (!(D_800E9ECE[0] & 0x80) && state[3] == 0) {
                    state[2] = 1;
                    func_80040410((void *)(*(s32 *)((u8 *)( state ) + (  0x50 ))) , 1);
                    return;
                }
            }
            break;
        case 1:
            if (D_8009B398 & 0x80E0) {
                func_80015C84();
                state[3] = 1;
                state[2] = 2;
                func_8003FEE0(0x34);
                o = rec->object_00;
                func_80043178((void *)o);
                (*(u16 *)((u8 *)( o ) + (  0x60 )))  = 0;
                return;
            }
            break;
        case 2:
            o = rec->object_00;
            if ((*(u16 *)((u8 *)( o ) + (  8 )))  & 4) {
                (*((u8 *)( o ) + (  0x21 )))  += 4;
                (*(u16 *)((u8 *)( o ) + (  0x60 )))  += 0xCC;
                func_8004318C((void *)o, 2, 4, (*(s16 *)((u8 *)( o ) + (  0x60 ))) );
                if ((*(s16 *)((u8 *)( o ) + (  0x60 )))  >= 0x800) {
                    (*((u8 *)( o ) + (  0x21 )))  = 0;
                    (*(s16 *)((u8 *)( o ) + (  0x30 )))  = 2;
                    (*(s16 *)((u8 *)( o ) + (  0x32 )))  = 4;
                    (*(u16 *)((u8 *)( o ) + (  8 )))  &= 0xFFFB;
                }
                if ((*(u16 *)((u8 *)( o ) + (  8 )))  & 4) {
                    break;
                }
            }
            if (!(D_800E9ECE[0] & 0x80) && state[3] == 0) {
                func_80047EC4();
                D_800E9DB0[2] = 0;
                {
                    void *p = (void *)(*(s32 *)((u8 *)( state ) + (  0x50 ))) ;

                    D_8009B0C0 = 0;
                    func_80040410(p, 2);
                }
                state[1] = 5;
                return;
            }
            break;
        }
        break;
    case 5:
        if (D_8009B398 & 0x20) {
            (*(u16 *)((u8 *)( rec->object_00 ) + (  8 )))  |= 4;
            state[1] = 6;
            state[4] = 0;
            func_8004036C((void *)(*(s32 *)((u8 *)( state ) + (  0x50 ))) );
            func_80014FA4();
            func_8003FEE0(0x31);
            return;
        }
        if (state[4] == 0 && (D_8009B398 & 0x20C0)
            && ((D_801D4244[(*(u16 *)((u8 *)( state ) + (  6 )))  - 1] >> 0x1A) & 0x1F) < 0x14
            && state[3] == 0) {
            state[1] = 4;
            return;
        }
        break;
    case 6:
        o = rec->object_00;
        (*((u8 *)( o ) + (  0x21 )))  += 8;
        if ((s8)(*((u8 *)( o ) + (  0x21 )))  < 0) {
            (*(s32 *)((u8 *)( rec->object_04 ) + (  4 )))  |= 0x80000000;
            (*(s32 *)((u8 *)( o ) + (  4 )))  &= 0xF7FFFFFF;
            func_80043178((void *)o);
            i = 0;
            (*(u16 *)((u8 *)( o ) + (  0x60 )))  = 0;
            do {
                (*(u16 *)((u8 *)( (*(s32 *)((u8 *)( state + i * 4 ) + (  0x24 )))  ) + (  8 )))  |= 0x40;
                i++;
            } while (i < 9);
            (*(u16 *)((u8 *)( D_800EB0F8[3].field_28 ) + (  8 )))  |= 0x40;
            D_800E9DB0[3] = func_80029EC4;
            func_80015C0C();
            state[3] = 2;
            state[1] = 7;
            func_8003FEE0(0x33);
            return;
        }
        break;
    case 7:
        o = rec->object_00;
        if (o != 0) {
            func_8002ABB4(((DisplayObject *)( o )) , 1);
            (*((u8 *)( o ) + (  0x22 )))  += 0xC;
            (*((u8 *)( o ) + (  0x21 )))  += 6;
            (*(u16 *)((u8 *)( o ) + (  0x60 )))  += 0x66;
            func_8004318C((void *)o,
                (*(s16 *)((u8 *)( state ) + (  8 )))  - (*(s16 *)((u8 *)( o ) + (  0x48 )))  - D_8009B146,
                (*(s16 *)((u8 *)( state ) + (  0xA )))  - (*(s16 *)((u8 *)( o ) + (  0x4A )))  - D_8009B148, (*(s16 *)((u8 *)( o ) + (  0x60 ))) );
            (*(u16 *)((u8 *)( o ) + (  0x46 )))  = (*(u16 *)((u8 *)( o ) + (  0x44 )))  -= 0xCC;
            if ((*(s16 *)((u8 *)( o ) + (  0x60 )))  >= 0x800) {
                func_80029528(0);
                (*((u8 *)( state + ((*(u16 *)((u8 *)( state ) + (  6 )))  << 2) ) + (  0x56 )))  |= 0x80;
                return;
            }
        } else if (state[3] == 0) {
            func_8004036C((void *)(*(s32 *)((u8 *)( state ) + (  0x4C ))) );
            (*(s32 *)((u8 *)( state ) + (  0x4C )))  = 0;
            func_80035B7C(&D_800EB0F8[0]);
            state[1] = 8;
            return;
        }
        break;
    case 8:
        state[0] = 1;
        break;
    }
}
