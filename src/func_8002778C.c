#include "common.h"

s32 func_8002778C(u8 **p) {
    u8 *e;
    s32 i;
    s32 n;

    n = 0;
    i = 5;

    do {
        e = &D_801A7AD8[D_800907D8[i + D_8009B1D5 * 20] * 28];
        if (*(u16 *)(e + 0x16) & 0x8000) {
            n++;
            if (func_8001EFD4(*p, *(u8 **)e) > 0) {
                return (*(u8 **)e)[0x6A];
            }
        }
        i++;
    } while (i < 0xA);

    if (n == 0) {
        return D_800907D8[D_8009B1D5 * 20 + 7];
    }
    return -1;
}
