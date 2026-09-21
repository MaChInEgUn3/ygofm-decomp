/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/model_slot_row_tables.c, profile gcc_2_8_1_g0.
 * The declarations above the function are the subset of that tree's headers
 * this unit needs, preprocessed and with symbols renamed to this tree's
 * spelling (func_ADDR, D_ADDR); their types are that tree's. Byte-identical
 * under the flag row in tools_src/build.py. */
#include "kg_types.h"
#include "kg_variables.h"
#include "kg_functions.h"
extern ModelSlot D_800F2C40[3 ];
void func_8004D75C(s32 slot);
void func_8004D75C(s32 index)
{
    ModelSlot *ch;
    ModelSlotPart *slot;
    s32 *cmd;
    u32 word;
    s32 row;
    s32 i;
    s32 key;

    ch = &D_800F2C40[index];
    if (ch->field_DD8 == 0) {
        return;
    }
    i = 0;
    if (i < ch->field_E1B) {
        for (; i < ch->field_E1B; i++) {
            slot = ch->field_1E0[i];
            if (slot == 0) {
                break;
            }
            row = 1;
            slot->start_sid = row;
            key = ch->field_1E0[i]->start;
            cmd = &ch->field_DD8[key];
            ch->field_2C8[row][i] = key;
            while (1) {
                word = *cmd;
                if ((s32)word < 0) {
                    row = word >> 16;
                    row = row & 0x7F;
                    if (row == 0) {
                        break;
                    }
                    if (ch->field_2C8[row][i] != 0xFFFF) {
                        cmd++;
                    } else {
                        ch->field_2C8[row][i] = *(u16 *)cmd;
                        cmd = &ch->field_DD8[*(u16 *)cmd];
                    }
                } else {
                    ch->field_750[row].values[i] =
                        ch->field_750[row].values[i] + *((u8 *)cmd + 2);
                    cmd++;
                }
            }
        }
    }
    for (row = 1; row < 10 ; row++) {
        ch->field_750[row].max = 0;
        for (i = 0; i < ch->field_E1B; i++) {
            if (ch->field_750[row].max < ch->field_750[row].values[i]) {
                ch->field_750[row].max = ch->field_750[row].values[i];
            }
        }
    }
}
