/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/func_8004CB0C.c, profile gcc_2_8_1_g8_split.
 * The declarations above the function are the subset of that tree's headers
 * this unit needs, preprocessed and with symbols renamed to this tree's
 * spelling (func_ADDR, D_ADDR); their types are that tree's. Byte-identical
 * under the flag row in tools_src/build.py. */
#include "kg_types.h"
#include "kg_variables.h"
#include "kg_functions.h"
extern s32 D_8001001C __attribute__((section(".data")));
extern s32 D_80010020 __attribute__((section(".data")));
extern s32 D_80010024 __attribute__((section(".data")));
extern s32 D_80010028 __attribute__((section(".data")));
extern ModelSlot D_800F2C40[3 ];
extern u32 *func_80089E20(GsARGUNIT *);
extern GsCOORDUNIT *func_8008A420(u32 *, u32 *);
extern int func_80089F80(u32 *, GsTYPEUNIT *, GsOT *, u32 *);
extern void func_8008A280(u32 *);
s32 func_8004D134(s32 mode, u16 *kind, u8 *ctx, s32 *best, s32 *total);
void func_8004D58C(s32 slot, u8 *commands);
void func_8006086C(ModelHandlerObject *object);
void func_80060AEC(ModelHandlerObject *object);
void func_80060220(
    s32 model_index, ModelTypeUnit *unit, u8 *scratch);
