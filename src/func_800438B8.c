#define D_8009B0F4_IS_AGGREGATE
#define D_8009B134_IS_AGGREGATE
#define D_8009B398_IS_AGGREGATE
#include "common.h"

void func_800438B8(s32 arg0) {
    s32 flag = 0;

    while (1) {
        func_80012D4C();

        if (flag == 0) {
            s32 f = D_8009B0F4[0];

            f &= 0x2000030;
            f |= D_8009B134[0];

            if (f == 0) {
                flag = 1;
            }
        }

        if ((D_8009B398[0] & 0x8C0) != 0 && flag != 0) {
            arg0 = 0;
        }

        arg0--;

        if (arg0 < 0) {
            arg0 = 0;

            if (flag != 0) {
                return;
            }
        }
    }
}
