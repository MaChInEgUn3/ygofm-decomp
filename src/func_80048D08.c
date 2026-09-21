/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/sound_voice_data.c (SD_LoadSequenceBankPair), profile gcc_2_8_1_g0.
 * The declarations above the function are the subset of that tree's headers
 * this unit needs, preprocessed and with symbols renamed to this tree's
 * spelling (func_ADDR, D_ADDR); their types are that tree's. Byte-identical
 * under the flag row in tools_src/build.py. */
#include "kg_types.h"
#include "kg_variables.h"
#include "kg_functions.h"
extern SDValue *D_8009B45C;
void func_8004763C(void);
void func_80048C70(u32 *dst, u32 *src);
void func_80048D08(s32 side, u32 *src);
void func_80048D08(s32 side, u32 *src)
{
    SDSeqBlock *blk;
    SDSeqBlock *other;
    SDSeqBlock *cur;
    SDNote *e;
    u32 addr_side;
    u32 addr_other;
    s32 rev;
    s32 i;
    s32 j;

    if ((u32)side >= 2) {
        return;
    }

    rev = 1 - side;
    addr_side = 0xD810 + (side % 2) * 0x19000;
    addr_other = 0xD810 + (rev % 2) * 0x19000;
    blk = (SDSeqBlock *)(0x801E7800 + (side << 11 ));
    other = (SDSeqBlock *)(0x801E7800 + (rev << 11 ));
    func_80048C70((u32 *)blk, src);
    func_8004763C();

    for (i = 0; i < 2; i++) {
        cur = other;
        if (i != 0) {
            cur = blk;
        }
        for (j = 0; j < cur->count; j++) {
            u16 key = cur->keys[j];
            if (key != 0xFFFF ) {
                u16 n = D_8009B45C->field_0440;
                u16 v;

                D_8009B45C->field_043C[key] = n;
                D_8009B45C->field_0444[n] = cur->data[j];
                e = (SDNote *)(
                    (u32)&((SDNote *)0)[n] +
                    (u32)D_8009B45C->field_0444
                );
                v = e->field_0006;
                e->field_0006 =
                    (i != 0) ? (u16)(v + (addr_side >> 4))
                             : (u16)(v + (addr_other >> 4));
                D_8009B45C->field_0440 = D_8009B45C->field_0440 + 1;
            }
            if (i != 0) {
                D_8009B45C->field_044C[side][j] = key;
            }
        }
    }
}
