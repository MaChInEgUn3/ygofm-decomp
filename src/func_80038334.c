#include "common.h"

/* The two extra names are a coupled pair, found by the permuter: `d` alone
 * changes nothing (6 differences, same as neither) and `a` alone is worse
 * (14), and together they match. Do not tidy either away. */
void func_80038334(u8 *p) {
    u8 **slot;
    u8 *q;
    u8 *d;
    u8 *a;
    s32 v;

    slot = (u8 **)(p + *(s8 *)(p + 0x58) * 4);
    d = *slot;
    q = d;
    v = *q;
    *slot = q + 1;
    p[0x5A] = v;

    a = p + *(s8 *)(p + 0x58) * 4;
    slot = (u8 **)a;
    q = *slot;
    v = *q;
    *slot = q + 1;
    p[0x5B] = v;
}
