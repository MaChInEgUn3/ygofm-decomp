/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/ai_script_state_ops.c (AiScript_LoadOpponentData), profile gcc_2_8_1_g0_split.
 * The declarations above the function are the subset of that tree's headers
 * this unit needs, preprocessed and with symbols renamed to this tree's
 * spelling (func_ADDR, D_ADDR); their types are that tree's. Byte-identical
 * under the flag row in tools_src/build.py. */
#include "kg_types.h"
extern s32 D_800F5B98[20 ];
extern AiOpponentData D_800917F0[40 ];
void func_800734DC(void);
s32 func_8007058C(void);
void func_800734DC(void)
{
    s32 index;
    s32 field;
    s32 dst;
    s32 *mem = D_800F5B98;

    index = mem[func_8007058C()];
    field = mem[func_8007058C()];
    dst = func_8007058C();
    if (field == 0) {
        mem[dst] = D_800917F0[index].values[1] * 100;
    } else {
        mem[dst] = D_800917F0[index].values[field + 1];
    }
}
