#define D_8009B398_SIZED_VOLATILE
#include "common.h"

void func_80030090(void);
void func_800300AC(void);
void func_80014FA4(void);
void func_8003FFFC(void);
void func_8003FFB4(s32 arg0);
void func_8003FF88(s32 arg0);

void func_800307B8(void) {
    s32 f;
    s32 n;
    s32 v;

    f = D_8009B2EB;
    if ((f & 0x80) == 0) {
        D_8009B2EB = f | 0x80;
        n = 3;
        func_80030090();
        D_8009B2C8 = D_8009B2C4;
        D_8009B2CA = D_8009B2DA;
        D_8009B2CC = D_8009B2C6;
        func_80030250((s32)D_80090CB4, 0x11, 0x19, 0x21, 9, 4, n);
        D_8009B2C2 = n;
        D_8009B2C1 = n;
        return;
    }

    if ((D_8009B398[0] & 0x800) != 0) {
        func_8003FFFC();
        return;
    }

    if ((D_8009B398[0] & 0x100) != 0) {
        func_80014FA4();
        return;
    }

    v = func_80030294();
    if (v == 0) {
        return;
    }
    if (v < 0) {
        D_8009B2EB = 0;
        func_800300AC();
        return;
    }

    switch (*(s8 *)&D_8009B2DC) {
    case 0:
        D_8009B2C4 = D_8009B2C8;
        if (*(s8 *)&D_8009B2E9 == 3) {
            func_8004763C();
            func_80047AD0((u16)((s16)D_8009B2C4 >> 12));
            return;
        }
        func_8003FEE0(D_8009B2C8 & 0xFFF);
        return;
    case 1:
        D_8009B2DA = D_8009B2CA;
        func_8003FF08(D_8009B2CA);
        return;
    case 2:
        D_8009B2C6 = D_8009B2CC;
        if ((D_8009B398[0] & 0x80) != 0) {
            func_8003FFB4((u16)D_8009B2CC);
            return;
        }
        func_8003FF88(D_8009B2CC);
        return;
    }
}
