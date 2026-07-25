#include "common.h"

void func_800594C0(s32 arg0, s32 *arg1) {
    u8 *p = &D_800F2C40[arg0 * 3616];

    if (arg1 != 0) {
        s32 a = arg1[0];
        s32 b = arg1[1];
        s32 c = arg1[2];
        s32 d = arg1[3];

        *(s32 *)(p + 0xDB0) = a;
        *(s32 *)(p + 0xDB4) = b;
        *(s32 *)(p + 0xDB8) = c;
        *(s32 *)(p + 0xDBC) = d;

        return;
    }
    *(s32 *)(p + 0xDB8) = 0x1000;
    *(s32 *)(p + 0xDB4) = 0x1000;
    *(s32 *)(p + 0xDB0) = 0x1000;
}
