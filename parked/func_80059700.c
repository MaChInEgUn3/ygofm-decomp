#include "common.h"

void func_80059700(s32 arg0, s32 arg1) {
    u8 *t = D_800F2C40;
    u8 *p = t + arg0 * 3616;
    u8 *q;
    s32 m;
    s32 v;
    s32 a;

    if (arg1 <= 0) {
        if (arg1 < 0) {
            p[0xE16] = 0x3C;
        } else {
            p[0xE16] = 0x23;
        }
    } else {
        p[0xE16] = 0x3E;
    }

    q = D_800F2C40 + arg0 * 3616;
    v = q[0xE0D] * 2;
    a = 0;
    m = q[0xE16];

    switch (m) {
    case 0x23:
        break;

    case 0x3C:
        a = v;
        a = -a;
        break;

    case 0x3E:
        a = v;
        break;

    default:
        return;
    }

    func_8005A468(arg0, a);
}
