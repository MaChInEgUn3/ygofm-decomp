#include "common.h"

void func_8005F7B0(s32 arg0, s32 arg1) {
    s16 buf[4];
    s32 t;
    s32 f;

    buf[0] = arg0;
    buf[1] = 0;
    buf[2] = 0;
    buf[3] = 5;

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

    func_8005F91C(f, buf, buf, arg1);
}
