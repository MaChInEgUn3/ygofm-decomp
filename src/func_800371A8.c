#include "common.h"

void func_80037110(u8 *arg0);

void func_800371A8(u8 *p) {
    u8 *e;
    s32 f;
    s32 g;
    s32 m;

    if ((p[0x51] & 0x80) == 0) {
        p[0x51] = p[0x51] | 0x80;
        e = func_800400AC(func_8004006C(), 4);
        func_800427DC(e, 1);
        func_80042918(e);
        func_800428EC(e, (s8)(*(*(u8 **)(p + 0x28) + 0x16) + 1));
        *(s32 *)(p + 0x30) = (s32)e;
        *(s32 *)(e + 0x54) = 0x2000;
        *(s32 *)(e + 0x4C) = 0x2000;
        *(s32 *)(e + 0x34) = 0x2000;
        *(s32 *)(e + 0x2C) = 0x2000;
        *(s32 *)(e + 0x44) = 0xC000;
        *(s32 *)(e + 0x3C) = 0xC000;
        *(s32 *)(e + 0x24) = (s32)func_80037110;
        *(s32 *)(e + 4) = *(s32 *)(e + 4) | 0x50000000;
        func_80036F80(p);
    }

    if ((*(u16 *)(p + 0x34) & 4) != 0) {
        return;
    }

    f = *(s8 *)&D_8009B327;
    g = D_8009B327;

    if (f != 0) {
        if ((g & 0x40) != 0) {
            D_8009B327 = g & 0xBF;
            D_8009B34D = g & 7;
            func_80036F80(p);
            return;
        }
        if ((f & 0x80) == 0) {
            return;
        }
        D_8009B327 = 0;
    } else {
        if (func_8003700C(p) != 0) {
            return;
        }
        if ((D_8009B398 & 0xC0) == 0) {
            return;
        }
    }

    m = 1 << D_8009B34D;
    if ((D_8009B336 & m) == 0) {
        func_8003FEE0(9);
        return;
    }

    p[0x51] = 0;
    func_8003FEE0(7);
    if ((D_8009B34C & 0x40) == 0) {
        func_8004036C(*(s32 *)(p + 0x30));
        *(s32 *)(p + 0x30) = 0;
        p[0x51] = 3;
    }
}
