#include "common.h"

void func_8005F714(s32 arg0, s32 arg1, s32 arg2) {
    u8 *a;
    u8 *b;
    s32 t;
    s32 f;

    if (arg0 >= 0) {
        a = &D_80091550[arg0 * 8];
    } else {
        a = 0;
    }

    if (arg1 >= 0) {
        b = &D_80091550[arg1 * 8];
    } else {
        b = 0;
    }

    if (D_8009B07B == 1 && D_8009B07C == 1) {
        return;
    }

    t = D_8009B07A;
    if (t < 0) {
        f = 0;
    } else {
        D_8009B07A = (u8)D_8009B07A + 1;
        f = t > 0;
    }

    func_8005F91C(f, a, b, arg2);
}
