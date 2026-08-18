#include "common.h"

s32 func_8002C7E8(s32 arg0, s32 arg1) {
    u8 *out[3];
    u8 *sl[5];
    u8 *t;
    u8 *r;
    u8 *e;
    s32 i;
    s32 j;
    s32 n;
    s32 k;

    t = D_801799D8;

    while (1) {
        if (*(u16 *)t == 0) {
            return 0;
        }
        if (*(u16 *)t == arg1) {
            break;
        }
        t += 0xA;
    }

    k = 5;
    if (D_8009B1D5 != 0) {
        k = 0x14;
    }

    r = D_801A7AD8 + k * 28;

    for (i = 0; i < 5; i++) {
        sl[i] = (u8 *)0;
        if ((*(u16 *)(r + 0x16) & 0x8000) != 0) {
            sl[i] = r;
        }
        r += 0x1C;
    }

    t += 2;

    for (n = 0; n < 3; n++) {
        for (j = 0; j < 5; j++) {
            e = sl[j];
            if (e != 0) {
                if (*(s16 *)(e + 0xC) == *(u16 *)(t + n * 2)) {
                    goto found;
                }
            }
        }
        return 0;
    found:
        out[n] = e;
        sl[j] = (u8 *)0;
    }

    if (arg0 != 0) {
        for (i = 0; i < 3; i++) {
            *(s32 *)(arg0 + i * 4) = *(s32 *)out[i];
        }
        *(s32 *)(arg0 + 0xC) = 0;
    }

    return *(u16 *)(t + 6);
}
