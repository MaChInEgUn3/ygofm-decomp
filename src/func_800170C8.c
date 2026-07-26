#include "common.h"

s32 func_800170C8(u8 *arg0) {
    s32 a = *(s16 *)(arg0 + 0xE);
    s32 b = *(s16 *)(arg0 + 0x12);
    s32 c = *(s16 *)(arg0 + 0x14);
    s32 x;
    s32 y;

    x = a + b + c;
    if (x < 0) {
        x = 0;
    }
    if (x >= 0x2710) {
        x = 0x270F;
    }

    y = *(s16 *)(arg0 + 0x10) + b + c;
    if (y < 0) {
        y = 0;
    }
    if (y >= 0x2710) {
        y = 0x270F;
    }

    return (y << 16) | x;
}
