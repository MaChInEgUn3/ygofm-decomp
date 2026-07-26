#define D_8009B2A8_IS_AGGREGATE
#define D_8009B2AA_IS_AGGREGATE
#define D_8009B270_IS_AGGREGATE
#define D_8009B27C_IS_AGGREGATE
#include "common.h"

void func_8003767C(u8 *arg0) {
    s32 r;

    D_8009B2AA[0] = 0;
    D_8009B2A8[0] = 0;
    r = func_80036D3C(arg0);
    D_8009B270[0] = r;

    if (r & 0x8000) {
        u8 **slot = (u8 **)(arg0 + *(s8 *)(arg0 + 0x58) * 4);
        u8 *b = *slot;
        s32 v = *b;

        *slot = b + 1;
        Base2_8009B2AA[0] = v;
        Base2_8009B2A8[0] = func_80036D3C(arg0);
    }

    D_8009B357 = 5;
    D_8009B27C[0] = 5;
    arg0[0x51] = 0xA;
}
