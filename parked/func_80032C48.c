/* 34 differing at 285/285 (2026-09-06, first written from the m2c draft). The
 * card-list sort-key builder: one loop per sort mode over 0x10-byte entries,
 * then one shared func_8008E400 call (jump table, full build only). What
 * paid, in order: the default-comparator call written as its OWN block at
 * the end of the switch that case 9 falls into (a `cmp = ...; goto sort`
 * block gets threaded into every arm, -10); the func_80032B60 comparator
 * calls written INLINE in cases 3/4/5 (retail duplicates their a0-a2 setup
 * and cross-jumps only the jal); the table base named before the cursor in
 * the table cases; the index minus one named (t[k], not t[idx - 1]); ONE
 * NAME PER ARM for the cursor, the index, the table word and the table base
 * (79 -> 43); and case 6/8 preheader constants named in retail's order with
 * the D_8009B2FC base read once and a stride of 1 (43 -> 34).
 * Residue: case 3's two key chains come out hi-first where retail computes
 * the lo chain first (pin round the lo chain, reversed compare: no change),
 * and case 8's four preheader pseudos sit one register lower than retail's
 * (index-first cast sum: no change; per-arm loop counters: 65, worse). */
#include "common.h"

void func_80031E04(u8 *arg0, s32 arg1);
void func_8008E400(u8 *arg0, s32 arg1, s32 arg2, void *arg3);
s32 func_80032B60();
s32 func_80032BD4();

void func_80032C48(u8 *arg0) {
    u8 *p;
    u8 *e1;
    u8 *e2;
    u8 *e3;
    u8 *e4;
    u8 *e5;
    u8 *e6;
    u8 *e7;
    u8 *e8;
    s32 i;
    s32 n;
    s32 w1;
    s32 w2;
    s32 w3;
    s32 w4;
    s32 w5;
    s32 w6;
    s32 w7;
    s32 w8;
    s32 lo;
    s32 hi;
    s32 v;
    s32 m6;
    s32 m7;
    s32 h7;
    u8 *b7;
    s32 x;
    s32 y;
    s32 *t1;
    s32 *t2;
    s32 *t3;
    s32 *t4;
    s32 *t5;
    s32 *t6;
    s32 *t7;
    s32 *t8;
    s32 k1;
    s32 k2;
    s32 k3;
    s32 k4;
    s32 k5;
    s32 k6;
    s32 k7;
    s32 k8;
    s32 a;
    s32 b;

    p = arg0;
    n = *(s16 *)(arg0 + 0x2D42);
    switch (arg0[0x2D45]) {
    case 1:
        if (arg0[0x2D47] != 0) {
            i = 0;
            if (n > 0) {
                k1 = 0xFFFF;
                e1 = p + 4;
                do {
                    *(s32 *)p = k1;
                    if (e1[9] != 0) {
                        *(s32 *)p = *(s16 *)e1;
                    }
                    i++;
                    e1 += 0x10;
                    p += 0x10;
                } while (i < n);
            }
        } else {
            i = 0;
            if (n > 0) {
                do {
                    i++;
                    *(s32 *)p = *(s16 *)(p + 4);
                    p += 0x10;
                } while (i < n);
            }
        }
        goto sortd;
    case 2:
        i = 0;
        if (n > 0) {
            do {
                *(s32 *)p = -1;
                if (p[0xD] != 0) {
                    *(s32 *)p = 0;
                }
                i++;
                p += 0x10;
            } while (i < n);
        }
        goto sortd;
    case 3:
        i = 0;
        if (n > 0) {
            t3 = D_801D4244;
            e3 = p + 4;
            do {
                *(s32 *)p = 0;
                if (e3[9] != 0) {
                    k3 = *(s16 *)e3 - 1;
                    w3 = t3[k3];
                    lo = w3 & 0x1FF;
                    a = lo * 0xA;
                    hi = (w3 >> 9) & 0x1FF;
                    b = hi * 0xA;
                    x = hi * 0xA0000;
                    if (a >= b) {
                        x = lo * 0xA0000;
                        y = hi * 0x28;
                    } else {
                        y = lo * 0x28;
                    }
                    *(s32 *)p = x | y | 1;
                }
                e3 += 0x10;
                i++;
                p += 0x10;
            } while (i < n);
        }
        func_8008E400(arg0, n, 0x10, func_80032B60);
        break;
    case 4:
        i = 0;
        if (n > 0) {
            t4 = D_801D4244;
            e4 = p + 4;
            do {
                *(s32 *)p = 0;
                if (e4[9] != 0) {
                    k4 = *(s16 *)e4 - 1;
                    w4 = t4[k4];
                    *(s32 *)p = ((w4 & 0x1FF) * 0xA0000) | (((w4 >> 9) & 0x1FF) * 0x28) | 1;
                }
                e4 += 0x10;
                i++;
                p += 0x10;
            } while (i < n);
        }
        func_8008E400(arg0, n, 0x10, func_80032B60);
        break;
    case 5:
        i = 0;
        if (n > 0) {
            t5 = D_801D4244;
            e5 = p + 4;
            do {
                *(s32 *)p = 0;
                if (e5[9] != 0) {
                    k5 = *(s16 *)e5 - 1;
                    w5 = t5[k5];
                    *(s32 *)p = (((w5 >> 9) & 0x1FF) * 0xA0000) | ((w5 & 0x1FF) * 0x28) | 1;
                }
                e5 += 0x10;
                i++;
                p += 0x10;
            } while (i < n);
        }
        func_8008E400(arg0, n, 0x10, func_80032B60);
        break;
    case 6:
        i = 0;
        if (n > 0) {
            m6 = -1;
            t6 = D_801D4244;
            e6 = p + 4;
            do {
                *(s32 *)p = m6;
                if (e6[9] != 0) {
                    k6 = *(s16 *)e6 - 1;
                    *(s32 *)p = (t6[k6] >> 0x1A) & 0x1F;
                }
                e6 += 0x10;
                i++;
                p += 0x10;
            } while (i < n);
        }
        goto sortd;
    case 8:
        i = 0;
        if (n > 0) {
            m7 = -1;
            h7 = 0x100;
            b7 = D_8009B2FC;
            e7 = p + 4;
            do {
                *(s32 *)p = m7;
                if (e7[9] != 0) {
                    *(s32 *)p = h7;
                    v = *(u8 *)(b7 + *(s16 *)e7 + 0x606A);
                    if (v != 0) {
                        *(s32 *)p = v;
                    }
                }
                e7 += 0x10;
                i++;
                p += 0x10;
            } while (i < n);
        }
        goto sortd;
    case 9:
        n = *(s16 *)(arg0 + 0x2D40);
        i = 0;
        if (n > 0) {
            do {
                *(s32 *)p = -1;
                if (p[0xD] != 0) {
                    *(s32 *)p = func_800358FC(0x1000);
                }
                i++;
                p += 0x10;
            } while (i < n);
        }
    sortd:
        func_8008E400(arg0, n, 0x10, func_80032BD4);
        break;
    }
    func_80031E04(arg0, 8);
}
