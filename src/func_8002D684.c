/* Reaches D_8009B26C gp-relatively; see the note in include/variables.h. */
#define D_8009B26C_IS_SCALAR
#include "common.h"

void func_8002D684(void) {
    u8 v = D_8009B26C;

    if (!(v & 0x40)) {
        D_8009B26C = v | 0x40;
        func_8003BEB8();
        func_8016A080();
    }
    func_8016A37C();
}
