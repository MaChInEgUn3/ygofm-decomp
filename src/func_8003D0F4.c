#define D_8009B0C4_IS_AGGREGATE
#define D_8009B408_IS_AGGREGATE
#include "common.h"

void func_8003D0F4(u8 *arg0) {
    s32 a;
    s32 b;

    func_8003BC40(D_801B125A, arg0 + 0x40C, 6);

    a = *(s32 *)(arg0 + 0x408);
    b = *(s32 *)(arg0 + 0x404);
    D_8009B0C4[0] = a;
    D_8009B3B8 = b;
    D_8009B27A[0] = arg0[0x5DC];

    if (D_8009B408[0] < 0) {
        u8 v = arg0[0x5DE];

        Base2_8009B408[0] = v;
        func_80046FA0((s8)v);
    }
}
