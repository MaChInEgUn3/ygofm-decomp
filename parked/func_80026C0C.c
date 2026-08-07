#include "common.h"

s32 func_80026C0C(s32 arg0) {
    s32 new_var;
    s32 n;
    s32 i;
    s32 r;
    s32 x;
    u8 *e;

    n = D_8009B1D5 * 15 + arg0;
    i = 0;
    r = n;
    e = &D_801A7AD8[r * 28];
    new_var = r;
    do {
        x = new_var + i;
        if ((*(u16 *)(e + 0x16) & 0x8000) == 0) {
            return x;
        }
        i++;
        e += 0x1C;
    } while (i < 5);
    return -1;
}
