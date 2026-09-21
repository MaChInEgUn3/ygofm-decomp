/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/duel_scene_field_actions.c (DuelScene_UpdateFieldActions), profile gcc_2_8_1_g8_split_comm.
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
void func_8001D670(void);
extern s32 D_8009B1BC;
extern u8 D_8009B21A;
extern u16 D_8009B170;
extern u16 D_8009B172;
extern u16 D_8009B178;
extern u16 D_8009B17A;
extern u16 D_8009B23A;
extern s16 D_800907AC[2 ][2][4];
typedef struct {
    u8 pad_00[0xF];
    s8 col;
    s8 row;
} DuelFieldCursor;
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
extern u8 D_8009B19C;
extern DuelSideState D_800E9FF0[2 ];
extern DuelSideState *D_8009B1C8;
extern u8 D_8009B229;
extern s8 D_8009B360[2 ] __attribute__((section(".data")));
extern u8 D_8009B165;
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
typedef struct {
    DuelSelectionRecord records[4 ];
} DuelSelectionSide;
extern u8 D_800E9F10[];
extern u8 D_800E9F48[];
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
extern DuelCardRecord D_801A7AD8[];
extern s32 D_801D4244[];
int func_8001700C(DuelCardRecord *object);
extern u8 D_8015C424[];
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
void func_80017E3C(DuelCardDisplayObject *object);
u8 *func_80017F04(DuelCardRecord *arg0, s32 arg1, s32 arg2);
void func_80024914(DuelCardRecord *object);
void func_80024954(DuelCardRecord *object);
typedef struct {
    u8 pad_00[0x19];
    u8 status;
} DuelCursorStatus;
extern s8 D_8009B160;
extern u8 D_8009B1D6;
extern u8 D_8009B1D7;
s32 func_80024060(DuelCursorStatus *object);
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
void func_8002348C(DuelFieldDisplaySource *source);
void func_800234E4(DuelFieldDisplaySource *source);
void func_8001D240(DisplayObject *object);
extern ;
void func_8001D344(DisplayObject *object);
void func_8001D3C4(DisplayObject *o);
DisplayObject *func_8001D518(DisplayObject *source);
s32 func_8001D5B4(DuelFieldCursor *cursor);
s32 func_80020988(void);
extern s16 D_8009B20C[2];
struct DisplayObject;
extern u8 D_8009B254 __attribute__((section(".data")));
extern u16 D_8009B246 __attribute__((section(".data")));
extern u8 D_8009B24B __attribute__((section(".data")));
s32 func_8001BD48(void);
extern u16 D_8009B16C;
extern u16 D_8009AF20[2];
extern u8 D_800EAE91[];
extern u8 D_800EAE92[];
void func_800705D8(u8 *script);
s32 func_80070650(void);
extern u8 D_801A9800[];
struct DisplayObject;
void func_8004036C(void *object);
typedef struct {
    u8 pad_00[0x30];
    s16 x;
    s16 y;
    s16 z;
    s16 velocity_x;
    s16 velocity_y;
    s16 velocity_z;
    u8 pad_3C[0x26];
    u8 fraction_x;
    u8 fraction_y;
    u8 fraction_z;
} DisplayObjectVelocity;
void *func_80042B40(s32 value);
s32 func_800428EC(DisplayObject *object, s8 value);
void func_800429D8(DisplayObjectVelocity *object);
extern DisplayObject *D_800E9EF0[];
s32 func_80017034(DuelCardRecord *card);
void func_80022D94(s32 frames, s32 x, s32 z, s32 y, s32 value);
extern volatile u16 D_8009B398 __attribute__((section(".data")));
extern u32 D_8009B300 __attribute__((section(".data")));
void func_8003FEE0(u32);
void func_80028220(void);
extern u16 D_8009B162;
extern u16 D_8009B23A;
extern u8 D_8009B174;
extern u8 D_8009B152;
extern DisplayObject *D_8009B1CC;
extern DisplayObject *D_8009B1F8;
extern u8 D_800EAE88[];
extern u16 D_8009B170;;
extern u16 D_8009B172;;
extern u16 D_8009B178;;
extern u16 D_8009B17A;;
extern u8 D_8009B19C;;
void func_8001D670(void)
{
    DuelSelectionRecord *side;
    DuelSelectionRecord *rec;
    u8 *o;
    u8 *other;
    DuelCardRecord *card;
    DuelCardRecord *pick;
    DisplayObject *co;
    s32 a;
    s32 k;
    s32 n;
    s32 i;
    s32 x;
    s32 y;
    s32 t;
    s32 lvl;
    s32 r;
    s32 d;
    s32 big;
    u8 *pw;
    s32 idx;
    s8 row;
    u32 f;
    s32 flags;

    side = (DuelSelectionRecord *)D_800E9F48 + D_8009B1D5 * 4 ;
    if (!(D_8009B23A & 0x8000)) {
        D_8009B23A |= 0x8000;
        if (D_800E9FF0[0].life_points.signed_value == 0 ||
            D_800E9FF0[1].life_points.signed_value == 0) {
            D_8009B165 = D_8009B1D5;
            if (D_800E9FF0[D_8009B1D5].life_points.signed_value == 0) {
                D_8009B165 = D_8009B1D5 ^ 1;
            }
            D_800E9FF0[D_8009B165].rank.result_adjustment = 2;
            D_8009B23A = 0xC;
            return;
        }
        D_8009B1F8 = 0;
        D_8009B21A = 0;
        D_8009B1B4 = ((DuelCardPickCursor *)( side )) ;
        side->field_12 = 4;
        side->field_0C = 0xAE;
        y = 1;
        side->field_18 = y;
        side->field_13 = 0;
        side->field_11 = 0;
        D_8009B162 = 3;
        D_8009B174 = y;
    }

    switch (D_8009B174 & 0xF) {
    case 1:
        if (D_8009B162 == 0) {
            D_8009B174 = 3;
        }
        return;
    case 2:
        if (!(D_8009B174 & 0x80)) {
            D_8009B174 |= 0x80;
            func_80028220();
            func_800705D8(D_801A9800);
            D_8009B20C[0] = 0;
            return;
        }
        flags = (u16)D_8009B20C[0];
        k = flags & 0xF;
        switch (k) {
        case 0:
            a = func_80070650();
            if (a == 0) {
                return;
            }
            if (a == 3) {
                D_8009B16C &= 0xEFFF;
                func_8004036C(D_8009B1F8);
                D_8009B1F8 = 0;
                D_8009B174 = 0xA;
                func_8003FEE0(0x30);
                return;
            }
            D_8009B20C[0] = 1;
            return;
        case 1:
            if (!(flags & 0x8000)) {
                a = D_800EAE91[0];
                D_8009B20C[0] = flags | 0x8000;
                D_8009B160 = -1;
                D_8009B1D7 = 2;
                D_8009B1D6 = (a - 1) % 5;
                if (a >= 6) {
                    D_8009B1D7 = 3;
                }
            }
            if (func_8001D5B4((DuelFieldCursor *)side) != 0) {
                return;
            }
            if (D_800EAE88[0xA] == 0 && D_800EAE88[0xB] == 0) {
                card = (&D_801A7AD8[D_800907D8[( side )->row * 5 + ( side )->col + D_8009B1D5 * 20]]) ;
                f = card->flags;
                if (f & 0x8000) {
                    card->flags = f | 0x4000;
                    func_80017E3C(card->object);
                }
                D_8009B174 = 2;
                return;
            }
            D_8009B20C[0] = 3;
            if (D_800EAE88[0xB] != 0 && D_800EAE88[9] < 6) {
                D_8009B20C[0] = 2;
            }
            return;
        case 2:
            card = (&D_801A7AD8[D_800907D8[( side )->row * 5 + ( side )->col + D_8009B1D5 * 20]]) ;
            if (!(flags & 0x8000)) {
                f = card->flags;
                D_8009B20C[0] = flags | 0x8000;
                if (f & 0x8000) {
                    if (f & 0x800) {
                        card->flags = f | 0x4000;
                        func_80017E3C(card->object);
                        goto back_to_menu;
                    }
                    o = card->object;
                    (*(s32 *)((u8 *)( o ) + (  0x24 )))  = (s32)func_8001D240;
                    (*((u8 *)( o ) + (  0x6C )))  = 0xF;
                    return;
                }
            back_to_menu:
                D_8009B174 = 2;
                return;
            }
            if (func_80042B40(0xF) == 0) {
                card->flags |= 0x4000;
                func_80017E3C(card->object);
                D_8009B174 = k;
            }
            return;
        case 3:
            if (!(flags & 0x8000)) {
                D_8009B20C[0] = flags | 0x8000;
                card = (&D_801A7AD8[D_800907D8[( side )->row * 5 + ( side )->col + D_8009B1D5 * 20]]) ;
                if (card->flags & 0x800) {
                    D_8009B20C[0] = flags | 0xC000;
                    o = card->object;
                    (*(s32 *)((u8 *)( o ) + (  0x24 )))  = (s32)func_8001D240;
                    (*((u8 *)( o ) + (  0x6C )))  = 0xF;
                }
                return;
            }
            if (!(flags & 0x4000) || func_80042B40(0xF) == 0) {
                D_8009B21A = 1;
                goto attack;
            }
            return;
        }
        return;
    case 3:
        if (!(D_8009B174 & 0x80)) {
            D_8009B174 |= 0xC0;
            D_8009B21A = 0;
            if (D_8009B360[D_8009B1D5] >= 0) {
                D_8009B174 = 2;
                return;
            }
            side->status = 0;
        }
        if (func_80042B40(0xF) != 0) {
            return;
        }
        if (func_80024060((DuelCursorStatus *)side) != 0) {
            D_8009B174 |= 0x40;
            return;
        }
        if (D_8009B174 & 0x40) {
            D_8009B174 &= 0xBF;
            if (side->row == 2
                && func_8001700C((&D_801A7AD8[D_800907D8[( side )->row * 5 + ( side )->col + D_8009B1D5 * 20]]) ) != 0) {
                D_8009B1F8 = func_8001D518(side->cursor_object);
            } else {
                func_8004036C(D_8009B1F8);
                D_8009B1F8 = 0;
            }
        }
        if (D_8009B360[D_8009B1D5] < 0 && (D_8009B398 & 0x800)) {
            D_8009B174 = 0xB;
            return;
        }
        if (func_8001BD48() != 0) {
            return;
        }
        if (D_8009B398 & 0xC) {
            r = side->row;
            card = &D_801A7AD8[D_800907D8[r * 5 + side->col + D_8009B1D5 * 20]];
            if (r == 2 && func_8001700C(card) != 0) {
                o = card->object;
                (*(s32 *)((u8 *)( o ) + (  0x24 )))  = (s32)func_8001D240;
                (*((u8 *)( o ) + (  0x6C )))  = 0xF;
                func_8003FEE0(0xB);
            }
            return;
        }
        a = func_80017034((&D_801A7AD8[D_800907D8[( side )->row * 5 + ( side )->col + D_8009B1D5 * 20]]) );
        if (a != 0) {
            D_8009B24B = 0x14;
            D_8009B246 = a;
            D_8009B254 = 2;
            return;
        }
        if (D_8009B398 & 0xC0) {
            if (side->row == 2) {
                if (D_8009B1C8->swords_turns_remaining != 0) {
                    func_8003FEE0(9);
                    return;
                }
                if (D_8009B16C & 0x1000) {
                    func_8003FEE0(9);
                    return;
                }
            }
            if (side->row < 2) {
                func_8003FEE0(9);
                return;
            }
        attack:
            i = side->row * 5 + side->col;
            card = &D_801A7AD8[D_800907D8[i + D_8009B1D5 * 20]];
            if (((*(s32 *)((u8 *)( card ) + (  0x14 )))  & 0xC8000000) == 0x80000000) {
                func_8003FEE0(7);
                func_8004036C(D_8009B1F8);
                D_8009B1F8 = 0;
                a = side->row;
                if (a >= 2) {
                    side = ((DuelSelectionRecord *)(D_800E9F10 + 0x54))  + D_8009B1D5 * 4 ;
                    if (a >= 3) {
                        D_8009B174 = 7;
                        if (((D_801D4244[( card->card_id ) - 1] >> 0x1A) & 0x1F)  == 0x17) {
                            x = 2;
                            y = 3;
                            side->field_11 = x;
                            side->row = x;
                            side->field_12 = y;
                            x = 4;
                            D_8009B174 = x;
                        }
                    } else {
                        x = 4;
                        y = 1;
                        D_8009B174 = x;
                        side->field_11 = y;
                        x = 2;
                        side->field_12 = x;
                        side->row = y;
                    }
                }
            } else {
                func_8003FEE0(9);
            }
        }
        return;
    case 4:
        side = ((DuelSelectionRecord *)(D_800E9F10 + 0x54))  + D_8009B1D5 * 4 ;
        if (!(D_8009B174 & 0x80)) {
            D_8009B174 |= 0x80;
            D_8009B1B4 = ((DuelCardPickCursor *)( side )) ;
            side->field_18 = 0;
            side->field_0C = 0x74;
            func_800234E4((DuelFieldDisplaySource *)side);
            func_80022D94(0x10, 0x14E, 0x3FE, D_8009AF20[D_8009B1D5],
                D_800907AC[D_8009B1D5][side->field_18][side->row]);
            o = (u8 *)side->cursor_object;
            other = *(u8 **)((u8 *)((DuelSelectionRecord *)(D_800E9F10 + 0x54))  + D_8009B1D5 * 0x70 - 0x18);
            func_800429D8((void *)o);
            (*(s16 *)((u8 *)( o ) + (  0x60 )))  = 0x10;
            (*((u8 *)( o ) + (  0x6C )))  = 0;
            (*(s32 *)((u8 *)( o ) + (  0x2C )))  = (*(s32 *)((u8 *)( o ) + (  0x28 ))) ;
            (*(s16 *)((u8 *)( o ) + (  0x36 )))  = (((*(s16 *)((u8 *)( o ) + (  0x28 )))  - (*(s16 *)((u8 *)( other ) + (  0x28 ))) ) << 8) / 16;
            (*(s16 *)((u8 *)( o ) + (  0x3A )))  = (((*(s16 *)((u8 *)( o ) + (  0x2A )))  - (*(s16 *)((u8 *)( other ) + (  0x2A ))) ) << 8) / 16;
            D_8009B162 = 0x52;
            ((DisplayObject *)( o )) ->position.word =
                ((DisplayObject *)( other )) ->position.word;
            return;
        }
        if (D_8009B162 == 0) {
            func_8002348C((DuelFieldDisplaySource *)side);
            D_8009B174 = 6;
            if (D_8009B21A != 0) {
                D_8009B174 = 5;
            }
        }
        return;
    case 5:
        side = ((DuelSelectionRecord *)(D_800E9F10 + 0x54))  + D_8009B1D5 * 4 ;
        if (!(D_8009B174 & 0x80)) {
            D_8009B174 |= 0x80;
            D_8009B229 = 0;
            a = D_800EAE92[0];
            if (a < 0x38) {
                if (a >= 6) {
                    D_8009B1D6 = a - 6;
                    x = 3;
                } else {
                    D_8009B1D6 = a - 1;
                    x = 2;
                }
            } else {
                D_8009B1D6 = 0x3C - a;
                x = 1;
            }
            D_8009B1D7 = x;
        }
        if (func_8001D5B4((DuelFieldCursor *)side) != 0) {
            return;
        }
        goto commit;
    case 6:
        side = ((DuelSelectionRecord *)(D_800E9F10 + 0x54))  + D_8009B1D5 * 4 ;
        if (D_8009B174 & 0x80) {
            D_8009B174 |= 0x80;
            D_8009B1B4 = ((DuelCardPickCursor *)( side )) ;
        }
        if (D_8009B174 & 0x40) {
            if (D_8009B162 == 0) {
                func_8004036C(side->cursor_object);
                side->cursor_object = 0;
                D_8009B174 = 3;
                D_8009B1B4 = ((DuelCardPickCursor *)( 
                    &((DuelSelectionSide *)D_800E9F10)[D_8009B1D5].records[2] )) ;
            }
            return;
        }
        if (func_80024060((DuelCursorStatus *)side) != 0) {
            return;
        }
        if (D_8009B398 & 0x20) {
            func_80022D94(0x10, 0x14E, 0x3FE, D_8009AF20[D_8009B1D5],
                D_800907AC[D_8009B1D5][(((DuelSelectionSide *)D_800E9F10)[D_8009B1D5].records[2]) .field_18][(((DuelSelectionSide *)D_800E9F10)[D_8009B1D5].records[2]) .row]);
            o = (u8 *)side->cursor_object;
            other = (u8 *)(((DuelSelectionSide *)D_800E9F10)[D_8009B1D5].records[2]) .cursor_object;
            func_800429D8((void *)o);
            (*(s16 *)((u8 *)( o ) + (  0x60 )))  = 0x10;
            (*((u8 *)( o ) + (  0x6C )))  = 0;
            (*(s16 *)((u8 *)( o ) + (  0x36 )))  = (((*(s16 *)((u8 *)( other ) + (  0x28 )))  - (*(s16 *)((u8 *)( o ) + (  0x28 ))) ) << 8) / 16;
            (*(s16 *)((u8 *)( o ) + (  0x3A )))  = (((*(s16 *)((u8 *)( other ) + (  0x2A )))  - (*(s16 *)((u8 *)( o ) + (  0x2A ))) ) << 8) / 16;
            (*(s32 *)((u8 *)( o ) + (  0x2C )))  = (*(s32 *)((u8 *)( other ) + (  0x28 ))) ;
            D_8009B162 = 0x58;
            D_8009B174 |= 0x40;
            return;
        }
        a = func_80017034((&D_801A7AD8[D_800907D8[( side )->row * 5 + ( side )->col + D_8009B1D5 * 20]]) );
        if (a != 0) {
            D_8009B24B = 0x14;
            D_8009B246 = a;
            D_8009B254 = 2;
            return;
        }
        if (!(D_8009B398 & 0xC0)) {
            return;
        }
        D_8009B229 = 0;
        if (D_8009B398 & 0x80) {
            D_8009B229 = 1;
        }
    commit:
        a = 0;
        if (side->row == 1) {
            i = 5;
            a = 1;
            for (n = 0; n < 5; n++, i++) {
                pick = &D_801A7AD8[D_800907D8[i + D_8009B1D5 * 20]];
                if (pick->flags & 0x8000) {
                    a = 0;
                    break;
                }
            }
        }
        i = side->row * 5 + side->col;
        pick = &D_801A7AD8[D_800907D8[i + D_8009B1D5 * 20]];
        if (a == 0 && !(pick->flags & 0x8000)) {
            func_8003FEE0(9);
            return;
        }
        func_8003FEE0(7);
        for (n = 6; n >= 0; n--) {
            D_800E9EF0[n] = 0;
        }
        i = (((DuelSelectionSide *)D_800E9F10)[D_8009B1D5].records[2]) .row * 5 + (((DuelSelectionSide *)D_800E9F10)[D_8009B1D5].records[2]) .col;
        pick = &D_801A7AD8[D_800907D8[i + D_8009B1D5 * 20]];
        D_8009B178 = (*(u16 *)((u8 *)( pick ) + (  0x16 ))) ;
        D_8009B170 = (*(u16 *)((u8 *)( pick ) + (  0x12 ))) ;
        o = func_80017F04(pick, (*(s16 *)((u8 *)( pick ) + (  8 ))) , (*(s16 *)((u8 *)( pick ) + (  0xA ))) );
        func_800428EC(((DisplayObject *)( o )) , -0xA);
        D_800E9EF0[0] = ((DisplayObject *)( o )) ;
        d = pick->card_id;
        func_80024914(pick);
        i = side->row * 5 + side->col;
        pick = &D_801A7AD8[D_800907D8[i + D_8009B1D5 * 20]];
        if (a == 0) {
            D_8009B17A = (*(u16 *)((u8 *)( pick ) + (  0x16 ))) ;
            D_8009B172 = (*(u16 *)((u8 *)( pick ) + (  0x12 ))) ;
            o = func_80017F04(pick, (*(s16 *)((u8 *)( pick ) + (  8 ))) , (*(s16 *)((u8 *)( pick ) + (  0xA ))) );
            D_800E9EF0[1] = ((DisplayObject *)( o )) ;
            D_8009B19C = (*((u8 *)( o ) + (  0x6A ))) ;
            func_80024914(pick);
            if (((D_801D4244[( d ) - 1] >> 0x1A) & 0x1F)  == 0x17) {
                D_8009B174 = 8;
                return;
            }
        }
        D_8009B23A = 9;
        return;
    case 7:
        if (!(D_8009B174 & 0x80)) {
            D_8009B174 |= 0x80;
            i = side->row * 5 + side->col;
            card = &D_801A7AD8[D_800907D8[i + D_8009B1D5 * 20]];
            o = func_80017F04(card, (*(s16 *)((u8 *)( card ) + (  8 ))) , (*(s16 *)((u8 *)( card ) + (  0xA ))) );
            card->flags &= 0x7FFF;
            if (card->flags & 0x1000) {
                (*((u8 *)( o ) + (  0x21 )))  = 0x80;
                (*(u16 *)((u8 *)( o ) + (  8 )))  |= 4;
            }
            (*(s16 *)((u8 *)( o ) + (  0x60 )))  = 0xC;
            (*(s32 *)((u8 *)( o ) + (  0x24 )))  = (s32)func_8001D3C4;
            (*(s16 *)((u8 *)( o ) + (  0x28 )))  = 0x86;
            (*(s16 *)((u8 *)( o ) + (  0x2A )))  = 0x5A;
            (*(s16 *)((u8 *)( o ) + (  0x2C )))  = 0;
            (*((u8 *)( o ) + (  0x6C )))  = 1;
            D_8009B1CC = ((DisplayObject *)( o )) ;
            co = side->cursor_object;
            co->flags &= 0xFFBF;
            if (D_8009B21A == 0) {
                D_8009B1BC = 0x202020;
                card = D_801A7AD8;
                for (n = 0; n < 0x1E; card++, n++) {
                    if (card->flags & 0x8000) {
                        o = card->object;
                        (*((u8 *)( o ) + (  0x6C )))  = 1;
                        (*(s16 *)((u8 *)( o ) + (  0x60 )))  = 8;
                        (*(s32 *)((u8 *)( o ) + (  0x24 )))  = (s32)func_8001D344;
                        a = 0x20;
                        if (card->flags & 0x4000) {
                            a = 0x10;
                        }
                        (*(s16 *)((u8 *)( o ) + (  0x2C )))  = a;
                        (*(s16 *)((u8 *)( o ) + (  0x2A )))  = a;
                        (*(s16 *)((u8 *)( o ) + (  0x28 )))  = a;
                    }
                }
                D_8009B152 = 0;
                D_8009B174 |= 0x20;
            }
            return;
        }
        if (D_8009B21A != 0) {
            if (func_80042B40(1) != 0) {
                return;
            }
            func_80024954(&D_801A7AD8[(*((u8 *)( D_8009B1CC ) + (  0x6A ))) ]);
            D_8009B174 = 9;
            D_800E9EF0[0] = D_8009B1CC;
            return;
        }
        if (D_8009B174 & 0x20) {
            a = *(u8 *)&D_8009B300;
            flags = (u8)D_8009B1BC;
            if (a >= flags) {
                a -= 8;
                t = a < flags;
            } else {
                a += 8;
                t = flags < a;
            }
            if (t != 0) {
                a = flags;
            }
            t = (a << 16) | (a << 8) | a;
            D_8009B300 = t;
            if (t == D_8009B1BC && func_80042B40(1) == 0) {
                D_8009B174 &= 0xDF;
            }
            return;
        }
        if (D_8009B174 & 0x40) {
            if (D_8009B174 & 0x10) {
                D_801A7AD8[(*((u8 *)( D_8009B1CC ) + (  0x6A ))) ].flags |= 0x8000;
                func_8004036C(D_8009B1CC);
                D_8009B174 = 3;
                co = side->cursor_object;
                co->flags |= 0x40;
                return;
            }
            func_80024954(&D_801A7AD8[(*((u8 *)( D_8009B1CC ) + (  0x6A ))) ]);
            D_8009B174 = 9;
            D_800E9EF0[0] = D_8009B1CC;
            return;
        }
        a = func_80020988();
        if (a == 0) {
            return;
        }
        if (a != 1) {
            D_8009B174 |= 0x10;
            func_8003FEE0(8);
            o = (u8 *)D_8009B1CC;
            (*(s16 *)((u8 *)( o ) + (  0x60 )))  = 0xC;
            pw = D_8015C424;
            (*(s32 *)((u8 *)( o ) + (  0x24 )))  = (s32)func_8001D3C4;
            (*(u16 *)((u8 *)( o ) + (  0x28 )))  = (big = 0x48000, (*(u16 *)((u8 *)( pw + ( (*((u8 *)( o ) + (  0x6A )))  ) * 0x1C + big ) + (  (  0x36BC ) ))) ) ;
            (*(u16 *)((u8 *)( o ) + (  0x2A )))  = (big = 0x48000, (*(u16 *)((u8 *)( pw + ( (*((u8 *)( o ) + (  0x6A )))  ) * 0x1C + big ) + (  (  0x36BE ) ))) ) ;
            (*(s16 *)((u8 *)( o ) + (  0x2C )))  = 0;
            if (D_801A7AD8[(*((u8 *)( o ) + (  0x6A ))) ].flags & 0x1000) {
                (*(s16 *)((u8 *)( o ) + (  0x2C )))  = 0x80;
            }
            (*((u8 *)( o ) + (  0x6C )))  = 1;
        } else {
            func_8003FEE0(7);
        }
        D_8009B1BC = 0x808080;
        card = D_801A7AD8;
        D_8009B174 |= 0x60;
        for (n = 0; n < 0x1E; card++, n++) {
            if (card->flags & 0x8000) {
                o = card->object;
                (*((u8 *)( o ) + (  0x6C )))  = 1;
                (*(s16 *)((u8 *)( o ) + (  0x60 )))  = 8;
                (*(s32 *)((u8 *)( o ) + (  0x24 )))  = (s32)func_8001D344;
                a = 0x80;
                if (card->flags & 0x4000) {
                    a = 0x40;
                }
                (*(s16 *)((u8 *)( o ) + (  0x2C )))  = a;
                (*(s16 *)((u8 *)( o ) + (  0x2A )))  = a;
                (*(s16 *)((u8 *)( o ) + (  0x28 )))  = a;
            }
        }
        return;
    case 8:
        if (!(D_8009B174 & 0x80)) {
            rec = ((DuelSelectionRecord *)(D_800E9F10 + 0x54))  + D_8009B1D5 * 4 ;
            co = rec->cursor_object;
            D_8009B174 |= 0x80;
            D_8009B1B4 = ((DuelCardPickCursor *)( rec )) ;
            func_8004036C(co);
            D_8009B162 = 8;
            ((DuelSelectionRecord *)D_8009B1B4)->cursor_object = 0;
        }
        if (D_8009B162 != 0) {
            return;
        }
        if (!(D_8009B174 & 0x40)) {
            D_8009B174 |= 0x40;
            D_8009B162 = 0xC;
            D_8009B1B4 = ((DuelCardPickCursor *)( 
                &((DuelSelectionSide *)D_800E9F10)[D_8009B1D5].records[2] )) ;
            return;
        }
        D_8009B23A = 7;
        return;
    case 9:
        if (!(D_8009B174 & 0x80)) {
            D_8009B174 |= 0x80;
            D_8009B162 = 0xC;
        }
        if (D_8009B162 == 0) {
            D_8009B23A = 6;
        }
        return;
    case 11:
        D_8009B16C &= 0xEFFF;
        func_8004036C(D_8009B1F8);
        D_8009B1F8 = 0;
        D_8009B174 = 0xA;
        func_8003FEE0(0x30);
        return;
    case 10:
        if (!(D_8009B174 & 0x80)) {
            D_8009B174 |= 0x80;
            D_8009B162 = 0xC;
        }
        if (D_8009B162 == 0) {
            D_8009B23A = 0xA;
        }
        return;
    }
}
