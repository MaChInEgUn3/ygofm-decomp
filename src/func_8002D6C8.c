#define D_8009B26C_IS_SCALAR
#define D_8009B269_IS_SCALAR
#include "common.h"

void func_8002D6C8(void) {
    u8 v = D_8009B26C;

    if (!(v & 0x40)) {
        D_8009B26C = v | 0x40;
        func_8003C2B4();
        func_8003C628();
        func_80015A00();
    }

    if (func_8003C8CC() == 0) {
        func_8003FF34();
        D_8009B26C = D_8009B269;
    }
}
