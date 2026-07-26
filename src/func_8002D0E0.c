#define D_8009B26C_IS_SCALAR
#include "common.h"

void func_8002D0E0(void) {
    u8 v = D_8009B26C;

    if (!(v & 0x40)) {
        D_8009B26C = v | 0x40;
        func_8002BFCC();
        func_80015A00();
    } else {
        func_8002BAB4();
        if (!(D_8009B26C & 0x40)) {
            D_8009B0C0[0] = 0;
            func_8003FF34();
            func_80015B00();
            func_800134B4();
            func_8004763C();
            func_80047AD0(2);
            func_80012D84(4);
            func_800137E4();
        }
    }
}
