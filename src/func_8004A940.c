/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/sound_secondary_object_selection.c (SD_SelectSecondaryObject), profile gcc_2_8_1_g0.
 * The declarations above the function are the subset of that tree's headers
 * this unit needs, preprocessed and with symbols renamed to this tree's
 * spelling (func_ADDR, D_ADDR); their types are that tree's. Byte-identical
 * under the flag row in tools_src/build.py. */
#include "kg_types.h"
extern SDSecondaryState *D_8009B458;
s32 func_8004A8E4(s32 index, s32 value);
s32 func_8004A940(s32 value, s32 variant);
extern 
s32 func_8004A940(s32 value, s32 variant)
{
    SDSecondaryState *state = D_8009B458;
    s32 i;
    s32 result = -1;
    u32 best;

     
    do {
        do {
            do {
                i = 0;
                if (state->object_count > 0) {
                    s32 none = 0x63 ;
                    s32 count = state->object_count;
                    do {
                        if (state->objects[i].channel_index == none) {
                            return i;
                        }
                        i++;
                    } while (i < count);
                }

                state = D_8009B458;
                i = 0;
                if (state->object_count > 0) {
                    s32 count = state->object_count;
                    do {
                        if (state->objects[i].field_000D == 0) {
                            return func_8004A8E4(i, (u8)value);
                        }
                        i++;
                    } while (i < count);
                }

                state = D_8009B458;
                i = 0;
                if (state->object_count > 0) {
                    do {
                        u8 owner = state->objects[i].channel_index;
                        if (owner == (u8)value &&
                            state->objects[i].field_0005 == (u8)variant) {
                            return func_8004A8E4(i, owner);
                        }
                        state = D_8009B458;
                        i++;
                    } while (i < state->object_count);
                }

                state = D_8009B458;
                i = 0;
                if (state->object_count > 0) {
                    s32 count = state->object_count;
                    do {
                        if (state->objects[i].field_000D == 0) {
                            return func_8004A8E4(i, (u8)value);
                        }
                        i++;
                    } while (i < count);
                }
            } while (0);
        } while (0);
    } while (0);

    state = D_8009B458;
    best = 0xFFFF;
    i = 0;
    if (state->object_count > 0) {
        s32 count = state->object_count;
        do {
            u16 candidate = state->objects[i].field_001E;
            if (candidate < best) {
                best = candidate;
                result = i;
            }
            i++;
        } while (i < count);
    }
    if (best >= 0xFFFF) {
        return -1;
    }
    return func_8004A8E4(result, (u8)value);
}
