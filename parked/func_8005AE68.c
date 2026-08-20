#include "common.h"

typedef struct {
    s32 h;
    u16 s;
    u16 v;
} Hsv;

typedef struct {
    u8 r;
    u8 g;
    u8 b;
} Rgb3;

void func_8005A98C(Hsv *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);


s32 func_8005AE68(s32 arg0, s32 arg1, s32 arg2) {
    Rgb3 out;
    Hsv hsv;
    Rgb3 rgb;
    u32 c;
    s32 lim;
    s32 f;
    s32 h;
    u8 m;
    s32 e6;
    s32 x;
    s32 y;
    s32 a;
    s32 b;
    s32 d;

    c = arg0 & 0xFFFF;
    if (c == 0) {
        return 0;
    }

    f = arg1 & 8;
    h = arg1 & 7;
    m = h & 0xFF;
    e6 = (m == 6);
    func_8005A98C(&hsv, arg0 & 0x1F, (c >> 5) & 0x1F, (c >> 10) & 0x1F, 0x1F);

    lim = 0x1F;
    if (m < 7) {
        x = h;
        if (f != 0) {
            x = (x + 3) % 6;
        }
        hsv.h = (x & 0xFF) << 12;
    }

    if (e6) {
        hsv.v = 0;
    } else {
        y = hsv.v * (arg2 & 0xFFFF);
        hsv.v = y / 4096;
    }

    func_8005ABA0((u8 *)&rgb, hsv.h, hsv.s, hsv.v, 0x1F);

    if (f != 0) {
        rgb.r = lim - rgb.r;
        rgb.g = lim - rgb.g;
        rgb.b = lim - rgb.b;
    }

    a = rgb.r;
    if (a == 0) {
        a = 1;
    }
    rgb.r = a;
    b = rgb.g;
    if (b == 0) {
        b = 1;
    }
    rgb.g = b;
    d = rgb.b;
    if (d == 0) {
        d = 1;
    }
    rgb.b = d;

    out = rgb;
    return (out.r & 0x1F) | ((out.g & 0x1F) << 5) | ((out.b & 0x1F) << 10) | (arg0 & 0x8000);
}
