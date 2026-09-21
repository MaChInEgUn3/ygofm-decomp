/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/model_effect_state.c, profile gcc_2_8_1_g8_split.
 * The declarations above the function are the subset of that tree's headers
 * this unit needs, preprocessed and with symbols renamed to this tree's
 * spelling (func_ADDR, D_ADDR); their types are that tree's. Byte-identical
 * under the flag row in tools_src/build.py. */
#include "kg_types.h"
void func_8005F7B0(s32 value, s32 arg);
void func_8005F91C(
    s32 mode,
    ModelEffectEndpoint *first,
    ModelEffectEndpoint *second,
    s32 arg
);
extern s8 D_8009B07A;
extern u8 D_8009B07B;
extern u8 D_8009B07C;
void func_8005F91C(
    s32 arg0,
    ModelEffectEndpoint *arg1,
    ModelEffectEndpoint *arg2,
    s32 arg3
);
void func_8005F7B0(s32 value, s32 arg)
{
     

    s16 d[4] = {value, 0, 0, 5};
    s32 flag;
    s32 next;

    if (D_8009B07B == 1 && D_8009B07C == 1) {
        return;
    }
    flag = (s8)D_8009B07A;
    next = (u8)D_8009B07A;
    if (flag < 0) {
        flag = 0;
    } else {
        D_8009B07A = next + 1;
        flag = flag > 0;
    }
    func_8005F91C(
        flag, ((ModelEffectEndpoint *)( &d )) , ((ModelEffectEndpoint *)( &d )) , arg
    );
}
