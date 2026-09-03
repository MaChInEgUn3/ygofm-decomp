#include "common.h"

void func_8003F454(void) {
    u8 *p;
    s32 f;
    s32 t;
    s32 u;
    s32 c;
    s32 n;

    f = D_8009B3FA;
    if ((f & 0x800) != 0) {
        if (D_8009B3D8 == (u8 *)0) {
            D_8009B3FA = 0;
            return;
        }
        if (func_8003F2B0(D_8009B3D8, 0x20, 0x100, D_8009B3EE) == 0) {
            func_80035B7C((u8 *)D_800EB0F8 + D_8009B3EE * 100);
            func_8004036C((s32)D_8009B3D8);
            D_8009B3D8 = (u8 *)0;
        }
        return;
    }
    if ((f & 0x4080) == 0x4080) {
        if ((f & 0x40) == 0) {
            D_8009B3FA = f | 0x40;
            p = func_80035BE4(D_8009B3EE, D_8009B3C6, 0x20, 0x50, 0x100, 0x30);
            func_8002E370(p);
            p[0x59] = 0x10;
            if ((D_8009B3FA & 0x20) != 0) {
                do {
                    func_80039794();
                } while (*(s32 *)(p + 0x30) == 0);
                return;
            }
            if ((D_8009B3FA & 0x10) != 0) {
                *(u16 *)(p + 0x34) = *(u16 *)(p + 0x34) | 0x1008;
                return;
            }
            func_80039A14(p);
            goto b14;
        }
        func_80039794();
        p = (u8 *)D_800EB0F8 + D_8009B3EE * 100;
        if ((*(s32 *)(p + 0x34) & 0x2008) != 0x2000) {
            return;
        }
    b14:
        t = D_8009B3FA;
        u = t & 8;
        D_8009B3FA = t & 0xFF7F;
        if (u == 0) {
            return;
        }
        D_8009B3FA = 0;
        goto b25;
    }
    if ((f & 0x4000) == 0) {
        if ((f & 0x2000) == 0) {
            D_8009B3FA = f | 0x2000;
            func_8008B85C();
            D_8009B3EF = 2;
            func_8003F388();
            *(s16 *)(D_8009B3D8 + 0x60) = -0x400;
            return;
        }
        if (func_8003F2B0(D_8009B3D8, 0x20, 0x50, -1) == 0) {
            D_8009B3FA = D_8009B3FA | 0x4000;
        }
        return;
    }
    if ((f & 0x1000) != 0) {
        c = func_8008CCE8(1, &D_8009B3F0, &D_8009B3F4);
        D_8009B3BC = c;
        if (c != 1) {
            return;
        }
        D_8009B3FA = D_8009B3FA & 0xEFFF;
    }
    D_80090F9C[D_8009B3DE]();
    if (D_8009B3FA != 0) {
        return;
    }
b25:
    D_8009B3FA = D_8009B3FA | 0x800;
    *(s16 *)(D_8009B3D8 + 0x60) = 0x400;
    func_8008B8CC();
}
