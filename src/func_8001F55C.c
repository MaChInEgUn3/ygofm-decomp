/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/duel_scene_battle.c (DuelScene_UpdateBattle), profile gcc_2_8_1_g8_split_comm.
 * The declarations above the function are the subset of that tree's headers
 * this unit needs, preprocessed and with symbols renamed to this tree's
 * spelling (func_ADDR, D_ADDR); their types are that tree's. Byte-identical
 * under the flag row in tools_src/build.py.
 * NOT his C verbatim: two copy statements are spelled through byte-address casts,
 * `*(u32 *)((u8 *)side + 40) = *(u32 *)((u8 *)side + 48);` (case 8) and
 * `*(u32 *)((u8 *)side + 48) = side->position.word;` (the 0xBF arm), where his tree has
 * `*(u32 *)&side->position` / `*(u32 *)&side->field_30`. In cc1psx that spelling carries the
 * struct marking and the load moves above the `sb D_8009B174` beside it, and the store moves
 * below `sh D_8009B1D0` into the `j`'s delay slot (-1 instruction); his build marks neither.
 * Measured 2026-09-21: -1/352 with his spelling, 347 with the first site cast, exact length
 * and byte-identical with both; casting the second site's load as well is +1 (the load must
 * stay free to hoist, as it does in retail). */
#include "kg_types.h"
#include "kg_variables.h"
#include "kg_functions.h"
extern u8 D_8009B1D5;
extern DisplayObject *D_8009B214;
extern DisplayObject *D_8009B21C;
extern DisplayObject *D_800E9EF0[];
extern ;
extern ;
extern u16 D_8009B170[2];
extern u16 D_8009B178[2];
extern s8 D_8009B208;
extern s8 D_8009B1B9;
extern AnimatedBattleModelProperties D_800EF658[];
extern ;
extern s8 D_8009B208;
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
                *(u32 *)((u8 *)side + 40) = *(u32 *)((u8 *)side + 48);
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
                    *(u32 *)((u8 *)side + 48) = side->position.word;
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
