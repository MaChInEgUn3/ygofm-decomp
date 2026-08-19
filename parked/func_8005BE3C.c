#include "common.h"

s32 func_8005BE3C(void) {
    u8 buf[0x60];
    s32 v;
    s32 w;
    s32 x;
    s32 y;
    s32 r;
    s32 h;
    u8 *p;

    if (D_8009B063 != 0) {
        return 1;
    }

    if (D_8009B064 != 0) {
        if (D_8009B065 == 0) {
            return 1;
        }
        v = D_8009B065 - 0x40;
        if (v < 0) {
            v = 0;
        }
        D_8009B065 = v;
        func_80044F58((u8)v);
    }

    D_8009B062 = 0;
    func_8007FEC8(buf);

    x = *(s16 *)buf;
    p = D_8009B498;
    h = *(s16 *)(p + 0x42424);
    if (D_8009B060 != 0) {
        w = 0x1E0;
    } else {
        w = 0x140;
    }
    x = x + (w - h) / 2;
    *(s16 *)(p + 0x42428) = x;
    *(s16 *)(p + 0x42420) = x;

    p = D_8009B498;
    y = *(u16 *)(buf + 2) + (0xF0 - *(s16 *)(p + 0x42426)) / 2;
    *(s16 *)(p + 0x4242A) = y;
    *(s16 *)(p + 0x42422) = y;

    func_8008FD38(p + D_8009B066 * 0xE000 + 0x1B000, D_8009B060);
    p = D_8009B498;
    func_8008FDB4(p + D_8009B067 * 0x2D00 + 0x37000,
                  *(s16 *)(p + 0x4242C) * *(s16 *)(p + 0x4242E) / 2);

    r = func_8005BFC8(1);
    if (r != 0) {
        return r;
    }
    func_8005C5D4();
    return 0;
}
