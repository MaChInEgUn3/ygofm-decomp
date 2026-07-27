#include "common.h"

void func_80030CB0(void) {
    u8 v = D_8009B2EB;
    s32 r;

    if (!(v & 0x80)) {
        D_8009B2EB = v | 0x80;
        D_8009B2C8 = D_8009B26D[0];
        func_80030250((s32)D_80090D28, 0x15, 0, 0, 0x12, 2, 1);
    }

    r = func_80030294();

    if (r != 0) {
        if (r < 0) {
            D_8009B2EB = 0;
        } else {
            D_8009B268[0] = 1;
            D_8009B26C[0] = 8;
            D_8009B26D[0] = D_8009B2C8;
        }
    }
}
