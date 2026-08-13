#include "common.h"

void func_8005F27C(s32 arg0, s32 arg1, s32 arg2) {
    u8 *r;
    s32 v;
    s32 d;
    s32 t;
    s32 k;
    u8 sp18[8];

    r = D_80091570 + arg1 * 8;

    if (D_8009B07B == 1) {
        if (D_8009B07C == 1) {
            return;
        }
    }

    v = (s16)*(u16 *)r;

    if (arg0 < 2) {
        func_80059000(arg0, sp18);
        if (*(s16 *)(sp18 + 6) < 0x32) {
            *(s16 *)(sp18 + 6) = 0x32;
        }
        *(s16 *)(sp18 + 6) = *(u16 *)(sp18 + 6) - 0x12C;
        d = *(s16 *)(sp18 + 6);
        if (d != 0) {
            k = 750;
            t = v;
            if (d > 0) {
                t = v / 2;
            }
            t = d * t;
            v += t / k;
        }
    }

    func_8005F3B8(arg0, v, *(s16 *)(r + 2), *(s16 *)(r + 4), arg2);
}
