#include "common.h"

void func_80053248(volatile s32 a, volatile s32 b, s32 c, s32 d, s32 e, s32 f) {
    u8 *p;
    if (b >= 0) {
        p = D_800F2C40;
        *(s16 *)(p + a * 3616 + 0xDF8) = b;
        D_8009B488[a] = b;
    }

    if (a < 2) {
        if (c >= 0) {
            p = D_800F2C40;
            *(s16 *)(p + a * 3616 + 0xDFA) = c;
        }
        if (d >= 0) {
            p = D_800F2C40;
            *(s16 *)(p + a * 3616 + 0xDFC) = d;
        }
        if (e >= 0) {
            p = D_800F2C40;
            (p + a * 3616)[0xDFE] = e != 0;
            D_8009B48E[a] = e != 0;
        }
        if (f >= 0) {
            p = D_800F2C40;
            (p + a * 3616)[0xDFF] = f != 0;
            D_8009B490[a] = f != 0;
        }
    } else {
        D_8009AF88 = D_80091008 + D_800F5678[0] * 178;
    }

    D_8009AF94 = 0xF;
}
