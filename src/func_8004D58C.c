/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/model_slot_row_tables.c, profile gcc_2_8_1_g0.
 * The declarations above the function are the subset of that tree's headers
 * this unit needs, preprocessed and with symbols renamed to this tree's
 * spelling (func_ADDR, D_ADDR); their types are that tree's. Byte-identical
 * under the flag row in tools_src/build.py. */
#include "kg_types.h"
#include "kg_variables.h"
#include "kg_functions.h"
extern ModelSlot D_800F2C40[3 ];
void func_8004D58C(s32 slot, u8 *commands);
void func_8004D58C(s32 arg0, u8 *arg1)
{
    ModelSlot *ch;
    u8 *t;
    u8 *c;
    u8 *q;
    u8 *e;
    u8 *p3;
    u8 *p2;
    u8 *g;
    u8 *k;
    u8 *s;
    u8 *u;
    u8 *v;
    s32 ff;
    s32 one;
    s32 i;
    s32 j;
    s32 n;
    s32 m;
    s32 a;
    s32 b;
    s32 w;
    s32 d;
    s32 x;
    s32 y;
    s32 flag;
    s32 qd;

    do {
        do {
            p3 = (u8 *)0;
        } while (0);
    } while (0);
    p2 = (u8 *)0;
    i = 0;
    ff = 0xFFFF;
    n = 0;
    m = 0;
    ch = &D_800F2C40[arg0];
    t = (u8 *)ch;
    c = t;
    ch->field_E06 = 0;
    ch->field_E08 = 0;
    ch->field_DD8 = 0;
    *(s32 *)&ch->field_DDC = 0;
    *(s32 *)&ch->field_DE0 = 0;
    *(s32 *)&ch->field_DE4 = 0;
    ch->field_DF0 = 0;
     











    do {
        ((ModelSlotRow *)(c + (u32)&((ModelSlot *)0)->field_750))->max = 0;
        j = 0;
        a = n;
        b = m;
        do {
            u = t + a;
            a += 2;
            v = t + b;
            b += 2;
            j++;
            *(u16 *)(v + (u32)&((ModelSlot *)0)->field_2C8) = ff;
            *(s16 *)(u + (u32)&((ModelSlot *)0)->field_750) = 0;
        } while (j < 0x3A);
        n += sizeof(ModelSlotRow);
        m += 0x74;
        i++;
        c += sizeof(ModelSlotRow);
    } while (i < 0xA);
    i = 7;
    q = t + i;
    do {
        q[(u32)&((ModelSlot *)0)->field_BEC] = 0;
        i--;
        q--;
    } while (i >= 0);
    e = *(u8 **)(arg1 + 0x10);
    if (e == (u8 *)0) {
        return;
    }
    do {
        if (*(s32 *)(e + 8) != 0) {
            w = e[0xF];
            if (w == 3) {
                p3 = *(u8 **)(e + 4);
            }
            if (w == 2) {
                p2 = *(u8 **)(e + 4);
            }
        }
        e = *(u8 **)e;
    } while (e != (u8 *)-1);
    if (p3 != (u8 *)0) {
        p3 += 8;
        k = *(u8 **)p3;
        p3 += 4;
        i = 0;
        if (*(u16 *)k != 0) {
            one = 1;
            g = k;
            do {
                do {
                    do {
                        qd = i / 8;
                    } while (0);
                } while (0);
                s = t + qd;
                d = qd << 3;
                y = s[(u32)&((ModelSlot *)0)->field_BEC];
                flag = *(volatile s32 *)(g + 4) & 0x100;
                if (flag != 0) {
                    x = y | (one << (i - d));
                } else {
                    x = y;
                }
                s[(u32)&((ModelSlot *)0)->field_BEC] = x;
                g += 4;
                i++;
            } while ((u32)i < *(u16 *)k);
        }
        *(s32 *)(t + (u32)&((ModelSlot *)0)->field_DD8) = *(s32 *)p3;
        *(s32 *)(t + (u32)&((ModelSlot *)0)->field_DDC) = *(s32 *)(p3 + 4);
    }
    if (p2 != (u8 *)0) {
        p2 += 4;
        *(s32 *)(t + (u32)&((ModelSlot *)0)->field_DE0) = *(s32 *)p2;
        *(s32 *)(t + (u32)&((ModelSlot *)0)->field_DE4) = *(s32 *)(p2 + 4);
    }
}
