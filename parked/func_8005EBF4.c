#include "common.h"

typedef struct {
    u8 b[0x28];
} R28;

void func_8005EBF4(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s16 *arg4) {
    u8 *a[4];
    u8 *b[4];
    u8 *c[4];
    u8 sp48[0x18];
    s32 k;
    s32 m;
    u8 *p;
    u8 *r;
    s16 *q;
    s32 v;

    b[0] = D_800F5788 + (((R28 *)arg0 - (R28 *)D_800F5788) % D_8009B078) * 0x28;
    b[1] = D_800F5788 + ((((R28 *)arg0 - (R28 *)D_800F5788) + 1) % D_8009B078) * 0x28;
    b[2] = D_800F5788 + ((((R28 *)arg0 - (R28 *)D_800F5788) + 2) % D_8009B078) * 0x28;
    a[0] = b[0];
    a[1] = b[1];
    a[2] = b[2];
    func_8008E3D0(c, 0, 0x10);
    c[0] = D_800F5768 + arg1 * 8;
    k = 1;
    while (k < 3) {
        if (*(u8 *)(a[k] + arg1 * 8 + 6) != 1) {
            break;
        }
        k++;
    }
    if (k < 3) {
        do {
            a[k] = a[k - 1];
            k++;
        } while (k < 3);
    }
    for (m = 0; m < 3; m++) {
        c[m + 1] = a[m] + arg1 * 8;
    }
    if (arg3 != 0) {
        p = D_800F5788 + ((((R28 *)arg0 - (R28 *)D_800F5788) + D_8009B078 - 1) % D_8009B078) * 0x28 + arg1 * 8;
        if (*(u8 *)(p + 6) == 1) {
            c[0] = p;
        }
    } else {
        arg3 = *(u16 *)(a[0] + 0x22);
        for (m = 1; m < 3; m++) {
            if (a[m - 1] != a[m]) {
                arg3 = arg3 + *(u16 *)(a[m] + 0x22);
            }
        }
    }
    q = arg4;
    r = sp48;
    for (m = 0; m < 3; m++) {
        func_8005FBC4(*(s16 *)(c[0] + m * 2), *(s16 *)(c[1] + m * 2),
                      *(s16 *)(c[2] + m * 2), *(s16 *)(c[3] + m * 2), r, 2);
        v = ((((*(s16 *)r * arg2) / arg3 + *(s16 *)(r + 2)) * arg2) / arg3
             + *(s16 *)(r + 4)) * arg2 / arg3;
        *q = *(u16 *)(r + 6) + v;
        r += 8;
        q++;
    }
}
