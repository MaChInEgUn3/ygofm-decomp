#include "common.h"

void func_80035DB8(s32 arg0) {
    s32 n = 0x26C;
    u8 *p;

    arg0++;
    p = (u8 *)D_800EB288;

    do {
        if (p[0x12] == arg0) {
            p[0x11] = 0;
        }
        p += 0x1C;
        n--;
    } while (n != 0);
}
