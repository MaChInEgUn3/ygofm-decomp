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
extern u8 D_801A8000[];
void func_80056D7C(FileTransferDescriptor *d, s32 stage)
{
    RECT rect0;
    RECT rect1;
    s32 index;
    s32 alternate;
    ModelSlot *slot;

    index = (s32)d->callback_data;
    alternate = d->position;
    slot = &D_800F2C40[index];
    switch (stage) {
    case 0: {
        u8 *destination;
        if (index == 0) {
            destination = D_80010000;
        } else {
            destination = D_80010004;
        }
        d->value_08 = d->value_0C = (u32)destination;
        d->phase_size = 96 * (1 << 11 ) ;
        D_8009B0F4_abs &= 0xFFDCFFFF;
        d->done = 1;
        break;
    }
    case 1:
        d->field_30.h.counter = index << 8;
        d->field_30.h.field_32 = 0x100;
        d->w = 0x40;
        d->h = 0x10;
        D_8009B0F4_abs &= 0xFFDDFFFF;
        d->phase_size = 48 * (1 << 11 ) ;
        D_8009B0F4_abs |= 0x10000;
        d->done = 2;
        d->value_08 = (u32)D_8009B118;
        d->value_0C = (u32)(D_8009B118 + (1 << 11 ) );
        break;
    case 2:
        d->value_08 = d->value_0C = (u32)D_801DD000;
        d->phase_size = 2 * (1 << 11 ) ;
        D_8009B0F4_abs &= 0xFFDCFFFF;
        d->done = 1;
        break;
    case 3: {
        u32 mask;
        u8 *source;
        RECT *rect;
        do { rect = &rect0; } while (0);
        rect0.x = index << 8;
        rect0.y = 0xF8;
        rect0.w = 0x100;
        rect0.h = 8;
        func_80081DE8(rect, (u32 *)D_801DD000);
        source = D_801DD000;
        do { mask = 0xFFDCFFFF; } while (0);
        source += 2 * (1 << 11 ) ;
        d->value_08 = d->value_0C = (u32)source;
        d->phase_size = (1 << 11 ) ;
        D_8009B0F4_abs &= mask;
        d->done = 1;
        break;
    }
    case 4:
        if (alternate == 0) {
            rect1.x = 0x200;
            rect1.y = index + 0xF2;
            rect1.w = 0x100;
            rect1.h = 1;
            func_80081DE8(&rect1, (u32 *)D_801DE000);
            d->field_30.h.counter = (index << 8) + 0xC0;
            d->w = 0x40;
            d->h = 0x10;
            {
                u32 cleared, loaded, enabled;
                cleared = D_8009B0F4_abs & 0xFFDDFFFF;
                D_8009B0F4_abs = cleared;
                do { loaded = D_8009B0F4_abs; } while (0);
                do { enabled = 0x10000; } while (0);
                d->field_30.h.field_32 = 0x100;
                D_8009B0F4_abs = loaded | enabled;
            }
            d->done = 2;
            d->phase_size = 16 * (1 << 11 ) ;
            d->value_08 = (u32)D_8009B118;
            d->value_0C = (u32)(D_8009B118 + (1 << 11 ) );
        } else {
            d->phase_size = 16 * (1 << 11 ) ;
            D_8009B0F4_abs &= 0xFFFCFFFF;
            D_8009B0F4_abs |= 0x200000;
            d->done = 1;
        }
        break;
    case 6:
        if (alternate == 1) {
            rect1.x = 0x200;
            rect1.y = index + 0xF2;
            rect1.w = 0x100;
            rect1.h = 1;
            func_80081DE8(&rect1, (u32 *)D_801DD000);
            d->field_30.h.counter = (index << 8) + 0xC0;
            d->w = 0x40;
            d->h = 0x10;
            {
                u32 cleared, loaded, enabled;
                cleared = D_8009B0F4_abs & 0xFFDDFFFF;
                D_8009B0F4_abs = cleared;
                do { loaded = D_8009B0F4_abs; } while (0);
                do { enabled = 0x10000; } while (0);
                d->field_30.h.field_32 = 0x100;
                D_8009B0F4_abs = loaded | enabled;
            }
            d->done = 2;
            d->phase_size = 16 * (1 << 11 ) ;
            d->value_08 = (u32)D_8009B118;
            d->value_0C = (u32)(D_8009B118 + (1 << 11 ) );
        } else {
            d->phase_size = 16 * (1 << 11 ) ;
            D_8009B0F4_abs &= 0xFFFCFFFF;
            D_8009B0F4_abs |= 0x200000;
            d->done = 1;
        }
        break;
    case 7:
        if (alternate == 0 && index == 0) {
            d->phase_size = 10 * (1 << 11 ) ;
            D_8009B0F4_abs &= 0xFFDCFFFF;
            d->value_08 = d->value_0C = D_80010014;
            d->done = 1;
        } else {
            d->phase_size = 10 * (1 << 11 ) ;
            D_8009B0F4_abs &= 0xFFFCFFFF;
            D_8009B0F4_abs |= 0x200000;
            d->done = 1;
        }
        break;
    case 8:
        if (alternate == 0 && index == 1) {
            d->phase_size = 10 * (1 << 11 ) ;
            D_8009B0F4_abs &= 0xFFDCFFFF;
            d->value_08 = d->value_0C = D_80010018;
            d->done = 1;
        } else {
            d->phase_size = 10 * (1 << 11 ) ;
            D_8009B0F4_abs &= 0xFFFCFFFF;
            D_8009B0F4_abs |= 0x200000;
            d->done = 1;
        }
        break;
    case 9:
        if (alternate == 1 && index == 0) {
            d->phase_size = 10 * (1 << 11 ) ;
            D_8009B0F4_abs &= 0xFFDCFFFF;
            d->value_08 = d->value_0C = D_80010014;
            d->done = 1;
        } else {
            d->phase_size = 10 * (1 << 11 ) ;
            D_8009B0F4_abs &= 0xFFFCFFFF;
            D_8009B0F4_abs |= 0x200000;
            d->done = 1;
        }
        break;
    case 10:
        if (alternate == 1 && index == 1) {
            d->phase_size = 10 * (1 << 11 ) ;
            D_8009B0F4_abs &= 0xFFDCFFFF;
            d->value_08 = d->value_0C = D_80010018;
            d->done = 1;
        } else {
            d->phase_size = 10 * (1 << 11 ) ;
            D_8009B0F4_abs &= 0xFFFCFFFF;
            D_8009B0F4_abs |= 0x200000;
            d->done = 1;
        }
        break;
    case 11:
        if (index == 0) {
            d->phase_size = 2 * (1 << 11 ) ;
            D_8009B0F4_abs &= 0xFFDCFFFF;
            d->value_08 = d->value_0C = (u32)D_8001000C;
            d->done = 1;
        } else {
            d->phase_size = 2 * (1 << 11 ) ;
            D_8009B0F4_abs &= 0xFFFCFFFF;
            D_8009B0F4_abs |= 0x200000;
            d->done = 1;
        }
        break;
    case 12:
        if (index == 1) {
            d->phase_size = 2 * (1 << 11 ) ;
            D_8009B0F4_abs &= 0xFFDCFFFF;
            d->value_08 = d->value_0C = (u32)D_80010010;
            d->done = 1;
        } else {
            d->phase_size = 2 * (1 << 11 ) ;
            D_8009B0F4_abs &= 0xFFFCFFFF;
            D_8009B0F4_abs |= 0x200000;
            d->done = 1;
        }
        break;
    case 13:
        if (slot->field_E1D != 0) {
            d->phase_size = (1 << 11 ) ;
            D_8009B0F4_abs &= 0xFFFCFFFF;
            D_8009B0F4_abs |= 0x200000;
            d->done = 1;
        } else {
            d->value_08 = d->value_0C =
                (u32)(D_801A8000 + index * (1 << 11 ) );
            d->phase_size = (1 << 11 ) ;
            D_8009B0F4_abs &= 0xFFDCFFFF;
            d->done = 1;
        }
        break;
    case 14:
        if (slot->field_E1D != 0) {
            u32 mask;
            do { mask = 0xFFFCFFFF; } while (0);
            d->phase_size = 50 * (1 << 11 ) ;
            D_8009B0F4_abs &= mask;
            D_8009B0F4_abs |= 0x200000;
            d->done = 1;
        } else {
            d->done = 3;
            d->field_30.word = index * 0x19000 + 0xD810;
            d->phase_size = 50 * (1 << 11 ) ;
            d->value_08 = (u32)D_8009B118;
            d->value_0C = (u32)(D_8009B118 + (1 << 11 ) );
        }
        break;
    case 5:
    case 15:
        d->value_08 = d->value_0C = (u32)D_801DD000;
        d->phase_size = (1 << 11 ) ;
        D_8009B0F4_abs &= 0xFFDCFFFF;
        d->done = 1;
        break;
    case 16: {
        u8 *source;
        source = D_801DD000;
        func_8005B620(
            (s32 *)slot->sound_entries,
            (const s32 *)source,
            64 
        );
        *(ModelSlotCF8BlockWords *)&slot->field_CF8 =
            ((ModelTransferMetadata *)source)->field_CF8;
        if (slot->field_CF8.prefix.values.field_08 & 0x20200000) {
            func_80059284(index, 4);
        }
        if (slot->field_DFA < 0xFFFF) {
            slot->field_CF8.prefix.values.field_00 = slot->field_DFA;
        }
        if (slot->field_DFC < 0xFFFF) {
            slot->field_CF8.prefix.values.field_02 = slot->field_DFC;
        }
        if (slot->field_E1D != 0) {
            slot->field_CF8.field_10 = -1;
            slot->field_CF8.field_14 = -1;
            slot->field_CF8.field_18 = -1;
        }
        slot->field_E14 = 1;
        break;
    }
    }
}
