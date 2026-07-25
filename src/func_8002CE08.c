/* Both flags are reached gp-relatively; see include/variables.h. */
#define D_8009B26C_IS_SCALAR
#define D_8009B269_IS_SCALAR
#include "common.h"

void func_8002CE08(void) {
    u8 v = D_8009B26C;

    if (!(v & 0x40)) {
        D_8009B26C = v | 0x40;
        func_80030198();
    } else {
        func_80031084();
        if (!(D_8009B26C & 0x40)) {
            D_8009B269 = 0;
        }
    }
}
