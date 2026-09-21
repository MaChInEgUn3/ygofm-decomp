/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/duel_scene_field_actions.c (DuelScene_UpdateFieldActions), profile gcc_2_8_1_g8_split_comm.
 * The declarations above the function are the subset of that tree's headers
 * this unit needs, preprocessed and with symbols renamed to this tree's
 * spelling (func_ADDR, D_ADDR); their types are that tree's. Byte-identical
 * under the flag row in tools_src/build.py. */
#include "kg_types.h"
#include "kg_variables.h"
#include "kg_functions.h"
extern u16 D_8009B170;
extern u16 D_8009B178;
extern u8 D_800907D8[];
extern u8 D_8009B1D5;
extern u8 D_8009B1D6;
extern u8 D_8009B1D7;
void func_8002348C(DuelFieldDisplaySource *source);
extern ;
extern u8 D_8009B254 __attribute__((section(".data")));
extern u16 D_8009B246 __attribute__((section(".data")));
extern u8 D_8009B24B __attribute__((section(".data")));
extern u16 D_8009B16C;
extern DisplayObject *D_800E9EF0[];
extern volatile u16 D_8009B398 __attribute__((section(".data")));
extern u32 D_8009B300 __attribute__((section(".data")));
extern u8 D_800EAE88[];
extern u16 D_8009B170;
extern u16 D_8009B178;
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
