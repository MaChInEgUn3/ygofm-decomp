#define D_8009B394_IS_VOLATILE
#define D_8009B398_IS_VOLATILE
#include "common.h"

void func_80031084(void) {
    u8 *b;
    s32 i;
    s8 d;
    s32 one;
    s32 k;
    s32 e;
    s32 t;

    func_8008E590();
    e = D_8009B2EB;
    i = 0;
    if (e != 0) {
        if (D_8009B2F0 != 0) {
            D_80090D7C[e & 0x1F]();
        } else {
            D_80090D84[e & 0x1F]();
        }
        return;
    }
    for (; i < 0x16; i++) {
        func_8007EF84(D_8009AF54);
    }
    if ((D_8009B394 & 0xF000) != 0) {
        if ((D_8009B394 & 0xA000) != 0) {
            if ((D_8009B394 & 0x2000) != 0) {
                if (D_8009B2F1 + 0xA < 0x14) {
                    D_8009B2F1 = D_8009B2F1 + 0xA;
                }
            } else {
                if (D_8009B2F1 - 0xA >= 0) {
                    D_8009B2F1 = D_8009B2F1 - 0xA;
                }
            }
        }
        if ((D_8009B394 & 0x1000) != 0) {
            t = (u8)D_8009B2F1;
            if (D_8009B2F1 >= 0xA) {
                d = t - 1;
                D_8009B2F1 = d;
                if (d < 0xA) {
                    D_8009B2F1 = 0x13;
                }
            } else {
                d = t - 1;
                D_8009B2F1 = d;
                if (d < 0) {
                    D_8009B2F1 = 9;
                }
            }
        }
        if ((D_8009B394 & 0x4000) != 0) {
            t = (u8)D_8009B2F1;
            if (D_8009B2F1 >= 0xA) {
                d = t + 1;
                D_8009B2F1 = d;
                if (d >= 0x14) {
                    D_8009B2F1 = 0xA;
                }
            } else {
                d = t + 1;
                D_8009B2F1 = d;
                if (d >= 0xA) {
                    D_8009B2F1 = 0;
                }
            }
        }
        func_800300C8();
    }
    if ((D_8009B398 & 0x20) != 0) {
        k = 0x13;
        if (D_8009B2F1 != k) {
            D_8009B2F1 = k;
            func_800300C8();
            return;
        }
        D_8009B2EB = 0x14;
        return;
    }
    if ((D_8009B398 & 0x100) != 0) {
        one = 1;
        func_8003B6AC(one, one);
        D_8009B2F0 = D_8009B2F0 ^ one;
        func_80035BE4(1, D_8009B2F0 + 0xF, 0x10, 0x10, 0x120, 0xA0);
        b = (u8 *)D_800EB0F8;
        b[0xBE] = 0x10;
        b[0xBF] = 0x10;
        func_80039A14(b + 0x64);
        return;
    }
    if ((D_8009B398 & 0xC0) != 0) {
        D_8009B2EB = D_8009B2F1 + 1;
    }
}
