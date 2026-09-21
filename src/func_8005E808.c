/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/func_8005E808.c, profile gcc_2_8_1_g8_split.
 * The declarations above the function are the subset of that tree's headers
 * this unit needs, preprocessed and with symbols renamed to this tree's
 * spelling (func_ADDR, D_ADDR); their types are that tree's. Byte-identical
 * under the flag row in tools_src/build.py. */
#include "kg_types.h"
#include "kg_variables.h"
#include "kg_functions.h"
extern long func_80086E50(long a);
extern SVECTOR D_800F5768[3 ];
void func_80058FB0(s32 idx, u16 *out);
int func_80058DD8(int index);
void func_8005EBF4(Key *cur, s32 k, s32 scale, s32 den, s16 *out);
void func_8005E808(Key *key);
void func_8005FB30(Key *key);
extern Key *D_8009B074;
void func_8005E808(Key *state)
{
     
    s16 pos[4];
    s16 buf[10][3];
    Coeff *e;
    SVECTOR *g;
    s32 i;
    s32 j;
    s32 a;
    s32 k;
    s32 sum;
    u32 d;
    s32 dx;
    s32 dy;
    s32 dz;
    s32 slot;
    u16 v;

    {
        s32 n;
        s32 t;
        n = state->magnitude;
        a = __builtin_abs(n);
        t = a;
        if (a <= 0) {
            t = 1;
        }
        k = t * 2;
    }
    func_8005FB30(state);
    state->progress = 0;
    if (D_8009B074->ready != 0) {
        return;
    }
    state->ready = 1;
    if (a >= 0x4000) {
        state->duration = 0x4000;
    } else {
        state->duration = k;
    }
    if (state->magnitude >= 0) {
        return;
    }

     
    e = (Coeff *)state;
    for (i = 0; i < 2; i++, e++) {
        g = &D_800F5768[i];
        switch ((s16)e->w) {
        case 0x80:
        case 0x81:
        {
            s32 dx, dy, dz;
            slot = (s16)(e->w & 0xFF7F);
            if (func_80058DD8(slot) != 1) {
                continue;
            }
            func_80058FB0(slot, (u16 *)pos);
            pos[0] = pos[0] + (u16)e->x;
            pos[1] = pos[1] + (u16)e->y;
            pos[2] = pos[2] + (u16)e->z;
            dx = pos[0] - g->vx;
            dy = pos[1] - g->vy;
            dz = pos[2] - g->vz;
            d = k * func_80086E50(dx * dx + dy * dy + dz * dz) / 1000;
            if (state->duration < d) {
                state->duration = d;
            }
            continue;
        }
        case 1:
            sum = 0;
            for (j = 0; j < 10; j++) {
                func_8005EBF4(state, i, j, 0x1E, buf[j]);
            }
            for (j = 1; j < 10; j++) {
                dx = buf[j - 1][0] - buf[j][0];
                dy = buf[j - 1][1] - buf[j][1];
                dz = buf[j - 1][2] - buf[j][2];
                sum += func_80086E50(dx * dx + dy * dy + dz * dz);
            }
            d = k * sum / 1000;
            if (state->duration < d) {
                state->duration = d;
            }
            continue;
        case 4:
        {
            s32 radius_scaled;
            s32 factor;
            v = (u16)D_800F5768[2].vx;
            if (D_800F5768[2].vx < e->x) {
                v = (u16)e->x;
            }
            radius_scaled = (s16)v * 6284 / 1000;
            d = k * radius_scaled;
            factor = __builtin_abs(e->y);
            d = (u32)(d * factor) / 4096000;
            if (state->duration < d) {
                state->duration = d;
            }
            continue;
        }
        default:
            continue;
        }
    }
}
