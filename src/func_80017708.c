#include "common.h"

void func_80017708(void) {
    s32 i = 0;
    u8 *base = D_800E9F10;
    s32 one = 1;
    s32 three = 3;
    u8 *row = 0;

    do {
        u8 *p = row + (s32)base;
        s32 j = 0;
        u8 *q = p + 0x14;

        do {
            *(s32 *)p = 0;
            *(s32 *)(q - 0x10) = 0;
            *(s32 *)(q - 0xC) = 0;
            q[4] = 0;
            q[-1] = one;
            q[3] = j;
            if (j != three) {
                q[0] = j;
            } else {
                q[0] = one;
            }
            q += 0x1C;
            j++;
            p += 0x1C;
        } while (j < 4);

        i++;
        row += 0x70;
    } while (i < 2);

    D_800E9F10[0x13] = 0;
    D_800E9F10[0x83] = 0;
}
