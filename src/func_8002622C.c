#define D_8009B0F4_IS_AGGREGATE
#define D_8009B134_IS_AGGREGATE
#include "common.h"

void func_8002622C(void) {
    if (func_80024E24() == 0) {
        s32 r = func_8002C7E8(0, D_8009B1D2);

        D_8009B1A0 = r;

        if ((s16)r != 0) {
            u8 *p = func_8002C68C(0x12);

            *(s16 *)p = 0xA0;
            *(s16 *)(p + 2) = 0x78;
            *(s16 *)(p + 0x1A) = 1;
            func_8003FEE0(2);
            func_80029164(1, D_8009B1A0);
        }
    } else {
        s32 f = D_8009B0F4[0];

        f &= 0x2000030;
        f |= D_8009B134[0];

        if (f == 0) {
            D_8009B220 = 0;
        }
    }
}
