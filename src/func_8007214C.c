/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/ai_script_find_card.c (AiScript_FindCard), profile gcc_2_8_1_g0_split.
 * The declarations above the function are the subset of that tree's headers
 * this unit needs, preprocessed and with symbols renamed to this tree's
 * spelling (func_ADDR, D_ADDR); their types are that tree's. Byte-identical
 * under the flag row in tools_src/build.py. */
#include "kg_types.h"
#include "kg_variables.h"
#include "kg_functions.h"
s32 func_8007058C(void);
extern s32 D_800F5B98[20 ];
extern AiActiveCard D_801AB000[];
void func_800707C4(s32 kind, s32 *low, s32 *high);
void func_8007214C(void);
void func_8007214C(void)
{
    s32 wanted;
    s32 type;
    s32 visible_only;
    s32 result;
    s32 *table = D_800F5B98;
    s32 wanted_idx;
    s32 type_idx;
    s32 visible_idx;
    s32 start;
    s32 end;
    s32 i;

    wanted_idx = func_8007058C();
    wanted = table[wanted_idx];
    type_idx = func_8007058C();
    type = table[type_idx];
    visible_idx = func_8007058C();
    visible_only = table[visible_idx];
    result = func_8007058C();

    func_800707C4(type, &start, &end);

    for (i = start; i <= end; i++) {
        if (D_801AB000[i].card_id != wanted) {
            continue;
        }
        if (type == 1 || type == 3 || type == 6 || type == 8) {
            if (D_801AB000[i].flags & 0x4000 ) {
                continue;
            }
        }
        if (visible_only != 1) {
            break;
        }
        if (type < 5) {
            break;
        }
        if (!(D_801AB000[i].flags & 0x1000 )) {
            break;
        }
    }

    if (end < i) {
        D_800F5B98[result] = 0;
    } else {
        D_800F5B98[result] = i;
    }
}
