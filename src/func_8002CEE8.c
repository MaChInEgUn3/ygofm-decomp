#define D_8009B26C_IS_SCALAR
#define D_8009B0A3_IN_DATA
#define D_8009B2F8_IN_DATA
#define D_8009B27A_IN_DATA
#define D_80010000_IN_DATA
#define D_8009B362_IN_DATA
#define D_8009B370_SIZED8
#define D_8009B369_IN_DATA
#include "common.h"

void func_8002CEE8(void) {
    s32 one;
    s32 mode;
    s32 v;
    s32 f;

    f = D_8009B26C;
    if ((f & 0x40) == 0) {
        D_8009B26C = f | 0x40;
        D_8009B26E = 1;
        if (D_8009B369 == 0 && D_8009B361[0] >= 0) {
            D_8009B26E = 0;
        }
        D_8009B0A3 = 0xA;
        return;
    }

    one = 1;
    v = D_8009B26E;
    mode = v & 0xF;

    if (mode == one) {
        goto m1;
    }
    if (mode < 2) {
        if (mode == 0) {
            goto m0;
        }
        return;
    }
    if (mode == 2) {
        goto m2;
    }
    return;

m0:
    if ((v & 0x80) == 0) {
        D_8009B26E = v | 0x80;
        D_8009B2F8 = 0x80;
        func_800323F8(D_80010000, D_801D0200, 0, 0x80);
        func_80015A00();
        return;
    }
    if (func_80033BE8() != 0) {
        return;
    }
    func_8003FF34();
    func_80015B00();
    func_8002CD8C();
    D_8009B26E = one;
    return;

m1:
    if ((v & 0x80) == 0) {
        D_8009B26E = v | 0x80;
        func_800179F4();
        return;
    }
    func_80024388();
    if ((D_8009B16C & 0x2000) != 0) {
        D_8009B26E = 2;
    }
    return;

m2:
    func_80015B00();
    func_8003FF34();
    func_80047AD0(2);
    func_800134B4();
    D_8009B0A3 = 6;
    func_80012D84(4);
    func_800137E4();
    D_8009B26C = D_8009B368[0];
    if (D_8009B26C != mode) {
        return;
    }
    D_8009B27A = *(u8 *)&D_8009B370[D_8009B362];
}
