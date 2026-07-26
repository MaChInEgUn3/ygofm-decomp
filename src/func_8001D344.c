#include "common.h"

void func_8001D344(u8 *arg0) {
    s32 step = *(s16 *)(arg0 + 0x60);
    s32 remaining = 3;
    s32 i = 0;
    u8 *p = arg0 + 0xC;
    u8 *q = arg0;

    for (; i < 3; i++) {
        s32 c = *p;
        s32 t = *(s16 *)(q + 0x28);

        if (c < t) {
            c += step;
            if (c >= t) {
                c = t;
                remaining--;
            }
        } else {
            c -= step;
            if (c <= t) {
                c = t;
                remaining--;
            }
        }
        *p = c;
        p++;
        q += 2;
    }

    if (remaining == 0) {
        arg0[0x6C] = 0;
        *(s32 *)(arg0 + 0x24) = 0;
    }
}
