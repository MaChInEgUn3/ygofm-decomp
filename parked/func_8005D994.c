#include "common.h"

u8 *func_80059208(void);

void func_8005D994(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u8 *arg4,
                   s32 arg5) {
    u16 a[4];
    u16 b[4];
    u8 *s;
    s32 one;
    s32 m;
    s32 t;
    s32 q;
    s32 x;
    s32 first;

    s = func_80059208();
    func_8008E3D0(a, 0, 8);
    a[3] = arg0 | 0x80;
    one = 1;

    if (D_8009B07B == one && D_8009B07C == one) {
        return;
    }

    if (arg0 == 2) {
        func_80058FB0(2, (u8 *)a);
        a[3] = one;
    }

    if (arg4 != (u8 *)0) {
        m = -1;
        if (arg0 <= 0) {
            m = 1;
        }
        a[0] = a[0] + *(s16 *)(arg4 + 0) * m;
        a[1] = a[1] + *(u16 *)(arg4 + 2);
        a[2] = a[2] + *(s16 *)(arg4 + 4) * m;
    }

    b[0] = arg1;
    x = *(s16 *)(s + 2);
    t = arg2 + 0x1000;
    if (arg0 <= 0) {
        x = x - 0xC00;
    } else {
        x = x - 0x400;
    }
    b[1] = (t - x) - (t - x) / 0x1000 * 0x1000;
    if (*(s16 *)&b[1] >= 0x801) {
        b[1] = b[1] - 0x1000;
    }
    if (*(s16 *)&b[1] < -0x800) {
        b[1] = b[1] + 0x1000;
    }

    q = arg3 + 0x1000;
    b[2] = (q - q / 0x1000 * 0x1000) - *(u16 *)(s + 4);
    if (*(s16 *)&b[2] >= 0x801) {
        b[2] = b[2] - 0x1000;
    }
    if (*(s16 *)&b[2] < -0x800) {
        b[2] = b[2] + 0x1000;
    }

    x = *(s8 *)&D_8009B07A;
    b[3] = 4;
    if (x < 0) {
        first = 0;
    } else {
        D_8009B07A = D_8009B07A + 1;
        first = x > 0;
    }
    func_8005F91C(first, (u8 *)b, (u8 *)a, arg5);
}
