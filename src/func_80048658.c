/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/sound_effect_request.c (SD_SEPlay), profile gcc_2_8_1_g0.
 * The declarations above the function are the subset of that tree's headers
 * this unit needs, preprocessed and with symbols renamed to this tree's
 * spelling (func_ADDR, D_ADDR); their types are that tree's. Byte-identical
 * under the flag row in tools_src/build.py. */
#include "kg_types.h"
s16 func_800451E0(u16 value, s32 unused);
extern SDValue *D_8009B45C;
void func_80048658(s32 id, s32 volume, s32 pan);
void func_800482B0(s32 id, s16 pitch, u8 volume, s16 pan, u32 mode, u8 value);
void func_80048658(s32 arg0, s32 arg1, s32 arg2)
{
    SDSEPlayIdPair tags;
    s32 vol;
    s32 pan;
    u8 last_arg;
    u16 stop_value;
    s32 lo;
    s32 hi;
    s32 n;
    u8 *e;
    s32 t2;

     

    if (arg0 & 0x8000) {
        tags.words.original = arg0;
        pan = arg2;
        arg0 = arg1;
        tags.words.copy = tags.words.original;
        vol = arg0;
        stop_value = tags.words.original;
    } else {
        tags.words.original = arg0;
        pan = arg2;
        arg0 = arg1;
        tags.words.copy = tags.words.original;
        vol = arg0;
        stop_value = tags.words.original;
    }
    if (tags.words.original & 0x8000) {
        func_800451E0(stop_value & 0xFFFF, 0);
        return;
    }
    if ((tags.words.original & 0xF000) == 0x4000) {
        SDValue *a = D_8009B45C;
        u8 *table;
        u16 v;
        s32 n;

        lo = (tags.words.original & 0x1F) << 1;
        t2 = tags.words.original & 0x100;
        hi = t2;
        hi = (hi != 0) << 6;

        table = (u8 *)&a->field_044C;
        v = *(u16 *)(table + (lo + hi));
        if (v == 0xFFFF) {
            return;
        }
        n = a->field_043C[v];
        if (n == 0xFFFF) {
            return;
        }
        e = (u8 *)(n * 8 + (u32)a->field_0444);
        t2 = e[2];
        last_arg = t2;
        vol &= 0xFF;
        func_800482B0(v, 0, vol, (s16)pan, e[3], last_arg & 0xFF);
    } else {
        SDValue *b = D_8009B45C;

        n = b->field_043C[tags.words.copy & 0xFFFF];
        if (n == 0xFFFF) {
            return;
        }
        e = (u8 *)(n * 8 + (u32)b->field_0444);
        t2 = e[2];
        last_arg = t2;
        vol &= 0xFF;
        func_800482B0(tags.words.copy & 0xFFFF, 0, vol, (s16)pan, e[3], last_arg & 0xFF);
    }
}
