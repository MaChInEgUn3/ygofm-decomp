/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/library_runtime.c, profile gcc_2_8_1_g8_split.
 * The declarations above the function are the subset of that tree's headers
 * this unit needs, preprocessed and with symbols renamed to this tree's
 * spelling (func_ADDR, D_ADDR); their types are that tree's. Byte-identical
 * under the flag row in tools_src/build.py. */
#include "kg_types.h"
#include "kg_variables.h"
#include "kg_functions.h"
extern s32 D_8009B118 __attribute__((section(".data")));
void func_8002BD0C(FileTransferDescriptor *object, s32 mode)
{
    switch (mode) {
    case 0:
        object->field_30.h.counter = 0x300;
        object->field_30.h.field_32 = 0x100;
        object->w = 0x40;
        object->h = 0x10;
        D_8009B0F4_abs &= 0xFFDDFFFF;
        D_8009B0F4_abs |= 0x10000;
        object->done = 2;
        object->phase_size = 64 * (1 << 11 ) ;
        object->value_08 = D_8009B118;
        object->value_0C = D_8009B118 + (1 << 11 ) ;
        break;

    case 1:
        object->phase_size = 4 * (1 << 11 ) ;
        D_8009B0F4_abs &= 0xFFDCFFFF;
        object->value_0C = D_8009B118;
        object->value_08 = D_8009B118;
        object->done = 1;
        break;

    case 2:
        (D_800E9D70[0]) .x = 0x100;
        (D_800E9D70[0]) .y = 0xF0;
        (D_800E9D70[0]) .w = 0x100;
        (D_800E9D70[0]) .h = 0x10;
        func_80081DE8(& (D_800E9D70[0]) , (u32 *)D_8009B118);
        object->field_30.h.counter = 0x240;
        object->field_30.h.field_32 = 0x100;
        object->w = 0x40;
        object->h = 0x10;
        D_8009B0F4_abs &= 0xFFDDFFFF;
        D_8009B0F4_abs |= 0x10000;
        object->done = 2;
        object->phase_size = 48 * (1 << 11 ) ;
        object->value_08 = D_8009B118;
        object->value_0C = D_8009B118 + (1 << 11 ) ;
        break;

    case 4:
        (D_800E9D70[0]) .x = 0x100;
        (D_800E9D70[0]) .y = 0xF6;
        (D_800E9D70[0]) .w = 0x100;
        (D_800E9D70[0]) .h = 2;
        func_80081DE8(& (D_800E9D70[0]) , (u32 *)D_8009B118);
        object->done = 3;
        object->field_30.word = 0x26810;
        object->phase_size = 20 * (1 << 11 ) ;
        object->value_08 = D_8009B118;
        object->value_0C = D_8009B118 + (1 << 11 ) ;
        break;

    case 3:
    case 5:
        object->phase_size = (1 << 11 ) ;
        D_8009B0F4_abs &= 0xFFDCFFFF;
        object->value_0C = D_8009B118;
        object->value_08 = D_8009B118;
        object->done = 1;
        break;

    case 6:
        func_80048D08(1, (u32 *)D_8009B118);
        break;
    }
}
