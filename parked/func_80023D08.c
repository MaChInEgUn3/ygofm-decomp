#include "common.h"

void func_80023D08(u8 *arg0, s32 arg1) {
    u8 *p;
    s32 t;
    s32 c;
    s32 i;
    s32 n;
    s32 m;
    u16 b;
    u8 *tb;
    s32 fl;

    p = *(u8 **)(arg0 + 4);
    if ((arg0[0x19] & 0x80) != 0) {
        if (D_8009B162 == 0) {
            func_8002348C();
            arg0[0x19] = arg0[0x19] & 0x3F;
            func_8003FEE0(6);
        }
        return;
    }
    if (arg1 < 0) {
        return;
    }
    t = arg1 & 2;
    if ((arg1 & 1) != 0) {
        c = *(s8 *)(arg0 + 0x10);
        i = c + 1;
        if (t != 0) {
            i = c - 1;
        }
        if (i >= *(s8 *)(arg0 + 0x12)) {
            return;
        }
        if (i < *(s8 *)(arg0 + 0x11)) {
            return;
        }
        n = 0x10;
        if ((c ^ i) != 3) {
            n = 8;
        }
        func_80022D94(n, 0x14E, 0x3FE, D_8009AF20[D_8009B1D5],
                      *(s16 *)(i * 2 + arg0[0x18] * 8 + D_8009B1D5 * 0x10 + D_800907AC));
        arg0[0x10] = i;
        m = i * 5 + *(s8 *)(arg0 + 0xF);
        func_800429D8(p);
        tb = D_80090800;
        p[0x6C] = 0;
        *(s16 *)(p + 0x60) = n;
        *(u16 *)(p + 0x2C) = *(u16 *)(p + 0x28);
        b = *(u16 *)(m * 4 + D_8009B1D5 * 0x50 + tb + 2);
        D_8009B162 = 0x50;
        *(u16 *)(p + 0x2E) = b;
        *(s16 *)(p + 0x3A) = (((s16)b - *(s16 *)(p + 0x2A)) << 8) / n;
        fl = arg0[0x19] | 0xC0;
    } else {
        c = *(s8 *)(arg0 + 0xF);
        i = c + 1;
        if (t != 0) {
            i = c - 1;
        }
        if ((u32)i >= 5) {
            return;
        }
        n = 8;
        arg0[0xF] = i;
        m = *(s8 *)(arg0 + 0x10) * 5 + *(s8 *)(arg0 + 0xF);
        func_800429D8(p);
        p[0x6C] = 0;
        *(s16 *)(p + 0x60) = n;
        *(volatile u16 *)(p + 0x2C) = *(u16 *)(m * 4 + D_8009B1D5 * 0x50 + D_80090800);
        *(s16 *)(p + 0x36) = ((*(s16 *)(p + 0x2C) - *(s16 *)(p + 0x28)) << n) / n;
        *(u16 *)(p + 0x2E) = *(u16 *)(p + 0x2A);
        D_8009B162 = 0x40;
        fl = arg0[0x19] | 0x80;
    }
    arg0[0x19] = fl;
}
