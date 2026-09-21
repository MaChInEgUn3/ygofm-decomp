/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/func_80051350.c, profile gcc_2_8_1_g8_split.
 * The declarations above the function are the subset of that tree's headers
 * this unit needs, preprocessed and with symbols renamed to this tree's
 * spelling (func_ADDR, D_ADDR); their types are that tree's. Byte-identical
 * under the flag row in tools_src/build.py. */
#include "kg_types.h"
#include "kg_variables.h"
#include "kg_functions.h"
s32 func_80051350(s32 mode, s32 min_extent, s32 depth);
extern ModelSlot D_800F2C40[3 ];
extern u8 D_8009AF98;
extern s8 D_8009AF99;
extern u16 D_8009B47A;
void func_80057F38(u8 *view);
extern long func_80086E50(long a);
extern int func_80086770(int a);
extern int func_800866A0(int a);
extern GsRVIEW2 D_800F56F0;
s32 func_80051350(s32 mode, s32 min_extent, s32 depth)
{
    ModelSeparationPair e3;
    ModelSeparationPair e0;
    ModelSeparationPair e1;
    ModelSeparationPair e2;
    ModelSeparationPair dx;
    ModelSeparationPair dy;
    ModelSeparationPair dz;
    ModelSeparationPair dist;
    ModelSeparationPair t;
    s32 moved;
    s32 hits;
    s32 i;
    s32 ox;
    s32 oz;
    s32 ref;
    s32 nv;
    s32 ry;
    s32 dz1;
    s32 v;
    s32 v5;
    ModelSlot *rec;

    ox = func_80086770(*(s16 *)&D_8009B47A + 0x800) * min_extent / 4096;
    oz = func_800866A0(*(s16 *)&D_8009B47A + 0x800) * min_extent / 4096;

    rec = D_800F2C40;
    v = (s16)rec[0].field_DC8[3] / 2;
    if (v < min_extent) {
        v = min_extent;
    }
    e0.values[0] = v;
    v = (s16)rec[1].field_DC8[3] / 2;
    if (v < min_extent) {
        v = min_extent;
    }
    do {
        e0.values[1] = v;
    } while (0);
    e3 = e0;
    v = (s16)rec[0].field_DC8[0] / 2;
    if (v < min_extent) {
        v = min_extent;
    }
    e1.values[0] = v;
    v = (s16)rec[1].field_DC8[0] / 2;
    if (v < min_extent) {
        v = min_extent;
    }
    do {
        e1.values[1] = v;
    } while (0);
    e0 = e1;
    v = (s16)rec[0].field_DC8[1] / 2;
    if (v < min_extent) {
        v = min_extent;
    }
    e2.values[0] = v;
    v = (s16)rec[1].field_DC8[1] / 2;
    if (v < min_extent) {
        v = min_extent;
    }
    do {
        e2.values[1] = v;
    } while (0);
    e1 = e2;
    v = (s16)rec[0].field_DC8[2] / 2;
    if (v < min_extent) {
        v = min_extent;
    }
    dx.values[0] = v;
    v5 = (s16)rec[1].field_DC8[2] / 2;
    if (v5 < min_extent) {
        v5 = min_extent;
    }
    nv = D_800F56F0.vpx;
    do {
        dx.values[1] = v5;
    } while (0);
    e2 = dx;

    ref = D_800F56F0.vpx;
    ref = ref + ox;
    dy.values[0] = ref - *(s16 *)&rec[0].field_DD0[0];
    dy.values[1] = ref - *(s16 *)&rec[1].field_DD0[0];
    dx = dy;
    nv = D_800F56F0.vpy;
    dz.values[0] = nv - *(s16 *)&rec[0].field_DD0[1];
    dz1 = nv - *(s16 *)&rec[1].field_DD0[1];
    do {
        dz.values[1] = dz1;
    } while (0);
    dy = dz;
    ry = D_800F56F0.vpz + oz;
    dist.values[0] = ry - *(s16 *)&rec[0].field_DD0[2];
    dist.values[1] = ry - *(s16 *)&rec[1].field_DD0[2];
    dz = dist;

    t.values[0] = func_80086E50(
        dx.values[0] * dx.values[0] + dz.values[0] * dz.values[0]);
    t.values[1] = func_80086E50(
        dx.values[1] * dx.values[1] + dz.values[1] * dz.values[1]);
    dist = t;

    moved = 0;
    hits = 0;
    if (D_800F2C40[0].field_E1F != 0) {
        if (D_800F2C40[0].field_DC0[3] >= 2) {
            if ((*(u32 *)D_800F2C40[0].field_DC0 & 0xFFFFFF) == 0) {
                dist.values[0] = -1;
            }
        }
    } else {
        dist.values[0] = -1;
    }
    if (D_800F2C40[1].field_E1F != 0) {
        if (D_800F2C40[1].field_DC0[3] >= 2) {
            if ((*(u32 *)D_800F2C40[1].field_DC0 & 0xFFFFFF) == 0) {
                dist.values[1] = -1;
            }
        }
    } else {
        dist.values[1] = -1;
    }

    depth = depth + 1;
    for (i = 0; i < 2; i++) {
        s32 limit;
        s32 eb;
        s32 d;
        s32 v;
        s32 *pv;
        s32 *pb;

        limit = e2.values[i];
        if (limit < e0.values[i]) {
            limit = e0.values[i];
        }
        if (limit < e3.values[i]) {
            limit = e3.values[i];
        }
         





        pv = e3.values - 4;
        pv += i;
        pv++;
        pb = e3.values - 4;
        pb += i;
        pb++;
        v = pv[13];
        eb = pb[7];
        if (v < 0) {
            v = -v;
        }
         

        eb = eb < v;
        if (eb) {
            continue;
        }
        d = dist.values[i];
        if (d < 0) {
            continue;
        }
        if (d >= limit) {
            continue;
        }
        if (moved != 0) {
            goto hit;
        }
        if (mode != 0) {
            s32 scale;
            s32 px;
            s32 pz;

            scale = ((limit - d) << 12) / limit;
            px = e0.values[i] * scale / 4096;
            if (dx.values[i] <= 0) {
                px = -px;
            }
            pz = e2.values[i] * scale / 4096;
            if (dz.values[i] <= 0) {
                pz = -pz;
            }
            {
                s32 ax = D_800F56F0.vrx;
                s32 az = D_800F56F0.vpz;
                s32 bx = D_800F56F0.vrz;
                s32 cx = D_800F56F0.vpx;
                s32 ux = bx - az;
                s32 uz = cx - ax;
                s32 cpx = cx + px;
                s32 apz = az + pz;
                s32 cross = ax * az - cx * bx;
                s32 len = func_80086E50(ux * ux + uz * uz);
                s32 sd = 0;

                if (len != 0) {
                    do {
                        sd = (cpx * ux + apz * uz + cross) / len;
                    } while (0);
                }
                if (D_8009AF98 == 0) {
                    if (sd < 0) {
                        D_8009AF99 = -1;
                    } else {
                        D_8009AF99 = 1;
                    }
                    D_8009AF98 = 0x1E;
                } else if (D_8009AF98 < 0xFF) {
                    D_8009AF98 = D_8009AF98 - 1;
                }
            }
            D_800F56F0.vpx = D_800F56F0.vpx + px;
            D_800F56F0.vpz = D_800F56F0.vpz + pz;
        }
        moved = limit;
        continue;
    hit:
        hits = hits + 1;
    }

    if (mode != 0 && moved != 0) {
        func_80057F38(0);
    }
    if (hits != 0 && mode != 0 && depth < 3) {
        func_80051350(mode, min_extent, depth);
    }
    return moved;
}
