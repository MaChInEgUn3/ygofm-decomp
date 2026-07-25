#include "common.h"

void func_80028220(void) {
    u8 *p = D_801AB00C;

    func_80027DF8(p, D_8009B1D5);
    func_80027DF8(p + 0x294, D_8009B1D5 ^ 1);
}
