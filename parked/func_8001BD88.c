/* CANDIDATO PORTADO de krystalgamer/memories-decomp (src/game/duel_scene_hand_actions.c, perfil gcc_2_8_1_g8_split):
 * C identico ao que casa la. Aqui NAO casa: a saida do cc1psx (SN, 2.8.1) e a do
 * mips-sony-psx-gcc 2.8.1 dele diferem no escalonamento -- um `lw 44($s3)` por ponteiro hoisted acima de `sh d_8009b20c` (gp) e o `sw 40($s3)` que o segue; 6 hunks, 1130/1130. Medido 2026-09-21
 * com os dois compiladores sobre ESTA unidade ($SP/cc1_s.py + gcc -S dele). Nao e
 * questao de fonte: e o par de builds do gcc 2.8.1. Flags: -quiet -O2 -G8 -fno-builtin -msplit-addresses; as -G8. */
typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
extern int func_8008E870(const char *fmt, ...);
extern s16 D_8009B19E;
extern u8 D_8009B1E2;
extern u16 D_8009B1E4;
extern const char D_80010060[];
typedef struct {
    u8 pad_00[8];
    u16 flags;                   
    u8 pad_0A[2];
    u32 color;                   
    u8 pad_10[6];
    u8 depth;                    
    u8 pad_17[0xA];
    u8 face;                     
    u8 pad_22[2];
    void (*update)();            
    union { struct { s16 x, y; } xy; s32 word; } target;   
    union { struct { u16 x, y; } xy; s32 word; } saved;    
    union { struct { u16 x, y; } xy; s32 word; } pos;      
    u8 pad_34[2];
    u16 home_x;                  
    u16 home_y;                  
    u8 pad_3A[0x22];
    u8 icon_state;               
    u8 pad_5D[3];
    s16 step;                    
    u8 pad_62[6];
    u8 kind;                     
    u8 pad_69;
    u8 card_index;               
    u8 pad_6B;
    u8 field_6C;                 
} HandCardObject;
void func_8001BD88(void);
extern u16 D_8009B23A;
extern s8 D_8009B208[8];
typedef struct {
    u8 pad_00[0xF];
    s8 col;
    s8 row;
} DuelFieldCursor;
extern u8 D_800907D8[];
extern u8 D_800907CC[];
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
extern u8 D_8009B19C;
extern DuelSideState *D_8009B1C8;
extern s8 D_8009B360[2 ] __attribute__((section(".data")));
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
extern u8 D_8009B1D4;
void func_800240B0(DuelCardPickCursor *cursor);
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
    u8 pad_00[4];
    struct DisplayObject *position_object;
    u8 pad_08[6];
    s8 slot_index;
    u8 pad_0F[6];
    u8 count;
    u8 pad_16[2];
} DuelHandStackState;
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
typedef struct {
    u8 pad_00[2 * 0x1C ];
    DuelCardPickCursor field;
    u8 pad_52[(4  * 0x1C )  - 2 * 0x1C  -
              sizeof(DuelCardPickCursor)];
} DuelSelectionSideCursors;
extern u8 D_800E9F10[];
extern u8 D_800E9F2C[];
extern u8 D_800E9F48[];
extern DuelCardPickCursor *D_8009B1B4;
void func_8001B938(DuelSelectionRecord *selection);
void func_8001BAF0(void);
void func_8001B8B8(DuelSelectionRecord *side);
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
typedef struct {
    s16 id;
     

    s8 deck_index;
    u8 data_block_index;
    u8 flags_04;
    u8 unk_05;
} DuelDeckCardRecord;
typedef struct {
    u8 pad_00000[0x4B6B4];
    DuelCardRecord field_cards[30 ];
    DuelDeckCardRecord cards[(40  * 2) ];
} DuelCardStagingDeckView;
extern u8 D_8015C424[];
u8 *func_80017F04(DuelCardRecord *arg0, s32 arg1, s32 arg2);
void func_80024914(DuelCardRecord *object);
typedef struct {
    u8 pad_00[0x19];
    u8 status;
} DuelCursorStatus;
extern s8 D_8009B160;
s32 func_80024060(DuelCursorStatus *object);
s32 func_80024088(DuelFieldCursor *cursor, s8 dir);
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
typedef struct DisplayLinkEntry {
    DisplayObject *object;
    DisplayObject *field_04;
    u8 pad_08[4];
} DisplayLinkEntry;
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
void func_80023144(DuelFieldDisplaySource *source, s32 index);
extern s16 D_8009B20C[2];
extern u16 D_8009B210;
struct DisplayObject;
extern u8 D_8009B254 __attribute__((section(".data")));
extern u16 D_8009B246 __attribute__((section(".data")));
extern u8 D_8009B24B __attribute__((section(".data")));
struct DisplayObject;
s32 func_8004002C(void);
void *func_800400AC(s32 index, s32 key);
void func_8004036C(void *object);
void func_800404CC(
    void *object, s32 x, s32 y, s32 field_67, s32 field_68,
    s32 field_69, s32 color, s32 texture
);
struct DisplayObject;
void *func_80040468(struct DisplayObject *object, s32 field_67,
                    s32 field_68, s32 field_69, s32 color, s32 texture);
