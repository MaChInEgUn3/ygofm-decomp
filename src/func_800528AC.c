/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/model_scene_setup.c, profile gcc_2_8_1_g8_split.
 * The declarations above the function are the subset of that tree's headers
 * this unit needs, preprocessed and with symbols renamed to this tree's
 * spelling (func_ADDR, D_ADDR); their types are that tree's. Byte-identical
 * under the flag row in tools_src/build.py. */
#include "kg_types.h"
#include "kg_variables.h"
#include "kg_functions.h"
s32 func_8005A8C4(s32 index, s32 type);
s32 func_80059AA8(s32 index, s32 value);
extern ModelSlot D_800F2C40[3 ];
extern ModelTintRequest D_800F2B50[10 ];
void func_8004DC38(ModelSlot *slot, s32 i, s32 n, u32 pos);
s32 func_80058E1C(void);
void func_800528AC(void);
extern u8 D_8009AF9B;
extern s32 D_8009AF9C;
void func_800540B4(s32 index);
void func_800528AC(void)
{
    ModelTintColor save;
    ModelTintColor col;
    s32 i;
    s32 j;
    s32 k;
    u32 v;
    s32 keep;
    s32 rowbase;
    u32 part;
    u32 sid;
    s32 old;
    u8 side;
    u16 sav06;
    s32 off;
    u16 lo;
    u16 hi;
    u16 a;
    s32 aa;
    s32 sv;
    ModelSlot *slot;
    ModelTintRequest *e;
    ModelTintRequest *table;

    table = (ModelTintRequest *)D_800F2B50;
    for (i = 0, off = 0; i < 10 ; off += 0x18, i++) {
        e = &table[i];
        rowbase = (s32)((u8 *)table + 1);
        if ((*(u8 *)e & 1) == 0) {
            continue;
        }
        if (D_800F2C40[(e->flags >> 1) & 1].field_E1F == 0) {
            continue;
        }
        if (func_8005A8C4((e->flags >> 1) & 1, e->start.b3)) {
            goto tail;
        }
        v = e->flags;
        a = e->field_0A;
        lo = e->elapsed;
        hi = e->duration;
        side = (v >> 1) & 1;
        v = v >> 3;
        slot = &D_800F2C40[side];
        sav06 = slot->field_E06;
        part = v & 0x1F;
        keep = slot->field_BF5;
        old = func_80059AA8(side, 0);
        sid = part;
        save = * ((ModelTintColor *)( slot->field_DC0 )) ;
        col.b3 = e->start.b3;
        col.b0 = e->start.b0 * (hi - lo) / hi + e->end.b0 * lo / hi;
        col.b1 = e->start.b1 * (hi - lo) / hi + e->end.b1 * lo / hi;
        col.b2 = e->start.b2 * (hi - lo) / hi + e->end.b2 * lo / hi;
        * ((ModelTintColor *)( slot->field_DC0 ))  = col;

        aa = a;
        for (j = 0; j < slot->field_E1B; j++) {
            s32 t = slot->field_BF5;
            if (sid != 0) {
                slot->field_1E0[j]->sid = sid;
                t = sid;
            }
            func_8004DC38(slot, j, t, aa);
        }
        if (sid != 0) {
            slot->field_BF5 = sid;
        }

        D_8009AF9C = off + rowbase;
        D_8009AF9B = (e->flags >> 2) & 1;
        func_800540B4(side);
        D_8009AF9C = 0;
        D_8009AF9B = 0;

        sv = sav06;
        for (k = 0; k < slot->field_E1B; k++) {
            s32 t = slot->field_BF5;
            if (keep != 0) {
                slot->field_1E0[k]->sid = keep;
                t = keep;
            }
            func_8004DC38(slot, k, t, sv);
        }
        if (keep != 0) {
            slot->field_BF5 = keep;
        }

        func_80059AA8(side, old);
        * ((ModelTintColor *)( slot->field_DC0 ))  = save;
tail:
        e->elapsed += func_80058E1C();
        if (e->elapsed >= e->duration) {
            e->flags &= 0xFFFE;
        }
    }
}
