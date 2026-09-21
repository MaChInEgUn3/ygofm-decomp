/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/model_effect_state.c, profile gcc_2_8_1_g8_split.
 * The declarations above the function are the subset of that tree's headers
 * this unit needs, preprocessed and with symbols renamed to this tree's
 * spelling (func_ADDR, D_ADDR); their types are that tree's. Byte-identical
 * under the flag row in tools_src/build.py. */
#include "kg_types.h"
#include "kg_variables.h"
#include "kg_functions.h"
void func_8005FBC4(
    s32 a, s32 b, s32 c, s32 d, Coeff *out, s32 scale
);
void func_8005FBC4(int a, int b, int c, int d, Coeff *out, int scale);
void func_8005EBF4(Key *cur, s32 k, s32 scale, s32 den, s16 *out)
{
    Key *keys[3] = {
        &D_800F5788[(cur - D_800F5788) % D_8009B078],
        &D_800F5788[(cur - D_800F5788 + 1) % D_8009B078],
        &D_800F5788[(cur - D_800F5788 + 2) % D_8009B078]
    };
    s16 *pts[4];
    Coeff co[3];
    s32 i;
    s32 j;

    func_8008E3D0(pts, 0, 16);
    pts[0] = (s16 *)(
        (u8 *)D_800F5768 + (u32)&((u8 (*)[8])0)[k]);
    for (i = 1; i < 3; i++) {
        s16 *e;

        e = (s16 *)(
            ((u8 *)( keys[i] ))  + (u32)&((u8 (*)[8])0)[k]);
        if (e[3] != 1) {
            break;
        }
    }
    j = i - 1;
    if (i < 3) {
        for (; i < 3; i++) {
            keys[i] = keys[j];
        }
    }
    for (i = 0; i < 3; i++) {
        pts[i + 1] = (s16 *)(
            ((u8 *)( keys[i] ))  + (u32)&((u8 (*)[8])0)[k]);
    }
    if (den != 0) {
        Key *kp;
        s16 *p;

        kp = &D_800F5788[(cur - D_800F5788 + D_8009B078 - 1) % D_8009B078];
        p = (s16 *)(((u8 *)( kp ))  + (u32)&((u8 (*)[8])0)[k]);
        if (p[3] == 1) {
            pts[0] = p;
        }
        i = 0;
    } else {
        den = keys[0]->duration;
        for (i = 1; i < 3; i++) {
            if (keys[i - 1] != keys[i]) {
                den += keys[i]->duration;
            }
        }
        i = 0;
    }
    for (i = 0; i < 3; i++) {
        s32 v;

        func_8005FBC4(pts[0][i], pts[1][i], pts[2][i], pts[3][i], &co[i], 2);
        v = co[i].x * scale / den;
        v = (v + co[i].y) * scale / den;
        v = (v + co[i].z) * scale / den;
        out[i] = co[i].w + v;
    }
}
