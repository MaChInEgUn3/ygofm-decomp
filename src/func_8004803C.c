/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/sound_effect_voices.c, profile gcc_2_8_1_g0_no_split.
 * The declarations above the function are the subset of that tree's headers
 * this unit needs, preprocessed and with symbols renamed to this tree's
 * spelling (func_ADDR, D_ADDR); their types are that tree's. Byte-identical
 * under the flag row in tools_src/build.py. */
#include "kg_types.h"
extern void func_80076ED0 (long on_off, unsigned long voice_bit);
extern void func_80077120 (SpuVoiceAttr *attr);
extern SDValue *D_8009B45C;
void func_8004803C(u16 id, u8 voice, s32 pitch_add, u8 volume,
                   s16 pan, u8 flags, u8 value);
void func_8004803C(u16 id, u8 voice, s32 pitch_add, u8 volume, s16 pan, u8 flags, u8 value) {
    u16 idx;

    idx = D_8009B45C->field_043C[id];
    if (idx != 0xFFFF) {
        D_8009B45C->voice_attr.volume.left = ((D_8009B45C->field_0444[idx].volume * volume) >> 1) | 0xFF;
        D_8009B45C->voice_attr.volume.right = ((D_8009B45C->field_0444[idx].volume * volume) >> 1) | 0xFF;
        if (pan != 0) {
            if ((u16)(pan - 1) < 0x80) {
                D_8009B45C->voice_attr.volume.left = D_8009B45C->voice_attr.volume.left * (0x80 - pan) / 128;
            }
            if ((u16)(pan + 0x80) < 0x80) {
                D_8009B45C->voice_attr.volume.right = D_8009B45C->voice_attr.volume.right * (pan + 0x80) / 128;
            }
        }
        D_8009B45C->voice_attr.note = D_8009B45C->field_0444[idx].pitch + pitch_add;
        D_8009B45C->voice_attr.voice = 1 << (voice + 20 );
        D_8009B45C->voice_attr.addr = D_8009B45C->field_0444[idx].field_0006 << 4;
        func_80076ED0(0 , D_8009B45C->voice_attr.voice);
        D_8009B45C->voice_active_mask |= 1 << voice;
        D_8009B45C->field_040C[voice] = value;
        D_8009B45C->voice_flags[voice] = flags;
        D_8009B45C->voice_ids[voice] = id;
        D_8009B45C->voice_volume_left[voice] = D_8009B45C->voice_attr.volume.left;
        D_8009B45C->voice_volume_right[voice] = D_8009B45C->voice_attr.volume.right;
        D_8009B45C->voice_value[voice] = 0xFF;
        D_8009B45C->voice_step[voice] = 0;
        D_8009B45C->voice_timer[voice] = D_8009B45C->field_0444[idx].timer << 2;
        func_80077120(&D_8009B45C->voice_attr);
    }
}
