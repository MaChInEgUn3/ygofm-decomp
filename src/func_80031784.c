#include "common.h"

void func_80031784(u8 *p, s32 arg1, u8 *q, s32 arg3) {
    s32 i;
    u8 *r;

    *(s16 *)(p + 0x12) = 0xFB;
    i = 0;
    r = q + 1;

    do {
        *(s32 *)(p + 0x14) = 0x202020;
        if ((r[0] & 0xF) == arg3) {
            *(s32 *)(p + 0x14) = 0x808080;
        }
        i++;
        p[0xE] = ((q[0] & 0xF) << 3) - 0x80;
        p[0xF] = q[0] & 0xF0;
        *(s16 *)(p + 0x10) = (r[0] & 0xF0) | 0x200;
        r += 2;
        func_800849F0(p, arg1, 0);
        *(u16 *)(p + 4) += 0x12;
        q += 2;
    } while (i < 7);
}
