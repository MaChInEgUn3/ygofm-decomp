#define D_800E9EF0_IS_PTR_VOLATILE
#define D_8009B0F4_IS_AGGREGATE
#define D_8009B134_IS_AGGREGATE
#include "common.h"

u8 *func_800291E0(s32 arg0, s32 arg1, s32 arg2);
void func_8001944C(u8 *arg0);
void func_80029528(s32 arg0);

void func_80019608(void) {
    u8 *p;
    u8 *e;
    u8 *q;
    u8 *r1;
    u8 *r2;
    u8 *volatile *b;
    u8 *volatile *b2;
    u8 *volatile *b3;
    s32 m;
    s32 st;
    s32 n;
    s32 c;
    s32 x;
    s32 mk;
    u16 f;

    f = D_8009B23A;
    p = D_800E9EF0[0];
    if ((f & 0x8000) == 0) {
        D_8009B23A = f | 0xC000;
        e = D_801A7AD8 + p[0x6A] * 28;
        n = *(s16 *)(e + 0xC);
        D_8009B150 = *(u16 *)(e + 0xC);
        func_80029164(0, n);
        if (p[0x68] == 0x14) {
            D_8009B1C8[5] = D_8009B1C8[5] + 1;
        }
        func_80024914(e);
        D_8009B174 = 1;
    }
    m = D_8009B174;
    st = m & 0xF;
    switch (st) {
    case 1:
        if ((m & 0x80) != 0) {
            goto c1b;
        }
        if (((D_8009B0F4[0] & 0x2000030) | D_8009B134[0]) != 0) {
            return;
        }
        D_8009B174 = m | 0x80;
        *(u16 *)(p + 8) = *(u16 *)(p + 8) | 4;
        n = -1;
        p = func_800291E0(0, n, n);
        *(u16 *)(p + 0x30) = 0x5A;
        *(u16 *)(p + 0x32) = 0x16;
        p[0x21] = 0xC0;
        func_800428EC(p, -0xA);
        *(u16 *)(p + 8) = (*(u16 *)(p + 8) | 4) & 0xFFBF;
        *(u8 **)D_800E9EF4 = p;
        return;
    c1b:
        if ((m & 0x40) != 0) {
            goto c1c;
        }
        p[0x21] = p[0x21] + 6;
        if (p[0x21] < 0x40) {
            return;
        }
        D_8009B174 = D_8009B174 | 0x40;
        func_8004036C(p);
        b = D_800E9EF0;
        q = b[1];
        b[0] = (u8 *)0;
        *(u16 *)(q + 8) = *(u16 *)(q + 8) | 0x40;
        return;
    c1c:
        p = *(u8 **)D_800E9EF4;
        if ((m & 0x20) != 0) {
            goto c1d;
        }
        c = (p[0x21] = p[0x21] + 6);
        if ((s8)c < 0) {
            return;
        }
        *(u16 *)(p + 0x60) = 0x1E;
        x = *(u16 *)(p + 8);
        p[0x21] = 0;
        n = D_8009B174;
        *(u16 *)(p + 8) = x & 0xFFFB;
        D_8009B174 = n | 0x20;
        return;
    c1d:
        c = *(u16 *)(p + 0x60) - 1;
        *(u16 *)(p + 0x60) = c;
        if ((s16)c > 0) {
            return;
        }
        D_8009B174 = 2;
        return;
    case 2:
        func_80026BA4(D_8009B150, 0);
        D_8009B174 = 3;
        return;
    case 3:
        if ((m & 0x80) != 0) {
            goto c3b;
        }
        mk = 0xF7FFFFFF;
        b2 = D_800E9EF0;
        p = b2[1];
        D_8009B174 = m | 0x80;
        func_8001944C(p);
        r1 = func_80019564(p);
        b2[0] = r1;
        *(s32 *)(r1 + 4) = *(s32 *)(r1 + 4) | 0x50000000;
        q = b2[0];
        *(s32 *)(q + 4) = *(s32 *)(q + 4) & mk;
        r2 = func_80019564(p);
        b2[1] = r2;
        func_800428EC(r2, -1);
        q = b2[1];
        *(s32 *)(q + 4) = *(s32 *)(q + 4) | 0x60000000;
        q = b2[1];
        *(s32 *)(q + 4) = *(s32 *)(q + 4) & mk;
        func_80029528(0);
        return;
    c3b:
        b3 = D_800E9EF0;
        p = b3[0];
        q = b3[1];
        n = *(s16 *)(p + 0x44) + 0x80;
        *(u16 *)(q + 0x46) = n;
        *(u16 *)(q + 0x44) = n;
        *(u16 *)(p + 0x46) = n;
        *(u16 *)(p + 0x44) = n;
        e = b3[0];
        c = e[0xC] - 4;
        if (c < 0) {
            c = 0;
        }
        c = c | (c << 16 | c << 8);
        *(s32 *)(e + 0xC) = c;
        *(s32 *)(b3[1] + 0xC) = c;
        if (c != 0) {
            return;
        }
        func_8004036C((s32)b3[0]);
        func_8004036C((s32)b3[1]);
        D_8009B174 = 4;
        return;
    case 4:
        if ((m & 0x80) != 0) {
            D_8009B23A = 5;
            return;
        }
        D_8009B174 = m | 0x80;
        func_80026BA4(D_8009B150, 1);
        return;
    }
}
