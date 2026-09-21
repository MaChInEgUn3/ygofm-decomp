/* Ported from krystalgamer/memories-decomp at commit 3dfeb592fcc8,
 * src/game/func_80046294.c, profile gcc_2_8_1_g8_split.
 * The declarations above the function are the subset of that tree's headers
 * this unit needs, preprocessed and with symbols renamed to this tree's
 * spelling (func_ADDR, D_ADDR); their types are that tree's. Byte-identical
 * under the flag row in tools_src/build.py. */
#include "kg_types.h"
#include "kg_variables.h"
#include "kg_functions.h"
extern SDValue *D_8009B45C __attribute__((section(".data")));
void func_80046294(void);
s16 func_80049F50(void);
void func_80049C40(s32 value);
void func_80046294(void)
{
    s32 i;
    s32 offset;
    s32 next_offset;
    s32 command;
    SDValue *base;

    base = D_8009B45C;
     

    do {
        i = 0;
    } while (0);
    if (base->command_count > 0) {
        while (1) {
            offset = i * 0x30 ;
            next_offset = (i + 1) * 0x30 ;
            if (base->command_count == 0) {
                goto after;
            }
            command = base->commands.b[offset];
            switch (command) {
            case 0x42:
            case 0x43:
            case 0x45:
            case 0x46:
            case 0x48:
                *(SDCommand *)(((u8 *)D_8009B45C)  + offset + 0x80 ) =
                    *(SDCommand *)(((u8 *)D_8009B45C)  + next_offset + 0x80 );
                goto decrement;
            case 0x20:
                 

                if (*(s32 *)(((u8 *)D_8009B45C)  + offset +
                        0x80  +
                        (u32)&((SDCommand *)0)->field_0010) != 0x20) {
                    goto test;
                }
                *(SDCommand *)(((u8 *)D_8009B45C)  + offset + 0x80 ) =
                    *(SDCommand *)(((u8 *)D_8009B45C)  + next_offset + 0x80 );
decrement:
                D_8009B45C->command_count = D_8009B45C->command_count - 1;
                goto test;
            default:
                i++;
            }
test:
            base = D_8009B45C;
            if (i >= base->command_count) {
                break;
            }
            if (i < 0) {
                break;
            }
        }
    }
after:
    switch (D_8009B45C->field_007C) {
    case 0x42:
    case 0x43:
    case 0x45:
    case 0x46:
    case 0x48:
        D_8009B45C->field_007C = 0;
        D_8009B45C->field_007D = 0;
        break;
    }

    if ((D_8009B45C->flags_0040 & 0x80) != 0) {
        if (D_8009B45C->field_157E != -1) {
            if (func_80049F50() == 1) {
                func_80049C40(D_8009B45C->field_157E);
            }
            D_8009B45C->flags_0040 = D_8009B45C->flags_0040 & 0xFF7F;
        }
    }
}
