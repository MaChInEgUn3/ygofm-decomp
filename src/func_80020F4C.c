/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/duel_result_runtime.c (DuelScene_UpdateResultOutro), profile gcc_2_8_1_g8_split.
 * The declarations above the function are the subset of that tree's headers
 * this unit needs, preprocessed and with symbols renamed to this tree's
 * spelling (func_ADDR, D_ADDR); their types are that tree's. Byte-identical
 * under the flag row in tools_src/build.py. */
#include "kg_types.h"
#include "kg_variables.h"
#include "kg_functions.h"
s32 func_8004002C(void);
void *func_800400AC(s32 index, s32 key);
extern u8 D_801AF000[];
void *func_80042B40(s32 value);
void func_800428A8(
    DisplayObject *object,
    s32 arg1,
    s32 arg2,
    s32 arg3,
    s32 arg4,
    s32 arg5,
    s32 arg6,
    s32 arg7,
    void *resource
);
void func_80042918(DisplayObject *object);
extern u16 D_801799D8[];
extern int  func_8008E590(void);
void func_8001EC70(DisplayObject *object);
extern volatile u16 D_8009B398 __attribute__((section(".data")));
s32 func_800358FC(s32 divisor);
extern DisplayObject *D_8009B214;
extern DisplayObject *D_8009B21C;
FileTransferDescriptor *func_80014E1C(
    s32, u8 *, s32, s32, FileTransferCallback, s32, s32
);
extern u32 D_8009B134_abs __attribute__((section(".data")));
void func_80020BE4(FileTransferDescriptor *descriptor, s32 mode);
void func_8003FF08(u32);
void func_8003FF34(void);
s32 func_8004703C(void);
void func_800472A8(s32 arg0);
extern FadeTransitionState D_800E9EC8;
extern u8 D_8009B165;
extern s8 D_8009B238;
extern u8 D_8009B362 __attribute__((section(".data")));
extern s8 D_8009B361 __attribute__((section(".data")));
void func_80020D4C(DisplayObject *object);
void func_80020EE8(DuelCardDisplayObject *object);
extern u16 D_8009B1E0;
void func_80020F4C(void);
extern DuelResultSpriteSpec D_80090928[][7 ];
extern DuelResultSpriteSpec D_80090960[][7 ];
extern u16 D_8009B162;
extern u8 D_8009B174;
extern u16 D_8009B1D0;
void func_80020F4C(void)
{
    DuelResultSpriteSlot *slots;
    DisplayObject *obj;
    DuelResultSpriteSpec *spec;
    s32 i;
    s32 flags;
    s32 state;
    s32 id;
    s32 timer;
    s32 mode;
    s32 v;

    slots = (DuelResultSpriteSlot *)D_801799D8;

    v = D_8009B23A;
    if ((v & 0x8000 ) == 0) {
        D_8009B23A = v | 0x8000 ;
        func_8003FF34();
        id = D_8009B165;
        D_8009B362 = 0;
        if (id != 0) {
            D_8009B362 = 1;
        }
        D_8009B238 = id;
        func_80014E1C(
            0, 0,
            0x1DAB ,
            0x22 ,
            func_80020BE4, 0, 0
        );
        mode = 0x72E0;
        if (D_8009B165 != 0) {
            if (D_8009B361 >= 0) {
                mode = 0x72F0;
            }
        }
        obj = D_8009B214;
        D_8009B1E0 = mode;
         




        *(s16 *)&obj->position.h.field_28 = -116;
        obj->field_2C.h.field_2C = 0x30;
        obj->field_6C = 1;
        obj->update = (DisplayObjectCallback)func_8001EC70;
        obj->position.h.field_2A = (s16)obj->field_30.h.field_32;
        obj = D_8009B21C;
        obj->position.h.field_28 = 0x198;
        obj->field_2C.h.field_2C = 0x30;
        obj->field_6C = 1;
        obj->update = (DisplayObjectCallback)func_8001EC70;
        D_8009B174 = 1;
        obj->position.h.field_2A = (s16)obj->field_30.h.field_32;
        return;
    }

    if (D_8009B162 != 0) {
        return;
    }

    flags = D_8009B174;
    state = flags & 0xF;
    switch (state) {
    case 1:
        if ((flags & 0x80) == 0) {
            if ((D_8009B0F4_abs & 0x02000030 ) |
                D_8009B134_abs) {
                return;
            }
            D_8009B174 = flags | 0x80;
            D_8009B162 = 8;
            id = D_8009B361;
            if (id < 0) {
                id = 1;
            }
            func_80014E1C(
                0, 0,
                id * 3  + 0x1D33 ,
                3 , 0, 0,
                (s32)((u8 *)slots - 0x1800));
            func_800472A8(D_8009B1E0);
        } else {
            if ((D_8009B0F4_abs & 0x02000030 ) |
                D_8009B134_abs) {
                return;
            }
            D_8009B174 = 2;
            func_8003FF08(D_8009B1E0);
        }
        break;
    case 2:
        if ((flags & 0x80) == 0) {
            D_8009B174 = flags | 0x80;
            for (i = 0; i < 7 ; i++) {
                if (D_8009B361 >= 0) {
                    spec = &D_80090928[D_8009B165][i];
                } else {
                    spec = &D_80090960[D_8009B165][i];
                }
                slots[i].object = 0;
                if (spec->kind != 0) {
                    obj = func_800400AC(func_8004002C(), 2);
                    func_800428A8(obj, spec->x, spec->y, 0,
                                  D_8009B165, spec->kind, 0x11, 9,
                                  D_801AF000);
                    if (obj->field_69 >= 0x1A) {
                        obj->field_40.h.field_40 =
                            (u16)obj->field_40.h.field_40 + 0x10;
                    }
                    obj->flags |= 0x20  |
                                  0x08 ;
                    obj->attribute |= ((1<<30)  | (1<<28) );
                    obj->field_48.h.field_48 = spec->tag;
                    obj->field_48.h.field_4A = 0x18;
                    func_80042918(obj);
                    obj->field_2C.word = obj->field_30.word;
                    obj->position.h.field_28 = (func_8008E590() & 0x3F) + 0x140;
                    obj->position.h.field_2A =
                        func_800358FC(0x1000 );
                    obj->field_6C = 1;
                    obj->update =
                        (DisplayObjectCallback)func_80020D4C;
                    slots[i].object = obj;
                }
            }
        } else {
            if ((D_8009B0F4_abs & 0x02000030 ) |
                D_8009B134_abs) {
                return;
            }
            if (func_80042B40(1) == 0) {
                D_8009B174 = 3;
            }
        }
        break;
    case 3:
        if ((flags & 0x80) == 0) {
            D_8009B174 = flags | 0x80;
            D_8009B1D0 = 0x258;
        }
        if ((D_8009B174 & 0x40) == 0) {
            timer = D_8009B1D0 - 1;
            D_8009B1D0 = timer;
            if ((s16)timer > 0) {
                if ((D_8009B398 &
                     (0x20   | (0x40  | 0x80 ) )) == 0) {
                    if ((func_8004703C() & 0x80) != 0) {
                        return;
                    }
                }
            }
            D_8009B174 = D_8009B174 | 0x40;
            for (i = 0; i < 7 ; i++) {
                obj = slots[i].object;
                if (obj != 0) {
                    obj->field_6C = 1;
                    obj->update = (DisplayObjectCallback)func_80020EE8;
                }
            }
        } else {
            if (func_80042B40(1) == 0) {
                D_8009B174 = 4;
            }
        }
        break;
    case 4:
        if ((flags & 0x80) == 0) {
            D_8009B174 = flags | 0x80;
        }
        if ((D_800E9EC8.flags & 0x80 ) == 0) {
            D_8009B23A = 0xD;
        }
        break;
    }
}
