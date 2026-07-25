#include "common.h"

void func_8002F9D4(void) {
    u8 *p = D_8009B290;
    s32 v;

    D_8009B290 = p + 2;
    v = p[0] | (p[1] << 8);
    if (func_8002EE5C() == 0) {
        D_8009B290 = D_801A8000 + v;
    }
    D_8009B27C = 0;
}
