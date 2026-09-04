/* Needs a -G8 compiler with a -G0 assembler; 13 differing. */
#include "common.h"

s32 func_8004A854(u8 arg0) {
    s32 best = -1;
    s32 bestv = 0xFFFF;
    s32 i = 0;
    s32 o = i;

    while (i < *(s16 *)(D_8009B458 + 0x510)) {
        u8 *p = D_8009B458 + o;
        u16 v = *(u16 *)(p + 0x19E);

        if ((u16)bestv >= v && p[0x183] == arg0 && p[0x18D] != 0) {
            bestv = v;
            best = i;
        }
        i++;
        o += 0x28;
    }

    return best;
}
