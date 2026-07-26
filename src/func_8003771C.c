#define D_8009B2A8_IS_AGGREGATE
#define D_8009B2AA_IS_AGGREGATE
#define D_8009B29C_IS_AGGREGATE
#define D_8009B27C_IS_AGGREGATE
#include "common.h"

void func_8003771C(u8 *arg0) {
    arg0[0x51] = 0;
    D_8009B2A8[0] = func_80036D3C(arg0);
    D_8009B2AA[0] = func_80036D3C(arg0);
    D_8009B29C[0] = func_80036D3C(arg0);

    {
        s32 t = (s16)Base2_8009B2AA[0];
        s32 w = Base3_8009B2AA[0];

        if (t >= 0x1000) {
            Base4_8009B2AA[0] = w - 0x1000;
            arg0[0x51] = 0xA;
        }
    }

    D_8009B357 = 7;
    D_8009B27C[0] = 7;
}
