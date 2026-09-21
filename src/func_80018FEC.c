/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/func_80018FEC.c (DuelScene_UpdateExodiaResult), profile gcc_2_8_1_g8_split.
 * The declarations above the function are the subset of that tree's headers
 * this unit needs, preprocessed and with symbols renamed to this tree's
 * spelling (func_ADDR, D_ADDR); their types are that tree's. Byte-identical
 * under the flag row in tools_src/build.py. */
#include "kg_types.h"
extern u8 D_8009B1D5;
extern DuelSideState D_800E9FF0[2 ];
extern u8 D_8009B165;
extern u8 D_8009B369 __attribute__((section(".data")));
u8 *func_8002C604(s32 id);
extern u8 *D_8009B17C;
extern u8 D_8009B260 __attribute__((section(".data")));
DuelEffectRequest *func_8002C68C(s32 id);
extern DuelHandSlot D_800EA030[5 ];
extern u8 D_800E9F10[];
extern DuelCardPickCursor *D_8009B1B4;
extern u8 D_8015C424[];
extern u8 D_8009B1B9;
void func_80018FEC(void);
extern u16 D_8009B23A;
extern DuelExodiaCardPoseTable D_80090918;
s32 func_800358FC(s32 divisor);
void func_800156DC(void);
void func_80015C84();
void func_8001EC70(DisplayObject *object);
extern DisplayObject *D_800E9EF0[];
void func_8004036C(void *object);
void *func_80042B40(s32 value);
extern u8 *D_8009B214;
extern u8 *D_8009B21C;
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
