/* CANDIDATO PORTADO de krystalgamer/memories-decomp (src/game/duel_scene_battle.c, perfil gcc_2_8_1_g8_split_comm):
 * C identico ao que casa la. Aqui NAO casa: a saida do cc1psx (SN, 2.8.1) e a do
 * mips-sony-psx-gcc 2.8.1 dele diferem no escalonamento -- `lw 48($s1)` hoisted acima de `sb d_8009b174` (gp) e o `sw 40($s1)` deslocado; 6 hunks, 1069/1069 (+ o passo SMALL_DATA_NOP_FUNCS, ja na tabela). Medido 2026-09-21
 * com os dois compiladores sobre ESTA unidade ($SP/cc1_s.py + gcc -S dele). Nao e
 * questao de fonte: e o par de builds do gcc 2.8.1. Flags: -quiet -O2 -G8 -fno-builtin -msplit-addresses; as -G8. */
typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
extern int  func_8008E590(void);
extern u16 D_8009B23A;
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
extern volatile u32 D_8009B0F4_abs __attribute__((section(".data")));
extern u32 D_8009B134_abs __attribute__((section(".data")));
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
extern u8 D_8009B229;
extern s16 D_8009B22A;
extern u8 D_8009B369 __attribute__((section(".data")));
extern u16 D_8009B210;
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
extern DisplayObject *D_8009B214;
extern DisplayObject *D_8009B21C;
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
extern s32 D_801D4244[];
s32 func_800170C8(DuelCardRecord *card);
s32 func_8001EE44(DuelCardRecord *left, DuelCardRecord *right);
extern u8 D_8015C424[];
extern DisplayObject *D_800E9EF0[];
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
extern u8 D_800E9F48[];
extern u8 D_800E9F64[];
extern DuelCardPickCursor *D_8009B1B4;
extern u8 D_800E9ECC[];
void func_800156B8(s32);
void func_80015904(void);
void func_80015C0C(void);
void func_80015CC0(void);
extern u8 D_8009B269 __attribute__((section(".data")));
extern u8 D_8009B26C __attribute__((section(".data")));
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
DuelEffectRequest *func_8002C68C(s32 id);
typedef struct {
	short x, y;		 
	short w, h;		 
} RECT;
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
FileTransferDescriptor *func_80029164(s32 slot, s32 value);
u8 *func_800291E0(s32 index, s32 x, s32 y);
void func_80029528(s32 index);
void *func_80042B40(s32 value);
s32 func_800428EC(DisplayObject *object, s8 value);
struct DisplayObject;
void func_8004036C(void *object);
void func_80019BA0(
    DisplayObject *object, u8 field_21, s16 x, s16 y
);
s32 func_8001EFD4(DisplayObject *left, DisplayObject *right);
s32 func_8001F0D0(u8 *record);
extern ;
s32 func_8001F364(void);
extern ;
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
void func_80024D34(s32 slot, s32 card_id);
void func_8001F55C(void);
extern s16 D_8009B1A4[2];
extern s8 D_8009B1B0[2];
extern u16 D_8009B170[2];
extern u16 D_8009B178[2];
extern s8 D_8009B208;
extern s8 D_8009B209;
extern s8 D_8009B1B9;
void func_8003FEE0(u32);
void func_8003FF34(void);
typedef struct {
    s16 model_id;
    s16 field_02;
    s16 field_04;
    u8 field_06;
    u8 field_07;
} AnimatedBattleModelProperties;
extern AnimatedBattleModelProperties D_800EF658[];
void func_8001944C(DisplayObject *object);
extern ;
void func_80018080(DuelCardDisplayObject *object);
void func_800472A8(s32 arg0);
s32 func_80049120(void);
void func_80059C18(s32 value);
void func_8001ED20(DisplayObject *object);
extern u16 D_8009B162;
extern u16 D_8009B23A;
extern u8 D_8009B174;
extern u16 D_8009B1D0;
extern u8 D_8009B1B8;
extern u16 D_8009B374 __attribute__((section(".data")));
extern u8 D_800E9ECE[];
extern s8 D_8009B208;;
extern s8 D_8009B209;;
void func_8001F55C(void)
{
    DisplayObject *o;
    DisplayObject *side;
    DuelCardRecord *rec;
    DuelCardRecord *left;
    DuelCardRecord *right;
    DuelEffectRequest *req;
    s32 result;
    s32 id;
    s32 level;
    s32 arg;
    u16 life;
    u8 flags;
    s32 ix;
    s8 *wins;
    u8 *view;
    AnimatedBattleModelProperties *models;
    DisplayObject **pair;
    DisplayObject **slots;
    DisplayObjectCallback cb;
    s32 one;
    s32 y;
    s32 h;
    s32 w;
    s32 big;
    s32 pos;
    DuelSelectionRecord *cur;
    u8 *pw;
    DuelEffectResourceRecord *effects;

    if (!(D_8009B23A & 0x8000)) {
        big = 0x48000;
        D_8009B23A |= 0x8000;
        w = 0x10;
        one = 1;
        slots = D_800E9EF0;
        pw = D_8015C424;
        o = D_8009B214;
        y = 0x5C;
        (*(s16 *)((u8 *)( o ) + (  0x28 )))  = -0x74;
        cb = (DisplayObjectCallback)func_8001ED20;
        o->field_2C.h.field_2C = w;
        o->field_6C = one;
        o->update = cb;
        o->position.h.field_2A = o->field_30.h.field_32;
        o = D_8009B21C;
        h = 0x18;
        o->position.h.field_28 = 0x198;
        o->field_2C.h.field_2C = w;
        o->field_6C = one;
        o->update = cb;
        o->position.h.field_2A = o->field_30.h.field_32;
        o = slots[0];
        o->position.h.field_28 = 0x38;
        o->position.h.field_2A = y;
        o->field_2C.h.field_2C = h;
        o->field_6C = one;
        o->update = cb;
        func_80029164(0, (*(s16 *)((u8 *)( pw + D_800E9EF0[0]->field_6A * 0x1C + big ) + (  0x36C0 ))) );
        o = slots[1];
        D_8009B22A = 0;
        D_8009B1B8 = 0;
        if (o != 0) {
            o->position.h.field_28 = 0xD8;
            o->position.h.field_2A = y;
            o->field_2C.h.field_2C = h;
            o->field_6C = one;
            o->update = cb;
        } else {
            D_8009B229 = 0;
        }
        if (func_8001F0D0((u8 *)D_800E9EF0[0]) != 0) {
            D_8009B229 = 0;
        }
        cur = (DuelSelectionRecord *)(D_800E9F64 + D_8009B1D5 * 0x70);
        D_8009B1B4 = (DuelCardPickCursor *)cur;
        func_8004036C(cur->cursor_object);
        D_8009B162 = 8;
        D_8009B174 = 1;
        ((DuelSelectionRecord *)D_8009B1B4)->cursor_object = 0;
    }

    switch (D_8009B174 & 0xF) {
    case 1:
        if (!(D_8009B174 & 0x80) && ((D_8009B0F4_abs & 0x02000030) | D_8009B134_abs) == 0) {
            if (!(D_8009B174 & 0x40)) {
                id = D_8009B22A;
                D_8009B174 |= 0x40;
                if (id == 0) {
                    if (D_800E9EF0[1] != 0) {
                        u8 *pw1 = D_8015C424;
                        s32 big1 = 0x48000;

                        id = (*(s16 *)((u8 *)( pw1 + D_800E9EF0[1]->field_6A * 0x1C + big1 ) + (  0x36C0 ))) ;
                        goto request;
                    }
                } else {
                request:
                    func_80029164(1, id);
                    return;
                }
            } else {
                D_8009B174 |= 0x80;
                goto wait;
            }
        } else {
        wait:
            if (!(D_8009B174 & 0x20) && D_8009B162 == 0) {
                if (!(D_8009B174 & 0x10)) {
                    D_8009B174 |= 0x10;
                    D_8009B162 = 0xC;
                    D_8009B1B4 = (DuelCardPickCursor *)(D_800E9F48 + D_8009B1D5 * 0x70);
                } else {
                    D_8009B174 |= 0x20;
                }
            }
            if ((D_8009B174 & 0xA0) == 0xA0 && func_80042B40(1) == 0) {
                D_8009B174 = 2;
                return;
            }
        }
        break;

    case 2: {
        u8 f = D_8009B174;

        if (!(f & 0x80)) {
            o = D_800E9EF0[0];
            D_8009B174 = f | 0x80;
            {
                s32 b21 = o->field_20.b.field_21;

                func_80019BA0(o, b21, b21 + 0x40, 8);
            }
            result = func_800170C8(&D_801A7AD8[o->field_6A]);
            o = (DisplayObject *)func_800291E0(0, result & 0xFFFF, result >> 16);
            effects = D_800EA0E8;
            effects[0].field_3C |= 0x40;
            o->field_30.h.field_30 = 0xA;
            o->field_30.h.field_32 = 0x16;
            o->field_20.b.field_21 = 0xC0;
            func_800428EC(o, -0xA);
            o->flags = (o->flags | 4) & 0xFFBF;
            D_800E9EF0[2] = o;
            o = D_800E9EF0[1];
            D_800E9EF0[3] = 0;
            if (o != 0) {
                {
                    s32 b21 = o->field_20.b.field_21;

                    func_80019BA0(o, b21, b21 + 0x40, 8);
                }
                result = func_800170C8(&D_801A7AD8[o->field_6A]);
                o = (DisplayObject *)func_800291E0(1, result & 0xFFFF, result >> 16);
                if (D_8009B178[1] & 0x800) {
                    effects[1].field_3C |= 0x80;
                } else {
                    effects[1].field_3C |= 0x40;
                }
            } else if (D_8009B22A != 0) {
                o = (DisplayObject *)func_800291E0(1, -1, -1);
            }
            if (o != 0) {
                o->field_30.h.field_30 = 0xAA;
                o->field_30.h.field_32 = 0x16;
                o->field_20.b.field_21 = 0xC0;
                func_800428EC(o, -0xA);
                o->flags = (o->flags | 4) & 0xFFBF;
                D_800E9EF0[3] = o;
            }
        }
        f = D_8009B174;
        if (f & 0x20) {
            if (func_8001F364() == 0) {
                D_8009B174 &= 0xDF;
                return;
            }
        } else if (!(f & 0x40)) {
            if (func_80042B40(1) == 0) {
                D_800E9EF0[0]->flags &= 0xFFBF;
                D_800E9EF0[2]->flags |= 0x40;
                if (D_800E9EF0[1] != 0) {
                    D_800E9EF0[1]->flags &= 0xFFBF;
                }
                if (D_800E9EF0[3] != 0) {
                    D_800E9EF0[3]->flags |= 0x40;
                }
                {
                    u8 g = D_8009B174;

                    D_8009B174 = g | 0x40;
                    if (D_8009B22A != 0) {
                        D_8009B174 = g | 0x60;
                    D_8009B210 = 0;
                    return;
                    }
                }
            }
        } else {
            D_800E9EF0[2]->field_20.b.field_21 += 8;
            if ((s8)D_800E9EF0[2]->field_20.b.field_21 >= 0) {
                D_800E9EF0[2]->field_20.b.field_21 = 0;
                D_8009B174 = 3;
                D_800E9EF0[2]->flags &= 0xFFFB;
            }
            if (D_800E9EF0[3] != 0) {
                u8 fade = D_800E9EF0[2]->field_20.b.field_21;

                D_800E9EF0[3]->field_20.b.field_21 = fade;
                if (fade == 0) {
                    D_800E9EF0[3]->flags &= 0xFFFB;
                    return;
                }
            }
        }
        break;
    }

    case 3:
        if (!(D_8009B174 & 0x80)) {
            D_8009B174 |= 0x80;
            func_80015CC0();
            return;
        }
        if (!(D_800E9ECE[0] & 0x80)) {
            D_8009B174 = 4;
            if (D_8009B22A != 0) {
                D_8009B1B9 = D_8009B22A == 0x2B2;
                D_8009B174 = 0xA;
                return;
            }
            result = func_8001EFD4(D_800E9EF0[0], D_800E9EF0[1]);
            if (result >= 0) {
                D_8009B1B0[0] = 0;
                D_8009B1A4[0] = 0;
                D_8009B1B0[1] = 1;
                D_8009B1A4[1] = 0;
                if (result != 0) {
                    if (D_800E9EF0[1] != 0 && (D_8009B178[1] & 0x800)) {
                        D_8009B1C8->rank.field_0B++;
                        D_8009B1B0[1] = -1;
                        D_800E9FF0[D_8009B1D5 ^ 1].rank.field_0C++;
                        return;
                    }
                    view = (u8 *)&D_800E9FF0[D_8009B1D5 ^ 1];
                    life = (*(u16 *)((u8 *)( view ) + (  0x14 )))  - result;
                    (*(u16 *)((u8 *)( view ) + (  0x14 )))  = life;
                    if ((s16)life < 0) {
                        (*(u16 *)((u8 *)( view ) + (  0x14 )))  = 0;
                    }
                    if (D_800E9EF0[1] != 0) {
                        D_8009B1C8->rank.field_0B++;
                        D_8009B1C8->rank.effective_attacks++;
                    }
                    D_8009B1B0[1] = -1;
                    D_8009B1A4[1] = result;
                    return;
                }
            } else {
                D_8009B1B0[0] = -1;
                D_8009B1B0[1] = -1;
                D_8009B1A4[0] = 0;
                D_8009B1A4[1] = 0;
                if (result < -1) {
                    view = (u8 *)&D_800E9FF0[D_8009B1D5];
                    life = (*(u16 *)((u8 *)( view ) + (  0x14 )))  + result;
                    (*(u16 *)((u8 *)( view ) + (  0x14 )))  = life;
                    if ((s16)life < 0) {
                        (*(u16 *)((u8 *)( view ) + (  0x14 )))  = 0;
                    }
                    D_8009B1A4[0] = result;
                    D_8009B1B0[1] = 1;
                    if (D_8009B178[1] & 0x800) {
                        D_8009B1B0[0] = 1;
                        D_800E9FF0[D_8009B1D5 ^ 1].rank.defensive_wins++;
                        return;
                    }
                }
            }
        }
        break;

    case 4:
        do {
            if (D_8009B174 & 0x80) {
                break;
            }
            D_8009B174 |= 0x80;
            if (D_800E9EF0[1] == 0) {
                break;
            }
            {
                result = func_8001EE44(&D_801A7AD8[D_800E9EF0[0]->field_6A],
                                                    &D_801A7AD8[D_800E9EF0[1]->field_6A]);
                if (result != 0) {
                    side = D_800E9EF0[2];
                    D_8009B1B9 = 0;
                    if (result < 0) {
                        side = D_800E9EF0[3];
                        D_8009B1B9 = 1;
                    }
                    rec = &D_801A7AD8[D_800E9EF0[D_8009B1B9]->field_6A];
                    if (rec->flags & 0x200) {
                        level = D_801D4244[rec->card_id - 1] >> 0x12;
                    } else {
                        level = D_801D4244[rec->card_id - 1] >> 0x16;
                    }
                    result = level & 0xF;
                    func_8003FEE0(0x1D);
                    req =
                        ((DuelEffectRequest *)( func_8002C604(0xE) )) ;
                    {
                        u8 t = D_8009B174;

                        D_8009B17C = ((u8 *)( req )) ;
                        pos = side->field_30.h.field_30;
                        pos += 0x46;
                        req->field_00 = pos;
                        D_8009B1D0 = 0;
                        arg = side->field_30.h.field_32;
                        arg += 0x62;
                        req->field_02 = arg;
                        pos = result - 1;
                        req->field_1A = pos;
                        D_8009B174 = t | 0x60;
                    }
                }
                return;
            }
        } while (0);
        {
            u8 f = D_8009B174;

            if (f & 0x20) {
                if (!(((DuelEffectRequest *)( D_8009B17C )) ->flags & 0x80)) {
                    D_8009B174 = f & 0xDF;
                }
            }
            f = D_8009B174;
            if (f & 0x40) {
                D_8009B1D0 += 0x10;
                if ((s16)D_8009B1D0 >= 0x1F4) {
                    D_8009B174 = f & 0xBF;
                    D_8009B1D0 = 0x1F4;
                }
                view = (u8 *)&D_800EA0E8[D_8009B1B9];
                arg = D_8009B1D0;
                (*(u16 *)((u8 *)( view ) + (  0x36 )))  = arg;
                (*(u16 *)((u8 *)( view ) + (  0x38 )))  = arg;
            }
            if (!(D_8009B174 & 0x60)) {
                D_8009B174 = 7;
                if (D_8009B229 != 0) {
                    D_8009B174 = 5;
                    return;
                }
            }
        }
        break;

    case 5:
        if (!(D_8009B174 & 0x80)) {
            D_8009B174 |= 0x80;
            func_8003FF34();
            func_80015904();
            D_800E9ECC[0] = 0xFF;
            func_800156B8(0xFF);
            return;
        }
        if (!(D_800E9ECE[0] & 0x80) && func_80049120() == 0) {
            pair = D_800E9EF0;
            func_800472A8(D_8009B374);
            func_80059C18(D_8009B374);
            left = &D_801A7AD8[pair[0]->field_6A];
            right = &D_801A7AD8[pair[1]->field_6A];
            func_80024D34(pair[0]->field_6A, pair[0]->field_6B);
            left->flags |= (D_8009B178[0] & 0xA00) | 0x4000;
            left->stat_modifier = D_8009B170[0];
            func_80024D34(pair[1]->field_6A, pair[1]->field_6B);
            right->flags |= D_8009B178[1] & 0xA00;
            (*(u16 *)((u8 *)( right ) + (  0x12 )))  = D_8009B170[1];
            models = D_800EF658;
            D_8009B209 = -1;
            D_8009B208 = -1;
            models[0].model_id = (*(u16 *)((u8 *)( left ) + (  0xC ))) ;
            models[0].field_06 = 0;
            models[0].field_02 = 0;
            models[0].field_04 = 0;
            models[0].field_07 = (D_8009B178[0] >> 9) & 1;
            models[1].model_id = right->card_id;
            models[1].field_07 = (D_8009B178[1] >> 9) & 1;
            models[1].field_02 = 0;
            models[1].field_04 = 0;
            models[1].field_06 = (D_8009B178[1] >> 0xB) & 1;
            result = func_8001EFD4(pair[0], pair[1]);
            if (result == -1) {
                D_8009B208 = pair[0]->field_6A;
                D_8009B209 = pair[1]->field_6A;
            } else {
                if (result > 0) {
                    models[0].field_02 = 1;
                    D_8009B208 = pair[1]->field_6A;
                }
                if (result < 0) {
                    if (!(right->flags & 0x800)) {
                        models[1].field_02 = 1;
                        D_8009B208 = pair[0]->field_6A;
                    }
                }
            }
            D_8009B369 = 1;
            D_8009B269 = 3;
            D_8009B26C = 1;
            return;
        }
        break;

    case 7:
        if (D_800E9EF0[1] == 0) {
            D_8009B174 = 9;
            return;
        }
        D_8009B1B9 = 2;
        D_8009B174 = 6;
    case 6:
        D_8009B1B9 = D_8009B1B9 - 1;
        if ((s8)D_8009B1B9 >= 0) {
            D_8009B174 = 8;
        case 8:
            flags = D_8009B174;
            ix = D_8009B1B9;
            side = D_800E9EF0[ix + 2];
            if (!(flags & 0x80)) {
                D_8009B174 = flags | 0xC0;
                *(u32 *)&side->position = *(u32 *)&side->field_30;
                wins = D_8009B1B0;
                if (wins[ix] != 0) {
                    req =
                        ((DuelEffectRequest *)( func_8002C604(2) )) ;
                    req->field_00 = side->field_30.h.field_30 + 0x46;
                    req->field_02 = side->field_30.h.field_32 + 0x62;
                    result = D_8009B1A4[D_8009B1B9];
                    D_8009B17C = ((u8 *)( req )) ;
                    req->field_12 = result;
                    result = (result < 0 ? -result : result) / 1000;
                    if (result >= 3) {
                        result = 2;
                    }
                    req->field_1A = result;
                    if (wins[D_8009B1B9] > 0) {
                        D_8009B174 |= 0x20;
                    }
                    arg = result + 0x10;
                    if (D_8009B1B9 == 0) {
                        arg = result + 0xD;
                    }
                    func_8003FEE0(arg);
                    goto shake;
                }
                D_8009B174 = 6;
                return;
            }
        shake:
        {
            s32 f = D_8009B174;

            if (f & 0x40) {
                if (!(((DuelEffectRequest *)( D_8009B17C )) ->flags & 0x80)) {
                    f &= 0xBF;
                    D_8009B174 = f;
                    *(u32 *)&side->field_30 = side->position.word;
                    D_8009B1D0 = 0xA;
                    return;
                }
                if (!(f & 0x20) &&
                    ((DuelEffectRequest *)( D_8009B17C )) ->field_1D != 0) {
                    side->field_30.h.field_30 = side->position.h.field_28 + ((func_8008E590() & 3) - 2);
                    side->field_30.h.field_32 = side->position.h.field_2A + ((func_8008E590() & 3) - 2);
                    return;
                }
            } else {
                D_8009B1D0 = D_8009B1D0 - 1;
                if ((s16)D_8009B1D0 <= 0) {
                    if (D_8009B174 & 0x20) {
                        D_8009B174 = 6;
                        return;
                    }
                    D_8009B174 = 0xA;
                    return;
                }
            }
        }
        } else {
            D_8009B174 = 0xB;
            return;
        }
        break;

    case 9:
        if (!(D_8009B174 & 0x80)) {
            D_8009B174 |= 0x80;
            req = func_8002C68C(2);
            req->field_00 = 0xF0;
            req->field_02 = 0x78;
            result = func_8001EFD4(D_800E9EF0[0], 0);
            req->field_1A = result / 1000;
            if (req->field_1A >= 3) {
                req->field_1A = 2;
            }
            func_8003FEE0(req->field_1A + 0x10);
            req->field_12 = result;
            req->field_1A = req->field_1A + 3;
            return;
        }
        D_8009B174 = 0xB;
        return;

    case 10:
        side = D_800E9EF0[D_8009B1B9 + 2];
        if (!(D_8009B174 & 0x80)) {
            D_8009B174 |= 0x80;
            func_8001944C(side);
            func_8003FEE0(0x1B);
            req = ((DuelEffectRequest *)( func_8002C604(3) )) ;
            D_8009B17C = ((u8 *)( req )) ;
            req->field_00 = side->field_30.h.field_30 + 0x46;
            req->field_02 = side->field_30.h.field_32 + 0x62;
            if (D_8009B22A != 0) {
                req->field_1A = 1;
            }
            D_8009B1D0 = 2;
            return;
        }
        if (!(D_8009B174 & 0x40)) {
            D_8009B1D0 = D_8009B1D0 - 1;
            if ((s16)D_8009B1D0 <= 0) {
                D_8009B174 |= 0x40;
                func_80029528(D_8009B1B9);
                if (D_8009B1B9 != 1 || D_8009B22A == 0) {
                    D_800E9EF0[D_8009B1B9 + 2] = 0;
                    return;
                }
            }
        } else if (!(((DuelEffectRequest *)( D_8009B17C )) ->flags & 0x80)) {
            D_8009B174 = 6;
            if (D_8009B22A != 0) {
                D_8009B174 = 0xB;
                return;
            }
        }
        break;

    case 11:
        if (!(D_8009B174 & 0x80)) {
            D_8009B174 |= 0x80;
            if (D_800E9EF0[2] != 0) {
                func_80024D34(D_800E9EF0[0]->field_6A, D_800E9EF0[0]->field_6B);
                left = &D_801A7AD8[D_800E9EF0[0]->field_6A];
                left->flags |= (D_8009B178[0] & 0xA00) | 0x4000;
                left->stat_modifier = D_8009B170[0];
                func_80018080((DuelCardDisplayObject *)left->object);
            }
            if (D_800E9EF0[3] != 0) {
                if (D_800E9EF0[1] != 0) {
                    func_80024D34(D_800E9EF0[1]->field_6A, D_800E9EF0[1]->field_6B);
                    left = &D_801A7AD8[D_800E9EF0[1]->field_6A];
                    left->flags |= D_8009B178[1] & 0xA00;
                    left->stat_modifier = D_8009B170[1];
                    if (D_8009B22A != 0) {
                        left->flags |= D_8009B178[1] & 0x3000;
                    }
                    func_80018080((DuelCardDisplayObject *)left->object);
                }
            }
            func_8004036C(D_800E9EF0[0]);
            func_8004036C(D_800E9EF0[1]);
            o = D_8009B214;
            o->position.h.field_28 = 0xC;
            o->field_2C.h.field_2C = 0x10;
            o->field_6C = 1;
            o->update = (DisplayObjectCallback)func_8001ED20;
            o->position.h.field_2A = o->field_30.h.field_32;
            o = D_8009B21C;
            o->position.h.field_28 = 0x118;
            o->field_2C.h.field_2C = 0x10;
            o->field_6C = 1;
            o->update = (DisplayObjectCallback)func_8001ED20;
            o->position.h.field_2A = o->field_30.h.field_32;
        }
        if (!(D_8009B174 & 0x40)) {
            o = D_800E9EF0[2];
            if (o != 0) {
                result = (*((u8 *)( o ) + (  0xC ))) ;
                result -= 8;
                if (result <= 0) {
                    func_80029528(0);
                    D_800E9EF0[2] = 0;
                } else {
                    (*((u8 *)( o ) + (  0xE )))  = result;
                    (*((u8 *)( o ) + (  0xD )))  = result;
                    (*((u8 *)( o ) + (  0xC )))  = result;
                }
            }
            o = D_800E9EF0[3];
            if (o != 0) {
                result = (*((u8 *)( o ) + (  0xC ))) ;
                result -= 8;
                if (result <= 0) {
                    func_80029528(1);
                    D_800E9EF0[3] = 0;
                } else {
                    (*((u8 *)( o ) + (  0xE )))  = result;
                    (*((u8 *)( o ) + (  0xD )))  = result;
                    (*((u8 *)( o ) + (  0xC )))  = result;
                }
            }
            if (D_800E9EF0[2] == 0 && D_800E9EF0[3] == 0) {
                D_8009B174 |= 0x40;
                func_80015C0C();
                return;
            }
        } else {
            D_8009B23A = 5;
        }
        break;
    }
}
