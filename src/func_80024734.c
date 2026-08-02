#include "common.h"

void func_80024734(void) {
    u8 *p = D_8017808C;
    u8 *q;
    u8 *r;
    s32 i;
    s32 last;
    s32 n;
    u8 *t;
    s32 v;

    func_800356A0(p, p - 0xA4, 0xA0);
    func_8008E400(p, 0x50, 2, func_80024704);

    q = p + 0xA4;
    last = 0;
    for (i = 0; i < 0x50; i++) {
        v = *(u16 *)p;
        if (v != last) {
            *(u16 *)q = v;
            last = v;
            q += 2;
        }
        p += 2;
    }

    *(u16 *)q = 0xFFFF;
    t = D_8015C424;
    n = *(u16 *)(t + 0x1BD0C);
    r = func_80014EEC(0, (u8 *)0, n - 1, last - n + 1, func_800245EC, 0, 0);
    *(s32 *)(r + 0x38) = (s32)D_80178130;
    *(s32 *)(r + 0x3C) = (s32)t;
    D_8009B0F4 = *(s32 *)(r + 0x2C) | 0x10;
}
