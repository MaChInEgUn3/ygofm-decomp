#include "common.h"

s32 func_8003D174(u8 *p) {
    s32 h;
    s32 i;
    s32 *q;

    h = func_8003CEB8(p, 0x340) & 0xFFFF;
    q = (s32 *)(p + 0x378);
    i = 0xF;
    D_8009AF68 = h | (h << 16);
    D_8009AF64[0] = h | (h << 16);
    do {
        if (*q != func_8003CE74()) {
            return 0;
        }
        i--;
        q--;
    } while (i != 0);

    h = func_8003CEB8(p + 0x380, 0x6C) & 0xFFFF;
    q = (s32 *)(p + 0x3F8);
    i = 4;
    D_8009AF68 = h | (h << 16);
    D_8009AF64[0] = h | (h << 16);
    do {
        if (*q != func_8003CE74()) {
            return 0;
        }
        i--;
        q--;
    } while (i != 0);

    h = func_8003CEB8(p + 0x400, 0x204) & 0xFFFF;
    q = (s32 *)(p + 0x624);
    i = 8;
    D_8009AF68 = h | (h << 16);
    D_8009AF64[0] = h | (h << 16);
    do {
        if (*q != func_8003CE74()) {
            return 0;
        }
        i--;
        q--;
    } while (i != 0);

    return 1;
}