void func_8005C6A0(s32 *object, ModelSlot *entry);
s32 func_8005A3D0(ModelSlot *model, GsCOORDUNIT *parent);
void func_8004CB0C(s32 slot, u8 *hmd, s32 size, s32 flags);
void func_8004CB0C(s32 index, u8 *hmd, s32 size, s32 flags)
{
    ModelSlot *base;
    GsUNIT *slot;
    u8 *cursor;
    GsOT *table;
    GsTYPEUNIT ev;
    s32 acc;
    s32 count;
    s32 i;
    u32 tag;
    s32 off;
    s32 loaded_limit;
    s32 limit;
    s32 sentinel;
    s32 next;
    s32 *cmd;
    GsCOORDUNIT *rec;
    GsCOORDUNIT *scan;
    GsCOORDUNIT *cur;
    GsCOORDUNIT *q;
    s32 handler;

    handler = (s32)func_80089E20;
    base = &D_800F2C40[index];
    slot = ((GsUNIT *)( base->field_000 )) ;
    cursor = hmd;
    if (index < 2) {
        table = D_800E9D90[2];
    } else {
        table = D_800E9D90[3];
    }
    count = 0;
    acc = 0;
    base->field_E13 = 0;
    base->field_E12 = 0;
    if (flags >= 0) {
        base->field_E11 = flags & 0x7F;
        if (flags & 0x80) {
            base->field_DC0[7] = 5;
        } else {
            base->field_DC0[7] = 0;
        }
    }
    base->field_DC0[6] = 0;
    base->field_DC0[5] = 0;
    base->field_DC0[4] = 0;
    base->field_DC8[0] = 0;
    base->field_DC8[1] = 0;
    base->field_DC8[2] = 0;
    base->field_DC8[3] = 0;
    base->field_DD0[0] = 0;
    base->field_DD0[3] = -0x15E;
    base->field_DD0[1] = -0x15E;
    switch (index) {
    default:
        base->field_DD0[2] = 0;
        break;
    case 0:
        base->field_DD0[2] = 0x1C2;
        break;
    case 1:
        base->field_DD0[2] = -0x1C2;
        break;
    }
    base->field_E0E = 6;
    base->field_E0F = 0;
    base->field_E10 = 0;
    base->entry_count = 0;
    base->field_E18 = 0;
    base->field_D18 = 0;
    base->entries = 0;
    base->field_D1C = 0;
    base->field_E19 = 0;
    base->field_E1B = 0;
    base->field_E1C = 0;
    base->field_DE8 = 0;
    base->field_DEC = 0;
    if (index < 2) {
        if (index != 0) {
            base->field_DE8 = D_80010020;
        } else {
            base->field_DE8 = D_8001001C;
        }
        if (index != 0) {
            base->field_DEC = D_80010028;
        } else {
            base->field_DEC = D_80010024;
        }
    }
    base->field_DF0 = 0;
    base->field_E00 = 0;
    base->field_E02 = 0;
    base->field_E04 = 0;
    base->field_DF4 = 0;
    base->field_E15 = 0;
    base->field_E1E = 0;
    base->field_E1F = 0;
    if (hmd == 0) {
        base->field_E1D = 0;
        base->field_E14 = 0xFF;
        return;
    }
    func_8008A280((u32 *)hmd);
    cursor += 0xC;
    func_8004D58C(index, hmd);
    base->field_E1A = *cursor;
    cursor += 4;
    if (base->field_E1A >= 0x3D) {
        base->field_E1A = 0x3C;
    }
    if (base->field_E1A != 0) {
        i = 0;
        do {
            slot->coord = 0;
            cmd = *(s32 **)cursor;
            cursor += 4;
            slot->primtop = (unsigned long *)cmd;
            if (cmd != 0) {
                func_80089F80((u32 *)cmd, 0, 0, 0);
            evloop:
                if (func_80089F80(0, &ev, table, (u32 *)0x1F800000) != 0) {
                    u8 *scratch;

                    tag = (u32)ev.type >> 24;
                    scratch = (u8 *)0x1F800000;
                    if (ev.type == 0) {
                        goto evloop;
                    }
                    if (tag < 2) {
                        goto masktest;
                    }
                    if (tag < 7) {
                        if (tag < 5) {
                            goto dispatch;
                        }
                    } else {
                        goto dispatch;
                    }
                masktest:
                    if (ev.type & 0x800000) {
                        base->entries = (u8 *)func_8008A420((u32 *)hmd, (u32 *)ev.ptr);
                        ev.type &= 0xFF7FFFFF;
                    }
                dispatch:
                    switch (tag) {
                    case 0:
                        base->field_E04 += func_8004D134(
                            index, (u16 *)&ev, scratch, &acc, &count);
                        func_8006086C((ModelHandlerObject *)&ev);
                        break;
                    case 1:
                        base->field_E04 += func_8004D134(
                            index, (u16 *)&ev, scratch, 0, &count);
                        func_80060AEC((ModelHandlerObject *)&ev);
                        break;
                    case 2:
                        func_80060220(
                            index, (ModelTypeUnit *)&ev, scratch);
                        break;
                    case 3:
                        func_8005C6A0((s32 *)&ev, base);
                        break;
                    default:
                        *ev.ptr = handler;
                        break;
                    }
                    goto evloop;
                }
            }
            i++;
            slot++;
        } while (i < base->field_E1A);
    }
    slot = ((GsUNIT *)( base->field_000 ))  + 1;
    i = 1;
    base->field_E00 = count;
    base->field_E02 = acc + i;
    if (i < base->field_E1A - 1) {
        off = 0;
    link:
        base->entry_count++;
        if (slot->primtop != 0) {
            slot->coord = ((GsCOORDUNIT *)( base->entries + off )) ;
        }
        off += 80 ;
        i++;
        slot++;
        if (i < base->field_E1A - 1) {
            goto link;
        }
    }
    scan = ((GsCOORDUNIT *)( base->entries )) ;
    if (scan != 0) {
        i = 0;
        while (scan->super != 0) {
            scan++;
            i++;
        }
        base->field_E18 = i;
        q = ((GsCOORDUNIT *)( base->entries ))  + i;
        base->field_D18 = q;
        base->field_E19 = func_8005A3D0(base, q);
        if (!(base->field_E19 < base->entry_count)) {
            base->field_E19 = base->field_E18;
        }
        cur = ((GsCOORDUNIT *)( base->entries ))  + base->field_E19;
        base->field_D1C = cur;
    retry:
        slot = ((GsUNIT *)( base->field_000 )) ;
        loaded_limit = base->field_E1A;
        i = 0;
        if (loaded_limit != 0) {
            sentinel = -1;
            limit = loaded_limit;
        claimed:
            if (slot->coord != 0 && slot->primtop != 0) {
                if (*slot->primtop != sentinel || *(slot->primtop + 2) != 0) {
                    if (slot->coord->super == cur) {
                        goto scanned;
                    }
                }
            }
            i++;
            slot++;
            if (i < limit) {
                goto claimed;
            }
        scanned:
            if (i < base->field_E1A) {
                goto found;
            }
        }
        next = func_8005A3D0(base, cur);
        if (!(next < base->entry_count)) {
            goto found;
        }
        cur = (GsCOORDUNIT *)base->entries + next;
        goto retry;
    found:
        rec = cur->super;
        if (rec != base->field_D18) {
            base->field_D1C = rec;
            if (rec != 0) {
                base->field_E19 = rec - ((GsCOORDUNIT *)( base->entries )) ;
            }
        }
    }
    if (base->field_DE0 == 0) {
        base->field_DE0 = (u8 *)(hmd + size);
    }
}
