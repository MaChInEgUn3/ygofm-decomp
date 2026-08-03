#include "common.h"

void func_80036C14(u8 *p, s32 a) {
    u8 *q;
    s16 *r;
    u16 f;
    s32 v;
    s32 b;
    s32 c;
    s32 d;

    q = *(u8 **)(p + 0x20);
    q[0x12] = p[0x57] + 1;
    q[0x13] = 1;
    q[0x15] = 0;
    r = D_801DA000;
    f = *(u16 *)(p + 0x34);
    if (f & 0x80) {
        q[0x10] = a;
        b = p[0x62];
        q[0x11] = 0xA0;
        q[0x17] = b;
    } else if (f & 0x100) {
        v = (a >> 20) & 0xFF;
        if (v == 0) {
            return;
        }
        q[0x10] = v;
        q[0x11] = 0xC0;
        c = p[0x54];
        q[0x13] = 0;
        q[0x16] = c;
    } else {
        a &= 0x8000FFFF;
        if (a == 0) {
            return;
        }
        if (f & 0x200) {
            r = (s16 *)(p[0x60] * 0x88 + (u8 *)r);
        }
        q[0x10] = 0;
        d = p[0x54];
        q[0x11] = 0x80;
        *(s32 *)q = a;
        q[0x16] = d;
        r[0] = 0x280;
        r[2] = 4;
        r[1] = 0;
        r[3] = 0x10;
    }
    if (*(u16 *)(p + 0x34) & 0x1C00) {
        q[0x13] = 0;
    }
    *(s16 *)(q + 0xC) = *(u16 *)(p + 0x38);
    *(s16 *)(q + 0xE) = *(u16 *)(p + 0x3A);
    q += 0x1C;
    q[0x11] = 0;
    *(u8 **)(p + 0x20) = q;
}
