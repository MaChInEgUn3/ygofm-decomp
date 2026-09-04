#include "common.h"

void func_8005FB30(u8 *arg0);
s32 func_80058DD8(s32 arg0);

void func_8005E808(u8 *p) {
    s16 a[3];
    s16 b[10][3];
    u8 *fp;
    u8 *e;
    u8 *q;
    u8 *t;
    u8 *r;
    s32 i;
    s32 j;
    s32 k;
    s32 m;
    s32 n;
    s32 w;
    s32 d0;
    s32 d1;
    s32 d2;
    u32 v;
    s32 mag;
    s32 acc;

    e = p;
    w = *(s16 *)(e + 0x20);
    m = w;
    if (w < 0) {
        m = -m;
    }
    mag = (m > 0 ? m : 1) * 2;
    func_8005FB30(e);
    r = (u8 *)D_8009B074;
    *(s16 *)(e + 0x24) = 0;
    if (r[0x26] != 0) {
        return;
    }
    p[0x26] = 1;
    if (m >= 0x4000) {
        *(u16 *)(e + 0x22) = 0x4000;
    } else {
        *(u16 *)(e + 0x22) = mag;
    }
    if (*(s16 *)(e + 0x20) >= 0) {
        return;
    }
    fp = e;
    i = 0;
    q = fp + 2;
    t = D_800F5768;
    do {
        switch (*(s16 *)(q + 4)) {
        case 0x80:
        case 0x81:
            n = (s16)(*(u16 *)(q + 4) & 0xFF7F);
            if (func_80058DD8(n) != 1) {
                break;
            }
            func_80058FB0(n, (u8 *)a);
            a[0] = a[0] + *(u16 *)fp;
            a[1] = a[1] + *(u16 *)q;
            a[2] = a[2] + *(u16 *)(q + 2);
            d0 = a[0] - *(s16 *)t;
            d1 = a[1] - *(s16 *)(t + 2);
            d2 = a[2] - *(s16 *)(t + 4);
            v = mag * func_80086E50(d0 * d0 + d1 * d1 + d2 * d2) / 1000;
            if (*(u16 *)(e + 0x22) < v) {
                *(u16 *)(e + 0x22) = v;
            }
            break;
        case 1:
            acc = 0;
            j = acc;
            do {
                func_8005EBF4(e, i, j, 0x1E, b[j]);
                j++;
            } while (j < 0xA);
            for (j = 1; j < 0xA; j++) {
                d0 = b[j - 1][0] - b[j][0];
                d1 = b[j - 1][1] - b[j][1];
                d2 = b[j][2];
                d2 = b[j - 1][2] - d2;
                acc += func_80086E50(d0 * d0 + d1 * d1 + d2 * d2);
            }
            v = mag * acc / 1000;
            goto put;
        case 4:
            m = *(u16 *)fp;
            v = *(u16 *)(D_800F5768 + 0x10);
            if (*(s16 *)(D_800F5768 + 0x10) < *(s16 *)fp) {
                v = m;
            }
            n = (s16)v;
            n = n * 6284;
            n = n / 1000;
            n = mag * n;
            k = *(s16 *)q;
            if (k < 0) {
                k = -k;
            }
            v = (u32)(n * k) / 4096000;
        put:
            if (*(u16 *)(e + 0x22) < v) {
                *(u16 *)(e + 0x22) = v;
            }
            break;
        }
        t += 8;
        i++;
        q += 8;
        fp += 8;
    } while (i < 2);
}
