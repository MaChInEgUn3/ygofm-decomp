/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/duel_field_display_objects.c, profile gcc_2_8_1_g8_split.
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
extern s16 D_800907AC[2 ][2][4];
extern u8 D_8009B1D5;
struct DisplayObject;
void func_8004036C(void *object);
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
typedef struct DisplayLinkEntry {
    DisplayObject *object;
    DisplayObject *field_04;
    u8 pad_08[4];
} DisplayLinkEntry;
typedef struct DisplayParent {
    DisplayObject *position_base;
    DisplayObject *base;
    DisplayLinkEntry *entries;
    u8 pad_0C[0xB];
    u8 index;
} DisplayParent;
void func_80022FF0(DisplayParent *parent, s32 clear);
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
void func_8002348C(DuelFieldDisplaySource *source);
void func_800234E4(DuelFieldDisplaySource *source);
s32 func_800235C0(void);
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
extern DuelCardPickCursor *D_8009B1B4;
struct DuelEffectChannel;
void func_80035B7C(struct DuelEffectChannel *record);
struct DuelEffectChannel;
void func_80039934(struct DuelEffectChannel *record, s32 x, s32 y);
void *func_80042B40(s32 value);
s32 func_800428EC(DisplayObject *object, s8 value);
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
DisplayObject *func_80018150(int arg0, int arg1);
typedef struct {
    u8 pad_0000[0x36B4];
    DuelCardRecord record;
} DuelCardReplayRecordBlock;
extern u8 D_8015C424[];
typedef struct {
    u8 pad_00[0x08];
    u16 flags;
    u8 pad_0A[0x16];
    union {
        s32 packed;
        u8 channel[4];
    } tint;
    s32 field_24;
    u16 angle_step;
    union {
        u16 unsigned_value;
        s16 signed_value;
    } angle;
    u8 pad_2C[0x02];
    s16 mode;
    u8 pad_30[0x30];
    u16 counter;
    u8 pad_62[0x08];
    u8 record_index;
    u8 pad_6B[0x01];
    u8 phase;
} DuelCardTurnObject;
void func_80022674(DuelCardTurnObject *p);
void func_800229F4(DuelCardTurnObject *p);
extern u16 D_8009AF20[2];
void func_80022D94(s32 frames, s32 x, s32 z, s32 y, s32 value);
extern s16 D_8009B204;
extern s16 D_8009B1EE;
extern s16 D_8009B192;
extern s16 D_8009B190;
extern s16 D_8009B166;
extern s32 D_8009B1C4;
extern s32 D_8009B15C;
extern s32 D_8009B158;
extern s32 D_8009B224;
extern s32 D_8009B1FC;
extern s32 D_8009B198;
extern s32 D_8009B194;
extern s32 D_8009B168;
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
extern u16 D_8009B162;
struct DuelEffectChannel;
void func_8002348C(DuelFieldDisplaySource *source);
void func_800234E4(DuelFieldDisplaySource *source);
s32 func_800235C0(void)
{
    DuelFieldDisplaySource *source;
    ViewState *view;
    DisplayObject *o;
    s32 i;
    s32 moving;
    s32 busy;
    s32 x;
    s32 y;
    s32 z;
    s32 w;
    s32 t;
    s16 count;
    u8 *records;
    u8 *replay;
    s32 result;
    u16 flags;

    flags = D_8009B162;
    source = (DuelFieldDisplaySource *)D_8009B1B4;
    view = &D_800F2848;
    do {
    } while (0);
    result = 0;
    if (flags != 0) {
        x = flags & 0x8000;
        do {
        } while (0);
        busy = 0;
        if (x == 0) {
            D_8009B162 = flags | 0x8000;
            if (D_8009B162 & 1) {
                func_80022D94(0x10, 0x14E, 0x3FE, D_8009AF20[D_8009B1D5],
                              D_800907AC[D_8009B1D5][source->field_18][source->y]);
            }
            if (D_8009B162 & 4) {
                func_80022D94(0x10, 0x258, 0x100, D_8009AF20[D_8009B1D5], 0);
                func_8004036C(source->object);
                source->object = 0;
                records = D_8015C424;
                for (i = 5; i < 30; i++) {
                    if (i % 15  >= 5  &&
                        (D_801A7AD8[i].flags & 0x8000)) {
                        o = ((DuelCardReplayRecordBlock *)(
                            (u8 *)&((DuelCardRecord *)records)[i] +
                            0x48000 ))->record.object;
                        o->field_6C = 1;
                        o->field_60 = 4;
                        o->update = (DisplayObjectCallback)func_800229F4;
                    }
                }
                D_8009B162 |= 0x4000;
            }
            if (D_8009B162 & 2) {
                o = func_80018150(0, 0xF0);
                source->field_16 = 0x24;
                if (source->field_13 != 0) {
                    func_80040410((DisplayObjectConfig *)o, source->field_13);
                    source->field_16 = 7;
                }
                func_800428EC(o, -(source->table_index * 2) - 2);
                o->position.h.field_28 = 0;
                o->position.h.field_2A = source->field_0C;
                func_80043178((DisplayObjectSnapshot *)o);
                o->field_60 = -0x400;
                o->field_6C = 2;
                source->field_00 = o;
                if (source->entries != 0) {
                    for (i = 0; i < 5 ; i++) {
                        if (source->entries[i].object != 0) {
                            source->entries[i].object->field_30.h.field_30 =
                                o->field_30.h.field_30 + (i * 0x3C + 0xE);
                            source->entries[i].object->field_30.h.field_32 =
                                o->field_30.h.field_32 - 0x1C;
                        }
                    }
                }
                func_80022FF0((DisplayParent *)source, 0);
            }
            if (D_8009B162 & 8) {
                o = source->field_00;
                o->position.h.field_2A = 0xF0;
                o->position.h.field_28 = o->field_30.h.field_30;
                func_80043178((DisplayObjectSnapshot *)o);
                o->field_60 = 0x400;
                o->field_6C = 2;
                func_80022FF0((DisplayParent *)source, 1);
            }
            busy = 0;
        }
        moving = busy;
        if (D_8009B162 & 0x40) {
            o = source->object;
            if (o->field_60 != 0) {
                t = (*(s16 *)&o->position.h.field_28 << 8) | o->pad_62[0];
                t += o->field_34.h.field_36;
                o->pad_62[0] = t;
                o->position.h.field_28 = t >> 8;
                t = (*(s16 *)&o->position.h.field_2A << 8) | o->field_64;
                t += o->field_38.h.field_3A;
                o->position.h.field_2A = t >> 8;
                o->field_64 = t;
                o->field_60--;
                busy = 1;
                if (o->field_60 <= 0) {
                    busy = 0;
                    o->field_60 = 0;
                    o->position.word = o->field_2C.word;
                }
            }
        }
        o = source->field_00;
        if ((D_8009B162 & 2) && o->field_6C != 0) {
            busy = 1;
            moving = busy;
            func_80043230((DisplayObjectPosition *)o,
                             *(s16 *)&o->position.h.field_28,
                             *(s16 *)&o->position.h.field_2A, o->field_60);
            o->field_60 += 0x40;
            if (o->field_60 >= 0) {
                o->field_6C = 0;
                o->field_30.word = o->position.word;
            }
        }
        if ((D_8009B162 & 8) && o->field_6C != 0) {
            busy = 1;
            func_80043230((DisplayObjectPosition *)o,
                             *(s16 *)&o->position.h.field_28,
                             *(s16 *)&o->position.h.field_2A, o->field_60);
            o->field_60 -= 0x40;
            moving = busy;
            if (o->field_60 < 0) {
                func_80035B7C(&D_800EB0F8[source->field_14]);
                func_8004036C(o);
                source->field_00 = 0;
                if (source->entries != 0) {
                    for (i = 0; i < 5 ; i++) {
                        func_8004036C(source->entries[i].object);
                        source->entries[i].object = 0;
                        func_8004036C(source->entries[i].field_04);
                        source->entries[i].field_04 = 0;
                    }
                }
                o->field_6C = 0;
                moving = 0;
            }
        }
        if (moving != 0) {
            func_80039934(&D_800EB0F8[source->field_14],
                           *(s16 *)&o->field_30.h.field_30 + 0x10,
                           *(s16 *)&o->field_30.h.field_32 + source->field_16);
        }
        if (D_8009B162 & 0x4000) {
            busy = 1;
            if (func_80042B40(1) != 0) {
                return busy;
            }
            D_8009B162 &= 0xBFFF;
        }
        if (D_8009B204 != 0) {
            count = (u16)D_8009B204 - 1;
            busy = 1;
            D_8009B204 = count;
            x = D_8009B1C4 += D_8009B1FC;
            y = D_8009B15C += D_8009B198;
            z = D_8009B158 += D_8009B194;
            w = D_8009B224 += D_8009B168;
            view->field_00 = x >> 16;
            view->field_04 = y >> 16;
            view->angle = z >> 16;
            view->view.vrz = w >> 16;
            if (count == 0) {
                view->field_00 = D_8009B1EE;
                view->field_04 = D_8009B192;
                view->angle = D_8009B190;
                view->view.vrz = D_8009B166;
                if (D_8009B162 & 1) {
                    replay = D_8015C424;
                    for (i = 5; i < 30; i++) {
                        if (i % 15  >= 5  &&
                            (D_801A7AD8[i].flags & 0x8000)) {
                            o = ((DuelCardReplayRecordBlock *)(
                                (u8 *)&((DuelCardRecord *)replay)[i] +
                                0x48000 ))->record.object;
                            o->field_6C = 1;
                            o->field_60 = 4;
                            o->update = (DisplayObjectCallback)func_80022674;
                        }
                    }
                    D_8009B162 |= 0x4000;
                }
            }
            func_8001352C();
        }
        if (busy == 0) {
            if (D_8009B162 & 1) {
                func_800234E4(source);
                func_8002348C(source);
            }
            D_8009B162 = 0;
        }
        result = busy;
    }
    return result;
}
