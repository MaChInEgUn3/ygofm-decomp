#define D_8009B26C_IS_SCALAR
#define D_8009B269_IS_SCALAR
#define D_80010000_IS_AGGREGATE
#define D_8009B2F8_IS_AGGREGATE
#include "common.h"

void func_8002D370(void) {
    u8 v = D_8009B26C;

    if (!(v & 0x40)) {
        D_8009B26C = v | 0x40;
        func_800323F8(D_80010000[0], D_801D0200, 0, D_8009B2F8[0]);
        func_80015A00();
    } else if (func_80033BE8() == 0) {
        func_8003FF34();
        func_80015B00();
        D_8009B26C = D_8009B269;
    }
}
