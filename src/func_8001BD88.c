/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/duel_scene_hand_actions.c (DuelScene_UpdateHandActions), profile gcc_2_8_1_g8_split.
 * The declarations above the function are the subset of that tree's headers
 * this unit needs, preprocessed and with symbols renamed to this tree's
 * spelling (func_ADDR, D_ADDR); their types are that tree's. Byte-identical
 * under the flag row in tools_src/build.py.
 * NOT his C verbatim: at two sites his `*(s32 *)&obj->target = *(s32 *)&obj->saved;`
 * is spelled `*(s32 *)((u8 *)obj + 40) = *(s32 *)((u8 *)obj + 44);` here. In cc1psx a
 * `*(T *)&p->member` access keeps the struct marking (MEM_IN_STRUCT_P), so the load is free
 * to move above the scalar-global store beside it (sched.c true_dependence exempts
 * struct+varying against non-struct+fixed); his mips-sony-psx-gcc build does not mark it and
 * keeps source order. The byte-address cast is unmarked in both. Measured 2026-09-21:
 * 20 differences with his spelling, byte-identical with this one; load alone at each site
 * is 10 and 16, both sites 6 (all six the renderer's `sym+2` spelling), volatile untried. */
#include "kg_types.h"
extern int func_8008E870(const char *fmt, ...);
extern s16 D_8009B19E;
extern u8 D_8009B1E2;
extern u16 D_8009B1E4;
extern const char D_80010060[];
void func_8001BD88(void);
extern u16 D_8009B23A;
extern s8 D_8009B208[8];
extern u8 D_800907D8[];
extern u8 D_800907CC[];
extern u8 D_8009B1D5;
extern u8 D_8009B19C;
extern DuelSideState *D_8009B1C8;
extern s8 D_8009B360[2 ] __attribute__((section(".data")));
extern u8 D_8009B1D4;
void func_800240B0(DuelCardPickCursor *cursor);
extern DuelHandSlot D_800EA030[5 ];
extern u8 D_800E9F10[];
extern u8 D_800E9F2C[];
extern u8 D_800E9F48[];
extern DuelCardPickCursor *D_8009B1B4;
void func_8001B938(DuelSelectionRecord *selection);
void func_8001BAF0(void);
void func_8001B8B8(DuelSelectionRecord *side);
extern DuelCardRecord D_801A7AD8[];
extern s32 D_801D4244[];
extern u8 D_8015C424[];
u8 *func_80017F04(DuelCardRecord *arg0, s32 arg1, s32 arg2);
void func_80024914(DuelCardRecord *object);
extern s8 D_8009B160;
s32 func_80024060(DuelCursorStatus *object);
s32 func_80024088(DuelFieldCursor *cursor, s8 dir);
void func_80023144(DuelFieldDisplaySource *source, s32 index);
extern s16 D_8009B20C[2];
extern u16 D_8009B210;
extern u8 D_8009B254 __attribute__((section(".data")));
extern u16 D_8009B246 __attribute__((section(".data")));
extern u8 D_8009B24B __attribute__((section(".data")));
s32 func_8004002C(void);
void *func_800400AC(s32 index, s32 key);
void func_8004036C(void *object);
void func_800404CC(
    void *object, s32 x, s32 y, s32 field_67, s32 field_68,
    s32 field_69, s32 color, s32 texture
);
void *func_80040468(struct DisplayObject *object, s32 field_67,
                    s32 field_68, s32 field_69, s32 color, s32 texture);
void *func_80042B40(s32 value);
s32 func_800428EC(DisplayObject *object, s8 value);
void func_80042918(DisplayObject *object);
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
                *(s32 *)((u8 *)obj + 40) = *(s32 *)((u8 *)obj + 44);
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
                    *(s32 *)((u8 *)obj + 40) = *(s32 *)((u8 *)obj + 44);
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
