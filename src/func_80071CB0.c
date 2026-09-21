/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/ai_script_find_card.c (AiScript_FindDefenseStopper), profile gcc_2_8_1_g0_split.
 * The declarations above the function are the subset of that tree's headers
 * this unit needs, preprocessed and with symbols renamed to this tree's
 * spelling (func_ADDR, D_ADDR); their types are that tree's. Byte-identical
 * under the flag row in tools_src/build.py. */
#include "kg_types.h"
s32 func_8007058C(void);
extern s32 D_800F5B98[20 ];
extern AiActiveCard D_801AB000[];
void func_80071CB0(void);
void func_80071CB0(void)
{
    s32 hide_face_down;
    s32 result;
    s32 answer;
    s32 taken[2 ][5 ];
    s32 best;
    s32 other;
    s32 i;
    s32 j;
    AiActiveCard *cards;
    AiActiveCard *others;

    hide_face_down = D_800F5B98[func_8007058C()];
    result = func_8007058C();
    answer = 1;

    for (i = 0; i < 2 ; i++) {
        for (j = 0; j < 5 ; j++) {
            taken[i][j] = 0;
        }
    }

    i = 0;
    do {
        best = 0 ;
        cards = &D_801AB000[1 ];
        for (j = 0; j < 5 ; j++) {
            if (taken[0][j] == 0) {
                if (cards[j].attack > D_801AB000[best].attack) {
                    best = j + 1 ;
                }
            }
        }
        if (best != 0 ) {
            taken[0][best - 1 ] = 1;
        }

        other = 0 ;
        others = &D_801AB000[(1  + (0x294  / 0x0C ) ) ];
        for (j = 0; j < 5 ; j++) {
            if (taken[1][j] == 0) {
                if (hide_face_down == 0 ||
                    !(others[j].flags & 0x1000 )) {
                    if (others[j].attack > D_801AB000[other].attack) {
                        other = j + (1  + (0x294  / 0x0C ) ) ;
                    }
                }
            }
        }
        if (other == 0 ) {
            break;
        }
        taken[1][other - (1  + (0x294  / 0x0C ) ) ] = 1;
        if (D_801AB000[best].attack <= D_801AB000[other].attack) {
            answer = 0;
            break;
        }
        i++;
    } while (i < 5 );

    if (i == 0) {
        answer = 0;
    }
    D_800F5B98[result] = answer;
}
