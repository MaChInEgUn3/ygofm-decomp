#define D_8009B26C_IS_SCALAR
#define D_8009B365_IS_SCALAR
#include "common.h"

void func_80030FA0(void) {
    u8 *p = D_80090D68;
    s32 i = D_8009B2F1;

    D_8009B365 = 0;
    D_8009B2B2 = 0;
    D_8009B26C = p[i];
}
