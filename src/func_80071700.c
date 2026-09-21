/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/ai_script_combo.c (AiScript_FindStrongest), profile gcc_2_8_1_g0_split.
 * The declarations above the function are the subset of that tree's headers
 * this unit needs, preprocessed and with symbols renamed to this tree's
 * spelling (func_ADDR, D_ADDR); their types are that tree's. Byte-identical
 * under the flag row in tools_src/build.py. */
#include "kg_types.h"
extern s32 D_800F5B98[20 ];
extern AiActiveCard D_801AB000[];
s32 func_80070920(s32 mode, s32 index);
void func_80070738(s32 kind, s32 *low, s32 *high);
s32 func_8007058C(void);
void func_80071700(void);
void func_80071700(void)
{
    s32 mode;
    s32 type;
    s32 hide_face_down;
    s32 sets;
    s32 result;
    s32 best_slot;
    s32 best_power;
    s32 *table = D_800F5B98;
    s32 start;
    s32 end;
    s32 i;
    s32 v;

    mode = table[func_8007058C()];
    best_slot = 0;
    type = table[func_8007058C()];
    best_power = -1;
    hide_face_down = table[func_8007058C()];
    sets = table[func_8007058C()];
    result = func_8007058C();

    func_80070738(type, &start, &end);

    for (i = start; i <= end; i++) {
        if (D_801AB000[i].card_id == 0) {
            continue;
        }
        if (type == 1 || type == 4 || type == 5) {
            if (D_801AB000[i].flags & 0x4000 ) {
                continue;
            }
        }
        if (type == 4) {
            if (D_801AB000[i].flags &
                0x800 ) {
                continue;
            }
        }
        if (type == 5) {
            if (!(D_801AB000[i].flags &
                  0x800 )) {
                continue;
            }
        }
        if (type >= 3 && type <= 5) {
            if (D_801AB000[i].flags & 0x1000 ) {
                if (hide_face_down == 1) {
                    continue;
                }
            }
        }
        if (func_80070920(sets, i) != 0) {
            continue;
        }
        if (mode != 1) {
            v = D_801AB000[i].attack;
            if (best_power < v) {
                best_power = v;
                best_slot = i;
            }
        }
        if (mode == 0) {
            continue;
        }
        v = D_801AB000[i].defense;
        if (best_power < v) {
            best_power = v;
            best_slot = i;
        }
    }

    D_800F5B98[result] = best_slot;
}
