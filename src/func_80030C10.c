#include "common.h"

void func_80030C10(void) {
    u8 v = D_8009B2EB;
    s32 r;

    if (!(v & 0x80)) {
        D_8009B2EB = v | 0x80;
        D_8009B2C8 = D_8009B2E8;
        func_80030250((s32)D_80090D0C, 0x14, 0, 0, 0xC, 2, 1);
    }

    r = func_80030294();
    if (r != 0) {
        if (r < 0) {
            D_8009B2EB = 0;
        } else {
            D_8009B363[0] = 0;
            D_8009B26C[0] = 5;
            D_8009B2E8 = D_8009B2C8;
        }
    }
}
