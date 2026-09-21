/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/duel_card_data_transfer.c (Duel_StepCardDataTransfer), profile gcc_2_8_1_g0_no_split.
 * The declarations above the function are the subset of that tree's headers
 * this unit needs, preprocessed and with symbols renamed to this tree's
 * spelling (func_ADDR, D_ADDR); their types are that tree's. Byte-identical
 * under the flag row in tools_src/build.py. */
#include "kg_types.h"
#include "kg_variables.h"
#include "kg_functions.h"
void func_800245EC(FileTransferDescriptor *o, int mode) {
    s16 *p = o->callback_data;

    if (mode == 0) {
        o->field_30.h.counter = *p;
        o->phase_size = (1 << 11 ) ;
        D_8009B0F4 &= ~0x230000;
        o->value_08 = o->value_0C = o->position;
        o->done = 1;
        return;
    }
    if (mode == 1) {
        p++;
        o->callback_data = p;
        o->position += 0x580 ;
    }
    o->field_30.h.counter++;
    if (o->field_30.h.counter == *p) {
        o->phase_size = (1 << 11 ) ;
        o->result = 1;
        D_8009B0F4 &= ~0x230000;
        o->value_08 = o->value_0C = o->position;
        o->done = 1;
    } else {
        o->phase_size = (1 << 11 ) ;
        o->result = 2;
        D_8009B0F4 &= ~0x30000;
        D_8009B0F4 |= 0x200000;
        o->done = 1;
    }
}
