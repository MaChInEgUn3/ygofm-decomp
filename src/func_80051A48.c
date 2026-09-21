/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/func_80051A48.c, profile gcc_2_8_1_g8_split.
 * The declarations above the function are the subset of that tree's headers
 * this unit needs, preprocessed and with symbols renamed to this tree's
 * spelling (func_ADDR, D_ADDR); their types are that tree's. Byte-identical
 * under the flag row in tools_src/build.py. */
#include "kg_types.h"
#include "kg_variables.h"
#include "kg_functions.h"
void func_80051A48(void)
{
    s32 eye_slots[2] = {D_800F2B20.eye.pair_slot, D_800F2B20.eye.slot};
    s32 target_slots[2] = {D_800F2B20.target.pair_slot, D_800F2B20.target.slot};
    s32 rate;
    s32 progress;
    Key *key;

    if (func_8005FB08() && D_800F2B20.flags) {
        if (D_800F2B20.duration <= 0xFFFE) {
            s32 next_elapsed;

            rate = func_80058E1C();
            if (D_800F2B20.elapsed < (u16)(D_800F2B20.duration / 5u) ||
                D_800F2B20.elapsed > 4 * D_800F2B20.duration / 5) {
                rate /= 2;
                if (rate < 2)
                    rate = 2;
            }
            next_elapsed = D_800F2B20.elapsed + rate;
            D_800F2B20.elapsed = next_elapsed < D_800F2B20.duration ?
                next_elapsed : D_800F2B20.duration;
        }
        if (eye_slots[0] >= 0) {
            ModelSlot *base = D_800F2C40;
            ModelSlot *slot;
            s32 dx;
            s32 dy;

            slot = base + eye_slots[0];
            dx = (s16)slot->field_DD0[0] - D_800F2B20.eye.start_x;
            dy = (s16)slot->field_DD0[1] - D_800F2B20.eye.start_y;
            D_800F2B20.eye.start_x = D_800F2B20.eye.start_x +
                (dx > 0 ? (dx < 31 ? dx : 30) :
                (dx >= -30 ? dx : -30));
            D_800F2B20.eye.start_y = D_800F2B20.eye.start_y +
                (dy > 0 ? (dy < 31 ? dy : 30) :
                (dy >= -30 ? dy : -30));
        }
        if (eye_slots[1] >= 0) {
            ModelSlot *base = D_800F2C40;
            ModelSlot *slot;
            s32 dx;
            s32 dy;
            s32 dz;

            slot = base + eye_slots[1];
            dx = (s16)slot->field_DD0[0] - D_800F2B20.eye.end_x;
            dy = (s16)slot->field_DD0[1] - D_800F2B20.eye.end_y;
            dz = (s16)slot->field_DD0[2] - D_800F2B20.eye.end_z;
            D_800F2B20.eye.end_x = D_800F2B20.eye.end_x +
                (dx > 0 ? (dx < 31 ? dx : 30) :
                (dx >= -30 ? dx : -30));
            D_800F2B20.eye.end_y = D_800F2B20.eye.end_y +
                (dy > 0 ? (dy < 31 ? dy : 30) :
                (dy >= -30 ? dy : -30));
            D_800F2B20.eye.end_z = D_800F2B20.eye.end_z +
                (dz > 0 ? (dz < 31 ? dz : 30) :
                (dz >= -30 ? dz : -30));
        }
        if (target_slots[0] >= 0) {
            ModelSlot *base = D_800F2C40;
            ModelSlot *slot;
            s32 dx;
            s32 dy;

            slot = base + target_slots[0];
            dx = (s16)slot->field_DD0[0] - D_800F2B20.target.start_x;
            dy = (s16)slot->field_DD0[1] - D_800F2B20.target.start_y;
            D_800F2B20.target.start_x = D_800F2B20.target.start_x +
                (dx > 0 ? (dx < 31 ? dx : 30) :
                (dx >= -30 ? dx : -30));
            D_800F2B20.target.start_y = D_800F2B20.target.start_y +
                (dy > 0 ? (dy < 31 ? dy : 30) :
                (dy >= -30 ? dy : -30));
        }
        if (target_slots[1] >= 0) {
            ModelSlot *base = D_800F2C40;
            ModelSlot *slot;
            s32 dx;
            s32 dy;
            s32 dz;

            slot = base + target_slots[1];
            dx = (s16)slot->field_DD0[0] - D_800F2B20.target.end_x;
            dy = (s16)slot->field_DD0[1] - D_800F2B20.target.end_y;
            dz = (s16)slot->field_DD0[2] - D_800F2B20.target.end_z;
            D_800F2B20.target.end_x = D_800F2B20.target.end_x +
                (dx > 0 ? (dx < 31 ? dx : 30) :
                (dx >= -30 ? dx : -30));
            D_800F2B20.target.end_y = D_800F2B20.target.end_y +
                (dy > 0 ? (dy < 31 ? dy : 30) :
                (dy >= -30 ? dy : -30));
            D_800F2B20.target.end_z = D_800F2B20.target.end_z +
                (dz > 0 ? (dz < 31 ? dz : 30) :
                (dz >= -30 ? dz : -30));
        }
        if (D_800F2B20.flags & 1) {
            D_800F56F0.vpx = (D_800F2B20.eye.end_x - D_800F2B20.eye.start_x) *
                D_800F2B20.elapsed / D_800F2B20.duration + D_800F2B20.eye.start_x;
            D_800F56F0.vpy = (D_800F2B20.eye.end_y - D_800F2B20.eye.start_y) *
                D_800F2B20.elapsed / D_800F2B20.duration + D_800F2B20.eye.start_y;
            D_800F56F0.vpz = (D_800F2B20.eye.end_z - D_800F2B20.eye.start_z) *
                D_800F2B20.elapsed / D_800F2B20.duration + D_800F2B20.eye.start_z;
            if (D_800F56F0.vpy >= -100)
                D_800F56F0.vpy = -100;
        } else if (D_800F2B20.mode) {
            rate = func_80058E1C();
            func_80058434(1, D_800F2B20.field_04 * rate * D_8009AF99, 0, 0, 0);
        }
        if (D_800F2B20.flags & 2) {
            D_800F56F0.vrx = (D_800F2B20.target.end_x - D_800F2B20.target.start_x) *
                D_800F2B20.elapsed / D_800F2B20.duration + D_800F2B20.target.start_x;
            D_800F56F0.vry = (D_800F2B20.target.end_y - D_800F2B20.target.start_y) *
                D_800F2B20.elapsed / D_800F2B20.duration + D_800F2B20.target.start_y;
            D_800F56F0.vrz = (D_800F2B20.target.end_z - D_800F2B20.target.start_z) *
                D_800F2B20.elapsed / D_800F2B20.duration + D_800F2B20.target.start_z;
            if (D_800F56F0.vry >= -100)
                D_800F56F0.vry = -100;
        }
        func_80057F38(0);
        func_80052694(1);
        if (D_800F2B20.elapsed >= D_800F2B20.duration)
            func_80059EBC(1);
        return;
    }
    if (!D_800F2B20.mode)
        return;
    key = (Key *)func_8005FB14();
    if (eye_slots[1] >= 0) {
        ModelSlot *base = D_800F2C40;
        ModelSlot *slot;
        s32 dx;
        s32 dy;
        s32 dz;

        slot = base + eye_slots[1];
        dx = (s16)slot->field_DD0[0] - D_800F56F0.vpx;
        dy = (s16)slot->field_DD0[1] - D_800F56F0.vpy;
        dz = (s16)slot->field_DD0[2] - D_800F56F0.vpz;
        D_800F56F0.vpx = D_800F56F0.vpx +
            (dx > 0 ? (dx < 31 ? dx : 30) :
            (dx >= -30 ? dx : -30));
        D_800F56F0.vpy = D_800F56F0.vpy +
            (dy > 0 ? (dy < 31 ? dy : 30) :
            (dy >= -30 ? dy : -30));
        D_800F56F0.vpz = D_800F56F0.vpz +
            (dz > 0 ? (dz < 31 ? dz : 30) :
            (dz >= -30 ? dz : -30));
        if (D_800F56F0.vpy >= -100)
            D_800F56F0.vpy = -100;
    }
    if (target_slots[1] >= 0) {
        ModelSlot *base = D_800F2C40;
        ModelSlot *slot;
        s32 dx;
        s32 dy;
        s32 dz;

        slot = base + target_slots[1];
        dx = (s16)slot->field_DD0[0] - D_800F56F0.vrx;
        dy = (s16)slot->field_DD0[1] - D_800F56F0.vry;
        dz = (s16)slot->field_DD0[2] - D_800F56F0.vrz;
        D_800F56F0.vrx = D_800F56F0.vrx +
            (dx > 0 ? (dx < 31 ? dx : 30) :
            (dx >= -30 ? dx : -30));
        D_800F56F0.vry = D_800F56F0.vry +
            (dy > 0 ? (dy < 31 ? dy : 30) :
            (dy >= -30 ? dy : -30));
        D_800F56F0.vrz = D_800F56F0.vrz +
            (dz > 0 ? (dz < 31 ? dz : 30) :
            (dz >= -30 ? dz : -30));
        if (D_800F56F0.vry >= -100)
            D_800F56F0.vry = -100;
    }
    if (!key || (key->requested[0].kind != 4 && key->requested[1].kind != 4)) {
        rate = func_80058E1C();
        func_80058434(1, D_800F2B20.field_04 * rate * D_8009AF99, 0, 0, 0);
        func_80052694(1);
    }
    if (D_800F2B20.field_02) {
        ModelCameraMove *move = &D_800F2B20;
        s32 step;

        step = func_80058E1C();
        if (move->field_02 - step > 0) {
            step = func_80058E1C();
            progress = move->field_02 - step;
        } else {
            progress = 0;
        }
        move->field_02 = progress;
    }
}
