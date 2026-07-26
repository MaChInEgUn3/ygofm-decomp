#include "common.h"

s32 func_8004C560(u8 *arg0) {
    s32 *p = (s32 *)arg0;
    s32 v = func_8004BBBC(p[0]);

    p[0] = v;

    if (v == -1) {
        return 1;
    }

    p[2] = func_8004BC2C(arg0);

    {
        s32 t = p[0];

        p[4] = t;
        t += p[2];
        p[3] = t;
    }

    return 0;
}
