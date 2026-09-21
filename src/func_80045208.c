/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/sound_output_state.c, profile gcc_2_8_1_g0.
 * The declarations above the function are the subset of that tree's headers
 * this unit needs, preprocessed and with symbols renamed to this tree's
 * spelling (func_ADDR, D_ADDR); their types are that tree's. Byte-identical
 * under the flag row in tools_src/build.py. */
#include "kg_types.h"
#include "kg_variables.h"
#include "kg_functions.h"
extern SDValue *D_8009B45C;
s32 func_80045BE8(SDCommand *);
void func_800464F0(void);
s32 func_80045208(u16 code, s32 unused);
void func_80044DA0(void);
s32 func_80045208(u16 arg0, s32 unused)
{
    SDValue *a = D_8009B45C;
    u16 code = arg0;
    u8 **table;
    s32 kind;
    u8 *second;
    SDCommand req;

    if (a->flags_004A & 0x80) {
        if ((a->flags_004A & 0x40) || code <= 0x9FFF) {
            if (arg0 & 0x8000) {
                *(s16 *)&a->field_0534 = arg0;
                switch (arg0 & 0xF000) {
                case 0x8000:
                    code = arg0 + 0x8000;
                    table = (u8 **)a->bank_0518[1];
                    second = (u8 *)&table[2];
                    kind = 0x50;
                    break;
                case 0x9000:
                    code = arg0 + 0x7000;
                    table = (u8 **)a->bank_0518[0];
                    second = (u8 *)&table[2];
                    kind = 0x60;
                    break;
                default:
                    code = code + 0x6000;
                    kind = 0x70;
                    table = (u8 **)D_8009B45C->bank_0518[2];
                    second = (u8 *)&table[2];
                    break;
                }
                {
                    s32 first;

                    first = table ? (second ? (s32)*table : (s32)*table) : (s32)*table;

                    func_800464F0();
                    req.command = 0x24;
                    req.field_0002 = code;
                    req.field_0004 = first;
                    req.field_000C = (s32)second;
                    req.field_0008 = kind;
                    func_80045BE8(&req);
                    func_80044DA0();
                }
                D_8009B45C->flags_0040 = (D_8009B45C->flags_0040 | 1) & 0xFFFB;
                return 1;
            }
        }
    }
    return 0;
}
