/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/func_8004DC38.c, profile gcc_2_8_1_g8.
 * The declarations above the function are the subset of that tree's headers
 * this unit needs, preprocessed and with symbols renamed to this tree's
 * spelling (func_ADDR, D_ADDR); their types are that tree's. Byte-identical
 * under the flag row in tools_src/build.py. */
#include "kg_types.h"
#include "kg_variables.h"
#include "kg_functions.h"
void func_8004DC38(ModelSlot *slot, s32 i, s32 n, u32 pos);
void func_8004DC38(ModelSlot *p, s32 i, s32 n, u32 pos) {
    s32 *tbl;
    ModelSlotPart *e;
    s32 *q;
    s32 *cp;
    s32 *v;
    s32 k;
    s32 step;
    s32 rem;
    s32 len;
    s32 idx;
    s32 x;
    s32 y;
    s32 z;
    s32 d;
    s32 off4;
    s32 off2;

     



    off4 = i * 4;
    off2 = i * 2;
    k = p->field_2C8[n][i];
    tbl = p->field_DD8;
    e = p->field_1E0[i];
    q = tbl + k;
    if (e == 0) {
        return;
    }
    if (k == 0xFFFF) {
        return;
    }
     

    if (p->field_750[n].values[i] == 0) {
        return;
    }
    step = p->field_750[n].values[i] * 16;
    rem = pos % step;
    cp = q - 1;
    if (rem == 0) {
        if (pos != 0 && p->field_E16 != 0x3C) {
            rem = step;
        }
    }
     




    idx = 0;
    if (idx >= *(u16 *)cp) {
        return;
    }
    for (; idx < *(u16 *)cp; idx++) {
        if (p->field_E16 != 0x3C) {
            d = rem - (((u8 *)q)[2] << 4);
            if (d <= 0) {
                break;
            }
        } else {
            d = rem - (((u8 *)q)[2] << 4);
            if (d < 0) {
                break;
            }
        }
        rem = rem - (((u8 *)q)[2] << 4);
        if (q[1] < 0) {
            break;
        }
        q++;
    }

    len = *(u16 *)cp;
    if (idx >= len) {
        return;
    }
     


    v = q;
scan:
    if (v[1] >= 0) {
        idx++;
        v++;
        if (idx < len) {
            goto scan;
        }
    }
    x = q - p->field_DD8;
    e->ti = x;
    if (x != 0) {
        x = x - 1;
    } else {
        x = v - p->field_DD8;
    }
    e->ci = x;
    y = ((u8 *)q)[2] << 4;
    z = y - rem;
    e->tframe = y;
    e->rframe = z;
    if (p->field_E16 != 0x3C) {
        return;
    }
    if ((s16)z < e->tframe) {
        return;
    }
    e->rframe = 0x6000;
}
