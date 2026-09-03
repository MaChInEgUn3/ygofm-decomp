#include "common.h"

void func_800556E8(s32 idx) {
    s32 n;
    u8 *p;
    s32 w;
    s32 sp;
    s32 st;
    s32 v;
    s32 cur;
    s32 z;
    s32 d;

    p = D_800F2C40 + idx * 0xE20;
    if (p[0xE1F] != 0) {
        if (*(s32 *)(p + 0xDD8) != 0) {
            n = p[0xBF5];
            w = *(u16 *)(p + n * 0x76 + 0x7C4) * 16;
            sp = p[0xE0D] * func_80058E1C();
            if (n == 6) {
                st = p[0xE16];
                d = w - sp;
                if (st == 0x3E) {
                    if (*(u16 *)(p + 0xE06) >= d) {
                        goto call;
                    }
                }
                if (st == 0x3C) {
                    if (*(u16 *)(p + 0xE06) < 2) {
                    call:
                        func_80059700(idx, 0);
                    }
                }
            }
            if (idx < 2) {
                func_8005106C(idx);
            }
            if (p[0xE16] != 0x23) {
                if (p[0xE16] == 0x3E) {
                    if (*(u16 *)(p + 0xE06) >= w) {
                        *(u16 *)(p + 0xE06) = 0;
                    }
                    v = *(volatile u16 *)(p + 0xE06) + sp;
                    if (v >= w) {
                        *(u16 *)(p + 0xE06) = w;
                    } else {
                        *(u16 *)(p + 0xE06) = v;
                    }
                } else {
                    cur = *(u16 *)(p + 0xE06);
                    v = cur - sp;
                    if (cur == 0) {
                        *(u16 *)(p + 0xE06) = w;
                        v = *(volatile u16 *)(p + 0xE06) - sp;
                    }
                    if (v <= 0) {
                        *(u16 *)(p + 0xE06) = 0;
                    } else {
                        *(u16 *)(p + 0xE06) = v;
                    }
                }
            }
            if (p[0xE10] == 0) {
                if (p[0xE16] == 0x3E) {
                    if (*(u16 *)(p + 0xE06) < w) {
                        goto tail;
                    }
                } else if (*(u16 *)(p + 0xE06) != 0) {
                    goto tail;
                }
                n = 6;
                if (p[0xDC7] == n) {
                    p[0xBF4] = 2;
                }
                if (p[0xBF4] != p[0xBF6]) {
                    func_800597C8(idx, p[0xBF4], 0);
                    p[0xBF6] = p[0xBF4];
                    if (p[0xE0F] != 0) {
                        func_80057AF4(idx, 0, 0);
                    }
                    z = p[0xDC7] == n;
                    if (z) {
                        func_8005F714(-1, idx + 2, *(u16 *)(p + 0x8B0));
                        p[0xDC7] = 0;
                        p[0xBF4] = 1;
                    }
                }
            }
        }
    tail:
        if (p[0xE16] == 0x23 || p[0xE0D] != 0x10 || func_80058E1C() != 2) {
            w = *(u16 *)(p + 0xE06);
            for (n = 0; n < p[0xE1B]; n++) {
                func_8004DC38(p, n, p[0xBF5], w);
            }
        }
    }
}
