/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/func_80018FEC.c (DuelScene_UpdateExodiaResult), profile gcc_2_8_1_g8_split.
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
extern u8 D_8009B165;
extern u8 D_8009B369 __attribute__((section(".data")));
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
extern u8 D_8009B260 __attribute__((section(".data")));
DuelEffectRequest *func_8002C68C(s32 id);
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
typedef struct {
    u8 *object;
    u8 *child;
    u8 pad_08;
    u8 active_09;
    u8 pad_0A[2];
} DuelHandSlot;
extern DuelHandSlot D_800EA030[5 ];
typedef struct {
    u32 field_00;
     


    struct DisplayObject *cursor_object;
    DuelHandSlot *hand;
     
    s16 field_0C;
     



    u8 field_0E;
     

    s8 col;
    s8 row;
    u8 field_11;
    u8 field_12;
    u8 field_13;
    u8 field_14;
     

    u8 field_15;
    u8 pad_16;
    u8 field_17;
    u8 field_18;
     
    u8 status;
    u8 pad_1A[2];
} DuelSelectionRecord;
extern u8 D_800E9F10[];
extern DuelCardPickCursor *D_8009B1B4;
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
typedef struct {
    u8 pad_0000[0x36B4];
    DuelCardRecord record;
} DuelCardReplayRecordBlock;
extern u8 D_8015C424[];
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
extern u8 D_8009B1B9;
void func_80018FEC(void);
extern u16 D_8009B23A;
struct DisplayObject;
typedef struct {
    u8 work_slot;
    u8 biased_x;
    u8 biased_y;
} DuelExodiaCardPose;
typedef struct {
    DuelExodiaCardPose poses[5 ];
    u8 padding;
} DuelExodiaCardPoseTable;
extern DuelExodiaCardPoseTable D_80090918;
s32 func_800358FC(s32 divisor);
void func_800156DC(void);
void func_80015C84();
void func_8001EC70(DisplayObject *object);
extern DisplayObject *D_800E9EF0[];
struct DisplayObject;
void func_8004036C(void *object);
void *func_80042B40(s32 value);
extern u8 *D_8009B214;
extern u8 *D_8009B21C;
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
extern u16 D_8009B162;
extern u16 D_8009B23A;
extern u16 D_8009B1D0;
extern u8 D_8009B269 __attribute__((section(".data")));
extern u8 D_8009B26C __attribute__((section(".data")));
extern u8 D_800E9ECF[];
void func_800472A8(s32 arg0);
void func_8003FEE0(u32);
void func_8003FF58(s32);
void func_8003FF88(u32);
void func_80059C18(s32 value);
extern u16 D_800EF658[];
extern int  func_8008E590(void);
extern s32 D_800E9F04[];
void func_80018FEC(void)
{
    u16 flags;
    DisplayObject *obj;
    u8 *pose;
    u8 *rec;
    DuelEffectObject *fx;
    s32 i;
    s32 anim;
    s32 n;
    s32 r;
    s32 t14;
    u32 sum;
    u8 *cards;
    u8 *poses;
    DisplayObject **objs;
    s32 fnv;
    DuelCardReplayRecordBlock *g;
    s32 py;
    s32 t;
    s32 k;
    DisplayObject **slot;
    s8 side;
    DuelSideState *other;
    DisplayObject *d;

    flags = D_8009B23A;
    if ((flags & 0x8000 ) == 0) {
        i = 0;
        cards = D_8015C424;
        poses = (u8 *)&D_80090918;
        r = (s32)func_8001EC70;
        fnv = r;
        objs = D_800E9EF0;
        D_8009B23A = flags | 0x8000 ;
        obj = ((DisplayObject *)( D_8009B214 )) ;
        side = D_8009B1D5;
        D_8009B1B4 =
            (DuelCardPickCursor *)&D_800E9F10[
                (u8)side * (4  * 0x1C ) 
            ];
        *(s16 *)&obj->position.h.field_28 = -0x40;
        obj->field_2C.h.field_2C = 0x10;
        obj->field_6C = 1;
        obj->update = (DisplayObjectCallback)fnv;
        obj->position.h.field_2A = obj->field_30.h.field_32;
        obj = ((DisplayObject *)( D_8009B21C )) ;
        obj->position.h.field_28 = 0x180;
        obj->field_2C.h.field_2C = 0x10;
        obj->field_6C = 1;
        obj->update = (DisplayObjectCallback)fnv;
        obj->position.h.field_2A = obj->field_30.h.field_32;
        rec = (u8 *)D_800EA030;
next_obj:
        obj = *(DisplayObject **)rec;
         
        g = (DuelCardReplayRecordBlock *)(
            (u32)&((DuelCardRecord *)0)[obj->field_6A] +
            (u32)cards + 0x48000 
        );
        anim = g->record.card_id - 0x11;
        pose = (u8 *)(anim * 3 + (u32)poses);
        obj->position.h.field_28 = pose[1] - 0x1A;
        py = pose[2];
        obj->field_2C.h.field_2C = 0xB4;
        obj->field_6C = 1;
        obj->update = (DisplayObjectCallback)fnv;
        obj->position.h.field_2A = py - 0x1E;
        objs[pose[0]] = obj;
        *(u8 **)rec = 0;
        i++;
        rec += sizeof(DuelHandSlot);
        if (i < 5 ) {
            goto next_obj;
        }
        D_800E9F04[0] = 0;
        func_8004036C(
            ((DuelSelectionRecord *)D_8009B1B4)->cursor_object);
        D_8009B162 = 8;
        D_8009B1D0 = 0;
        D_8009B1B9 = 0;
        D_8009B17C = 0;
        D_8009B23A = D_8009B23A | 0x4000;
        func_80015C84();
        D_800E9ECF[0] = 2;
        func_8003FF58(2);
        return;
    }
    if (flags & 0x4000) {
        if (flags & 0x2000) {
            if ((D_8009B260 & 1) != 0) {
                return;
            }
            D_8009B23A = flags & 0xBFFF;
            D_8009B1B9 = 0;
            D_8009B1D0 = 0;
            return;
        }
        if (D_8009B17C != 0) {
            if (D_8009B17C[((u32)&((DuelEffectRequest *)0)->field_1D) ] == 0) {
                return;
            }
            func_8003FEE0(0x1D);
            if (func_80042B40(1) == 0) {
                D_8009B23A = D_8009B23A | 0x2000;
                return;
            }
        }
        fx = ((DuelEffectObject *)( func_8002C604(0x13) )) ;
        D_8009B17C = (u8 *)fx;
        fx->x = (func_8008E590() & 0xFF) + 0x20;
        r = func_800358FC(0xB0);
        n = D_8009B1B9;
        t14 = fx->field_14;
        fx->y = r + 0x20;
        fx->field_14 = t14 + ((n & 3) << 13);
        D_8009B1B9 = n + 1;
        return;
    }
    if (flags & 0x2000) {
        t = D_8009B1D0 - 1;
        D_8009B1D0 = t;
        if ((s16)t > 0) {
            return;
        }
        if ((s8)D_8009B1B9 >= 5 ) {
            D_8009B23A = (flags & 0xDFFF) | 0x1000;
            fx = ((DuelEffectObject *)( func_8002C604(0x13) )) ;
            fx->x = 0xA0;
            fx->y = 0x78;
            D_8009B17C = (u8 *)fx;
            fx->field_14 = fx->field_14 + 0x8000;
            return;
        }
        D_8009B1D0 = 4;
        fx = ((DuelEffectObject *)( func_8002C604(0) )) ;
        k = (s8)D_8009B1B9;
        slot = &D_800E9EF0[k];
        d = *slot;
        fx->x = d->field_30.h.field_30 + 0x1A;
        d = *slot;
        fx->y = d->field_30.h.field_32 + 0x1E;
        sum = (k << 12) + 0xA000;
        anim = fx->field_14 + sum;
        fx->field_14 = anim;
        fx->field_1A = 9;
        func_8003FEE0(0x17);
        D_8009B1B9 = D_8009B1B9 + 1;
        return;
    }
    if (flags & 0x1000) {
        if (D_8009B17C[((u32)&((DuelEffectRequest *)0)->field_1D) ] == 0) {
            return;
        }
        D_8009B23A = flags & 0xEFFF;
        func_8003FEE0(0x1D);
        func_8002C68C(0x18);
        func_8003FF88(0x8021);
        return;
    }
    func_800156DC();
    D_800EF658[0] = 0x309 ;
    side = D_8009B1D5;
    D_8009B165 = side;
    D_800E9FF0[(u8)side].rank.result_adjustment = 0x28;
    other = &D_800E9FF0[D_8009B1D5 ^ 1];
    other->life_points.unsigned_value = 0;
    other->displayed_life_points = 0;
    func_800472A8(0x7310);
    func_80059C18(0x7310);
    D_8009B369 = 1;
    D_8009B269 = 3;
    D_8009B26C = 1;
}
