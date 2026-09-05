#define D_8009B26C_IS_SCALAR
#define D_8009B0C0_SIZED
#define D_801D0534_IS_AGGREGATE
#include "common.h"

void func_800878B0(s32 arg0, s32 arg1);
void func_8003F87C(void);
s32 func_8003F70C(void);
void func_80039794(void);
void func_80059C9C(void);
void func_80059CD0(void);
void func_80059CE4(void);

void func_8002DA1C(void) {
    u8 *b;
    u8 *r;
    u16 *e;
    u16 *t;
    s32 one;
    s32 i;
    s32 v;
    s32 f;
    s32 m;

    func_800878B0(0xA0, 0x78);
    func_800878D0(0x12C);

    v = D_8009B26C;
    if ((v & 0x40) == 0) {
        D_8009B26C = v | 0x40;
        func_80015780();
    init:
        b = D_801D0200;
        *(s16 *)(b + 0x5DC) = 0x30;
        for (i = 0x20; i < 0x120; i++) {
            func_8002CCE4(i | 0x8000);
        }
        D_8009B26E = 0;
        b[0x3DE] = b[0x3DE] | 3;
    }

    f = D_8009B26E;
    one = 1;
    m = f & 0xF;

    if (m == one) {
        goto m1;
    }
    if (m < 2) {
        if (m == 0) {
            goto m0;
        }
        return;
    }
    if (m == 2) {
        goto m2;
    }
    return;

m0:
    if ((f & 0x80) == 0) {
        D_8009B26E = f | 0x80;
        func_8003F87C();
    }
    f = func_8003F70C();
    if (f == 0) {
        return;
    }
    if (f == 2) {
        goto init;
    }
    D_8009B26E = one;
    return;

m1:
    if ((f & 0x80) == 0) {
        D_8009B26E = f | 0x80;
        f = D_801D0534[0] % 5;
        t = D_80090B50;
        e = &t[f * 2];
        D_801D5608[0] = e[0];
        D_801D5608[1] = e[1];
        func_80035C38(0, 0x23, 0x10, 0x70, 0x120, 0x20, 8);
    }
    func_80039794();
    r = (u8 *)D_800EB0F8;
    if ((*(u16 *)(r + 0x34) & 8) == 0) {
        func_80035B7C(r);
        D_8009B26E = 2;
    }
    return;

m2:
    if ((f & 0x80) == 0) {
        D_8009B26E = f | 0x80;
        D_8009B0C0[0] = one;
        func_800530C4();
        func_800533D8();
        func_80059C9C();
        return;
    }
    func_80059CD0();
    func_80059CE4();
}
