#include "common.h"

void func_80056250(s32 arg0, u8 *arg1, s32 arg2, s32 arg3) {
    u8 *p;
    u8 *q;
    u8 **c;
    u8 *e;
    u8 *r;
    s32 i;
    s32 sum;
    s32 k;
    s32 v;

    func_8004CB0C();
    if (arg1 == (u8 *)0) {
        return;
    }
    func_8004D75C(arg0);
    func_8004D914(arg0);
    p = arg0 * 0xE20 + D_800F2C40;
    sum = 0;
    if (arg0 < 2) {
        for (i = 0; i < p[0xE1B]; i++) {
            if (*(u16 *)(p + i * 2 + 0x33C) != 0xFFFF) {
                k = i / 8;
                if (((p + k)[0xBEC] >> (i - k * 8)) & 1) {
                    sum += 0x14;
                } else {
                    sum += 0xC;
                }
            }
        }
    }
    v = *(s32 *)(p + 0xDE0) + sum;
    *(s32 *)(p + 0xDF0) = v;
    v += *(u16 *)(p + 0xE02) * 4;
    *(s32 *)(p + 0xDF4) = v;
    func_8005A4C4(p, 0, 0, 0, arg0 == 1 ? 0x800 : 0);

    q = arg0 * 0xE20 + D_800F2C40;
    c = (u8 **)(q + 0x1E0);
    for (i = 0; i < q[0xE1B]; i++) {
        *(u16 *)(*c + 8) = 0xFFFF;
        *(u16 *)(*c + 0x16) = *(u16 *)(*c + 0x18);
        *(u16 *)(*c + 0xA) = 0xFFFF;
        (*c)[0xC] = (*c)[0x1A];
        *(u16 *)(*c + 0x10) = 0;
        (*c)[0xD] = 0x10;
        c++;
    }

    e = arg0 * 0xE20 + D_800F2C40;
    e[0xE1F] = 1;
    func_800590DC(arg0);
    v = e[0xE0D] * 2;
    switch (e[0xE16]) {
    case 0x23:
        func_8005A468(arg0, 0);
        break;
    case 0x3E:
        func_8005A468(arg0, v);
        break;
    case 0x3C:
        func_8005A468(arg0, -v);
        break;
    }
    if (arg0 < 2) {
        r = arg0 * 0xE20 + D_800F2C40;
        func_800582C0(arg0, r[0xE0C], *(u16 *)(r + 0xE0A));
    }
}
