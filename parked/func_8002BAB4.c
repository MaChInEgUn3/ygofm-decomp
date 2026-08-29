#include "common.h"

void func_8002BAB4(void) {
    u8 *p;
    u8 *q;
    u8 *o;
    s32 one;
    s32 r;
    s32 d;
    s32 v;
    s32 t;

    p = D_800EA1E8;
    one = 1;
    switch (p[0] & 0xF) {
    case 0:
        func_8002BAA0(p);
        return;

    case 1:
        func_8002A788(p);
        return;

    case 2:
        func_8002ACA4(p);
        q = D_800F2848;
        r = func_80058DD8(0);
        if (r == one) {
            if (func_80058E68(0) != r) {
                func_80058FB0(0, (u8 *)0x80181010);
                d = D_80181012 - D_80181002;
                v = d;
                if (d < 0) {
                    v = -v;
                }
                v = v / 24 + 1;
                if (D_80181012 < *(s32 *)(q + 0x20)) {
                    *(s32 *)(q + 0x20) = *(s32 *)(q + 0x20) - v;
                }
                if (*(s32 *)(q + 0x20) < D_80181012) {
                    *(s32 *)(q + 0x20) = *(s32 *)(q + 0x20) + v;
                }
            } else {
                d = *(s32 *)(q + 0x20);
                t = D_80181002;
                if (d != t) {
                    if (t < d) {
                        d = d - 8;
                        v = d < t;
                    } else {
                        d = d + 8;
                        v = t < d;
                    }
                    if (v != 0) {
                        d = t;
                    }
                    *(s32 *)(q + 0x20) = d;
                }
                v = *(s32 *)(p + 0x20) - 1;
                *(s32 *)(p + 0x20) = v;
                if (v <= 0) {
                    *(s32 *)(p + 0x20) = 0x12C;
                    d = 2;
                    if ((func_8008E590(0) & 1) != 0) {
                        d = 7;
                    }
                    func_80057AF4(0, d, 1);
                }
            }
        }
        *(u16 *)(D_800F2848 + 2) = *(u16 *)(D_800F2848 + 2) + 0xC;
        func_8001352C();
        o = (u8 *)func_800591FC();
        *(Words8 *)o = *(Words8 *)(q + 0x10);
        func_80057F38(0);
        return;

    case 3:
        func_8002BAAC(p);
        return;
    }
}
