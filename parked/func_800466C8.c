#include "common.h"

void func_800466C8(void) {
    u8 *p;

    p = D_8009B45C;
    if ((*(u16 *)(p + 0x40) & 0x80) != 0) {
        *(u16 *)(p + 0x1588) = 8;
        p[0x1584] = 0xFF;
        p = D_8009B45C;
    }
    p[0x49] = 0;
    *(s16 *)(p + 0x512) = -0x40;
    *(u16 *)(D_8009B45C + 0x40) &= 0xFFFB;
}
