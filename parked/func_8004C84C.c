/* Needs a -G8 compiler with a -G0 assembler; see the park note. */
#include "common.h"

void func_8004C84C(void) {
    s32 i = 0;
    s32 o = 0x180;

    while (i < *(s16 *)(D_8009B458 + 0x510)) {
        u8 *p = D_8009B458 + o;
        u16 c = *(u16 *)(p + 0x1E);

        if (c != 0 && (u32)p[3] < 0x10) {
            *(u16 *)(p + 0x1E) = c - 1;
        } else {
            *(u16 *)(p + 0x1E) = 0;
        }
        i++;
        o += 0x28;
    }
}
