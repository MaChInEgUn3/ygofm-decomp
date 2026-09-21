/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/sound_output_state.c, profile gcc_2_8_1_g0.
 * The declarations above the function are the subset of that tree's headers
 * this unit needs, preprocessed and with symbols renamed to this tree's
 * spelling (func_ADDR, D_ADDR); their types are that tree's. Byte-identical
 * under the flag row in tools_src/build.py. */
#include "kg_types.h"
#include "kg_variables.h"
#include "kg_functions.h"
extern SDValue *D_8009B45C;
s32 func_80045054(void)
{
    s32 select = func_80076D20(
        (SpuDecodedData *)g_SDValue_output_level->buffer_053C, 5 
    );
    SDValue *choice_state = g_SDValue_output_level;
    s16 *values;
    s32 i;
    SDValue *loaded;
    SDValue *state;

    choice_state->decoded_half = select;
    if (select == 0 ) {
        values = (s16 *)choice_state->buffer_ptrs_153C[0];
    } else {
        values = (s16 *)choice_state->buffer_ptrs_153C[1];
    }
    loaded = g_SDValue_output_level;
    i = 0;
    state = loaded;
    state->output_level.sum = 0;
    state->field_1550.sum = 0;
    do {
        s32 value = *values;
        u32 square = value * value;
        state->output_level.sum += square >> 8;
        i++;
        values++;
    } while (i < 256 );
    {
        s32 result;
        s32 flags;
        s32 other;
        state = g_SDValue_output_level;
        do {
            result = state->output_level.halves[1];
        } while (0);
        flags = state->flags_0040;
        other = state->field_1550.halves[1];
        flags &= 3;
        state->output_level.sum = result;
        state->field_1550.sum = other;
        if (!flags) {
            return result;
        }
        return 0;
    }
}
