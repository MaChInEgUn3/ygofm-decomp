#include "common.h"

void func_80032370(void) {
    s16 *t = (s16 *)D_801D07BC;
    u8 *m = (u8 *)t - 0x56C;
    s16 *w;
    s32 i;

    for (i = 15; i >= 0; i--) {
        s32 v = t[i];

        if (v != 0 && m[v - 1] == 0) {
            t[i] = 0;
        }
    }

    w = t;

    for (i = 0; i < 0x10; i++) {
        if (*t != 0) {
            if (t != w) {
                *w = *(u16 *)t;
                *t = 0;
            }
            w++;
        }
        t++;
    }
}
