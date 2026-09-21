/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/duel_init_scene.c (Duel_InitScene), profile gcc_2_8_1_g8_split.
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
void func_800245A0(void *arg0, void *arg1);
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
extern u8 D_800907D8[];
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
extern u8 *D_8009B22C;
extern s8 D_8009B238;
extern u8 D_8009B369 __attribute__((section(".data")));
void func_800175A0(void);
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
typedef struct {
	short x, y;		 
	short w, h;		 
} RECT;
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
void func_80016E70(DisplayObject *widget);
void func_8001778C(void);
void func_800164FC(void);
extern u16 D_801D0200[];
extern u8 D_801D1200[];
extern u8 D_8009B1D4;
struct DisplayObject;
void func_800176D0(void);
void func_80017708(void);
void func_80012D84(s32 count);
extern u8 D_801781D8[];
extern u8 D_8009B164;
extern u16 D_8009B16C;
struct DisplayObject;
s32 func_8004002C(void);
void *func_800400AC(s32 index, s32 key);
void func_800404CC(
    void *object, s32 x, s32 y, s32 field_67, s32 field_68,
    s32 field_69, s32 color, s32 texture
);
FileTransferDescriptor *func_80014E1C(
    s32, u8 *, s32, s32, FileTransferCallback, s32, s32
);
void func_800137E4(void);
void func_800171A8(FileTransferDescriptor *d, s32 stage);
s32 func_800428EC(DisplayObject *object, s8 value);
void func_80042918(DisplayObject *object);
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
void func_8001352C(void);
extern void (*D_800E9DB0[4])(void);
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
void func_8004763C(void);
s32 func_80047AD0(s32 value);
extern u16 D_8009B220;
struct DisplayObject;
extern u16 D_8009B162;
extern u16 D_8009B23A;
extern u8 D_8009B174;
void func_800179F4(void);
extern DisplayObject *D_8009B214;
extern DisplayObject *D_8009B21C;
extern u8 *D_8009B1D8;
extern u8 *D_8009B1DC;
void func_8001755C(void);
void func_8002C598(void);
void func_80029574(s32 index);
void func_80035668(u32 value);
void func_800178BC(void);
extern u8 D_8009B364 __attribute__((section(".data")));
extern u16 D_8009B204;
extern s8 D_8009B361 __attribute__((section(".data")));
void func_800179F4(void)
{
    DisplayObject *obj;
    u8 *p;
    u8 *q;
    s32 value;
    s32 side;
    DuelEffectResourceRecord *pane;
    u8 *prev;
    s8 *pid;

    pid = &D_8009B361;
    func_8004763C();
    func_80047AD0(1);
    func_80012D84(4);
    func_800137E4();
    value = D_8009B364;
    func_80014E1C(
        0, 0,
        (((value * 15) * 4 - value) * 4 - value) +
            0x16C6 ,
        0xEB , func_800171A8, 0, 0);
    func_800137E4();
    D_8009B238 = -1;
    D_8009B23A = 11;
    D_8009B164 = 0;
    D_8009B162 = 0;
    D_8009B1D4 = 0;
    D_8009B204 = 0;
    D_8009B220 = 0;
    D_8009B16C = 0;
    D_8009B174 = 0;
    if (D_8009B369 != 1) {
        if (D_8009B361 >= 0) {
            func_80014E1C(
                0, 0,
                D_8009B361 * (3  - 1) +
                    D_8009B361 + 0x1D33 ,
                3 , 0, 0,
                (s32)D_801781D8
            );
        }
        D_8009B1D5 = 0;
        D_8009B23A = 1;
        func_8001778C();
        func_80017708();
        func_800175A0();
        D_8009B16C |= 0x1000;
    }
    D_8009B1C8 = &D_800E9FF0[D_8009B1D5];
    func_800178BC();
    D_800F2848.angle =
        D_8009B1D5 * (0x1000  / 2)  + (0x1000  / 4) ;
    func_8001352C();
    func_800176D0();
    pane = &D_800EA0E8[0];
    func_8002C598();
    func_80029574(0);
    pane->src_x = 0;
    pane->src_y = 256;
    pane->field_2C = 0;
    pane->field_2E = 255;
    func_80029574(1);
    pane[1].src_x = 64;
    pane[1].src_y = 256;
    pane[1].field_2C = 0;
    pane[1].field_2E = 254;
    func_80035668(0);
    func_8001755C();
    func_800137E4();
    D_8009B22C =
        &D_800907D8[D_8009B1D5 * 20 ];
    obj = func_800400AC(func_8004002C(), 2);
    func_800404CC(obj, 12, 24, 4, 2, D_8009B364, 11, 732);
    func_80042918(obj);
     











    *(s16 *)&obj->flags |= 0x08 ;
    side = (u32)D_8009B361 >> 31;
    D_8009B214 = obj;
    obj = func_800400AC(func_8004002C(), 2);
    func_800404CC(
        obj, 280, 32, 4, side, 0, 11, 748
    );
    func_80042918(obj);
    *(s16 *)&obj->flags |= 0x08 ;
    if (D_8009B1D5 != 0) {
        *(u16 *)&obj->field_40.h.field_40 += 16;
    }
    D_8009B21C = obj;
    obj = func_800400AC(func_8004002C(), 6);
    func_80042918(obj);
    func_800428EC(obj, 1);
    obj->field_4C = (s32)func_80016E70;
    prev = (u8 *)D_8009B21C;
    obj->field_50.word = (s32)prev;
    D_800E9DB0[3] = func_800164FC;
    if (D_8009B369 != 1) {
        p = 0;
        D_8009B1DC = 0;
        D_8009B1D8 = 0;
        if (pid[-1] < 0) {
            if (D_8009B361 < 0) {
                D_8009B1D8 = D_801D1200;
                D_8009B1DC = D_801D1200 + 0x1000 ;
                func_800245A0(
                    D_801D1200, D_801D1200 + 0x1000 
                );
                return;
            }
            p = (u8 *)D_801D0200;
            D_8009B1D8 = p;
            if (D_8009B361 < 39 ) {
                q = 0;
                goto shuffle;
            }
        }
        q = p;
    shuffle:
        func_800245A0(p, q);
    }
}
