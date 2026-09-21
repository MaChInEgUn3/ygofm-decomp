/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/model_texture_transfer.c, profile gcc_2_8_1_g8_split.
 * The declarations above the function are the subset of that tree's headers
 * this unit needs, preprocessed and with symbols renamed to this tree's
 * spelling (func_ADDR, D_ADDR); their types are that tree's. Byte-identical
 * under the flag row in tools_src/build.py. */
#include "kg_types.h"
#include "kg_variables.h"
#include "kg_functions.h"
extern u8 *D_8009B118 __attribute__((section(".data")));
void func_80057544(FileTransferDescriptor *object, s32 mode) {
    RECT rect0;
    RECT rect1;

    switch (mode) {
    case 0:
        object->phase_size = 18 * (1 << 11 ) ;
        D_8009B0F4_abs &= 0xFFDCFFFF;
        object->value_0C = D_80010008;
        object->value_08 = D_80010008;
        object->done = 1;
        break;

    case 1:
        object->field_30.h.counter = 0x200;
        object->field_30.h.field_32 = 0x100;
        object->w = 0x40;
        object->h = 0x10;
        D_8009B0F4_abs &= 0xFFDDFFFF;
        D_8009B0F4_abs |= 0x10000;
        object->done = 2;
        object->phase_size = 64 * (1 << 11 ) ;
        object->value_08 = (u32)D_8009B118;
        object->value_0C = (u32)(D_8009B118 + (1 << 11 ) );
        break;

    case 2:
        object->value_0C = (s32)D_801DD800;
        object->value_08 = (s32)D_801DD800;
        object->phase_size = (1 << 11 ) ;
        D_8009B0F4_abs &= 0xFFDCFFFF;
        object->done = 1;
        break;

    case 3:
        rect0.x = 0x200;
        rect0.y = 0xF1;
        rect0.w = 0x100;
        rect0.h = 1;
        func_80081DE8(&rect0, (u32 *)D_801DD800);
        object->value_0C = (s32)(D_801DD800 - (1 << 11 ) );
        object->value_08 = (s32)(D_801DD800 - (1 << 11 ) );
        object->phase_size = (1 << 11 ) ;
        D_8009B0F4_abs &= 0xFFDCFFFF;
        object->done = 1;
        break;

    case 4:
        rect1.x = 0x200;
        rect1.y = 0xF4;
        rect1.w = 0x100;
        rect1.h = 2;
        func_80081DE8(&rect1, (u32 *)D_801DD000);
        object->field_30.h.counter = 0x380;
        object->field_30.h.field_32 = 0;
        object->w = 0x40;
        object->h = 0x10;
        D_8009B0F4_abs &= 0xFFDDFFFF;
        D_8009B0F4_abs |= 0x10000;
        object->done = 2;
        object->phase_size = 32 * (1 << 11 ) ;
        object->value_08 = (u32)D_8009B118;
        object->value_0C = (u32)(D_8009B118 + (1 << 11 ) );
        break;

    case 5:
        D_800F5694[0] = 1;
        break;
    }
}
