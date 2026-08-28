#define D_8009B0AC_SIZED8
#define D_8009B0F4_SIZED
#define D_8009B134_SIZED
#define D_8009B145_SIZED8
#define D_8009B146_SIZED
#include "common.h"

void func_8002E00C(u8 *arg0);
void func_8002DF2C(u8 *arg0, s32 arg1);
void func_8002E128(u8 *arg0, s32 arg1);
void func_80015C84(void);
void func_80015C0C(void);

void func_8002E730(void) {
    u8 *e;
    u8 *t;
    u8 *u;
    s32 f;

    u = D_8009B0AC;
    if (func_8002E3B4() == 0) {
        D_800E9D70[0] = 0;
        D_800E9D70[1] = 0;
        D_800E9D70[2] = 0x140;
        D_800E9D70[3] = 0xA0;
        if (u[0] == 0) {
            D_800E9D70[0] = 0x140;
        }
        func_8007FA38(D_800E9D70, 0x1C0, 0x100);
        return;
    }

    if (((D_8009B0F4[0] & 0x2000030) | D_8009B134[0]) != 0) {
        return;
    }
    if ((D_800E9ECE[0] & 0x80) != 0) {
        return;
    }

    f = D_8009B27C;
    if ((f & 0x4000) == 0) {
        D_8009B27C = f | 0x4000;
        e = func_800400AC(func_8004006C(), 3);
        func_80040510(e, 0, 0, 0x140, 0xA0, 0, 0, 0x17, 0, 0xF4);
        t = D_800EAE98;
        do {
            D_8009B280 = e;
        } while (0);
        *(s32 *)(e + 4) = *(s32 *)(e + 4) | 0x2000000;
        func_8002E00C(t);
        D_8009B146[0] = D_8009B2A8;
        D_8009B148[0] = D_8009B2AA;
        if (D_8009B145[0] == 0) {
            func_80015C84();
        }
        func_8002DF2C(t, D_8009B270 & 0xFFF);
        return;
    }

    if ((f & 0x2000) == 0) {
        D_8009B27C = f | 0x2000;
        func_8004036C((s32)D_8009B280);
        func_8002E128(D_800EAE98, -1);
        if (D_8009B145[0] == 0) {
            if ((D_8009B270 & 0x4000) == 0) {
                func_80015C0C();
            }
        }
    } else {
        D_8009B27C = 0;
    }
}
