/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/sound_runtime.c (SD_UpdateFades), profile gcc_2_8_1_g0.
 * The declarations above the function are the subset of that tree's headers
 * this unit needs, preprocessed and with symbols renamed to this tree's
 * spelling (func_ADDR, D_ADDR); their types are that tree's. Byte-identical
 * under the flag row in tools_src/build.py. */
#include "kg_types.h"
void func_80044DC0(s16 a0);
extern SDValue *D_8009B45C;
void func_80045C98(void);
void func_80049F10(s16 left, s16 right);
void func_80045C98(void) {
    u8 changed;
    s16 y;

    changed = 0;
    if (D_8009B45C->field_1588 != 0) {
        D_8009B45C->field_1586 += D_8009B45C->field_1588;
        changed = 1;
        if (D_8009B45C->field_1586 <= D_8009B45C->field_158A &&
            D_8009B45C->field_1588 < 0) {
            D_8009B45C->field_1588 = 0;
            D_8009B45C->field_1586 = D_8009B45C->field_158A;
        }
        if (D_8009B45C->field_1586 >= D_8009B45C->field_158A &&
            D_8009B45C->field_1588 > 0) {
            D_8009B45C->field_1588 = 0;
            D_8009B45C->field_1586 = D_8009B45C->field_158A;
        }
    }
    if (D_8009B45C->field_1582 != 0) {
        D_8009B45C->field_1580 += D_8009B45C->field_1582;
        changed = 1;
        if (D_8009B45C->field_1580 <= D_8009B45C->field_1584 &&
            D_8009B45C->field_1582 < 0) {
            D_8009B45C->field_1582 = 0;
            D_8009B45C->field_1580 = D_8009B45C->field_1584;
        }
        if (D_8009B45C->field_1580 >= D_8009B45C->field_1584 &&
            D_8009B45C->field_1582 > 0) {
            D_8009B45C->field_1582 = 0;
            D_8009B45C->field_1580 = D_8009B45C->field_1584;
        }
    }
    if (changed) {
        u16 v;

        v = D_8009B45C->field_0044;
        if (v) {
            v *= D_8009B45C->field_1580 + 1;
            v >>= 8;
        } else {
            v = 0;
        }
        if (v) {
            v *= D_8009B45C->field_1586 + 1;
            v >>= 8;
        } else {
            v = 0;
        }
        y = v;
        func_80049F10(y, y);
    }
    if (D_8009B45C->field_0512 != 0) {
        D_8009B45C->cd_volume += D_8009B45C->field_0512;
        if (D_8009B45C->cd_volume <= D_8009B45C->field_0049 &&
            D_8009B45C->field_0512 < 0) {
            D_8009B45C->field_0512 = 0;
            D_8009B45C->cd_volume = D_8009B45C->field_0049;
        }
        if (D_8009B45C->cd_volume >= D_8009B45C->field_0049 &&
            D_8009B45C->field_0512 > 0) {
            D_8009B45C->field_0512 = 0;
            D_8009B45C->cd_volume = D_8009B45C->field_0049;
        }
        y = D_8009B45C->cd_volume;
        func_80044DC0(y);
    }
}
