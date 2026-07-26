#include "common.h"

void func_8002EDB0(void) {
    if (func_8002E3B4() == 0) {
        u8 *p = D_8009B290;
        s32 raw = *p;
        /* The narrowing copy is load-bearing: read straight into a 16-bit
           local and gcc loads into the callee-saved register directly,
           losing the move retail makes. */
        s16 c = raw;

        D_8009B290 = p + 1;
        if ((c & 0x7F) == 0) {
            func_8003FF34();
        } else {
            func_8003FF58(c & 0x7F);
        }

        if (c & 0x80) {
            return;
        }
    }

    D_8009B27C = 0;
}
