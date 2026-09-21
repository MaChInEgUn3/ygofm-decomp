/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/func_80052D2C.c, profile gcc_2_8_1_g8_split.
 * The declarations above the function are the subset of that tree's headers
 * this unit needs, preprocessed and with symbols renamed to this tree's
 * spelling (func_ADDR, D_ADDR); their types are that tree's. Byte-identical
 * under the flag row in tools_src/build.py. */
#include "kg_types.h"
#include "kg_variables.h"
#include "kg_functions.h"
void func_80052D2C(s32 arg0, s32 arg1, s32 arg2, s32 arg3)
{
    SVECTOR a;
    SVECTOR b;
    SVECTOR t;
    s32 index;
    s32 state;
    s32 flags;

    func_8008E3D0(&b, 0, 8);
    b.vx = D_800F56F0.vpx;
    b.vy = D_800F56F0.vpy;
    b.vz = D_800F56F0.vpz;
    a = b;
    func_8008E3D0(&t, 0, 8);
    t.vx = D_800F56F0.vrx;
    t.vy = D_800F56F0.vry;
    t.vz = D_800F56F0.vrz;
    b = t;
    state = func_8005F174();
    if (state == 1) {
        if (func_8005F18C() == state) {
            return;
        }
    }
    if (arg1 != 0 || arg0 <= 0) {
        if (arg1 > 0) {
            index = arg1 - 1;
            arg1 = (s32)((u8 *)( D_800F3A10 ) + (  index ) * 0xE20 ) ;
            if (arg3 >= 0) {
                D_800F2B20.eye.pair_slot = index ^ 1;
            } else {
                D_800F2B20.eye.pair_slot = -1;
            }
            D_800F2B20.eye.slot = index;
        } else {
            ModelCameraMove *p = &D_800F2B20;

            p->eye.slot = -1;
            p->eye.pair_slot = -1;
        }
    }
    if (arg2 != 0 || arg0 <= 0) {
        if (arg2 > 0) {
            index = arg2 - 1;
            arg2 = (s32)((u8 *)( D_800F3A10 ) + (  index ) * 0xE20 ) ;
            if (arg3 >= 0) {
                D_800F2B20.target.pair_slot = index ^ 1;
            } else {
                D_800F2B20.target.pair_slot = -1;
            }
            D_800F2B20.target.slot = index;
        } else {
            ModelCameraMove *p = &D_800F2B20;

            p->target.slot = -1;
            p->target.pair_slot = -1;
        }
        if (arg0 < 0) {
            goto have_flags;
        }
    }
    D_800F2B20.mode = arg0;
have_flags:
    {
        ModelCameraMove *p = &D_800F2B20;

        p->field_02 = 0x12C ;
        p->field_06 = 8;
        p->field_04 = 8;
        p->flags = 0;
        if (arg1 != 0) {
            p->flags = 1;
        } else {
            arg1 = (s32)&a;
        }
    }
    if (arg2 != 0) {
        ModelCameraMove *p = &D_800F2B20;

        p->flags = p->flags | 2;
    } else {
        arg2 = (s32)&b;
    }
    {
        ModelCameraMove *p = &D_800F2B20;

        p->eye.start_x = a.vx;
        p->eye.start_y = a.vy;
        p->eye.start_z = a.vz;
         

        p->eye.end_x = ((SVECTOR *)( arg1 )) ->vx;
        p->eye.end_y = ((SVECTOR *)( arg1 )) ->vy;
        p->eye.end_z = ((SVECTOR *)( arg1 )) ->vz;
        p->target.start_x = b.vx;
        p->target.start_y = b.vy;
        p->target.start_z = b.vz;
        p->target.end_x = ((SVECTOR *)( arg2 )) ->vx;
        p->target.end_y = ((SVECTOR *)( arg2 )) ->vy;
        p->target.end_z = ((SVECTOR *)( arg2 )) ->vz;
        arg3 = (arg3 < 0 ? -arg3 : arg3) * 2;
        if (arg3 > 0xFFFE) {
            p->duration = 0xFFFF;
        } else {
            p->duration = arg3;
        }
    }
    {
        ModelCameraMove *p = &D_800F2B20;

        flags = p->flags;
        p->elapsed = 0;
        if (flags != 0) {
            D_8009AF98 = 0;
        }
        if (arg3 != 0) {
            return;
        }
        if (flags & 1) {
            D_800F56F0.vpx = p->eye.end_x;
            D_800F56F0.vpy = p->eye.end_y;
            D_800F56F0.vpz = p->eye.end_z;
        }
        if (p->flags & 2) {
            D_800F56F0.vrx = p->target.end_x;
            D_800F56F0.vry = p->target.end_y;
            D_800F56F0.vrz = p->target.end_z;
        }
        if (p->flags & 3) {
            func_80057F38(0);
        }
        p->flags = 0;
    }
}
