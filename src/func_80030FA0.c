#define D_8009B365_IN_DATA
#define D_8009B26C_IN_DATA
#include "common.h"

void func_80030FA0(void) {
    u8 *p = D_80090D68;
    s32 i = D_8009B2F1;
    u8 v;

    D_8009B365 = 0;
    v = p[i];
    D_8009B2B2 = 0;
    D_8009B26C = v;
}
