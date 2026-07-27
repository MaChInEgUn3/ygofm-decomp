#define D_8009B0C0_IS_VOLATILE
#define D_8009B0D8_IS_SCALAR
#define D_8009AFA3_IS_AGGREGATE
#define D_8009AFA4_IS_AGGREGATE
#include "common.h"

void func_80012DB4(void) {
    s32 a;

    if (!(D_8009B098 & 0x8000)) {
        func_8007F6CC(0);
    }

    while (D_8009B0C8 < D_8009B0C0) {
    }

    D_8009B0C1 = D_8009B0C8;

    if (D_8009B0C1 != 0) {
        D_8009B0C1 = 1;
    }

    D_8009B0D8 = D_8009B0C1 + 1;

    if (D_8009AFA4[0] != 0) {
        a = 2;
    } else {
        a = (u8)D_8009B0D8;
    }

    D_8009AFA3[0] = a;
    Base2_8009AFA4[0] = 0;
    D_8009B0C8 = -1;

    func_80074170(0);

    D_8009B0CC = D_8009B0CC + 1;
}
