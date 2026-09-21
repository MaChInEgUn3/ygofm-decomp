/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/func_8004E7B0.c, profile gcc_2_8_1_g8_split_comm.
 * The declarations above the function are the subset of that tree's headers
 * this unit needs, preprocessed and with symbols renamed to this tree's
 * spelling (func_ADDR, D_ADDR); their types are that tree's. Byte-identical
 * under the flag row in tools_src/build.py. */
#include "kg_types.h"
#include "kg_variables.h"
#include "kg_functions.h"
extern ModelBytes8 D_8009B478;
extern s16 D_8009B47A;
extern s16 D_8009B47C;
void func_8004E7B0(s32 force)
{
    s32 dy;
    s32 dz;
    s32 t;
    s32 a;
    s32 b;
    s32 u;
    s32 r;
    s32 m;

    dy = D_8009B47A - D_8009B482;
    dz = D_8009B47C - D_8009B484;
    if (__builtin_abs(dy) >= 0x801) {
        if (dy > 0) {
            dy -= 0x1000 ;
        } else {
            dy += 0x1000 ;
        }
    }
    if (force != 0 || dy != 0) {
        m = ((ModelBackgroundRecord *)D_8009AF88)->texture_width;
        D_8009AF8E = (dy * 1280 / 384 + D_8009AF8E + m) % m;
    }
    if (force != 0 || dz != 0) {
        a = D_8009B47C;
        if (a < 0x801) {
            goto low;
        }
        t = a - 0x1000 ;
        if (t < 0) {
            goto neg_side;
        }
        r = -0x139;
        if (t < (0x1000  / 4) ) {
            goto compute;
        }
        goto store;
neg_side:
        r = -0x139;
        if (0x1000  - a >= (0x1000  / 4) ) {
            goto store;
        }
compute:
        b = D_8009B47C;
        u = b - 0x1000 ;
        if (u < 0) {
            goto sub_form;
        }
        r = -(u * 26) / 85;
        goto store;
sub_form:
        r = -((0x1000  - b) * 26) / 85;
        goto store;
low:
        if (a >= (0x1000  / 4) ) {
            goto clamp_pos;
        }
        r = (a * 26) / 85;
        goto store;
clamp_pos:
        r = 0x139;
store:
        D_8009AF90 = r;
    }
    D_8009B480 = D_8009B478;
}
