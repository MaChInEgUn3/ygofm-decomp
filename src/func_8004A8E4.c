/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/sound_secondary_object_selection.c (SD_PrepareSecondaryObjectReuse), profile gcc_2_8_1_g0.
 * The declarations above the function are the subset of that tree's headers
 * this unit needs, preprocessed and with symbols renamed to this tree's
 * spelling (func_ADDR, D_ADDR); their types are that tree's. Byte-identical
 * under the flag row in tools_src/build.py. */
#include "kg_types.h"
extern SDSecondaryState *D_8009B458;
s32 func_8004A8E4(s32 index, s32 value);
s32 func_8004A8E4(s32 index, s32 value)
{
    SDSecondaryState *state = D_8009B458;
    SDSecondaryObject *object = &state->objects[index];

    if (object->channel_index != 0x63 ) {
        SDSecondaryRecord *record = &state->channels[object->channel_index];

        if ((record->field_0006 & 0xF) != 0) {
            record->field_0006 = record->field_0006 - 1;
        }
    }
    return index;
}
