/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/func_80019608.c (DuelScene_UpdateCardUse), profile gcc_2_8_1_g8_split_comm.
 * The declarations above the function are the subset of that tree's headers
 * this unit needs, preprocessed and with symbols renamed to this tree's
 * spelling (func_ADDR, D_ADDR); their types are that tree's. Byte-identical
 * under the flag row in tools_src/build.py. */
#include "kg_types.h"
extern u16 D_8009B150;
extern DuelCardRecord D_801A7AD8[];
void func_80024914(DuelCardRecord *object);
extern DuelSideState *D_8009B1C8;
extern u16 D_8009B23A;
void func_8004036C(void *object);
s32 func_800428EC(DisplayObject *object, s8 value);
extern volatile u32 D_8009B0F4_abs __attribute__((section(".data")));
extern u32 D_8009B134_abs __attribute__((section(".data")));
void func_8001944C(DisplayObject *object);
extern 
struct DisplayObject;
DisplayObject *func_80019564(DisplayObjectConfigView *source);
void func_80026BA4(s32 value, s32 flag);
u8 *func_800291E0(s32 index, s32 x, s32 y);
void func_80029528(s32 index);
FileTransferDescriptor *func_80029164(s32 slot, s32 value);
extern u16 D_8009B23A;
extern u8 D_8009B174;
void func_80019608(void);
extern DisplayObject *D_800E9EF0[];
extern u16 D_8009B150;
void func_80019608(void)
{
    DisplayObject *p;
    DuelCardRecord *slot;
    DisplayObject *q0;
    DisplayObject *q1;
    u8 state;
    u16 flags;
    u16 f2;
    u16 f3;
    u8 st;
    s32 v1;
    s32 v2;
    s32 v3;
    s32 value;
    s32 fld;

    p = D_800E9EF0[0];
    flags = D_8009B23A;
    if ((flags & 0x8000 ) == 0) {
        D_8009B23A = flags | 0xC000;
        slot = &D_801A7AD8[p->field_6A];
        value = slot->card_id;
        D_8009B150 = *(u16 *)&slot->card_id;
        func_80029164(0, value);
        if (p->field_68 == 20 ) {
            D_8009B1C8->rank.pure_magic_used =
                D_8009B1C8->rank.pure_magic_used + 1;
        }
        func_80024914(slot);
        D_8009B174 = 1;
    }
    state = D_8009B174;
    switch (state & 0xF) {
    case 1:
        if ((state & 0x80) == 0) {
            if (((D_8009B0F4_abs & 0x02000030 ) |
                 D_8009B134_abs) != 0) {
                return;
            }
            f2 = p->flags;
            D_8009B174 = state | 0x80;
            p->flags = f2 | 0x04 ;
            p = (DisplayObject *)func_800291E0(0, -1, -1);
            p->field_30.h.field_30 = 0x5A;
            p->field_30.h.field_32 = 0x16;
            p->field_20.b.field_21 = 0xC0;
            func_800428EC(p, -0xA);
            p->flags =
                (p->flags | 0x04 ) &
                ~0x40 ;
            D_800E9EF0[1] = p;
            return;
        }
        if ((state & 0x40) == 0) {
            v1 = p->field_20.b.field_21 + 6;
            p->field_20.b.field_21 = v1;
            if ((u8)v1 < 0x40) {
                return;
            }
            D_8009B174 = D_8009B174 | 0x40;
            func_8004036C(p);
            q1 = D_800E9EF0[1];
            D_800E9EF0[0] = 0;
            q1->flags = q1->flags | 0x40 ;
            return;
        }
        p = D_800E9EF0[1];
        if ((state & 0x20) == 0) {
            v2 = p->field_20.b.field_21 + 6;
            p->field_20.b.field_21 = v2;
            if ((s8)v2 < 0) {
                return;
            }
            p->field_60 = 0x1E;
            p->field_20.b.field_21 = 0;
            f3 = p->flags;
            st = D_8009B174 | 0x20;
            p->flags = f3 & ~0x04 ;
            D_8009B174 = st;
            return;
        }
        v3 = *(u16 *)&p->field_60 - 1;
        p->field_60 = v3;
        if ((s16)v3 > 0) {
            return;
        }
        D_8009B174 = 2;
        return;
    case 2:
        func_80026BA4((s16)D_8009B150, 0);
        D_8009B174 = 3;
        return;
    case 3:
        if ((state & 0x80) == 0) {
            p = D_800E9EF0[1];
            D_8009B174 = state | 0x80;
            func_8001944C(p);
            D_800E9EF0[0] =
                func_80019564((DisplayObjectConfigView *)p);
            D_800E9EF0[0]->attribute = D_800E9EF0[0]->attribute | ((1<<30)  | (1<<28) );
            D_800E9EF0[0]->attribute = D_800E9EF0[0]->attribute & ~(1<<27) ;
            D_800E9EF0[1] =
                func_80019564((DisplayObjectConfigView *)p);
            func_800428EC(D_800E9EF0[1], -1);
            D_800E9EF0[1]->attribute = D_800E9EF0[1]->attribute | ((1<<30)  | (2<<28) );
            D_800E9EF0[1]->attribute = D_800E9EF0[1]->attribute & ~(1<<27) ;
            func_80029528(0);
            return;
        }
        q0 = D_800E9EF0[0];
        fld = q0->field_44.h.field_44;
        value = fld + 0x80;
        q1 = D_800E9EF0[1];
        *(u16 *)&q1->field_44.h.field_46 = value;
        *(u16 *)&q1->field_44.h.field_44 = value;
        *(u16 *)&q0->field_44.h.field_46 = value;
        *(u16 *)&q0->field_44.h.field_44 = value;
        value = *(u8 *)&D_800E9EF0[0]->field_0C;
        value -= 4;
        if (value < 0) {
            value = 0;
        }
        value = value | ((value << 16) | (value << 8));
        D_800E9EF0[0]->field_0C = value;
        D_800E9EF0[1]->field_0C = value;
        if (value != 0) {
            return;
        }
        func_8004036C(D_800E9EF0[0]);
        func_8004036C(D_800E9EF0[1]);
        D_8009B174 = 4;
        return;
    case 4:
        if ((state & 0x80) == 0) {
            D_8009B174 = state | 0x80;
            func_80026BA4((s16)D_8009B150, 1);
            return;
        }
        D_8009B23A = 5;
        return;
    }
}
