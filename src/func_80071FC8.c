/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/ai_script_find_card.c (AiScript_FindFirstCard), profile gcc_2_8_1_g0_split.
 * The declarations above the function are the subset of that tree's headers
 * this unit needs, preprocessed and with symbols renamed to this tree's
 * spelling (func_ADDR, D_ADDR); their types are that tree's. Byte-identical
 * under the flag row in tools_src/build.py. */
#include "kg_types.h"
s32 func_8007058C(void);
extern s32 D_800F5B98[20 ];
extern AiActiveCard D_801AB000[];
void func_800707C4(s32 kind, s32 *low, s32 *high);
void func_80071FC8(void);
void func_80071FC8(void)
{
    s32 wanted;
    s32 type;
    s32 result;
    s32 *table = D_800F5B98;
    s32 wanted_idx;
    s32 type_idx;
    s32 start;
    s32 end;
    s32 i;

    wanted_idx = func_8007058C();
    wanted = table[wanted_idx];
    type_idx = func_8007058C();
    type = table[type_idx];
    result = func_8007058C();

    func_800707C4(type, &start, &end);

    for (i = start; i <= end; i++) {
        if (type == 1 || type == 3 || type == 6 || type == 8) {
            if (D_801AB000[i].flags & 0x4000 ) {
                continue;
            }
        }
        if (D_801AB000[i].card_id != 0) {
            if (D_801AB000[i].flags & 0x1000 ) {
                if (wanted == 2) {
                    break;
                }
            } else {
                if (wanted == 1) {
                    break;
                }
            }
        } else {
            if (wanted == 0) {
                break;
            }
        }
    }

    if (end < i) {
        D_800F5B98[result] = 0;
    } else {
        D_800F5B98[result] = i;
    }
}
