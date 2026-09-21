/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/func_800556E8.c, profile gcc_2_8_1_g8_split.
 * The declarations above the function are the subset of that tree's headers
 * this unit needs, preprocessed and with symbols renamed to this tree's
 * spelling (func_ADDR, D_ADDR); their types are that tree's. Byte-identical
 * under the flag row in tools_src/build.py. */
#include "kg_types.h"
#include "kg_variables.h"
#include "kg_functions.h"
extern ModelSlot D_800F2C40[3 ];
void func_8004DC38(ModelSlot *slot, s32 i, s32 n, u32 pos);
void func_8005106C(s32 index);
s32 func_80058E1C(void);
void func_80059700(s32 index, s32 sign);
void func_8005F714(s32 first, s32 second, s32 arg);
void func_800556E8(s32 index) {
    ModelSlot *m;
    s32 anim;
    s32 length;
    s32 speed;
    s32 i;
    s32 frame;
    s32 lim;

    m = &D_800F2C40[index];
    if (m->field_E1F == 0) {
        return;
    }
    if (m->field_DD8 != 0) {
        anim = m->field_BF5;
        length = m->field_750[anim].max << 4;
        speed = m->field_E0D * func_80058E1C();
        if (anim == 6) {
            lim = length - speed;
            if ((m->field_E16 == 0x3E && m->field_E06 >= lim) ||
                (m->field_E16 == 0x3C && m->field_E06 < 2)) {
                func_80059700(index, 0);
            }
        }
        if (index < 2) {
            func_8005106C(index);
        }
        if (m->field_E16 != 0x23) {
            if (m->field_E16 == 0x3E) {
                s32 v;

                if (m->field_E06 >= length) {
                    m->field_E06 = 0;
                }
                v = m->field_E06 + speed;
                if (v >= length) {
                    m->field_E06 = length;
                } else {
                    m->field_E06 = v;
                }
            } else {
                s32 w;

                if (m->field_E06 == 0) {
                    m->field_E06 = length;
                }
                w = m->field_E06 - speed;
                if (w <= 0) {
                    m->field_E06 = 0;
                } else {
                    m->field_E06 = w;
                }
            }
        }
        if (m->field_E10 == 0) {
            if (m->field_E16 == 0x3E ? m->field_E06 >= length : m->field_E06 == 0) {
                if (m->field_DC0[7] == 6) {
                    m->field_BF4 = 2;
                }
                if (m->field_BF4 != m->field_BF6) {
                    func_800597C8(index, m->field_BF4, 0);
                    m->field_BF6 = m->field_BF4;
                    if (m->field_E0F != 0) {
                        func_80057AF4(index, 0, 0);
                    }
                    if (m->field_DC0[7] == 6) {
                        func_8005F714(-1, index + 2, m->field_750[2].max);
                        m->field_DC0[7] = 0;
                        m->field_BF4 = 1;
                    }
                }
            }
        }
    }
    if (m->field_E16 != 0x23) {
        if (m->field_E0D == 0x10) {
            if (func_80058E1C() == 2) {
                return;
            }
        }
    }
    frame = m->field_E06;
    if (m->field_E1B != 0) {
        i = 0;
        do {
            func_8004DC38(m, i, m->field_BF5, frame);
            i++;
        } while (i < m->field_E1B);
    }
}
