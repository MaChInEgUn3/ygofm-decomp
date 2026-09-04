#include "common.h"

s32 func_8004BCE8(void) {
    u8 *p;
    u32 r;
    u32 v;
    s32 c;
    s32 m;

    p = D_8009B458 + 0x518;
    D_8009B458[0x801] = 0;
    *(s32 *)(D_8009B458 + 0x7F0) = 0;
    *(s32 *)(D_8009B458 + 0x7F4) = 0;
    *(s32 *)(D_8009B458 + 0x518) = 8;
    *(s16 *)(D_8009B458 + 0x7FC) = func_8004BCA8(p);
    *(s16 *)(D_8009B458 + 0x7FA) = 1;
    *(s16 *)(D_8009B458 + 0x7F8) = 0;
    *(s32 *)(D_8009B458 + 0x7EC) = 0x10000;
    r = (u32)func_8004BC2C(p) >> 8;
    *(s32 *)(D_8009B458 + 0x808) = r;

    v = 60000000 / r * 100 / 115;
    if (v >= 0x100) {
        v = 0xFF;
    }

    m = *(u16 *)(D_8009B458 + 0x7FC);
    if (m == 0x1E) {
        goto sh2;
    }
    if (m < 0x1F) {
        if (m == 0x18) {
            goto sh1;
        }
        c = v & 0xFF;
        goto store;
    }
    if (m != 0x3C) {
        goto mask;
    }
sh1:
    v >>= 1;
    goto mask;
sh2:
    v >>= 2;
mask:
    c = v & 0xFF;
store:
    *(s16 *)(p + 0x16) = c;
    *(s16 *)(p + 0x14) = c;
    func_8004BAE4(p);

    if (*(u16 *)(D_8009B458 + 0x7FC) >= 0x60) {
        *(s32 *)(D_8009B458 + 0x804) = *(u16 *)(D_8009B458 + 0x7FC);
    } else {
        *(s32 *)(D_8009B458 + 0x804) = 0;
    }
    *(s32 *)(D_8009B458 + 0x804) = *(u16 *)(D_8009B458 + 0x7FC);
    return 1;
}
