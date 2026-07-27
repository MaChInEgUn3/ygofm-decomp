#include "common.h"

s32 func_80019A60(s32 arg0, s32 arg1) {
    u8 *base = (u8 *)D_8017C2D8;
    u8 *p;
    s32 off;
    s32 n;
    s32 b;

    if (arg1 < arg0) {
        s32 t = arg1;
        arg1 = arg0;
        arg0 = t;
    }
    off = *(u16 *)(base + arg0 * 2);
    if (off == 0) {
        return 0;
    }
    p = base + off;
    n = p[0];
    if (n == 0) {
        n = 0x1FF - p[1];
        p++;
    }
    p++;
    do {
        b = p[0];
        if ((((b << 8) & 0x300) | p[1]) == arg1) {
            return ((b << 6) & 0x300) | p[2];
        }
        if ((((b << 4) & 0x300) | p[3]) == arg1) {
            return ((b << 2) & 0x300) | p[4];
        }
        p += 5;
        n -= 2;
    } while (n > 0);
    return 0;
}
