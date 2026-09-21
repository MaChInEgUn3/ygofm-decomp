/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/sound_secondary_object_selection.c (SD_FindLowestPrioritySecondaryObject), profile gcc_2_8_1_g0.
 * The declarations above the function are the subset of that tree's headers
 * this unit needs, preprocessed and with symbols renamed to this tree's
 * spelling (func_ADDR, D_ADDR); their types are that tree's. Byte-identical
 * under the flag row in tools_src/build.py. */
#include "kg_types.h"
#include "kg_variables.h"
#include "kg_functions.h"
extern SDSecondaryState *D_8009B458;
s32 func_8004A854(s32 value)
{
    s32 result = -1;
    SDSecondaryState *state = D_8009B458;
    s32 best = 0xFFFF;
    s32 i = 0;

    if (state->object_count > i) {
        s32 offset;

        value = (u8)value;
        offset = 0;
        do {
            SDSecondaryState *entry =
                ((SDSecondaryState *)((u8 *)( state ) + (  offset ))) ;
            u16 candidate = entry->objects[0].field_001E;

            if ((u16)best >= candidate &&
                entry->objects[0].channel_index == value &&
                entry->objects[0].field_000D != 0) {
                best = candidate;
                result = i;
            }
            offset += 0x28 ;
            state = D_8009B458;
            i++;
        } while (i < state->object_count);
    }
    best = result;
    return best;
}
