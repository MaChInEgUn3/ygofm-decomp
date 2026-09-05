#define D_8009B0D8_IN_DATA
#include "common.h"

void func_80039AFC(u8 *p) {
    if (func_80039AAC(p) == 0) {
        p[0x15] = 2;
        *(s32 *)(p + 4) = 0;
        p[0x14] = 0x20;
    }

    p[0x14] = p[0x14] - D_8009B0D8 * 2;

    if ((p[0x13] & 0x40) == 0) {
        p[4] = p[4] + D_8009B0D8 * 16;
        if ((s8)p[4] < 0) {
            p[4] = 0x80;
            p[0x14] = 0x10;
            p[0x13] |= 0x40;
        }
        p[6] = p[4];
    } else {
        p[5] = p[5] + D_8009B0D8 * 16;
        if ((s8)p[5] < 0) {
            p[0x14] = 0;
            p[0x15] = 0;
            p[0x13] = 0;
        }
        p[7] = p[5];
    }
}
