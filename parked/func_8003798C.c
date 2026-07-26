#define D_8009B0F4_IS_AGGREGATE
#define D_8009B134_IS_AGGREGATE
#include "common.h"

void func_8003798C(u8 *arg0) {
    s32 f = D_8009B0F4[0];

    f &= 0x2000030;
    f |= D_8009B134[0];

    if (f == 0) {
        arg0[0x51] = 0;
    }
}
