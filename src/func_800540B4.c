/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/func_800540B4.c, profile gcc_2_8_1_g8_split_comm.
 * The declarations above the function are the subset of that tree's headers
 * this unit needs, preprocessed and with symbols renamed to this tree's
 * spelling (func_ADDR, D_ADDR); their types are that tree's. Byte-identical
 * under the flag row in tools_src/build.py. */
#include "kg_types.h"
#include "kg_variables.h"
#include "kg_functions.h"
static inline s32 Model_MirrorOffset(s32 index, s32 value, s32 offset)
{
    if (index > 0) {
        return value - offset;
    }
    return value + offset;
}
void func_800540B4(s32 index)
{
    MATRIX zero;
    long sxy_z;
    long flag;
    GsOT *ot;
    ModelSlot *slot;
    s8 *blk;
    ModelSlotHeadEntry *e;
    s32 i;
    s32 x;
    s32 y;
    s32 z;
    s32 a;
    s32 b;
    s32 count;
    s32 w;
    s32 h;
    s32 d;
    s32 v;
    s32 t;
    u8 fl;

    if (index < 2) {
        ot = D_800E9D98[0];
    } else {
        ot = D_800E9D98[1];
    }
    slot = &D_800F2C40[index];
    blk = (s8 *)&slot->field_CF8;
    if (slot->field_E1F == 0) {
        return;
    }
    if (index == 2 && slot->field_DA0[0] == -0x1000 && slot->field_DA0[1] == slot->field_DA0[0]
        && slot->field_DA0[2] == slot->field_DA0[1]) {
        return;
    }
    if (slot->field_E11 != 1 && slot->field_DC0[3] >= 2 && !((*(s32 *)((u8 *)( slot->field_DC0 ) + (  0 )))  & 0xFFFFFF)) {
        return;
    }
    func_800857E0(0, (GsF_LIGHT *)&slot->field_D70[0]);
    func_800857E0(1, (GsF_LIGHT *)&slot->field_D70[1]);
    func_800857E0(2, (GsF_LIGHT *)&slot->field_D70[2]);
    func_80085D50(slot->field_DA0[0], slot->field_DA0[1], slot->field_DA0[2]);
    D_8009AFE0 = slot->field_DF0;
    D_8009AFE4 = slot->field_E11;
    if (slot->field_E11 != 4) {
        slot->field_E11 = 0;
    }
    if (index < 2) {
        ot->length = 0xE;
        if ((slot->field_DC0[7] % 6) && slot->field_DC0[3] == 0 && D_8009AFE4 == 0) {
            s32 step;
            s32 colour;
            s32 r;
            s32 fl;
            s32 mode;
            s32 lim;
            s32 limg;
            s32 limb;

            step = func_80058E1C() * 2;
            h = slot->field_DC0[6];
            w = slot->field_DC0[5];
            r = slot->field_DC0[4];
            colour = (h << 16) | (w << 8) | r;
            fl = slot->field_DC0[7];
            { if ((  fl ) != 0) { ( colour ) |= 0x02000000; } D_8009AFAC = ( colour ) | 0x24000000; D_8009AFB0 = ( colour ) | 0x2C000000; D_8009AFB4 = ( colour ) | 0x34000000; D_8009AFB8 = ( colour ) | 0x3C000000; D_8009AFCC = ( colour ) | 0x4A000000; D_8009AFD0 = ( colour ) | 0x4E000000; D_8009AFBC = ( colour ) | 0x26000000; D_8009AFC0 = ( colour ) | 0x2E000000; D_8009AFC4 = ( colour ) | 0x36000000; D_8009AFC8 = ( colour ) | 0x3E000000; (*((u8 *)( &D_8009AFE6 ) + (  0 )))  = (  r ); (*((u8 *)( &D_8009AFE6 ) + (  1 )))  = (  w ); D_8009AFE8 = (  h ); if ((  fl ) != 2) { if ((  fl ) != 3) { if ((  fl ) != 4) { if ((  fl ) != 5) { D_8009AFD8 = 0; } else { D_8009AFD8 = 0x200000; } } else { D_8009AFD8 = 0x600000; } } else { D_8009AFD8 = 0x400000; } } else { D_8009AFD8 = 0x200000; } if ((  fl ) == 5) { D_8009AFDC = 0x3C200000; } else { D_8009AFDC = 0; } (  mode ) = (  fl ) - 1; D_8009AFE5 = (u32)(  mode ) < 4; if (D_8009AFE5 != 0) { D_8009AFD4 = (((  mode ) << 5) & 0x9FF) | 0xE1000200; } else { D_8009AFD4 = 0xE1000220; } } ;
            D_8009AFE4 = 3;
            lim = slot->field_DC0[0];
            if (slot->field_DC0[4] + step < lim) {
                lim = slot->field_DC0[4] + step;
            }
            slot->field_DC0[4] = lim;
            limg = slot->field_DC0[1];
            if (slot->field_DC0[5] + step < limg) {
                limg = slot->field_DC0[5] + step;
            }
            slot->field_DC0[5] = limg;
            limb = slot->field_DC0[2];
            if (slot->field_DC0[6] + step < limb) {
                limb = slot->field_DC0[6] + step;
            }
            slot->field_DC0[6] = limb;
            if (slot->field_DC0[4] >= slot->field_DC0[0] && slot->field_DC0[5] >= slot->field_DC0[1]
                && (u32)(limb & 0xFF) >= slot->field_DC0[2]) {
                slot->field_DC0[7] = 0;
            }
        } else if (D_8009AFE4 != 1) {
            s32 colour;
            s32 fl;
            s32 mode;

            h = slot->field_DC0[2];
            w = slot->field_DC0[1];
            y = slot->field_DC0[0];
            fl = slot->field_DC0[3];
            colour = h << 16;
            colour |= w << 8;
            colour |= y;
            { if ((  fl ) != 0) { ( colour ) |= 0x02000000; } D_8009AFAC = ( colour ) | 0x24000000; D_8009AFB0 = ( colour ) | 0x2C000000; D_8009AFB4 = ( colour ) | 0x34000000; D_8009AFB8 = ( colour ) | 0x3C000000; D_8009AFCC = ( colour ) | 0x4A000000; D_8009AFD0 = ( colour ) | 0x4E000000; D_8009AFBC = ( colour ) | 0x26000000; D_8009AFC0 = ( colour ) | 0x2E000000; D_8009AFC4 = ( colour ) | 0x36000000; D_8009AFC8 = ( colour ) | 0x3E000000; (*((u8 *)( &D_8009AFE6 ) + (  0 )))  = (  y ); (*((u8 *)( &D_8009AFE6 ) + (  1 )))  = (  w ); D_8009AFE8 = (  h ); if ((  fl ) != 2) { if ((  fl ) != 3) { if ((  fl ) != 4) { if ((  fl ) != 5) { D_8009AFD8 = 0; } else { D_8009AFD8 = 0x200000; } } else { D_8009AFD8 = 0x600000; } } else { D_8009AFD8 = 0x400000; } } else { D_8009AFD8 = 0x200000; } if ((  fl ) == 5) { D_8009AFDC = 0x3C200000; } else { D_8009AFDC = 0; } (  mode ) = (  fl ) - 1; D_8009AFE5 = (u32)(  mode ) < 4; if (D_8009AFE5 != 0) { D_8009AFD4 = (((  mode ) << 5) & 0x9FF) | 0xE1000200; } else { D_8009AFD4 = 0xE1000220; } } ;
            if ((*(s32 *)((u8 *)( slot->field_DC0 ) + (  0 )))  != 0x808080) {
                D_8009AFE4 = 3;
            }
            slot->field_DC0[7] = 0;
        } else {
            goto neutral;
        }
    } else {
    neutral:
        (*((u8 *)( &D_8009AFE6 ) + (  0 )))  = 0x80;
        (*((u8 *)( &D_8009AFE6 ) + (  1 )))  = 0x80;
        D_8009AFE8 = 0x80;
        D_8009AFAC = 0x24808080;
        D_8009AFB0 = 0x2C808080;
        D_8009AFB4 = 0x34808080;
        D_8009AFB8 = 0x3C808080;
        D_8009AFCC = 0x4A808080;
        D_8009AFD0 = 0x4E808080;
        D_8009AFBC = 0x26808080;
        D_8009AFC0 = 0x2E808080;
        D_8009AFC4 = 0x36808080;
        D_8009AFC8 = 0x3E808080;
        D_8009AFD8 = 0;
        D_8009AFDC = 0;
        D_8009AFE5 = 0;
        D_8009AFD4 = 0xE1000220;
    }

    e = slot->field_000;
    if (D_8009AFE4 >= 3) {
        D_8009AFE0 = 0;
    }
    for (i = 0; i < slot->field_E1A; i++, e++) {
        MATRIX ls;
        MATRIX lw;
        GsCOORDUNIT *unit;

        a = 0;
        if (D_8009AF9B != 0 && slot->entry_count < i) {
            continue;
        }
        if (D_8009AF9C != 0 && i > 0 && !(slot->entry_count < i)) {
            if (!((((u8 *)D_8009AF9C)[(i - 1) / 8] >> ((i - 1) % 8)) & 1)) {
                a = 1;
                if (D_8009AF9B != 0) {
                    continue;
                }
            }
        }
        if (e->field_04 == 0) {
            continue;
        }
        if (slot->field_D1C != 0 &&
            ((GsCOORDUNIT *)( e->field_00 )) ->super == slot->field_D1C) {
            s32 k;
            s32 found;
            u8 n;
            s32 idx;

            idx = (((GsCOORDUNIT *)( e->field_00 ))  -
                   ((GsCOORDUNIT *)( slot->entries )) ) * 0x14 + 0x04000001;
            k = 0;
            found = 0;
            n = slot->field_E1B;
            for (; k < n; k++) {
                if (slot->field_1E0[k]->rewrite_idx == idx) {
                    if (slot->field_1E0[k]->aframe == 0xFFFF
                        && ((slot->field_BEC[k / 8] >> (k % 8)) & 1)
                        && slot->field_750[slot->field_BF5].values[k] != 0) {
                        found = 1;
                    }
                    break;
                }
            }
            if (found) {
                func_80087670(
                    & ((GsCOORDUNIT *)( e->field_00 )) ->matrix,
                    ((VECTOR *)( &slot->field_DB0 )) );
            } else {
                func_8005922C(
                    ((GsCOORDUNIT *)( e->field_00 )) ,
                    ((VECTOR *)( &slot->field_DB0 )) );
            }
        }
        if ((*(s32 *)((u8 *)( e->field_04 ) + (  0 )))  != -1 || (*(s32 *)((u8 *)( e->field_04 ) + (  8 )))  != 0) {
            if (a) {
                func_8008E3D0(&zero, 0, 0x20);
                func_800855D0(&zero);
            } else if ((unit = ((GsCOORDUNIT *)( e->field_00 )) ) != 0) {
                if (D_8009AFE4 != 0) {
                    s32 k;
                    s32 m;
                    u16 max;
                    s16 *cp;

                    do {
                        func_8008AA30(unit, &lw, &ls);
                    } while (0);
                    max = 0;
                    cp = (s16 *)&lw;
                    for (k = 0; k < 9; k++, cp++) {
                        m = (( *cp ) >= 0 ? ( *cp ) : -( *cp )) ;
                        if (max < m) {
                            max = m;
                        }
                    }
                    cp = (s16 *)&lw;
                    if (max != 0) {
                        for (k = 0; k < 9; k++, cp++) {
                            *cp = (*cp << 12) / max;
                        }
                    } else {
                        cp[8] = 0x1000;
                        cp[4] = 0x1000;
                        cp[0] = 0x1000;
                    }
                    func_80085600(&lw);
                } else {
                    func_8008A760(unit, &ls);
                }
                func_800855D0(&ls);
            }
            func_8008A150((GsUNIT *)e, ot, (u32 *)0x1F800000);
        }
    }

    if (D_8009AF9C != 0) {
        if (index < 2) {
            ot->length = 0xC;
        }
        return;
    }
    if (index < 2 && slot->field_D1C != 0) {
        s16 minx;
        s16 miny;
        s16 minz;
        s16 maxx;
        s16 maxy;
        s16 maxz;
        GsCOORDUNIT *unit;
        u8 *list;

        minz = miny = minx = 0x7FFF;
        maxz = maxy = maxx = -0x8000;
        count = x = y = z = 0;
        e = slot->field_000;
        for (i = 0; i < slot->field_E1A; i++, e++) {
            unit = ((GsCOORDUNIT *)( e->field_00 )) ;
            if (unit != 0 && e->field_04 != 0
                && ((*(s32 *)((u8 *)( e->field_04 ) + (  0 )))  != -1 || (*(s32 *)((u8 *)( e->field_04 ) + (  8 )))  != 0)) {
                count++;
                x += unit->workm.t[0];
                y += unit->workm.t[1];
                z += unit->workm.t[2];
            }
        }
        if (count != 0) {
            x /= count;
            y /= count;
            z /= count;
        } else {
            x = slot->field_D1C->workm.t[0];
            y = slot->field_D1C->workm.t[1];
            z = slot->field_D1C->workm.t[2];
        }
        x = Model_MirrorOffset(index, x, blk[4] * 0x10);
        slot->field_DD0[0] = x;
        y += blk[5] * 0x10;
        slot->field_DD0[1] = y;
        z = Model_MirrorOffset(index, z, blk[6] * 0x10);
        count = y = 0;
        slot->field_DD0[2] = z;
        e = slot->field_000;
        for (i = 0; i < slot->field_E1A; i++, e++) {
            unit = ((GsCOORDUNIT *)( e->field_00 )) ;
            if (unit != slot->field_D1C && unit != slot->field_D18 && unit != 0 && (list = e->field_04) != 0) {
                s32 uy;

                if (unit->super == slot->field_D1C) {
                    count++;
                    y += unit->workm.t[1];
                }
                if ((*(s32 *)((u8 *)( list ) + (  0 )))  != -1 || (*(s32 *)((u8 *)( list ) + (  8 )))  != 0) {
                    a = unit->workm.t[0];
                    b = unit->workm.t[2];
                    uy = unit->workm.t[1];
                    if (maxx < a) {
                        maxx = a;
                    }
                    if (a < minx) {
                        minx = a;
                    }
                    if (maxy < uy) {
                        maxy = uy;
                    }
                    if (uy < miny) {
                        miny = uy;
                    }
                    if (maxz < b) {
                        maxz = b;
                    }
                    if (b < minz) {
                        minz = b;
                    }
                }
            }
        }
        if (count != 0) {
            y /= count;
        } else {
            y = slot->field_D1C->workm.t[1];
        }
        slot->field_DD0[3] = (y - 700) / 3 + blk[5] * 0x10;
        w = maxx - minx;
        h = maxy - miny;
        d = maxz - minz;
        if ((s16)slot->field_DC8[3] < w) {
            slot->field_DC8[3] = w;
        }
        if ((s16)slot->field_DC8[3] < d) {
            slot->field_DC8[3] = d;
        }
        w += 0x32;
        h += 0x32;
        d += 0x32;
        v = (s16)slot->field_DC8[0];
        if (v != 0) {
            if (w < v) {
                t = v - w;
                if (t >= 0x15) {
                    t = 0x14;
                }
                slot->field_DC8[0] = slot->field_DC8[0] - t;
            } else {
                t = w - v;
                if (t >= 0x15) {
                    t = 0x14;
                }
                slot->field_DC8[0] = slot->field_DC8[0] + t;
            }
        } else {
            slot->field_DC8[0] = w;
        }
        v = (s16)slot->field_DC8[1];
        if (v != 0) {
            if (h < v) {
                t = v - h;
                if (t >= 0x15) {
                    t = 0x14;
                }
                slot->field_DC8[1] = slot->field_DC8[1] - t;
            } else {
                t = h - v;
                if (t >= 0x15) {
                    t = 0x14;
                }
                slot->field_DC8[1] = slot->field_DC8[1] + t;
            }
        } else {
            slot->field_DC8[1] = h;
        }
        v = (s16)slot->field_DC8[2];
        if (v != 0) {
            if (d < v) {
                t = v - d;
                if (t >= 0x15) {
                    t = 0x14;
                }
                slot->field_DC8[2] = slot->field_DC8[2] - t;
            } else {
                t = d - v;
                if (t >= 0x15) {
                    t = 0x14;
                }
                slot->field_DC8[2] = slot->field_DC8[2] + t;
            }
        } else {
            slot->field_DC8[2] = d;
        }
        if (slot->field_E12 != 0) {
            SVECTOR v0;
            SVECTOR v1;
            SVECTOR v2;
            ModelEffectAdjustment adj;
            POLY_G3 poly;
            s32 cx;
            s32 res;

            if (D_8009AFE4 == 1) {
                goto finish_ot;
            }
            (((P_TAG *)( &poly ))->len  = (u8)(  6 )) ;
            (((P_TAG *)( &poly ))->code = (u8)(  0x30 )) ;
            poly.r0 = (*((u8 *)( &D_8009AFE6 ) + (  0 ))) ;
            poly.g0 = (*((u8 *)( &D_8009AFE6 ) + (  1 ))) ;
            poly.b0 = D_8009AFE8;
            poly.r1 = (s16)(*((u8 *)( &D_8009AFE6 ) + (  0 )))  / 16;
            poly.g1 = (s16)(*((u8 *)( &D_8009AFE6 ) + (  1 )))  / 16;
            poly.b1 = (s16)D_8009AFE8 / 16;
            poly.r2 = (s16)(*((u8 *)( &D_8009AFE6 ) + (  0 )))  / 16;
            poly.g2 = (s16)(*((u8 *)( &D_8009AFE6 ) + (  1 )))  / 16;
            poly.b2 = (s16)D_8009AFE8 / 16;
            func_800855D0((MATRIX *)func_80059220());
            func_80057E20(index, &adj);
            w = adj.x;
            d = adj.z;
            if (w >= 0x12C) {
                cx = 0x320;
                if (w < 0x321) {
                    cx = w;
                }
            } else {
                cx = 0x12C;
            }
            w = cx;
            if (d >= 0x12C) {
                cx = 0x320;
                if (d < 0x321) {
                    cx = d;
                }
            } else {
                cx = 0x12C;
            }
            d = cx;
            if (D_8009AF92 != 0x8000) {
                y = (s16)D_8009AF92;
            } else {
                y = D_800F2C40[2].field_D18->matrix.t[1] + (*(s16 *)((u8 *)( D_8009AF88 ) + (  0xA2 ))) ;
            }
            a = w / 2;
            b = d / 2;
            v0.vx = x;
            v0.vy = y;
            v0.vz = z;
            v2.vx = x + a;
            v2.vy = y;
            v2.vz = z;
            v1.vy = y;
            for (i = 0; i < 8; i++) {
                v0.vx = x;
                v0.vz = z;
                v1.vx = x + ((ModelShadowFanStep *)D_800914E8)[i].x * a / 4096;
                v1.vz = z + ((ModelShadowFanStep *)D_800914E8)[i].z * b / 4096;
                if ((*((u8 *)( D_8009AF88 ) + (  0xA1 )))  & 1) {
                    v0.vx = (( v0.vx ) < -0x4B0 ? -0x4B0 : ( v0.vx ) < 0x4B1 ? ( v0.vx ) : 0x4B0) ;
                    v0.vz = (( v0.vz ) < -0x4B0 ? -0x4B0 : ( v0.vz ) < 0x4B1 ? ( v0.vz ) : 0x4B0) ;
                    v1.vx = (( v1.vx ) < -0x4B0 ? -0x4B0 : ( v1.vx ) < 0x4B1 ? ( v1.vx ) : 0x4B0) ;
                    v1.vz = (( v1.vz ) < -0x4B0 ? -0x4B0 : ( v1.vz ) < 0x4B1 ? ( v1.vz ) : 0x4B0) ;
                    v2.vx = (( v2.vx ) < -0x4B0 ? -0x4B0 : ( v2.vx ) < 0x4B1 ? ( v2.vx ) : 0x4B0) ;
                    v2.vz = (( v2.vz ) < -0x4B0 ? -0x4B0 : ( v2.vz ) < 0x4B1 ? ( v2.vz ) : 0x4B0) ;
                    if (v1.vx == v2.vx && (( v0.vx ) >= 0 ? ( v0.vx ) : -( v0.vx ))  >= (( v1.vx ) >= 0 ? ( v1.vx ) : -( v1.vx )) ) {
                        goto skip;
                    }
                    if (v1.vz == v2.vz && (( v0.vz ) >= 0 ? ( v0.vz ) : -( v0.vz ))  >= (( v1.vz ) >= 0 ? ( v1.vz ) : -( v1.vz )) ) {
                        goto skip;
                    }
                }
                res = func_80087A50(&v0, &v1, &v2, (long *)&poly.x0, (long *)&poly.x1, (long *)&poly.x2,
                    &sxy_z, &flag);
                sxy_z = func_800879A0(*(long *)&poly.x0, *(long *)&poly.x1, *(long *)&poly.x2);
                if (res >= 0 && flag >= 0) {
                    func_8005B260((u32 *)&poly, ot, 0xFFF, 2);
                }
            skip:
                v2 = v1;
            }
        }
    }
    if (D_8009AFE4 == 1) {
    finish_ot:
        if (index < 2) {
            ot->length = 0xC;
        }
        return;
    }
    if (slot->field_E10 != 0) {
        func_80057AF4(index, -1, 0);
    } else if (slot->field_E0F != 0) {
        if (slot->field_E0F != slot->field_BF5) {
            func_800597C8(index, slot->field_E0F, 0);
        } else if (slot->field_E16 != 0x23) {
            slot->field_BF6 = 0;
        }
    }
    fl = slot->field_E13;
    if (fl != 0 && fl != 0xFF) {
        RECT rect;
        u16 pal[16];
        RECT prect;
        u16 pix[0x400];

        if (fl == 0xFE) {
            s32 k;
            s32 row;
            u16 *cp;

            rect.x = index << 8;
            rect.y = 0xF0;
            rect.w = 0x100;
            rect.h = 4;
            for (i = 0, row = 0xF0; i < 8; i += 4, row += 4) {
                rect.y = row;
                while (func_80082324(3) != 0) {
                }
                while (func_80081ED4(&rect, (u32 *)pix) != 0) {
                }
                while (func_80082324(3) != 0) {
                }
                cp = pix;
                for (k = 0; k < 0x400; k++, cp++) {
                    if (*cp != 0) {
                        *cp |= 0x8000;
                    }
                }
                rect.y = row;
                while (func_80082324(3) != 0) {
                }
                while (func_80081DE8(&rect, (u32 *)pix) != 0) {
                }
                while (func_80082324(3) != 0) {
                }
            }
            func_80059700(index, 0);
            slot->field_E13 = 0;
        } else {
            u16 *cp;

            slot->field_E13 = fl - 1;
            prect.x = (index << 8) + slot->field_E13 * 2;
            prect.y = 0xF8;
            prect.w = 2;
            prect.h = 8;
            while (func_80082324(3) != 0) {
            }
            while (func_80081ED4(&prect, (u32 *)pal) != 0) {
            }
            while (func_80082324(3) != 0) {
            }
            for (i = 0, cp = pal; i < 0x10; i++, cp++) {
                *cp = func_8005AE68(*cp, 6, 0x1000) & 0x7FFF;
            }
            prect.y = 0xF0;
            while (func_80082324(3) != 0) {
            }
            while (func_80081DE8(&prect, (u32 *)pal) != 0) {
            }
            while (func_80082324(3) != 0) {
            }
            if (slot->field_E13 == 0) {
                ModelSlot *s;
                ModelSlotHeadEntry *se;
                u8 *list;
                u8 *next;
                s32 (*fn)(s32);

                s = &D_800F2C40[index];
                se = s->field_000;
                fn = func_8005FE44;
                if (s->field_E1F != 0) {
                    for (i = 0; i < s->field_E1A; i++, se++) {
                        list = se->field_04;
                        if (list != 0) {
                            for (;;) {
                                if ((*(s32 *)((u8 *)( list ) + (  8 )))  != 0) {
                                    func_8005A53C(fn, (ModelHandlerRunEntry *)(list + 0xC),
                                                  (*(s32 *)((u8 *)( list ) + (  4 ))) , (*(s32 *)((u8 *)( list ) + (  8 ))) );
                                }
                                next = (u8 *)(*(s32 *)((u8 *)( list ) + (  0 ))) ;
                                if (next == (u8 *)-1) {
                                    break;
                                }
                                list = next;
                            }
                        }
                    }
                }
                slot->field_E13 = 0xFE;
            }
        }
    }
    if (index < 2) {
        ot->length = 0xC;
    }
}
