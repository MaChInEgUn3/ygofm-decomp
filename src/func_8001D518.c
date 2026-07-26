#include "common.h"

u8 *func_8001D518(u8 *arg0) {
    u8 *p = D_8009B1F8;

    if (p == 0) {
        p = func_800400AC(func_8004002C(), 2);
        func_80040468(p, 4, 3, 8, 0xB, 0x1F0);
        p[0x6A] = arg0[0xA];
        func_800428EC(p, 1);
        *(void **)(p + 0x24) = func_80015DB8;
        *(u16 *)(p + 8) |= 8;
    }

    return p;
}
