/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/text_control_commands.c (Text_HandleDisplayEffectCommand), profile gcc_2_8_1_g8_split.
 * The declarations above the function are the subset of that tree's headers
 * this unit needs, preprocessed and with symbols renamed to this tree's
 * spelling (func_ADDR, D_ADDR); their types are that tree's. Byte-identical
 * under the flag row in tools_src/build.py. */
#include "kg_types.h"
extern volatile s32 D_8009B350;
extern MenuRecord D_800EB010[];
extern MenuRecord *D_8009B328;
void func_80039F44(DisplayEffectState *object);
void func_80039FD4(MenuRecord *record);
void func_80038EB0(EffectObject *object);
void func_80038EB0(EffectObject *o) {
    MenuRecord *e;
    s32 id;
    s32 flags;
    s32 slot;
    s32 a;
    s32 b;

    D_8009B350 = 1;
    a = *o->streams[o->depth]++;
    b = *o->streams[o->depth]++;
    id = a;
    flags = b;

    e = D_800EB010;
    if (id >= 0x41 ) {
        e += 2;
    } else if (e->field_30 != id) {
        e++;
        if (e->field_30 != id) {
            e = 0;
        }
    }

    if (flags & 0x80) {
        if (e == 0) {
            return;
        }
        D_8009B328 = e;
        if (flags & 2) {
            func_80039FD4(e);
            return;
        }
        if (flags & 1) {
            o->state = 0xE;
            return;
        }
        if (e->field_3C != 0) {
            e->field_40 = 0x178;
        } else {
            e->field_40 = -0x38;
        }
        e->field_42 = 0xB2;
        e->field_44 = 0x10;
        o->state = 7;
        e->display_effect_step = 3;
        if (id >= 0x41 ) {
            e->display_effect_step = 5;
            e->field_40 = 1;
        }
        return;
    }
    if (flags & 0x60) {
        if (e == 0) {
            return;
        }
        if (id >= 0x41 ) {
            return;
        }
        D_8009B328 = e;
        if (flags & 0x40) {
            e->field_31 = flags & 3;
            o->state = 9;
            return;
        } else if (flags & 0x20) {
            e->field_32 &= 0xEF;
            if (flags & 1) {
                e->field_32 |= 0x10;
            }
            return;
        }
    }

    slot = flags & 1;
    if (id >= 0x41 ) {
        slot = 2;
    }
    e = &D_800EB010[slot];
    func_80039F44((DisplayEffectState *)e);
    e->field_30 = id;
    e->field_3C = slot;
    if (slot != 0) {
        *(s16 *)&e->field_34 = 0x178;
    } else {
        *(s16 *)&e->field_34 = -0x38;
    }
    o->state = 6;
    D_8009B328 = e;
    if (id >= 0x41 ) {
        e->display_effect_step = 5;
        e->field_3C = 2;
        *(s16 *)&e->field_34 = 0xF0;
        e->field_40 = 0;
        *(s16 *)&e->field_36 = 0x60;
        return;
    }
    e->display_effect_step = 2;
    e->field_40 = 3;
    if (flags & 8) {
        *(s16 *)&e->field_34 = 0x400;
        e->field_40 = 7;
    }
    if (flags & 0x10) {
        e->field_31 = (flags >> 1) & 3;
    }
}
