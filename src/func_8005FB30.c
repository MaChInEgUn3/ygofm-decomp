#include "common.h"

void func_8005FB30(u8 *arg0) {
    u8 *base = arg0;
    u8 *p;
    s32 i;
    s32 o;

    if (base == 0) {
        base = (u8 *)D_8009B074;
        if (base == 0) {
            return;
        }
    }

    i = 0;
    o = 0x10;
    p = base;
    do {
        s32 v = *(s16 *)(p + 6);

        if (v < 4) {
            if (v >= 2) {
                func_80058FB0(*(s16 *)p, base + o);
            }
        }
        o += 8;
        i++;
        p += 8;
    } while (i < 2);
}
