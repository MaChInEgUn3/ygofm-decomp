#include "common.h"

void func_80038EB0(u8 *p) {
    u8 **c;
    u8 *e;
    u8 *q;
    s32 cmd;
    s32 fl;
    s32 v;
    s32 v3;
    s32 a;
    s32 b;
    s32 k;

    D_8009B350 = 1;

    c = (u8 **)(p + *(s8 *)(p + 0x58) * 4);
    e = *c;
    a = e[0];
    *c = e + 1;

    cmd = a;
    q = (u8 *)D_800EB010;

    e = *(u8 **)(p + *(s8 *)(p + 0x58) * 4);
    b = e[0];
    *(u8 **)(p + *(s8 *)(p + 0x58) * 4) = e + 1;
    fl = b;

    if (cmd >= 0x41) {
        q = q + 0x98;
        goto have;
    }
    if (*(s8 *)(q + 0x30) == cmd) {
        goto have;
    }
    q = q + 0x4C;
    if (*(s8 *)(q + 0x30) == cmd) {
        goto have;
    }
    q = (u8 *)0;

have:
    if ((fl & 0x80) != 0) {
        if (q == (u8 *)0) {
            return;
        }
        D_8009B328 = q;
        if ((fl & 2) != 0) {
            func_80039FD4(q);
            return;
        }
        if ((fl & 1) != 0) {
            p[0x51] = 0xE;
            return;
        }
        v = 0x178;
        if (q[0x3C] == 0) {
            v = -0x38;
        }
        *(s16 *)(q + 0x40) = v;
        *(s16 *)(q + 0x42) = 0xB2;
        *(s16 *)(q + 0x44) = 0x10;
        p[0x51] = 7;
        q[0x33] = 3;
        if (cmd >= 0x41) {
            q[0x33] = 5;
            *(s16 *)(q + 0x40) = 1;
        }
        return;
    }

    if ((fl & 0x60) != 0) {
        if (q == (u8 *)0) {
            return;
        }
        if (cmd >= 0x41) {
            return;
        }
        D_8009B328 = q;
        if ((fl & 0x40) != 0) {
            q[0x31] = fl & 3;
            p[0x51] = 9;
            return;
        }
        if ((fl & 0x20) == 0) {
            goto create;
        }
        v = q[0x32] & 0xEF;
        q[0x32] = v;
        if ((fl & 1) != 0) {
            q[0x32] = v | 0x10;
        }
        return;
    }

create:
    k = fl & 1;
    if (cmd >= 0x41) {
        k = 2;
    }
    q = (u8 *)D_800EB010 + k * 0x4C;
    func_80039F44(q);
    q[0x30] = cmd;
    q[0x3C] = k;
    if (k != 0) {
        v3 = 0x178;
    } else {
        v3 = -0x38;
    }
    *(s16 *)(q + 0x34) = v3;
    p[0x51] = 6;
    D_8009B328 = q;
    if (cmd + 1 >= 0x42) {
        q[0x33] = 5;
        q[0x3C] = 2;
        *(s16 *)(q + 0x34) = 0xF0;
        *(s16 *)(q + 0x40) = 0;
        *(s16 *)(q + 0x36) = 0x60;
        return;
    }
    q[0x33] = 2;
    *(s16 *)(q + 0x40) = 3;
    if ((fl & 8) != 0) {
        *(s16 *)(q + 0x34) = 0x400;
        *(s16 *)(q + 0x40) = 7;
    }
    if ((fl & 0x10) != 0) {
        q[0x31] = (fl >> 1) & 3;
    }
}
