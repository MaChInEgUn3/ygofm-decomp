/* Needs a -G8 compiler with a -G0 assembler; 8 differing. */
#include "common.h"

s32 func_80045484(void) {
    s32 i = 1;
    s32 o = 0x30;

    while (i < *(s16 *)(D_8009B45C + 0x4C)) {
        u8 *p = D_8009B45C + o;

        switch (p[0x80]) {
        case 0x11:
        case 0x20:
        case 0x24:
            return 1;
        }

        i++;
        o += 0x30;
    }

    return 0;
}
