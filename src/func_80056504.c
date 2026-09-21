/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/model_load_monster_merge.c (Model_LoadMonsterMerge), profile gcc_2_8_1_g8_split.
 * The declarations above the function are the subset of that tree's headers
 * this unit needs, preprocessed and with symbols renamed to this tree's
 * spelling (func_ADDR, D_ADDR); their types are that tree's. Byte-identical
 * under the flag row in tools_src/build.py. */
#include "kg_types.h"
#include "kg_variables.h"
#include "kg_functions.h"
s32 func_80056504(s32 slot, s32 model, s32 p2, s32 p3, s32 p4,
                           s32 p5, s32 arg6)
{
    FileTransferDescriptor *transfer;
    s32 flags;
    s32 result;

    result = 0;
    flags = slot & 0x80;
    slot &= 0x7F;
    if (model < 0) {
        model = D_800F2C40[slot].field_DF8;
    } else {
        D_800F2C40[slot].field_DF8 = model;
    }
    if (flags == 0) {
        func_80047EC4();
    }
    func_800137E4();
    func_8004CB0C(slot, 0, 0, arg6);
    D_800F2C40[slot].field_E1D = flags;
    if (slot < 2) {
        if (model == 0x309 ) {
            transfer = func_80014EEC(
                1, D_800114F8, 0x3B4 ,
                0x113 ,
                func_800577B0, 0, 0
            );
            D_8009B0F4_abs = transfer->status_flags
                | 0x10 ;
            D_800F2C40[slot].field_E14 = 0;
            return 0;
        }
        if (model < 0 || model >= 0x2D2 
            || (model >= 0x12C 
                && model < 0x15E )
            || (model >= 0x28A 
                && model < 0x2BC )
            || model == 0x2D0 ) {
            result++;
        } else {
            if (model >= (0x2D2  - 1) ) {
                model--;
            }
            if (model >= 0x2BC ) {
                model -= (0x15E  - 0x12C ) ;
            }
            if (model >= 0x15E ) {
                model -= (0x15E  - 0x12C ) ;
            }
            transfer = func_80014EEC(
                2, D_80011580, model * 0x114 ,
                0x114 , func_80056D7C,
                0, 0
            );
            if (p2 >= 0) {
                D_800F2C40[slot].field_DFA = p2;
            }
            if (p3 >= 0) {
                D_800F2C40[slot].field_DFC = p3;
            }
            if (p4 >= 0) {
                D_800F2C40[slot].field_DFE = p4 != 0;
            }
            if (p5 >= 0) {
                D_800F2C40[slot].field_DFF = p5 != 0;
            }
            transfer->callback_data = (void *)slot;
            transfer->position = D_800F2C40[slot].field_DFE;
            D_8009B0F4_abs = transfer->status_flags
                | 0x10 ;
            D_800F2C40[slot].field_E14 = 0;
        }
    } else {
        if (model >= 0 && model < 7) {
            model = D_80091008[
                model * 0xB2 
                + 0xA0 ];
            if (model >= 0 && model < 7) {
                goto found;
            }
        }
        result++;
        goto done;
found:
        transfer = func_80014EEC(
            1, D_800114F8,
            model * 0x74  + 0x88 ,
            0x74 , func_80057544, 0, 0
        );
        D_8009B0F4_abs = transfer->status_flags
            | 0x10 ;
        D_800F2C40[slot].field_E14 = 0;
    }
done:
    return result;
}
