#include "common.h"

void func_800300C8(void) {
    u8 *b = D_800EB15C;
    s32 n = D_8009B2F1;
    u8 *p = D_8009B2E4;
    s32 x = *(s16 *)(b + 0x3C);
    s32 y;
    s32 z;
    s8 m;
    s32 h;

    if (n >= 10) {
        x -= 0x10;
        h = *(s16 *)(b + 0x3E) / 2;
        x += h;
    }
    *(s16 *)(p + 0x38) = x;
    *(s16 *)(p + 0x28) = x;
    h = *(s16 *)(b + 0x3E) / 2;
    y = x + h;
    y -= 0x10;
    *(s16 *)(p + 0x40) = y;
    *(s16 *)(p + 0x30) = y;
    m = n % 10;
    z = *(u16 *)(b + 0x40) + m * 16;
    *(s16 *)(p + 0x32) = z;
    *(s16 *)(p + 0x2A) = z;
    z += 0x10;
    *(s16 *)(p + 0x42) = z;
    *(s16 *)(p + 0x3A) = z;
}
