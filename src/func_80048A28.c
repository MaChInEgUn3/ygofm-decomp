/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/sound_voice_data.c, profile gcc_2_8_1_g0.
 * The declarations above the function are the subset of that tree's headers
 * this unit needs, preprocessed and with symbols renamed to this tree's
 * spelling (func_ADDR, D_ADDR); their types are that tree's. Byte-identical
 * under the flag row in tools_src/build.py. */
#include "kg_types.h"
#include "kg_variables.h"
#include "kg_functions.h"
extern void func_80077C50 (int vNum, short *envx);
extern SDValue *D_8009B45C;
void func_80044E90(s32 pan);
void func_80047864(s32 index);
void func_80048A28(s32 arg0, s32 arg1, s32 arg2);
void func_80048A28(id, value, word)
    u16 id;
    u8 value;
    u16 word;
{
    s32 i;
    s32 pan;
    s32 right;
    s32 left;
    s32 leftOk;
    s32 lo;
    s32 hi;
    s32 ff;

    if (id & 0x8000) {
        D_8009B45C->cd_volume = value;
        func_80044E90((s16)word);
        return;
    }
    if ((id & 0xF000 ) == 0x4000 ) {
        SDValue *a = D_8009B45C;
        u16 v;

        lo = (id & (32  - 1) ) << 1;
        hi = id & 0x100 ;
        hi = (hi != 0) << 6 ;
        v = *(u16 *)((u8 *)a + (lo + hi) + 0x44C );
        ff = 0xFFFF ;
        if (v == ff) {
            return;
        }
        id = a->field_043C[v];
        if (id == ff) {
            return;
        }
    }
    i = 0;
    leftOk = (u16)(word - 1) < 0x80;
    pan = (s16)word;
    left = 0x80 - pan;
    right = pan + 0x80;
loop:
    {
        s16 local;
        SDValue *b;
        u16 vid;

        func_80077C50(i + 20  , &local);
        b = D_8009B45C;
        vid = b->voice_ids[i];
        if (vid == (id & 0xFFFF) && local != 0) {
            do {
                b->voice_value[i] = value;
            } while (0);
            if (pan != 0) {
                if (leftOk) {
                    SDValue *c = D_8009B45C;
                    s32 v;

                    v = c->field_0444[vid].volume;
                    v *= left;
                    c->voice_volume_left[i] = v;
                }
                if ((u16)(word + 0x80) < 0x80) {
                    SDValue *d = D_8009B45C;
                    s32 v;

                    v = d->field_0444[vid].volume;
                    v *= right;
                    d->voice_volume_right[i] = v;
                }
            }
            func_80047864(i);
        }
    }
    if (++i < 4 ) {
        goto loop;
    }
}
