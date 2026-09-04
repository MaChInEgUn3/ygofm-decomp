#include "common.h"


void func_80052D2C(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    SVector a;
    SVector b;
    SVector c;
    s32 r;
    s32 n;
    s32 t;
    u8 *q1;
    u8 *q2;
    u8 *g;
    u8 *h;
    u8 *e;
    u8 *f;
    u16 k;
    u16 v;

    func_8008E3D0(&b, 0, 8);
    b.vx = *(u16 *)(D_800F56F0 + 0);
    b.vy = *(u16 *)(D_800F56F0 + 4);
    b.vz = *(u16 *)(D_800F56F0 + 8);
    a = b;
    func_8008E3D0(&c, 0, 8);
    c.vx = *(u16 *)(D_800F56F0 + 0xC);
    c.vy = *(u16 *)(D_800F56F0 + 0x10);
    c.vz = *(u16 *)(D_800F56F0 + 0x14);
    b = c;
    r = func_8005F174();
    if (r == 1) {
        if (func_8005F18C() == r) {
            return;
        }
    }
    if (arg1 != 0 || arg0 <= 0) {
        if (arg1 > 0) {
            n = arg1 - 1;
            arg1 = (s32)(D_800F3A10 + n * 3616);
            if (arg3 >= 0) {
                D_800F2B32[0] = n ^ 1;
            } else {
                D_800F2B32[0] = -1;
            }
            D_800F2B3A[0] = n;
        } else {
            q1 = D_800F2B20;
            *(s16 *)(q1 + 0x1A) = -1;
            *(s16 *)(q1 + 0x12) = -1;
        }
    }
    if (arg2 != 0 || arg0 <= 0) {
        if (arg2 > 0) {
            n = arg2 - 1;
            arg2 = (s32)(D_800F3A10 + n * 3616);
            if (arg3 >= 0) {
                D_800F2B42[0] = n ^ 1;
            } else {
                D_800F2B42[0] = -1;
            }
            D_800F2B4A[0] = n;
        } else {
            q2 = D_800F2B20;
            *(s16 *)(q2 + 0x2A) = -1;
            *(s16 *)(q2 + 0x22) = -1;
        }
        if (arg0 >= 0) {
            goto setb;
        }
    } else {
    setb:
        D_800F2B20[0] = arg0;
    }
    g = D_800F2B20;
    *(s16 *)(g + 2) = 0x12C;
    *(s16 *)(g + 6) = 8;
    *(s16 *)(g + 4) = 8;
    g[1] = 0;
    if (arg1 != 0) {
        g[1] = 1;
    } else {
        arg1 = (s32)&a;
    }
    if (arg2 != 0) {
        g = D_800F2B20;
        g[1] = g[1] | 2;
    } else {
        arg2 = (s32)&b;
    }
    h = D_800F2B20;
    *(u16 *)(h + 0xC) = a.vx;
    *(u16 *)(h + 0xE) = a.vy;
    *(u16 *)(h + 0x10) = a.vz;
    do {
        v = ((u16 *)arg1)[0];
        *(u16 *)(h + 0x14) = v;
        v = ((u16 *)arg1)[1];
        *(u16 *)(h + 0x16) = v;
    } while (0);
    *(u16 *)(h + 0x1C) = b.vx;
    k = ((u16 *)arg1)[2];
    *(u16 *)(h + 0x1E) = b.vy;
    *(u16 *)(h + 0x20) = b.vz;
    *(u16 *)(h + 0x18) = k;
    v = ((u16 *)arg2)[0];
    *(u16 *)(h + 0x24) = v;
    v = ((u16 *)arg2)[1];
    *(u16 *)(h + 0x26) = v;
    do {
        t = arg3;
    } while (0);
    if (arg3 < 0) {
        t = -t;
    }
    arg3 = t * 2;
    *(u16 *)(h + 0x28) = ((u16 *)arg2)[2];
    if (arg3 > 0xFFFE) {
        *(u16 *)(h + 0xA) = 0xFFFF;
    } else {
        *(u16 *)(h + 0xA) = arg3;
    }
    e = D_800F2B20;
    *(s16 *)(e + 8) = 0;
    if (e[1] != 0) {
        D_8009AF98 = 0;
    }
    if (arg3 != 0) {
        return;
    }
    if (e[1] & 1) {
        *(s32 *)(D_800F56F0 + 0) = *(s16 *)(e + 0x14);
        *(s32 *)(D_800F56F0 + 4) = *(s16 *)(e + 0x16);
        *(s32 *)(D_800F56F0 + 8) = *(s16 *)(e + 0x18);
    }
    if (e[1] & 2) {
        f = D_800F56F0;
        *(s32 *)(f + 0xC) = *(s16 *)(e + 0x24);
        *(s32 *)(f + 0x10) = *(s16 *)(e + 0x26);
        *(s32 *)(f + 0x14) = *(s16 *)(e + 0x28);
    }
    if (e[1] & 3) {
        func_80057F38((u8 *)0);
    }
    e[1] = 0;
}
