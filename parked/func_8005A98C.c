#include "common.h"

typedef struct {
    s32 h;
    s16 s;
    s16 v;
} HsvT;

HsvT *func_8005A98C(HsvT *out, s8 r, u8 g, s8 b, u8 lim) {
    u8 c[3];
    HsvT t;
    u8 x;
    s32 i;
    s32 hi;
    s32 lo;
    s32 mx;
    s32 mn;
    s32 d2;
    s32 sum;
    s32 q;
    s32 df;
    s32 n;

    hi = 0;
    lo = 0;
    i = 1;
    c[0] = r;
    c[1] = g;
    c[2] = b;

    do {
        x = c[i];
        if (c[hi] < x) {
            hi = i;
        }
        if (x < c[lo]) {
            lo = i;
        }
        i++;
    } while (i < 3);

    mx = c[hi];
    mn = c[lo];
    sum = mx + mn;
    d2 = (lim & 0xFF) * 2;
    q = (sum << 12) / d2;

    t.v = 0;
    t.h = 0;
    df = mx - mn;
    t.s = q;

    if (df != 0) {
        n = df << 12;
        if ((u32)(q & 0xFFFF) < 0x801) {
            t.v = n / sum;
        } else {
            t.v = n / (d2 - sum);
        }
        n = (c[(hi + 1) % 3] - c[(hi + 2) % 3]) << 12;
        n = (hi << 13) + n / df;
        t.h = n;
        if (n < 0) {
            t.h = n + 0x6000;
        }
    }

    *out = t;
    return out;
}
