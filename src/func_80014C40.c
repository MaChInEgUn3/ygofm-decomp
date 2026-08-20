#include "common.h"

typedef struct {
    s32 w[8];
} Blk32;

void func_80014B30(void);

s32 func_80014C40(u8 *p, u8 *q) {
    u8 *e;
    u8 *r;
    void *f;
    s32 a;
    s32 b;
    s32 c;
    s32 n;
    s32 m;
    s32 v;
    s32 w;
    s32 t;

    if (p == (u8 *)0) {
        return D_8009B0F4 & 0x20;
    }

    a = *(s32 *)(p + 0x14);
    b = *(s32 *)(p + 0x18);
    c = *(s16 *)(p + 0x1C);

    if ((a | b | c) == 0) {
        return (s32)func_80013A94(*(s32 *)p, *(s32 *)(p + 4));
    }

    if (c != 0) {
        if (c < 0) {
            D_8009B112 = D_8009B112 & 0x3FFC;
            D_8009B112 = D_8009B112 | 2;
            return 1;
        }
        n = *(s32 *)D_800E9EC0 + *(s32 *)(p + 4);
        return func_80013B68(n, n + c, p[0x1F], p[0x1E]);
    }

    a = a + b;
    if (a == 0) {
        return 0;
    }

    {
        w = *(s32 *)p;
        /* Borrowed local: `m`'s real assignment is three lines down and this
         * one is dead, but it ties the negation's pseudo to m's allocation
         * and rotates $s2/$s3/$s4 into retail's order. A fresh name, six
         * declaration orders and four statement orders are all 6. */
        m = a;
        t = -m;
        r = D_801D4200;
        *(Blk32 *)(r + 0x20) = *(Blk32 *)p;
        m = *(s32 *)(p + 4);
        D_8009B0F4 = D_8009B0F4 & ~0x20;
        v = w | 0x1400000;
        f = func_80014B30;

        if ((D_8009B0F4 & 0x10) != 0) {
            if ((D_8009B0F4 & 0x80000) != 0) {
                func_80015010();
            }
        }

        func_80013998(D_800E9E18, v, q, m, t, f, 0, (s32)p);
        e = D_800E9E18;
        D_8009B0F4 = D_8009B0F4 | 0x20;
    }

    return (s32)e;
}
