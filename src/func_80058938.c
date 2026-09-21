/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/func_80058938.c (Model_QueueTintRequest), profile gcc_2_8_1_g8_split_no_strength_reduce.
 * The declarations above the function are the subset of that tree's headers
 * this unit needs, preprocessed and with symbols renamed to this tree's
 * spelling (func_ADDR, D_ADDR); their types are that tree's. Byte-identical
 * under the flag row in tools_src/build.py. */
#include "kg_types.h"
extern ModelSlot D_800F2C40[3 ];
extern ModelTintRequest D_800F2B50[10 ];
void func_80058938(
    s32 slot, s32 selection, ModelTintColor start, ModelTintColor end,
    s32 duration, const u8 *part_mask);
void func_80058938(
    s32 slot, s32 selection, ModelTintColor start, ModelTintColor end,
    s32 duration, const u8 *part_mask);
void func_80058938(
    s32 a0, s32 a1, ModelTintColor a2, ModelTintColor a3, s32 a4,
    const u8 *bits)
{
    ModelSlot *slot;
    ModelTintRequest *r;
    ModelTintRequest *end;
    register u8 *base = (u8 *)D_800F2B50;
    s32 off;
    s32 fill;
    s32 f;
    s32 mode;
    s32 f1, f2, f3, f4, f5, f6;
    s32 sel;

    slot = &D_800F2C40[a0];
    mode = (a0 & 1) << 1;
    sel = (a1 & 1) << 2;
    fill = 0xFF;
    off = 0;
    r = D_800F2B50;
    end = r + 10 ;
    do {
        if ((*(u8 *)r & 1) == 0) {
            f = r->flags;
            f1 = f | 1;
            f2 = f1 & 0xFFFD;
            f3 = f2 | mode;
            f4 = f3 & 0xFFFB;
            f5 = f4 | sel;
            do {
                mode = 0;
            } while (0);
            r->flags = f5;
            f6 = f5 & 0xFF07;
            sel = off;
            f = f6 | ((slot->field_BF5 & 0x1F) << 3);
            r->flags = f;
            r->field_0A = slot->field_E06;
            r->elapsed = 0;
            r->duration = (a4 *= 2);
            r->start = a2;
            r->end = a3;
            for (; mode < 8; mode++) {
                base[mode + sel + 1] = bits ? bits[mode] : fill;
            }
            break;
        }
        off += sizeof(ModelTintRequest);
        r++;
    } while ((s32)r < (s32)end);
}
