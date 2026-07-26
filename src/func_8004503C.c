#include "common.h"

/* func_800470B0 and its siblings pass a third value this ignores; declared
   so those call sites can be written as retail wrote them. */
void func_8004503C(s16 arg0, u8 arg1, s32 arg2) {
    u8 *p = D_8009B45C;

    *(s16 *)(p + 0x512) = arg0;
    p[0x49] = arg1;
}
