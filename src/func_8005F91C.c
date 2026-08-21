#include "common.h"

/* An eight-byte record with alignment 1: retail copies it with lwl/lwr and
 * swl/swr pairs, which is what gcc emits when it cannot prove alignment 4. */
typedef struct {
    u8 b[8];
} Blk8;

void func_8005F91C(s32 arg0, u8 *arg1, u8 *arg2, s32 arg3) {
    u8 *p;
    u8 *q;
    u8 *r;
    s32 n;
    s32 i;
    s32 one;

    one = 1;
    if (D_8009B07B == one && D_8009B07C == one) {
        return;
    }

    if (arg0 == one) {
        goto m1;
    }
    if (arg0 < 2) {
        if (arg0 == 0) {
            goto m0;
        }
        return;
    }
    if (arg0 == 2) {
        goto m2;
    }
    return;

m0:
    func_80059EBC(-1);
    D_8009B074 = (s32)D_800F5788;
    D_8009B078 = 0;
    if (arg1 == (u8 *)0 && arg2 == (u8 *)0 &&
        (arg3 == 0 || arg3 == 0x4000)) {
        return;
    }
    func_8005F070(0);
    D_8009B079 = 1;

m1:
    if (D_8009B078 < 0xA) {
        r = &D_800F5788[D_8009B078 * 0x28];
        if (arg1 != (u8 *)0) {
            *(Blk8 *)r = *(Blk8 *)arg1;
        } else {
            *(u16 *)(r + 6) = 0;
        }
        if (arg2 != (u8 *)0) {
            *(Blk8 *)(r + 8) = *(Blk8 *)arg2;
            r[0x26] = 0;
        } else {
            *(u16 *)(r + 0xE) = 0;
            r[0x26] = 0;
        }
        n = D_8009B078;
        *(s16 *)(r + 0x20) = arg3;
        *(s16 *)(r + 0x22) = 0;
        *(s16 *)(r + 0x24) = 0;
        D_8009B078 = n + 1;
    }
    return;

m2:
    q = D_800F5788;
    for (i = 0; i < D_8009B078; i++) {
        p = q;
        q += 0x28;
        func_8005E808(p);
    }
    D_8009B079 = 0;
    D_8009B07A = -1;
}
