#include "common.h"

void func_8002EB48(void) {
    u8 *p = D_8009B290;
    u8 v = *p;

    D_8009B290 = p + 1;
    D_8009B26C[0] = 5;
    D_8009B363[0] = v;
}
