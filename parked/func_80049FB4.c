#include "common.h"

/* NOT a near miss -- 74 differences, correct length. This is the decode
 * parked so it is not redone: the arithmetic is settled and only the
 * shapes are open. See docs/PARKED.txt. */

u16 func_80049FB4(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s16 n;
    s32 r;
    s16 d;
    s16 m;
    s16 j;
    s32 q;
    s32 k;

    n = arg1 + arg3;
    q = n / 128;
    r = n % 128;
    d = arg0 + q - arg2;

    if (d < 0) {
        m = -d;
        j = m % 12;
        k = (12 - j) % 12;
        return D_80010834[k * 128 + r] >> ((m + 11) / 12);
    }

    j = d % 12;
    return D_80010834[j * 128 + r] << (d / 12);
}
