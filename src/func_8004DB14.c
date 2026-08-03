#include "common.h"

s32 func_8004DB14(u8 *p, s32 i) {
    s32 acc;
    s32 n;
    u8 *e;
    u8 *tbl;
    u8 *lim;
    u8 *q;
    s32 k;
    s32 v;
    s32 off;

    acc = 0;
    n = 1;
    off = i * 4;
    e = *(u8 **)(p + off + 0x1E0);
    if (e == (u8 *)0) {
        return 0;
    }
    lim = *(u8 **)(p + 0xDD8) + *(u16 *)(e + 0x16) * 4;
    if (*(s32 *)lim < 0) {
        return 0;
    }
    tbl = *(u8 **)(p + 0xDD8);
    for (n = 1; n < 10; n++) {
        k = *(u16 *)(p + (n * 0x74 + i * 2) + 0x2C8);
        q = tbl + k * 4;
        if (k != 0xFFFF && lim >= q - 4 && tbl + *(u16 *)(q - 4) * 4 >= lim) {
            break;
        }
    }
    if (n < 10) {
        while (q < lim) {
            acc += q[2];
            q += 4;
        }
        v = *(s16 *)(e + 0x10);
        if (v != 0x6000 && v != 0x7000) {
            acc += (*(u16 *)(e + 0x12) - v) / 16;
        }
    } else {
        n = 0;
    }
    return (n << 24) | acc;
}
