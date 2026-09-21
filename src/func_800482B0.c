/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/func_800482B0.c, profile gcc_2_8_1_g8_split.
 * The declarations above the function are the subset of that tree's headers
 * this unit needs, preprocessed and with symbols renamed to this tree's
 * spelling (func_ADDR, D_ADDR); their types are that tree's. Byte-identical
 * under the flag row in tools_src/build.py. */
#include "kg_types.h"
#include "kg_variables.h"
#include "kg_functions.h"
extern SDValue *D_8009B45C __attribute__((section(".data")));
void func_800482B0(s32 id, s16 pitch, u8 volume, s16 pan, u32 mode, u8 value)
{
    u16 sound_id = id;
    u8 slot;
    u8 count;
    u8 found;
    s32 index;
    s32 mask;
    s32 observed;
    u8 occurrence;
    s16 envelope;
    s16 mode_snapshot;

    mode_snapshot = mode;
    if (D_8009B45C->field_043C[(u16)sound_id] == 0xFFFF) {
        return;
    }
    if ((id & 0x8000) != 0) {
        func_800451E0(sound_id, 0);
        return;
    }

    found = 0;
    if ((mode & 0xF) != 0) {
        mask = func_80047F38(mode & 0xF);
        if (mask != 0) {
            slot = 0;
            do {
                if (mask & 1) {
                    D_8009B45C->field_0435 = slot;
                    func_8004803C(sound_id, D_8009B45C->field_0435, pitch, volume,
                                  pan, mode_snapshot, value);
                    return;
                }
                slot++;
                mask >>= 1;
            } while (slot < 4 );
        }
    }

    if (((u16)mode_snapshot & 0xF0) != 0) {
        slot = 0;
        count = 0;
        occurrence = ((u16)mode_snapshot & 0xF0) >> 4;
        for (index = 0; index < 4 ; index++, slot++) {
            func_80077C50(
                index + 20  , &envelope
            );
             
            observed = envelope;
            if (observed != 0) {
                observed = (u16)sound_id;
                if (D_8009B45C->voice_ids[slot] == observed) {
                    count++;
                    if (count == occurrence) {
                        D_8009B45C->field_0435 = slot;
                        func_8004803C(sound_id, D_8009B45C->field_0435, pitch, volume,
                                      pan, mode_snapshot, value);
                        return;
                    }
                }
            }
        }
    }

    mask = 1 << D_8009B45C->field_0435;
    if (found == 0) {
        index = 0;
        do {
            func_80077C50(
                D_8009B45C->field_0435 + 20  , &envelope
            );
            if (envelope == 0) {
                found = 1;
                func_8004803C(sound_id, D_8009B45C->field_0435, pitch, volume, pan,
                              mode_snapshot, value);
            }
            mask <<= 1;
            if ((mask & 0x10) != 0) {
                mask = 1;
            }
            D_8009B45C->field_0435 = D_8009B45C->field_0435 + 1;
            D_8009B45C->field_0435 = D_8009B45C->field_0435 & 3;
            index++;
        } while (index < 4  && found == 0);
    }

    if (found == 0) {
        index = 0;
        mask = 1 << D_8009B45C->field_0435;
        do {
            if (value >= D_8009B45C->field_040C[D_8009B45C->field_0435]) {
                found = 1;
                func_8004803C(sound_id, D_8009B45C->field_0435, pitch, volume, pan,
                              mode_snapshot, value);
            }
            mask <<= 1;
            if ((mask & 0x10) != 0) {
                mask = 1;
            }
            D_8009B45C->field_0435 = D_8009B45C->field_0435 + 1;
            D_8009B45C->field_0435 = D_8009B45C->field_0435 & 3;
            index++;
        } while (index < 4  && found == 0);
    }
}
