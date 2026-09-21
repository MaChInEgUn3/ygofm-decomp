/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/dialog_choice_cursor.c (Dialog_ReadChoiceInput), profile gcc_2_8_1_g8.
 * The declarations above the function are the subset of that tree's headers
 * this unit needs, preprocessed and with symbols renamed to this tree's
 * spelling (func_ADDR, D_ADDR); their types are that tree's. Byte-identical
 * under the flag row in tools_src/build.py. */
#include "kg_types.h"
#include "kg_variables.h"
#include "kg_functions.h"
void func_80036F80(struct DuelEffectChannel *record);
extern s8 D_8009B345;
extern s8 D_8009B34D;
extern volatile u16 D_8009B394 __attribute__((section(".data")));
void func_80036F80(DuelEffectChannel *record);
s32 func_8003700C(DuelEffectChannel *record)
{
    if (D_8009B394 &
        ((0x1000  | 0x4000 )  | 0x8 )) {
        if (D_8009B394 & 0x8 ) {
            u8 choice = D_8009B34D;
            s32 count = D_8009B345;

            D_8009B34D = choice + 1;
            if ((s8)(choice + 1) >= count) {
                D_8009B34D = 0;
            }
        } else if (D_8009B394 & 0x4000 ) {
            u8 choice = D_8009B34D;
            s32 count = D_8009B345;

            D_8009B34D = choice + 1;
            if ((s8)(choice + 1) >= count) {
                D_8009B34D = choice;
                return 1;
            }
        } else {
            u8 choice = D_8009B34D;

            D_8009B34D = choice - 1;
            if ((s8)(choice - 1) < 0) {
                D_8009B34D = choice;
                return 1;
            }
        }
        func_8003FEE0(6);
        func_80036F80(record);
        return 1;
    }
    return 0;
}
