#define D_8009B450_IS_SCALAR
#include "common.h"

s32 func_80044608(void) {
    s32 c;
    switch (D_8009B43D) {
    case 0:
        switch (D_8009B450) {
        case 1:
            c = D_8009B43C - 1;
            D_8009B43C = c;
            if ((s8)c != 0) {
                func_80043D48(D_800F2AE0);
                func_8008B330(D_8009B437);
                return -1;
            }
            break;

        case 0:
            if ((*(u8 *)&D_8009B44E & 0x80) == 0 || D_8009B43E == 8) {
                D_8009B450 = 3;
                goto arm3;
            }
            break;

        case 2:
            break;

        case 3:
        arm3:
            if (D_8009B43E != 1) {
                D_8009B43C = 0xA;
                D_8009B43D = D_8009B43D + 1;
                func_80043D48(D_800F2AF0);
                func_8008B3A0(D_8009B437);
                return -1;
            }
            break;
        }
        break;

    case 1:
        if (D_8009B450 == 0) {
            D_8009B43C = 0xA;
            D_8009B43D = 2;
        shared340:
            func_80043D48(D_800F2AE0);
            func_8008B340(D_8009B437);
            return -1;
        }
        if (D_8009B450 == 2) {
            D_8009B43C = D_8009B43C - 1;
            if ((s8)D_8009B43C > 0) {
                func_80043D48(D_800F2AF0);
                func_8008B3A0(D_8009B437);
                return -1;
            }
        }
        break;

    case 2:
        if (D_8009B450 == D_8009B43D) {
            c = D_8009B43C - 1;
            D_8009B43C = c;
            if ((s8)c > 0) {
                goto shared340;
            }
        }
        *(u8 *)&D_8009B44E = *(u8 *)&D_8009B44E | 0x80;
        if (D_8009B450 == 0) {
            D_8009B444 = (s32)D_800F2888;
            func_80044470(D_8009B437, D_8009AF7C, D_800F2888, &D_8009B440);
            D_8009B438 = func_80044544(D_8009B444, D_8009B440);
        }
        if (D_8009B450 == 3) {
            D_8009B450 = 4;
        }
        break;
    }
    return D_8009B450;
}
