#define D_8009B0F4_IS_AGGREGATE
#define D_8009B134_IS_AGGREGATE
#include "common.h"

void func_800137E4(void) {
    s32 f = D_8009B0F4[0];

    f &= 0x2000030;
    f |= D_8009B134[0];

    if (f != 0) {
        do {
            if (!(Base2_8009B0F4[0] & 0x20)) {
                func_80015038();
            }

            func_80012D4C();
            f = Base3_8009B0F4[0];
            f &= 0x2000030;
            f |= Base2_8009B134[0];
        } while (f != 0);
    }

    while (D_8009B134[0] != 0) {
        func_80012D4C();
    }
}
