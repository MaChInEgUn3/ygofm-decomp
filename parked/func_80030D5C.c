#define D_8009B0F4_SIZED_VOLATILE
#define D_8009B0F4_IS_AGGREGATE
#include "common.h"

void func_80030D5C(void) {
    u8 v = D_8009B2EB;
    u8 f;

    if (!(v & 0x80)) {
        D_8009B2EB = v | 0x80;
        D_8009B2C8 = 0;
        func_80030250((s32)D_80090D44, 0x1D, 0, 0, 5, 2, 1);
    }

    f = D_8009B2EB;

    if (f & 0x40) {
        if (D_8009B0F4[0] & 0x2000000) {
            return;
        }

        D_8009B2EB = f & 0xBF;
    } else {
        s32 r = func_80030294();

        if (r == 0) {
            return;
        }

        if (r < 0) {
            D_8009B2EB = 0;

            return;
        }

        func_8003594C(D_8009B2C8);
        D_8009B2EB = D_8009B2EB | 0x40;
    }
}
