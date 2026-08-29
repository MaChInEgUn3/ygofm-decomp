#include "common.h"

void func_80056250(s32 arg0, u8 *arg1, s32 arg2, s32 arg3) {
    u8 *p;
    u8 *q;
    u8 **c;
    u8 *e;
    u8 *r;
    s32 i;
    s32 j;
    s32 sum;
    s32 k;
    s32 v;
    s32 m;
    s32 n;
    u8 *b;
    u8 *b2;
    s32 w;

    func_8004CB0C();
    if (arg1 == (u8 *)0) {
        return;
    }
    func_8004D75C(arg0);
    func_8004D914(arg0);
    p = arg0 * 0xE20 + D_800F2C40;
    sum = 0;
    if (arg0 < 2) {
        if (sum < p[0xE1B]) {
        i = sum;
        m = 0xFFFF;
        n = p[0xE1B];
        do {
            if (*(u16 *)(p + i * 2 + 0x33C) != m) {
                k = i / 8;
                if (((p + k)[0xBEC] >> (i - k * 8)) & 1) {
                    sum += 0x14;
                } else {
                    sum += 0xC;
                }
            }
            i++;
        } while (i < n);
        }
    }
    v = (*(s32 *)(p + 0xDF0) = *(s32 *)(p + 0xDE0) + sum);
    *(s32 *)(p + 0xDF4) = v + *(u16 *)(p + 0xE02) * 4;
    func_8005A4C4(p, 0, 0, 0, arg0 == 1 ? 0x800 : 0);

    q = arg0 * 0xE20 + D_800F2C40;
    c = (u8 **)(q + 0x1E0);
    for (j = 0; j < q[0xE1B]; j++) {
        *(u16 *)(*c + 8) = 0xFFFF;
        *(u16 *)(*c + 0x16) = *(u16 *)(*c + 0x18);
        *(u16 *)(*c + 0xA) = 0xFFFF;
        (*c)[0xC] = (*c)[0x1A];
        *(u16 *)(*c + 0x10) = 0;
        (*c)[0xD] = 0x10;
        c++;
    }

    b = D_800F2C40;
    e = arg0 * 0xE20 + b;
    e[0xE1F] = 1;
    func_800590DC(arg0);
    v = e[0xE0D] * 2;
    w = v;
    switch (e[0xE16]) {
    case 0x23:
        w = 0;
        func_8005A468(arg0, w);
        break;
    case 0x3E:
        w = v;
        func_8005A468(arg0, w);
        break;
    case 0x3C:
        w = -w;
        func_8005A468(arg0, w);
        break;
    }
    if (arg0 < 2) {
        b2 = D_800F2C40;
        r = arg0 * 0xE20 + b2;
        func_800582C0(arg0, r[0xE0C], *(u16 *)(r + 0xE0A));
    }
}
