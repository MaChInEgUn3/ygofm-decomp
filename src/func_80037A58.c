#define D_8009B146_IS_AGGREGATE
#define D_8009B0CC_IS_AGGREGATE
#include "common.h"

void func_80037A58(u8 *arg0) {
    s32 v = arg0[0x51];
    s32 n;

    if ((v & 0x80) == 0) {
        arg0[0x51] = v | 0x80;
        D_8009B322 = func_80036D3C(arg0);
        D_8009B348[0] = D_8009B146[0];
        D_8009B348[1] = D_8009B148[0];
    }

    if (D_8009B0CC[0] & 1) {
        D_8009B146[0] = D_8009B348[0] + ((func_8008E590() & 7) - 4);
        D_8009B148[0] = D_8009B348[1] + ((func_8008E590() & 3) - 2);
    }

    n = D_8009B322 - 1;
    D_8009B322 = n;
    if ((s16)n == 0) {
        D_8009B146[0] = D_8009B348[0];
        D_8009B148[0] = D_8009B348[1];
        arg0[0x51] = 0;
    }
}
