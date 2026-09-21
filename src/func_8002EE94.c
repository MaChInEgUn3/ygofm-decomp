/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/script_op_save_prompt.c (Script_OpSavePrompt), profile gcc_2_8_1_g8_split.
 * The declarations above the function are the subset of that tree's headers
 * this unit needs, preprocessed and with symbols renamed to this tree's
 * spelling (func_ADDR, D_ADDR); their types are that tree's. Byte-identical
 * under the flag row in tools_src/build.py. */
#include "kg_types.h"
#include "kg_variables.h"
#include "kg_functions.h"
extern volatile u16 D_8009B398 __attribute__((section(".data")));
extern ;
extern u16 D_8009B27C;
extern s8 D_8009B345 __attribute__((section(".data")));
extern s8 D_8009B34D __attribute__((section(".data")));
extern ;
void func_8002EE94(void)
{
    DuelEffectChannel *box;
    DisplayObject *obj;
    u8 *p;
    u8 *p2;
    DisplayObject *slot;
    DuelEffectChannel *chan;
    DuelEffectChannel *prompt;
    s32 value;
    s32 lo;
    s32 choice;
    s32 step;
    u16 flags;
    u16 next;

    if (func_8002E3B4() == 0) {
        p = D_8009B290;
        p2 = p + 2;
        D_8009B34D = -1;
        D_8009B290 = p2;
        lo = p[0];
        value = lo | (p[1] << 8);
        D_8009B290 = p + 4;
        D_8009B2A6 = p[2] | (p2[1] << 8);
        func_8003B6AC(0, 2);
        func_8002E370(
            func_80035BE4(0, value, 0x10, 0xB0, 0x120, 0x30));
        return;
    }

    if ((D_8009B27C & 0x80) != 0) {
        if (func_8003F70C() == 0) {
            return;
        }
        D_8009B345 = 4;
        D_8009B34D = 0;
        D_8009B34C = 0;
        D_8009B27C &= 0xFF7F;
        return;
    }

    func_80039794();
    flags = D_8009B27C;
    if ((flags & 0x4000) == 0) {
        chan = D_800EB0F8;
        if ((chan->flags_34 & 0x2000) == 0) {
            return;
        }
        if (func_8003735C(chan) != 0) {
            return;
        }
        D_8009B27C |= 0x4000;
        if (func_8002EE5C() == 0) {
            D_8009B27C |= 0x200;
            func_8003FEE0(0x2A);
            return;
        }
        func_8003B6AC(0, 2);
        box = func_80035BE4(3, 0x11, -0x90, 0x38, 0x78, 0x30);
        func_8002E370((MenuRecord *)box);
        box->flags_34 |= 0x24;
        do {
            func_80039794();
        } while (box->field_30 == 0);
        func_80043178((DisplayObjectSnapshot *)box->field_28);
        slot = box->field_28;
        next = D_8009B27C | 0x6000;
        slot->field_60 = -0x400;
        D_8009B27C = next;
        return;
    }

    box = &D_800EB0F8[3];
    obj = box->field_28;

    if ((flags & 0x400) != 0) {
        if ((flags & 0x800) == 0) {
            D_8009B27C = flags | 0x800;
            func_8003B6AC(0, 2);
            box = func_80035BE4(2, 0x12, 0x90, 0x70, 0x18, 0x18);
            func_8002E370((MenuRecord *)box);
            box->flags_34 |= 0x20;
            do {
                func_80039794();
            } while (box->field_30 == 0);
        }
        prompt = &D_800EB0F8[2];
        if ((prompt->flags_34 & 0x2000) == 0) {
            return;
        }
        D_8009B27C &= 0xF3FF;
        func_80035B7C(prompt);
        if (D_8009B34D != 0) {
            D_8009B268 = 1;
            D_8009B26D = 5;
            D_8009B26C = 8;
        }
        D_8009B345 = 4;
        D_8009B34D = 2;
        return;
    }

    if ((flags & 0x200) != 0) {
        if ((flags & 0x800) == 0) {
            D_8009B27C = flags | 0x800;
            func_8003B6AC(0, 2);
            func_8002E370(func_80035C38(
                0, 0x1C, 0x10, 0xB0, 0x120, 0x24, 0x1008));
            return;
        }
        if ((D_800EB0F8[0].flags_34 & 8) != 0) {
            return;
        }
        func_8003FEE0(8);
        D_8009B268 = 1;
        D_8009B26D = 5;
        D_8009B26C = 8;
        return;
    }

    if ((flags & 0x1000) != 0) {
        if ((flags & 0x800) == 0) {
            D_8009B27C = flags | 0x800;
            func_80043178((DisplayObjectSnapshot *)obj);
            *(s16 *)&box->field_28->field_60 = 0x400;
        }
        step = *(u16 *)&obj->field_60 - 0x40;
        obj->field_60 = step;
        if ((s16)step <= 0) {
            func_80035B7C(box);
            D_8009B27C = 0;
            return;
        }
        func_80043230((DisplayObjectPosition *)obj, -0x90, 0x38, (s16)step);
        func_80039934(box, *(s16 *)&obj->field_30.h.field_30,
                       *(s16 *)&obj->field_30.h.field_32);
        return;
    }

    if ((flags & 0x2000) != 0) {
        step = *(u16 *)&obj->field_60 + 0x40;
        obj->field_60 = step;
        if ((s16)step >= 0) {
            *(s16 *)&obj->field_30.h.field_30 = 0x10;
            *(s16 *)&obj->field_30.h.field_32 = 0x38;
            D_8009B27C = flags & 0xDFFF;
             


            value = ((s16 *)obj)[((u32)&((DisplayObject *)0)->field_30.h.field_32 / sizeof(s16)) ];
            func_80039934(
                box, ((s16 *)obj)[((u32)&((DisplayObject *)0)->field_30.h.field_30 / sizeof(s16)) ], value
            );
            return;
        }
        func_80043230((DisplayObjectPosition *)obj, 0x10, 0x38, (s16)step);
        func_80039934(box, *(s16 *)&obj->field_30.h.field_30,
                       *(s16 *)&obj->field_30.h.field_32);
        return;
    }

    do {
        if (func_8003700C(box) != 0) {
            return;
        }
        if ((D_8009B398 & 0xC0) == 0) {
            return;
        }
        D_801D0000[(0x200  + 0x5DC ) /
                  sizeof(s16)] = D_8009B2A6;
        choice = D_8009B34D;
        switch (choice) {
        case 0:
            func_8003FEE0(7);
            D_801D0000[(0x200  + 0x5DC ) /
                      sizeof(s16)] = D_8009B2A6;
            func_8003F87C();
            D_8009B27C |= 0x80;
            break;
        case 1:
            func_8003FEE0(7);
            func_80033C90();
            D_8009B269 = 2;
            D_8009B27A = (u8)D_8009B2A6;
            break;
        case 2:
            func_8003FEE0(7);
            D_8009B27C |= 0x400;
            break;
        case 3:
            func_8003FEE0(8);
            D_8009B27C |= 0x1000;
            break;
        }
    } while (0);
}
