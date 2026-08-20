#include "common.h"

u8 *func_8005B0B4(u8 *out, u8 r, u8 g, u8 b, s32 mode, u16 scale, u8 lvl) {
    u8 hsv[8];
    u8 rgb[4];
    s32 k;
    s32 m;
    s32 t;
    s32 h;
    s32 c;
    s32 d;
    s32 e;
    s32 f;
    s32 g2;
    s32 h2;

    m = mode & 8;
    k = mode & 7;
    t = ((u8)k == 6);

    func_8005A98C(hsv, r, g, b, lvl);

    if ((u8)k < 7) {
        h = k;
        if (m != 0) {
            h += 3;
            h %= 6;
        }
        *(s32 *)hsv = (h & 0xFF) << 12;
    }

    if (t != 0) {
        *(s16 *)(hsv + 6) = 0;
    } else {
        *(s16 *)(hsv + 6) = *(u16 *)(hsv + 6) * scale / 4096;
    }

    func_8005ABA0(rgb, *(s32 *)hsv, *(u16 *)(hsv + 4), *(u16 *)(hsv + 6), lvl);

    if (m != 0) {
        rgb[0] = lvl - rgb[0];
        rgb[1] = lvl - rgb[1];
        rgb[2] = lvl - rgb[2];
    }

    c = rgb[0];
    if (c == 0) {
        c = 1;
    }
    rgb[0] = c;
    d = rgb[1];
    if (d == 0) {
        d = 1;
    }
    rgb[1] = d;
    e = rgb[2];
    if (e == 0) {
        e = 1;
    }
    rgb[2] = e;

    out[0] = *(s8 *)(rgb + 0);
    out[1] = *(s8 *)(rgb + 1);
    out[2] = *(s8 *)(rgb + 2);
    return out;
}
