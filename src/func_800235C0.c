/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/duel_field_display_objects.c, profile gcc_2_8_1_g8_split.
 * The declarations above the function are the subset of that tree's headers
 * this unit needs, preprocessed and with symbols renamed to this tree's
 * spelling (func_ADDR, D_ADDR); their types are that tree's. Byte-identical
 * under the flag row in tools_src/build.py. */
#include "kg_types.h"
#include "kg_variables.h"
#include "kg_functions.h"
extern u8 D_8009B1D5;
void func_8002348C(DuelFieldDisplaySource *source);
extern s16 D_8009B204;
void func_8002348C(DuelFieldDisplaySource *source);
s32 func_800235C0(void)
{
    DuelFieldDisplaySource *source;
    ViewState *view;
    DisplayObject *o;
    s32 i;
    s32 moving;
    s32 busy;
    s32 x;
    s32 y;
    s32 z;
    s32 w;
    s32 t;
    s16 count;
    u8 *records;
    u8 *replay;
    s32 result;
    u16 flags;

    flags = D_8009B162;
    source = (DuelFieldDisplaySource *)D_8009B1B4;
    view = &D_800F2848;
    do {
    } while (0);
    result = 0;
    if (flags != 0) {
        x = flags & 0x8000;
        do {
        } while (0);
        busy = 0;
        if (x == 0) {
            D_8009B162 = flags | 0x8000;
            if (D_8009B162 & 1) {
                func_80022D94(0x10, 0x14E, 0x3FE, D_8009AF20[D_8009B1D5],
                              D_800907AC[D_8009B1D5][source->field_18][source->y]);
            }
            if (D_8009B162 & 4) {
                func_80022D94(0x10, 0x258, 0x100, D_8009AF20[D_8009B1D5], 0);
                func_8004036C(source->object);
                source->object = 0;
                records = D_8015C424;
                for (i = 5; i < 30; i++) {
                    if (i % 15  >= 5  &&
                        (D_801A7AD8[i].flags & 0x8000)) {
                        o = ((DuelCardReplayRecordBlock *)(
                            (u8 *)&((DuelCardRecord *)records)[i] +
                            0x48000 ))->record.object;
                        o->field_6C = 1;
                        o->field_60 = 4;
                        o->update = (DisplayObjectCallback)func_800229F4;
                    }
                }
                D_8009B162 |= 0x4000;
            }
            if (D_8009B162 & 2) {
                o = func_80018150(0, 0xF0);
                source->field_16 = 0x24;
                if (source->field_13 != 0) {
                    func_80040410((DisplayObjectConfig *)o, source->field_13);
                    source->field_16 = 7;
                }
                func_800428EC(o, -(source->table_index * 2) - 2);
                o->position.h.field_28 = 0;
                o->position.h.field_2A = source->field_0C;
                func_80043178((DisplayObjectSnapshot *)o);
                o->field_60 = -0x400;
                o->field_6C = 2;
                source->field_00 = o;
                if (source->entries != 0) {
                    for (i = 0; i < 5 ; i++) {
                        if (source->entries[i].object != 0) {
                            source->entries[i].object->field_30.h.field_30 =
                                o->field_30.h.field_30 + (i * 0x3C + 0xE);
                            source->entries[i].object->field_30.h.field_32 =
                                o->field_30.h.field_32 - 0x1C;
                        }
                    }
                }
                func_80022FF0((DisplayParent *)source, 0);
            }
            if (D_8009B162 & 8) {
                o = source->field_00;
                o->position.h.field_2A = 0xF0;
                o->position.h.field_28 = o->field_30.h.field_30;
                func_80043178((DisplayObjectSnapshot *)o);
                o->field_60 = 0x400;
                o->field_6C = 2;
                func_80022FF0((DisplayParent *)source, 1);
            }
            busy = 0;
        }
        moving = busy;
        if (D_8009B162 & 0x40) {
            o = source->object;
            if (o->field_60 != 0) {
                t = (*(s16 *)&o->position.h.field_28 << 8) | o->pad_62[0];
                t += o->field_34.h.field_36;
                o->pad_62[0] = t;
                o->position.h.field_28 = t >> 8;
                t = (*(s16 *)&o->position.h.field_2A << 8) | o->field_64;
                t += o->field_38.h.field_3A;
                o->position.h.field_2A = t >> 8;
                o->field_64 = t;
                o->field_60--;
                busy = 1;
                if (o->field_60 <= 0) {
                    busy = 0;
                    o->field_60 = 0;
                    o->position.word = o->field_2C.word;
                }
            }
        }
        o = source->field_00;
        if ((D_8009B162 & 2) && o->field_6C != 0) {
            busy = 1;
            moving = busy;
            func_80043230((DisplayObjectPosition *)o,
                             *(s16 *)&o->position.h.field_28,
                             *(s16 *)&o->position.h.field_2A, o->field_60);
            o->field_60 += 0x40;
            if (o->field_60 >= 0) {
                o->field_6C = 0;
                o->field_30.word = o->position.word;
            }
        }
        if ((D_8009B162 & 8) && o->field_6C != 0) {
            busy = 1;
            func_80043230((DisplayObjectPosition *)o,
                             *(s16 *)&o->position.h.field_28,
                             *(s16 *)&o->position.h.field_2A, o->field_60);
            o->field_60 -= 0x40;
            moving = busy;
            if (o->field_60 < 0) {
                func_80035B7C(&D_800EB0F8[source->field_14]);
                func_8004036C(o);
                source->field_00 = 0;
                if (source->entries != 0) {
                    for (i = 0; i < 5 ; i++) {
                        func_8004036C(source->entries[i].object);
                        source->entries[i].object = 0;
                        func_8004036C(source->entries[i].field_04);
                        source->entries[i].field_04 = 0;
                    }
                }
                o->field_6C = 0;
                moving = 0;
            }
        }
        if (moving != 0) {
            func_80039934(&D_800EB0F8[source->field_14],
                           *(s16 *)&o->field_30.h.field_30 + 0x10,
                           *(s16 *)&o->field_30.h.field_32 + source->field_16);
        }
        if (D_8009B162 & 0x4000) {
            busy = 1;
            if (func_80042B40(1) != 0) {
                return busy;
            }
            D_8009B162 &= 0xBFFF;
        }
        if (D_8009B204 != 0) {
            count = (u16)D_8009B204 - 1;
            busy = 1;
            D_8009B204 = count;
            x = D_8009B1C4 += D_8009B1FC;
            y = D_8009B15C += D_8009B198;
            z = D_8009B158 += D_8009B194;
            w = D_8009B224 += D_8009B168;
            view->field_00 = x >> 16;
            view->field_04 = y >> 16;
            view->angle = z >> 16;
            view->view.vrz = w >> 16;
            if (count == 0) {
                view->field_00 = D_8009B1EE;
                view->field_04 = D_8009B192;
                view->angle = D_8009B190;
                view->view.vrz = D_8009B166;
                if (D_8009B162 & 1) {
                    replay = D_8015C424;
                    for (i = 5; i < 30; i++) {
                        if (i % 15  >= 5  &&
                            (D_801A7AD8[i].flags & 0x8000)) {
                            o = ((DuelCardReplayRecordBlock *)(
                                (u8 *)&((DuelCardRecord *)replay)[i] +
                                0x48000 ))->record.object;
                            o->field_6C = 1;
                            o->field_60 = 4;
                            o->update = (DisplayObjectCallback)func_80022674;
                        }
                    }
                    D_8009B162 |= 0x4000;
                }
            }
            func_8001352C();
        }
        if (busy == 0) {
            if (D_8009B162 & 1) {
                func_800234E4(source);
                func_8002348C(source);
            }
            D_8009B162 = 0;
        }
        result = busy;
    }
    return result;
}