void *func_80042B40(s32 value);
s32 func_800428EC(DisplayObject *object, s8 value);
void func_80042918(DisplayObject *object);
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
void func_8001EC70(DisplayObject *object);
extern DisplayObject *D_800E9EF0[];
void func_8001B780(DuelHandStackState *state);
void func_8001B7AC(DuelHandStackState *state);
s32 func_80017034(DuelCardRecord *card);
s32 func_8001BD48(void);
extern volatile u16 D_8009B398 __attribute__((section(".data")));
extern volatile u16 D_8009B3A4 __attribute__((section(".data")));
extern volatile u16 D_8009B394 __attribute__((section(".data")));
void func_800705D8(u8 *script);
s32 func_80070650(void);
extern u8 D_801A8000[];
struct DisplayObject;
void func_8003FEE0(u32);
void func_80028220(void);
extern u16 D_8009B162;
extern u16 D_8009B23A;
extern u8 D_8009B174;
extern DisplayObject *D_8009B188;
extern DisplayObject *D_8009B18C;
extern u8 D_800EAE88[];
void func_8001BD88(void)
{
    DuelSelectionRecord *side;
    DuelHandSlot *hand;
    DuelHandSlot *slot;
    DuelHandSlot *first_slot;
    DisplayObject **out;
    u8 *sprite;
    HandCardObject *obj;
    DuelCardRecord *card;
    s32 n;
    s32 i;
    s32 v;
    s32 value;
    s32 card_id;

    side = (DuelSelectionRecord *)(D_800E9F10 + D_8009B1D5 * (4  * 0x1C ) );
    if (!(D_8009B23A & 0x8000)) {
        D_8009B23A |= 0x8000;
        for (n = 6; n >= 0; n--) {
            D_800E9EF0[n] = 0;
        }
        D_8009B18C = 0;
        D_8009B188 = 0;
        D_8009B1B4 = (DuelCardPickCursor *)side;
        D_8009B162 = 0;
        side->field_0E = 0;
        side->field_15 = 0;
        obj = ((HandCardObject *)( 
            func_800400AC(func_8004002C(), 2) )) ;
        func_80040468(
            ((DisplayObject *)( obj )) , 3, 0, 2, 0xB, 0x20C);
        obj->flags |= 0x28;
        func_80042918(((DisplayObject *)( obj )) );
        func_800428EC(((DisplayObject *)( obj )) , 0xA);
        side->cursor_object = ((DisplayObject *)( obj )) ;
        func_8001B780(((DuelHandStackState *)( side )) );
        func_80023144((DuelFieldDisplaySource *)side, (D_800907CC[(s8)( side )->field_0E + D_8009B1D5 * 5]) );
        D_8009B174 = 1;
        if (D_8009B360[D_8009B1D5] >= 0) {
            D_8009B174 = 2;
        }
        return;
    }
    if (D_8009B23A & 0x4000) {
        func_800240B0(D_8009B1B4);
        if (D_8009B1D4 != 0) {
            return;
        }
        D_8009B1B4 = ((DuelCardPickCursor *)(( D_800E9F10 ) + D_8009B1D5 * (4  * 0x1C ) )) ;
        D_8009B23A &= 0xBFFF;
        return;
    }

    hand = &D_800EA030[(s8)side->field_0E];
    switch (D_8009B174 & 0xF) {
    case 2:
        if (!(D_8009B174 & 0x80)) {
            D_8009B174 |= 0x80;
            (*(u16 *)D_8009B20C)  = 0;
        }
        switch ((*(u16 *)D_8009B20C)  & 0xF) {
        case 0:
            if (!((*(u16 *)D_8009B20C)  & 0x8000)) {
                (*(u16 *)D_8009B20C)  |= 0x8000;
                func_80028220();
                func_800705D8(D_801A8000);
                return;
            }
            if (func_80070650() != 0) {
                *(s8 *)&D_8009B1E2 = -1;
                D_8009B19E = 0;
                if (D_800EAE88[1] != 0) {
                    D_8009B19E = 1;
                }
                (*(u16 *)D_8009B20C)  = 1;
                func_8001BAF0();
                return;
            }
            return;
        case 1:
            if (!((*(u16 *)D_8009B20C)  & 0x8000)) {
                (*(u16 *)D_8009B20C)  |= 0x8000;
                D_8009B1E2++;
                value = D_800EAE88[(s8)D_8009B1E2];
                if (value == 0) {
                    func_8001B8B8(side);
                    (*(u16 *)D_8009B20C)  = 2;
                    D_8009B19E &= 1;
                    if (D_8009B19E != 0) {
                        (*(u16 *)D_8009B20C)  = 3;
                    }
                    func_8003FEE0(7);
                    return;
                }
                if (value < 0xB) {
                    func_8008E870(D_80010060);
                    return;
                }
                D_8009B208[2] = value - 0xB;
                D_8009B1E4 = 6;
            }
            D_8009B1E4--;
            if ((s16)D_8009B1E4 <= 0) {
                D_8009B1E4 = 6;
                if ((s8)side->field_0E != D_8009B208[2]) {
                    func_8003FEE0(6);
                    if ((s8)side->field_0E > D_8009B208[2]) {
                        side->field_0E -= 1;
                    } else {
                        side->field_0E += 1;
                    }
                    func_8001B780(((DuelHandStackState *)( side )) );
                    func_80023144((DuelFieldDisplaySource *)side, (D_800907CC[(s8)( side )->field_0E + D_8009B1D5 * 5]) );
                    return;
                }
                if (D_8009B19E & 1) {
                    func_8001B7AC(((DuelHandStackState *)( side )) );
                }
                (*(u16 *)D_8009B20C)  &= 0x7FFF;
                return;
            }
            return;
        case 2:
            obj = ((HandCardObject *)( hand->object )) ;
            if (!((*(u16 *)D_8009B20C)  & 0x8000)) {
                (*(u16 *)D_8009B20C)  |= 0xC000;
                card_id = ((((DuelCardStagingDeckView *)D_8015C424)->field_cards[  obj->card_index  ]) .card_id) ;
                if (((D_801D4244[( card_id ) - 1] >> 26 ) & 0x1F )  < 20 ) {
                    if (D_800EAE88[8] == 0) {
                        (*(u16 *)D_8009B20C)  = 3;
                        return;
                    }
                }
                obj->target.xy.x = 0x86;
                obj->target.xy.y = 0x5A;
                obj->saved.xy.x = 0x10;
                obj->field_6C = 1;
                obj->update = func_8001EC70;
                func_800428EC(
                    ((DisplayObject *)( obj )) , (s8)(obj->depth + 4));
                side->cursor_object->flags &= 0xFFBF;
                return;
            }
            if ((*(u16 *)D_8009B20C)  & 0x4000) {
                if (func_80042B40(1) == 0) {
                    (*(u16 *)D_8009B20C)  &= 0xBFFF;
                    if ((*(u16 *)D_8009B20C)  & 0x1000) {
                        func_800428EC(
                            ((DisplayObject *)( obj )) , (s8)(obj->depth - 4));
                        (*(u16 *)D_8009B20C)  = 3;
                        side->cursor_object->flags |= 0x40;
                        return;
                    }
                    obj->saved.xy.x = obj->home_x;
                    obj->saved.xy.y = obj->home_y;
                    if (D_800EAE88[8] != 0) {
                        func_8003FEE0(0xB);
                        (*(u16 *)D_8009B20C)  |= 0x2000;
                        obj->flags |= 4;
                        return;
                    }
                }
            } else if ((*(u16 *)D_8009B20C)  & 0x2000) {
                obj->face += 8;
                if ((s8)obj->face < 0) {
                    obj->face = 0x80;
                    D_801A7AD8[obj->card_index].flags |= 0x1000;
                    (*(u16 *)D_8009B20C)  &= 0xDFFF;
                    return;
                }
            } else {
                card_id = ((((DuelCardStagingDeckView *)D_8015C424)->field_cards[  obj->card_index  ]) .card_id) ;
                value = ((D_801D4244[( card_id ) - 1] >> 26 ) & 0x1F ) ;
                if (value >= 20  && obj->face == 0 &&
                    value != 23  && value != 21 ) {
                    D_800E9EF0[0] = ((DisplayObject *)( obj )) ;
                    D_8009B1C8->hand[(s8)side->field_0E] = -1;
                    D_8009B174 = 5;
                    return;
                }
                obj->update = func_8001EC70;
                (*(u16 *)D_8009B20C)  |= 0x5000;
                *(s32 *)&obj->target = *(s32 *)&obj->saved;
                obj->saved.xy.x = 0x10;
                obj->field_6C = 1;
                return;
            }
            return;
        case 3:
            if (D_8009B162 != 0) {
                D_8009B160 = -1;
                return;
            }
            if (!((*(u16 *)D_8009B20C)  & 0x8000)) {
                (*(u16 *)D_8009B20C)  |= 0xC000;
                func_8001B938(side);
                D_8009B208[2] = D_800EAE88[6] - 6;
                if (D_8009B208[2] < 0) {
                    D_8009B208[2] = D_800EAE88[6] - 1;
                }
                D_8009B160 = -1;
                return;
            }
            if (func_80024088((void *)D_8009B1B4, D_8009B160) == 0) {
                if (D_8009B1B4->col == D_8009B208[2]) {
                    goto confirm;
                }
                D_8009B160 = 0;
                if (D_8009B208[2] < D_8009B1B4->col) {
                    D_8009B160 = 2;
                }
            }
            return;
        }
        break;
    case 1:
        if (!(D_8009B174 & 0x80)) {
            D_8009B174 |= 0x80;
            for (n = 0; n < 5; n++) {
                ((HandCardObject *)( D_800EA030[n].object )) ->color = 0x808080;
            }
        }
        if (func_8001BD48() != 0) {
            break;
        }
        if (D_8009B398 & 0x10) {
            card_id = ((((DuelCardStagingDeckView *)D_8015C424)->field_cards[  (D_800907CC[(s8)( side )->field_0E + D_8009B1D5 * 5])   ]) .card_id) ;
            D_8009B24B = 0x14;
            D_8009B254 = 2;
            D_8009B246 = card_id;
            return;
        }
        if (D_8009B394 & 0xA000) {
            value = (s8)side->field_0E;
            if (D_8009B394 & 0x2000) {
                value++;
                if (value >= 5) {
                    return;
                }
            } else {
                value--;
                if (value < 0) {
                    return;
                }
            }
            side->field_0E = value;
            func_8001B780(((DuelHandStackState *)( side )) );
            func_80023144((DuelFieldDisplaySource *)side, (D_800907CC[(s8)( side )->field_0E + D_8009B1D5 * 5]) );
            func_8003FEE0(6);
            return;
        }
        if ((D_8009B398 & 0xFFFF) == 0x1000 && D_8009B3A4 == 0x1000) {
            if (hand->active_09 == 0) {
                func_8001B7AC(((DuelHandStackState *)( side )) );
                return;
            }
        } else if ((D_8009B398 & 0x20) ||
                   ((D_8009B398 & 0xFFFF) == 0x4000 &&
                    D_8009B3A4 == 0x4000)) {
            value = hand->active_09;
            if (value != 0) {
                func_8003FEE0(0x2F);
                hand->active_09 = 0;
                ((HandCardObject *)( hand->object )) ->pos.xy.y += 4;
                func_8004036C(hand->child);
                hand->child = 0;
                side->field_15--;
                hand = D_800EA030;
                for (n = 0; n < 5; n++, hand++) {
                    v = hand->active_09;
                    if (v >= value) {
                        hand->active_09 = v - 1;
                        ((HandCardObject *)( hand->child )) ->icon_state =
                            (v - 2) * 0x10;
                    }
                }
                return;
            }
        } else {
            if (D_8009B3A4 & 3) {
                D_8009B1D4 = 0;
                D_8009B1B4 = ((DuelCardPickCursor *)(( D_800E9F2C ) + D_8009B1D5 * (4  * 0x1C ) )) ;
                D_8009B23A |= 0x4000;
                return;
            }
            if ((D_8009B398 & 0xC0) && side->field_15 != 1) {
                func_8003FEE0(7);
                D_8009B174 = 4;
                func_8001B8B8(side);
                if (side->field_15 == 0) {
                    D_8009B174 = 3;
                    return;
                }
            }
        }
        break;
    case 3:
        obj = ((HandCardObject *)( hand->object )) ;
        if (!(D_8009B174 & 0x80)) {
            D_8009B174 |= 0xC0;
            obj->target.xy.x = 0x86;
            obj->target.xy.y = 0x5A;
            obj->saved.xy.x = obj->pos.xy.x;
            obj->saved.xy.y = obj->pos.xy.y;
            func_80043178((void *)obj);
            obj->step = 0;
            func_800428EC(
                ((DisplayObject *)( obj )) , (s8)(obj->depth + 4));
            side->cursor_object->flags &= 0xFFBF;
        }
        if (D_8009B174 & 0x40) {
            func_8004318C(
                (void *)obj, obj->target.xy.x, obj->target.xy.y, obj->step);
            obj->step = obj->step + 0xAA;
            if (obj->step >= 0x800) {
                D_8009B174 &= 0xBF;
                obj->pos.word = obj->target.word;
                if (D_8009B174 & 0x10) {
                    side->cursor_object->flags |= 0x40;
                    func_800428EC(
                        ((DisplayObject *)( obj )) , (s8)(obj->depth - 4));
                    if (D_8009B174 & 0x20) {
                        D_8009B174 = 4;
                        return;
                    }
                    D_8009B174 = 1;
                    return;
                }
                card_id = ((DuelDeckCardRecord *)(((DuelCardStagingDeckView *)D_8015C424)->field_cards[ obj->card_index ]) .data)->id;
                value = ((D_801D4244[( card_id ) - 1] >> 26 ) & 0x1F ) ;
                if ((value < 20  || value == 21 ) && obj->face == 0) {
                    obj->step = 0x10;
                    D_8009B174 |= 0x20;
                    func_8003FEE0(0xB);
                }
                sprite = func_800400AC(func_8004002C(), 2);
                func_800404CC(
                    sprite, (s16)obj->pos.xy.x - 8, (s16)obj->pos.xy.y + 0x1E,
                    3, 1, 2, 0xB, 0x20C);
                func_80042918(((DisplayObject *)( sprite )) );
                func_800428EC(((DisplayObject *)( sprite )) , 0xA);
                (*(u16 *)((u8 *)( sprite ) + 8))  |= 0x28;
                D_8009B188 = ((DisplayObject *)( sprite )) ;
                sprite = func_800400AC(func_8004002C(), 2);
                func_800404CC(
                    sprite, (s16)obj->pos.xy.x + 0x3C, (s16)obj->pos.xy.y + 0x1E,
                    3, 1, 0, 0xB, 0x20C);
                func_80042918(((DisplayObject *)( sprite )) );
                func_800428EC(((DisplayObject *)( sprite )) , 0xA);
                (*(u16 *)((u8 *)( sprite ) + 8))  |= 0x28;
                D_8009B18C = ((DisplayObject *)( sprite )) ;
                return;
            }
        } else if (D_8009B174 & 0x20) {
            obj->flags |= 4;
            obj->face += obj->step;
            if (!(obj->face & 0x7F)) {
                if (obj->face == 0) {
                    obj->flags &= 0xFFFB;
                }
                D_8009B174 &= 0xDF;
                if (D_8009B174 & 0x10) {
                restore:
                    func_8004036C(D_8009B188);
                    func_8004036C(D_8009B18C);
                    D_8009B18C = 0;
                    D_8009B188 = 0;
                    *(s32 *)&obj->target = *(s32 *)&obj->saved;
                    func_80043178((void *)obj);
                    obj->step = 0;
                    D_8009B174 |= 0x50;
                    return;
                }
            }
        } else {
            if (D_8009B394 & 0xA000) {
                obj->step = 0x10;
                D_8009B174 |= 0x20;
                if (D_8009B394 & 0x2000) {
                    obj->step = -0x10;
                }
                func_8003FEE0(0xB);
                return;
            }
            if (D_8009B398 & 0x20) {
                func_8003FEE0(8);
                if (obj->face != 0) {
                    obj->step = 0x10;
                    D_8009B174 |= 0x30;
                    return;
                }
                goto restore;
            }
            if (D_8009B398 & 0xC0) {
                func_8003FEE0(7);
                D_801A7AD8[obj->card_index].flags &= 0xEFFF;
                if (obj->face != 0) {
                    D_801A7AD8[obj->card_index].flags |= 0x1000;
                }
                card_id = ((((DuelCardStagingDeckView *)D_8015C424)->field_cards[  obj->card_index  ]) .card_id) ;
                value = ((D_801D4244[( card_id ) - 1] >> 26 ) & 0x1F ) ;
                if (value >= 20  && obj->face == 0 &&
                    value != 23  && value != 21 ) {
                    func_8004036C(D_8009B188);
                    func_8004036C(D_8009B18C);
                    D_800E9EF0[0] = ((DisplayObject *)( obj )) ;
                    D_8009B18C = 0;
                    D_8009B188 = 0;
                    D_8009B1C8->hand[(s8)side->field_0E] = -1;
                    D_8009B174 = 5;
                    return;
                }
                D_8009B174 |= 0x70;
                goto restore;
            }
        }
        break;
    case 4:
        if (!(D_8009B174 & 0x80)) {
            D_8009B174 |= 0x80;
            D_8009B210 = 0;
            func_8001B938(side);
            D_8009B174 |= 0x40;
        }
        if (D_8009B174 & 0x40) {
            if (D_8009B162 == 0) {
                D_8009B174 &= 0xBF;
                if (D_8009B174 & 0x10) {
                    D_8009B174 = 1;
                    D_8009B1B4 = ((DuelCardPickCursor *)(( D_800E9F10 ) + D_8009B1D5 * (4  * 0x1C ) )) ;
                    if (side->field_15 == 0) {
                        D_8009B174 = 3;
                        return;
                    }
                }
            }
        } else if (func_80024060((void *)D_8009B1B4) == 0) {
            value = func_80017034(
                &D_801A7AD8[D_800907D8[(((DuelSelectionSideCursors *)D_800E9F10)[D_8009B1D5].field) .row * 5 + (((DuelSelectionSideCursors *)D_800E9F10)[D_8009B1D5].field) .col +
                                       D_8009B1D5 * 20]]);
            if (value != 0) {
                D_8009B24B = 0x14;
                D_8009B246 = value;
                D_8009B254 = 2;
                return;
            }
            if (D_8009B398 & 0x20) {
                D_8009B162 = 0xC;
                D_8009B174 |= 0x50;
                func_8003FEE0(8);
                return;
            }
            if (D_8009B398 & 0xC0) {
            confirm:
                func_8003FEE0(7);
                for (n = 6; n >= 0; n--) {
                    D_800E9EF0[n] = 0;
                }
                n = D_8009B1B4->row * 5 + D_8009B1B4->col;
                value = D_800907D8[n + D_8009B1D5 * 20];
                card = &D_801A7AD8[value];
                D_8009B19C = value;
                i = 0;
                if (card->flags & 0x8000) {
                    obj = ((HandCardObject *)( card->object )) ;
                    i = 1;
                    D_800E9EF0[0] = ((DisplayObject *)( 
                        func_80017F04(
                            card, (*(s16 *)((u8 *)( card ) + 8)) , (*(s16 *)((u8 *)( card ) + 0xA)) ) )) ;
                    func_80024914(&D_801A7AD8[obj->card_index]);
                } else if (side->field_15 == 0 &&
                           ((HandCardObject *)( hand->object )) ->kind ==
                               23  &&
                           D_8009B1B4->row == 2) {
                    return;
                }
                if (side->field_15 == 0) {
                    hand->active_09 = 1;
                    if (((HandCardObject *)( hand->object )) ->face != 0) {
                        D_8009B1C8->rank.face_down_plays++;
                    }
                }
                 

                for (value = 1, first_slot = D_800EA030; value < 6; value++) {
                    s8 none = -1;

                    do {
                        n = 0;
                        out = &D_800E9EF0[i];
                        slot = first_slot;
                        for (;;) {
                            if (slot->active_09 == value) {
                                D_8009B1C8->hand[n] = none;
                                i++;
                                *out = ((DisplayObject *)( slot->object )) ;
                                break;
                            }
                            n++;
                            slot++;
                            if (n >= 5) {
                                value = 8;
                                break;
                            }
                        }
                    } while (0);
                }
                D_8009B174 = 6;
                return;
            }
        }
        break;
    case 6:
        if (!(D_8009B174 & 0x80)) {
            D_8009B162 = 0xC;
            D_8009B174 |= 0x80;
            D_8009B1B4 = ((DuelCardPickCursor *)(( D_800E9F48 ) + D_8009B1D5 * (4  * 0x1C ) )) ;
        }
        if (D_8009B162 == 0) {
            D_8009B23A = 7;
        }
        break;
    case 5:
        if (!(D_8009B174 & 0x80)) {
            D_8009B174 |= 0x80;
            hand->object = 0;
            D_8009B162 = 8;
            D_8009B1B4 = ((DuelCardPickCursor *)(( D_800E9F10 ) + D_8009B1D5 * (4  * 0x1C ) )) ;
        }
        if (D_8009B162 == 0) {
            D_8009B23A = 6;
        }
        break;
    }
}
