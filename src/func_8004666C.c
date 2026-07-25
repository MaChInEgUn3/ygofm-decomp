#include "common.h"

void func_8004666C(void) {
    u8 *p = D_8009B45C;
    u8 *q;
    s32 f;

    p[0x49] = 0xFF;
    q = D_8009B45C;
    *(s16 *)(p + 0x512) = 0x40;
    f = (*(u16 *)(q + 0x40) & 0xFFFC) | 4;
    *(u16 *)(q + 0x40) = f;
    if (f & 0x80) {
        if (*(s16 *)(q + 0x1588) >= 0) {
            *(s16 *)(q + 0x1588) = -0x10;
            q[0x1584] = 0xDC;
        }
    }
}
